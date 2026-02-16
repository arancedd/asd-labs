//
// Created by Edoardo on 16/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "cruciverba.h"

/* Funzione di utilità per stampare la matrice a schermo */
void stampaMatrice(char **M, int R, int C) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c  ", M[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int R = 3;
    int C = 4;

    /* 1. ALLOCAZIONE DINAMICA DELLA MATRICE (Array di puntatori) */
    char **M = (char **)malloc(R * sizeof(char *));
    if (M == NULL) exit(EXIT_FAILURE);

    for (int i = 0; i < R; i++) {
        M[i] = (char *)malloc(C * sizeof(char));
        if (M[i] == NULL) exit(EXIT_FAILURE);
    }

    /* 2. INIZIALIZZAZIONE DELLA MATRICE (L'esempio del testo) */
    char dati_test[3][4] = {
        {'C', 'A', 'T', 'O'},
        {'R', 'O', 'P', 'E'},
        {'M', 'I', 'S', 'S'}
    };

    /* Copio i dati statici nella mia matrice dinamica ufficiale */
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            M[i][j] = dati_test[i][j];
        }
    }

    printf("--- TEST RICERCA PAROLA ---\n\n");
    printf("Matrice (%dx%d):\n", R, C);
    stampaMatrice(M, R, C);
    printf("\n");

    /* 3. ESECUZIONE DEI TEST */

    /* TEST 1: Parola presente (C -> R -> O -> P) */
    char parola1[] = "CROP";
    printf("Cerco '%s'...\t", parola1);
    if (trovaParola(M, R, C, parola1)) printf("[TROVATA!]\n");
    else printf("[NON TROVATA]\n");

    /* TEST 2: Parola assente (Lettere presenti, ma non adiacenti) */
    char parola2[] = "ROMA";
    printf("Cerco '%s'...\t", parola2);
    if (trovaParola(M, R, C, parola2)) printf("[TROVATA!]\n");
    else printf("[NON TROVATA]\n");

    /* TEST 3: Parola assente (Ripassa sulla stessa lettera) */
    char parola3[] = "CACAO";
    printf("Cerco '%s'...\t", parola3);
    if (trovaParola(M, R, C, parola3)) printf("[TROVATA!]\n");
    else printf("[NON TROVATA]\n");

    /* TEST 4: Parola presente (M -> I -> S -> S) */
    char parola4[] = "MISS";
    printf("Cerco '%s'...\t", parola4);
    if (trovaParola(M, R, C, parola4)) printf("[TROVATA!]\n");
    else printf("[NON TROVATA]\n");

    /* 4. DEALLOCAZIONE DELLA MATRICE DINAMICA */
    for (int i = 0; i < R; i++) {
        free(M[i]); /* Prima libero le singole righe */
    }
    free(M); /* Poi libero il vettore principale dei puntatori */

    return 0;
}