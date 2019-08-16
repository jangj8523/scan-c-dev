

#include <stdio.h>
#include <stdlib.h>
#include "osutil.h"
#include <unistd.h>


#define ADDRESS     "localhost:1883"
#define CLIENTID    "jangj8523"
#define SUB_TOPIC   "jetson"
#define PUB_TOPIC   "lidar"
#define PAYLOAD     "Hello World!"
#define QOS         0
#define TIMEOUT     10000L
#define MQTT_FILE_NAME "mqtt_config.txt"
#define BUFFER_DEFAULT_SIZE 50
#define PATH_MAX    100


static char *get_curr_dir(char *buf, size_t size);


static char *get_curr_dir(char *buf, size_t size){
  char* cwd = malloc(PATH_MAX);
  if (getcwd(cwd, PATH_MAX) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       exit(EXIT_FAILURE);
   }
   // return cwd;
   // char buff [] = "/home/pi/jaewoo_work/c_lidar/src";
   // return buff;
}

void free_configs(struct MQTTConfig *config) {
  free(config->bridge_address);
  free(config->client_id);
  free(config->sub_topic);
  free(config->pub_topic);
  free(config);
}


struct MQTTConfig *parse_mqtt_configuration() {
  struct MQTTConfig *config = (struct MQTTConfig *)malloc(sizeof(struct MQTTConfig));
  config->QoS = 0;
  config->timeout = 10000L;
  FILE *fp;
  fp  = fopen ("/home/pi/jaewoo_work/c_lidar/src/mqtt_config.txt", "r");
  if (fp == NULL)
  {
    printf ("Configuration to MQTT Bridge does not exist\n");
    exit(EXIT_FAILURE);
  }

  int counter = 0;
  char ch;
  char*buffer = (char*)malloc(BUFFER_DEFAULT_SIZE);
  size_t curr_buff_size = BUFFER_DEFAULT_SIZE;
  size_t curr_length=0;

  while (counter < 4)
  {
    ch = fgetc(fp);
    if (buffer == NULL)
    {
        buffer = malloc(BUFFER_DEFAULT_SIZE);
        curr_buff_size = BUFFER_DEFAULT_SIZE;
    }
    if (sizeof(buffer) == curr_length)
    {
        buffer = realloc(buffer, 2 * curr_buff_size);
        curr_buff_size = 2 * curr_buff_size;
    }
    *(buffer+curr_length) = ch;
    if (ch == '\n' || ch == '\0')
    {
      switch(counter) {
        case 0:
          config->bridge_address = buffer;
        case 1:
          config->client_id = buffer;
        case 2:
          config->sub_topic = buffer;
        case 3:
          config->pub_topic = buffer;
      }
      buffer = NULL;
      counter += 1;
      curr_length = -1;
    }
    curr_length+=1;

  }
  printf("MQTT Bridge_address %s\n", config->bridge_address);
  printf("Client ID %s\n", config->client_id);
  printf("Subscribe Topic %s\n", config->sub_topic);
  printf("Publish Topic %s\n", config->pub_topic);

  return config;
}
