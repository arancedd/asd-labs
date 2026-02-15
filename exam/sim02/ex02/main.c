//
// Created by Edoardo on 15/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(void) {
    /* 1. Inizializzazione dell'albero tramite l'interfaccia */
    BST mioAlbero = BSTinit();

    /* 2. Popolamento (nel mondo reale useresti una BSTinsert(mioAlbero, "Stringa")) */
    BSTinsertTest(mioAlbero);

    printf("Ricerca del cammino piu' profondo in corso...\n");

    /* 3. Chiamata alla funzione richiesta dall'esame */
    BSTprintDeepest(mioAlbero);

    /* 4. Gestione memoria */
    BSTfree(mioAlbero);

    return 0;
}