#include "../include/Insertion.h"

void insertionSort(Base *vetorBase, int tamanhoArray) {
  Base aux;
  for (int i = 1; i < tamanhoArray; i++) {
    aux = vetorBase[i];
    int j = i - 1;
    while ((j >= 0) && (aux > vetorBase[j])) {
      vetorBase[j + 1] = vetorBase[j];
      j--;
    }
    vetorBase[j + 1] = aux;
  }
}