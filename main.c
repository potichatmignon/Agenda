#include "functions.h"
#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    t_d_list liste;
    int val;
    scanf("Combien de niveau pour la liste : %d",val);
    liste = create_empty_list(val);
    printf(liste.heads[0]);
    return 0;
}