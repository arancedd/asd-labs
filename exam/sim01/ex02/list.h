//
// Created by Edoardo on 13/02/2026.
//

#ifndef ASD_LABS_LIST_H
#define ASD_LABS_LIST_H


// 1. NODE come "quasi ADT"

typedef struct node{
    int val;
    struct node *next;
}NODE;

// 2. LIST come "ADT di I categoria"
typedef struct list_s *LIST;

// Funzioni richieste della traccia
void f(LIST l);
void deleteNode(NODE *node);



#endif //ASD_LABS_LIST_H