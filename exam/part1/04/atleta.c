#include <stdio.h>
#include <stdlib.h>
#include "atleta.h"

Atleta* atleti_leggi(char *file_name, int *n) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return NULL;

    if (fscanf(fp, "%d", n) != 1) {
        fclose(fp);
        return NULL;
    }

    Atleta *vett = (Atleta *) malloc((*n)*sizeof(Atleta));
    if (vett == NULL) {
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        fscanf(fp, "%50s %d", &vett[i].name, &vett[i].age);
    }

    fclose(fp);
    return vett;

}

void atleti_stampa(Atleta *vett, int n) {
    if (vett == NULL) return;
    for (int i = 0; i < n; i++) {
        printf("Atleta [%d]: %s (%d anni)\n", i+1, vett[i].name, vett[i].age);
    }
}

void atleti_libera(Atleta *vett) {
    free(vett);
}