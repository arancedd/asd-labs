//
// Created by Edoardo on 05/02/2026.
//

#ifndef ASD_LABS_KNAPSACK_H
#define ASD_LABS_KNAPSACK_H


typedef struct {
    int id;
    int value;
    int weight;
} Item;

/*
 * items; array di oggetti
 * n: numero di oggetti disponibili
 * max_weight: capacità dello zaino
 */

void solve_knapsack(Item *items, int n, int max_weight);

#endif //ASD_LABS_KNAPSACK_H