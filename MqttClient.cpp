#include "MqttClient.h"

MqttClient::MqttClient() {
  espClient = WiFiClient();
  client = PubSubClient(espClient);
  pinMode(BUILTIN_LED, OUTPUT);
  client.setServer(MQTT_SERVER, MQTT_SERVERPORT);
  client.setCallback([this] (char* topic, byte * payload, unsigned int length) {
    this->callback(topic, payload, length);
  });
}

void MqttClient::connect() {
  while (!client.connected()) {
    if (client.connect(MQTT_CLIENT_NAME, MQTT_USERNAME, MQTT_PASSWORD)) {
      client.publish(MQTT_DISTANCE_PUBLISH_TOPIC, "200");
      client.publish(MQTT_STATE_PUBLISH_TOPIC, "0");
      client.subscribe(MQTT_STATE_SUBSCRIBE_TOPIC);
    } else {
      delay(5000);
    }
  }
}

void MqttClient::loop() {
  if (!client.connected()) {
    this->connect();
  }
  client.loop();
}

void MqttClient::publishDistance(int i) {
  long now = millis();
  if (now - lastMsgDistance > 5000 && i != lastDistance) {
    lastMsgDistance = now;
    lastDistance = i;
    String distance = String(i);
    int len = distance.length() + 1;
    char charBuf[len];
    distance.toCharArray(charBuf, len);
    client.publish(MQTT_DISTANCE_PUBLISH_TOPIC, charBuf) ;
  }
}

void MqttClient::publishState(int i) {
  long now = millis();
  if (now - lastMsgState > 5000 && i != lastState) {
    lastMsgState = now;
    lastState = i;
    String state = String(i);
    int len = state.length() + 1;
    char charBuf[len];
    state.toCharArray(charBuf, len);
    client.publish(MQTT_STATE_PUBLISH_TOPIC, charBuf);
  }
}

void MqttClient::setCallback(EventCallback *eventCallback) {
  this->eventCallback = eventCallback;
}

void MqttClient::callback(char* topic, byte* payload, unsigned int length) {
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);
    if (eventCallback != NULL ) {
      eventCallback->callback(SWITCH_OPEN_DOOR_PAYLOAD);
    }
  } else {
    digitalWrite(BUILTIN_LED, HIGH);
    if (eventCallback != NULL ) {
      eventCallback->callback(SWITCH_CLOSE_DOOR_PAYLOAD);
    }
  }
}

