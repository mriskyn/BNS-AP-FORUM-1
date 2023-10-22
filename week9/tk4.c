#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Membersihkan layar saat run program
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

// Maksimum jumlah buku yang dapat disimpan
#define MAX_BOOKS 100

// Struktur untuk merepresentasikan data buku
struct Book
{
  char code[10];
  char name[50];
  char type[20];
  double price;
};

// Deklarasi variabel global
struct Book books[MAX_BOOKS];
int numBooks = 0;
char history[1000][100];

// Fungsi untuk menyimpan data buku ke dalam array
void inputBook()
{
  if (numBooks < MAX_BOOKS)
  {
    struct Book newBook;
    printf("Enter book's code: ");
    scanf("%s", newBook.code);
    printf("Enter book's name: ");
    scanf(" %s", newBook.name); // Menghindari masalah pembacaan karakter
    printf("Enter book's type: ");
    scanf(" %s", newBook.type);
    printf("Enter book's price: ");
    scanf("%lf", &newBook.price);

    books[numBooks] = newBook;
    numBooks++;
    printf("\nData sucessfully created..\n");
  }
  else
  {
    printf("\nThe book data capacity has reached the maximum limit.\n");
  }
}

// Fungsi untuk melihat riwayat penjualan
void viewHistory()
{
  printf("\n======== Transaction History ========\n");
  for (int i = 0; i < numBooks; i++)
  {
    printf("%s %s %s %.2lf\n", history[i]);
  }
  printf("======== -------------------- ========\n");
}

// Fungsi untuk melihat data buku
void viewBooks()
{
  printf("\n======== Books data ========\n");
  for (int i = 0; i < numBooks; i++)
  {
    printf("%d. %s %s %s %.2lf\n", i + 1, books[i].code, books[i].name, books[i].type, books[i].price);
  }
  printf("======== ---------- ========\n");
}

// Fungsi untuk menghapus riwayat penjualan
void deleteHistory()
{
  viewHistory();
  int index;
  printf("Enter the index of the history you want to (1-%d): ", numBooks);
  scanf("%d", &index);
  if (index >= 1 && index <= numBooks)
  {
    for (int i = index - 1; i < numBooks - 1; i++)
    {
      strcpy(history[i], history[i + 1]);
    }
    numBooks--;
    printf("Data Successfully delete..\n");
  }
  else
  {
    printf("\nInvalid index.\n");
  }
}

// Fungsi untuk menghapus data buku
void deleteBook()
{
  viewBooks();
  int index;
  printf("Enter the index of the book you want to delete (1-%d): ", numBooks);
  scanf("%d", &index);
  if (index >= 1 && index <= numBooks)
  {
    for (int i = index - 1; i < numBooks - 1; i++)
    {
      books[i] = books[i + 1];
    }
    numBooks--;
    printf("Data Successfully delete..\n");
  }
  else
  {
    printf("\nInvalid index.\n");
  }
}

int main()
{
  clearScreen();
  // Membaca data buku dari file "databuku.txt" saat program pertama kali dijalankan
  FILE *file = fopen("databuku.txt", "r");
  if (file != NULL)
  {
    while (fscanf(file, "%s %s %s %lf", books[numBooks].code, books[numBooks].name, books[numBooks].type, &books[numBooks].price) != EOF)
    {
      numBooks++;
    }
    fclose(file);
  }

  int choice;
  do
  {
    printf("\nMenu:\n");
    printf("\t1. Input data\n");
    printf("\t2. View History\n");
    printf("\t3. View Data\n");
    printf("\t4. Delete History\n");
    printf("\t5. Delete Buku\n");
    printf("\t6. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      inputBook();
      break;
    case 2:
      viewHistory();
      break;
    case 3:
      viewBooks();
      break;
    case 4:
      deleteHistory();
      break;
    case 5:
      deleteBook();
      break;
    case 6:
      // Menulis data buku ke file "databuku.txt" sebelum keluar
      file = fopen("databuku.txt", "w");
      for (int i = 0; i < numBooks; i++)
      {
        fprintf(file, "%s %s %s %.2lf\n", books[i].code, books[i].name, books[i].type, books[i].price);
      }
      fclose(file);
      printf("\n==================================\n");
      printf("Thank you for using this program.\n");
      printf("==================================\n\n");
      break;
    default:
      printf("\nInvalid choice. Please Try Again.\n");
      break;
    }
  } while (choice != 6);

  return 0;
}
