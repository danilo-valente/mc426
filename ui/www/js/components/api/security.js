(function (angular) {

    'use strict';

    angular
        .module('app.components.api.security', [])
        .service('alarmApi', ['$q', '$http', 'API_ENDPOINT', AlarmApi]);
        //.service('alarmApi', ['$q', AlarmApiMockup]);

    function AlarmApi($q, $http, API_ENDPOINT) {

        var $alarmStatus = false;

        this.getStatus = function () {
            var deferred = $q.defer();
            deferred.resolve($alarmStatus);
            return deferred.promise;
        };

        this.enable = function () {
            return $http.get(API_ENDPOINT + '/monit/ativar').then(function (response) {
                return response.status;
            });
        };

        this.disable = function () {
            return $http.get(API_ENDPOINT + '/monit/desativar').then(function (response) {
                return response.status;
            });
        };

        this.toggle = function () {
            if ($alarmStatus) {
                return this.disable();
            }

            return this.enable();
        };
    }

    function AlarmApiMockup($q) {

        var $alarmStatus = false;

        this.getStatus = function () {
            var deferred = $q.defer();
            deferred.resolve($alarmStatus);
            return deferred.promise;
        };

        this.toggle = function () {
            $alarmStatus = !$alarmStatus;
            return this.getStatus();
        };
    }

})(window.angular);