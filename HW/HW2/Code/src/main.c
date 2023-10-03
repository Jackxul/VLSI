//Main.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include <igraph/igraph.h>
#include "filehandler.h"
#include "graphmap.h"

#ifdef DEBUG_MODE
#define dbg_printf(fmt, ...) printf("[%s][%s][%d]: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)
#else
#define dbg_printf(...)
#endif


char start_nodes[100][7];
char end_nodes[50][7];
char mid_nodes[1000][7];

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
	bool** matrix = NULL;
	int total_node = 0;


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

		total_node = get_input_node_num() + get_output_node_num() + get_mid_node_num();
		printf("input_node_num: %d\n", get_input_node_num());
		printf("mid_node_num: %d\n", get_mid_node_num());
		printf("output_node_num: %d\n", get_output_node_num());
		printf("node_num: %d\n", total_node);
		


		//print out the start_nodes(input nodes)
		printf("input_nodes:\n");
		for(int count = 0; count < get_input_node_num(); count++){
			printf("%s\t", start_nodes[count]);
		}

		//print out the mid_nodes(input nodes)
		printf("\nmid_nodes:\n");
		for(int count = 0; count < get_mid_node_num(); count++){
			printf("%s\t", mid_nodes[count]);
		}

		//print out the end_nodes(output nodes)
		printf("\noutput_nodes:\n");
		for(int count = 0; count < get_output_node_num(); count++){
			printf("%s\t", end_nodes[count]);
		}
		printf("\n");
		matrix = mapcreation(total_node);
		//for(int count = 0; count < total_node; count++){
		//	for(int count2 = 0; count2 < total_node; count2++){
		//		printf("%d ", matrix[count][count2]);
		//	}
		//	printf("\n");
		//}
		freemap(matrix, total_node);

	}else{
		printf("Invalid option\n");
		return 1;	
	}


	return 0;
}
