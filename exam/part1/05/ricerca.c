#include <stdio.h>
#include <stdlib.h>
#include "ricerca.h"

/* * LOGICA
 * Calcolo centro: mid = sx +(dx - sx) / 2
 * Non trovato: sx > dx -> return -1
 * Trovato: vett[mid] == key -> return mid
 * Ricorsione:
 *  - key < vett[mid]: cerca nella metà sinistra (mid - 1)
 *  - key > vett [mid] cerca nella metà destra (mid + 1 )
 */

int* carica_dati(char *filename, int *n) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return NULL;

    if (fscanf(fp, "%d", n) != 1) {
        fclose(fp);
        return NULL;
    }

    int *v = (int *) malloc((*n) * sizeof(int));
    if (v == NULL) {
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        fscanf(fp, "%d", &v[i]);
    }

    fclose(fp);
    return v;
}

int ricerca_binaria_R(int *vett, int sx, int dx, int key) {
    if (sx > dx) return -1;

    int mid = sx + (dx - sx) / 2;

    if (vett[mid] == key) {
        return mid;

    }else {
        if (key < vett[mid]) {
            return ricerca_binaria_R(vett, sx, mid -1, key);
        }else if (key > vett[mid]) {
            return ricerca_binaria_R(vett, mid + 1, dx, key);
        }
    }
}

void libera_dati (int *vett) {
    free(vett);
}
