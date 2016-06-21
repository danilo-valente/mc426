(function (angular) {

    'use strict';

    angular
        .module('app.components.api.objects', ['app.components.devices'])
        //.service('doorApi', ['$http', DoorApi])
        .service('doorApi', ['$q', DoorApiMockup])
        .service('lightsApi', ['$q', '$http', 'API_ENDPOINT', 'devices', LightsApi]);
        //.service('lightsApi', ['$q', LightsApiMockup]);

    function DoorApiMockup($q) {

        var status = {};

        this.getStatus = function (id) {
            var deferred = $q.defer();
            deferred.resolve(!!status[id]);
            return deferred.promise;
        };

        this.toggle = function (id) {
            var that = this;
            return this.getStatus(id).then(function (status) {
                if (status) {
                    return that.open(id);
                }

                return that.close(id);
            });
        };

        this.open = function (id) {
            status[id] = false;
            return this.getStatus(id);
        };

        this.close = function (id) {
            status[id] = true;
            return this.getStatus(id);
        };
    }

    function LightsApi($q, $http, API_ENDPOINT, devices) {

        this.getStatus = function (id) {
            var deferred = $q.defer();
            deferred.resolve(findObject(parseInt(id)).status);
            return deferred.promise;
        };

        this.toggle = function (id) {
            var that = this;
            return this.getStatus(id).then(function (status) {
                findObject(parseInt(id)).status = status;
                if (status) {
                    return that.open(id);
                }

                return that.close(id);
            });
        };

        this.open = function (id) {
            return $http.get(API_ENDPOINT + '/lampada/acender?id=' + id).then(function (response) {
                return response.acesa;
            });
        };

        this.close = function (id) {
            return $http.get(API_ENDPOINT + '/lampada/apagar?id=' + id).then(function (response) {
                return response.acesa;
            });
        };

        function findObject(id) {
            return devices.objects.find(function (room) {
                return room.id === id;
            });
        }
    }

    function LightsApiMockup($q) {

        var status = {};

        this.getStatus = function (id) {
            var deferred = $q.defer();
            deferred.resolve(!!status[id]);
            return deferred.promise;
        };

        this.toggle = function (id) {
            var that = this;
            return this.getStatus(id).then(function (status) {
                if (status) {
                    return that.open(id);
                }

                return that.close(id);
            });
        };

        this.open = function (id) {
            status[id] = false;
            return this.getStatus(id);
        };

        this.close = function (id) {
            status[id] = true;
            return this.getStatus(id);
        };
    }

})(window.angular);