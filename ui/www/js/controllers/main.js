(function (angular) {

    'use strict';

    angular
        .module('app.controllers.main', ['app.components.api.notifications'])
        .config(['$stateProvider', '$urlRouterProvider', function ($stateProvider, $urlRouterProvider) {

            $urlRouterProvider.otherwise('/main/menu');

            $stateProvider
                .state('main', {
                    url: '/main',
                    abstract: true,
                    templateUrl: 'views/main.html',
                    controller: ['$scope', 'notificationsApi', MainCtrl]
                });
        }]);

    function MainCtrl($scope, notificationsApi) {

        $scope.notifications = [];

        notificationsApi.getNotifications().then(function (notifications) {
            $scope.notifications = notifications;
        });
    }

})(window.angular);