(function (angular) {

    'use strict';

    angular
        .module('app.controllers.main.rooms.details', [
            'app.components.map',
            'app.components.api.settings'
        ])
        .config(['$stateProvider', function ($stateProvider) {

            $stateProvider
                .state('main.rooms.details', {
                    url: '/details/:id',
                    views: {
                        'main.rooms@main': {
                            templateUrl: 'views/main/rooms/details.html',
                            controller: ['$scope', '$stateParams', 'settingsApi', DetailsCtrl]
                        }
                    }
                });
        }]);

    function DetailsCtrl($scope, $stateParams, settingsApi) {

        $scope.room = null;

        settingsApi.getRoom($stateParams.id).then(function (room) {
            $scope.room = room;
            console.log(room.name);
        });
    }

})(window.angular);