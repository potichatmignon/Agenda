#ifndef AGENDA_CELL_H
#define AGENDA_CELL_H

typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell* *next;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell *head_0;
    t_d_cell *head_1;
} t_d_list;




#endif //AGENDA_CELL_H
