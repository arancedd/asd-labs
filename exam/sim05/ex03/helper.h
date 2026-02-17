//
// Created by Edoardo on 17/02/2026.
//

#ifndef ASD_LABS_HELPER_H
#define ASD_LABS_HELPER_H

typedef struct treeNode *link;

int sommaRange(link root, int min, int max);

/* Aggiungiamo i prototipi per permettere al main di costruire l'albero */
link nuovoNodoAlbero(int val, link left, link right);
void liberaAlbero(link root);

#endif //ASD_LABS_HELPER_H