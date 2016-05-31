(function (angular) {

    'use strict';

    angular
        .module('app.controllers.main.menu.map', [
            'app.components.map',
            'app.components.api.settings'
        ])
        .config(['$stateProvider', function ($stateProvider) {

            $stateProvider
                .state('main.menu.map', {
                    url: '/map',
                    views: {
                        'main.menu@main': {
                            templateUrl: 'views/main/menu/map.html',
                            controller: ['$scope', 'settingsApi', MapCtrl]
                        }
                    }
                });
        }]);

    function MapCtrl($scope, settingsApi) {

        $scope.map = null;

        settingsApi.getMap().then(function (map) {
            $scope.map = map;
        });
    }

})(window.angular);