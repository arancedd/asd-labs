//
// Created by Edoardo on 18/02/2026.
//

#ifndef ASD_LABS_SIM0801_H
#define ASD_LABS_SIM0801_H

typedef struct node {
    char *val;
    struct node *next;
}*link;

link removeDupl(link h);

#endif //ASD_LABS_SIM0801_H