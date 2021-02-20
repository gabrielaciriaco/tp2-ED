#ifndef I_Base_H
#define I_Base_H
#include <string>

using namespace std;
class Base{
  private:
    string nome;
    int distancia;
  public:
    Base();
    string getNome();
    int getDistancia();
    void setNome(string nome);
    void setDistancia(int distancia);
    friend bool operator < (const Base& base1, const Base& base2);
    friend bool operator > (const Base& base1, const Base& base2);
};

#endif