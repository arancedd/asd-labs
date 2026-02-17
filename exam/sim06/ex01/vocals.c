//
// Created by Edoardo on 17/02/2026.
//

#include "../vocals.h"
#include <ctype.h>

int isVowel(char c) {

    c = toupper(c);
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ) {
        return 1;
    }
    return 0;
}

int rimuoviVocali(char *str) {
    int removed = 0;
    int j=0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isVowel(str[i])) {
            removed ++;
        }
        else {
            str[j] = str[i];
            j++;
        }

    }

    return removed;
}