#include <stdio.h>
#include <string.h>

void reset() {
  printf("\033[0m");
}

void red(char string[]) {
  printf("\033[0;31m");
  printf("%s",string);
  reset();
}

void green(char string[]) {
  printf("\033[0;32m");
  printf("%s",string);
  reset();
}

void yellow(char string[]) {
  printf("\033[0;33m");
  printf("%s",string);
  reset();
}

void blue(char string[]) {
  printf("\033[0;34m");
  printf("%s",string);
  reset();
}

void purple(char string[]) {
  printf("\033[0;35m");
  printf("%s",string);
  reset();
}

void cyan(char string[]) {
  printf("\033[0;36m");
  printf("%s",string);
  reset();
}



void inputJenisBensin() {
  printf("Masukkan jenis bensin ("), blue("Pertamax"), printf("/"), green("Pertalite"), printf("): ");
}

void inputBensinAwal() {
  printf("Masukkan jumlah bensin awal ("), purple("liter"), printf("): ");
}

void inputJarak() {
  printf("Masukkan jarak yang ditempuh ("), cyan("km"), printf("): ");
}

void inputModeMenyopir() {
  // printf("Masukkan mode menyopir (konstan / luarkota atau stop&go / dalamkota): ");
  printf("Masukkan mode menyopir ("), red("konstan / luarkota"), printf(" atau "), yellow("stop&go / dalamkota"), printf("): ");
}

void output(float bensinAwal, float bensinAkhir) {
  printf("Jumlah ("), purple("liter"), printf(") pengurangan bensin: %.2f liter\n", bensinAwal - bensinAkhir); 
  printf("Jumlah ("), purple("liter"), printf(") bensin akhir: %.2f liter\n", bensinAkhir);
  // menggunakan %.2f untuk output float data angka desimal dengan 2 angka setelah koma
}

int main() {
    // Deklarasi variabel
    char jenisBensin[20];
    float keiritan;
    float bensinAwal, bensinAkhir;
    float jarak;
    char modeMenyopir[20];

    // Input jenis bensin dan hitung keiritan
    inputJenisBensin();
    scanf("%s", jenisBensin);

    if (strcmp(jenisBensin, "Pertamax") == 0) {
        keiritan = 15.0;
    } else if (strcmp(jenisBensin, "Pertalite") == 0) {
        keiritan = 12.0;
    } else {
        printf("Jenis bensin tidak valid.\n");
        return 1;
    }

    // Input bensinAwal
    inputBensinAwal();
    scanf("%f", &bensinAwal);

    // Input jarak
    inputJarak();
    scanf("%f", &jarak);

    // Input modeMenyopir
    inputModeMenyopir();
    scanf("%s", modeMenyopir);

    // Menghitung jumlah bensin yang terpakai
    if (strcmp(modeMenyopir, "konstan") == 0 || strcmp(modeMenyopir, "luarkota") == 0) {
        bensinAkhir = bensinAwal - (jarak / keiritan);
    } else if (strcmp(modeMenyopir, "stop&go") == 0 || strcmp(modeMenyopir, "dalamkota") == 0) {
        if (keiritan == 15.0) {
            keiritan = 10.0; // Keiritan untuk Pertamax dalam mode stop&go dan dalamkota
        }
        if (keiritan == 12.0) {
            keiritan = 8.0; // Keiritan untuk jenis Pertalite dalam mode stop&go dan dalamkota
        }
        bensinAkhir = bensinAwal - (jarak / keiritan); // jarak / keiritan == km / liter
    } else {
        printf("Mode menyopir tidak valid.\n");
        return 1;
    }

    // Output hasil simulasi
    if (bensinAkhir < 0) {
        printf("Anda kehabisan bensin sebelum mencapai tujuan.\n");
    } else {
        output(bensinAwal, bensinAkhir);
    }

    return 0;
}
