
#ifndef AGENDA_FUNCTIONS_H
#define AGENDA_FUNCTIONS_H
#include "cell.h"
#include "timer.h"

typedef struct s_d_list
{
    int max_level;
    t_d_cell* *heads;
} t_d_list;

typedef struct contact
{
    char * nom;
}contact;

typedef struct date
{
    int jour;
    int mois;
    int annee;
}date;

typedef struct horaire
{
    int heure;
    int minute;
}horaire;

typedef struct rdv
{
    date date;
    horaire debut;
    horaire duree;
    char * objet;
}rdv;




t_d_list create_empty_list(int);

void displayList(t_d_list l);

void displayLevelList(t_d_list,int);

void insert_cell(t_d_cell*, t_d_list*);

void sort_insert_cell(t_d_cell*,t_d_list*);

t_d_cell* find_from_zero(t_d_list, int);

t_d_cell* find_from_top(t_d_list, int);

int exposant(int, int);

t_d_list create_complexity_list(int);

char * scanString(void);

#endif //AGENDA_FUNCTIONS_H
