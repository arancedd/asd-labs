#include <stdio.h>
#include "optimization.h"

int main() {
    // Dati disordinati. Il programma deve trovare {50, 40, 40}
    int values[] = {10, 50, 20, 30, 40};
    int n = 5;
    int k = 3;

    solve_max_sum(n, k, values);

    return 0;

}