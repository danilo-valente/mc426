(function (angular) {

    'use strict';

    angular
        .module('app', [
            'ionic',
            'app.controllers.login',
            'app.controllers.main',
            'app.controllers.main.menu',
            'app.controllers.main.menu.map',
            'app.controllers.main.rooms',
            'app.controllers.main.rooms.details',
            'app.controllers.main.notifications'
        ])
        .run(run)
        .config(config)
        .constant('API_ENDPOINT', 'http://10.0.0.2');

    function run($ionicPlatform) {
        $ionicPlatform.ready(function () {
            if (window.cordova && window.cordova.plugins && window.cordova.plugins.Keyboard) {
                cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);
                cordova.plugins.Keyboard.disableScroll(true);

            }
            if (window.StatusBar) {
                StatusBar.styleDefault();
            }
        });
    }

    function config($ionicConfigProvider, $urlRouterProvider) {
        $ionicConfigProvider.backButton.text('Voltar');
        $urlRouterProvider.otherwise('/login');
    }

})(window.angular);
