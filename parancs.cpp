#include "parancs.h"
#include <sstream>
#include <stdexcept>

Parancs::Parancs(ParancsTipus t, string *args, int db)
    : tipus(t), argumentumok(args), db(db) {}

ParancsTipus Parancs::getTipus() const { return tipus; }

string *Parancs::getArgumentumok() const { return argumentumok; }

string Parancs::getArgumentum(int index) const {
  if (index >= db)
    throw std::invalid_argument(
        "Nagyobb index lett megadva mint amennyi argumentum létezik");
  return argumentumok[index];
}

Parancs::~Parancs() { delete[] argumentumok; }

ParancsTipus stringToParancsTipus(const std::string &s) {
  if (s == "ADD_FILM")
    return ADD_FILM;
  if (s == "ADD_CSALADI")
    return ADD_CSALADI;
  if (s == "ADD_DOK")
    return ADD_DOK;
  if (s == "LIST")
    return LIST;
  if (s == "LIST_TYPE")
    return LIST_TYPE;
  if (s == "FIND_TITLE")
    return FIND_TITLE;
  if (s == "FIND_YEAR")
    return FIND_YEAR;
  if (s == "MARK_WATCHED")
    return MARK_WATCHED;
  if (s == "RATE")
    return RATE;
  if (s == "DELETE")
    return DELETE;
  if (s == "STATS")
    return STATS;
  if (s == "EXIT")
    return EXIT;
  throw std::invalid_argument("Ismeretlen parancs: " + s);
}

Parancs ParancsElemzo::elemez(string sor) const {
  std::istringstream ss(sor);
  std::string tipusStr;
  ParancsTipus tipus;
  const int MAX_ARGS = 10;
  std::string *argumentumok = new std::string[MAX_ARGS];
  int db = 0;

  ss >> tipusStr;
  while (ss >> argumentumok[db])
    db++;
  return Parancs(tipus, argumentumok, db);
}

void ParancsFeldolgozo::kezeldAddFilm(const Parancs &p) {
  string cim = p.getArgumentum(0);
  int jatekido = stoi(p.getArgumentum(1));
  int kiadasEv = stoi(p.getArgumentum(2));
  bool megtekintett = stoi(p.getArgumentum(3)); // "0" vagy "1"
  int ertekeles = stoi(p.getArgumentum(4));
  filmtar.addAltalanosFilm(cim, jatekido, kiadasEv, megtekintett, ertekeles);
}

void ParancsFeldolgozo::kezeldAddCsaladi(const Parancs &p) {
  string cim = p.getArgumentum(0);
  int jatekido = stoi(p.getArgumentum(1));
  int kiadasEv = stoi(p.getArgumentum(2));
  bool megtekintett = stoi(p.getArgumentum(3));
  int ertekeles = stoi(p.getArgumentum(4));
  int korthatar = stoi(p.getArgumentum(5));
  filmtar.addCsaladiFilm(cim, jatekido, kiadasEv, megtekintett, ertekeles,
                         korthatar);
}

void ParancsFeldolgozo::kezeldAddDok(const Parancs &p) {
  string cim = p.getArgumentum(0);
  int jatekido = stoi(p.getArgumentum(1));
  int kiadasEv = stoi(p.getArgumentum(2));
  bool megtekintett = stoi(p.getArgumentum(3));
  int ertekeles = stoi(p.getArgumentum(4));
  string leiras = p.getArgumentum(5);
  filmtar.addDokumentumFilm(cim, jatekido, kiadasEv, megtekintett, ertekeles,
                            leiras);
}

void printFilmek(Film **filmek, int db) {
  for (int i = 0; i < db; i++) {
    filmek[i]->toMegjelenitoSzoveg();
  }
}

void ParancsFeldolgozo::kezeldList() {
  int db = 0;
  Film **filmek = filmtar.listFilmek(db);
  printFilmek(filmek, db);
}

void ParancsFeldolgozo::kezeldListType(const Parancs &p) {
  int db = 0;
  Film **filmek = filmtar.listTipusszerintFilmek(
      stringToParancsTipus(p.getArgumentum(0)), db);
  printFilmek(filmek, db);
}

void ParancsFeldolgozo::kezeldFindTitle(const Parancs &p) {
  int db = 0;
  Film **filmek = filmtar.keresCimAlapjan(p.getArgumentum(0), db);
  printFilmek(filmek, db);
}

void ParancsFeldolgozo::kezeldFindYear(const Parancs &p) {
  int db = 0;
  Film **filmek = filmtar.keresEvIntervalumban(stoi(p.getArgumentum(0)),
                                               stoi(p.getArgumentum(1)), db);
  printFilmek(filmek, db);
}

void ParancsFeldolgozo::kezeldMarkWatched(const Parancs &p) {
    filmtar.megtekitettreAllit(stoi(p.getArgumentum(0));
}

void ParancsFeldolgozo::kezeldRate(const Parancs &p) {
  filmtar.ertekelesBeallit(stoi(p.getArgumentum(0)), stoi(p.getArgumentum(1)));
}

void ParancsFeldolgozo::kezeldDelete(const Parancs &p) {
  filmtar.filmTorol(stoi(p.getArgumentum(0)));
}
