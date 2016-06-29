#include <Arduino.h>
#include <IPAddress.h>

#include "AuthHandler.h"
#include "LightStatusHandler.h"
#include "TurnOnLightHandler.h"
#include "TurnOffLightHandler.h"
#include "DoorStatusHandler.h"
#include "OpenDoorHandler.h"
#include "CloseDoorHandler.h"
#include "MonitoringStatusHandler.h"
#include "EnableMonitoringHandler.h"
#include "DisableMonitoringHandler.h"

#include "DeviceManager.h"

#include "WebServer.h"
#include "User.h"
#include "Monitoramento.h"
#include "Lampada.h"
#include "Porta.h"
#include "Movimento.h"
#include "Audio.h"
#include "Gas.h"
#include "Tank.h"
#include "Flame.h"
#include "Power.h"
#include "TempHum.h"

//#define DEBUG

#define PORT 80
#define BAUD 9600

#if defined(__AVR_ATmega2560__)
#define PINS            52
#define PIN_GAS         A0
#define PIN_POWER_1     A1
#define PIN_POWER_2     A2
#define PIN_AUDIO        3
#define PIN_PIR         22
#define PIN_LIGHT_1     30
#define PIN_LIGHT_2     31
#define PIN_LIGHT_3     32
#define PIN_LIGHT_4     33
#define PIN_FLAME       39
#define PIN_TANK        41
#define PIN_DHT         52
#define PIN_HEATER      38
#define PIN_FAN         40
#define PIN_DOOR        23
#define PIN_DOOR_LOCK   24
#elif defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
#define PINS            13
#define PIN_GAS         A0
#define PIN_POWER_1     A1
#define PIN_POWER_2     A2
#define PIN_AUDIO        2
#define PIN_PIR          3
#define PIN_LIGHT_1      4
#define PIN_LIGHT_2      5
#define PIN_LIGHT_3      6
#define PIN_LIGHT_4      7
#define PIN_FLAME        8
#define PIN_TANK         9
#define PIN_DHT         10
#define PIN_HEATER      11
#define PIN_FAN         12
#define PIN_DOOR         0
#define PIN_DOOR_LOCK    1
#endif

#define AUDIO_FREQUENCY 4
#define AUDIO_MAX_VALUE 510

#define GAS_MIN_VALUE 250

#define PIR_MIN_VALUE 500

#define POWER_CALIBRATION 93
#define POWER_SAMPLES 1480
#define POWER_SCALE 3600000
#define POWER_PRECISION 5

#define DHT_TYPE DHT11
#define DHT_MAX_T_HEATER 20
#define DHT_MIN_T_FAN 30

// Endpoints
const char EP_AUTH[] = "a";
const char EP_LIGHT_STATUS[] = "ls";
const char EP_TURN_ON_LIGHT[] = "le";
const char EP_TURN_OFF_LIGHT[] = "ld";
const char EP_DOOR_STATUS[] = "ds";
const char EP_OPEN_DOOR[] = "do";
const char EP_CLOSE_DOOR[] = "dc";
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

Porta door(PIN_DOOR, PIN_DOOR_LOCK);

Audio audio(PIN_AUDIO, AUDIO_FREQUENCY, AUDIO_MAX_VALUE);
Gas gas(PIN_GAS, GAS_MIN_VALUE, &audio, &light2);
Movimento pir(PIN_PIR, PIR_MIN_VALUE, &audio, &light1);
Tank tank(PIN_TANK, &audio);
Flame flame(PIN_FLAME, &audio);
Power power(PIN_POWER_1, PIN_POWER_2, POWER_CALIBRATION, POWER_SAMPLES, POWER_SCALE, POWER_PRECISION);
TempHum tempHum(PIN_DHT, DHT_TYPE, PIN_HEATER, PIN_FAN, DHT_MAX_T_HEATER, DHT_MIN_T_FAN);

Monitoramento monitoring;

// Handlers
AuthHandler authHandler;

LightStatusHandler lightStatusHandler(&devices);
TurnOnLightHandler turnOnLightHandler(&devices);
TurnOffLightHandler turnOffLightHandler(&devices);

DoorStatusHandler doorStatusHandler(&devices);
OpenDoorHandler openDoorHandler(&devices);
CloseDoorHandler closeDoorHandler(&devices);

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
    devices.add(&door);
    devices.add(&audio);
    devices.add(&gas);
    devices.add(&tank);
    devices.add(&flame);
    devices.add(&power);
    devices.add(&tempHum);
    devices.setup();

    server.registerHandler(EP_AUTH, &authHandler);
    server.registerHandler(EP_LIGHT_STATUS, &lightStatusHandler);
    server.registerHandler(EP_TURN_ON_LIGHT, &turnOnLightHandler);
    server.registerHandler(EP_TURN_OFF_LIGHT, &turnOffLightHandler);
    server.registerHandler(EP_DOOR_STATUS, &doorStatusHandler);
    server.registerHandler(EP_OPEN_DOOR, &openDoorHandler);
    server.registerHandler(EP_CLOSE_DOOR, &closeDoorHandler);
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
