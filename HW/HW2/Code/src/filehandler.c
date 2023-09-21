//Doing File read and write operations
//filehandler.c
// Created at 2023-09-21 23:07:00
#include "filehandler.h"

void file_read(){
	FILE *fp = fopen("test.txt", "r");
	if(fp != NULL){
		char buffer[100];
		while(fgets(buffer, 100, fp) != NULL){
			printf("%s", buffer);
		}
		fclose(fp);
	}else{
		printf("Error: .txt open failed!\n");
	}
}



