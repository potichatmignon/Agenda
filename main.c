#include "functions.h"
#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    t_d_list liste;
    int val;
    printf("Combien de niveaux pour la liste :");
    scanf("%d",&val);
    liste = create_empty_list(val);

    t_d_cell * cell = create_cell(35,2);
    t_d_cell * cell2 = create_cell(4,3);
    t_d_cell * cell3 = create_cell(5,1);
    t_d_cell * cell4 = create_cell(6,4);
    insert_cell(cell,&liste);
    insert_cell(cell2,&liste);
    insert_cell(cell3,&liste);
    insert_cell(cell4,&liste);
    displayList(liste);


    return 0;
}