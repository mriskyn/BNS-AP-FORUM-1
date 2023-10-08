#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

int main()
{
  clearScreen();

  // Deklarasi Variabel
  float total_pembelian;
  int kupon_undian = 0;
  float diskon = 0;
  int menu;

  printf("==============================\n");
  printf("SELAMAT DATANG DI SUPERMARKET!\n");
  printf("==============================\n");

  while (1)
  {
    printf("\nMenu:\n");
    printf("\t1. Masukkan total pembelian (Rp)\n");
    printf("\t2. Keluar\n\n");
    printf("Pilih menu: ");
    scanf("%d", &menu);

    if (menu == 1)
    {
      printf("\nMasukkan total pembelian Anda (Rp): ");
      scanf("%f", &total_pembelian);

      if (total_pembelian < 0) // Jika input angka minus
      {
        printf("Total pembelian tidak valid. Harap masukkan angka positif.\n");
        continue;
      }

      if (total_pembelian < 100000) // Jika pembelian dibawah 100000
      {
        printf("Maaf, total pembelian Anda tidak memenuhi syarat untuk mendapatkan kupon undian atau diskon.\n");
      }
      else
      {
        // Menghitung jumlah kupon undian
        kupon_undian = total_pembelian / 100000;

        // Menghitung diskon jika total pembelian memenuhi syarat
        if (kupon_undian >= 1)
        {
          diskon = total_pembelian * 0.1;
          printf("Anda mendapatkan %d kupon undian.\n", kupon_undian);
          printf("Anda juga mendapatkan diskon Rp %.2f.\n", diskon);
        }

        float total_pembayaran = total_pembelian - diskon;
        printf("Total pembayaran setelah diskon adalah Rp %.2f.\n", total_pembayaran);
      }
    }
    else if (menu == 2)
    {
      printf("\n================================================\n");
      printf("Terima kasih telah berbelanja di supermarket kami!\n");
      printf("\n================================================\n");
      break;
    }
    else
    {
      printf("Menu tidak valid. Pilih 1 untuk memasukkan total pembelian atau 2 untuk keluar.\n");
    }
  }

  return 0;
}
