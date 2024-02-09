#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main() {

    int i, j;
    char mode;

    int **Matrix = (int**) malloc(10 * sizeof(int*));

    for (int i = 0; i < 10; ++i)
        Matrix[i] = (int*) malloc(10 * sizeof(int));

    do {
        scanf(" %c", &mode);  

        if (mode == 'A') {

            getMatrixValues(Matrix, 10);

        } else if (mode == 'B') {

            scanf("%d%d", &i, &j);
            printf("%s\n", isTherePath(Matrix, i, j, 10) ? "True" : "False");

        } else if (mode == 'C') {

            scanf("%d%d", &i, &j);
                printf("%d\n", findShortestPath(Matrix, i, j, 10));
        }
    } 

    while(mode != 'D');

    for (int i = 0; i < 10; ++i)
        free(Matrix[i]);

    free(Matrix);

    return 0;
}