#include "film.h"
#include <cstring>
#include <string>
using std::string;

class Filmtar {
  Film **filmek;
  int darabszam;
  int kapacitas;
  int kovetkezoId;

  void bovit();

public:
  Filmtar();
  ~Filmtar();
  void addAltalanosFilm(string cim, int jatekido, int ev, bool megtek, int ert);
  void addCsaladiFilm(string cim, int jatekido, int ev, bool megtek, int ert,
                      int korthatar);
  void addDokumentumFilm(string cim, int jatekido, int ev, bool megtek, int ert,
                         string leiras);
  Film **listFilmek(int &db) const;
  Film **listTipusszerintFilmek(FilmTipus tipus, int &db) const;
  Film **keresCimAlapjan(string resz, int &db) const;
  Film **keresEvIntervalumban(int kezdoEv, int vegEv, int &db) const;
  void megtekintettreAllit(int id);
  void ertekelesBeallít(int id, int ertekeles);
  bool filmTorol(int id);
  int getDarab() const;
};
