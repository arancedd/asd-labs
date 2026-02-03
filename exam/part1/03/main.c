#include <stdio.h>
#include <stdlib.h>

int main() {
    typedef struct {
        char name[30];
        int age;
    }Atleta;

    FILE *fp;
    int n, i;

    // 1. Apertura file
    fp = fopen("atleti.txt", "r");
    if (fp == NULL) {
        perror("Errore lettura file");
        return -1;
    }

    if (fscanf(fp, "%d", &n) != 1) {
        perror("Errore dimensione");
        fclose(fp);
        return -1;
    }

    Atleta *vett = (Atleta *) malloc(n * sizeof(Atleta));

    for (i = 0; i < n; i++) {
        fscanf(fp, "%s %d", vett[i].name, &vett[i].age);
    }
    fclose(fp);

    printf("Atleti:\n");
    for (i = 0; i < n; i++) {
        printf("%s %d\n", vett[i].name, vett[i].age);
    }

    free(vett);

    return 0;
}