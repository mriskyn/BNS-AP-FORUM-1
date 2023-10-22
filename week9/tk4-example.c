#include <stdio.h>

void streamExample()
{
  char input[100];
  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin); // Membaca input dari stdin
  printf("You entered: %s", input);
}

void fileExample()
{
  FILE *file;
  file = fopen("data.txt", "w"); // Membuka file "data.txt" dalam mode penulisan
  if (file != NULL)
  {
    fprintf(file, "Hello, World!\n"); // Menulis teks ke file
    fclose(file);                     // Menutup file
  }
  else
  {
    printf("File cannot be opened...\n");
  }
}

int main()
{
  fileExample();
  streamExample();

  return 0;
}
