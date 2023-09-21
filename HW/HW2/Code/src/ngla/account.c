//account.c
//  Created by  on 2012-11-13.
//private variables
#include "account.h"
/*	Account init function	*/
Acc *account_init(int fileno){
	Acc *account = malloc(sizeof(Acc)); //Still needs to call free()
	if(account){
		account->accountNumber = 0;
		strcpy(account->name, "NULL");
		account->wallet = 100;
		strcpy(account->station_in_color , "N");
		account->station_in_number = -1;
		strcpy(account->station_out_color , "N");
		account->station_out_number = -1;
		pthread_mutex_init(&account->mutex , NULL);//IMPORTANT!!!
		account->lock = 0;

		char path[20];
		bool flag = true;
		sprintf(path, ".data/%d.csv", fileno);
		
		FILE *fp = fopen(path, "a");
		if(fp != NULL){
			fprintf(fp, "%c,%d,%s,%d,%s,%d,%s,%d,%d\n",
					'I',
					fileno,account->name,
					account->wallet,
					account->station_in_color,
					account->station_in_number,
					account->station_out_color,
					account->station_out_number,
					account->lock);
			fclose(fp);
		}else{
			printf("Error: .txt open failed!\n");
		}
		flag = false;
		printf("(Account init success!)\n");
	}else{
		printf("Error: Account init failed!\n");
	}	
	return account;
}

/*	set functions	*/
void set_account_number(Acc *account,int value){
	pthread_mutex_lock(&account->mutex);
	account->accountNumber = value;
	pthread_mutex_unlock(&account->mutex);
}
void set_account_name(Acc *account,char *name){
	pthread_mutex_lock(&account->mutex);
	strcpy(account->name, name);
	pthread_mutex_unlock(&account->mutex);
}
void set_account_wallet(int *value){
	Acc *account = malloc(sizeof(Acc)); //Still needs to call free()
	pthread_mutex_lock(&account->mutex);
	account->wallet = *value;
	pthread_mutex_unlock(&account->mutex);
}
void set_account_station_in_color(Acc *account,char *color){
	pthread_mutex_lock(&account->mutex);
	strcpy(account->station_in_color , color);
	pthread_mutex_unlock(&account->mutex);
}
void set_account_station_in_no(Acc *account,int num){
	pthread_mutex_lock(&account->mutex);
	account->station_in_number = num;
	pthread_mutex_unlock(&account->mutex);
}
void set_account_station_out_color(Acc *account,char *color){
	pthread_mutex_lock(&account->mutex);
	strcpy(account->station_out_color , color);
	pthread_mutex_unlock(&account->mutex);
}
void set_account_station_out_no(Acc *account,int num){
	pthread_mutex_lock(&account->mutex);
	account->station_out_number = num;
	pthread_mutex_unlock(&account->mutex);
}
/*	get functions	*/
int get_account_number(Acc *account){
	int value;
	pthread_mutex_lock(&account->mutex);
	value = account->accountNumber;
	pthread_mutex_unlock(&account->mutex);
	return value;
}
char *get_account_name(Acc *account){
	char *name;
	pthread_mutex_lock(&account->mutex);
	name = account->name;
	pthread_mutex_unlock(&account->mutex);
	return name;
}
int get_account_wallet(Acc *account){
	int value;
	pthread_mutex_lock(&account->mutex);
	value = account->wallet;
	pthread_mutex_unlock(&account->mutex);
	return value;
}
char *get_account_station_in_color(Acc *account){
	char *color;
	pthread_mutex_lock(&account->mutex);
	color = account->station_in_color;
	pthread_mutex_unlock(&account->mutex);
	return color;
}
int get_account_station_in_no(Acc *account){
	int num;
	pthread_mutex_lock(&account->mutex);
	num = account->station_in_number;
	pthread_mutex_unlock(&account->mutex);
	return num;
}
char *get_account_station_out_color(Acc *account){
	char *color;
	pthread_mutex_lock(&account->mutex);
	color = account->station_out_color;
	pthread_mutex_unlock(&account->mutex);
	return color;
}
int get_account_station_out_no(Acc *account){
	int num;
	pthread_mutex_lock(&account->mutex);
	num = account->station_out_number;
	pthread_mutex_unlock(&account->mutex);
	return num;
}
int create_info_text(){
	int fileno = 0;
	char path[20];
	bool flag = true;
	while(flag){
		sprintf(path, ".data/%d.csv", fileno);
		if(access(path, F_OK) == 0){
			//printf("Error: info.txt already exists!\n");
			fileno++;
			continue;
		}else{
			
			//doen't exist
			FILE *fp = fopen(path, "w");
			if(fp != NULL){
				fprintf(fp, "index,AccountID,AccountName,Wallet,In_Colo,In_no,Out_Colo,Out_no,Lock\n");
				fclose(fp);
			}else{
				printf("Error: .txt open failed!\n");
			}
			flag = false;
		}

	}
	printf("Thanks for your purchase !\nYour Account ID is : %d  ", fileno);
return fileno;
}

void account(){



}
