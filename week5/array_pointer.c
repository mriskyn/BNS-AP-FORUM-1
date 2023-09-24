#include <stdio.h>
#include <string.h>

int main()
{
  char nama1[20];  // Deklarasi array character
  char *nama2;     // Deklarasi pointer character
  char *nama3[20]; // Deklarasi array of 20 pointer character

  // Mengisikan data string ke nama1
  strcpy(nama1, "Brisia Jodie");

  // Mengisikan alamat data literal string ke nama2
  nama2 = "Brisia Jodie";

  // Mengisikan alamat data literal string ke nama3[0]
  nama3[0] = "Brisia Jodie";
  printf("%s\n%s\n%s", nama1, nama2, nama3[0]);
  return 0;

  /**
   * Penting untuk diingat bahwa dalam kasus nama2 dan nama3, program tersebut mengisikan alamat memori dari string literal ke pointer tersebut. Dalam kasus nama1, program tersebut menyalin string literal ke dalam array karakter.
  */
}