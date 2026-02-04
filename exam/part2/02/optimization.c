#include <stdio.h>
#include <stdlib.h>
#include <string.h> // OBBLIGATORIO per 'memcpy'

#include "optimization.h"

// Prototipo privato (helper)
void optimization_R(int n, int k, int pos, int start, int *val, int *sol, int *best_sol, int *max_score);

// --- WRAPPER ---
void solve_max_sum(int n, int k, int *val) {
    // 1. Allocazione vettori
    int *sol = (int *) malloc(k * sizeof(int));         // soluzione corrente (cambia ad ogni iterazione)
    int *best_sol = (int *) malloc(k * sizeof(int));    // soluzione migliore (quella che salviamo)

    if (sol == NULL || best_sol == NULL) {
        printf ("Memory allocation failed\n");
        return;
    }

    // 2. Inizializzazione variabili di stato
    int max_score = -1; // Partiamo da un valore basso (o 0 se i dati sono positivi)

    // 3. Lancio ricorsione
    // Passiamo &max_score per poterlo modificare dentro la ricorsione
    optimization_R(n, k, 0, 0, val, sol, best_sol, &max_score);

    // 4. Stampa risultato finale
    printf("--- RISULTATO OTTIMIZZAZIONE ---\n");
    printf("Max Sum found: %d\n", max_score);
    printf("Elements: { ");
    for (int i = 0; i < k; i++) {
        // best_sol contiene INDICI.
        printf("%d ", val[best_sol[i]]);
    }
    printf("}\n");

    // 5. Pulizia
    free(sol);
    free(best_sol);

}

// --- FUNZIONE RICOSIVA ---
void optimization_R(int n, int k, int pos, int start, int *val, int *sol, int *best_sol, int *max_score) {
    // A. BASE CASE
    if (pos >= k) {
        // Calcoliamo la somma della soluzione corrente
        int current_sum = 0;
        for (int i = 0; i < k; i++) {
            current_sum += val[sol[i]]; // sol[i] è l'indice -> lo utilizziamo per prendere il valore corrispondente in 'val'
        }

        // B. CHECK OTTIMIZZAZIONE (Il valore preso è meglio del record attuale?)
        if (current_sum > *max_score) {
            *max_score = current_sum; // aggiorna il record

            // C. SAVE SNAPSHOT (Copia profonda)
            // Copia 'k' interi da 'sol' a 'best_sol'
            memccpy(best_sol, sol, start, k*sizeof(int));
        }
        return;
    }

    // C. ITERAZIONE (Logica combinazioni semplici)
    for (int i = start; i < n; i++) {
        sol[pos] = i; // Prova indice 'i'

        // Ricorsione (i+1 poiché nelle combinazioni non vogliamo ripetizione nè ordine inverso)
        optimization_R(n,k, pos + 1, i + 1, val, sol, best_sol, max_score );
    }
}