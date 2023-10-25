#include "functions.h"
#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    t_d_cell * cell = create_cell(5,2);
    printf("%d\n",cell->level);
    printf("%d\n",cell->value);

    return 0;
}