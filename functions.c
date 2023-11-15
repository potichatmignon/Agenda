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
        displayLevelList(l,i);
    }
}

void displayLevelList(t_d_list list, int n){
    t_d_cell * temp = list.heads[n];
    t_d_cell * temp_base = list.heads[0];
    printf("[list->head_%d @-]--",n);

    while(temp_base!=NULL){
        if(temp == NULL){
            printf("-----------");
            temp_base = temp_base->next[0];
        }
        else{
            if (n>0){
                if (temp!=temp_base){
                    printf("-----------");
                    temp_base = temp_base->next[0];
                }
                else{
                    printf(">[%3d|@-]--",temp->value);
                    temp = temp->next[n];
                    temp_base = temp_base->next[0];
                }
            }
            else{
                printf(">[%3d|@-]--",temp->value);
                temp = temp->next[n];
                temp_base = temp_base->next[0];
            }
        }

    }
    printf(">NULL\n");
}

void insert_cell(t_d_cell * cell, t_d_list *list) {
    int level = cell->level;
    for(int i=0;i<level;i++){
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;
    }
}



void sort_insert_cell(t_d_cell * cell, t_d_list *list) {
    int level = cell->level;
    t_d_cell * temp;
    t_d_cell * prev;
    if(list->heads[0]==NULL){
        insert_cell(cell,list);
        return;
    }
    for(int i=0;i<level;i++){
        temp = list->heads[i];
        prev = temp;
        while(temp!=NULL && temp->value < cell->value){
            prev = temp;
            temp = temp->next[i];
        }
        if(temp==list->heads[i]){
            cell->next[i] = list->heads[i];
            list->heads[i] = cell;
        }

        else{
            if(temp==NULL){
                cell->next[i] = NULL;
                prev->next[i] = cell;
            }
            else{
                cell->next[i] = temp;
                prev->next[i] = cell;
            }

        }
    }
}

// Return 0 s'il trouve pas  || Return 1 s'il trouve
int find_from_zero(t_d_list list, int val) {
    t_d_cell * temp = list.heads[0];
    while (temp->next != NULL) {
        printf("temp->value= %d \n", temp->value); // Pour le debug
        if (temp->value == val) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}