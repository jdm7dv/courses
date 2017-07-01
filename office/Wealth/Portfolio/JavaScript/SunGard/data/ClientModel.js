//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF 
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A 
//// PARTICULAR PURPOSE. 
//// 
//// Copyright (c) Microsoft Corporation. All rights reserved     
////
//// To see the topic that inspired this sample app, go to http://msdn.microsoft.com/en-us/library/windows/apps/dn163530

(function () {
    "use strict";

    var UPDATE_EVENT = 'update'
      , GROUPS = {
          'summary':     { sort: 0, title: '%CLIENT_NAME%' },
          'detail':      { sort: 1, title: 'Personal, Family and Interests' },
          'investments': { sort: 2, title: 'Portfolio' },
          'retirement':  { sort: 3, title: 'Over Time Analysis' }
        }
      , VALID_FILTERS = ['none'].concat( Object.keys(GROUPS) );

    var ClientModel = WinJS.Class.define(

        function () {
            this._cache = null;
            this._filter = VALID_FILTERS[0];
            this._items = null;
            this._groups = null;
            this._update();
        },

        {
            // Get/set the JSON object that backs this MediaModel
            cache: {
                get: function () { return this._cache; },
                set: function (data) {

                    this._cache = data;

                    // If this were a service, this would make a new request to that service
                    Data.Repository.update(this._cache);
                    this._update();
                }
            },

            filter: {
                get: function() { return this._filter; },
                set: function(value) {
                    if (this._filter != value && VALID_FILTERS.indexOf(value) > -1) {
                        this._filter = value;
                        this._update();
                    }
                    else {
                        // Even though there was no change, trigger the UPDATE_EVENT so
                        // that the invoking class may rely on it
                        this.dispatchEvent(UPDATE_EVENT, {});
                    }
                }
            },

            // Get the item datasource
            items: {
                get: function () { return this._items; }
            },

            // Get the group datasource
            groups: {
                get: function () { return this._groups; }
            },

            // Get a JSON object describing the groups
            allGroups: {
                get: function () { return GROUPS; }
            },

            // Get the item from the datasource at the specified index
            getItemAt: function(index) {
                return this.items.dataSource._list.getAt(index);
            },

            _update: function () {

                var self = this
                  , filter = this.filter
                  , groups = {}
                  , items = [];

                // Pull all of the available data from the Repository
                Data.Repository.getData().then(function (data) {

                    var data = data.client
                      , clientName = [data.name.first, data.name.mi, data.name.last].join(' ');

                    // Initialize the _cache with our data set
                    self._cache = data;

                    // Name the client group
                    GROUPS.summary.title = clientName;

                    items = [
                        { category: 'summary', name: clientName, posessive: data.name.posessive, photo: data.photo, lastModified: new Date(data.lastModified) },
                        { category: 'detail',  title: 'contact',   entries: data.contact },
                        { category: 'detail',  title: 'family',    entries: data.family },
                        { category: 'detail',  title: 'interests', entries: data.interests }
                    ];

                    // Add the individual investment accounts
                    calculateTotalPortfolio.call(self, data.portfolio).every(function (val) {
                        return items.push({ category: 'investments', title: val.account_type, allocations: val.allocations, value: val.value });
                    });

                    // Add retirement planning data
                    items.push({ category: 'retirement', title: 'accounts', values: data.retirement.accounts });
                    items.push({ category: 'retirement', title: 'controls', values: data.retirement.controls });

                    // Filter the items. Summary is __always__ included
                    items = items.filter(function (val, i) {
                        return (filter == VALID_FILTERS[0] || val.category == 'summary' || val.category == filter);
                    });

                    // Create new item and group datasources from the filtered data
                    var list = new WinJS.Binding.List(items);

                    // Create item and group data sources for ListView consumption
                    var groupedList = list.createGrouped(
                        function groupKeySelector(item) { return item.category; },
                        function groupDataSelector(item) { return GROUPS[item.category]; },
                        function groupSorter(group1, group2) { return group1.sort < group2.sort; }
                    );

                    self._items = groupedList;
                    self._groups = groupedList.groups;

                    // Notify listeners that there is new data to consume
                    self.dispatchEvent(UPDATE_EVENT, {});
                });
            }
        }
    );

    // Returns an array comprising of the original portfolio data set and an aggregate
    function calculateTotalPortfolio(data) {

        var result = { account_type: 'total', value: 0, allocations: [] }
          , i;

        data.forEach(function (item) {

            item.value = 0;
            i = result.allocations.push({ category: item.account_type, value: 0, holdings: [] }) - 1;

            item.allocations.forEach(function (allocation) {

                allocation.value = 0;
                allocation.holdings.forEach(function (holding) {
                    allocation.value += holding.value;
                });

                item.value += allocation.value;

                result.allocations[i].holdings.push({
                    name: allocation.category,
                    value: allocation.value,
                    memo: ''
                })
            });

            result.allocations[i].value = item.value;
            result.value += item.value;
        });

        // Store the total portfolio worth in _cache so we can use it for retirement planning too
        this._cache.retirement.current_assets = result.value;

        return [result].concat(data);
    }

    // Gives ClientModel the addEventListener, removeEventListener, and dispatchEvent methods
    WinJS.Class.mix(ClientModel, WinJS.Utilities.eventMixin);

    WinJS.Namespace.define('Data', {
        ClientModel: new ClientModel()
    });

}());