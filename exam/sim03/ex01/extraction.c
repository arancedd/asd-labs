//
// Created by Edoardo on 16/02/2026.
//

#include "extraction.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char* extractDigits(const char *str) {

    char *digits;
    int i =0;
    int j=0;

    if (str == NULL) return NULL;

    // Allochiamo caso peggiore
    digits = (char*)malloc((strlen(str)+1)*sizeof(char));
    if (digits == NULL) {
        exit(EXIT_FAILURE); /* Controllo fallimento memoria */
    }

    while (str[i] != '\0') {
        if (isdigit(str[i])) digits[j++] = str[i];
        i++;

    }
    digits[j] = '\0';


    digits =(char*)realloc(digits, (j+1)*sizeof(char));
    return digits;


}