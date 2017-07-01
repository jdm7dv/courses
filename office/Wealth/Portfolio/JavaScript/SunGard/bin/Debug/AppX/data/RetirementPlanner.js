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
      , startYear = 2010
      , yearsPerStep = 5;

    /**
     * RetirementPlanner calculates data over a period of time from
     * account data retrieved from ClientModel.js
     */
    var RetirementPlanner = WinJS.Class.define(

        function () {

            this._data = {};

            // Recalculate retirement data when the data set changes
            Data.ClientModel.addEventListener('update', this._update.bind(this));
        },

        {
            data: {

                /** 
                 * Marshalls the result of the _update method into a format that can be
                 * used by the Retirement Chart
                 */
                set: function(value) {

                    var result = [
                        { key: 'gross',                 displayType: 'bar', data: []  , label: ["Gross asset value"]},
                        { key: 'afterTax',              displayType: 'bar', data: []  , label: ["After all taxes"]},
                        { key: 'afterTaxLiving',        displayType: 'line', data: [] , label: ["After all taxes", "& living expenses"]},
                        { key: 'afterTaxLivingHealth',  displayType: 'line', data: [] , label: ["After all taxes, living,", "& healthcare expenses"]}
                    ];

                    value.forEach(function (entry, i) {
                        result[0].data.push({ time: entry.time, value: entry.data.gross });
                        result[1].data.push({ time: entry.time, value: entry.data.afterTax });
                        result[2].data.push({ time: entry.time, value: entry.data.afterTaxLiving });
                        result[3].data.push({ time: entry.time, value: entry.data.afterTaxLivingHealth });
                    });

                    this._data = result;
                },
                get: function() {
                    return this._data;
                }
            },

            /**
             * Pulls current account data from the Client Model and calculates a
             * projection of assets over time
             */
            _update: function () {

                var data = Data.ClientModel.cache.retirement
                  , accounts = data.accounts
                  , year = startYear
                  , complete = false
                  , result = []
                  , assetGrowth = data.rate_of_asset_growth
                  , taxRate = data.taxable_rate
                  , gross = data.current_assets
                  , net = gross - (gross * taxRate)
                  , atl = net + accounts.living_expenses.value
                  , atlh = atl + accounts.medical_expenses.value
                  , ss = data.controls.incl_social_security.value
                  , key, entry;

                // The "complete" flag is unset when there are no more accounts
                // that coincide with the current year being calculated. Each
                // iteration of the loop calculates values for the next year.
                while (complete == false) {

                    // Assume that there are no accounts to calculate until proven otherwise
                    complete = true;

                    entry = {

                        // Always end on the last day of this year
                        time: new Date('12/31/' + year),

                        // Append values from the prior year to the result
                        data: {
                            gross: gross,
                            afterTax: net,
                            afterTaxLiving: atl,
                            afterTaxLivingHealth: atlh
                        }
                    };

                    result.push(entry);

                    // Calculate gross value by finding the sum of all accounts 
                    // that coincide with this year
                    for (key in accounts) {

                        if (key == 'ss_income' && ss == false) {
                            // ...Ignore social security income while ss flag is unset
                        }
                        else if (year >= accounts[key].start && year < accounts[key].end) {

                            // Found an account for this year, so keep running the while loop
                            complete = false;
                            gross += accounts[key].value;
                        }
                    }

                    // Calculate the rest of the values from the gross value
                    net = gross - (gross * taxRate);
                    atl = net + accounts.living_expenses.value;
                    atlh = atl + accounts.medical_expenses.value;

                    // Increment the current year
                    year += yearsPerStep;
                }

                this.data = result;

                // Notify any listeners that there has been a change in data
                this.dispatchEvent(UPDATE_EVENT);
            }
        }
    );

    // Gives RetirementPlanner the addEventListener, removeEventListener, and dispatchEvent methods
    WinJS.Class.mix(RetirementPlanner, WinJS.Utilities.eventMixin);

    WinJS.Namespace.define('Data', {
        RetirementPlanner: new RetirementPlanner()
    });

}());