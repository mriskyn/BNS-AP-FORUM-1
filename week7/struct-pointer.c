#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Contact
{
  char *nama;
  char *no_hp;
  char *no_kantor;
  char *email;
  char *nama_perusahaan;
  struct Contact *next;
};

struct Contact *buatKontak()
{
  struct Contact *kontak = (struct Contact *)malloc(sizeof(struct Contact));
  if (kontak == NULL)
  {
    perror("Gagal mengalokasikan memori");
    exit(1);
  }

  kontak->nama = NULL;
  kontak->no_hp = NULL;
  kontak->no_kantor = NULL;
  kontak->email = NULL;
  kontak->nama_perusahaan = NULL;
  kontak->next = NULL;

  return kontak;
}

void tampilkanKontak(struct Contact *kontak)
{
  printf("\nNama: %s\n", kontak->nama);
  printf("No. HP: %s\n", kontak->no_hp);
  printf("No. Kantor: %s\n", kontak->no_kantor);
  printf("Email: %s\n", kontak->email);
  printf("Nama Perusahaan: %s\n", kontak->nama_perusahaan);
  printf("-----------------------------\n\n");
}

void hapusKontak(struct Contact *kontak)
{
  free(kontak->nama);
  free(kontak->no_hp);
  free(kontak->no_kantor);
  free(kontak->email);
  free(kontak->nama_perusahaan);
  free(kontak);
}

int main()
{
  clearScreen();
  int menu;
  struct Contact *kontak_pertama = NULL;
  struct Contact *kontak_terakhir = NULL;

  while (1)
  {
    printf("Menu:\n");
    printf("\t1. Tambah Kontak\n");
    printf("\t2. Tampilkan Kontak\n");
    printf("\t3. Hapus Kontak\n");
    printf("\t4. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
    {
      struct Contact *kontak_baru = buatKontak();
      printf("Masukkan data kontak:\n");
      printf("Nama: ");
      char nama[100];
      scanf(" %[^\n]s", nama);
      kontak_baru->nama = strdup(nama);

      printf("No. HP: ");
      char no_hp[15];
      scanf(" %[^\n]s", no_hp);
      kontak_baru->no_hp = strdup(no_hp);

      printf("No. Kantor: ");
      char no_kantor[15];
      scanf(" %[^\n]s", no_kantor);
      kontak_baru->no_kantor = strdup(no_kantor);

      printf("Email: ");
      char email[100];
      scanf(" %[^\n]s", email);
      kontak_baru->email = strdup(email);

      printf("Nama Perusahaan: ");
      char nama_perusahaan[100];
      scanf(" %[^\n]s", nama_perusahaan);
      kontak_baru->nama_perusahaan = strdup(nama_perusahaan);

      kontak_baru->next = NULL;

      if (kontak_terakhir == NULL)
      {
        kontak_pertama = kontak_baru;
        kontak_terakhir = kontak_baru;
      }
      else
      {
        kontak_terakhir->next = kontak_baru;
        kontak_terakhir = kontak_baru;
      }

      printf("Kontak berhasil ditambahkan.\n");
      break;
    }
    case 2:
    {
      if (kontak_pertama == NULL)
      {
        printf("Kontak belum ada.\n");
      }
      else
      {
        struct Contact *current = kontak_pertama;
        while (current != NULL)
        {
          tampilkanKontak(current);
          current = current->next;
        }
      }
      break;
    }
    case 3:
    {
      if (kontak_pertama == NULL)
      {
        printf("Kontak belum ada.\n");
      }
      else
      {
        printf("Masukkan nama kontak yang ingin dihapus: ");
        char nama_hapus[100];
        scanf(" %[^\n]s", nama_hapus);

        struct Contact *current = kontak_pertama;
        struct Contact *prev = NULL;

        while (current != NULL)
        {
          if (strcmp(current->nama, nama_hapus) == 0)
          {
            if (prev == NULL)
            {
              kontak_pertama = current->next;
            }
            else
            {
              prev->next = current->next;
            }

            printf("Kontak '%s' berhasil dihapus.\n", current->nama);
            hapusKontak(current);
            break;
          }

          prev = current;
          current = current->next;
        }
      }
      break;
    }
    case 4:
    {
      struct Contact *current = kontak_pertama;
      while (current != NULL)
      {
        struct Contact *next = current->next;
        hapusKontak(current);
        current = next;
      }
      printf("Terima kasih! Keluar dari program.\n");
      exit(0);
    }
    default:
      printf("Pilihan menu tidak valid. Silakan coba lagi.\n");
      break;
    }
  }

  return 0;
}
