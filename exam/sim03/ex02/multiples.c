//
// Created by Edoardo on 16/02/2026.
//

#include "multiples.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *link;
struct listNode {
    int val;
    link next;
};

struct list_t {
    link head;
};





LIST extractMultiples(LIST L, int K) {
    // 1. Creiamo il nuovo wrapper
    LIST multiples = LISTinit();

    // Controlli di sicurezza
    if (L == NULL || L->head == NULL || K == 0) return multiples;

    // 2. Prepariamo gli indici per scorrere la lista
    link curr = L->head;
    link prev = NULL;
    link last_multiple = NULL;
    // 3. Iterazione
    while (curr != NULL) {

        // CONDIZIONE: Trovato multiplo di K
        if (curr->val % K == 0) {
            link da_estrarre = curr;

            if (prev == NULL) { //CASO SPECIALE è IL PRIMO VAGONE
                L->head = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            curr = curr->next; // Spostiamo in avanti

            da_estrarre->next = NULL; // Ripuliamo gancio
            if (multiples->head == NULL) { // E' il primo nodo estratto
                multiples->head = da_estrarre;
                last_multiple = da_estrarre;
            }
            else {
                last_multiple->next = da_estrarre;
                last_multiple = da_estrarre;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }


    }

    return multiples;

}


/* Inserisce un nodo in fondo alla lista */
void insertTail(LIST L, int val) {
    link newNode = malloc(sizeof(struct listNode));
    newNode->val = val;
    newNode->next = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return;
    }
    link x = L->head;
    while (x->next != NULL) {
        x = x->next;
    }
    x->next = newNode;
}

void printList(LIST L) {
    if (L == NULL || L->head == NULL) {
        printf("VUOTA\n");
        return;
    }
    link x = L->head;
    while (x != NULL) {
        printf("[%d] -> ", x->val);
        x = x->next;
    }
    printf("NULL\n");
}

