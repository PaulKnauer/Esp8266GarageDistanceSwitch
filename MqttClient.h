#ifndef MqttClient_h
#define MqttClient_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "UserConfig.h"
#include "EventCallback.h"

class MqttClient {
  public:
    MqttClient();
    void connect();
    void loop();
    void publishDistance(int i);
    void publishState(int i);
    void setCallback(EventCallback *eventCallback);
  private:
    long lastMsgDistance = 0;
    int lastDistance = 0;
    long lastMsgState = 0;
    int lastState = 0;
    WiFiClient espClient;
    PubSubClient client;
    EventCallback *eventCallback;
    void callback(char* topic, byte* payload, unsigned int length);
};

#endif
