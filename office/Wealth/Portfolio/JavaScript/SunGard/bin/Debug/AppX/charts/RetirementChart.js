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

    var duration = 500;

    var RetirementChart = WinJS.Class.define(

            function (element, data, options) {

                options = options || {};

                this._root = element;

                this._options = {
                    colors: options.colors || ['#1A6600', '#004000', '#B2CBD4', '#042200'],
                    height: options.height || 500,
                    width: options.width || 920,
                    margin: options.margin || 0,

                    // home view doesn't show the key
                    showKey: options.showKey === undefined ? true : options.showKey
                }
                this.dom = {};
                this.meta = {};

                this._render(data);
            },

            {
                _render: function (data) {                    

                    var self = this;

                    this.dom.stage = d3.select(this._root).append('svg').attr('id', 'planning').attr('height', this._options.height).attr('width', this._options.width);
                    
                    this.dom.space = { 
                        height: this._options.height,
                        width: this._options.width,
                        margin: this._options.margin,
                        graph: {                            
                        },
                        key: {
                            height: this._options.height
                        },
                        chart: {
                            height: this._options.height,                           
                        },
                        meta: {
                            offsetLeft: 80,
                            offsetBottom: 60
                        }
                    };

                    // the number of horizontal lines on the chart
                    this.meta.lineCount = 11;

                    // Creation of various SVG groups to be referenced throughout
                    this.dom.key = this.dom.stage.append('g').attr('id', 'planning-key');
                    this.dom.chart = this.dom.stage.append('g').attr('id', 'planning-chart');
                    this.dom.meta = this.dom.chart.append('g').attr('id', 'planning-meta');
                    this.dom.graph = this.dom.chart.append('g').attr('id', 'planning-graph');
                    
                    if (this._options.showKey == true) {
                        this.dom.space.chart.width = Math.floor(this._options.width * 2 / 3);
                        this.dom.space.key.width = Math.floor(this._options.width / 3);                        
                    } else {
                        this.dom.space.chart.width = this._options.width;
                        this.dom.space.key.width = 0;
                        this.dom.key.attr('transform', 'scale(0)');
                    }

                    this.dom.space.chart.height = this.dom.space.height;
                    this.dom.space.graph.height = this.dom.space.chart.height - this.dom.space.meta.offsetBottom;
                    this.dom.space.graph.width = this.dom.space.chart.width - this.dom.space.meta.offsetLeft;

                    this.dom.key
                        .attr('height', this.dom.space.key.height)
                        .attr('width', this.dom.space.key.width)

                    this.dom.chart                            
                        .attr('height', this.dom.space.chart.height)
                        .attr('width', this.dom.space.chart.width)
                        .attr('transform', 'translate(' + this.dom.space.key.width + ',0)')

                    this.dom.graph
                        .attr('height', this.dom.space.graph.height)
                        .attr('width', this.dom.space.graph.width)
                        .attr('transform', 'translate(' + this.dom.space.meta.offsetLeft + ',0)')
                    
                    this.dom.meta = this.dom.meta.attr('width', this.dom.space.chart.width).attr('height', this.dom.space.chart.height).attr('transform', 'translate(0,0)');
                    this.dom.bars = this.dom.graph.append('g').attr('id', 'bar-group').attr('width', this.dom.space.graph.width).attr('height', this.dom.space.graph.height).attr('transform','translate(0,0)');
                    this.dom.lines = this.dom.graph.append('g').attr('id', 'line-group').attr('width', this.dom.space.graph.width).attr('height', this.dom.space.graph.height).attr('transform','translate(0,0)');
                    

                    this.update(data);

                    // Add the listeners to show the highlighted pieces of data, but only on the detail view
                    if (this._options.showKey) {
                        this.dom.graph[0][0].addEventListener('MSPointerMove', this._mousemove.bind(this));
                        this.dom.graph[0][0].addEventListener('MSPointerDown', this._mousemove.bind(this));
                    }
                },

                update: function (data) {
                    this.data = data;
                    
                    // Barwidth = the space / the number of data points / the number of data types (+1 for the gap)
                    this._barWidth = Math.ceil((this.dom.space.graph.width) / (this.data[0].data.length * ((this.data.length / 2) + 1)));
                    this._range = this._getRange(this.data);                   

                    // These scales are used by the mouseover handler to attach a pointer position to a data point
                    this._scales = {
                        spaceXScale: d3.scale.linear().range([0, this.dom.space.graph.width]),
                        dataXScale: d3.scale.linear().domain([0, 1]).range([0, this.data[0].data.length])
                    };

                    // Renders a line or bar depending
                    var barIdx = 0, lineIdx = 0;
                    for (var i = 0, len = this.data.length; i < len; i++) {
                        if (this.data[i].displayType == "bar") {
                            this._renderBarGraph(this.data, barIdx, i);
                            barIdx++;
                        }
                        if (this.data[i].displayType == "line") {
                            this._renderLine(this.data, lineIdx, i);
                            lineIdx++;
                        }
                    }

                    this._renderKey(this.data);
                    this._renderMeta(this.data);
                },

                _getRange: function (data) {
                    // combined data gets all the data values, and runs a max method

                    var combinedData = []
                      , i = 0
                      , j = 0
                      , len = data.length
                      , itemLen = data[0].data.length
                      , result
                      , key;

                    for (i; i < len; i++) {
                        j = 0;
                        for (j; j < itemLen; j++) {
                            combinedData.push(data[i].data[j].value);
                        }
                    }
                    this.meta.dataMax = d3.max(combinedData);

                    result = d3.scale.linear()
                                  .domain([0, this.meta.dataMax])
                                  .range([this.dom.space.margin * 2, this.dom.space.graph.height - this.dom.space.margin * 4]);

                    return result;                
                },

                _renderBarGraph: function (data, idx, i) {

                    // Each bar is dynamically created, transitioned, or removed. 
                    var self = this
                      , key = data[i].key
                      , selected = this.dom.bars.selectAll('rect.bar-' + key).data(data[i].data, function (d) { return d.time.toUTCString(); })
                      , floor = this.dom.space.graph.height - this.dom.space.margin
                      , fn = {
                          x: function (d, i) {
                              // time division + index division
                              return (i * self._barWidth * ((self._data.length / 2) + 1) + (self._barWidth * idx))
                          },
                          y: function (d, i) {
                              return floor - self._range(d.value);
                          },
                          h: function (d, i) {
                              return self._range(d.value);
                          },
                          w: this._barWidth
                      };

                    selected.enter().insert('rect')
                      .attr('class', 'bar-' + key)
                      .attr('x', fn.x)
                      .attr('y', floor)
                      .attr('height', 0)
                      .attr('width', fn.w)
                      .attr('fill', this._options.colors[idx]);

                    selected.transition()
                      .delay(duration)
                      .duration(duration)
                        .attr('x', fn.x)
                        .attr('y', fn.y)
                        .attr('height', fn.h)
                        .attr('width', fn.w);

                    selected.exit().transition()
                      .duration(duration)
                      .attr('y', floor)
                      .attr('height', 0)
                      .remove();
                },

                _renderLine: function (data, idx, i) {

                    var self = this 
                      , key = data[idx].key
                      , selected = this.dom.lines.selectAll('path#line-' + key)
                      , floor = this.dom.space.graph.height - this.dom.space.margin
                      , line = d3.svg.line().interpolate('basis')
                        .x(function(d, i) { 
                            return (i * self._barWidth * ((self._data.length / 2) + 1) + (self._barWidth));
                        })
                        .y(function (d, i) {
                            // if val > the size of the chart, the lines will extend beyond the bounds of the chart. 
                            // This ensures that the lines stay within the range.
                            var val = floor - self._range(d.value);
                            return val > self.dom.space.graph.height ? self.dom.space.graph.height : val ;
                        });

                    // unlike the bars, there need to be two lines regardless of the bumber of data points.
                    // This checks to see if lines exist already, and uses them if true.
                    if (selected[0].length > 0) {
                        selected = selected.data(data[i].data);
                    } else {
                        selected = this.dom.lines.append('path').attr('id', 'line-' + key).data(data[i].data)
                    }

                    selected.transition().duration(duration).delay(duration).attr('d', line(data[i].data)).attr('stroke', this._options.colors[i]).attr('fill', 'none');

                },

                _renderKey: function (data, idx) {
                    // Idx is used to specify if a data point is selected. 
                    if (!idx) idx = 0;
                   
                    // A key item is created for each data type in the array.
                    var self = this
                      , selected = this.dom.key.selectAll('g').data(data)
                      , circleWidth = 30

                      , keyItem = selected.enter().insert('g')
                                    .attr('data-keyIndex', function (d, i) { return i; })
                                    .attr('data-keyName', function (d, i) { return d.key; })
                                    .attr('class', 'keyItem')
                                    .attr('transform', function (d, i) { return 'translate(' + circleWidth + ', ' + (i * circleWidth * 3 + 50) + ')' })

                      , circles = keyItem.append('svg:circle').attr('r', 18)
                                    .attr('stroke', function (d, i) { return self._options.colors[i] })
                                    .attr('fill', 'transparent')
                                    .attr('stroke-width', 15)
                      , amounts = keyItem.append('svg:text').attr('class', 'amount')
                                    .attr('y', function () { return -5 })
                                    .attr('x', function () { return circleWidth + 10 })
                                    .attr('style','font-size: 20px; font-weight: bold')
                      , labels = keyItem.append('svg:text').attr('class', 'label')
                                    .attr('y', function () { return 15 })
                                    .attr('x', function () { return circleWidth + 10 })
                                    .attr('width', '100');

                    var yearLabel = this.dom.key.selectAll('text.year-label');

                    if (yearLabel[0].length < 1) {
                        yearLabel = this.dom.key.append('svg:text').attr('class', 'year-label')
                            .attr('y', 15);
                    }
                    yearLabel.text(function (d) {
                        return self.data[1].data[idx].time.getFullYear()+' Values'
                    });
                    // IE10 does not yet support svg:textArea, so this is used to force line breaks. 
                    labels.each(function (d) {
                        for (var i = 0; i < d.label.length; i++) {
                            d3.select(this).append('svg:tspan')
                                .attr('y', (i * 20) + 15)
                                .attr('x', circleWidth + 10)
                                .text(d.label[i]);
                        }
                    });

                    var i = -1;
                    selected.transition().selectAll('text.amount').text(function (d) {
                        i++;
                        return '$'+self.data[i].data[idx].value.toFixed(2).toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
                    }) 
                },

                _renderMeta: function (data, mouseoverIdx) {
                    var metaData = this._generateMetaData(data)
                    var dataGross;


                    var self = this
                      , selected = this.dom.meta
                      , lineHeight = this.dom.space.graph.height / this.meta.lineCount
                      , floor = this.dom.space.height - this.dom.space.margin - 30
                      , fn = {
                          x: function (d, i) {
                              // time division + index division
                              return (i * self._barWidth * ((self._data.length / 2) + 1) + self.dom.space.meta.offsetLeft + self._barWidth)
                          },
                          y: function (d, i) {
                              return floor - self._range(d.value);
                          },
                          h: function (d, i) {
                              return self._range(d.value);
                          },
                          w: this._barWidth
                      }


                      , labels = selected.selectAll('text.bottomLabel').data(metaData.labels)
                      , lines = selected.selectAll('path.meta-lines-line').data(metaData.lines)
                      , lineLabels = selected.selectAll('text.meta-lines-label').data(metaData.lines);

                    // Some styles, such as the white color of the text, are in a separate css file. These styles
                    // aren't applied to the svg on share, so the text is viewable on the white background of the
                    // shared image.
                    labels.enter().append('svg:text')
                                .attr('y', floor)
                                .text(function (d, i) { return d.time.getFullYear() })
                    labels.transition()
                        .attr('class', function (d, i) {
                            if (i == mouseoverIdx || mouseoverIdx == undefined && i == 0) {
                                return 'bottomLabel selected'
                            }
                            return 'bottomLabel'
                        })
                        .attr('x', fn.x)
                        .attr('style', function (d, i) {
                            if (i == mouseoverIdx || mouseoverIdx == undefined && i == 0) {
                                return 'font-size: 20px; font-weight: bold; text-anchor: middle;'
                            }
                            return 'text-anchor: middle;'
                        })

                    labels.exit().remove();                        

                    lines.enter().append('svg:path').attr('class', 'meta-lines-line')
                    lines.attr('d', function (d, i) { return 'M ' + self.dom.space.chart.width + ' ' + i * lineHeight+ ' L 0 ' + i * lineHeight });
                    lines.exit().remove()

                    lineLabels.enter().append('svg:text').attr('class', 'meta-lines-label')
                        .attr('x', 0).attr('y', function (d, i) { return i * lineHeight + 20 })
                    lineLabels.transition().delay(duration).text(function (d) {
                        return '$' + Math.floor(d).toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",")
                    });
                    lineLabels.exit().remove();
                },

                _generateMetaData: function (data) {
                    var obj = {};

                    obj.labels = data[0].data;
                    obj.lines = [];

                    for (var i = 0; i < this.meta.lineCount + 1; i++) {
                        obj.lines.push(this.meta.dataMax - (this.meta.dataMax * i / this.meta.lineCount));
                    }

                    return obj;
                },

                _mousemove: function (e) {
                    // it appears that the mousemove event, while attached to the chart, returns x values relative to the parent div
                    // of the svg. Thus, an offset is calculated based on the chart's relative position to the svg + the margin.

                    var offset = this.dom.space.key.width +10 + this.dom.space.meta.offsetLeft;

                    var x0 = this._scales.spaceXScale.invert(e.x - offset);  
                    var i = Math.floor(this._scales.dataXScale(x0));
                    var year = this.data[1].data[i].time.getFullYear();

                    this._renderKey(this.data, i);
                    this._renderMeta(this.data, i);
                    this.dispatchEvent('change', { year: year });
                },


                data: {
                    get: function () {
                        return this._data;
                    },
                    set: function (value) {
                        this._data = value;
                    }
                }

               
            },
            {
                // static members
            }
    );

    WinJS.Class.mix(RetirementChart, WinJS.Utilities.eventMixin);

    WinJS.Namespace.define('Charts', {
        RetirementChart: RetirementChart
    });

}());