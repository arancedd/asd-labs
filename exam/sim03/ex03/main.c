#include <stdio.h>
#include <stdlib.h>

#include "backpack.h" /* Sostituisci con il nome del tuo header se diverso */

int main(void) {
    /* 1. Inizializzo i dati del problema (L'esempio del testo) */
    int V[] = {4, 7, 5, 2};
    int N = 4;
    int C = 10;
    int max_peso;

    /* 2. Alloco il vettore soluzione (Il testo dice esplicitamente:
     * "già allocato dal main e di dimensione N") */
    int *best_sol = (int *)malloc(N * sizeof(int));
    if (best_sol == NULL) {
        fprintf(stderr, "Errore di allocazione memoria!\n");
        exit(EXIT_FAILURE);
    }

    printf("--- TEST PROBLEMA DELLO ZAINO (KNAPSACK) ---\n");
    printf("Capacita' massima (C) : %d\n", C);
    printf("Oggetti a disposizione: ");
    for (int i = 0; i < N; i++) {
        printf("[%d] ", V[i]);
    }
    printf("\n\n");

    /* 3. Chiamo la funzione d'esame */
    printf("Calcolo la combinazione ottima...\n\n");
    max_peso = riempiZaino(V, N, C, best_sol);

    /* 4. Output dei risultati */
    printf(">>> RISULTATI <<<\n");
    printf("Peso totale ottimo raggiunto: %d\n", max_peso);
    
    printf("Vettore best_sol restituito : [");
    for (int i = 0; i < N; i++) {
        printf("%d%s", best_sol[i], (i == N - 1) ? "" : ", ");
    }
    printf("]\n");

    /* 5. Stampa visuale per confermare cosa ha preso */
    printf("Oggetti effettivamente presi: ");
    for (int i = 0; i < N; i++) {
        if (best_sol[i] == 1) {
            printf("(%d) ", V[i]);
        }
    }
    printf("\n");

    /* 6. Regola d'oro del C: chi sporca, pulisce! */
    free(best_sol);

    return 0;
}