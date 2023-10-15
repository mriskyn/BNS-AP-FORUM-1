#include <stdio.h>
#include <stdlib.h>

// Define the struct for student data
struct Student
{
  int ID;
  char Nama[50];
  char Prodi[50];
  float GPA;
};

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

// Function to input student data
void inputData(struct Student *student)
{
  printf("Masukkan ID Mahasiswa: ");
  if (scanf("%d", &student->ID) != 1)
  {
    printf("Input ID tidak valid.\n");
    exit(1);
  }

  printf("Masukkan Nama Mahasiswa: ");
  scanf(" %[^\n]s", student->Nama);

  printf("Masukkan Program Studi: ");
  scanf(" %[^\n]s", student->Prodi);

  printf("Masukkan GPA: ");
  if (scanf("%f", &student->GPA) != 1)
  {
    printf("Input GPA tidak valid.\n");
    exit(1);
  }
}

int main()
{
  clearScreen();
  int totalStudents = 10; // Jumlah total mahasiswa dalam data
  int choice;
  int index = 0;

  printf("===========================================\n");
  printf("=========== Data GPA Mahasiswa ===========\n");
  printf("===========================================\n\n");

  // Array untuk menyimpan data mahasiswa
  struct Student students[totalStudents];

  do
  {
    printf("\nMenu:\n");
    printf("1. Input Data Mahasiswa\n");
    printf("2. Tampilkan Data Mahasiswa\n");
    printf("3. Keluar\n");
    printf("Pilihan: ");
    if (scanf("%d", &choice) != 1)
    {
      printf("Input pilihan tidak valid.\n");
      exit(1);
    }

    switch (choice)
    {
    case 1:
      if (totalStudents > 0)
      {
        printf("Masukkan data mahasiswa ke-%d:\n", index + 1);
        inputData(&students[index]);
        totalStudents--;
        index++;
      }
      else
      {
        printf("Kapasitas data penuh.\n");
      }
      break;
    case 2:
      // Menampilkan data mahasiswa
      printf("\nData Mahasiswa:\n");
      printf("ID\tNama\tProdi\tGPA\n");
      for (int i = 0; i < 10 - totalStudents; i++)
      {
        printf("%d\t%s\t%s\t%.2f\n", students[i].ID, students[i].Nama, students[i].Prodi, students[i].GPA);
      }
      break;
    case 3:
      exit(0);
    default:
      printf("Pilihan tidak valid. Silakan pilih lagi.\n");
    }
  } while (1);

  return 0;
}
