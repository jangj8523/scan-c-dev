

#ifndef LIDAR_H
#define LIDAR_H

struct CLidar {
  /* private: */
  double currSecTime;
  void *scanReading;
  void *currSecScanReading;
  // Must initialize a mqtt class that deals with curr_sec_scan_readings
};

void Lidar_init(CLidar* self, int x, int y) {
  self->x = x;
  self->y = y;
 }


/* Global Member Functions */
extern void m_lidar_constructor(struct Lidar *this);


#endif
