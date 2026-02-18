//
// Created by Edoardo on 18/02/2026.
//

#include "sim0801.h"

#include <stdlib.h>
#include <string.h>


link removeDupl(link h) {

    link node;
    link maybeDuplicate;
    link prevNode;

    /* CICLO 1 (Esterno)
     * Scorre la lista nodo per nodo
     * Stabilisce la prima occorrenza che verrà comparata con il resto della lista per cercare i duplicati
     * Iniziamo da ciò che ci passa la funzione e andiamo avanti finché node diventa NULL
     */
    for (node = h; node != NULL; node=node->next) {

        /* CICLO 2 (Interno)
         * Scorre il resto della lista per controllare se ci sono duplicati
         * * INIZIALIZZAZIONE
         * * maybeDuplicate -> Il nodo sospettato di essere un duplicato, parte dal nodo dopo node
         * * prevNode -> Ultimo nodo sicuro al quale in caso bisogenrà attaccare il nuovo nodo dopo l'eliminazione
         *
         * Avanza duplicate ad ogni iterazione
         * Si stoppa quando duplicate è NULL (la prossima iterazione non esiste)
         */
        for (maybeDuplicate = node->next, prevNode = node; maybeDuplicate != NULL; maybeDuplicate=maybeDuplicate->next) {

            // Confrontiamo la stringa duplicate con la stringa del nodo esterno
            if (strcmp(maybeDuplicate->val, node->val) == 0) {

                /* --- CASO 1: DUPLICATO TROVATO ---
                 * Dobbiamo eliminarlo
                 */

                /* 1. Snip (bypass)
                 * Il nodo precedente (prevNode) salta il duplicato (maybeDuplicate) e si collega direttamente al nodo successivo a 'maybeDuplicate'
                 */
                prevNode->next = maybeDuplicate->next;

                /* 2. Pulizia
                 * Liberiamo la memoria della stringa e del nodo
                 */
                free(maybeDuplicate->val);
                free(maybeDuplicate);

                // NOTA: Non muoviamo prevNode perchè nessuno ci assicura che il prossimo nodo non sia di nuovo un duplicato
                // quindi dovrò ricollegarlo ancora allo stesso prevNode.

            }else {
                /* --- CASO 2: DUPLICATO NON TROVATO ---
                 * Possiamo avanzare prevNode
                 * Il CICLO 2 si occuperà di avanzare il prossimo possibile duplicato
                 */
                prevNode = maybeDuplicate; // maybeDuplicate non è un duplicato, può diventare il nuovo prevNode
            }
        }
    }

    return h;

}
