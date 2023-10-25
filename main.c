#include "functions.h"
#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    t_d_list liste;
    int val;
    printf("Combien de niveau pour la liste : ");
    scanf("%d",val);
    liste = create_empty_list(val);
    displayList(liste);
    return 0;
}