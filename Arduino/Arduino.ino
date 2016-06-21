#include <Arduino.h>
#include <IPAddress.h>

#include "TurnOnLightHandler.h"
#include "TurnOffLightHandler.h"

#include "WebServer.h"
#include "Monitoramento.h"

#define DEBUG

#define PORT 80
#define BAUD 9600

#define PIN_LIGHT_1 6
#define PIN_LIGHT_2 7
#define PIN_LIGHT_3 8
#define PIN_LIGHT_4 9

#define EP_TURN_ON_LIGHT_1 "/lampada/acender?id=1"
#define EP_TURN_OFF_LIGHT_1 "/lampada/apagar?id=1"
#define EP_TURN_ON_LIGHT_2 "/lampada/acender?id=2"
#define EP_TURN_OFF_LIGHT_2 "/lampada/apagar?id=2"
#define EP_TURN_ON_LIGHT_3 "/lampada/acender?id=3"
#define EP_TURN_OFF_LIGHT_3 "/lampada/apagar?id=3"
#define EP_TURN_ON_LIGHT_4 "/lampada/acender?id=4"
#define EP_TURN_OFF_LIGHT_4 "/lampada/apagar?id=4"

Lampada light1(PIN_LIGHT_1);
Lampada light2(PIN_LIGHT_2);
Lampada light3(PIN_LIGHT_3);
Lampada light4(PIN_LIGHT_4);

TurnOnLightHandler turnOnLight1Handler(&light1);
TurnOffLightHandler turnOffLight1Handler(&light1);
TurnOnLightHandler turnOnLight2Handler(&light2);
TurnOffLightHandler turnOffLight2Handler(&light2);
TurnOnLightHandler turnOnLight3Handler(&light3);
TurnOffLightHandler turnOffLight3Handler(&light3);
TurnOnLightHandler turnOnLight4Handler(&light4);
TurnOffLightHandler turnOffLight4Handler(&light4);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10, 0, 0, 2);
WebServer server(PORT, mac, ip);

Monitoramento monitoramento;

void setup() {
    Serial.begin(BAUD);
    while (!Serial);

    server.setup();
    server.registerHandler(EP_TURN_ON_LIGHT_1, &turnOnLight1Handler);
    server.registerHandler(EP_TURN_OFF_LIGHT_1, &turnOffLight1Handler);
    server.registerHandler(EP_TURN_ON_LIGHT_2, &turnOnLight2Handler);
    server.registerHandler(EP_TURN_OFF_LIGHT_2, &turnOffLight2Handler);
    server.registerHandler(EP_TURN_ON_LIGHT_3, &turnOnLight3Handler);
    server.registerHandler(EP_TURN_OFF_LIGHT_3, &turnOffLight3Handler);
    server.registerHandler(EP_TURN_ON_LIGHT_4, &turnOnLight4Handler);
    server.registerHandler(EP_TURN_OFF_LIGHT_4, &turnOffLight4Handler);

    monitoramento.setup();
}

void loop() {
    server.loop();
    monitoramento.loop();
#ifdef DEBUG
    readAll();
    delay(1000);
#endif
}

#ifdef DEBUG
void readAll() {
    int i;
    for (i = 1; i <= 13; i++) {
        Serial.print(i);
        Serial.print(" = ");
        Serial.println(digitalRead(i));
    }
    Serial.println();
}
#endif