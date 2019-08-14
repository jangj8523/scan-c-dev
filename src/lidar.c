
#include "lidar.h"
#include <stdlib.h>
#include "MQTTClient.h"
#include <stdio.h>
#include "osutil.h"




static void _initialize_mqtt_client(MQTTClient *client, struct MQTTConfig *config);


static void _initialize_mqtt_client(MQTTClient *client, struct MQTTConfig *config) {
  client = (MQTTClient*) malloc (sizeof(MQTTClient));
  MQTTClient_message pubmsg = MQTTClient_message_initializer;
  MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
  MQTTClient_deliveryToken token;
  int rc;

  MQTTClient_create(client, config->bridge_address, config->client_id,
      MQTTCLIENT_PERSISTENCE_NONE, NULL);
  conn_opts.keepAliveInterval = 20;
  conn_opts.cleansession = 1;
}

void _free_lidar (struct c_lidar* self) {

}


void lidar_connect(struct c_lidar* self) {

}

void lidar_init(struct c_lidar* self) {
  self->scan_reading = (int *) malloc(SCAN_ARRAY_SIZE*sizeof(int));
  self->curr_sec_scan_readings = (int**) malloc (READING_MAP_SIZE * sizeof(int));
  self->config = parse_mqtt_configuration();
  _initialize_mqtt_client(self->client, self->config);
}
