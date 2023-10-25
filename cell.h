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
    t_d_cell* *heads;
    int max_level;
} t_d_list;

t_d_cell * create_cell(int,int);


#endif //AGENDA_CELL_H
