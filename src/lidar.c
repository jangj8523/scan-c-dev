


#include "lidar.h"
#include <stdlib.h>
#include "MQTTClient.h"
#include <stdio.h>
#include "osutil.h"
#include <string.h>
#include <rplidar.h>




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
  if ((rc = MQTTClient_connect(*client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
  pubmsg.payload = "Hello World!\n";
  pubmsg.payloadlen = strlen(pubmsg.payload);
  pubmsg.qos = 0;
  pubmsg.retained = 0;
  MQTTClient_publishMessage(*client, config->pub_topic, &pubmsg, &token);
  printf("Waiting for up to %d seconds for publication of %s\n"
          "on topic %s for client with ClientID: %s\n",
          (int)(10000L/1000), pubmsg.payload, config->pub_topic, config->client_id);
  rc = MQTTClient_waitForCompletion(*client, token, (int)10000L/1000);
  printf("Message with delivery token %d delivered\n", token);
}

void lidar_start_scan(struct c_lidar* self)
{

}

void _free_lidar (struct c_lidar* self) {
  MQTTClient_disconnect(*self->client, 10000);
  MQTTClient_destroy(self->client);
  free(self->scan_reading);
  for(size_t i = 0; i < READING_MAP_SIZE; i++)
  {
    if ((self->curr_sec_scan_readings+i) != NULL)
    {
      free(self->curr_sec_scan_readings+i);
    }
  }
  free(self->curr_sec_scan_readings);
}


void lidar_connect(struct c_lidar* self) {

}

void lidar_init(struct c_lidar* self) {
  self->scan_reading = (int *) malloc(SCAN_ARRAY_SIZE*sizeof(int));
  self->curr_sec_scan_readings = (int**) malloc (READING_MAP_SIZE * sizeof(int));
  self->config = parse_mqtt_configuration();
  _initialize_mqtt_client(self->client, self->config);
}
