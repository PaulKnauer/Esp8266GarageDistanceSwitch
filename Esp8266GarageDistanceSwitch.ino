#include <ESP8266WiFi.h>

#include "UserConfig.h"
#include "HcSr04.h"
#include "MqttClient.h"
#include "GarageDoorState.h"

MqttClient *client;
GarageDoorState *state;
HcSr04 *hcSr04 = new HcSr04(D0, D5);

void setup() {
  setUpWiFi();
  client = new MqttClient();
  state = new GarageDoorState();
  client->setCallback(state);
}

void loop() {
  delay(DELAY);
  client->loop();
  int distance = hcSr04->getDistanceInCm();
  client->publishDistance(distance);
  state->setDistance(distance);
  if (state->getState() == STATE_OPEN) {
    client->publishState(SWITCH_OPEN_DOOR_PAYLOAD);
  } else if (state->getState() == STATE_CLOSED) {
    client->publishState(SWITCH_CLOSE_DOOR_PAYLOAD);
  }
}

void setUpWiFi() {
  delay(10);
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

