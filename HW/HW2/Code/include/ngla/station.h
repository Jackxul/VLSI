//station.h
#ifndef STATION_H
#define STATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#include "account.h"
//for both
//Need to be modify
static struct station{
	char in_color[10];
	char out_color[10];
	int in_number;
	int out_number;
	time_t time;
	char PSK[10];
	bool lock;
	pthread_mutex_t mutex;
} ST = {
	"BR",
	"R",
	12,
	9,
	0,
	"NGLAB_2023",
	0,
	PTHREAD_MUTEX_INITIALIZER
};


bool station_login(char *PSK);//for login to set station setting
void lock_reset();

void *In_set(const char *color , int *num );//for set station setting
void *Out_set(const char *color , int *num );//for set station setting
char *In_Colo_get();//for set station setting
int *In_st_get();//for set station setting
char *Out_Colo_get();//for set station setting
int *Out_st_get();//for set station setting
								   //
void check_remain(Acc *account);//for check account remain >= 0

#endif /* STATION_H */ 
