#include "functions.h"
#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    t_d_list liste;
    int val, answer, niveau,cell_val;
    printf("Combien de niveaux pour la liste :");
    scanf("%d",&val);
    liste = create_empty_list(val);

    while(answer != 0){
        printf("Voulez vous insérer une cellule ? (1 pour Oui, 0 pour Non)\n");
        scanf("%d",&answer);
        if(answer!=0){
            printf("Donnez la valeur et le niveau de la cellule :");
            scanf("%d %d",&cell_val ,&niveau);
            t_d_cell * cell = create_cell(cell_val,niveau);
            sort_insert_cell(cell,&liste);
        }

    }
    displayList(liste);


    return 0;
}