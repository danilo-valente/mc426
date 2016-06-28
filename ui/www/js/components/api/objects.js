(function (angular) {

    'use strict';

    angular
        .module('app.components.api.objects', ['app.components.devices'])
        //.service('doorApi', ['$http', DoorApi])
        .service('doorApi', ['$q', DoorApiMockup])
        .service('lightsApi', ['$http', 'API_ENDPOINT', 'devices', LightsApi]);

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
                    return that.close(id);
                }

                return that.open(id);
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

    function LightsApi($http, API_ENDPOINT, devices) {

        this.getStatus = function (id) {
            return $http.get(API_ENDPOINT + '/ls?i=' + id).then(function (response) {
                return response.data.acesa;
            });
        };

        this.toggle = function (id) {
            var that = this;
            return this.getStatus(id).then(function (status) {
                findObject(parseInt(id)).status = status;
                if (status) {
                    return that.close(id);
                }

                return that.open(id);
            });
        };

        this.open = function (id) {
            return $http.get(API_ENDPOINT + '/le?i=' + id).then(function (response) {
                return response.data.acesa;
            });
        };

        this.close = function (id) {
            return $http.get(API_ENDPOINT + '/ld?i=' + id).then(function (response) {
                return response.data.acesa;
            });
        };

        function findObject(id) {
            return devices.objects.find(function (room) {
                return room.id === id;
            });
        }
    }

})(window.angular);
