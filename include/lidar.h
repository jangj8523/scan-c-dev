

#ifndef LIDAR_H
#define LIDAR_H

struct _CLidar {
  /* private: */
  double currSecTime;
  void *scanReading;
  void *currSecScanReading;
  // Must initialize a mqtt class that deals with curr_sec_scan_readings



  /* public: */
  /* Member Functions */


} Lidar;


/* Global Member Functions */
extern void m_lidar_constructor(struct Lidar *this);


#endif
