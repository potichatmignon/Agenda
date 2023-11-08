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
    printf(">NULL\n");
}

void insert_cell(t_d_cell * cell, t_d_list *list) {
    int level = cell->level;
    for(int i=0;i<level;i++){
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;
    }
}




/*void sort_insert_cell(t_d_cell * cell, t_d_list *list){
    int level = cell->level;
    t_d_cell * temp = list->heads[level-1];
    t_d_cell * prev = temp;

    if(temp == NULL){
        printf("caca\n");
        insert_cell(cell,list);
    }
    else{
        for(int i=level-1;i>=0;i--){
            while(temp!=NULL && temp->value < cell->value){
                prev = temp;
                temp = temp->next[i];
                printf("%d\n",i);
            }

            if(temp == list->heads[i]){
                printf("heads\n");
                cell->next[i] = temp;
                list->heads[i] = cell;
            }
            else{
                if(temp==NULL){
                    printf("null\n");
                    cell->next[i] = NULL;
                    prev->next[i] = cell;
                    temp = prev;
                }
                else{
                    printf("other\n");
                    cell->next[i] = temp;
                    prev->next[i] = cell;
                    temp = prev;
                }

            }
        }
    }
}*/



void sort_insert_cell(t_d_cell * cell, t_d_list *list){
    int level = cell->level;
    t_d_cell * temp = list->heads[0];
    t_d_cell * prev = temp;

    if(temp == NULL){
        insert_cell(cell,list);
    }

    else{
        while(temp!=NULL && temp->value <= cell->value){
            prev = temp;
            temp = temp->next[0];
        }
        if(temp==NULL){
            for(int i=0;i<level;i++) {
                cell->next[i] = NULL;
                prev->next[i] = cell;
            }
        }
        else{
            if(temp == list->heads[0]){
                for(int i=0;i<level;i++){
                    cell->next[i] = list->heads[i];
                    list->heads[i] = cell;
                }
            }
            else{
                for(int i=0;i<level;i++) {
                    cell->next[i] = temp;
                    prev->next[i] = cell;
                }
            }

        }
    }
}

