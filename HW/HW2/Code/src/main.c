//Main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "filehandler.h"

extern int *input_ptr;


#ifdef DEBUG_MODE
#define dbg_printf(fmt, ...) printf("[%s][%s][%d]: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)
#else
#define dbg_printf(...)
#endif



int main(int argc, char *argv[]){	//argc is the number of arguments, argv is the array of arguments
		
#ifdef DEBUG_MODE
	printf("DEBUG MODE\n");
	
	dbg_printf("argc = %d", argc);

	for (int i = 0; i < argc; i++) {
        	dbg_printf("argv[%d] = %s", i, argv[i]);
    	}
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
		file_read(filename);

	}else if(strncmp(option, "-e", 2) == 0){
		printf("Option: %s\n", option);
		printf("ILP solver\n");
		printf("Filename: %s\n", filename);
		file_read(filename);

	}else{
		printf("Invalid option\n");
		return 1;	
	}



	return 0;
}
