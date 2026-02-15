//
// Created by Edoardo on 15/02/2026.
//

#ifndef ASD_LABS_BST_H
#define ASD_LABS_BST_H


/* 1. Definizione dell'ADT di Prima Classe (Puntatore Opaco)
 * Diciamo al compilatore: "Esiste una struct bst_t, ma non ti dico come è fatta".
 * Il main conoscerà solo il tipo 'BST'. */
typedef struct bst_t *BST;


void BSTprintDeepest (BST b);


/* Funzioni di utilità necessarie al main per creare e distruggere l'albero
 * (In sede d'esame non ti è richiesto scriverle se non specificato,
 * ma servono per un progetto compilabile) */
BST BSTinit(void);
void BSTfree(BST b);
void BSTinsertTest(BST b); /* Funzione fittizia per riempire l'albero nel test */


#endif //ASD_LABS_BST_H