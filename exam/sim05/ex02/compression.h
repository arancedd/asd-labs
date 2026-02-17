#ifndef ASD_LABS_COMPRESSION_H
#define ASD_LABS_COMPRESSION_H

typedef struct list *link;

link comprimiLista(link head);

/* Prototipi per permettere al main di testare */
link nuovoNodo(char val, link next);
void stampaLista(link head);
void liberaLista(link head);

#endif //ASD_LABS_COMPRESSION_H