//
// Created by Edoardo on 11/02/2026.
//

#ifndef ASD_LABS_GRAPH_H
#define ASD_LABS_GRAPH_H
#include <stdio.h>

#define MAX_NODES 20 // dimensione massima per l'esame (spesso basta)

typedef struct {
    int V; // Numero effettivo di vertici (Nodi)
    int adj[MAX_NODES][MAX_NODES]; // Matrice: 1 se colleganti 0 se no.
}Graph;

// Inizializza grafico vuoto
void init_graph(Graph *G, int num_vertices);

// Aggiunge arco (collegamento)
void add_edge(Graph *G, int u, int v);

// Stampa la matrice per debug
void print_graph(Graph *G);

// Carica da file (Simulazione esame)
void load_graph_from_file(Graph *G, const char *filename);

// Visita in profondita a partire dal nodo 'start node'
void graph_dfs(Graph *G, int start_node);

void find_longest_path(Graph *G, int start_node);


#endif //ASD_LABS_GRAPH_H