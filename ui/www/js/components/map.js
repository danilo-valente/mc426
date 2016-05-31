(function (angular) {

    'use strict';

    angular
        .module('app.components.map', ['app.components.api.objects'])
        .directive('mcMap', [MapDirective])
        .directive('mcRoomMap', [RoomMapDirective])
        .directive('mcMapRoom', [MapRoomDirective])
        .directive('mcMapObject', ['doorApi', 'lightsApi', MapObjectDirective]);

    function MapDirective() {

        var template = '' +
            '<div class="map">' +
            '<mc-map-room ng-show="floor.id == room.floor" room="room" ng-repeat="room in rooms"></mc-map-room>' +
            '<mc-map-object ng-show="floor.id == obj.floor" object="obj" ng-repeat="obj in objects"></mc-map-object>' +
            '</div>';

        return {
            restrict: 'E',
            template: template,
            replace: true,
            scope: {
                rooms: '=',
                floors: '=',
                objects: '=',
                floor: '='
            },
            link: function (scope, element) {

                var height = scope.rooms.reduce(function (height, room) {
                    return Math.max(height, room.y + room.height);
                }, 0);

                element.css({ height: height + 'px' });
            }
        };
    }

    function RoomMapDirective() {

        var template = '' +
            '<div class="map">' +
            '<mc-map-room room="room" offset-x="room.x" offset-y="room.y"></mc-map-room>' +
            '<mc-map-object object="obj" offset-x="room.x" offset-y="room.y" ng-repeat="obj in objects"></mc-map-object>' +
            '</div>';

        return {
            restrict: 'E',
            template: template,
            replace: true,
            scope: {
                room: '=',
                objects: '='
            },
            link: function (scope, element) {

                var height = scope.room.y + scope.room.height;
                element.css({ height: height + 'px' });
            }
        };
    }

    function MapRoomDirective() {

        var template = '<img class="map-room" ng-src="{{ room.image }}" />';

        return {
            restrict: 'E',
            template: template,
            replace: true,
            scope: {
                room: '=',
                offsetX: '=',
                offsetY: '='
            },
            link: function (scope, element) {

                var offsetX = scope.offsetX || 0;
                var offsetY = scope.offsetY || 0;

                element.css({
                    left: (scope.room.x - offsetX) + 'px',
                    top: (scope.room.y - offsetY) + 'px'
                });
            }
        };
    }

    function MapObjectDirective(doorApi, lightsApi) {

        var template = '' +
            '<a class="button map-object" ng-class="buttonClass[object.status]" ng-click="toggle()">' +
            '<i class="ion" ng-class="iconClass[object.status]"></i>' +
            '</a>';

        return {
            restrict: 'E',
            template: template,
            replace: true,
            scope: {
                object: '=',
                offsetX: '=',
                offsetY: '='
            },
            link: function (scope, element) {

                var offsetX = scope.offsetX || 0;
                var offsetY = scope.offsetY || 0;

                var api;

                scope.iconClass = {};

                scope.buttonClass = {
                    true: 'button-balanced',
                    false: 'button-assertive'
                };

                switch (scope.object.type) {

                    case 'door':
                        api = doorApi;
                        scope.iconClass = {
                            true: 'ion-locked',
                            false: 'ion-unlocked'
                        };
                        break;

                    case 'light':
                        api = lightsApi;
                        scope.iconClass = {
                            true: 'ion-ios-lightbulb',
                            false: 'ion-ios-lightbulb-outline'
                        };
                        break;
                }

                scope.toggle = function () {
                    api.toggle(scope.object.id).then(function (status) {
                        scope.object.status = status;
                    });
                };

                element.css({
                    left: (scope.object.x - offsetX) + 'px',
                    top: (scope.object.y - offsetY) + 'px'
                });
            }
        }
    }

})(window.angular);