
//file.h
#ifndef _FILEHANDLE_H_
#define _FILEHANDLE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void file_read(const char *filename);
void get_inout_node(const char *buffer, bool countflag);
void get_mid_node(const char *buffer);
int get_input_node_num();
int get_mid_node_num();
int get_output_node_num();



#endif /*FILEHANDLE_H*/
