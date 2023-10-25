//
// Created by proem on 25/10/2023.
//

#ifndef AGENDA_FUNCTIONS_H
#define AGENDA_FUNCTIONS_H
#include "cell.h"

typedef struct s_d_list
{
    t_d_cell* *heads;
    int max_level;
} t_d_list;

t_d_list create_empty_list(int);



#endif //AGENDA_FUNCTIONS_H
