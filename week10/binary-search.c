#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
      return mid;
    if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1; // Return -1 if key is not found
}

int main()
{
  int data[1000]; // Assume the data is sorted
  int key = 42;   // The value you want to find
  int index = binarySearch(data, 1000, key);
  if (index != -1)
    printf("Key found at index %d\n", index);
  else
    printf("Key not found\n");
  return 0;
}
