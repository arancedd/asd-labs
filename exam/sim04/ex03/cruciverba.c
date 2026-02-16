//
// Created by Edoardo on 16/02/2026.
//

#include "cruciverba.h"

#include <stdlib.h>
#include <string.h>

int trovaParola_R(char **M, int R, int C, char *parola, int i, int j) {


    /* 1. CASO BASE DI FALLIMENTO (Muro o Lettera Sbagliata o Cella Già Usata):
 * - Sono uscito dai bordi?
 * - La lettera su cui sono atterrato è diversa da quella che cerco?
 * - Sono finito su un '*' (cella già usata per questa parola)? */
    if (i < 0 || i >= R || j < 0 || j >= C || M[i][j] != parola[0]) {
        return 0;
    }

    /* 2. CASO BASE DI SUCCESSO:
     * Ho cercato l'n-esima lettera, ma l'n-esima lettera è '\0'.
     * Parola trovata */
    if (parola[1] == '\0') {
        return 1;
    }



    /* 3. SONO SULLA LETTERA GIUSTA
     * Salvo la lettera e "sporco" la matric  per non ripassarci */
    char temp = M[i][j];
    M[i][j] = '*';

    /* 4. CHIAMATE RICORSIVE (N, S, E, O)
     * L'operatore || (OR) fa sì che appena una mossa restituisce 1,
     * si fermano tutte e restituisce 1 all'istante */
    int trovato = trovaParola_R(M, R, C, parola + 1, i+1, j) ||  /* SUD */
                  trovaParola_R(M, R, C, parola + 1, i-1, j) ||  /* NORD */
                  trovaParola_R(M, R, C, parola + 1, i, j+1) ||  /* EST */
                  trovaParola_R(M, R, C, parola + 1, i, j-1);    /* OVEST */

    /* 5. BACKTRACKING
     * Ho esplorato tutte le vie da qui (sia in caso di successo che fallimento).
     * Tolgo l'asterisco e rimetto la lettera, lascio la matrice pulita! */
    M[i][j] = temp;

    /* Ritorno al livello superiore se l'ho trovata (1) o no (0) */
    return trovato;
}




int trovaParola(char **M, int R, int C, char *parola) {

    /* DOBBIAMO TROVARE IL PRIMO CARATTERE PRIMA DI FAR PARTIRE LA RICORSIONE */
    /* Scorro tutta la matrice */
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            /* Ho trovato la prima lettera? */
            if (M[i][j] == parola[0]) {

                /* Lancio l'esploratore ricorsivo da questa cella (passo n=0) */
                if (trovaParola_R(M, R, C, parola, i, j) == 1) {
                    return 1; /* Trovata -> Interrompo il ciclo */
                }
            }
        }
    }
    return 0; /* Ho setacciato tutta la matrice, parola inesistente */

}