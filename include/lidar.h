

#ifndef LIDAR_H
#define LIDAR_H

#define SCAN_ARRAY_SIZE 720
#define READING_MAP_SIZE 100

#include "MQTTClient.h"




struct c_lidar {
  /* private: */
  double curr_sec_time;
  int *scan_reading;
  int **curr_sec_scan_readings;
  MQTTClient *client;
  struct MQTTConfig *config;

  // Must initialize a mqtt class that deals with curr_sec_scan_readings
};
void lidar_init(struct c_lidar* self);
void _free_lidar(struct c_lidar* self);
void lidar_start_scan(struct c_lidar* self);
/* Global Member Functions */
extern void m_lidar_constructor(struct c_lidar *this);


#endif
