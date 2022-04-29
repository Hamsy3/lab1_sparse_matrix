#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    int num_of_elements;
    int *line_elements;
} line;


typedef struct matrix {
    int num_of_lines;
    line *lines;
} matrix;

int input_int (int *num);
void erase_matrix (matrix *new);
void erase_vector (int *different);
int input_matrix (matrix *new);
void output_matrix (matrix new);
void output_vector (matrix new, int *different);
void different_function (matrix new, int *different);
#endif
