//
// Created by Edoardo on 16/02/2026.
//

#ifndef ASD_LABS_MULTIPLES_H
#define ASD_LABS_MULTIPLES_H

typedef struct list_t *LIST;

LIST extractMultiples(LIST L, int K);


void printList(LIST L);
void insertTail(LIST L, int val);
LIST LISTinit();

#endif //ASD_LABS_MULTIPLES_H