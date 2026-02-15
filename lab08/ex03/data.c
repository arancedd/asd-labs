//
// Created by Edoardo on 12/02/2026.
//

#include <stdlib.h>
#include<stdio.h>
#include "data.h"

#include <string.h>


BSTNode *NewNode(Price *stock) {
    BSTNode *temp = (BSTNode *)malloc(sizeof(BSTNode));
    temp->stock = *stock;
    temp->left = NULL;  // Nasce senza figli
    temp->right = NULL;
    return temp;
}

int DateTime_cmp(DateTime dt1, DateTime dt2) {
    if (dt1.year != dt2.year) return dt1.year - dt2.year;
    if (dt1.month != dt2.month) return dt1.month - dt2.month;
    if (dt1.day != dt2.day) return dt1.day - dt2.day;

    if (dt1.hh != dt2.hh) return dt1.hh - dt2.hh;
    if (dt1.mm != dt2.mm) return dt1.mm - dt2.mm;
}

// struct BSTnode * bst_update(struct BSTnode * left, Price * price);

BSTNode *bst_update(BSTNode *root, Price *q) {
    // CASO BASE: Albero vuoto -> creo il nodo quì
    if (root == NULL) {
        return NewNode(q);
    }
    const int cmp= DateTime_cmp(q->dateTime, root->stock.dateTime);

    if (cmp < 0) {
        root->left = bst_update(root->left,q);
    }
    else if (cmp > 0) {
        root->right = bst_update(root->right, q);
    }

    else {

    }

    return root;
}

void add_transaction(DateTime dt, char *ticker, float amount, int qty, Stock *s ) {
    bst_update(s->root_price, s->root_price->stock);

}

ListNode *searchStock(ListNode *head, char *tickerSearch) {
    ListNode *curr = head; // Parto dalla testa

    while (curr != NULL) {
        // Confronto
        if (strcmp(curr->val.ticker, tickerSearch)== 0) {
            return curr; // Trovato! Restituisci puntatore al vafone
        }

        curr = curr->next; // Prossimo elemento lista
    }
    return NULL;
}

ListNode *addStock(char *ticker, ListNode *ln) {

    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    if (new == NULL) exit(1); // Controllo memoria

    // Riempio struct stock
    strcpy(new->val.ticker, ticker);
    new->val.root_price = NULL;

    // Il nuovo elemento della lista è la nua head
    new->next = ln;
    return new;



    printf("ERRORE: Aggiunta stock alla lsita");
    return NULL;

}

ListNode load_from_file(ListNode *ln, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("ERRORE: lettura file %s", filename);
    }
    int nStocks;
    fscanf(f,"%d", &nStocks);


    //Ciclo sui titoli
    for (int i = 0; i<nStocks; i++) {
        char tickerTmp[21];
        int nTrans;

        fscanf(f, "%s %d", tickerTmp, &nTrans);

        // 1. RICERCA: il titolo esiste già?
        ListNode *nodeStock = searchStock(ln, tickerTmp);

        // 2. GESTIONE: Se non esiste lo creo
        if (nodeStock == NULL) {
            ln = addStock(tickerTmp, ln);
            nodeStock = ln; // Ora il nodo corrente è nuovo ed è in testa.
        }

        for (int j=0; j < nTrans; j++) {
            DateTime dt;
            float val;
            int qty;
            Stock stock = ln->val;

            fscanf(f, "%d/%d/%d %d:%d &f &d", &dt.year, &dt.month, &dt.day,
                    &dt.hh, &dt.mm,
                    &val, &qty);
            add_transaction(dt, tickerTmp, val, qty, &nodeStock->val);

        }

    }



}