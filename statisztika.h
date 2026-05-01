#include "film.h"
#include <string>
using std::string;

class Statisztika {
  int osszesFilm;
  int osszesAltalanos;
  int osszesCsaladi;
  int osszesDokumentum;
  int megtekintettDb;
  int nemMegtekintettDb;
  int atlagJatekido;
  int atlagErtekeles;

public:
  string toMegjelenitesSzoveg() const;
};

struct StatisztikaSzolgaltatas {
  Statisztika statisztikatKeszit(Film **filmek, int db) const;
  int tipusonkentDarabszam(Film **filmek, int db, FilmTipus t) const;
  int megtekintettekSzama(Film **filmek, int db) const;
  int nemMegtekintettekSzama(Film **filmek, int db) const;
  double atlagJatekido(Film **filmek, int db) const;
  double atlagErtekelesFelnezes(Film **filmek, int db) const;
};
