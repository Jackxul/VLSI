//station_in.h
//  Created by  on 2012-11-13.
#ifndef STATION_IN_H
#define STATION_IN_H

#include "account.h"
#include <time.h>
#include <string.h>
//check account lock   lock:0 ==> pass , lock:1 ==> block	
//record station color
//record station number
//record time


//for in
char set_station_in(Acc *account , char *color , int num);//for set station status to account



#endif /* STATION_IN_H */
