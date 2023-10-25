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
    displayList(liste);

    t_d_cell * cell = create_cell(3,3);
    t_d_cell * cell2 = create_cell(4,3);
    insert_cell(cell,&liste);
    insert_cell(cell2,&liste);
    displayLevelList(liste,0);


    return 0;
}