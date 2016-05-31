(function (angular) {

    'use strict';

    angular
        .module('app.controllers.main.menu', ['app.components.api.security'])
        .config(['$stateProvider', function ($stateProvider) {

            $stateProvider
                .state('main.menu', {
                    url: '/menu',
                    views: {
                        'main.menu@main': {
                            templateUrl: 'views/main/menu.html',
                            controller: ['$scope', 'alarmApi', MenuCtrl]
                        }
                    }
                });
        }]);

    function MenuCtrl($scope, alarmApi) {

        $scope.items = [
            {
                icon: 'ion-home',
                sref: '.map',
                text: 'Visão Geral'
            }, {
                icon: 'ion-radio-waves',
                sref: '.security',
                text: 'Segurança'
            }, {
                icon: 'ion-stats-bars',
                sref: '.stats',
                text: 'Estatísticas'
            }, {
                icon: 'ion-gear-a',
                sref: '.settings',
                text: 'Configurações'
            }
        ];

        $scope.alarmStatus = false;

        $scope.toggleAlarm = function () {
            alarmApi.toggle().then(function (status) {
                $scope.alarmStatus = status;
            });
        };

        alarmApi.getStatus().then(function (status) {
            $scope.alarmStatus = status;
        });
    }

})(window.angular);