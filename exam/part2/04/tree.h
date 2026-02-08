//
// Created by Edoardo on 08/02/2026.
//

#ifndef ASD_LABS_TREE_H
#define ASD_LABS_TREE_H

// Struttura dati per un nodo di un albero binario
typedef struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Funzioni per la gestione dell'albero
TreeNode* insert(TreeNode *root, int key);          // Inserisci numero
void print_inorder(TreeNode *root);                 // Stampa in ordine
void free_tree(TreeNode *root);                     // Libera memoria
int tree_height(TreeNode *root);                    // Calcola altezza (profondità massima)
int total_nodes(TreeNode *root);                    // Conta numero totale nodi
TreeNode *min_value(TreeNode *root);                // Trova nodo con valore minimo
TreeNode *delete_node(TreeNode *root, int key);     // Cancella un nodo
TreeNode *load_tree_from_file(const char *filename); // Carica albero da file

#endif //ASD_LABS_TREE_H