(function (angular) {

    'use strict';

    angular
        .module('app.controllers.main.rooms', ['app.components.api.settings'])
        .config(['$stateProvider', function ($stateProvider) {

            $stateProvider
                .state('main.rooms', {
                    url: '/rooms',
                    views: {
                        'main.rooms@main': {
                            templateUrl: 'views/main/rooms.html',
                            controller: ['$scope', 'settingsApi', RoomsCtrl]
                        }
                    }
                });
        }]);

    function RoomsCtrl($scope, settingsApi) {

        $scope.rooms = [];

        settingsApi.getRooms().then(function (rooms) {
            $scope.rooms = rooms;
        });
    }

})(window.angular);