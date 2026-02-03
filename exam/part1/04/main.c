#include <stdio.h>
#include <stdlib.h>
#include "atleta.h"


int main() {
    int n_atleti = 0;
    Atleta *vettore = NULL;

    vettore = atleti_leggi("atleti.txt", &n_atleti);

    if (vettore == NULL) {
        printf("Errore durante lettura file.\n");
        return -1;
    }

    printf("Caricati %d atleti:\n", n_atleti);
    atleti_stampa(vettore, n_atleti);

    atleti_libera(vettore);

    return 0;

}
