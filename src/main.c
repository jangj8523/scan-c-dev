
#ifndef BASIC_H
#define BASIC_H
#include <stdio.h>
#include <stdlib.h>
#endif /* BASIC_H */

#include <MQTTClient.h>
#include "lidar.h"




int main()
{
   // printf() displays the string inside quotation
   printf("========= RUNNING LIDAR CLIENT IMPLEMENTED IN C =========!\n");
   struct c_lidar active_lidar;
   lidar_init(&active_lidar);
   lidar_connect(&active_lidar);
   //lidar_create_MQTTClient(&active_lidar);
   // Create a lidar class that creates the mqtt client
   // Loops infinitely
   // And free resources



   return 0;
}
