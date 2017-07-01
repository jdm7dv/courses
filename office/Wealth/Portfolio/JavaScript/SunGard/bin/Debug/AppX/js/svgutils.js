//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF 
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A 
//// PARTICULAR PURPOSE. 
//// 
//// Copyright (c) Microsoft Corporation. All rights reserved     
////
//// To see the topic that inspired this sample app, go to http://msdn.microsoft.com/en-us/library/windows/apps/dn163530

(function (global) {
    "use strict";

    var crytography = Windows.Security.Cryptography.CryptographicBuffer
      , xmlLoadSettings = new Windows.Data.Xml.Dom.XmlLoadSettings()
      , serializer = new XMLSerializer();

    // Configure XmlLoadSettings
    xmlLoadSettings.prohibitDtd = false;
    xmlLoadSettings.resolveExternals = true;

    // Expose to the global scope
    global.svgutils = {
        convertToImg:    convertToImg,
        convertToCanvas: convertToCanvas,
        convertToString: convertToString,
        convertToXml:    convertToXml,
        base64Encode:    base64Encode,
        uriEncode:       uriEncode
    };

    /**
     * Converts a valid SVG element to text. This can then be
     * saved as a local file, used as the src of an <img> element,
     * for example
     *
     * @param svgElement The SVGElement to convert
     */
    function convertToString(svgElement) {
        return serializer.serializeToString(svgElement);
    }

    /**
     * Converts a valid SVG element to an XML document that can
     * be traversed through normal DOM methods
     *
     * @param svgElement The SVGElement to convert
     */
    function convertToXml(svgElement) {

        var xmldoc = new Windows.Data.Xml.Dom.XmlDocument()
          , svgstr = convertToString(svgElement);

        xmldoc.loadXml(svgstr, xmlLoadSettings);
    }

    /**
     * Creates a new <img> element, and applies the SVG element
     * to its src attribute
     *
     * @param svgElement The SVGElement to convert
     */
    function convertToImg(svgElement) {

        var img = new Image();

        img.width = svgElement.clientWidth;
        img.height = svgElement.clientHeight;
        img.src = base64Encode(svgElement);

        return img;
    }

    /**
     * Creates a new <canvas> element, and renders the
     * SVG element within it
     *
     * @param svgElement The SVGElement to convert
     */
    function convertToCanvas(svgElement, fill) {

        return new WinJS.Promise(function (complete) {

            var body = document.querySelector('body')
              , canvas = document.createElement('canvas')
              , context = canvas.getContext('2d')
              , img = convertToImg(svgElement);

            img.onload = function () {

                var x = 0
                  , y = 0
                  , w = img.width
                  , h = img.height
                  , event = document.createEvent('customevent');

                img.onload = null;

                canvas.width = w;
                canvas.height = h;

                if (fill) {
                    context.fillStyle = 'white';
                    context.fillRect(x, y, w, h);
                }

                context.drawImage(img, x, y, w, h);
                complete(canvas);
            }

        });
    }

    /**
     * Converts an SVG element to a base64 encoded string
     *
     * @param svgElement The SVGElement to convert
     */
    function base64Encode(svgElement) {

        var encoding = Windows.Security.Cryptography.BinaryStringEncoding.utf8
          , svgstr = convertToString(svgElement)
          , buffer = crytography.convertStringToBinary(svgstr, encoding);

        return ['data:image/svg+xml;charset=utf-8;base64,', crytography.encodeToBase64String(buffer)].join('');
    }

    /**
     * Converts an SVG element to a URI encoded string
     *
     * @param svgElement The SVGElement to convert
     */
    function uriEncode(svgElement) {

        var svgstr = convertToString(svgElement);

        return ['data:image/svg+xml,', encodeURIComponent(svgstr)].join('');
    }

}(window));