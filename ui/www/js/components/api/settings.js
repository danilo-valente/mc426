(function (angular) {

    'use strict';

    angular
        .module('app.components.api.settings', ['app.components.devices'])
        //.service('settingsApi', ['$http', SettingsApi])
        .service('settingsApi', ['$q', 'devices', SettingsApiMockup]);

    function SettingsApiMockup($q, devices) {

        this.getRooms = function () {
            var deferred = $q.defer();
            deferred.resolve(devices.rooms);
            return deferred.promise;
        };

        this.getRoom = function (id) {
            var deferred = $q.defer();
            deferred.resolve(findRoom(parseInt(id)));
            return deferred.promise;
        };

        this.getMap = function () {
            var deferred = $q.defer();
            deferred.resolve(devices);
            return deferred.promise;
        };

        function findRoom(id) {
            return devices.rooms.find(function (room) {
                return room.id === id;
            });
        }
    }

})(window.angular);