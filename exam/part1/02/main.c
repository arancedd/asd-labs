#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int n, i;
    float *vett;

    // 1. Apertura file in letture ("r")
    fp = fopen("dati.txt", "r");
    if (fp == NULL) {
        perror("Errore apertura file");
        return -1;
    }

    // 2. Lettura dimensione (legge la dimensione inizio file e lo mette in &n per poi allocare memoria)
    if (fscanf(fp, "%d", &n) != 1) { //fscanf legge 5 e aumenta il cursore di uno
        perror("Dimensione diversa da 1");
        fclose(fp);
        return -1;
    }

    // 3. Allocazione dinamica: S(n) = O(n)
    vett = (float *) malloc(n * sizeof(float));
    if (vett == NULL) {
        fclose(fp);
        return -1;
    }

    // 4. Lettura dati: T(n) = O(n)
    for (i = 0; i < n; i++) { //cursore già aumentato di 1 quindi apre dall nuova riga
        fscanf(fp, "%f", &vett[i]);
    }

    // 5. Chiusura file e stampa
    fclose(fp);

    printf("Dati letti con successo: \n");
    for (i = 0; i < n; i++) {
        printf("%.1f\n", vett[i]);
    }

    // 6. Pulizia memoria
    free(vett);

    return 0;
}