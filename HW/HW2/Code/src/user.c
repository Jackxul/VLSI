
//user.c
#include "user.h"
#include "station.h"
#include "account.h"
#include "map.h"
#include "file.h"
void user_menu()
{
	char *test_in = In_Colo_get();
	char *test_out = Out_Colo_get();
	int choice = '\0';
	int fno;
	//const char *test[]={"BR" , "BL" , "G" , "Y" , "R"};
	printf("|==================================|\n");
	printf("|                                  |\n");
	printf("|   Select    what    to    do     |\n");
	printf("|----------------------------------|\n");
	printf("|   1. Buy      A         Card     |\n");
	printf("|   2. Take     The       MRT      |\n");
	printf("|   3. Add      Value    (Top  Up) |\n");
	printf("|   4. Buy      One-Way   Ticket   |\n");
	printf("|==================================|\n");

	printf("Please enter your choice => ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			//buy_card();
			//
			//
			//

			fno = create_info_text();
			*account_init(fno);
			fileprint(&fno);
			break;
		case 2:
			
			printf("Station IN : %s --> %d \n", test_in, *In_st_get());
			printf("Station Out : %s --> %d \n", test_out, *Out_st_get());
			int d = stat_cal(test_in, *In_st_get(),test_out, *Out_st_get());
			printf("Distance : %d \n", d);
			break;
		case 3:
			//add_value();
			printf("Please enter your Account ID => ");
			scanf("%d", &fno);
			set_account_wallet(&fno);
			break;
		case 4:
			//buy_one_way_ticket();
			break;
		default:
			printf("Invalid choice!\n");
			exit(0);
	}
}
