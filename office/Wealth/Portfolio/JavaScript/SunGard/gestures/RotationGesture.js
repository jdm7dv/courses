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

    /**
     * The RotationGesture was designed to work exclusively with the PieChart control.
     */
    var RotationGesture = WinJS.Class.derive(Gestures.Gesture,

        function (control, options) {

            this.control = control;

            // super()
            Gestures.Gesture.call(this, this.control.graphNode, { minPointers: 1, maxPointers: 99 });
        },

        {
            _onGestureStart: function (evt) {
                // follows the gesture, nad calculates the original offset

                var offset = this.control.rotation.rotate
                  , deg = this._calculateAngle(evt.offsetX, evt.offsetY);

                this._originalOffset = offset - deg;
            },

            _onGestureChange: function (evt) {                

                var deg = this._calculateAngle(evt.offsetX, evt.offsetY);

                this.control.rotation = this._originalOffset + deg;
            },

            _onGestureEnd: function (evt) {
                this.control.snapToCurrent();
            },

            _onGestureTap: function (evt) {

                // handle the other gesture, tapping on the arc

                var offset = this.control.rotation.rotate
                  , deg = this._calculateAngle(evt.offsetX, evt.offsetY);

                this.control.snapToRotation(offset - deg);
            },

            _calculateAngle: function(x, y) {
                // deg is calculated via arctan from a center point, because trigonometry.

                var dx = x - (this.target.clientWidth / 2)
                  , dy = y - (this.target.clientHeight / 2)
                  , deg = (Math.atan2(dy, dx) * 180 / Math.PI);

                return (deg < 0) ? deg + 360 : deg;
            }
        }
    );

    WinJS.Namespace.define('Gestures', {
        RotationGesture: RotationGesture
    });

    // Register the RotationGesture with the factory
    Gestures.register('rotation', Gestures.RotationGesture);

}());