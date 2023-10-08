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
// Enumerasi untuk penerbit
enum Penerbit
{
  GRAMEDIA,
  ELEXMEDIA,
  ANDI_OFFSET,
  PUSTAKA,
};

// Enumerasi untuk kategori buku
enum KategoriBuku
{
  FIKSI,
  TEKS,
  SEJARAH,
  NOVEL,
};

// Struktur untuk menyimpan data buku
struct Buku
{
  char isbn[15];
  char judul[100];
  char pengarang[100];
  int tahun_terbit;
  enum Penerbit penerbit;
  enum KategoriBuku kategori;
};

// Fungsi untuk menampilkan data buku
void tampilkanBuku(const struct Buku *buku)
{
  printf("ISBN: %s\n", buku->isbn);
  printf("Judul: %s\n", buku->judul);
  printf("Pengarang: %s\n", buku->pengarang);
  printf("Tahun Terbit: %d\n", buku->tahun_terbit);
  printf("Penerbit: %d\n", buku->penerbit);
  printf("Kategori: %d\n", buku->kategori);
  printf("-----------------------------\n");
}

int main()
{
  clearScreen();
  int menu;
  struct Buku perpustakaan[100]; // Batasi jumlah buku yang dapat disimpan

  int jumlah_buku = 0;

  while (1)
  {
    printf("Menu:\n");
    printf("\t1. Tambah Buku\n");
    printf("\t2. Tampilkan Buku\n");
    printf("\t3. Hapus Buku\n");
    printf("\t4. Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
    {
      if (jumlah_buku < 100)
      {
        struct Buku buku_baru;
        printf("\nMasukkan data buku:\n");
        printf("ISBN: ");
        scanf("%s", buku_baru.isbn);

        printf("Judul: ");
        scanf(" %[^\n]s", buku_baru.judul);

        printf("Pengarang: ");
        scanf(" %[^\n]s", buku_baru.pengarang);

        printf("Tahun Terbit: ");
        scanf("%d", &buku_baru.tahun_terbit);

        printf("Penerbit (0: Gramedia, 1: Elexmedia, 2: Andi Offset, 3: Pustaka): ");
        scanf("%d", &buku_baru.penerbit);

        printf("Kategori (0: Fiksi, 1: Teks, 2: Sejarah, 3: Novel): ");
        scanf("%d", &buku_baru.kategori);

        perpustakaan[jumlah_buku] = buku_baru;
        jumlah_buku++;

        printf("\nBuku berhasil ditambahkan.\n\n");
      }
      else
      {
        printf("\nPerpustakaan penuh. Hapus buku terlebih dahulu.\n");
      }
      break;
    }
    case 2:
    {
      if (jumlah_buku == 0)
      {
        printf("\nPerpustakaan kosong.\n");
      }
      else
      {
        printf("\n");
        for (int i = 0; i < jumlah_buku; i++)
        {
          printf("Data Buku %d:\n", i + 1);
          tampilkanBuku(&perpustakaan[i]);
        }
      }
      break;
    }
    case 3:
    {
      if (jumlah_buku == 0)
      {
        printf("\nPerpustakaan kosong.\n");
      }
      else
      {
        printf("\nMasukkan ISBN buku yang ingin dihapus: ");
        char isbn_hapus[15];
        scanf("%s", isbn_hapus);

        int index_hapus = -1;
        for (int i = 0; i < jumlah_buku; i++)
        {
          if (strcmp(perpustakaan[i].isbn, isbn_hapus) == 0)
          {
            index_hapus = i;
            break;
          }
        }

        if (index_hapus != -1)
        {
          for (int i = index_hapus; i < jumlah_buku - 1; i++)
          {
            perpustakaan[i] = perpustakaan[i + 1];
          }
          jumlah_buku--;
          printf("\nBuku berhasil dihapus.\n");
        }
        else
        {
          printf("\nBuku dengan ISBN tersebut tidak ditemukan.\n");
        }
      }
      break;
    }
    case 4:
    {
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
