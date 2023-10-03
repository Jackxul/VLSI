//Doing File read and write operations
//filehandler.c
// Created at 2023-09-21 23:07:00
#include "filehandler.h"

extern char start_nodes[50][7];
extern char end_nodes[50][7];
extern char mid_nodes[1000][7];

wordCount = 0;
int input_node_num = 0;
int mid_node_num = 0;
int output_node_num = 0;
void file_read(const char *filename){

	
	const char *_input = ".input";
	const char *_output = ".output";
	const char *_nodes = ".name";
	FILE *fp = fopen(filename, "r");
	
	if(fp != NULL){
		char *buffer = malloc(sizeof(char) * 100); //remember to free!
		while(fgets(buffer, 100, fp) != NULL){
			if(strstr(buffer, _input) != NULL){
				//printf("%s", buffer);
				get_inout_node(buffer, true);
			}else if(strstr(buffer, _output) != NULL){
				//printf("%s", buffer);
				get_inout_node(buffer, false);
			}else if(strstr(buffer, _nodes) != NULL){
				//printf("%s", buffer);
				mid_node_num++;
				get_mid_node(buffer);
			}
		}
		wordCount = 0;
		fclose(fp);
		free(buffer);
	}else{
		printf("Error: .blif open failed!\n");
	}
	//printf("%s", start_nodes);
	
}
void get_inout_node(const char *buffer, bool countflag){
	int length = 0;
	char *token = strtok(buffer, " "); //get the first token
	token = strtok(NULL, " "); //filter out the first token
	while(token != NULL && countflag){
		//printf("%s\n", token);
		
		char* newline = strchr(token, '\n');
        	if (newline != NULL) {
            		*newline = '\0';
        	}
		//save input node
		strcpy(start_nodes[wordCount], token);
		wordCount++;
		input_node_num++;
		token = strtok(NULL, " ");
	}
	while(token != NULL && !countflag){
		//printf("%s\n", token);
		char* newline = strchr(token, '\n');
        	if (newline != NULL) {
            		*newline = '\0';
        	}
		strcpy(end_nodes[wordCount], token);
		wordCount++;
		output_node_num++;
		token = strtok(NULL, " ");
	}
	wordCount = 0;
}
void get_mid_node(const char *buffer){
	const char *delim = " ";
	const char *lastSpace = strrchr(buffer, ' ');

	if(lastSpace != NULL){
		char* newline = strchr(lastSpace, '\n');
        	if (newline != NULL) {
            		*newline = '\0';
        	}
		strcpy(mid_nodes[wordCount], (lastSpace + 1));
		wordCount++;
	}else{
		printf("Error: No space found!\n");
	}
} 
int get_input_node_num(){
	return input_node_num;
}
int get_mid_node_num(){
	return (mid_node_num - output_node_num);
}
int get_output_node_num(){
	return output_node_num;
}
