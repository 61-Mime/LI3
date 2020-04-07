/**
 * @file  sort.c
 * @brief Ficheiro que contém funções relativas a ordenação e procura
 */


#include "sort.h"
#include <string.h>

/**
 * @brief   Função troca duas Strings de apontadores
 * @param a Apontador para String
 * @param b Apontador para String
 */
void swap(char** a, char** b)
{
    void* aux = *a;
    *a = *b;
    *b = aux;
}

/**
 * @brief       Função de ordenação pelo algoritmo Quicksort
 * @param arr   Array de Strings a ordenar
 * @param low   Inteiro com o incio do array 
 * @param high  Interio com o fim do array
 */
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

/**
 * @brief       Função de Procura Binária
 * @param arr   Array de Strings onde procurar
 * @param code  String a procurar
 * @param left  Inteiro com o inicio do array
 * @param right Inteiro com o fim do array
 * @return      Inteiro com a posição da String no array
 */
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
