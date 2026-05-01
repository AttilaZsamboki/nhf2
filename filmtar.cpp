#include "filmtar.h"
#include "film.h"
#include <string>
using std::string;

void Filmtar::bovit() {
  if (darabszam == kapacitas) {
    Film **tmp = new Film *[kapacitas * 2];
    std::memcpy(tmp, filmek, darabszam);
    delete[] filmek;
    filmek = tmp;
    kapacitas *= 2;
  }
}

Filmtar::Filmtar() : kovetkezoId(1), filmek(nullptr) {};

Filmtar::~Filmtar() {
  for (int i = 0; i < darabszam; i++) {
    delete filmek[i];
  }
  delete[] filmek;
};

void Filmtar::addAltalanosFilm(string cim, int jatekido, int ev, bool megtek,
                               int ert) {
  AltalanosFilm *new_film =
      new AltalanosFilm(kovetkezoId++, cim, jatekido, ev, megtek, ert);
  bovit();
  filmek[darabszam++] = new_film;
}

void Filmtar::addCsaladiFilm(string cim, int jatekido, int ev, bool megtek,
                             int ert, int korthatar) {
  CsaladiFilm *new_film =
      new CsaladiFilm(kovetkezoId++, cim, jatekido, ev, megtek, ert, korthatar);
  bovit();
  filmek[darabszam++] = new_film;
}

void Filmtar::addDokumentumFilm(string cim, int jatekido, int ev, bool megtek,
                                int ert, string leiras) {
  DokumentumFilm *new_film =
      new DokumentumFilm(kovetkezoId++, cim, jatekido, ev, megtek, ert, leiras);
  bovit();
  filmek[darabszam++] = new_film;
}
