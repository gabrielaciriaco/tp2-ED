#include <iostream>
#include "Base.h"
#include "Heap.h"
#include "Quick.h"
#include "Insertion.h"
#include "QuickOtimizado.h"
#include "Shell.h"

using namespace std; 

Base *lerArquivo(char *nomeArquivo, int quantidadeDeLinhas) {
  Base *dadosBase = new Base[quantidadeDeLinhas];
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Arquivo no encontrado, verifique se o arquivo esta na pasta");
    exit(1);
  }
  char aux;
  for (int i = 0; i < quantidadeDeLinhas; i++) {
    aux = fgetc(arquivo);
    string trechoDadosBase = "";
    int distancia;
    while (aux != ' ') {
      trechoDadosBase += aux;
      aux = fgetc(arquivo);
    }
    fscanf(arquivo, "%d", &distancia);
    fscanf(arquivo, "%*[\n]");
    dadosBase[i].setNome(trechoDadosBase);
    dadosBase[i].setDistancia(distancia);
  }
  return dadosBase;
}
void imprimeSaida(Base *vetorBase){
  for(int i=0;i<7;i++){
    cout<<vetorBase[i].getNome()<<" "<<vetorBase[i].getDistancia()<<endl;
  }
}
int main(int argc, char *argv[]) {
  int quantidadeDeLinhas = stoi(argv[2]);
  char *nomeArquivo = argv[1];
  Base *bases = lerArquivo(nomeArquivo, quantidadeDeLinhas);
  shellSort(bases,quantidadeDeLinhas);
  imprimeSaida(bases);
  return 0;
}