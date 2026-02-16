//
// Created by Edoardo on 16/02/2026.
//

#include "backpack.h"

#include <stdlib.h>


void riempiZaino_R(int *V, int N, int C, int *best_sol, int i, int peso_corr, int *sol_corr, int *best_peso) {

    // 1. CASO BASE: Siamo arrivati alla fine dell'array
    if (i == N) {
        // Nuovo record?
        if (peso_corr > *best_peso && peso_corr <= C) {
            *best_peso = peso_corr;

            // Copio soluzione temporanea
            for(int j = 0; j < N; j++) best_sol[j] = sol_corr[j];
        }
        return; // Backtrakcing
    }

    // PRUNING
    if (peso_corr > C) return;

    //SCELTA A: Non prneod l0ggetto V[i]
    sol_corr[i] =0;
    riempiZaino_R(V, N, C, best_sol, i + 1, peso_corr, sol_corr, best_peso);

    //SCELTA B: prendo l'oggetto V[i]
    sol_corr[i] = 1;
    riempiZaino_R(V, N, C, best_sol, i + 1, peso_corr + V[i], sol_corr, best_peso);
}
int riempiZaino(int *V, int N, int C, int *best_sol) {

    int best_peso = 0;
    int *sol_corr;

    sol_corr = (int *)calloc(N, sizeof(int));
    if (sol_corr == NULL) exit(EXIT_FAILURE);

    riempiZaino_R(V, N, C, best_sol, 0, 0, sol_corr, &best_peso);

    free(sol_corr);
    return best_peso;

}