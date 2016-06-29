(function (angular) {

    'use strict';

    angular
        .module('app.components.devices', [])
        .factory('devices', DevicesFactory);

    function DevicesFactory() {

        var $objects = [
            {
                id: 30,
                type: 'light',
                status: false,
                x: 150,
                y: 170,
                floor: 0
            }, {
                id: 31,
                type: 'light',
                status: false,
                x: 460,
                y: 170,
                floor: 0
            }, {
                id: 32,
                type: 'light',
                status: false,
                x: 150,
                y: 170,
                floor: 1
            }, {
                id: 33,
                type: 'light',
                status: false,
                x: 460,
                y: 170,
                floor: 1
            }, {
                id: 23,
                type: 'door',
                status: false,
                x: 295,
                y: 170,
                floor: 0
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
                objects: [$objects[0], $objects[1]],
                rooms: [$rooms[0], $rooms[1]]
            }, {
                id: 1,
                name: 'Segundo andar',
                objects: [$objects[2], $objects[3]],
                rooms: [$rooms[2], $rooms[3]]
            }
        ];

        return {
            rooms: $rooms,
            floors: $floors,
            objects: $objects,
            floor: $floors[0]
        };
    }

})(window.angular);
