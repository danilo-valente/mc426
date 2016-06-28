(function (angular) {

    'use strict';

    angular
        .module('app.controllers.login', ['app.components.api.security'])
        .config(['$stateProvider', function ($stateProvider) {

            $stateProvider
                .state('login', {
                    url: '/login',
                    templateUrl: 'views/login.html',
                    controller: ['$scope', '$state', 'authApi', LoginCtrl]
                });
        }]);

    function LoginCtrl($scope, $state, authApi) {
        $scope.login = {};
        $scope.error = 0;

        $scope.auth = function (username, password) {
            $scope.error = 0;

            authApi.auth(username, password).then(function (response) {
                if (response.success) {
                    $state.go('main.menu');
                } else {
                    $scope.error = response.error;
                }
            });
        };
    }

})(window.angular);