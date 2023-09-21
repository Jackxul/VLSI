//account.h
//Jack_Xul
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
	pthread_mutex_t mutex;
    	int accountNumber;
    	char name[30];
    	int wallet;
	char station_in_color[5];
	int station_in_number;
	char station_out_color[5];
	int station_out_number;
	int lock;//0:unlock 1:lock 
} Acc;
/*	Account init 	*/
Acc *account_init(int fileno);
/*	Account set 	*/
void set_account_number(Acc *account,int value);
void set_account_name(Acc *account,char *name);
void set_account_wallet(int *value);
/*	Account get 	*/
int get_account_number(Acc *account);
char *get_account_name(Acc *account);
int get_account_wallet(Acc *account);
char *get_account_station_in_color(Acc *account);
int get_account_station_in_no(Acc *account);
char *get_account_station_out_color(Acc *account);
int get_account_station_out_no(Acc *account);

int create_info_text();
#endif /* ACCOUNT_H */
