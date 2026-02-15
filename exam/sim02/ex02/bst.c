//
// Created by Edoardo on 15/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

typedef struct bstNode *link;
struct bstNode {
    char *key;
    link left;
    link right;
};

struct bst_t {
    link root;
    int size;
};

/* 2. FUNZIONE PRIVATA (Ausiliaria)
 * Nota: usare 'static' in C significa "questa funzione è visibile SOLO dentro BST.c".
 * Il main non può chiamare searchDeepest per sbaglio. */
static void searchDeepest(link h, int level, char **current_path, char **best_path, int *max_level, char **max_str) {
    // CONDIZIONE DI TERMINAZIONE
    if (h == NULL) return;

    current_path[level] = h->key;

    // Se siamo una foglia
    if (h->left == NULL && h->right == NULL) {
        //Controlliamo se siamo il percorso più lungo, e se abbiamo la stessa lughezza comapriamo le stringe
        if (level >= *max_level || (*max_level == level && strcmp(h->key, *max_str)) > 0 ) {
            // Aggiorniamo percorso più lungo e stringa di tale eprcorso
            *max_level = level;
            *max_str = h->key;

            // Salviamo il percorso attuale nel percorso migliore
            for (int i = 0; i <= level; i++) {
                best_path[i] = current_path[i];
            }
        }
    }

    // Eseguiamo lo stesso algoritmo per le altre foglie
    searchDeepest(h->left, level + 1, current_path, best_path, max_level, max_str);
    searchDeepest(h->right, level + 1, current_path, best_path, max_level, max_str);
}

// FUNZIONE WRAPPER (Chiamata dal main)
void BSTprintDeepest(BST b) {
    char **current_path, **best_path;
    char *max_str = "";
    int max_level = -1;

    if (b == NULL || b->root == NULL || b->size == 0) return;

    current_path = (char**)malloc(b->size * sizeof(char *));
    best_path = (char**)malloc(b->size * sizeof(char*));

    if (current_path == NULL || best_path == NULL) exit(EXIT_FAILURE);
    searchDeepest(b->root, 0, current_path, best_path, &max_level, &max_str);


    for (int i = max_level; i >=0; i--) {
        printf("%s\n", best_path[i]);
    }

    free(current_path);
    free(best_path);
}

/* --- SEGUONO LE IMPLEMENTAZIONI DELLE FUNZIONI DI UTILITA' --- */
BST BSTinit(void) {
    BST b = malloc(sizeof(struct bst_t));
    if (b == NULL) exit(EXIT_FAILURE);
    b->root = NULL;
    b->size = 0;
    return b;
}

static link newNode(char *key) {
    link x = malloc(sizeof(struct bstNode));
    if (x == NULL) exit(EXIT_FAILURE);
    x->key = key;
    x->left = x->right = NULL;
    return x;
}

void BSTinsertTest(BST b) {
    /* Costruiamo manualmente l'albero del nostro test precedente */
    b->root = newNode("Mela");
    b->root->left = newNode("Banana");
    b->root->right = newNode("Pera");
    b->root->left->left = newNode("Ananas");
    b->root->left->right = newNode("Ciliegia");
    b->root->right->right = newNode("Zucchina");
    b->root->left->right->left = newNode("Cedro");
    b->root->right->right->left = newNode("Uva");
    b->size = 8;
}

static void freeTree(link h) {
    if (h == NULL) return;
    freeTree(h->left);
    freeTree(h->right);
    free(h);
}

void BSTfree(BST b) {
    if (b == NULL) return;
    freeTree(b->root);
    free(b);
}