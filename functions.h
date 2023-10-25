
#ifndef AGENDA_FUNCTIONS_H
#define AGENDA_FUNCTIONS_H
#include "cell.h"

typedef struct s_d_list
{
    int max_level;
    t_d_cell* *heads;
} t_d_list;

t_d_list create_empty_list(int);

void displayList(t_d_list l);

t_d_cell* insert_cell(t_d_cell * cell, t_d_list *list);
#endif //AGENDA_FUNCTIONS_H
