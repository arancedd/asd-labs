//
// Created by Edoardo on 17/02/2026.
//

#include "even.h"

#include <stdlib.h>


int* estraiPari(const int *v, int N, int *new_size) {

    *new_size = 0;
    int *sol;
    sol = (int*)malloc(N*sizeof(int));
    if (sol == NULL)exit(EXIT_FAILURE);

    for (int i = 0; i < N; i++) {
        if (v[i] % 2 == 0 ) {
            sol[*new_size] = v[i];
            (*new_size)++;
        }
    }

    if (*new_size == 0) {
        free(sol);
        return NULL;
    }
    sol = (int*)realloc(sol, *new_size*sizeof(int));
    if (sol == NULL) exit(EXIT_FAILURE);
    return sol;
}
