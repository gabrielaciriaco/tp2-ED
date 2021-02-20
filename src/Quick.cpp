#include "../include/Quick.h"

void trocaPosicaoItens(Base vetorBases[], int *indiceBase1, int *indiceBase2) {
  Base baseAuxiliar;
  baseAuxiliar = vetorBases[*indiceBase1];
  vetorBases[*indiceBase1] = vetorBases[*indiceBase2];
  vetorBases[*indiceBase2] = baseAuxiliar;
  (*indiceBase1)++;
  (*indiceBase2)--;
}

void partirVetor(Base vetorBases[], int esquerda, int direita, int *i, int *j) {
  Base baseAuxiliar1, baseAuxiliar2;
  *i = esquerda;
  *j = direita;
  baseAuxiliar1 = vetorBases[(*i + *j) / 2];
  do {
    while (baseAuxiliar1 < vetorBases[*i]) (*i)++;
    while (baseAuxiliar1 > vetorBases[*j]) (*j)--;

    if (*i <= *j) {
      trocaPosicaoItens(vetorBases,i,j);
    }

  } while (*i <= *j);
}

void quickSort(Base vetorBases[], int esquerda, int direita) {
  int i, j;
  partirVetor(vetorBases, esquerda, direita, &i, &j);
  if (esquerda < j) quickSort(vetorBases, esquerda, j);
  if (i < direita) quickSort(vetorBases, i, direita);
}
