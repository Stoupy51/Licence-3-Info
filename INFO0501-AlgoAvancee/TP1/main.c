
#include "liste.h"

int main() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\nDébut du main()\n");

    /**
     * Tests de la liste chaînée
    **/
    int x;
    Liste l = initListe();
    CELLULE c;
    char prompt = 'Y';
    while (prompt == 'Y' || prompt == 'y') {
        printf("\nEntrez un entier : ");
        scanf("%d", &x);
        insertListe(&l, newCellule(x));
        printListe(l);
        printf("\nVoulez-vous continuer d'entrer des valeurs ? (Y/N) ");
        scanf("%s", &prompt);
    }
    prompt = 'Y';
    while (prompt == 'Y' || prompt == 'y') {
        printf("\nQuel entier voulez-vous supprimer : ");
        scanf("%d", &x);
        c = searchInListe(l, x);
        deleteFromListe(&l, &c);
        printListe(l);
        printf("\nVoulez-vous continuer de supprimer des valeurs ? (Y/N) ");
        scanf("%s", &prompt);
    }
    destroyListe(&l);





    printf("\n\nFin du main()\n");
    return 0;
}

