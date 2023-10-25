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


    /*t_d_cell * cell = create_cell(5,2);
    t_d_cell * cell2 = create_cell(3,1);
    printf("%d\n",cell->level);
    printf("%d\n",cell->value);
    cell->next[0] = cell2;
    printf("%d",cell->next[0]->value);*/

    return 0;
}