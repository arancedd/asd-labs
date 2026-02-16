#include <stdio.h>
#include <stdlib.h>
#include "potatura.h"

int main(void) {
    /* 1. L'albero parte vuoto (NULL) */
    link radice = NULL;

    /* 2. Costruiamo un BST di prova
     * (Nota come aggiorniamo sempre 'radice' per non perdere i pezzi!) */
    radice = BSTinsert(radice, 10);
    radice = BSTinsert(radice, 5);
    radice = BSTinsert(radice, 15);
    radice = BSTinsert(radice, 2);  /* Foglia < 8 */
    radice = BSTinsert(radice, 7);  /* Foglia < 8 */
    radice = BSTinsert(radice, 12); /* Foglia >= 8 */
    radice = BSTinsert(radice, 20); /* Foglia >= 8 */

    /* Struttura attuale:
     * 10
     * /    \
     * 5      15
     * / \    /  \
     * 2   7  12   20
     */

    printf("--- PRIMA DELLA POTATURA ---\n");
    printf("Nodi (In-Order): ");
    BSTprint(radice);
    printf("\n\n");

    /* 3. TEST DELL'ESAME: Tagliamo tutte le foglie minori di 8 */
    int K = 8;
    printf("Eseguo pruneLeaves(radice, %d)...\n\n", K);

    /* ATTENZIONE: Anche qui aggiorniamo la radice, caso mai
     * l'intera radice fosse diventata una foglia da tagliare! */
    radice = pruneLeaves(radice, K);

    printf("--- DOPO LA POTATURA ---\n");
    printf("Nodi (In-Order): ");
    BSTprint(radice);
    /* I nodi 2 e 7 dovrebbero sparire. Il 5, diventato foglia e < 8,
     * dovrebbe sparire anch'esso per l'effetto Bottom-Up! */
    printf("\n");

    /* 4. Pulizia finale */
    BSTfree(radice);

    return 0;
}