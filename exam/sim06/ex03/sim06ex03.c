//
// Created by Edoardo on 17/02/2026.
//

#include "sim06ex03.h"

#include <stdio.h>
#include <stdlib.h>

void powerset_somma(int *v, int N, int target, int *sol, int sum, int pos, int *nSottogruppi) {


    // PRUNING #1: la somma supera il target
    if (sum > target) return;
    // PRUNING #2: sono arrivato al mio target, non c'è bisogno che continuo la ricorsione
    if (sum == target) {
        (*nSottogruppi)++;

        printf("{ ");
        for (int i = 0; i < pos; i++) {

            if (sol[i] == 1) {
                printf("%d  ", v[i]);
            }
        }
        printf("}\n");
        return;
    }

    // CASO 1: Sono arrivato alla fine di *v, potrebbe ANCORA essere una soluzione valida
    if (pos == N) return;


    /* --- RICORSIONE --- */
    // CASO 1: prendo l'elemento
    sol[pos] = 1;
    powerset_somma(v, N, target, sol, sum+v[pos], pos+1, nSottogruppi);


    // CASO 0: non prendo l'elemento
    sol[pos] = 0;
    powerset_somma(v, N, target, sol, sum, pos+1, nSottogruppi);




}

int sommaEsatta(int *v, int N, int target) {

    int *sol = (int*)calloc(N,sizeof(int));

    // Sottogruppi trovati
    int res = 0;

    powerset_somma(v, N, target, sol, 0, 0, &res);

    free(sol);
    return res;


}
