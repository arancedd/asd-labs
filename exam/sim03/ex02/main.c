//
// Created by Edoardo on 16/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "multiples.h"

/* ==========================================
 * 4. IL MAIN
 * ========================================== */
int main() {
    /* Creiamo il telecomando della lista originale */
    LIST L = LISTinit();

    /* Riempiamo la lista con i numeri da 1 a 10 */
    for (int i = 1; i <= 10; i++) {
        insertTail(L, i);
    }

    printf("--- PRIMA DELL'ESTRAZIONE ---\n");
    printf("Lista Originale (L): ");
    printList(L);
    printf("\n");

    /* TEST: Estraiamo tutti i multipli di 2 (i numeri pari) */
    int K = 2;
    printf("Eseguo extractMultiples(L, %d)...\n\n", K);
    LIST M = extractMultiples(L, K);

    printf("--- DOPO L'ESTRAZIONE ---\n");
    printf("Lista Originale (L) residua : ");
    printList(L); /* Dovrebbero esserci solo i dispari */

    printf("Nuova Lista Estratti (M)    : ");
    printList(M); /* Dovrebbero esserci solo i pari, nello stesso ordine! */
    printf("\n");

    /* (Nota: in un programma reale qui andrebbe fatta la free() di tutti i nodi e dei telecomandi L e M) */

    return 0;
}