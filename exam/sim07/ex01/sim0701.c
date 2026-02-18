//
// Created by Edoardo on 18/02/2026.
//

#include "sim0701.h"

#include <stdlib.h>
#include <string.h>

char* mergeAlternato(char *s1, char *s2) {

    // Alloco caso peggiore
    char *str = (char *)malloc((strlen(s1)+strlen(s2)+1*sizeof(char)));
    if (str == NULL) return NULL;

    int i=0, j=0, k=0;

    while (s1[i] != '\0' || s2[j] != '\0') {
        if (s1[i] != '\0') {
            str[k++] = s1[i++];
        }
        if (s2[j] != '\0') {
            str[k++] = s2 [j++];
        }
    }

    // Aggiungiamo ovviamene l'ultimo carattere a \0
    str[k] = '\0';

    str = (char*)realloc(str, (k+1)*sizeof(char));

    return str;
}


char* mergeAlternatoV2(char *s1, char *s2) {

    // ALLOCAZIONE MEMORIA
    // La lunghezza della stirgna finale è ovviamente la lunghezza delle due stighe di partenza + 1
    char *str = (char*)malloc((strlen(s1)+strlen(s2) + 1)*sizeof(char));

    // Dichiarazione indici per scorrimento vettori
    int i=0, j=0, k=0;

    // CICLO 1: iterazione finché una delle due stringhe non finisce
    while (s1[i] != '0' && s2[j] != '0') {
        str[k++] = s1[i++];
        str[k++] = s2[j++];
    }

    // CICLO 2: Stringa 1 finita -> Inserisco in coda il resto di s2
    while (s2[j] != '\0') {
        str[k++] = s2[j++];
    }

    // CICLO 3: Stringa 2 finita -> Inserisco in coda il resto di s1
    while (s1[i] != '\0') {
        str[k++] = s1[i++];
    }

    // Inserisco termine stringa
    str[k] = '\0';

    return str;
}