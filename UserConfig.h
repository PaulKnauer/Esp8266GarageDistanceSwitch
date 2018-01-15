#ifndef UserConfig_h
#define UserConfig_h

#define WLAN_SSID        "kezro"
#define WLAN_PASSWORD    "P@ul123D3bbie"
#define DELAY 100

#define MQTT_CLIENT_NAME "GarageDoor1"
#define MQTT_SERVER      "192.168.2.9"
#define MQTT_SERVERPORT  1883
#define MQTT_USERNAME    "hassio"
#define MQTT_PASSWORD    "hassio"

#define MQTT_STATE_SUBSCRIBE_TOPIC "/Garage/Door1/Switch/State"
#define MQTT_STATE_PUBLISH_TOPIC "/Garage/Door1/State"
#define MQTT_DISTANCE_PUBLISH_TOPIC "/Garage/Door1/Distance"

#define SWITCH_OPEN_DOOR_PAYLOAD 1
#define SWITCH_CLOSE_DOOR_PAYLOAD 0

#define RELAY_TOGGLE_MODE 0
#define RELAY_MOMENTARY_MODE 1

#define DOOR_CLOSED_DISTANCE 200
#define DOOR_OPEN_DISTANCE 10

#define STATE_CLOSED 0
#define STATE_OPEN 1
#define STATE_TRANSITION 99

#endif
