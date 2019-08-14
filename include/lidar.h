

#ifndef LIDAR_H
#define LIDAR_H

#define SCAN_ARRAY_SIZE 720
#define READING_MAP_SIZE 100

#include "MQTTClient.h"



struct C_Lidar {
  /* private: */
  double curr_sec_time;
  int *scan_reading;
  int **curr_sec_scan_readings;

  // Must initialize a mqtt class that deals with curr_sec_scan_readings
};

void lidar_init(struct C_Lidar* self);


/* Global Member Functions */
extern void m_lidar_constructor(struct C_Lidar *this);


#endif
