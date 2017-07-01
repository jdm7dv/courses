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
      , dataTransferManager = Windows.ApplicationModel.DataTransfer.DataTransferManager.getForCurrentView()
      , listView
      , requestedIndex;

    WinJS.UI.Pages.define("/pages/clientPortfolio/clientPortfolio.html", {

        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data
        ready: function (element, options) {

            // Store the index of the chart that was requested so we can
            // use it later. +1 to account for the client summary tile
            requestedIndex = options.itemIndex + 1;

            initializeLayout();
            bindEventListeners();

            // We only care about the client's portfolio data
            Data.ClientModel.filter = 'investments';
        },

        unload: function () {
            unbindEventListeners();
        }
    });

    function initializeLayout() {

        // Customize the page title for the current client
        var summaryItem = Data.ClientModel.getItemAt(0)
          , pagetitle = summaryItem.posessive + ' Portfolio Allocations';

        document.querySelector('.pagetitle').textContent = pagetitle;

        listView = document.querySelector(".clientPortfolioList").winControl;

        // Let the listView automatically render to the item at the requested index
        listView.indexOfFirstVisible = (requestedIndex > 1) ? requestedIndex : 0;
        listView.groupHeaderTemplate = Renderers.GroupHeaderRenderer;
        listView.itemTemplate = Renderers.ItemRenderer.bind(window, 'clientPortfolio');
        listView.selectionMode = 'none';
        listView.tapBehavior = 'none';
        listView.swipeBehavior = 'none';
        listView.layout = new WinJS.UI.GridLayout({
            disableBackdrop: true,
            groupHeaderPosition: "top",
            groupInfo: {
                enableCellSpanning: true,
                cellWidth: 100,
                cellHeight: 150
            },
            maxRows: 3
        });

        listView.element.focus();
    }

    function updateLayout() {
        listView.groupDataSource = Data.ClientModel.groups.dataSource;
        listView.itemDataSource = Data.ClientModel.items.dataSource;
    }

    function bindEventListeners() {
        Data.ClientModel.addEventListener('update', updateLayout);
        dataTransferManager.addEventListener("datarequested", onDataRequested);
    }

    function unbindEventListeners() {
        Data.ClientModel.removeEventListener('update', updateLayout);
        dataTransferManager.removeEventListener("datarequested", onDataRequested);
    }

    /**
     * Method invoked when a user chooses to Share while in the clientPortfolio view.
     * This will convert all the charts in their current state into PNG assets that
     * can be saved to SkyDrive or sent as attachments within an email
     */
    function onDataRequested(evt) {

        var request = evt.request
          , deferral = request.getDeferral() // Defers the share contract until we're ready
          , client = Data.ClientModel.items.dataSource._list.getAt(0)
          , charts = listView.element.querySelectorAll('.pie-chart svg')
          , promises = []
          , storageFiles = [];

        // Create separate promises to convert each chart to an image. We'll join 
        // them together and proceed after they all complete
        Array.prototype.forEach.call(charts, function (val, i) {
            promises.push(createStreamedFile('filename_' + i + '.png', val));
        });

        return WinJS.Promise.join(promises)
            .then(function (result) {

                Array.prototype.forEach.call(result, function (val) {

                    // Ignore failures
                    if (typeof val == 'boolean') return;

                    // Add the rest to our list of image files
                    else storageFiles.push(val);
                });

                // Set up all the data in the share contract
                request.data.properties.title = [client.posessive, 'Investment Allocations'].join(' ');
                request.data.properties.description = 'A pie-graphy analysis of how ' + client.posessive + ' investments are distributed';
                request.data.setStorageItems(storageFiles);

                // Complete the deferral when everything is ready to be shared
                deferral.complete();
            });
    }

    /**
     * Creates a StorageFile that can be shared
     *
     * @param filename The name of the file to create
     * @param svg The SVGElement that will be saved to the file
     */
    function createStreamedFile(filename, svg) {

        var filename = filename || 'investments_' + Date.now() + '.png'
          , svg = svg || listView.element.querySelector('.pie-chart svg')
          , canvas
          , blob
          , inMemoryStream
          , buffer;

        // Convert the SVGElement to a <canvas> element
        return svgutils.convertToCanvas(svg, true)
            .then(function (result) {

                // Get an image out of the resulting canvas
                blob = result.msToBlob();
                inMemoryStream = blob.msDetachStream();
                buffer = new Windows.Storage.Streams.Buffer(inMemoryStream.size);

                inMemoryStream.seek(0);

                // We need to copy the image stream to a file stream,
                // so we'll use the buffer as an intermediary
                return inMemoryStream.readAsync(buffer, buffer.capacity, Windows.Storage.Streams.InputStreamOptions.none);
            })
            .then(function () {

                // Create a thumbnail to go along with the image file
                var thumbnailStream = Windows.Storage.Streams.RandomAccessStreamReference.createFromStream(inMemoryStream);

                // Close the image stream
                inMemoryStream.close();
                blob.msClose();

                // Create the image file that will be shared
                return Windows.Storage.StorageFile.createStreamedFileAsync(filename, function (destinationStream) {

                    // Be sure to close our streams on success and/or failure
                    var onsuccess = destinationStream.close.bind(destinationStream)
                      , onerror = destinationStream.failAndClose.bind(destinationStream);

                    // Write the buffer to our newly created file
                    return destinationStream.writeAsync(buffer).done(onsuccess, onerror);

                }, thumbnailStream);
            });
    }

})();