

#ifndef OS_UTIL_H
#define OS_UTIL_H

#include <stdlib.h>
#include <stdio.h>
#include "MQTTClient.h"

struct MQTTConfig {
  char *bridge_address;
  char *client_id;
  char *sub_topic;
  char *pub_topic;
  int QoS;
  long int timeout;
};


struct MQTTConfig* parse_mqtt_configuration();
void free_configs();

#endif
