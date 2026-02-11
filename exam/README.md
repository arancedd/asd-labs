# 🎓 Algoritmi e Strutture Dati in C - Percorso di Preparazione

Questa repository contiene il percorso completo di preparazione all'esame di Algoritmi e Strutture Dati. Il codice è diviso in **4 Sprint** (Parti) di difficoltà crescente, progettati per coprire ogni tipologia di esercizio richiesta: dalla gestione della memoria alla risoluzione di problemi complessi su Grafi.

## 🗺️ Mappa del Percorso

| Directory | Focus Principale | Concetti Chiave | Obiettivo d'Esame |
| :--- | :--- | :--- | :--- |
| **📂 part1** | **Fondamenta & Ricorsione** | Puntatori, Aritmetica dei Puntatori, Ricerca Binaria, Divide et Impera | Gestione base della memoria e algoritmi $O(\log n)$. |
| **📂 part2** | **Ottimizzazione Combinatoria** | Backtracking, Insieme delle Parti, Pruning (Potatura), Wrapper Functions | Risolvere problemi tipo "Zaino" (Knapsack) o "Selezione Ottima". |
| **📂 part3** | **Strutture Dati Dinamiche** | Alberi Binari di Ricerca (BST), Struct, Allocazione Dinamica, File I/O | Costruire, navigare e modificare strutture dati collegate. |
| **📂 part4** | **Grafi & Percorsi** | Matrici di Adiacenza, DFS (Profondità), Backtracking su Grafi | Trovare cammini, uscite da labirinti e connessioni. |

---

## 📚 Dettaglio dei Moduli

### 1️⃣ Part 1: Fondamenti (`/part1`)
Punto di partenza. Abbandoniamo la logica sequenziale per abbracciare la **Ricorsione**.
* **Teoria:**
    * **Stack Frame:** Come la memoria gestisce le chiamate ricorsive.
    * **Complessità Logaritmica:** Perché dimezzare il problema ad ogni passo (Binary Search) è infinitamente meglio di scorrere un array.
* **Codice Chiave:** `binary_search_recursive`
* **Da Ricordare:** *Ogni funzione ricorsiva deve avere un Caso Base (uscita) e un Passo Ricorsivo (avanzamento).*

### 2️⃣ Part 2: Backtracking e Pruning (`/part2`)
Come funziona *Problem Solving*. Non ci concentriamo sulla ricerca dei dati ma sulla **generazione di soluzioni**.
* **Teoria:**
    * **Spazio degli Stati:** L'albero immaginario di tutte le possibili combinazioni.
    * **Pruning (Potatura):** La tecnica fondamentale per tagliare i rami "morti" dell'albero decisionale (es. "Se ho già sforato il peso, non continuo ad aggiungere oggetti").
* **Scenario Tipico:** *Knapsack Problem* (Riempire uno zaino di valore massimo senza rompere la capienza).
* **Da Ricordare:** *Il Pruning trasforma un algoritmo impossibile ($O(2^n)$) in uno fattibile.*

### 3️⃣ Part 3: Alberi Binari (BST) (`/part3`)
Introduzione alle strutture non lineari. I dati non sono più uno dopo l'altro, ma organizzati gerarchicamente.
* **Teoria:**
    * **BST Property:** Sinistra < Padre < Destra.
    * **Visita In-Order:** L'algoritmo magico che stampa i dati ordinati attraversando l'albero.
    * **Cancellazione:** Il caso difficile (Nodo con 2 figli) che richiede la sostituzione con il *Successore*.
* **Codice Chiave:** `insert`, `delete_node`, `load_from_file`.
* **Da Ricordare:** *L'altezza dell'albero determina la velocità. Un albero bilanciato è veloce, una linea retta è lenta.*

### 4️⃣ Part 4: Grafi e Labirinti (`/part4`)
Strutture senza gerarchia, con cicli e percorsi multipli.
* **Teoria:**
    * **Rappresentazione:** Matrice di Adiacenza ($N \times N$) vs Liste.
    * **DFS (Depth First Search):** L'esplorazione "audace" che va in profondità fino al vicolo cieco.
    * **Vettore `visited`:** Essenziale per non girare in tondo nei cicli.
* **Scenario Tipico:** *Longest Path Problem* (Trovare il cammino semplice più lungo).
* **Da Ricordare:** *Il Backtracking sui grafi richiede di segnare il nodo come "Visitato" all'andata e "Non Visitato" al ritorno (dopo il ciclo for).*

---

---

## 🛠️ Cheat Sheet Tecnico: "Salva-Esame"

Questa lista contiene gli errori più comuni e le *Best Practices* fondamentali. Leggila prima di iniziare a scrivere codice per evitare i bug più frequenti.

