#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 200

// Fungsi untuk membaca dan menampilkan data dari file
void readAndDisplayData()
{
  char line[MAX_LINE];
  FILE *file = fopen("data.txt", "r");

  if (!file)
  {
    printf("Error saat membuka file: %s\n", strerror(errno));
    return;
  }

  printf("\nData dalam file:\n");
  printf("==========================================================\n");

  while (fgets(line, sizeof(line), file))
  {
    printf("%s", line);
  }

  printf("\n==========================================================\n");

  fclose(file);
}

int main()
{
  int choice;

  while (1)
  {
    // Menampilkan Piliha Menu
    printf("\nMenu:\n");
    printf("1. Baca dan Tampilkan Data\n");
    printf("2. Keluar\n");
    printf("Pilih menu (1/2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
      readAndDisplayData();
    }
    else if (choice == 2) // Menutup program
    {
      printf("\nTerima kasih. Program selesai.\n");
      break;
    }
    else // Pilihan menu tidak sesuai
    {
      printf("\nPilihan tidak valid. Silakan pilih 1 atau 2.\n");
    }
  }

  return 0;
}
