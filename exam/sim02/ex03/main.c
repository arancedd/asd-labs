//
// Created by Edoardo on 15/02/2026.
//

//
// Created by Edoardo on 15/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "maze.h" /* Il tuo header che espone int minPath(...) */

int main() {
    int N = 4;
    int M = 5;
    int r0 = 1, c0 = 0; /* Coordinate di partenza */
    int r1 = 2, c1 = 3; /* Coordinate di destinazione */
    int i, j;
    int lunghezza;
    char **area = NULL;

    /* 1. La matrice dell'esempio (con gli '0' al posto delle 'x' della traccia
     * perché 'x' indicava solo visivamente il cammino per farti capire)
     * 0 1 0 0 0
     * 0 0 0 1 0
     * 0 1 0 0 0
     * 0 0 0 0 0
     */
    char test_matrix[4][5] = {
        {'0', '1', '0', '0', '0'},
        {'0', '0', '0', '1', '0'},
        {'0', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    /* 2. Allocazione dinamica rigorosa per matchare la firma (char **) */
    area = (char **)malloc(N * sizeof(char *));
    if (area == NULL) {
        fprintf(stderr, "Errore di allocazione matrice righe\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < N; i++) {
        area[i] = (char *)malloc(M * sizeof(char));
        if (area[i] == NULL) {
            fprintf(stderr, "Errore di allocazione colonne\n");
            exit(EXIT_FAILURE);
        }
        /* Copio i valori dalla matrice statica a quella dinamica */
        for (j = 0; j < M; j++) {
            area[i][j] = test_matrix[i][j];
        }
    }

    printf("Avvio simulazione labirinto %dx%d...\n", N, M);
    printf("Partenza: (%d, %d) - Arrivo: (%d, %d)\n\n", r0, c0, r1, c1);

    /* 3. Chiamata alla tua funzione (l'interfaccia) */
    lunghezza = minPath(area, N, M, r0, c0, r1, c1);

    /* 4. Output dei risultati */
    if (lunghezza != -1) {
        printf(">>> Percorso minimo trovato!\n");
        printf(">>> Lunghezza del cammino ottimo: %d caselle.\n", lunghezza);
    } else {
        printf(">>> ERRORE: Nessun percorso valido trovato o coordinate errate.\n");
    }

    /* 5. Prevenzione memory leak */
    for (i = 0; i < N; i++) {
        free(area[i]);
    }
    free(area);

    return 0;
}