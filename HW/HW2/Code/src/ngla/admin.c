//admin.c
#include "admin.h"
#include "station.h"
#include "select.h"
//for terminal echoing
#include <termios.h>
#include <unistd.h>
//
#define PSK_LEN 20

bool get_psk(char *password){
	struct termios old_term, new_term;

    	/* Turn off terminal echoing */
	tcgetattr(STDIN_FILENO, &old_term);
    	new_term = old_term;
    	new_term.c_lflag &= ~(ECHO);
    	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
	/* Turn off terminal echoing */

	printf("Please enter the Admin PSK : ");
	while(getchar()!= '\n')
		continue;

	scanf("%20s", password);
	//login
	//printf("Login Status : %d \n", station_login(password));
	//
	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);

	if(station_login(password)){
		printf("\nLogin Success ! \n");
		return true;
	}else{
		printf("\nLogin Failed\n");
		return false;
	}
	/*Turn on terminal echoing*/
	/*Turn on terminal echoing*/
	//printf("password is : %s", password);

}
void admin_menu()
{
	char PSK[PSK_LEN + 1];
	int choice = '\0';
	
	const char *starray[]={"BR" , "BL" , "G" , "Y" , "R"};
	if(!get_psk(PSK))
		exit(0);

	
	

		printf("|==================================|\n");
		printf("|                                  |\n");
		printf("|   Select    what    to    do     |\n");
		printf("|----------------------------------|\n");
		printf("|   1. Set     Station     Info    |\n");
		printf("|   2. Show    Station     Info    |\n");
		printf("|   3. Search     User     Info    |\n");
		printf("|   4. Exit                        |\n");
		printf("|==================================|\n");

		printf("Please enter your choice => ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				//list station color line  
				#ifdef _WIN32
					system("cls");
				#else
					system("clear");
				#endif
				//BR
				//R
				//G
				//O
				//BL
				
				int selection = colo_selection();	
				int st = st_selection(&selection);
				printf("Select Info : %s  Line  %d Station\n", starray[selection], st);
				*In_set(starray[selection], &st);
				/*
				 * char *colo = In_Colo_get();
				 *printf("Station IN : %s --> %d \n", colo, *In_st_get());
				 */
				//set_station_info();   need to implement (ask for PSK and call *station_login(*PSK))
				break;
			case 2:
				//search_user_info();   need to implement
				break;
			case 3:


				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid Input\n");
				exit(0);
		}
	lock_reset();
	
}
