//
// Created by Edoardo on 15/02/2026.
//

#include "group.h"



void powerset_pruning (int pos, int *sol, int num_scelti, int *best_sol, int *min_scelti,int *controllo, int **M, int O, int S) {
    int valido = 1;

    // CRITERIO DI PURNING: se sto usando già troppi insiemi rispetto il mio record, taglia ramo
    if (num_scelti >= *min_scelti) return;

    // CASO BASE: fondo dell'albero
    if (pos >= S) {
        // Controllo se tutti gli elementi al fondo sono '1' altrimenti soluzione NON valida
        for (int i = 0; i < O; i++) {
            if (controllo[i] == 0) return;
        }

        // Se arrivo qui, ho una soluzione valida ed è migliore del record -> aggiorno il record
        *min_scelti = num_scelti;
        for (int i = 0; i < S; i++) best_sol[i] = sol[i];

        return;
    }

    // === BIFORCAZIONE ALBERO ===

    // SCELTA 0 -> non prendo sottoinsieme 'pos'
    sol[pos] = 0;
    powerset_pruning(pos+1, sol, num_scelti, best_sol, min_scelti, controllo, M, O, S);

    // SCELTA 1 -> Prendo il sottoinsieme 'pos'
    sol[pos] = 1;

    // CONTROLLO SU MATRICE FORNITA
    for (int i = 0; i < O ; i++) {
        if (M[i][pos] == 1) {
            controllo[i]++;
            if (controllo[i] > 1){
                valido = 0; //  CRITERIO PRUNING: Sovrapposizione
            }
        }
    }

    if (valido == 1) {
        powerset_pruning(pos+ 1, sol, num_scelti + 1, best_sol, min_scelti, controllo, M, O , S);
    }

    /* BACKTRACKING (FONDAMENTALE):
         * Indipendentemente dal fatto che io sia sceso nel ramo o che abbia fatto pruning,
         * devo "smontare" la Scelta 1 prima di risalire la ricorsione!
         * Devo togliere gli oggetti che avevo aggiunto al vettore 'controllo'. */

    for (int i = 0; i < O; i++) {
        if (M[i][pos] == 1) {
            controllo[i]--;
        }
    }
}
