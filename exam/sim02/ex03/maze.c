//
// Created by Edoardo on 15/02/2026.
//


#include "maze.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchPath(char **area, int **visited, int N, int M, int *bestStep, int step, int i, int j, int r1, int c1) {


    //CONDIZIONI DI USCITA
    //Percorso più lungo del percorso trovato
    if (step >= *bestStep){
        return;
    }

    // Raggiunte le coordinate obiettivo
    if (i == r1 && j == c1 ) {
        *bestStep = step;
        return;
    }

    visited[i][j] = 1; // Segniamo il percorso

    // i + 1 -> Sotto
    // i - 1 -> Sopra
    // j + 1 -> Destra
    // j - 1 -> Sinistra


    // Destra
    if (j + 1 < M && area[i][j+1] == '0' && visited[i][j+1] == 0) {
        searchPath(area, visited,N, M, bestStep, step + 1, i, j + 1, r1, c1);
    }
    // Sinistra
    if (j - 1 < 0 && area[i][j-1] == '0' && visited[i][j-1] == 0) {
        searchPath(area, visited, N, M, bestStep, step + 1, i, j - 1, r1, c1);
    }
    //Sotto
    if (i + 1 < N && area[i+1][j] == '0' && visited[i-1][j] == 0) {
        searchPath(area, visited, N, M, bestStep, step + 1, i + 1, j, r1, c1);
    }
    //Sopra
    if (i - 1 < 0 && area[i-1][j] == '0' && visited[i-1][j] == 0) {
        searchPath(area, visited, N, M, bestStep, step + 1, i - 1, j, r1, c1);
    }

    visited[i][j] = 0;

}

int minPath(char **area, int N, int M, int r0, int c0, int r1, int c1){

    int bestStep = N*M;
    int **visited;

    // Controlliamo se le coordinate sono valide
    if (r0 < 0 || r0 >= N || r1 < 0 || r1 >= N ||
        c0 < 0 || c0 >= M || c1 < 0 || c1 >= M ||
        area[r0][c0] == '1' || area[r1][c1] == '1') {
        printf("ERRORE: Coordinate non valide\n");
        return -1;
        }


    /* Allocazione dinamica corretta della matrice visited (piena di zeri) */
    visited = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        visited[i] = (int *)calloc(M, sizeof(int));
    }

    searchPath(area, visited, N, M, &bestStep, 1, r0, c0, r1, c1);

    if (bestStep == N * M + 1) {
        return -1; /* Non ha trovato nessuna strada */
    }

    return bestStep;

}

