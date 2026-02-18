//
// Created by Edoardo on 18/02/2026.
//

#include "sim0702.h"

#include <stdlib.h>

struct Tree {
    int val;
    struct Tree *left;
    struct Tree *right;
};

void contaNodi_R(link root, int *tot) {

    if(root == NULL) return;


    // SE sono una foglia
    if (root->left != NULL || root->right != NULL) {
        (*tot)++;
    }

    contaNodi_R(root->left, tot);
    contaNodi_R(root->right, tot);
}

int contaNodi(link root) {
     int tot = 0;
    contaNodi_R(root, &tot);

    return tot;
}

int contaNodiV2(link root) {
    // Albero vuoto
    if (root == NULL) return 0;

    // Caso base: sono una foglia -> valgo 0
    if (root->left == NULL && root->right == NULL) return 0;

    // Non sono una foglia (ho superato l'if precedente) -> sono per forza un padre
    // Valgo 1 + albero sinstra + albero destra
    // Farò tutta la ricorsione a sinistra finchè non torno un intero, poi faccio tutta la ricorsione destra
    return 1 + contaNodiV2(root->left) + contaNodiV2(root->right);
}