### 🧠 1. Gestione della Memoria (`malloc` / `free`)
* **La Formula Magica:** `tipo *ptr = (tipo*) malloc(n * sizeof(tipo));`
    * *Errore Comune:* Dimenticare `sizeof(tipo)` o moltiplicare male `n`.
* **Array Puliti:** Se ti serve un array di contatori o di "visitati" (tutti a 0), usa `calloc` invece di `malloc`.
    * `int *visited = (int*) calloc(N, sizeof(int));` (Già inizializzato a 0).
* **Stringhe:** Ricorda sempre il carattere terminatore!
    * `malloc(strlen(s) + 1);` (Quel `+1` è vitale).
* **Pulizia:** Per ogni `malloc` scritta, chiediti: "Dove ho messo la `free` corrispondente?".

### 👉 2. Puntatori e Frecce
* **Quando usare `.` (punto)?** Quando hai la **variabile** strutturata in mano.
    * `Graph g; g.V = 5;`
* **Quando usare `->` (freccia)?** Quando hai un **puntatore** alla struttura.
    * `Graph *g; g->V = 5;`
* **La Regola d'Oro:** `ptr->campo` è solo una scorciatoia per `(*ptr).campo`.

### 📂 3. File I/O (Lettura Dati)
* **Controllo Apertura:** Mai dare per scontato che il file esista.
    * `if (f == NULL) { return error; }`
* **Il Ciclo di Lettura Perfetto:**
    * ❌ *Sbagliato:* `while (!feof(f))` (Spesso legge l'ultima riga due volte).
    * ✅ *Giusto:* `while (fscanf(f, "%d", &val) != EOF)`
* **Stringhe nei file:** `fscanf(f, "%s", buffer)` si ferma al primo spazio! Per leggere righe intere serve `fgets`.

### 🌳 4. Alberi (BST)
* **Aggiornare la Radice:** Le funzioni che modificano l'albero (insert, delete) devono ritornare il puntatore nuovo, altrimenti le modifiche si perdono.
    * ❌ *Sbagliato:* `insert(root, 50);`
    * ✅ *Giusto:* `root = insert(root, 50);`
* **Il Caso Base:** Ogni funzione ricorsiva deve iniziare con `if (root == NULL) ...`.
* **Cancellazione:**
    * **0 Figli:** `free(node); return NULL;`
    * **1 Figlio:** `temp = child; free(node); return temp;`
    * **2 Figli:** Trova successore (minimo a destra), copia valore, cancella successore ricorsivamente.

### 🕸️ 5. Grafi e Matrici
* **Allocazione Matrice:** Se la matrice è statica (`adj[MAX][MAX]`), ricorda di inizializzarla a 0 (con `init_graph` o cicli for).
* **Orientamento (Cruciale):**
    * *Grafo Orientato (A->B):* `adj[u][v] = 1;`
    * *Grafo Non Orientato (A-B):* `adj[u][v] = 1; adj[v][u] = 1;`
* **Limiti Array:** Controlla sempre che `u` e `v` siano `< N` prima di accedere alla matrice per evitare crash (Segmentation Fault).

### 🔙 6. Backtracking (Ricorsione Complessa)
* **Wrapper:** Usa sempre una funzione wrapper (che prepara `visited`, `best_sol`, ecc.) e una funzione ricorsiva interna `_R`.
* **Pruning (Potatura):** Controlla i vincoli **PRIMA** di scendere in ricorsione per risparmiare tempo.
    * `if (peso_corrente + nuovo_peso <= max) { recurse(); }`
* **La "Smarcata" (Backtracking sui Grafi):**
    * Lo "smarcamento" (`visited[u] = 0`) va fatto **DOPO** il ciclo `for` che esplora i vicini, non dentro!
    * Metterlo dentro il ciclo causa loop infiniti e crash dello stack.

### 🚨 7. Debug Rapido (Se il programma crasha)
1.  **Segmentation Fault (0xC0000005):** Hai usato un puntatore `NULL` o sei uscito dai bordi di un array. Controlla `malloc`, `fopen` e indici dei cicli.
2.  **Heap Corruption:** Hai scritto fuori da una `malloc` (es. stringa senza `+1` o array troppo piccolo). Manca `<stdlib.h>`?
3.  **Stack Overflow:** Ricorsione infinita. Hai dimenticato il Caso Base o il controllo `visited` nei grafi.

## 🚀 Come Eseguire
Ogni cartella è un progetto a sé stante.
1.  Entra nella cartella (es. `cd part3`).
2.  Compila con `gcc main.c tree.c -o app` (o usa CMake/CLion).
3.  Assicurati che i file `.txt` di input siano nella stessa cartella dell'eseguibile.

---
*Progetto realizzato durante le sessioni di tutoraggio intensivo per l'esame di Algoritmi.*