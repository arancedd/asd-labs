#ifndef ASD_LABS_SIM0802_H
#define ASD_LABS_SIM0802_H

// 1. Definisci Key QUI (così il prototipo sa cos'è)
typedef int Key;

// 2. Definisci il puntatore al BST (questo può restare nascosto perché è un puntatore)
typedef struct binarysearchtree *BST;

// 3. Prototipo
int BSTcountBetween(BST b, Key k1, Key k2);

#endif //ASD_LABS_SIM0802_H