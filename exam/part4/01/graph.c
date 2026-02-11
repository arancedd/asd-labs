//
// Created by Edoardo on 11/02/2026.
//

#include <stdlib.h>
#include <string.h>
#include "graph.h"

static int *best_path;
static int max_len = -1;

void init_graph(Graph *G, int num_vertices) {
    G->V=num_vertices;
    // Puliamo la matrice: tutto a 0 (no collegamenti)
    for (int i=0; i<MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            G->adj[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {

    // Controllo indici validi
    if (u >= 0 && u  < G->V && v >= 0 && v < G->V) {
        G->adj[u][v] = 1;
        // Se il grafo NON è ORIENTATO (A-B uguale a B-A):
        G->adj[v][u] = 1;
    }
}

void print_graph(Graph *G) {
    printf("--- MATRICE DI ADIACENZA (%d nodi) ---\n", G->V);
    for (int i = 0; i < G->V; i++) {
        printf ("%d: ", i);
        for (int j = 0; j < G->V; j++) {
            printf ("%d ", G->adj[i][j]);
        }
        printf("\n");
    }
}

void load_graph_from_file(Graph *G, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("ERRORE: apertura file %s\n", filename);
        return;
    }

    int num_v;
    fscanf(f, "%d", &num_v); // Leggiamo quanti nodi ci sono

    init_graph(G, num_v); // Inizializziamo la struttura

    int u, v;
    // Leggiamo coppie di nodi collegati (esempio: "0 1" significa arco 0->1)
    while (fscanf(f, "%d %d", &u, &v) != EOF) {
        add_edge(G, u, v);
    }

    fclose(f);
    printf("Grafo caricato da %s.\n", filename);

}

// Funzione ricorsiva interna
void dfs_R(Graph *G, int u, int *visited) {
    // 1. Visita il nodo corrente
    printf("%d ", u);
    visited[u] = 1; // Segna come visitato

    // 2. Cerca i vicini
    for (int v = 0; v < G->V; v++) {
        // Se c'è un arco (adj[u][v] == 1) e non l'ho ancora visitato
        if (G->adj[u][v] == 1 && visited[v] == 0) {
            dfs_R(G, v, visited); // Ricorsione
        }
    }

}

void longest_path_R(Graph *G, int u, int *visited, int *current_path, int current_len) {
    // 1. Aggiungo il nodo corrente al percorso
    visited[u] = 1; // Marco come visitato
    current_path[current_len] = u; // Lo salvo nel percorso attuale

    // 2. Controllo se ho battuto il record
    if (current_len > max_len) {
        max_len = current_len;
        // Salvo la soluzione migliore
        // NOTA: 'current_len' è l'indice, quindi la dimensione è 'current_len+1'
        for (int k = 0; k <= max_len; k++) best_path[k] = current_path[k];
    }

    // 3. Esploro i vicini
    for (int v = 0; v <G->V; v++) {
        // Se c'è un arco e non l'ho già visitato in QUESTO percorso
        if (G->adj[u][v] == 1 && visited[v]==0) {
            longest_path_R(G, v, visited, current_path, current_len+1);
        }


    }
    // 4. BACKTRACKING
    // Prima di tornare al padre pulisco 'visited' cosi gli altri percorsi possono utilizzarmi
    visited[u] = 0;
}

// Wrapper
void graph_dfs(Graph *G, int start_node) {
    // Creiamo un array per tenere traccia di chi abbiamo già visto
    //calloc inizializza tutto a 0 (NON visitato)
    int *visited = (int *)calloc(G->V, sizeof(int));

    if (visited == NULL) return;

    printf("DFS partendo dal nodo %d: ", start_node);

    // Lanciamo la ricorsione
    dfs_R(G, start_node, visited);
    printf("\n");
    free(visited);
}

void find_longest_path(Graph *G, int start_node) {
    int *visited = (int *)calloc(G->V, sizeof(int));
    int *current_path = (int *)calloc(G->V, sizeof(int));
    best_path= (int *)malloc(G->V * sizeof(int)); // Allocato sulla variabile statica
    max_len = -1;

    printf("Cercando il cammino piu' lungo da %d...\n", start_node);

    // Lancio la ricorsione: livello 0 (lunghezza percorso: 0)
    longest_path_R(G, start_node, visited, current_path, 0);

    // Stampa risultato
    printf("Cammino MAX trovato (Lunghezza %d archi): ", max_len);
    for (int i = 0; i<=max_len;i++) {
        printf("%d ", best_path[i]);
        if (i < max_len) printf("-> ");
    }
    printf("\n");

    free(visited);
    free(current_path);
    free(best_path);
}


