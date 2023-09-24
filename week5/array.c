#include <stdio.h>
#include <stdlib.h>

void clearscr(void)
{
#ifdef _WIN32
  system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
  system("clear");
#else
#error "OS not supported."
#endif
}

int main()
{
  clearscr(); // Clear Screen
  printf("+++++++++++++++----------------++++++++++++++\n");
  printf("==========  LIST DATA MATA KULIAH  ==========\n");
  printf("+++++++++++++++----------------++++++++++++++\n\n");
  // Deklarasi variabel array 3 mata kuliah
  char mataKuliah[3][50] = {"Pemrograman", "Database", "Compiler"};
  // Deklarasi variabel array 3 bobot sks
  int sks[3] = {4, 6, 4};
  // Deklarasi variabel array 3 jenis grade
  char grade[3] = {'B', 'A', 'C'};

  // Output table dari list mata kuliah, sks, dan grade
  printf("┌───────────────┬───────────────┬────────────┐\n");
  printf("│Mata Kuliah\t│      SKS\t│     GRADE  │\n");
  printf("├───────────────┼───────────────┼────────────┤\n");
  for (int i = 0; i < 3; i++)
  {
    printf("│%s\t│\t%d\t│\t%c    │\n", mataKuliah[i], sks[i], grade[i]);
  }
  printf("└───────────────┴───────────────┴────────────┘\n\n");

  return 0;
}