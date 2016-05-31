(function (angular) {

    'use strict';

    angular
        .module('app.components.api.security', [])
        //.service('alarmApi', ['$http', AlarmApi])
        .service('alarmApi', ['$q', AlarmApiMockup]);

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