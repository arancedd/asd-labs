//
// Created by Edoardo on 12/02/2026.
//

#ifndef ASD_LABS_DATA_H
#define ASD_LABS_DATA_H

typedef struct {
    int day;
    int month;
    int year;
    int hh;
    int mm;
}DateTime;


typedef struct {
    DateTime dateTime;          // Chiave di ricerca nel BST
    int amount;         // Somma delle quantità scambiate
    float totPrice;     // Somma (price*amount)
    float avgPrice;     // totPrice / amount
}Price;

typedef struct BSTNode {
    Price stock;              // Dato
    // float totPrice;
    struct BSTNode *left;   // Figlio sinistro (dati minori)
    struct BSTNode *right;  // Figlio destro (dati maggiori)
}BSTNode;

typedef struct {
    char ticker[21];
    BSTNode *root_price; // Puntatore al BST quotazioni
}Stock;

typedef struct ListNode{
    Stock val;
    struct ListNode *next; // Puntatore al prossimo titolo
}ListNode;


DateTime parseDateTime(char dateTime[]);
ListNode *addStock(char *ticker, ListNode *ln);
BSTNode *bst_update(BSTNode *root, Price *stock);
void add_transaction(DateTime dt, char *ticker, float amount, int qty, Stock *stock );
ListNode load_from_file(ListNode *ln, const char *filename);
ListNode search_stock(ListNode *head, char ticker);
void search_price();


#endif //ASD_LABS_DATA_H