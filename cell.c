#include <stdlib.h>
#include <stdio.h>
#include "cell.h"

t_d_cell* create_cell(int val, int level) {
    t_d_cell* cell = (t_d_cell*) malloc(sizeof(t_d_cell));
    cell->value = val;
    cell->level = level;
    cell->next = (t_d_cell**) malloc(level*sizeof(t_d_cell*));
    return cell;
}



