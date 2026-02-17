#include "helper.h"
#include <stdlib.h> /* Serve per malloc, free ed exit */

struct treeNode {
    int val;
    link left;
    link right;
};

/* --- FUNZIONI DI SUPPORTO AGGIUNTE QUI --- */
link nuovoNodoAlbero(int val, link left, link right) {
    link x = malloc(sizeof *x);
    if (x == NULL) exit(EXIT_FAILURE);
    x->val = val;
    x->left = left;
    x->right = right;
    return x;
}

void liberaAlbero(link root) {
    if (root == NULL) return;
    liberaAlbero(root->left);
    liberaAlbero(root->right);
    free(root);
}
/* ----------------------------------------- */

int sommaRange(link root, int min, int max) {

    // CASO BASE: albero o ramo vuoto
    if (root == NULL) {
        return 0;
    }

    int res = 0;

    // Sono in range?
    if (root->val >= min && root->val <= max) {
        res += root->val;
    }

    // PRUNING SINISTRA
    if (root->val > min) {
        res += sommaRange(root->left, min, max);
    }

    // PRUNING DESTRA
    if (root->val < max) {
        res += sommaRange(root->right, min, max);
    }

    return res;
}