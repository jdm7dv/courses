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

    var duration = 500
    , _rotation = { selectPoint: 0, rotate: 0 }
    , SELECTED_EVENT = 'arcSelected';

    var PieChart = WinJS.Class.define(

            function (element, data, options) {

                options = options || {};

                this._root = element;
                this._data = data;
                this._rotation = { selectPoint: 0, rotate: 0 };

                this._options = {
                    colors:      options.colors || ["#8e0700", "#db1200", "#ff5148","#310206"],
                    height:      options.height || 450,
                    width:       options.width  || 450,
                    margin:      options.margin || 0,
                    innerRadius: options.innerRadius === "undefined" ? .75 : options.innerRadius
                }
                
                this._render();
            },

            {
                _render: function (element) {

                    element = this._root;

                    this._options.innerHeight = this._options.height - (this._options.margin * 2);
                    this._options.innerWidth = this._options.width - (this._options.margin * 2);
                    
                    this._stage = d3.select(element).append('svg').attr('class', 'arc').attr('height', this._options.height);
                    this._group = this._stage.append('g').attr('class', 'graph').attr('transform', 'translate(' + this._options.innerWidth / 2 + ',' + this._options.innerHeight / 2 + ')');
                    this._key = this._stage.append('g').attr('class', 'key').attr('style', 'border: 1px solid black')
                        .attr('height', 200).attr('width', 200).attr('transform', 'translate(' + this._options.innerWidth * 1.25 + ',' + this._options.innerHeight / 3 + ')');

                    this._color = d3.scale.ordinal().range(this._options.colors);

                    this._update();

                },

                _update: function () {                    
                    this._renderPie();
                    this._renderKey();

                    this.rotation = this._rotation.rotate;

                },
                
                _getRange: function (data) {

                    var combinedData = [],
                        i = 0,
                        len = data.length,
                        result;

                    for (i; i < len; i++) {
                        combinedData.push(data[i].value);
                    }

                    result = d3.scale.linear().domain([0, d3.max(combinedData)]).range([this._options.margin * 2, this._options.height - this._options.margin * 4]);
                    return result;
                },

                _renderPie: function () {

                    var data = this._data
                      , range = this._getRange(data);

                    this.pie = d3.layout.pie().sort(null).value(function(d) {
                        return d.value;
                    });

                    var arc = d3.svg.arc().outerRadius(this._options.innerHeight / 2).innerRadius(this._options.innerHeight / 2 * this._options.innerRadius);
                    var selected = this._group.selectAll('path').data(this.pie(data));
                    var self = this;

                    selected.enter().insert('path').style('fill', function (d, i) {
                        return self._color(i)
                    });

                    this.arcs = selected.attr('d', arc);
                    this.arcs.each(function (val) {
                        val.midPoint = (val.endAngle + val.startAngle) / 2 * 180 / Math.PI;
                    });
                },

                _renderKey: function () {

                    // key is hidden by default via external css. Sharing ignores external css, thus displaying
                    // the key on share.

                    var data = this._data
                      , range = this._getRange(data)
                      , keyItemHeight = 50;


                    var selected = this._key.selectAll('g').data(this.pie(data));
                    var self = this;

                    this._key.append('svg:text').text('Key:').attr('class', 'key-header').attr('y', -20);
                    this._key.append('svg:rect').attr('x',-20).attr('y',-1*keyItemHeight-10).attr('height', keyItemHeight*(data.length+1)+40).attr('width',200).attr('stroke','black').attr('fill','transparent')

                    var keyItem = selected.enter().insert('g')
                        .attr('class', 'key-container').attr('height', keyItemHeight).attr('width', 200)
                        .attr('transform', function (d, i) { return 'translate(0,' + i * keyItemHeight + ')' });
                        
                    keyItem.append('svg:rect').attr('class', 'key-color').attr('fill', function (d, i) {
                        return self._color(i)
                    }).attr('height', keyItemHeight).attr('width', keyItemHeight / 2);

                    keyItem.append('svg:text').attr('class', 'key-label').text(function (d) {
                        var val = d.data.category.replace(/[^\s]+/g, function (str) { return str.substr(0, 1).toUpperCase() + str.substr(1).toLowerCase(); });
                        return val
                    }).attr('x', keyItemHeight * 2 / 3).attr('y', keyItemHeight * 1 / 3);

                    keyItem.append('svg:text').attr('class', 'key-value').text(function (d) {                        
                        return "$"+d.data.value
                    }).attr('x', keyItemHeight * 2 / 3).attr('y', keyItemHeight * 3 / 4);


                },

                _currentArc: function () {
                    return this._getArcAtDegs(this._rotation.selectPoint);
                },

                _getArcAtDegs: function (degs) {

                    var rads
                      , result;

                    while (degs >= 360) {
                        degs -= 360;
                    }

                    rads = degs * Math.PI / 180;

                    this.arcs.each(function (val, i) {
                        if (val.startAngle <= rads && val.endAngle >= rads) {
                            result = val;
                        }
                    });

                    return result;
                },

                _selectedArc: function () {
                    return this._currentArc();
                },

                _rotatePie: function () {
                    this.arcs.attr('transform', 'rotate(' + this._rotation.rotate + ' 0 0)');
                },

                _calculateSelectPoint: function (degs) {
                    // The select point is at 90 deg (east).
                    // However, the 0 point of rotation is actually at the bottom of the arc (south)
                    // Thus, subtract 90 to bring it to the east, but normalize against 360 to be accurate against
                    // values < 360. 

                    var result = Math.abs(degs - 450);

                    while (result > 360) {
                        result -= 360;
                    }

                    return result;
                },

                // public methods
                graphNode: {
                    get: function () {
                        return this._root.querySelector('.graph');
                    }
                },

                rotation: {
                    get: function () {
                        return this._rotation;
                    },
                    set: function (rotate) {
                        
                        this._rotation = {
                            rotate: rotate,
                            selectPoint: this._calculateSelectPoint(rotate)
                        };

                        this._rotatePie();
                    }
                },

                snapToArc: function (arc) {

                    // see the comment under calculateSelectPoint: 
                    var rotateTo = Math.abs(arc.midPoint - 450);
                    if (rotateTo >= 360) rotateTo -= 360;

                    // Selected event is caught by the renderer to handle data selection
                    this.dispatchEvent(SELECTED_EVENT, { selected: arc });

                    var self = this;

                    this.arcs.transition()
                        .duration(500)
                        .attr('transform', 'rotate(' + rotateTo + ' 0 0)');

                    // this sets the current rotation in the data to the same rotation the arc has been 
                    // transformed to. Takes place exactly when the transition finishes.
                    d3.timer(function () {
                        self.rotation = rotateTo;
                        return true
                    }, 500)
                },

                snapToCurrent: function() {
                    var arc = this._selectedArc();
                    this.snapToArc(arc);
                },

                snapToRotation: function (degs) {

                    var norm = this._calculateSelectPoint(degs)
                      , arc = this._getArcAtDegs(norm);

                    this.snapToArc(arc);
                },

                snapToArcAt: function (i) {

                    if (i < 0 || i > this.arcs[0].length) {
                        return;
                    }

                    var arc = this.arcs[0][i].__data__;
                    this.snapToArc(arc);
                }
            },
            {
                // static members
            }
    );

    WinJS.Class.mix(PieChart, WinJS.Utilities.eventMixin);

    WinJS.Namespace.define('Charts', {
        PieChart: PieChart
    });

}());