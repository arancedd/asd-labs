#include <stdio.h>
#include "knapsack.h"

int main() {


    Item items[] = {
        {0, 60, 10},
        {1, 100, 20},
        {2, 120, 30},
        {3, 200, 50},
        {4, 10, 5}
    };

    int n = 5;
    int capacity = 50;

solve_knapsack(items, n, capacity);

    return 0;
}