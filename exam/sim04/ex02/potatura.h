//
// Created by Edoardo on 16/02/2026.
//

#ifndef ASD_LABS_POTATURA_H
#define ASD_LABS_POTATURA_H

typedef struct node *link;

link pruneLeaves(link root, int K);

/* Funzioni di utilità per testare l'albero */
link BSTinsert(link root, int val);
void BSTprint(link root);
void BSTfree(link root);

#endif //ASD_LABS_POTATURA_H