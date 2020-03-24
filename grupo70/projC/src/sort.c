#include "sort.h"
#include <string.h>

// Troca duas posições de um array
void swap(char** a, char** b)
{
    void* aux = *a;
    *a = *b;
    *b = aux;
}

void swapS(SALE* a, SALE* b)
{
    void* aux = *a;
    *a = *b;
    *b = aux;
}

// Algoritmo de ordenação quicksort para os arrays de produtos e clientes
void quickSort(char** arr, int low, int high)
{
    if (low < high)
    {
      char* pivot = arr[high];
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (strcmp(arr[j], pivot) < 0)
          {
              i++;
              swap(&arr[i], &arr[j]);
          }
      }
      swap(&arr[i + 1], &arr[high]);

      int pi = i + 1;

      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
    }
}

// Algoritmo de ordenação quicksort para os arrays de produtos e clientes
void quickSortSALE(SALE* s, int low, int high)
{
    if (low < high)
    {
      char* pivot = s[high].p;
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (strcmp(s[j].p, pivot) < 0)
          {
              i++;
              swapS(&s[i], &s[j]);
          }
      }
      swapS(&s[i + 1], &s[high]);

      int pi = i + 1;

      quickSortSALE(s, low, pi - 1);
      quickSortSALE(s, pi + 1, high);
    }
}

// Procura binária para um produto ou cliente
int binarySearch(char** arr, char* code, int left, int right)
{
  int mid, res=(-1);

  while (left<=right && res==(-1))
  {
    mid = left + (right-left)/2;

    if (strcmp(arr[mid], code) == 0)
        res = mid;

    if (strcmp(arr[mid], code) < 0)
        left = mid + 1;

    else right = mid - 1;
  }

  return res;
}
