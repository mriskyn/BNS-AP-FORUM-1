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

// Fungsi pass-by-value
void swapByValue(int num1, int num2)
{
  // x++; // Menambah nilai salinan x
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

// Fungsi pass-by-address
void swapByAddress(int *num1, int *num2)
{
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int main()
{
  clearscr();
  int num1 = 55;
  int num2 = 77;
  printf("PASS BY VALUE\n");
  printf("Nilai num1 sebelum pemanggilan fungsi: %d\n", num1);
  printf("Nilai num2 sebelum pemanggilan fungsi: %d\n\n", num2);

  swapByValue(&num1, &num2); // Memanggil fungsi pass-by-value

  printf("Nilai num1 setelah pemanggilan fungsi: %d\n", num1);
  printf("Nilai num2 setelah pemanggilan fungsi: %d\n", num2);

  printf("\n\nPASS BY REFERENCE\n");
  printf("Nilai num1 sebelum pemanggilan fungsi: %d\n", num1);
  printf("Nilai num2 sebelum pemanggilan fungsi: %d\n\n", num2);

  swapByAddress(&num1, &num2); // Memanggil fungsi pass-by-address dengan menyertakan alamat num

  printf("Nilai num1 setelah pemanggilan fungsi: %d\n", num1);
  printf("Nilai num2 setelah pemanggilan fungsi: %d\n", num2);

  return 0;
}
