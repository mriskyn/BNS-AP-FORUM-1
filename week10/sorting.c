#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][20], int n) {
    int swapped;
    char temp[20];
    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(arr[i], arr[i + 1]) > 0) {
                // Swap the strings
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i + 1]);
                strcpy(arr[i + 1], temp);
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    char nama[10][20] = {
        "Fahmi Harahap",
        "Icha Nurlisa",
        "Agus Gumilang",
        "Zelda Zuraida",
        "Felix Halim",
        "Deddy Corbuizer",
        "Hassan Makmur",
        "Makmun Sukur",
        "Bella Christie",
        "Chelshe Love"
    };
    int n = 10;

    printf("Data sebelum pengurutan:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    bubbleSort(nama, n);

    printf("\nData setelah pengurutan:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    return 0;
}
