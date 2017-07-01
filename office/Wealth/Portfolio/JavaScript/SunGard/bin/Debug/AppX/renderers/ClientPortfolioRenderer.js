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
        'investments': investmentItemRenderer
    };
    var COLORS = ["#8e0700", "#db1200", "#ff5148", "#310206", "#000"];

    // 'item' refers to the allocation items to the right of each pie
    var itemHeight = 50;

    Renderers.register('clientPortfolio', function (category) {
        return categories[category] || Renderers.DefaultItemRenderer;
    });

    function investmentItemRenderer(element, item) {

        var frag = document.createDocumentFragment()
          , chart = document.createElement('div')
          , allocations = document.createElement('div')
          , allocationsList = document.createElement('ol')
          , allocationsDetail = document.createElement('div')
          , title = document.createElement('h2');

        title.className = 'portfolio-title';
        // Regex to title case the text
        title.textContent = item.data.title.replace(/[^\s]+/g, function (str) { return str.substr(0, 1).toUpperCase() + str.substr(1); });

        chart.className = 'pie-chart';
        allocations.className = 'allocations';
        allocationsList.className = 'allocations-list';
        allocationsDetail.className = 'allocation-item-detail';

        var total = { category: 'total', value: item.data.value };
        allocationsList.appendChild(makeAllocationItem(total, item.data.allocations.length));

        item.data.allocations.forEach(function (val, i) {
            allocationsList.appendChild(makeAllocationItem(val, i));
            allocationsDetail.appendChild(makeHoldingsItem(val, i));
        });

        allocationsList.style.height = (itemHeight * (item.data.allocations.length + 1)) + 'px';
        allocationsDetail.style.height = (itemHeight * (item.data.allocations.length + 1)) + 'px';

        allocations.appendChild(allocationsList);
        allocations.appendChild(allocationsDetail);

        frag.appendChild(chart);
        frag.appendChild(allocations);

        element.appendChild(title)
        element.appendChild(frag);
        element.classList.add('portfolio-item');

        var options = { colors: COLORS, innerRadius: 0.72 };

        // Do this *after* the rest of the DOM has been rendered
        chart.visualization = new Charts.PieChart(chart, item.data.allocations, options);

        // This event is fired by the chart upon having a piece of the pie selected. The fired functions
        // cause the detail to pop out, and the selected category to be highlighted.
        chart.visualization.addEventListener('arcSelected', function (e) {
            handleArcSelect(e, allocationsList);
            handleArcSelect(e, allocationsDetail);
        });

        // On clicking an allocation item, snap the arc to that point, and then fire all the normal reactions.
        Array.prototype.forEach.call(allocationsList.childNodes, function (node, i) {
            node.onclick = chart.visualization.snapToArcAt.bind(chart.visualization, i - 1);
        });

        // Creates a rotational gesture and binds it to the chart instance
        Gestures.create('rotation', chart.visualization);
    };
    function makeAllocationItem(val, i) {
        // top level category labels for each pie

        var allocationItem
          , allocationItemTitle
          , allocationItemValue
          , allocationItemSelectedArrow;

        allocationItem = document.createElement('li');
        allocationItem.className = 'allocation-item';
        allocationItem.setAttribute('data-category', val.category);
        allocationItem.style.backgroundColor = COLORS[i];
        allocationItem.style.height = itemHeight+'px';

        allocationItemSelectedArrow = document.createElement('div');
        allocationItemSelectedArrow.className = 'allocation-item-arrow';
        allocationItemSelectedArrow.style.borderLeftColor = COLORS[i];

        allocationItemTitle = document.createElement('span');
        allocationItemTitle.className = 'allocation-item-title';
        allocationItemTitle.textContent = val.category;

        allocationItemValue = document.createElement('span');
        allocationItemValue.className = 'allocation-item-value';
        allocationItemValue.textContent = '$'+val.value.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");

        allocationItem.appendChild(allocationItemSelectedArrow);
        allocationItem.appendChild(allocationItemTitle);
        allocationItem.appendChild(allocationItemValue);
        
        return allocationItem;
    }

    function makeHoldingsItem(val, i) {
        // pop-out details for each allocation

        var holdingsList,
            holdingsItem,
            holdingsDesc,
            holdingsPct,
            holdingsValue;

        holdingsList = document.createElement('ul');
        holdingsList.className = "holdings-list";
        holdingsList.setAttribute('data-category', val.category);

        val.holdings.forEach(function (val, i) {
            holdingsItem = document.createElement('li');
            holdingsItem.className = "holdings-item";

            holdingsDesc = document.createElement('span');
            holdingsDesc.className = "holdings-desc";
            holdingsDesc.textContent = val.name.replace(/^([a-z]{1})/, function (c) { return c.toUpperCase(); });

            holdingsPct = document.createElement('span');
            holdingsPct.className = "holdings-pct";
            holdingsPct.textContent = val.memo;

            holdingsValue = document.createElement('span');
            holdingsValue.className = "holdings-value";
            holdingsValue.textContent = '$' + val.value.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");

            holdingsItem.appendChild(holdingsDesc);
            holdingsItem.appendChild(holdingsPct);
            holdingsItem.appendChild(holdingsValue);

            holdingsList.appendChild(holdingsItem);
        });

        return holdingsList;        
    }

    function handleArcSelect(e, element) {
        // Upon selecting a piece of the arc, highlight that allocation item and pop out the detail list.
        // All animation in this regard is done via css, so we merely need to apply the proper class to the
        // selected element.

        var category = e.detail.selected.data.category;
        var selected, el;

        element.classList.add('is-selected');

        for (var i = 0; i < element.childNodes.length; i++) {
            el = element.childNodes[i];

            if (el.getAttribute('data-category') == category) {
                el.classList.add('selected')
                selected = el;
            } else {
                el.classList.remove('selected');
            }
        };
        
    };

}());