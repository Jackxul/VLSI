//Doing File read and write operations
//filehandler.c
// Created at 2023-09-21 23:07:00
#include "filehandler.h"

extern char start_nodes[100];

void file_read(const char *filename){

	
	const char *_input = ".input";
	const char *_output = ".output";
	const char *_nodes = ".name";
	FILE *fp = fopen(filename, "r");
	
	if(fp != NULL){
		char *buffer = malloc(sizeof(char) * 100); //remember to free!
		while(fgets(buffer, 100, fp) != NULL){
			if(strstr(buffer, _input) != NULL){
				printf("%s", buffer);
			}else if(strstr(buffer, _output) != NULL){
				printf("%s", buffer);
				get_node(buffer, start_nodes);
			}else if(strstr(buffer, _nodes) != NULL){
				//printf("%s", buffer);
			}
		}
		fclose(fp);
		free(buffer);
	}else{
		printf("Error: .blif open failed!\n");
	}

	//printf("%s", start_nodes);
}
void get_node(const char *buffer, char *array){
	int length = 0;
	char *token = strtok(buffer, " "); //get the first token
	token = strtok(NULL, " "); //filter out the first token
	while(token != NULL){
		printf("%s\n", token);
		
		token = strtok(NULL, " ");
	}
}
