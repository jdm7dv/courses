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
      , changeTimer = null
      , listView;

    WinJS.UI.Pages.define("/pages/clientRetirement/clientRetirement.html", {

        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data.
        ready: function (element, options) {
            initializeLayout();
            bindEventListeners();
            Data.ClientModel.filter = 'retirement';
        },

        unload: function () {
            unbindEventListeners();
        }
    });

    function initializeLayout() {

        // Customize the page title for the current client
        var summaryItem = Data.ClientModel.getItemAt(0)
          , pagetitle = summaryItem.posessive + ' Retirement Planning';

        document.querySelector('.pagetitle').textContent = pagetitle;

        listView = document.querySelector(".clientRetirementList").winControl;
        listView.groupHeaderTemplate = Renderers.RetirementHeaderRenderer;
        listView.itemTemplate = Renderers.ItemRenderer.bind(window, 'clientRetirement');
        listView.selectionMode = 'none';
        listView.tapBehavior = 'none';
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

    function bindEventListeners() {
        Data.ClientModel.addEventListener('update', updateLayout);
        dataTransferManager.addEventListener("datarequested", onDataRequested);
    }

    function unbindEventListeners() {
        document.removeEventListener('change', onChangeControls);
        Data.ClientModel.removeEventListener('update', updateLayout);
        Data.RetirementPlanner.removeEventListener('update', updateRetirementData);
        dataTransferManager.removeEventListener("datarequested", onDataRequested);
    }

    function updateLayout() {
        listView.groupDataSource = Data.ClientModel.groups.dataSource;
        listView.itemDataSource = Data.ClientModel.items.dataSource;

        // Bind chart- and controls-related events now that they have been rendered
        document.addEventListener('change', onChangeControls);
        Data.RetirementPlanner.addEventListener('update', updateRetirementData);

        // We really only want this method to run the once
        Data.ClientModel.removeEventListener('update', updateLayout);
    }

    /**
     * Updates the chart with the current data set
     */
    function updateRetirementData() {
        document.querySelector('.retirement-chart').visualization.update(Data.RetirementPlanner.data);
    }

    /**
     * Updates the labels on each of the controls to reflect their current value.
     * Since this operation is inexpensive, we don't need to wait before adjusting
     * these values like we do in onChangeControls()
     */
    function updateControls() {
        retirement_age_client_value.textContent = retirement_age_client.value;
        retirement_age_spouse_value.textContent = retirement_age_spouse.value;
        living_expenses_value.textContent = '$' + living_expenses.value.replace(/\B(?=(\d{3})+(?!\d))/g, ",") + '/yr';
        medical_expenses_value.textContent = '$' + medical_expenses.value.replace(/\B(?=(\d{3})+(?!\d))/g, ",") + '/mo';
        years_to_project_value.textContent = years_to_project.value;
    }

    /**
     * Handles document-level change events, generally dispatched by chart controls.
     * This method will prevent updates to the chart until the user is done interacting
     * the the controls (via a 100ms timer).
     */
    function onChangeControls(evt) {

        // Clear the previous timeout (if there is one)
        clearTimeout(changeTimer);

        // Update the controls and calculate new values for the retirement planner
        // after a specificed time has elapsed (100ms)
        changeTimer = setTimeout(function () {

            var model = Data.ClientModel.cache

              // In this demonstration, we assume that the client and his spouse
              // were both 30 years old in 2010
              , projectionEnd = 2010 - 30 + parseInt(years_to_project.value)
              , retirementYear = 2010 - 30 + parseInt(retirement_age_client.value)
              , spouseRetirementYear = 2010 - 30 + parseInt(retirement_age_spouse.value);

            // Update the model for the control that was *just* changed
            model.retirement.controls[evt.target.id].value = parseInt(evt.target.value);

            // Update the client and spouse income span based on the "retirement age" controls
            model.retirement.accounts.client_income.end = (projectionEnd > retirementYear) ? retirementYear : projectionEnd;
            model.retirement.accounts.spouse_income.end = (projectionEnd > spouseRetirementYear) ? spouseRetirementYear : projectionEnd;

            // These are debit accounts, so ensure tha their values are negative
            model.retirement.accounts.living_expenses.value = parseInt(living_expenses.value) * -1;
            model.retirement.accounts.medical_expenses.value = parseInt(medical_expenses.value) * -1;

            // Update the rest of the spans based on the "years to project" control
            model.retirement.accounts.living_expenses.end = projectionEnd;
            model.retirement.accounts.medical_expenses.end = projectionEnd;
            model.retirement.accounts.ss_income.end = projectionEnd;
            model.retirement.accounts.living_expenses.end = projectionEnd;
            model.retirement.accounts.medical_expenses.end = projectionEnd;

            // Update the ClientModel with these new values directly
            Data.ClientModel.cache = model;
        }, 100);

        updateControls();
    }

    /**
     * Method invoked when a user chooses to Share while in the clientRetirement view.
     * This will convert the retirement chart in its current state into a PNG that
     * can be saved to SkyDrive or sent as attachments within an email
     */
    function onDataRequested(evt) {

        var request = evt.request
          , deferral = request.getDeferral() // Defers the share contract until we're ready
          , client = Data.ClientModel.items.dataSource._list.getAt(0)
          , charts = listView.element.querySelectorAll('.retirement-chart svg')
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
                request.data.properties.title = [client.posessive, 'Retirement Plan'].join(' ');
                request.data.properties.description = 'An analysis of how ' + client.posessive + ' next few years might look';
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

        var canvas
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

                // We need to copy the image stream to a file stream,
                // so we'll use the buffer as an intermediary
                inMemoryStream.seek(0);

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