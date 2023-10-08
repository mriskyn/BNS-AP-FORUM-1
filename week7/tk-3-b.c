#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fungsi untuk membersihkan layar konsol
void clearScreen()
{
#ifdef _WIN32
  system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
  system("clear");
#else
#error "OS not supported."
#endif
}

// Struktur untuk data pegawai
struct Pegawai
{
  char nip[10];
  char nama[50];
  char alamat[100];
  char no_hp[15];
  char jabatan[50];
  char golongan[2];
  int gaji_pokok;
};

// Fungsi untuk menghitung gaji lemburan
int hitungGajiLemburan(char golongan[2], int jumlahJamLembur)
{
  int gajiLemburan = 0;

  // Menghitung Gaji Lemburan berdasarkan golongan
  if (strcmp(golongan, "D1") == 0)
  {
    gajiLemburan = jumlahJamLembur * 10000;
  }
  else if (strcmp(golongan, "D2") == 0)
  {
    gajiLemburan = jumlahJamLembur * 5000;
  }
  else if (strcmp(golongan, "D3") == 0)
  {
    gajiLemburan = jumlahJamLembur * 2500;
  }
  else
  {
    printf("\nGolongan tidak valid.\n");
    return 1;
  }
  return gajiLemburan;
}

int main()
{
  clearScreen();
  struct Pegawai pegawai;

  printf("===================================\n");
  printf("---- PROGRAM GAJI DATA PEGAWAI ----\n");
  printf("===================================\n\n");

  while (1)
  {
    int pilihan;
    printf("Menu:\n");
    printf("\t1. Input Data Pegawai\n");
    printf("\t2. Input Data Lemburan\n");
    printf("\t3. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &pilihan);

    if (pilihan == 1)
    {
      // Input data pegawai
      printf("\nInput Data Pegawai:\n");
      printf("NIP: ");
      scanf("%s", pegawai.nip);
      printf("Nama: ");
      scanf("%s", pegawai.nama);
      printf("Alamat: ");
      scanf("%s", pegawai.alamat);
      printf("No HP: ");
      scanf("%s", pegawai.no_hp);
      printf("Jabatan: ");
      scanf("%s", pegawai.jabatan);
      printf("Golongan (D1/D2/D3): ");
      scanf("%s", pegawai.golongan);

      // Mengatur gaji pokok berdasarkan golongan
      if (strcmp(pegawai.golongan, "D1") == 0)
      {
        pegawai.gaji_pokok = 2500000;
      }
      else if (strcmp(pegawai.golongan, "D2") == 0)
      {
        pegawai.gaji_pokok = 2000000;
      }
      else if (strcmp(pegawai.golongan, "D3") == 0)
      {
        pegawai.gaji_pokok = 1500000;
      }
      else
      {
        printf("Golongan tidak valid.\n");
        return 1;
      }

      printf("Data Pegawai telah diinput.\n");
    }
    else if (pilihan == 2)
    {
      // Input data lemburan
      int jumlahJamLembur;
      printf("\nInput Data Lemburan:\n");
      printf("NIP: ");
      scanf("%s", pegawai.nip);
      printf("Golongan (D1/D2/D3): ");
      scanf("%s", pegawai.golongan);
      printf("Jumlah Jam Lembur: ");
      scanf("%d", &jumlahJamLembur);

      // Menghitung gaji lemburan
      int gajiLemburan = hitungGajiLemburan(pegawai.golongan, jumlahJamLembur);

      // Menghitung total gaji bulan ini
      int totalGaji = pegawai.gaji_pokok + gajiLemburan;

      printf("\nTampilan Input 2:\n");
      printf("NIP = %s\n", pegawai.nip);
      printf("Golongan = %s\n", pegawai.golongan);
      printf("Lembur = %d jam\n", jumlahJamLembur);
      printf("Total Gaji Bulan ini = Rp %d\n\n", totalGaji);
    }
    else if (pilihan == 3)
    {
      // Keluar dari program
      printf("\n====================================================\n");
      printf("---- TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI ----\n");
      printf("==================================================\n\n");
      break;
    }
    else
    {
      printf("Pilihan menu tidak valid. Silakan coba lagi.\n");
    }
  }

  return 0;
}
