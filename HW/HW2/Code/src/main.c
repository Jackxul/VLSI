//Main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "account.h"
//#include "station.h"
//#include "map.h"
#include "user.h"
#include "admin.h"
int main(){
	char choice = '\0';
	bool invalid = false;

//	Acc *acorigin = account_init();	
	//set the account
//	set_account_number(acorigin, 0);
//	set_account_name(acorigin, "Jack");
//	set_account_wallet(acorigin, 100);
	//print the account
	//
	//
	//some example of how to access account variables
//	printf("Account Number: %d\n", get_account_number(acorigin));
//	printf("Account Name: %s\n", get_account_name(acorigin));
//	printf("Account Wallet: %d\n", get_account_wallet(acorigin));

	//Need to be implemented
	//stat_cal(*get_account_station_in_color(acorigin), get_account_station_in_no(acorigin), *get_account_station_out_color(acorigin), get_account_station_out_no(acorigin));

	printf("|==================================|\n");
	printf("|                                  |\n");
	printf("|   Welcome to the Metro System    |\n");
	printf("|----------------------------------|\n");
	printf("|   1. U s e r       M o d e       |\n");
	printf("|   2. A d m i n     M o d e       |\n");
	printf("|   3. E x i t                     |\n");
	printf("|                                  |\n");
	printf("|==================================|\n");
	while(true){
		if(!invalid)
			printf("Please enter your choice => ");
		choice = getchar();
		printf("\n");
		if(choice == '1'){
			printf("User Mode\n");
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
			user_menu();
			break;
		}
		else if(choice == '2'){
			printf("Admin Mode\n");
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
			admin_menu();
			break;
		}
		else if(choice == '3'){
			printf("Exit\n");
			exit(0);
		}else{
			if(!invalid)
				printf("Invalid Input\n");
			invalid = true;
			choice = '\0';
		}

	}
	//print out accout station info
	/*
	printf("Account Station In Color: %s ->", get_account_station_in_color(acorigin));
	printf("%d\n", get_account_station_in_no(acorigin));
	printf("Account Station Out Color: %s ->", get_account_station_out_color(acorigin));
	printf("%d\n", get_account_station_out_no(acorigin));
	*/

	//some example of how to access account variables
	//
	//
/*
	int *p = &acorigin->wallet;
	printf("Wallet for now : %d\n", *p);

	printf("========\nEnter Station ...\n========\n");
	
	check_remain(acorigin);

	printf("Station Info : %s -> %d\n", get_account_station_in_color(acorigin), get_account_station_in_no(acorigin));

	printf("Lock Stat : %d\n", acorigin->lock);

	printf("========\nExit Station ...\n========\n");

	set_account_wallet(acorigin, -1);

	printf("Station Info : %s -> %d\n", get_account_station_out_color(acorigin), get_account_station_out_no(acorigin));

	check_remain(acorigin);

	printf("Lock Stat : %d\n", acorigin->lock);
*/
	return 0;
}
//EOF
