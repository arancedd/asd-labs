//
// Created by Edoardo on 13/02/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct list_s {
    NODE *head;
};

void deleteNode(NODE *node) {
    NODE *delete = node->next;
    node->next = node->next->next;

    free(delete);
}


void f(LIST l) {
    if (l == NULL || l->head == NULL) {
        printf("ERRORE: Lista vuota");
        return;
    }

    NODE *curr = l->head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val) {
            deleteNode(curr);
        }
        else curr = curr->next;
    }

}