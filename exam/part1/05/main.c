#include <stdio.h>
#include "ricerca.h"

int main() {
    int n = 0;
    int target = 99;

    int *dati = carica_dati("data.txt", &n);
    if (dati == NULL) {
        printf("Errore file\n");
        return -1;
    }

    // Chiamata iniziale: da indice 0 ad n-1
    int pos = ricerca_binaria_R(dati, 0, n-1, target);

    if (pos != -1) {
        printf("trovato %d alla riga %d del file -> indice array [%d]\n", target, pos + 2, pos);
    }else {
        printf("Numero %d non trovato\n", target);
    }

    libera_dati(dati);
    return 0;
}