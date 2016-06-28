#include <Arduino.h>
#include <IPAddress.h>

#include "AuthHandler.h"
#include "LightStatusHandler.h"
#include "TurnOnLightHandler.h"
#include "TurnOffLightHandler.h"
#include "MonitoringStatusHandler.h"
#include "EnableMonitoringHandler.h"
#include "DisableMonitoringHandler.h"

#include "DeviceManager.h"

#include "WebServer.h"
#include "User.h"
#include "Monitoramento.h"
#include "Movimento.h"
#include "Audio.h"
#include "Gas.h"
#include "Tank.h"
#include "Flame.h"
#include "Power.h"

//#define DEBUG

#define PORT 80
#define BAUD 9600

#if defined(__AVR_ATmega2560__)
#define PINS        52
#define PIN_GAS     A0
#define PIN_POWER_1 A1
#define PIN_POWER_2 A2
#define PIN_AUDIO    3
#define PIN_PIR     22
#define PIN_LIGHT_1 30
#define PIN_LIGHT_2 31
#define PIN_LIGHT_3 32
#define PIN_LIGHT_4 33
#define PIN_FLAME   39
#define PIN_TANK    41
#elif defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
#define PINS        13
#define PIN_GAS     A0
#define PIN_POWER_1 A1
#define PIN_POWER_2 A2
#define PIN_AUDIO    3
#define PIN_PIR      4
#define PIN_LIGHT_1  5
#define PIN_LIGHT_2  6
#define PIN_LIGHT_3  7
#define PIN_LIGHT_4  8
#define PIN_FLAME    9
#define PIN_TANK    10
#endif

#define AUDIO_FREQUENCY 4
#define AUDIO_MAX_VALUE 510

#define GAS_MIN_VALUE 250

#define PIR_MIN_VALUE 500

#define POWER_CALIBRATION 93
#define POWER_SAMPLES 1480
#define POWER_SCALE 3600000
#define POWER_PRECISION 5

// Endpoints
const char EP_AUTH[] = "a";
const char EP_LIGHT_STATUS[] = "ls";
const char EP_TURN_ON_LIGHT[] = "le";
const char EP_TURN_OFF_LIGHT[] = "ld";
const char EP_MONITORING_STATUS[] = "ms";
const char EP_ENABLE_MONITORING[] = "me";
const char EP_DISABLE_MONITORING[] = "md";

// Users
User adminUser("admin", "pwd", "Administrador");

// Device Manager
DeviceManager devices;

// Devices
Lampada light1(PIN_LIGHT_1);
Lampada light2(PIN_LIGHT_2);
Lampada light3(PIN_LIGHT_3);
Lampada light4(PIN_LIGHT_4);

Audio audio(PIN_AUDIO, AUDIO_FREQUENCY, AUDIO_MAX_VALUE);
Gas gas(PIN_GAS, GAS_MIN_VALUE, &audio, &light2);
Movimento pir(PIN_PIR, PIR_MIN_VALUE, &audio, &light1);
Tank tank(PIN_TANK, &audio);
Flame flame(PIN_FLAME, &audio);
Power power(PIN_POWER_1, PIN_POWER_2, POWER_CALIBRATION, POWER_SAMPLES, POWER_SCALE, POWER_PRECISION);

Monitoramento monitoring;

// Handlers
AuthHandler authHandler;

LightStatusHandler lightStatusHandler(&devices);
TurnOnLightHandler turnOnLightHandler(&devices);
TurnOffLightHandler turnOffLightHandler(&devices);

MonitoringStatusHandler monitoringStatusHandler(&monitoring);
EnableMonitoringHandler enableMonitoringHandler(&monitoring);
DisableMonitoringHandler disableMonitoringHandler(&monitoring);

// WebServer
const uint8_t mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10, 0, 0, 2);
WebServer server(PORT, mac, ip);

void setup() {
    Serial.begin(BAUD);
    while (!Serial);

    authHandler.addUser(&adminUser);

    devices.add(&light1);
    devices.add(&light2);
    devices.add(&light3);
    devices.add(&light4);
    devices.add(&audio);
    devices.add(&gas);
    devices.add(&tank);
    devices.add(&flame);
    devices.add(&power);
    devices.setup();

    server.registerHandler(EP_AUTH, &authHandler);
    server.registerHandler(EP_LIGHT_STATUS, &lightStatusHandler);
    server.registerHandler(EP_TURN_ON_LIGHT, &turnOnLightHandler);
    server.registerHandler(EP_TURN_OFF_LIGHT, &turnOffLightHandler);
    server.registerHandler(EP_MONITORING_STATUS, &monitoringStatusHandler);
    server.registerHandler(EP_ENABLE_MONITORING, &enableMonitoringHandler);
    server.registerHandler(EP_DISABLE_MONITORING, &disableMonitoringHandler);
    server.setup();

    monitoring.addDevice(&pir);
    monitoring.setup();
}

void loop() {
    server.loop();
    monitoring.loop();
    devices.loop();

#ifdef DEBUG
    readAll();
    delay(1000);
#endif
}

#ifdef DEBUG
void readAll() {
    int i;
    Serial.print("M = ");
    Serial.println(monitoring.getStatus() ? "true" : "false");
    for (i = 1; i <= PINS; i++) {
        Serial.print(i);
        Serial.print(" = ");
        Serial.println(digitalRead(i));
    }
    Serial.println();
}
#endif
