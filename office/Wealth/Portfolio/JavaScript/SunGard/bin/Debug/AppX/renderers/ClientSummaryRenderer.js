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
        'detail': detailItemRenderer,
        'investments': investmentItemRenderer,
        'retirement': retirementItemRenderer
    };
    
    // Registers as a renderer for each category
    Renderers.register('clientSummary', function (category) {
        return categories[category] || Renderers.DefaultItemRenderer;
    });

    function detailItemRenderer(element, item) {

        var frag = document.createDocumentFragment()
            , heading = document.createElement('h3')
            , list = document.createElement('ul')
            , listItem;

        element.classList.add('border-style-2');

        heading.className = 'detail-heading';
        heading.textContent = item.data.title;

        list.className = 'detail-list';

        // These tiles are all static, and thus only in the app to show sample meta data for the data visualization.

        item.data.entries.every(function (entry) {

            listItem = document.createElement('li');

            switch (item.data.title) {
                case 'contact':
                    listItem.textContent = entry.type + ': ' + entry.value;
                    break;
                case 'family':
                    listItem.textContent = [entry.name.first, entry.name.mi, entry.name.last].join(' ') + ', ' + entry.relationship;
                    break;
                case 'interests':
                default:
                    listItem.textContent = entry;
                    break;
            }

            return list.appendChild(listItem);
        });

        frag.appendChild(heading);
        frag.appendChild(list);

        element.appendChild(frag);
    };

    function investmentItemRenderer(element, item) {

        // This is the main pie chart on the home client summary view. Each pie chart is an instance of PieChart.js,
        // and the inner value is calculated and set in HTML

        var frag = document.createDocumentFragment()
          , chart = document.createElement('div')
          , label = document.createElement('span')
          , value = document.createElement('span');

        chart.className = 'investment-item-chart pie-chart';

        label.className = 'investment-item-label';
        label.textContent = (item.data.title == 'total') ? 'Total Relationship' : item.data.title;

        value.className = 'investment-item-value';
        value.textContent = '$' + item.data.value.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");

        frag.appendChild(chart);
        frag.appendChild(label);
        frag.appendChild(value);

        element.appendChild(frag);

        // These options are passed to PieChart.js. innerRadius set to 0 renders a pie, where all other values 0 - 1 
        // render an arc, with the inner radius as a percentage of the whole size.

        if (item.data.title == 'total') {
            var options = {
                height: 425,
                width: 425,
                innerRadius: .72
            }
        } else {
            var options = {
                height: 130,
                width: 130,
                innerRadius: 0
            }
        }

        // Instantiates the pie chart. Instanced methods can be referenced now by selecting the chart and accessing
        // the visualization property.
        chart.visualization = new Charts.PieChart(chart, item.data.allocations, options);
    };

    function retirementItemRenderer(element, item) {

        // This renders the investment bar / line chart. 

        var frag = document.createDocumentFragment()
          , chart = document.createElement('div')
          , label = document.createElement('span')
          , value = document.createElement('span');

        chart.className = 'investment-item-chart retirement-chart';

        label.className = 'investment-item-label';
        label.textContent = (item.data.title == 'total') ? 'Total Relationship' : item.data.title;

        value.className = 'investment-item-value';

        frag.appendChild(chart);

        element.appendChild(frag);

        // showKey determines whether or not the key is visible, and also determines if the chart stretches
        // to the full specified width.

        var options = {
            height: 500,
            width: 690,
            showKey: false
        }

        // Instantiates the retirement chart. Instanced methods can be referenced now by selecting the chart and accessing
        // the visualization property.
        chart.visualization = new Charts.RetirementChart(chart, Data.RetirementPlanner.data, options);
    };

}());