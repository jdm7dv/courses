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
     * The PointerManager class keeps track of touch points as they're added
     * and removed from the device. Gesture classes can request ownership
     * of available points through the requestPointer() method, and return
     * points that they're no longer using through the returnPointer() method.
     */
    var PointerManager = WinJS.Class.define(

        function () {

            this._registry = {};

            // Bind event handlers to the scope of this instance
            this.onPointerDown = this._onPointerDown.bind(this);
            this.onPointerUp = this._onPointerUp.bind(this);

            this._addEventListeners();
        },

        {
            count: {
                get: function () {
                    return Object.keys(this._registry).length;
                }
            },

            _addEventListeners: function () {
                document.addEventListener('MSPointerDown', this.onPointerDown, true);
                document.addEventListener('MSPointerUp', this.onPointerUp, true);
                document.addEventListener('MSPointerCancel', this.onPointerUp, true);
                document.addEventListener('MSLostPointerCapture', this.onPointerUp, true);
            },

            _onPointerDown: function (evt) {

                // Add the new point to the registry
                this._registry[evt.pointerId] = { pointerId: evt.pointerId, owner: null };
            },

            _onPointerUp: function (evt) {

                var pointer = this._registry[evt.pointerId];

                if (pointer) {
                    (pointer.owner) && pointer.owner.release();
                    delete this._registry[evt.pointerId];
                }
            },

            /**
             * Releases all of the current pointers from the PointerManager
             */
            reset: function () {

                for (var key in this._registry) {
                    (this._registry[key].owner) && this._registry[i].owner.release();
                    delete this._registry[key];
                }
            },

            /**
             * When there are pointers available, the PointerManager will
             * return a pointerId, and keep a record of the new "owner"
             *
             * @param Gestures.Gesture owner
             */
            requestPointer: function (owner) {

                var result = null;

                for (var key in this._registry) {

                    if (this._registry[key].owner == null) {
                        this._registry[key].owner = owner;
                        result = this._registry[key].pointerId;
                        break;
                    }
                }

                return result;
            },

            /**
             * Returns the pointer with the given pointerId to the registry.
             *
             * @param Int pointerId
             */
            returnPointer: function (pointerId) {

                var pointer = this._registry[pointerId];

                if (pointer && pointer.owner) {
                    pointer.owner = null;
                }
            }
        }

    );

    // Create a singleton instance of PointerManager
    WinJS.Namespace.define('Gestures', {
        PointerManager: new PointerManager()
    });

}());