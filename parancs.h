#include "filmtar.h"
#include "statisztika.h"
#include <string>
using std::string;

enum ParancsTipus {
  ADD_FILM,
  ADD_CSALADI,
  ADD_DOK,
  LIST,
  LIST_TYPE,
  FIND_TITLE,
  FIND_YEAR,
  MARK_WATCHED,
  RATE,
  DELETE,
  STATS,
  EXIT,
};

class Parancs {
  ParancsTipus tipus;
  string *argumentumok;

public:
  Parancs(ParancsTipus t, string *args);
  ParancsTipus getTipus() const;
  string *getArgumentumok() const;
  string getArgumentum(int index) const;
};

struct ParancsElemzo {
  Parancs elemez(string sor) const;
  bool ervenyesParancs(string token) const;
};

class ParancsFeldolgozo {
  Filmtar &filmtar;
  StatisztikaSzolgaltatas statSzolg;
  void kezeldAddFilm(const Parancs &p);
  void kezeldAddCsaladi(const Parancs &p);
  void kezeldAddDok(const Parancs &p);
  void kezeldList();
  void kezeldListType(const Parancs &p);
  void kezeldFindTitle(const Parancs &p);
  void kezeldFindYear(const Parancs &p);
  void kezeldMarkWatched(const Parancs &p);
  void kezeldRate(const Parancs &p);
  void kezeldDelete(const Parancs &p);
  void kezeldStats();

public:
  ParancsFeldolgozo(Filmtar &ft);
  void feldolgoz(const Parancs &p);
};
