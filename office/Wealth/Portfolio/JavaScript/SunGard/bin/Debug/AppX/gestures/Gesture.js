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

    var constructors = []
      , types = []
      , eventMap = {
          'MSPointerDown': '_onPointerDown',
          'MSPointerUp': '_onPointerUp',
          'MSGestureStart': '_onGestureStart',
          'MSGestureChange': '_onGestureChange',
          'MSGestureEnd': '_onGestureEnd',
          'MSGestureTap': '_onGestureTap'
      };

    /**
     * The Gesture class is meant to be the basis for custom Gesture classes.
     * It works with the PointerManager, and creates and maintains an instance
     * of MSGesture when made active.
     *
     * @param DOMElement element
     * @param Object options
     */
    var Gesture = WinJS.Class.define(

        function (element, options) {

            var options = options || {};

            this.target = element;

            // Prevent the target element from accepting native gestures
            this.target.style.msTouchAction = 'none';

            this.msgesture = null;
            this.primaryPointer = null;

            this.options = {};

            // The minimum number of pointers that should be present before this
            // gesture will activate
            this.options.minPointers = options.minPointers || 1;

            // The maximum number of pointers that can be present before this
            // gesture will deactivate
            this.options.maxPointers = options.maxPointers || 1;

            // Bind event handlers to the scope of this instance
            this.eventHandler = this._eventHandler.bind(this);
            this.bindEvents();
        },

        {
            bindEvents: function () {
                this.target.addEventListener('MSPointerDown', this.eventHandler, true);
                this.target.addEventListener('MSGestureStart', this.eventHandler, true);
                this.target.addEventListener('MSGestureChange', this.eventHandler, true);
                this.target.addEventListener('MSGestureEnd', this.eventHandler, true);
                this.target.addEventListener('MSGestureTap', this.eventHandler, true);
            },

            _eventHandler: function (evt) {

                // Ignore gesture events that are not for "this.target". This only happens
                // when there are gestures assigned to both an element and one of its children
                if (evt.gestureObject && evt.gestureObject.target != this.target) return;

                // Call the appropriate event handler
                this[eventMap[evt.type]].call(this, evt);
            },

            _onPointerDown: function (evt) {

                var numPointers = Gestures.PointerManager.count
                  , pointer;

                // If there are too many or too few pointers, then stop the gestutre
                if (numPointers > this.options.maxPointers || numPointers < this.options.minPointers) {
                    (this.msgesture) && this.release();
                }
                else if (this.msgesture == null) {

                    pointer = Gestures.PointerManager.requestPointer(this);

                    // PointerManager may not have any pointers to give,
                    // so check the result first then set up the gesture
                    if (pointer) {
                        this.primaryPointer = pointer;
                        this.msgesture = new MSGesture();
                        this.msgesture.target = this.target;
                        this.msgesture.addPointer(this.primaryPointer);
                        this.target.gesture = this.msgesture;
                    }
                }
            },

            _onGestureStart: function (evt) {
                // Override this in a concrete class...
            },

            _onGestureChange: function (evt) {
                // Override this in a concrete class...
            },

            _onGestureEnd: function (evt) {
                // Override this in a concrete class...
            },

            _onGestureTap: function(evt) {
                // Override this in the concrete class...
            },

            release: function () {

                Gestures.PointerManager.returnPointer(this.primaryPointer);

                if (this.msgesture) {

                    // Halt the gesture immediately
                    this.msgesture.stop();
                }

                this.primaryPointer = null;
                this.msgesture = null;
                this.target.gesture = null;
            }
        },

        {
            /**
             * Gesture factory. Creates gestures of a given type, and assigns
             * them to a DOM element.
             *
             * @param String type
             * @param DOMElement element
             */
            create: function (type, element) {

                var index = types.indexOf(type);

                if (index > -1) {
                    return new constructors[index](element);
                }
                else {
                    throw new Error('Gestures.create: "' + type + '" is not a valid gesture type');
                }
            },

            /**
             * Classes that derive from Gesture may register themselves with
             * the factory here.
             *
             * @param String type
             * @param Function constructor
             */
            register: function (type, constructor) {
                constructors.push(constructor);
                types.push(type);
            }
        }
    );

    WinJS.Namespace.define('Gestures', {
        Gesture: Gesture,

        // Convenience method for the factory
        create: Gesture.create,

        // Convenience method for gesture registration
        register: Gesture.register
    });

    // Register the default Gesture with the factory
    Gestures.register('default', Gestures.Gesture);

}());