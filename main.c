#include "matrix.h"
int main() {
    matrix new = {0, NULL};
    int *different = NULL;
    if (input_matrix(&new) == 0) {
        printf("EOF\n");
        return 1;
    }
    different = calloc(new.num_of_lines, sizeof(int));
    different_function (new, different);
    output_matrix (new);
    output_vector (new, different);
    erase_matrix (&new);
    erase_vector (different);
    return  0;
}

