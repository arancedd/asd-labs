#include <stdio.h>
#include <stdlib.h>
#include "combinatorics.h"

// Prototipo funzione ricorsiva (privata, non serve nell'header)
void noRepCombinations_R(int n, int k, int pos, int start, int *sol);
void dispositions_R(int n, int k, int pos, int *sol, int *mark);

// --- FUNZIONI WRAPPER ---
void generate_noRepCombo(int n, int k) {
    // 1. Allocazione array soluzione
    int *sol = (int *)malloc(k * sizeof(int));
    if (sol == NULL) {
        printf("Error allocating memory\n");
        free(sol);
        return;
    }

    printf("--- COMBINAZIONI DI %d ELEMNTI DA UN GRUPPO DI %d ---\n", k, n);
    // 2. Ricorsione
    // pos: 0 (indice corrente in array soluzioni
    // start: 0 (primo indice disponibile)
    noRepCombinations_R(n, k, 0, 0, sol);

    // 3. Pulizia memoria
    free(sol);
}

void generate_dispositions(int n, int k) {
    int *sol = (int *)malloc(k * sizeof(int));
    int *mark = (int *)calloc(n,sizeof(int));

    if (sol == NULL || mark == NULL) {
        free(sol);
        free(mark);
        printf("Error allocating memory\n");
        return;
    }

    printf("--- GENERA DISPOSIZIONI (Ordine conta, senza ripetizioni)\n");
    dispositions_R(n, k, 0, sol, mark);

    free(sol);
    free(mark);
}

// --- FUNZIONE RICORSIVA COMBINAZIONI SENZA RIPETIZIONE ---
void noRepCombinations_R(int n, int k, int pos, int start, int *sol) {
    // A. CASO BASE (Terminazione)
    // Se 'pos' ha raggiunto 'k' -> vettore 'sol' riempito
    // Combinazione completa!
    if (pos >= k) {
        printf ("{ ");
        for (int i = 0; i < k; i++) {
            printf ("%d ", sol[i]);
        }
        printf ("}\n");
        return;
    }

    // B. ITERAZIONE & RICORSIONE
    // Dobbiamo riempire la casella 'pos' del vettore 'sol'
    // Proviamo tutti gli elementi da 'start' fino alla fine (n-1)
    for (int i = start; i <= n; i++) {
        sol[pos] = i; // 1. Scegliamo l'elemento 'i'

        // 2. Scendiamo al livello successivo (ricorsione)
        // pos + 1: andiamo a riempire la prossima casella
        // i + 1: il primo elemento deve essere DOPO 'i' (evita duplicati come {1,0}
        // se i: si ottengono disposizioni con ripetizione {0,0,0} {0,0,1} (lucchetto)
        noRepCombinations_R(n, k, pos + 1, i+1, sol);

        // 3. Backtracking (implicito)
        // Quando la funzione torna il ciclo for avanza
        // Sovrascriviamo sol[pos] con il prossimo numero

    }
}

void dispositions_R(int n, int k, int pos, int *sol, int *mark) {
    // A. CASO BASE (Terminazione)
    // Uguale a noRepCombinations_R
    if (pos >= k) {
        printf ("{ ");
        for (int i = 0; i < k; i++) {
            printf("%d ", sol[i]);
        }
        printf ("}\n");
        return;
    }

    // B. ITERAZIONE & RICORSIONE
    // Loop: sempre da 0 a 'n' (poiché l'ordine è rilevante: 1 può stare prima di 0
    for (int i = 0; i < n; i++) {
        // CHECK: l'elemento i è disponibile?
        if (mark[i] == 0) {
            mark[i] = 1; // DO: segna l'elemento 'i' come usato
            sol[pos] = i; //aggiungi alla soluzione
            dispositions_R(n, k, pos + 1, sol, mark);

            mark[i] = 0; // UNDO (Backtracking): Liberalo per gli altri rami della ricorsione
        }


    }
}


