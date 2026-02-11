# Part 2: Backtracking e Ottimizzazione (Knapsack)

Questa sezione introduce il concetto di **Backtracking** applicato a problemi di ottimizzazione combinatoria, come il "Problema dello Zaino" (Knapsack Problem).

## 🎯 Obiettivi
- Generare combinazioni (Insieme delle Parti).
- Risolvere problemi di ottimizzazione (Massimizzare valore dato un vincolo).
- Implementare il **Pruning** (Potatura) per efficienza.

## 📚 Teoria: Backtracking con Pruning
Il Backtracking è una tecnica per esplorare sistematicamente tutte le possibili soluzioni (Spazio degli Stati). Immagina un albero decisionale:
- **Nodo**: Una scelta parziale (es. "Prendo l'oggetto A").
- **Ramo**: Una decisione futura.

### Il Concetto di Pruning (Potatura) ✂️
Esplorare tutto è troppo lento ($O(2^n)$). Il **Pruning** consiste nell'interrompere l'esplorazione di un ramo appena capiamo che non porterà a una soluzione valida (es. abbiamo già superato il peso massimo dello zaino).
*Senza Pruning:* Controllo tutto e poi filtro.
*Con Pruning:* Mi fermo prima di sbagliare.

## 💻 Pattern di Codice
```c
void knapsack_R(..., int curr_weight, ...) {
    // Check Record
    if (curr_val > best_val) update_best();

    for (int i = start; i < n; i++) {
        // PRUNING: Entro solo se l'oggetto "ci sta"
        if (curr_weight + items[i].weight <= max_weight) {
            // Do (Aggiungo)
            sol[pos] = i;
            // Recurse
            knapsack_R(..., curr_weight + items[i].weight);
            // Backtracking (Implicito o Esplicito)
        }
    }
}