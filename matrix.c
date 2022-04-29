#include "matrix.h"
int input_int (int *num) {
    int a = 0;
    do {
        a = scanf ("%d", num);
        if (a < 0) {
            return 0;
        }

        if (a == 0) {
            scanf("%*c");
        }
    } while (a == 0);
    return 1;
}

void erase_matrix (matrix *new) {
    for (int i =0; i< new->num_of_lines; ++i) {
        free (new->lines[i].line_elements);
    }
    free (new->lines);
    new->num_of_lines = 0;
    new->lines = NULL;
}
void erase_vector (int *different) {
    free (different);
}

int input_matrix (matrix *new) {
    int n = 0;
    int m = 0;
    do {
        printf("Please, write number of lines\n");
        if (input_int(&n) == 0) {
            return 0;
        }
    }while (n<1);
    new->num_of_lines = n;
    new->lines = (line*) calloc(n, sizeof(line));
    for (int i = 0; i< new->num_of_lines; ++i) {
        do {
            printf ("Please, write number of elemets in %d line\n", i+1);
            if (input_int(&m) == 0) {
                new->num_of_lines = i;
                erase_matrix (new);
                return 0;
            }
        }while (m<1);
        new->lines[i].num_of_elements = m;
        new->lines[i].line_elements = calloc(m, sizeof(int));
        printf("Please write elements for %d line\n", i+1);
        for (int j = 0; j < m; ++j) {
            if (input_int(&new->lines[i].line_elements[j]) == 0) {
                new->num_of_lines = i+1;
                erase_matrix (new);
                return 0;
            }
        }
    }
        return 1;
    }


    void output_matrix (matrix new) {
    printf("\nMatrix:\n");
    for (int i = 0; i < new.num_of_lines; ++i) {
        for (int j = 0; j < new.lines[i].num_of_elements; ++j) {
                printf("%d ", new.lines[i].line_elements[j]);
        }
    printf("\n");
    }
    }
    void output_vector (matrix new, int *different) {
        printf("\nVector:\n");
        for (int k = 0; k < new.num_of_lines; ++k) {
            printf("%d ", different[k]);
        }
        printf("\n");
    }

    void different_function (matrix new, int *different) {
        int buffer = 1;
        for (int i = 0; i<new.num_of_lines; ++i) {
            for (int k = 1; k < new.lines[i].num_of_elements; k++) {
                int j = 0;
                for (; j < k; j++)
                    if (new.lines[i].line_elements[k] == new.lines[i].line_elements[j]) {
                        break;
                    }
         
                if (k == j) {
                    buffer++;
                }
            }
            different[i] = buffer;
            buffer = 1;
        }
    }
