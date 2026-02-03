
#ifndef RICERCA_H
#define RICERCA_H

// Funzione di caricamento
int* carica_dati(char *filename, int *n);

/* * RICERCA BINARIA RICORSIVA
 * vett: puntatore all'array
 * sx: indice sinistro (start)
 * dx: indice destro (end)
 * key: valore da cercare
 * RETURN -> indice elemento se trovato, -1 se non trovato.
 */

int ricerca_binaria_R(int *vett, int sx, int dx, int key);

void libera_dati(int *vett);

#endif //RICERCA_H