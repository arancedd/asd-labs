#include "sim0802.h"
#include <stdlib.h>

// 1. Definisci la struttura "vera" dell'albero (Nascosta)
typedef struct BSTnode* link;

struct BSTnode {
    Key key;   // Usa la Key definita nell'header
    link left;
    link right;
};

struct binarysearchtree {
    link root;
    link z;
};

// 2. Funzioni Ausiliarie (Confronto)
int KEYcmp(Key k1, Key k2) {
    if (k1 < k2) return -1;
    if (k1 == k2) return 0;
    return 1;
}

Key KEYget(link node) {
    return node->key;
}

static int count_R(link h, Key k1, Key k2, int *foundCounter) {

    /* RETURN
     * 1 -> ho trovato una c
     *
     */


    // SE IL MIO NODO NON ESISTE
    if (h == NULL) return 0;

    // Mi salvo i risultati di KEYcmp per non stare ogni volta a riscrivere tutto
    int cmp1 = KEYcmp(k1, KEYget(h));
    int cmp2 = KEYcmp(k2, KEYget(h));

    // Chiamata la ricorsione iniziamo comparando il nodo su cui ci troviamo con k1 e k2
    if (cmp1 == 0 || cmp2 == 0) (*foundCounter)++;

    /* DOVE ANDIAMO?
     * Dobbiamo capire dove andare: se il nodo in cui mi trovo
     * ha già sforato una delle estremità del mio range è inutile che mi inoltro.
     * Quindi:
     * Se KEYGet(h) è <= k1 (estremo più piccolo) è inutile continuare ad andare a sinistra
     * Se KEYGet(h) è >= k2 (estremo più grande) è inutile continuare ad andare a destra
     */

    // Se KEYGet(h) è <= k1, vai a destra
    if (cmp1 >= 0) {
        return count_R(h->right, k1, k2, foundCounter);
    }
    // Se KEYGet(h) è >= k2, vai a sinistra
    if (cmp2 <=0) {
        return count_R(h->left, k1, k2, foundCounter);
    }

    // Se sono in un punto in mezzo nel range conto me stesso (1) e vado da entrambe le parti
    return 1 + count_R(h->left, k1, k2, foundCounter) + count_R(h->right, k1, k2, foundCounter);

}

int BSTcountBetween(BST b, Key k1, Key k2) {

    // Controllo se effettivamente l'albero esista
    if (b == NULL) return -2;
    int foundCounter = 0;
    int res = count_R(b->root, k1, k2, &foundCounter);

    // Se abbiamo trovato meno di due chiavi torniamo -1
    if (foundCounter < 2) return -1;
    return res;

}