#include <stdio.h>

int main() {
    int a = 10, max = 100;

    for (int x1 = 1; x1 <= max; x1++) {
        for (int x2 = 1; x2 <= max; x2++) {
            for (int x3 = 1; x3 <= max; x3++) {
                for (int x4 = 1; x4 <= max; x4++) {
                    a -= 4;
                    a += x1;
                    a *= x2;
                    a /= x3;
                    a %= x4;

                    if (a == 10) {
                        printf("Nilai a dapat diatur menjadi 10 dengan x1=%d, x2=%d, x3=%d, dan x4=%d\n", x1, x2, x3, x4);
                        return 0; // Keluar dari program setelah menemukan kombinasi yang tepat
                    }

                    // Kembalikan nilai awal a untuk iterasi / loop berikutnya
                    a = 10;
                }
            }
        }
    }

    printf("Tidak ada kombinasi yang dapat membuat nilai a tetap 10.\n");

    return 0;
}
