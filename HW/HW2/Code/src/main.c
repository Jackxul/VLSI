//Main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "filehandler.h"

#ifdef DEBUG_MODE
#define dbg_printf(fmt, ...) printf("[%s][%s][%d]: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)
#else
#define dbg_printf(...)
#endif


char start_nodes[100][7];

int main(int argc, char *argv[]){  //argc is the number of arguments, argv is the array of arguments
				   //argv[3] is AND_CONSTRAINTS
				   //argv[4] is OR_CONSTRAINTS
				   //argv[5] is NOT_CONSTRAINTS
	if(argc != 6){
		printf("Invalid number of arguments\n");
		return 1;
	}

	char *option = argv[1];
	char *filename = argv[2];
	int _AND_CON = atoi(argv[3]);
	int _OR_CON = atoi(argv[4]);
	int _NOT_CON = atoi(argv[5]);

	if(strncmp(option, "-h", 2) == 0){
		printf("heuristic\n");
		dbg_printf("Option: %s\n", option);
		dbg_printf("Filename: %s\n", filename);
		dbg_printf("AND_CONSTRAINTS: %d\n", _AND_CON);
		dbg_printf("OR_CONSTRAINTS: %d\n", _OR_CON);
		dbg_printf("NOT_CONSTRAINTS: %d\n", _NOT_CON);
		file_read(filename);

	}else if(strncmp(option, "-e", 2) == 0){
		printf("ILP solver\n");
		dbg_printf("Option: %s\n", option);
		dbg_printf("Filename: %s\n", filename);
		dbg_printf("AND_CONSTRAINTS: %d\n", _AND_CON);
		dbg_printf("OR_CONSTRAINTS: %d\n", _OR_CON);
		dbg_printf("NOT_CONSTRAINTS: %d\n", _NOT_CON);
		file_read(filename);

	}else{
		printf("Invalid option\n");
		return 1;	
	}


	return 0;
}
