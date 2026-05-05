#include "filmtar.h"
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

Filmtar::Filmtar() : filmek(nullptr), kovetkezoId(1) {};

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

Film **Filmtar::listFilmek(int &db) const {
  if (darabszam == 0) {
    db = 0;
    return nullptr;
  }
  db = darabszam;
  Film **masolat = new Film *[darabszam];
  for (int i = 0; i < db; i++) {
    masolat[i] = filmek[i];
  }
  return masolat;
}

template <typename Filter>
Film **generic(int &db, int darabszam, Film **filmek, Filter filter) {
  if (darabszam == 0) {
    db = 0;
    return nullptr;
  }
  Film **masolat = new Film *[darabszam];
  int idx = 0;
  for (int i = 0; i < darabszam; i++) {
    if (filter(filmek[i])) {
      masolat[idx++] = filmek[i];
    }
  }
  db = idx;
  return masolat;
}

Film **Filmtar::listTipusszerintFilmek(FilmTipus tipus, int &db) const {
  return generic(db, darabszam, filmek,
                 [tipus](Film *f) { return f->getTipus() == tipus; });
}

Film **Filmtar::keresCimAlapjan(string resz, int &db) const {
  return generic(db, darabszam, filmek, [resz](Film *f) {
    return std::string::npos != f->getCim().find(resz)
  });
}

Film **Filmtar::keresEvIntervalumban(int kezdoEv, int vegEv, int &db) const {
  return generic(db, darabszam, filmek, [kezdoEv, vegEv](Film *f) {
    return f->getKiadasiEv() >= kezdoEv && f->getKiadasiEv() <= vegEv;
  });
}

void Filmtar::megtekintettreAllit(int id) {
  for (int i = 0; i < darabszam; i++) {
    if (filmek[i]->getId() == id) {
      filmek[i]->setMegtekintett();
    }
  }
}

void Filmtar::ertekelesBeallit(int id, int ertekeles) {
  for (int i = 0; i < darabszam; i++) {
    if (filmek[i]->getId() == id) {
      filmek[i]->setErtekeles(ertekeles);
    }
  }
}

bool Filmtar::filmTorol(int id) {
  for (int i = 0; i < darabszam; i++) {
    if (filmek[i]->getId() == id) {
      delete filmek[i];
      filmek[i] = filmek[--darabszam];
      return true;
    }
  }
  return false;
}
int Filmtar::getDarab() const { return darabszam; }
