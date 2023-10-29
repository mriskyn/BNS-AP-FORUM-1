#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
      return i;
  }
  return -1; // Return -1 if key is not found
}

int main()
{
  int data[1000]; // Assume the data is unsorted
  int key = 42;   // The value you want to find
  int index = linearSearch(data, 1000, key);
  if (index != -1)
    printf("Key found at index %d\n", index);
  else
    printf("Key not found\n");
  return 0;
}


