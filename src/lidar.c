
#include "lidar.h"
#include <stdlib.h>
#include "MQTTClient.h"


void Lidar_init(struct C_Lidar* self) {
  self->scan_reading = (int *) malloc(SCAN_ARRAY_SIZE*sizeof(int));
  self->curr_sec_scan_readings = (int**) malloc (READING_MAP_SIZE * sizeof(int));

 }
