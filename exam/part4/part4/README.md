# Part 4: Grafi e Cammini (DFS & Longest Path)

L'ultima parte unisce tutto: strutture dati complesse e algoritmi di ricerca avanzati. Lavoriamo su Grafi rappresentati tramite Matrici di Adiacenza.

## 🎯 Obiettivi
- Rappresentare un Grafo (Matrice $N \times N$).
- Capire la differenza tra Grafi Orientati e Non Orientati.
- Implementare la visita **DFS** (Depth First Search).
- Risolvere problemi complessi: **Cammino Semplice Più Lungo**.

## 📚 Teoria: Esplorazione e Backtracking
Un Grafo è un insieme di Nodi collegati da Archi.
- **DFS (Depth First Search)**: Algoritmo "labirinto". Segue un percorso finché non sbatte contro un vicolo cieco, poi torna indietro all'ultimo bivio.
- **Array `visited`**: Fondamentale per evitare cicli infiniti (es. A va a B, B va ad A).

### Backtracking sul Grafo
Per trovare il cammino più lungo, dobbiamo esplorare, ma anche permettere al programma di "cambiare idea".
1. Marco il nodo come `visited`.
2. Esploro i vicini ricorsivamente.
3. **Backtracking**: Smarco il nodo (`visited[u] = 0`) *dopo* aver esplorato tutti i vicini, così quel nodo può essere riutilizzato in percorsi alternativi.

## 💻 Pattern di Codice
```c
void dfs_longest_path(int u, int *visited) {
    visited[u] = 1; // Mark
    
    // ... logica per salvare il percorso migliore ...

    for (each neighbor v) {
        if (!visited[v]) dfs_longest_path(v, visited);
    }

    visited[u] = 0; // Backtrack (Cruciale!)
}