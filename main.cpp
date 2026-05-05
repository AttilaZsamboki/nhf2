#include "parancs.h"
#include <iostream>
#include <string>
using std::string;

struct TesztProgram {
  void fv();
  void sortFeldolgoz(string sor);
  void kiSzoveg(string szoveg);
  void listaKiir(Film **filmek, int db);
  void hibaKiir(string uzenet);
};

int main(void) {
  Filmtar filmtar;
  ParancsElemzo elemzo;
  ParancsFeldolgozo feldolgozo(filmtar);
  string sor;
  while (getline(std::cin, sor)) {
    Parancs p = elemzo.elemez(sor);
    if (p.getTipus() == ParancsTipus::EXIT)
      break;
    feldolgozo.feldolgoz(p);
  }
}
