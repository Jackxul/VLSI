//graphmap.c
//Created at 2023-10-3 09:26
#include "graphmap.h"
//make a 2D square array for the graph with size of node_num*node_num

bool** mapcreation(int size) {
	bool** matrix;
    	// Allocate memory for the matrix
    	matrix = (bool**)malloc(size * sizeof(bool*));
    	if (matrix == NULL) {
		//Memory allocation failed
		return false;
    	}
    	for (int i = 0; i < size; i++) {
        	matrix[i] = (bool*)calloc(size, sizeof(bool));
        	if (matrix[i] == NULL) {
			//Memory allocation failed
        		return false;
        	}
    	}

    	// Return the created matrix
    	return matrix;
}
void freemap(bool** matrix, int size) {
	// Free the allocated memory
    	for (int i = 0; i < size; i++) {
        	free(matrix[i]);
    	}
    	free(matrix);
}
