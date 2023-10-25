
#ifndef AGENDA_FUNCTIONS_H
#define AGENDA_FUNCTIONS_H
#include "cell.h"

typedef struct s_d_list
{
    t_d_cell* *heads;
    int max_level;
} t_d_list;

t_d_list create_empty_list(int);

void displayList(t_d_list l);

#endif //AGENDA_FUNCTIONS_H
