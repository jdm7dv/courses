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

    var keys = []
      , renderers = [];

    WinJS.Namespace.define('Renderers', {

        /**
         * Provides a renderer for the default group header
         */
        GroupHeaderRenderer: function (itemPromise, recycledElement) {

            var header = document.createElement('div');

            return {
                element: header,
                renderComplete: itemPromise.then(function (item) {
                    header.classList.add(item.key);
                    if (item.key.match(/investments/)) {
                        header.classList.add('active');
                        header.addEventListener('click', function () {
                            if (WinJS.Navigation.location.match('clientSummary.html')) {
                                WinJS.Navigation.navigate("/pages/clientPortfolio/clientPortfolio.html", { itemIndex: 0 });
                            }
                        });
                    }
                    else if (item.key.match(/retirement/)) {
                        header.classList.add('active');
                        header.addEventListener('click', function () {
                            WinJS.Navigation.navigate("/pages/clientRetirement/clientRetirement.html", { itemIndex: 0 });
                        });
                    }
                    header.innerHTML = item.data.title;
                })
            };
        },

        /**
         * Provides a ListView tile renderer
         *
         * Usage ex:
         *     listView.itemTemplate = Renderers.ItemRenderer.bind(window, 'clientPortfolio');
         * 
         * @param String key Specifies a registered renderer to use
         * @param IItemPromise itemPromise Provided by WinJS.UI.ListView
         * @param DOMElement recycledElement Provided by WinJS.UI.ListView
         */
        ItemRenderer: function (key, itemPromise, recycledElement) {

            var element = recycledElement || document.createElement('div')
              , category = itemPromise._value.data.category
              , renderer;

            element.className = [itemPromise._value.data.category, itemPromise._value.data.title].join(' ');
            element.innerHTML = '';

            // If this is a summary item then just return a summary item renderer
            if (category == 'summary') {
                renderer = summaryItemRenderer;
            }

            // Otherwise, attempt to find a renderer for the specified 'type'
            else if (keys.indexOf(key) > -1) {
                renderer = renderers[keys.indexOf(key)](category);
            }

            // If all else fails, use the default item renderer
            else {
                renderer = defaultItemRenderer;
            }
            
            // This is the object format required by WinJS.UI.ListView for item templates
            return {
                element: element,
                renderComplete: itemPromise.then(renderer.bind(window, element))
            };
        },

        /**
         * Global reference to the default item renderer
         */
        DefaultItemRenderer: defaultItemRenderer,

        /**
         * Register a renderer with the ItemRenderer class
         *
         * @param String key The key this renderer will be registered under
         * @param Function renderer The rendering function to register
         */
        register: function (key, renderer) {
            renderers.push(renderer);
            keys.push(key);
        }
    });

    /**
     * The summary item is common to every view, and includes the client's
     * name, a photo and the date of their last review
     */
    function summaryItemRenderer(element, item) {

        var frag = document.createDocumentFragment()
          , photo = document.createElement('div')
          , caption = document.createElement('div')
          , fmt = new Windows.Globalization.DateTimeFormatting.DateTimeFormatter('shortdate');

        element.classList.add('border-style-1');

        photo.className = 'summary-photo';
        photo.style.backgroundImage = 'url(' + item.data.photo + ')';

        caption.className = 'summary-caption';
        caption.innerHTML = 'Last Review: ' + fmt.format(item.data.lastModified).replace(/[0-9]*$/, item.data.lastModified.getYear() - 100);

        frag.appendChild(photo);
        frag.appendChild(caption);

        element.appendChild(frag);
    };

    /**
     * The default item is a placeholder that contains the item's
     * title and nothing else
     */
    function defaultItemRenderer(element, item) {
        element.classList.add('default');
        element.innerHTML = item.data.title;
    };

}());