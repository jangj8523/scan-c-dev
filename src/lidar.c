
#include "lidar.h"


extern void m_lidar_constructor(CButton *this)
{
  /* Initialize the private objects */
  this->scanReading; 
  this->currSecScanReading;
}
