#include <stdio.h>
#include <string.h>

int input(char nim[20], char nama[50], float *nilaiTugas, float *nilaiUTS, float *nilaiUAS)
{
  printf("-------------------------------------------\n");
  printf("=-=-=-=-=-= PENILAIAN MAHASISWA =-=-=-=-=-=\n");
  printf("-------------------------------------------\n\n");

  printf("Masukkan NIM           :");
  scanf("%s", nim);
  printf("Masukkan Nama          :");
  scanf(" %[^\n]s", nama);
  printf("Masukkan Nilai Tugas   :");
  if (scanf("%f", nilaiTugas) == 0)
  {
    return 0;
  }
  if (*nilaiTugas > 100 || *nilaiTugas < 0)
  {
    return 0;
  }

  printf("Masukkan Nilai UTS     :");
  if (scanf("%f", nilaiUTS) == 0)
  {
    return 0;
  }
  if (*nilaiUTS > 100 || *nilaiUTS < 0)
  {
    return 0;
  }

  printf("Masukkan Nilai UAS     :");
  if (scanf("%f", nilaiUAS) == 0)
  {
    return 0;
  }
  if (*nilaiUAS > 100 || *nilaiUAS < 0)
  {
    return 0;
  }

  return 1;
}

void process(float *nilaiAkhir, float tugas, float uts, float uas, char *grade, char *plusAtauMinus)
{
  // Perhitungan nilai akhir
  *nilaiAkhir = (0.4 * tugas) + (0.3 * uts) + (0.3 * uas);

  // Menentukan grade
  if (*nilaiAkhir >= 90)
  {
    *grade = 'A';
  }
  else if (*nilaiAkhir >= 85 && *nilaiAkhir < 90)
  {
    *grade = 'A', *plusAtauMinus = '-';
  }
  else if (*nilaiAkhir >= 80 && *nilaiAkhir < 85)
  {
    *grade = 'B', *plusAtauMinus = '+';
  }
  else if (*nilaiAkhir >= 75 && *nilaiAkhir < 80)
  {
    *grade = 'B';
  }
  else if (*nilaiAkhir >= 70 && *nilaiAkhir < 75)
  {
    *grade = 'B', *plusAtauMinus = '-';
  }
  else if (*nilaiAkhir >= 65 && *nilaiAkhir < 70)
  {
    *grade = 'C';
  }
  else if (*nilaiAkhir >= 50 && *nilaiAkhir < 65)
  {
    *grade = 'D';
  }
  else if (*nilaiAkhir < 50)
  {
    *grade = 'E';
  }
}

void output(char nim[20], char nama[50], float nilaiAkhir, char grade, char plusAtauMinus)
{
  printf("\n=========================== \n");
  printf(">>>> Hasil Perhitungan <<< \n");
  printf("===========================\n");
  printf("NIM              :%s\n", nim);
  printf("Nama             :%s\n", nama);
  printf("Nilai Akhir      :%.2f\n", nilaiAkhir);

  if (plusAtauMinus == '+' || plusAtauMinus == '-')
  {
    printf("Grade            :%c%c\n", grade, plusAtauMinus);
  }
  else
  {
    printf("Grade            :%c\n", grade);
  }

  printf("\n---------------------------------------\n");
}

int main()
{
  // Deklarasi variabel
  char nim[20];
  char nama[50];
  float nilaiTugas, nilaiUTS, nilaiUAS, nilaiAkhir;
  char grade, plusAtauMinus;

  // Input data mahasiswa
  int respon = input(nim, nama, &nilaiTugas, &nilaiUTS, &nilaiUAS);

  // Handle Error
  if (respon == 0)
  {
    printf("%s", "\n==== Error Input ====\n");
    printf("%s", "Input nilai harus angka dan dalam range 0 - 100\n");
    return 0;
  }

  // Process data
  process(&nilaiAkhir, nilaiTugas, nilaiUTS, nilaiUAS, &grade, &plusAtauMinus);

  // Output hasil
  output(nim, nama, nilaiAkhir, grade, plusAtauMinus);

  return 0;
}