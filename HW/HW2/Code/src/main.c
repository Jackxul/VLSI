//Main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include "account.h"
//#include "station.h"
//#include "map.h"
#include "filehandler.h"


#ifdef DEBUG_MODE
#define dbg_printf(...) printf("[%s][%s][%d]: " __VA_ARGS__, __FILE__, __FUNCTION__, __LINE__)
#else
#define dbg_printf(...)
#endif



int main(int argc, char *argv[]){	//argc is the number of arguments, argv is the array of arguments
		
#ifdef DEBUG_MODE
	printf("DEBUG MODE\n");
	printf("Number of arguments: %d\n", argc);
	printf("Option: %s\n", argv[1]);
	printf("Filename: %s\n", argv[2]);
#else
	printf("RELEASE MODE\n");
#endif




	char *option = argv[1];
	char *filename = argv[2];
	if(argc != 3){
		printf("Invalid number of arguments\n");
		return 1;
	}else if(strncmp(option, "-h", 2) == 0){
		printf("Option: %s\n", option);
		printf("heuristic\n");
		printf("Filename: %s\n", filename);

	}else if(strncmp(option, "-e", 2) == 0){
		printf("Option: %s\n", option);
		printf("ILP solver\n");
		printf("Filename: %s\n", filename);

	}else{
		printf("Invalid option\n");
		return 1;	
	}


	return 0;
}
