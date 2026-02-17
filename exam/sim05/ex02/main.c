#include <stdio.h>
#include "compression.h"

int main(void) {
    printf("--- COMPRESSIONE LISTA ---\n\n");

    /* Costruisco A -> A -> B -> C -> C -> C -> A -> NULL */
    link head = nuovoNodo('A',
                nuovoNodo('A',
                nuovoNodo('B',
                nuovoNodo('C',
                nuovoNodo('C',
                nuovoNodo('C',
                nuovoNodo('A', NULL)))))));

    printf("Lista originale:\n");
    stampaLista(head);

    /* Compressione */
    head = comprimiLista(head);

    printf("\nLista compressa (Attesa: A -> B -> C -> A -> NULL):\n");
    stampaLista(head);

    /* Pulizia finale della memoria */
    liberaLista(head);

    return 0;
}