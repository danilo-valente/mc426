(function (angular) {

    'use strict';

    angular
        .module('app.controllers.main.notifications', ['app.components.api.notifications'])
        .config(['$stateProvider', function ($stateProvider) {

            $stateProvider
                .state('main.notifications', {
                    url: '/notifications',
                    views: {
                        'main.notifications@main': {
                            templateUrl: 'views/main/notifications.html',
                            controller: ['$scope', 'notificationsApi', MenuCtrl]
                        }
                    }
                });
        }]);

    function MenuCtrl($scope, notificationsApi) {

    }

})(window.angular);