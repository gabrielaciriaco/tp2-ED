#include "../include/Base.h"

Base::Base(){
  
}
string Base::getNome(){
  return this->nome;
}

int Base::getDistancia(){
  return this->distancia;
}

void Base::setNome(string nome){
  this->nome =  nome;
}

void Base::setDistancia(int distancia){
  this->distancia = distancia;
}

bool operator < (const Base& base1, const Base& base2) {
  return base1.distancia < base2.distancia;
}

bool operator > (const Base& base1, const Base& base2) {
  return base1.distancia > base2.distancia;
}
