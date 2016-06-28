(function (angular) {

    'use strict';

    angular
        .module('app.components.api.security', [])
        .service('alarmApi', ['$http', 'API_ENDPOINT', AlarmApi])
        .service('authApi', ['$http', 'API_ENDPOINT', AuthApi]);

    function AlarmApi($http, API_ENDPOINT) {

        this.getStatus = function () {
            return $http.get(API_ENDPOINT + '/ms').then(function (response) {
                return response.data.status;
            });
        };

        this.enable = function () {
            return $http.get(API_ENDPOINT + '/me').then(function (response) {
                return response.data.status;
            });
        };

        this.disable = function () {
            return $http.get(API_ENDPOINT + '/md').then(function (response) {
                return response.data.status;
            });
        };

        this.toggle = function () {
            var that = this;

            return this.getStatus().then(function (status) {
                if (status) {
                    return that.disable();
                }

                return that.enable();
            });
        };
    }

    function AuthApi($http, API_ENDPOINT) {

        this.auth = function (username, password) {
            return $http.get(API_ENDPOINT + '/a', { u: username, p: password }).then(function (response) {
                return response.data;
            });
        };
    }

})(window.angular);
