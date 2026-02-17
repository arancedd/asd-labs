//
// Created by Edoardo on 17/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "sim06ex03.h"

/* Funzione di utilità per lanciare i test e stampare un report pulito */
void eseguiTest(int *v, int N, int target, int numeroTest, const char *descrizione) {
    printf("========================================\n");
    printf("TEST %d: %s\n", numeroTest, descrizione);
    printf("Array: [ ");
    for(int i = 0; i < N; i++) printf("%d ", v[i]);
    printf("]\nTarget: %d\n", target);
    printf("----------------------------------------\n");
    printf("Soluzioni trovate:\n");

    int conteggio = sommaEsatta(v, N, target);

    printf("----------------------------------------\n");
    printf("Totale sottoinsiemi validi: %d\n", conteggio);
    printf("========================================\n\n");
}

int main(void) {
    printf("\n*** AVVIO TEST BACKTRACKING - SOMMA ESATTA ***\n\n");

    /* TEST 1: Caso Standard (Target 8)
     * Soluzioni attese: {3, 5}, {7, 1}, {3, 2, 1} -> Totale 3 */
    int v1[] = {3, 2, 7, 5, 1};
    eseguiTest(v1, 5, 8, 1, "Caso standard multi-soluzione");

    /* TEST 2: Nessuna Soluzione (Target 4)
     * I numeri sono troppo grandi o non si incastrano -> Totale 0 */
    int v2[] = {10, 5, 7, 12};
    eseguiTest(v2, 4, 4, 2, "Nessuna soluzione possibile");

    /* TEST 3: Numero Esatto e Combinazione (Target 8)
     * Soluzioni attese: {8}, {5, 2, 1} -> Totale 2 */
    int v3[] = {5, 2, 8, 1};
    eseguiTest(v3, 4, 8, 3, "Presenza del target esatto nell'array");

    /* TEST 4: Tutti gli elementi necessari (Target 15)
     * Soluzioni attese: {1, 2, 3, 4, 5} -> Totale 1 */
    int v4[] = {1, 2, 3, 4, 5};
    eseguiTest(v4, 5, 15, 4, "Tutti gli elementi richiesti");

    /* TEST 5: Elementi duplicati (Target 6)
     * Soluzioni attese: {3, 3}, {4, 2}, {6} -> Totale 3 */
    int v5[] = {3, 4, 3, 2, 6};
    eseguiTest(v5, 5, 6, 5, "Gestione duplicati");

    printf("*** FINE DEI TEST ***\n");
    return 0;
}