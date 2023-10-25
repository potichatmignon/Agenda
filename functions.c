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
void displayLevelList(t_d_list liste,int n) {

}

void displayList(t_d_list l) {
    for(int i=0;i<l.max_level;i++) {

        if (l.heads[i] == NULL) {
            printf("[list head_%d @-]--> NULL\n", i);
        }
    }
}

void displayCell(t_d_list list, int val){}

t_d_cell* insert_cell(t_d_cell * cell, t_d_list *list) {
    int level = cell->level;
    for(int i=0;i<level;i++){
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;
    }
}