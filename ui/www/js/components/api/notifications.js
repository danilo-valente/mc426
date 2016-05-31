(function (angular) {

    'use strict';

    angular
        .module('app.components.api.notifications', [])
        //.service('notificationsApi', ['$http', NotificationApi])
        .service('notificationsApi', ['$q', NotificationApiMockup]);

    function NotificationApiMockup($q) {

        var $notifications = [
            {
                date: new Date(2016, 4, 11, 23, 10),
                text: 'Alarme Desativado',
                level: 0
            }, {
                date: new Date(2016, 4, 11, 18, 30),
                text: 'Alarme Ativado',
                level: 0
            }, {
                date: new Date(2016, 4, 10, 23, 10),
                text: 'Alarme Desativado',
                level: 0
            }, {
                date: new Date(2016, 4, 10, 21, 31),
                text: 'Protocolo 01 já acionado',
                level: 1
            }, {
                date: new Date(2016, 4, 10, 21, 30),
                text: 'Sensor Quarto Alertado',
                level: 1
            }, {
                date: new Date(2016, 4, 10, 21, 21),
                text: 'Protocolo 01 acionado',
                level: 1
            }, {
                date: new Date(2016, 4, 10, 21, 20),
                text: 'Sensor Sala Alertado',
                level: 1
            }, {
                date: new Date(2016, 4, 10, 18, 22),
                text: 'Alarme Ativado',
                level: 0
            }
        ];

        this.getNotifications = function () {
            var deferred = $q.defer();
            deferred.resolve($notifications);
            return deferred.promise;
        };
    }

})(window.angular);