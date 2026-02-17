#include "compression.h"
#include <stdlib.h>
#include <stdio.h>

struct list {
    char val;
    link next;
};

/* --- FUNZIONI DI SUPPORTO --- */
link nuovoNodo(char val, link next) {
    link x = malloc(sizeof *x);
    if (x == NULL) exit(EXIT_FAILURE);
    x->val = val;
    x->next = next;
    return x;
}

void stampaLista(link head) {
    for (link t = head; t != NULL; t = t->next) {
        printf("%c -> ", t->val);
    }
    printf("NULL\n");
}

void liberaLista(link head) {
    link temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
/* ----------------------------------------- */

link comprimiLista(link head) {
    /* 1. CASO BASE */
    if (head == NULL || head->next == NULL) return head;

    /* 2. CREO ESPLORATORE */
    link temp;
    link curr = head;

    /* 3. CICLO */
    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val) {
            temp = curr->next->next;
            free(curr->next);
            curr->next = temp;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}