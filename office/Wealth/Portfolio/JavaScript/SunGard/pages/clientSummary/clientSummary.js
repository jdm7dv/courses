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

    var appView = Windows.UI.ViewManagement.ApplicationView
      , appViewState = Windows.UI.ViewManagement.ApplicationViewState
      , listView;

    WinJS.UI.Pages.define("/pages/clientSummary/clientSummary.html", {

        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data.
        ready: function (element, options) {
            initializeLayout();
            bindEventListeners();
            Data.ClientModel.filter = 'none';
        },

        unload: function () {
            unbindEventListeners();
        }
    });

    function initializeLayout() {

        // Creates the initial listview.

        var summaryItem = Data.ClientModel.getItemAt(0)
          , pagetitle = summaryItem.posessive + ' Dashboard';

        document.querySelector('.pagetitle').textContent = pagetitle;

        listView = document.querySelector(".clientSummaryList").winControl;
        listView.groupHeaderTemplate = Renderers.GroupHeaderRenderer;
        listView.itemTemplate = Renderers.ItemRenderer.bind(window, 'clientSummary');
        listView.selectionMode = 'none';
        listView.tapBehavior = 'invokeOnly';
        listView.swipeBehavior = 'none';
        listView.layout = new WinJS.UI.GridLayout({
            disableBackdrop: true,
            groupHeaderPosition: "top",
            groupInfo: {
                enableCellSpanning: true,
                cellWidth: 50,
                cellHeight: 150
            },
            maxRows: 3
        });
    }

    function updateLayout() {
        listView.groupDataSource = Data.ClientModel.groups.dataSource;
        listView.itemDataSource = Data.ClientModel.items.dataSource;
    }

    function bindEventListeners() {
        Data.ClientModel.addEventListener('update', updateLayout);
        listView.element.addEventListener('iteminvoked', onItemInvoked);
    }

    function unbindEventListeners() {
        Data.ClientModel.removeEventListener('update', updateLayout);
        listView.element.removeEventListener('iteminvoked', onItemInvoked);
    }

    function onItemInvoked(evt) {

        // handles navigation. For this sample, we only need to navigate to the portfolio and retirement views.

        var item = Data.ClientModel.getItemAt(evt.detail.itemIndex)
          , index = evt.detail.itemIndex - Data.ClientModel.groups._groupItems.investments.firstItemIndexHint;

        switch (item.category) {
            case 'investments':
                WinJS.Navigation.navigate("/pages/clientPortfolio/clientPortfolio.html", { itemIndex: index });
                break;
            case 'retirement':
                WinJS.Navigation.navigate("/pages/clientRetirement/clientRetirement.html", { itemIndex: index });
                break;
            default:
                break;
        }
    }

})();