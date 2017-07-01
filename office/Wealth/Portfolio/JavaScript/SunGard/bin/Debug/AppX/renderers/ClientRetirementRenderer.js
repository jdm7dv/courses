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

    var categories = {
        'retirement': retirementItemRenderer
    };

    var chart;

    Renderers.register('clientRetirement', function (category) {
        return categories[category] || Renderers.DefaultItemRenderer;
    });

    WinJS.Namespace.define('Renderers', {

        RetirementHeaderRenderer: function (itemPromise) {

            // The retirement header has a custom renderer due to the fact that we emulate the look of three separate tiles,
            // while it is only two.

            var header = document.createElement('div');

            return {
                element: header,
                renderComplete: itemPromise.then(function (item) {

                    if (item.key == 'summary') {
                        header.innerHTML = item.data.title;
                    }
                    else {

                        var key = document.createElement('span')
                          , chart = document.createElement('span')
                          , controls = document.createElement('span');

                        key.className = 'header-key';
                        key.innerText = '2010 Values';

                        chart.className = 'header-chart';
                        chart.innerText = 'Over Time Analysis';

                        controls.className = 'header-controls';
                        controls.innerText = 'Controls';

                        header.appendChild(key);
                        header.appendChild(chart);
                        header.appendChild(controls);
                    }
                })
            };
        }
    });

    function retirementItemRenderer(element, item) {
           
        // Create a chart for the retirement chart, and a box of controls

        chart = document.createElement('div');
        chart.className = "retirement-chart";

        switch (item.data.title) {
            case 'accounts':
                chart.visualization = new Charts.RetirementChart(chart, Data.RetirementPlanner.data, {});
                chart.visualization.addEventListener('change', function (evt) {
                    document.querySelector('.header-key').textContent = evt.detail.year + ' Values';
                });
                element.appendChild(chart);
                break;
            case 'controls':
                retirementControlsRenderer(element, item);
                break;
        }
    };

    function retirementChartRenderer(element, item) {

        // instantiates the chart. 
        chart.visualization.update( Data.RetirementPlanner.data );
    };

    function retirementControlsRenderer(element, item) {

        var frag = document.createDocumentFragment()
          , values = item.data.values
          , key, label, labelValue, control;

        for (key in values) {

            label = document.createElement('label');
            label.setAttribute('for', key);
            label.textContent = values[key].label;

            labelValue = document.createElement('span');
            labelValue.setAttribute('id', key + '_value');

            label.appendChild(labelValue);
            frag.appendChild(label);
            
            if (values[key].type.match('WinJS.UI.ToggleSwitch')) {

                control = document.createElement('div');

                new WinJS.UI.ToggleSwitch(control, {

                    checked: values[key].value,

                    onchange: function (originalEvt) {
                        // WinJS.UI.ToggleSwitch doesn't bubble, so a custom event has to be written to mimic the functionality
                        if (originalEvt.bubbles == false) {

                            var evt = document.createEvent('event')
                              , target = document.getElementById(key);

                            evt.initEvent('change', true, false);

                            target.value = target.querySelector('input').value;
                            target.dispatchEvent(evt);
                        }
                    }
                }).element.setAttribute('id', key);
            }
            else {
                // create the controls with labels and values

                control = document.createElement('input');
                control.setAttribute('id', key);
                control.setAttribute('type', values[key].type);
                (values[key].min) && control.setAttribute('min', values[key].min);
                (values[key].max) && control.setAttribute('max', values[key].max);
                control.setAttribute('value', values[key].value);

                if (key.match(/living_expenses/)) {
                    labelValue.textContent = '$' + String(values[key].value).replace(/\B(?=(\d{3})+(?!\d))/g, ",") + '/yr';
                }
                else if (key.match(/medical_expenses/)) {
                    labelValue.textContent = '$' + String(values[key].value).replace(/\B(?=(\d{3})+(?!\d))/g, ",") + '/mo';
                }
                else {
                    labelValue.textContent = values[key].value;
                }
            }

            frag.appendChild(control);
        }

        element.classList.add('win-interactive');
        element.appendChild(frag);
    };

}());