//
// Created by Edoardo on 15/02/2026.
//


#include<stdlib.h>

#include "vett.h"

int* diffVett(int *a, int na, int *b, int nb, int *nc) {

    int i = 0, j = 0, k = 0;
    int *c = NULL; // Vettore soluzione

    //ALLOCHIAMO CASO PESISMO
    c = (int*)malloc(na * sizeof(int));
    if (c == NULL) exit(EXIT_FAILURE);

    while (i < na && j < nb) {

        // a[i] < b[j] -> Matematicamente, essendo tutti gli elementi in b
        // sempre più grandi non ci sarà MAI corrispondenza
        if (a[i] < b[j]) {
            c[k++] = a[i++]; // Salviamo nelle soluzioni e scorriamo sia l'indice della soluzione che il vettore
        }
        // a[i] > b[j] -> Possiamo ancora trovare b in a
        if (a[i] > b[j]) {
            j++;
        }

        // a[i] == b[j] -> Elemento trovato in entrambi -> SCARTIAMO (Vogliamo la differenza)
        if (a[i] == b[j]) {
            i++;
            j++;
        }
    }
    // Se b finisce vuol dire che tutti i rimanenti elementi di a non sono in b -> li prendo tutti
    while (i < na) {
        c[k++] = i;
    }

    *nc = k; // Siamo obbligati a salvare quanti elementi sono in c perchè ci serve nel main se vogliamo utilizzare il vettore in qualsiasi modo

    // Ottimizziamo la memoria ridimensionando la soluzione
    if (k > 0) {
        c = (int*)realloc(c, k*sizeof(int));
    }
    else {
        free(c);
        c = NULL;
    }
    return c;

}