#include <stdio.h>

int main() {
    int i, j;

    printf("Tabel Perkalian 1-10:\n\n");
    printf("     ");
    for (i = 1; i <= 10; i++) {
        printf("%4d", i);
    }
    printf("\n");

    printf("   --------------------------------------------\n");

    i = 1;
loop:
    printf("%2d |", i);
    j = 1;

inner_loop:
    printf("%4d", i * j);
    j++;
    if (j <= 10) {
        goto inner_loop;
    }

    printf("\n");
    i++;
    if (i <= 10) {
        goto loop;
    }

    return 0;
}
