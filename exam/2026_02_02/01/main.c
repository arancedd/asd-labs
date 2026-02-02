#include <stdio.h>
#include <stdlib.h> //OBBLIGATORIA per malloc e free

int main() {
    int n, i;
    float *vett, somma = 0.0;

    printf("Quanti elementi vuoi inserire?" );
    if (scanf("%d", &n) != 1 || n <=0 ) return -1;

    //ALLOCAZIONE DINAMICA T(n) = O(1), S(n) = O(n)
    vett = (float *) malloc(n * sizeof(float));

    //CONTROLLO vettore
    if (vett == NULL) {
        printf("Errore di allocazione memoria\n");
        return -1;
    }

    //RIEMPIMENTO vettore: T(n) = O(n)
    for (i = 0 ; i < n ; i++) {
        printf("Inserire elemento %d: ", i + 1);
        scanf("%f", &vett[i]);
        somma += vett[i];
    }

    if (n>0) {
        printf("\nMedia: %.2f\n", somma / n);

    }

    // LIBERAZIONE MEMORE: fondamentale per evitare leak
    free(vett);

    return 0;

}