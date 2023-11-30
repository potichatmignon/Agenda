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

// Insére une cellule en tête de liste
void insert_cell(t_d_cell * cell, t_d_list *list) {
    int level = cell->level;
    for(int i=0;i<level;i++){
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;
    }
}


// Insére une cellule dans la liste de manière trié et croissante
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

// Cherche une valeur depuis le premier étage de la liste
int find_from_zero(t_d_list list, int val) {
    t_d_cell * temp = list.heads[0];
    while (temp != NULL) {
        if (temp->value == val) {
            return 1;
        }
        temp = temp->next[0];
    }
    return 0;
}

// Cherche une valeur en partant du plus haut niveau de la liste
int find_from_top(t_d_list list, int val) {
    for (int i = list.max_level - 1; i >= 0; i--) {
        t_d_cell *temp = list.heads[i];
        while (temp != NULL && temp->value <= val) {
            if (temp->value == val) {
                return 1;
            }
            temp = temp->next[i];
        }
    }
    return 0;
}

// Retourne a^b
int exposant (int a, int b) {
    int temp = a;
    for(int i=0; i<b-1; i++) {
        a = a*temp;
    }
    return a;
}

// Retourne une liste de 2^n-1 élements de et de n niveaux
t_d_list create_complexity_list(int n) {
    t_d_list t = create_empty_list(n);
    int val_exposant = exposant(2, n);
    for (int i=1; i<val_exposant; i++) { // Pour se balader de cellule en cellule
        int j = 0;
        int level = 0;
        while (j<n) { // Tester chaque niveau de la cellule pour avoir son nombre de niveau
            if (i%2 == 1) {
                t_d_cell* t_cell = create_cell(i, 1);
                sort_insert_cell(t_cell, &t);
                break;
            }
            if (i%exposant(2, j)==0) {
                level += 1;
            }
            j += 1;
        }
        t_d_cell* t_cell = create_cell(i, level);
        sort_insert_cell(t_cell, &t);
    }
    return t;
}


/* FONCTION PAS FINIE */

char * scanString(void) {
    int taille = 10;
    char *chaine = (char *) malloc(taille * sizeof(char));
    int i = 0;
    char character;

    printf("Entrez la chaîne de caractères : ");
    while((character = getchar())!= '\n') {
        chaine[i] = character;
        i++;
        if (i>=taille){
            taille += i;
            chaine = (char*)realloc(chaine, taille*sizeof(char));
        }
    }
    chaine[i] = '\0';
    return chaine;
}

