//
// Created by Edoardo on 05/02/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "knapsack.h"

// Helper function
// Nuovi parametri: curr_weight, max_weight

void knapsack_R(Item *items, int n, int max_weight,
                int pos, int start,
                int *sol, int *best_sol, int *best_val, int curr_val,
                int curr_weight, int *best_size);

void solve_knapsack(Item *items, int n, int max_weight) {
    // Allocazione pessima ipotesi: prendiamo tutti gli n oggetti
    int *sol = (int *)malloc(n * sizeof(int));
    int *best_sol = (int *)malloc(n * sizeof(int));

    int best_val = 0;
    int best_size = 0;

    if (sol == NULL || best_sol == NULL) {
        free(sol);
        free(best_sol);
        return;
    }

    printf("--- KNAPSACK PROBLEM (Max weight: %d) ---\n)", max_weight);
    knapsack_R(items, n, max_weight, 0, 0, sol, best_sol, &best_val, 0, 0, &best_size);

    // curr_val = 0, curr_weight = 0
    printf("Best Value: %d\nItems:\n", best_val);
    for (int i = 0; i < best_size; i++) {
        int idx = best_sol[i];
        printf(" -> Item %d (Val; %d, Weight: %d)\n", items[idx].id, items[idx].value, items[idx].weight);
    }

    free(sol);
    free(best_sol);
}

void knapsack_R(Item *items, int n, int max_weight,
                int pos, int start,
                int *sol, int *best_sol, int *best_val, int curr_val,
                int curr_weight, int *best_size) {
    // 1. Controlla se l'attuale soluzione è la nuova migliore
    // Nota: non c'è un "pos == k" perchè la dimensione del gruppo è VARIABILE!
    if (curr_val > *best_val) {
        *best_val = curr_val;
        *best_size = pos; // Salviamo quanti elementi abbiamo usato
        memcpy(best_sol, sol, pos * sizeof(int));

    }

    // 2. Iterazione e Ricorsione con PRUNING
    for (int i = start; i < n; i++) {

        // --- PRUNING (Potatura) ---
        // Se aggiungiamo items[i] sforiamo il peso -> NON ENTRIAMO
        if (curr_weight + items[i].weight <= max_weight) {
            sol[pos] = i; // Aggiungiamo indice alla soluzione

            // Ricorsione:
            // Aggiorniamo 'curr_val' e 'curr_weight' passando i nuovi valori
            knapsack_R(items, n, max_weight, pos + 1, i + 1,
                        sol, best_sol, best_val,
                        curr_val + items[i].value,      // Aggiorniamo 'value'
                        curr_weight + items[i].weight,  // Aggiorniamo 'weight';
                        best_size);

            // BACKTRACKING implicito -> passiamo i valori per valore nella chiamata
            // e 'sol[pos] verrà sovrascritta alla prossima iterazione
        }
    }
}
