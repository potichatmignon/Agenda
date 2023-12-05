#include "functions.h"
#include "cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start_timer() {
    return clock();
}

double stop_timer(clock_t start) {
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    t_d_list liste;
    int val, answer = 1, niveau,cell_val;
    int val_find;
    contact name;
    char *time;
    int res;
    clock_t start;
    double duration;

    printf("Créer une liste manuel (1) ou automatique (2):");
    scanf("%d", &answer);
    if (answer == 1) {
        printf("Combien de niveaux pour la liste manuel:");
        scanf("%d",&val);
        liste = create_empty_list(val);
        displayList(liste);
    }
    if (answer == 2) {
        printf("Combien de niveaux pour la liste automatique: ");
        scanf("%d", &val);
        liste = create_complexity_list(val);
        displayList(liste);
    }

    while(answer != 0) {
        printf("Voulez vous insérer une cellule ? (1 pour Oui, 0 pour Non)\n");
        printf("Ou vous voulez chercher une cellule ? (2)\n");
        printf("ou comparer deux algorithmes de recherche (3):\n");
        scanf("%d", &answer);
        if (answer == 1) {
            printf("Donnez la valeur et le niveau de la cellule :");
            scanf("%d %d", &cell_val, &niveau);
            t_d_cell *cell = create_cell(cell_val, niveau);
            sort_insert_cell(cell, &liste);
            displayList(liste);
        }
        if (answer == 2) {
            printf("Quelle méthode utiliser ? (6: depuis le zero; 7: depuis le niveau haut)\n");
            scanf("%d", &answer);
            if (answer == 6) {
                printf("Methode par le zero\n");
                printf("Quelle valeur à chercher ? (val)\n");
                scanf("%d", &val_find);
                if (find_from_zero(liste, val_find) == 1) {
                    printf("Valeur trouvee\n");
                }
                else {
                    printf("Valeur non trouvee\n");
                }
            }
            if (answer == 7) {
                printf("Methode par le haut\n");
                printf("Quelle valeur à chercher ? (val)\n");
                scanf("%d", &val_find);
                res = find_from_top(liste, val_find);
                if (res == 1) {
                    printf("Valeur trouvee\n");
                }
                else {
                    printf("Valeur non trouve ;e\n");
                }
            }
        }
        // Comparer deux algorithmes de recherche
        if (answer == 3) {
            printf("Quelle valeur sougaitez-vous chercher: ");
            scanf("%d", &val_find);

            printf("Lancement de l'algorithme de recherche par la liste zero\n");
            start = start_timer();
            res = find_from_zero(liste, val_find);
            duration = stop_timer(start);
            if (res == 1) {
                printf("Valeur trouvee en %f\n", duration);
            }
            else {
                printf("Valeur non trouvee\n");
            }


            printf("Lancement de l'algorithme de recherche par la liste du haut\n");
            start = start_timer();
            res = find_from_top(liste, val_find);
            duration = stop_timer(start);
            if (res == 1) {
                printf("Valeur trouvee en %f\n", duration);
            }
            else {
                printf("Valeur non trouvee\n");
            }
        }
    }
    displayList(liste);
    return 0;
}