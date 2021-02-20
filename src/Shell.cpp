#include "../include/Shell.h"

void shellSort(Base *vetorBase, int tamanhoArray) {
  for (int distanciaElementos = tamanhoArray / 2; distanciaElementos > 0; distanciaElementos /= 2) {
    for (int i = distanciaElementos; i < tamanhoArray; i += 1) {
      Base aux = vetorBase[i];

      int j;
      for (j = i; j >= distanciaElementos && vetorBase[j - distanciaElementos] < aux; j -= distanciaElementos) {
        vetorBase[j] = vetorBase[j - distanciaElementos];
      }
      vetorBase[j] = aux;
    }
  }
}