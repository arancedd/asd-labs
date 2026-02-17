#include <stdio.h>
#include "helper.h"

int main(void) {
    printf("--- SOMMA RANGE BST ---\n\n");

    /* Costruiamo l'albero dell'esempio usando le funzioni del tuo modulo */
    link root = nuovoNodoAlbero(10,
                    nuovoNodoAlbero(5,
                        nuovoNodoAlbero(2, NULL, NULL),
                        nuovoNodoAlbero(7, NULL, NULL)
                    ),
                    nuovoNodoAlbero(15,
                        nuovoNodoAlbero(12, NULL, NULL),
                        nuovoNodoAlbero(20, NULL, NULL)
                    )
                );

    int min = 6;
    int max = 13;

    printf("Cerco somma nel range [%d, %d]...\n", min, max);
    int somma = sommaRange(root, min, max);

    printf("Risultato: %d (Atteso: 29)\n", somma);

    /* Pulizia */
    liberaAlbero(root);
    return 0;
}