//
// Created by Edoardo on 16/02/2026.
//

#include "potatura.h"

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    link left;
    link right;
};

link pruneLeaves(link root, int K) {
    // 1. CASO BASE: Albero vuoto
    if (root == NULL) return NULL;

    //2. CHIAMATE RICORSIVE (Post-Order)
    root->left = pruneLeaves(root->left, K);
    root->right = pruneLeaves(root->right, K);

    //3. VALUTO ME STESSO
    if (root->left == NULL && root->right == NULL) { // Se sono una foglia
        if (root->val < K) {
            free(root);
            return NULL;
        }
    }

    // 4. Caso normale: non sono una foglia OPPURE >=K
    return root;
}

/* Inserimento classico da BST (ricorsivo) */
link BSTinsert(link root, int val) {
    if (root == NULL) {
        link x = malloc(sizeof(struct node));
        if (x == NULL) exit(EXIT_FAILURE);
        x->val = val;
        x->left = NULL;
        x->right = NULL;
        return x;
    }
    if (val < root->val) {
        root->left = BSTinsert(root->left, val);
    } else if (val > root->val) {
        root->right = BSTinsert(root->right, val);
    }
    return root;
}

/* Stampa In-Order (dal più piccolo al più grande) */
void BSTprint(link root) {
    if (root == NULL) return;
    BSTprint(root->left);
    printf("%d ", root->val);
    BSTprint(root->right);
}

/* Deallocazione totale dell'albero (Post-Order) */
void BSTfree(link root) {
    if (root == NULL) return;
    BSTfree(root->left);
    BSTfree(root->right);
    free(root);
}