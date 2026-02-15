//
// Created by Edoardo on 13/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


void f(int **M, int r, int c, int ***M_result) {
    // --- 1. ALLCOAZIONE NUOVA MATRICE ---
    // Inizio ad allocare quante righe ci sono
    *M_result = (int **)malloc(r * sizeof(int *));
    if (*M_result == NULL) exit(1);

    // Scorro tutti i puntatori alle righe, e per ognuna creo 'c' colonne e alloco
    for (int i = 0; i < r; i++) {
        (*M_result)[i] = (int *)malloc(c * sizeof(int));
        if ((*M_result[i])  == NULL) exit(1);
    }

    // --- 2. CALCOLO DELLA SOMMA ---
    for (int i = 0; i <r; i++) {
        for (int j = 0; j < c; j++) {

            int sum = M[i][j]; // Parto dal valore della cella poiché il testo chiede di considerarlo

            for (int col = 0; col < j; col++) { // Sommo gli elementi precedenti sulla STESSA RIGA
                sum += M[i][col];
            }

            for (int row = 0; row < i; row++) { // Sommo gli elementi precedenti sulla STESSA COLONNA
                sum += M[row][j];
            }

            // Salvo il risultato nella nuova matrice
            (*M_result)[i][j] = sum;
        }
    }
}