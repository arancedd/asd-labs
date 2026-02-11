# Part 1: Fondamenta e Ricerca Binaria

Questa sezione copre le basi fondamentali per affrontare l'esame di Algoritmi in C, concentrandosi sulla gestione della memoria e sull'approccio "Divide et Impera".

## 🎯 Obiettivi
- Comprendere l'uso dei puntatori e degli array.
- Implementare la **Ricerca Binaria** (Binary Search) ricorsiva.
- Gestire input/output base.

## 📚 Teoria: Divide et Impera
La **Ricerca Binaria** è l'algoritmo standard per trovare un elemento in un array *ordinato*. Invece di controllare ogni elemento uno per uno ($O(n)$), l'algoritmo:
1. Guarda l'elemento centrale.
2. Se è quello cercato, fine.
3. Se è maggiore, scarta tutta la metà destra e ripete a sinistra.
4. Se è minore, scarta la metà sinistra e ripete a destra.

### Complessità
- **Tempo**: $O(\log n)$ (Ogni passo dimezza il problema).
- **Spazio**: $O(\log n)$ (Per lo stack delle chiamate ricorsive).

## 💻 Pattern di Codice
```c
int binary_search(int *arr, int l, int r, int target) {
    if (l > r) return -1; // Caso Base: Elemento non trovato
    
    int mid = l + (r - l) / 2; // Calcolo centro sicuro (evita overflow)
    
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binary_search(arr, l, mid - 1, target);
    return binary_search(arr, mid + 1, r, target);
}