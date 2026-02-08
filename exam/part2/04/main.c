//
// Created by Edoardo on 08/02/2026.
//

#include <stdio.h>
#include "tree.h"

int main() {
    TreeNode *root = NULL;  // L'albero nasce vuoto
    TreeNode *rootF = NULL; // Albeor per file

    // Inseriamo numeri in ordine sparso
    // Immagina l'albero che cresce: 50 è la radice. 30 va a sx. 20 va a sx di 30...
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Numeri ordinati (In-Order): ");
    print_inorder(root); // Dovrebbe stampare: 20 30 40 50 60 70 80
    printf("\n");


    printf("Statistiche Albero:\n");
    printf("- Altezza: %d\n", tree_height(root));
    printf("- Totale Nodi: %d\n", total_nodes(root));

    TreeNode *min_node = min_value(root);
    if (min_node != NULL) {
        printf("- Valore Minimo: %d\n", min_node->key);
    }

    printf("\n--- TEST CANCELLAZIONE ---\n");

    // Caso 1: Cancella una foglia (es. 20 o 40 o 60 o 80)
    printf("Cancello 20 (Foglia)...\n");
    root = delete_node(root, 20);
    print_inorder(root);
    printf("\n");

    // Caso 2: Cancella nodo con 1 figlio (Difficile da simulare col tuo albero attuale
    // perché è molto bilanciato, ma fidiamoci della logica)

    // Caso 3: Cancella nodo con 2 figli (es. 30 o 70 o 50)
    printf("Cancello 50 (Radice con 2 figli)...\n");
    root = delete_node(root, 50);
    print_inorder(root);
    printf("\n");

    free_tree(root);

    printf("--- CARICAMENTO DA FILE --- \n");

    root = load_tree_from_file("data.txt");
    if (root == NULL) {
        printf("Nessun albero caricato.\n");
        return 1;
    }

    // 2. STAMPA E VERIFICA
    printf("Albero caricato (In-Order): ");
    print_inorder(root);
    printf("\n");

    // 3. STATISTICHE
    printf("Nodi totali: %d\n", total_nodes(root));
    printf("Altezza: %d\n", tree_height(root));

    // 4. TEST CANCELLAZIONE
    printf("\n--- Cancellazione Radice (50) ---\n");
    root = delete_node(root, 50);
    print_inorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}