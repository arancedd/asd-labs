//
// Created by Edoardo on 16/02/2026.
//

#include "alternate.h"

#include <stdlib.h>
#include <string.h>

char* interleaveStrings(const char *s1, const char *s2) {

    char *str = (char *)malloc((strlen(s1)+strlen(s2)+1)*sizeof(char));
    if (str == NULL) exit(EXIT_FAILURE);
    int i,j,k = 0;
    while (s1[i] != '\0' || s2[j] != '\0') {
        if (s1[i] != '\0') str[k++] = s1[i++];
        if (s2[j] != '\0') str[k++] = s2[j++];
    }
    str[k] = '\0';
    str = (char *)realloc(str, (k+1)*sizeof(char));
    if (str == NULL) exit(EXIT_FAILURE);

    return str;
}
