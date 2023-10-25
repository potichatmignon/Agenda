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

t_d_list create_empty_list(int max_level) {
    t_d_list* empty_list = (t_d_list*) malloc(sizeof(t_d_list));
    empty_list->max_level = max_level;
    empty_list->heads = NULL;
    return *empty_list;
}