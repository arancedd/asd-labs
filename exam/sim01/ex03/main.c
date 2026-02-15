//
// Created by Edoardo on 15/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "group.h"

int main() {
    /* Nuove dimensioni del problema di test */
    int O = 6; /* Numero di oggetti (righe) */
    int S = 7; /* Numero di sottoinsiemi (colonne) */
    int i;

    int *sol = NULL;
    int *best_sol = NULL;
    int *controllo = NULL;
    int **M = NULL;
    int min_scelti = S + 1; /* Inizializzato a "infinito" */

    /* 1. Allocazione rigorosa delle strutture dati */
    sol = (int*)calloc(S, sizeof(int));
    best_sol = (int*)calloc(S, sizeof(int));
    controllo = (int*)calloc(O, sizeof(int));

    M = (int**)malloc(O * sizeof(int*));
    if (M == NULL || sol == NULL || best_sol == NULL || controllo == NULL) {
        fprintf(stderr, "Errore di allocazione memoria vettori\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < O; i++) {
        M[i] = (int*)calloc(S, sizeof(int)); /* Usa calloc per inizializzare tutto a 0 di default */
        if (M[i] == NULL) {
            fprintf(stderr, "Errore di allocazione memoria matrice righe\n");
            exit(EXIT_FAILURE);
        }
    }

    /* 2. Popolamento della matrice complessa
     * S0: {0, 1, 2}
     * S1: {1, 3}
     * S2: {2, 4, 5}
     * S3: {0, 3}
     * S4: {4, 5}
     * S5: {1, 2}
     * S6: {3}
     */

    // Inserimento manuale degli '1' (gli '0' sono già garantiti dalla calloc)
    M[0][0] = 1; M[1][0] = 1; M[2][0] = 1; // S0
    M[1][1] = 1; M[3][1] = 1;              // S1
    M[2][2] = 1; M[4][2] = 1; M[5][2] = 1; // S2
    M[0][3] = 1; M[3][3] = 1;              // S3
    M[4][4] = 1; M[5][4] = 1;              // S4
    M[1][5] = 1; M[2][5] = 1;              // S5
    M[3][6] = 1;                           // S6

    printf("Avvio ricerca copertura esatta (Exact Cover) su matrice %dx%d...\n", O, S);

    /* 3. Chiamata alla funzione ricorsiva (il "motore") */
    powerset_pruning(0, sol, 0, best_sol, &min_scelti, controllo, M, O, S);

    /* 4. Valutazione e stampa dei risultati */
    if (min_scelti <= S) {
        printf("Trovata copertura a cardinalita' minima: %d\n", min_scelti);
        printf("Sottoinsiemi selezionati: ");
        for (i = 0; i < S; i++) {
            if (best_sol[i] == 1) {
                printf("S%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("Nessuna copertura esatta possibile per l'insieme universo.\n");
    }

    /* 5. Prevenzione memory leak (liberazione memoria) */
    free(sol);
    free(best_sol);
    free(controllo);
    for (i = 0; i < O; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}