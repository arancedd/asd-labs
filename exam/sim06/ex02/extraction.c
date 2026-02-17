//
// Created by Edoardo on 17/02/2026.
//

#include "extraction.h"

#include <stddef.h>
#include <stdlib.h>

struct list {
    int val;
    link next;
};


link estraiMaggiori(link *headPtr, int K) {

    link newListHead = NULL;
    link newListTail = NULL;

    if (headPtr == NULL || *headPtr == NULL) return NULL;

    // Inizializziamo indici di scorrimento
    link curr = *headPtr;
    link prev = NULL;

    // CICLO -> Finchè il nodo a cui puntiamo non è NULL(vuoto)
    while (curr != NULL) {
        // Se il valore nel nodo è > K, estraiamo il nodo
        if (curr->val > K) {
            // Salviamo questo nodo perchè poi dovremmo inserirlo nella LISAT B
            link toExtract = curr;

            /* RIMUOVIAMO IL NODO DALLA LISTA A E RICOLEGHIAMO IL PRECEDENTE AL SUCCESSIVO*/
            // Se è il primo nodo della lista
            if (prev == NULL){
                // -> semplicemente cambiamo la testa con il nodo successivo
                *headPtr = curr->next;
            }
            // Se non siamo nel caso speciale
            else {
                //-> Attacchiamo la coda del nodo successivo alla testa del nodo precedente
                prev->next = curr->next;
            }
            // Ci spostiamo avanti, tanto abbiamo già salvato il nodo da estrarre
            curr = curr->next;
            /* AGGIUNGIAMO IL NODO ESTRATTO ALLA LISTA B */
            // 1. RIPULIAMO il gancio del nodo da estrarre che punta ancora al nodo nella LISTA A
            toExtract->next = NULL;

            // Se la LISTA B è vuota (non ha ancora il puntatore a un nodo)
            if (newListHead == NULL) {
                // Usiamo il valore da estrarre come testa nel wrapper della LISTA B
                newListHead = toExtract;
                // Salviamo questo nodo come ultimo nodo estratto
                newListTail = toExtract;
            }
            // Se la LISTA B non è vuota
            else {
                // Colleghiamo il nodo estratto all'ultimo nodo salvato
                newListTail->next = toExtract;
                // Aggiorniamo l'ultimo nodo salvato con quello appena estratto
                newListTail = toExtract;
            }


        }
        // Se non deve essere estratto scorriamo la LISTA A
        else {
            prev = curr;
            curr = curr->next;
        }

    }

    return newListHead;


}