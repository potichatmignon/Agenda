#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

t_d_list create_empty_list(int max_level) {
    t_d_list* empty_list = (t_d_list*) malloc(sizeof(t_d_list));
    empty_list->max_level = max_level;
    for (int i=0; i<max_level; i++) {
        empty_list->heads[i] = NULL;
    }
    return *empty_list;
}

void displayList(t_d_list l) {
    for(int i=0;i<l.max_level;i++) {

        if (l.heads[i] == NULL) {
            printf("[list head_%d @-]--> NULL\n", i);
        }
    }
}