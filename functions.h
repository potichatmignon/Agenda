
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

void displayLevelList(t_d_list,int);

void insert_cell(t_d_cell*, t_d_list*);

void sort_insert_cell(t_d_cell*,t_d_list*);

int find_from_zero(t_d_list list, int val);
#endif //AGENDA_FUNCTIONS_H
