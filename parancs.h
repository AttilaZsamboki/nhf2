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
  int db;

public:
  Parancs(ParancsTipus t, string *args, int db);
  ParancsTipus getTipus() const;
  string *getArgumentumok() const;
  string getArgumentum(int index) const;
  ~Parancs();
};

struct ParancsElemzo {
  Parancs elemez(string sor) const;
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
