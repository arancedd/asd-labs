# Part 3: Alberi Binari di Ricerca (BST)

Questa sezione copre le strutture dati dinamiche non lineari. Creiamo, navighiamo e modifichiamo un **BST** (Binary Search Tree).

## 🎯 Obiettivi
- Definire `struct` con puntatori (`left`, `right`).
- Implementare inserimento, ricerca e visita **In-Order**.
- Calcolare statistiche (Altezza, Conteggio Nodi).
- Gestire la **Cancellazione** di un nodo (Caso complesso).
- Caricamento da file.

## 📚 Teoria: Proprietà del BST
Un BST è un albero dove per ogni nodo:
1. I valori nel sottoalbero **Sinistro** sono minori (`<`).
2. I valori nel sottoalbero **Destro** sono maggiori (`>`).

Questa proprietà permette:
- **Ricerca**: Simile alla Binary Search ($O(\log n)$ se bilanciato).
- **Ordinamento**: Una visita *In-Order* (Sinistra -> Centro -> Destra) restituisce i valori già ordinati.

### La Cancellazione
Rimuovere un nodo è delicato. Se il nodo ha 2 figli, non possiamo lasciare un "buco".
**Strategia**: Sostituiamo il nodo da cancellare con il suo **Successore** (il nodo più piccolo del ramo destro), che preserva l'ordine del BST.

## 💻 Pattern di Codice
```c
typedef struct node {
    int key;
    struct node *left, *right;
} node_t;

// Visita Ricorsiva
void print_inorder(node_t *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->key);
        print_inorder(root->right);
    }
}