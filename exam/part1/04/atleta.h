

#ifndef ATLETA_H
#define ATLETA_H

typedef struct {
    char name[51];
    int age;
} Atleta;

Atleta* atleti_leggi(char *file_name, int *n);

void atleti_stampa(Atleta *vett, int n);

void atleti_libera(Atleta *vett);

#endif //ATLETA_H