(function (angular) {

    'use strict';

    angular
        .module('app.components.api.settings', [])
        //.service('settingsApi', ['$http', SettingsApi])
        .service('settingsApi', ['$q', SettingsApiMockup]);

    function SettingsApiMockup($q) {

        var $objects = [
            {
                id: 1,
                type: 'light',
                status: false,
                x: 150,
                y: 170,
                floor: 0
            }, {
                id: 2,
                type: 'door',
                status: false,
                x: -22,
                y: 40,
                floor: 0
            }, {
                id: 3,
                type: 'door',
                status: false,
                x: 295,
                y: 260,
                floor: 0
            }, {
                id: 4,
                type: 'light',
                status: false,
                x: 460,
                y: 100,
                floor: 0
            }, {
                id: 5,
                type: 'light',
                status: false,
                x: 460,
                y: 250,
                floor: 0
            }, {
                id: 6,
                type: 'door',
                status: false,
                x: 295,
                y: 200,
                floor: 1
            }, {
                id: 7,
                type: 'light',
                status: false,
                x: 460,
                y: 170,
                floor: 1
            }, {
                id: 8,
                type: 'light',
                status: false,
                x: 150,
                y: 170,
                floor: 1
            }
        ];

        var $rooms = [
            {
                id: 1,
                name: 'Sala',
                x: 0,
                y: 0,
                width: 326,
                height: 400,
                floor: 0,
                image: 'img/map1.png',
                objects: [$objects[0], $objects[1], $objects[2]]
            }, {
                id: 2,
                name: 'Cozinha',
                x: 316,
                y: 0,
                width: 326,
                height: 400,
                floor: 0,
                image: 'img/map2.png',
                objects: [$objects[2], $objects[3], $objects[4]]
            }, {
                id: 3,
                name: 'Quarto 1',
                x: 0,
                y: 0,
                width: 326,
                height: 400,
                floor: 1,
                image: 'img/map1.png',
                objects: [$objects[5], $objects[7]]
            }, {
                id: 4,
                name: 'Quarto 2',
                x: 316,
                y: 0,
                width: 326,
                height: 400,
                floor: 1,
                image: 'img/map2.png',
                objects: [$objects[5], $objects[6]]
            }
        ];

        var $floors = [
            {
                id: 0,
                name: 'Térreo',
                objects: [$objects[0], $objects[1], $objects[2], $objects[3], $objects[4]],
                rooms: [$rooms[0], $rooms[1]]
            }, {
                id: 1,
                name: 'Segundo andar',
                objects: [$objects[5], $objects[6], $objects[7]],
                rooms: [$rooms[2], $rooms[3]]
            }
        ];

        this.getRooms = function () {
            var deferred = $q.defer();
            deferred.resolve($rooms);
            return deferred.promise;
        };

        this.getRoom = function (id) {
            var _id = parseInt(id);
            var deferred = $q.defer();
            deferred.resolve($rooms.find(function (room) {
                return room.id === _id;
            }));
            return deferred.promise;
        };

        this.getMap = function () {
            var deferred = $q.defer();
            deferred.resolve({
                rooms: $rooms,
                floors: $floors,
                objects: $objects,
                floor: $floors[0]
            });
            return deferred.promise;
        };
    }

})(window.angular);