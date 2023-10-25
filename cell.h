#ifndef AGENDA_CELL_H
#define AGENDA_CELL_H

typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell* *next;
} t_d_cell;

t_d_cell * create_cell(int,int);




#endif //AGENDA_CELL_H
