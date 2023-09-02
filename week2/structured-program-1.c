#include <stdio.h>

int main() {
    int x = 5;

    // Statement if
    if (x > 0) {
        printf("Nilai x adalah positif\n");
    } else if (x < 0) {
        printf("Nilai x adalah negatif\n");
    } else {
        printf("Nilai x adalah nol\n");
    }

    // Statement while
    int i = 1;
    while (i <= 5) {
        printf("Perulangan ke-%d\n", i);
        i++;
    }

    // Statement for
    for (int j = 0; j < 3; j++) {
        printf("Iterasi ke-%d\n", j);
    }

    return 0;
}
