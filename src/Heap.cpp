#include "../include/Heap.h"

void trocaPosicaoItens (Base bases[], int indiceBase1, int indiceBase2 ){
    Base baseTrocada;

    baseTrocada = bases[indiceBase1];
    bases[indiceBase1] = bases[indiceBase2];
    bases[indiceBase2] = baseTrocada;
}
void montaHeap(Base bases[], int tamanhoDaHeap, int posicaoAtual) {
  int indiceMenorItem = posicaoAtual;
  int indiceEsquerda = 2 * posicaoAtual + 1;
  int indiceDireita = 2 * posicaoAtual + 2;

  if (indiceEsquerda < tamanhoDaHeap && bases[indiceEsquerda] < bases[indiceMenorItem]){
    indiceMenorItem = indiceEsquerda;
  } 

  if (indiceDireita < tamanhoDaHeap && bases[indiceDireita] < bases[indiceMenorItem]){
    indiceMenorItem = indiceDireita;
  } 

  if (indiceMenorItem != posicaoAtual) {
    trocaPosicaoItens(bases,indiceMenorItem,posicaoAtual);
    montaHeap(bases, tamanhoDaHeap, indiceMenorItem);
  }
}

void heapSort(Base bases[], int tamanhoArray) {
  int posicaoDoMeio = tamanhoArray / 2 - 1;

  for (int i = posicaoDoMeio; i >= 0; i--) {
    montaHeap(bases, tamanhoArray, i);
  }

  Base baseTrocada;

  for (int i = tamanhoArray - 1; i >= 0; i--) {
    trocaPosicaoItens(bases,i,0);
    montaHeap(bases, i, 0);
  }
}
