//
// Created by Edoardo on 17/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "even.h" /* Il tuo header con il prototipo estraiPari */

int main(void) {
    printf("--- ESTRAZIONE PARI ---\n\n");

    int v1[] = {1, 2, 5, 4, 8, 9};
    int N1 = 6;
    int new_size1;

    printf("Array originale: ");
    for(int i = 0; i < N1; i++) printf("%d ", v1[i]);
    printf("\n");

    int *risultato1 = estraiPari(v1, N1, &new_size1);

    if (risultato1 != NULL) {
        printf("Array dei pari (dimensione %d): ", new_size1);
        for(int i = 0; i < new_size1; i++) {
            printf("%d ", risultato1[i]);
        }
        printf("\n");
        free(risultato1); /* Fondamentale per non avere memory leak */
    } else {
        printf("Nessun numero pari trovato. Dimensione: %d\n", new_size1);
    }

    return 0;
}