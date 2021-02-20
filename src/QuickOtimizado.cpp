#include "../include/QuickOtimizado.h"

namespace QuickOtimizado {
void trocaPosicaoItens(Base vetorBases[], int *indiceBase1, int *indiceBase2) {
  Base baseAuxiliar;
  baseAuxiliar = vetorBases[*indiceBase1];
  vetorBases[*indiceBase1] = vetorBases[*indiceBase2];
  vetorBases[*indiceBase2] = baseAuxiliar;
  (*indiceBase1)++;
  (*indiceBase2)--;
}
int selecionarPivo(Base vetorBases[], int esquerda, int direita) {
  int meio = (esquerda + direita) / 2;
  if ((esquerda > direita) xor (esquerda > meio)) {
    return esquerda;
  } else if ((direita > esquerda) xor (direita > meio)) {
    return direita;
  }
  return meio;
}
void partirVetor(Base vetorBases[], int esquerda, int direita, int *i, int *j) {
  Base baseAuxiliar1, baseAuxiliar2;
  *i = esquerda;
  *j = direita;
  int pivo = selecionarPivo(vetorBases, esquerda, direita);
  baseAuxiliar1 = vetorBases[pivo];
  do {
    while (baseAuxiliar1 < vetorBases[*i]) (*i)++;
    while (baseAuxiliar1 > vetorBases[*j]) (*j)--;

    if (*i <= *j) {
      trocaPosicaoItens(vetorBases, i, j);
    }

  } while (*i <= *j);
}
}  // namespace QuickOtimizado

void quickSortOtimizado(Base vetorBases[], int esquerda, int direita) {
  int i, j;
  QuickOtimizado::partirVetor(vetorBases, esquerda, direita, &i, &j);
  if (esquerda < j) quickSortOtimizado(vetorBases, esquerda, j);
  if (i < direita) quickSortOtimizado(vetorBases, i, direita);
}
