
#include "lidar.h"
#include <stdlib.h>
#include "MQTTClient.h"


#define ADDRESS     "localhost:1883"
#define CLIENTID    "jangj8523"
#define TOPIC       "MQTT Examples"
#define PAYLOAD     "Hello World!"
#define QOS         0
#define TIMEOUT     10000L


static void _initialize_mqtt_client(MQTTClient *client);


static void _initialize_mqtt_client(MQTTClient *client) {
  client = (MQTTClient*) malloc (sizeof(MQTTClient));
  MQTTClient_message pubmsg = MQTTClient_message_initializer;
  MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
  MQTTClient_deliveryToken token;
  int rc;

  MQTTClient_create(client, ADDRESS, CLIENTID,
      MQTTCLIENT_PERSISTENCE_NONE, NULL);
  conn_opts.keepAliveInterval = 20;
  conn_opts.cleansession = 1;
}

void lidar_init(struct c_lidar* self) {
  self->scan_reading = (int *) malloc(SCAN_ARRAY_SIZE*sizeof(int));
  self->curr_sec_scan_readings = (int**) malloc (READING_MAP_SIZE * sizeof(int));
  _initialize_mqtt_client(self->client);
}
