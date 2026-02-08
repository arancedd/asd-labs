//
// Created by Edoardo on 08/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Funzione (privata) per creare un nuovo nodo pulito
TreeNode *newNode(int key) {
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = key;
    temp->left = NULL;  // Nasce senza figli
    temp->right = NULL;
    return temp;
}

// Funzione helper
int max(int a, int b) {
    return (a > b) ? a : b; // if (a>b) return 'a' else return 'b'
}

TreeNode* insert(TreeNode *root, int key) {
    // 1. CASO BASE: Se sono arrivato in un punto vuoto (NULL), inserisco nuovo nodo
    if (root == NULL) {
        return newNode(key);
    }

    // 2. RICORSIONE: Cerco la strada giusta
    if (key < root->key) {
        // Se più piccolo, scendo a SINISTRA
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        // Se più grande, scendo a DESTRA
        root->right = insert (root->right, key);
    }
    // Se uguale non faccio nulla (No duplicati per ora

    return root; // Restituisco puntatore aggiornato
}

void print_inorder(TreeNode *root) {
    // Visita simmetrica (Sinistra -> io -> Destra)
    if (root != NULL) {
        print_inorder(root->left);          // 1. Stampa tutto ciò che è minore
        printf("%d ", root->key);      // 2. Stampa me
        print_inorder(root->right);          // 3. Stampa tutto ciò che è meggiore
        }
    }

void free_tree(TreeNode *root){
    if (root != NULL) {
        // Prima libero i figli (Post-Order), altrimenti perdo i puntatori!
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }


}

int tree_height(TreeNode *root) {
    // 1. CASO BASE: Albero vuoto -> altezza -1 (o 0, dipende dalla convenzione.)
    // Convenzione esame: spesso 0 per NULL, così una foglia ha altezza 1.
    if (root == NULL) return 0;

    // 2. CASO RICORSIVO
    // Chiedo altezza a sinistra e a destra

    int h_left = tree_height(root->left);
    int h_right = tree_height(root->right);

    //la mia altezza è 1 (io) + max dei miei figli
    return 1+ max(h_left, h_right);
}

int total_nodes(TreeNode *root) {
    // 1. CASO BASE
    if (root == NULL) return 0;

    // 2. PASSO RICORSIVO
    // 1(io) + tutti quelli a sx + tutti quelli a dx
    return 1+ total_nodes(root->left) + total_nodes(root->right);
}

TreeNode *min_value(TreeNode *root) {
    // 1. CASO BASE: Albero vuoto
    if (root == NULL) return NULL;

    // 2. ITERAZIONE
    // Vai sempre a sinistra finché non trovi il fondo
    TreeNode *current = root;
    while (current->left != NULL) {
        current =  current->left;
    }
    return current;

}

TreeNode *delete_node(TreeNode *root, int key) {
    // 1. CASO BASE: Albero vuoto o nodo non trovato
    if (root == NULL) return root;

    // 2. RICERCA DEL NODO
    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    // 3. TROVATO! (key == root->key)
    else {
        // CASO 1 & 2: una sola o nessuna foglia
        if (root->left == NULL) {
            TreeNode *temp = root->right;   // Salvo il figlio destro (o NULL)
            free(root);                     // Cancello me stesso
            return temp;                    // Ritorno il figlio al nonno
        }
        if (root->right == NULL) {
            TreeNode *temp = root->left;   // Salvo il figlio sinistro (o NULL)
            free(root);                     // Cancello me stesso
            return temp;                    // Ritorno il figlio al nonno
        }

        // CASO 3: Due figli
        // Trova il successore (più piccolo del rampo destro)
        // Nota: usiamo funzione 'min_value'
        // Prendiamo il ramo destro perchè il PADRE/NONNO deve essere
        // più GRANDE del successore per mantenere l'ordine
        TreeNode *temp = min_value(root->right);

        // Copia il valore del successore
        root->key = temp->key;

        // Cancella "vecchio" successore del ramo destro
        root->right = delete_node(root->right, temp->key);


    }
    return root;
}

TreeNode *load_tree_from_file(const char *filename) {
    FILE *f =fopen(filename, "r");
    if (f == NULL) {
        printf("ERRORE: Impossibile aprire il file %s\n", filename);
        return NULL;
    }

    TreeNode *root = NULL; //Partiamo da 0
    int val;

    // Leggi un intero alla volta finché il file non finisce (EOF)
    while (fscanf(f, "%d", &val) != EOF) {
        // Per ogni numero letto chiamiamo la nostra insert!
        root = insert(root, val);
    }

    fclose(f);
    printf("Caricamento completato da %s\n", filename);
    return root;
}


