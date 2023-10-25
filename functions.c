#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

t_d_list create_empty_list(int max_level) {
    t_d_list list;
    list.heads = (t_d_cell**) malloc(max_level*sizeof(t_d_cell*));
    list.max_level = max_level;
    for (int i=0; i<max_level; i++) {
        list.heads[i] = NULL;
    }
    return list;
}

void displayList(t_d_list l) {
    for(int i=0;i<l.max_level;i++) {

        if (l.heads[i] == NULL) {
            printf("[list head_%d @-]--> NULL\n", i);
        }
    }
}

t_d_cell* insert_cell( t_d_cell cell, t_d_list *list) {

    t_d_cell *temp_cell = list->heads[cell.value]->next;
    list->heads[level]->next =
}