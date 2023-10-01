#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Fungsi iteratif untuk menghitung bilangan Fibonacci ke-n
unsigned long long fibonacciIterative(int n)
{
  unsigned long long a = 0, b = 1, temp;
  if (n == 0)
    return a;
  for (int i = 2; i <= n; i++)
  {
    temp = a + b;
    a = b;
    b = temp;
  }
  return b;
}

// Fungsi rekursif untuk menghitung bilangan Fibonacci ke-n
unsigned long long fibonacciRecursive(int n)
{
  if (n <= 1)
    return n;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main()
{
  clearScreen();
  int n;
  printf("Masukkan nilai n: ");
  scanf("%d", &n);

  // Menggunakan fungsi iteratif (variabel tic & toc untuk menghitung waktu program berjalan)
  clock_t tic = clock();
  unsigned long long resultIterative = fibonacciIterative(n);
  clock_t toc = clock();

  printf("\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  printf("Hasil Fibonacci ke-%d (iteratif): %llu\n\n", n, resultIterative);

  // Menggunakan fungsi rekursif (variabel tic & toc untuk menghitung waktu program berjalan)
  clock_t tic2 = clock();
  unsigned long long resultRecursive = fibonacciRecursive(n);
  clock_t toc2 = clock();

  printf("Elapsed: %f seconds\n", (double)(toc2 - tic2) / CLOCKS_PER_SEC);
  printf("Hasil Fibonacci ke-%d (rekursif): %llu\n", n, resultRecursive);

  return 0;
}
