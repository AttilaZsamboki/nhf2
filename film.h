#include <string>
using std::string;

enum FilmTipus {
  FILM,
  CSALADI,
  DOK,
};

class Film {
protected:
  int id;
  string cim;
  int jatekidoPerc;
  int kiadasiEv;
  bool megtekintett;
  int ertekeles;

public:
  Film(int id, string cim, int jatekIdo, int kiadasiEv, bool megtekintett,
       int ertekeles = 0)
      : id(id), cim(cim), jatekidoPerc(jatekIdo), kiadasiEv(kiadasiEv),
        megtekintett(megtekintett), ertekeles(ertekeles) {}
  int getId() { return id; }
  string getCim() { return cim; }
  int getJatekidoPerc() { return jatekidoPerc; }
  int getKiadasiEv() { return kiadasiEv; }
  bool isMegtekintett() { return megtekintett; }
  int getErtekeles() { return ertekeles; }
  void setMegtekintett() { megtekintett = true; }
  void setErtekeles(int ertekeles) { this->ertekeles = ertekeles; }
  virtual FilmTipus getTipus() const = 0;
  virtual string toMegjelenitoSzoveg() const = 0;
  virtual ~Film();
};

class AltalanosFilm : public Film {
public:
  using Film::Film;
  FilmTipus getTipus() const override { return FilmTipus::FILM; }
  string toMegjelenitoSzoveg() const override {
    string szoveg = "";
    szoveg += "[" + std::to_string(id) + "] ";
    szoveg += cim + " ";
    szoveg += "(" + std::to_string(kiadasiEv) + ") ";
    szoveg += "| Játékidő: " + std::to_string(jatekidoPerc) + " perc ";
    szoveg += "| Megtekintett: " + string(megtekintett ? "igen" : "nem") + " ";
    szoveg += "| Értékelés: " + std::to_string(ertekeles) + "/10";
    return szoveg;
  }
};

class CsaladiFilm : public Film {
  int korhatar;

public:
  CsaladiFilm(int id, string cim, int jatekIdo, int kiadasiEv,
              bool megtekintett, int ertekeles, int korhatar)
      : Film(id, cim, jatekIdo, kiadasiEv, megtekintett, ertekeles),
        korhatar(korhatar) {}
  FilmTipus getTipus() const override { return FilmTipus::CSALADI; }
  int getKorhatar() { return korhatar; }
  string toMegjelenitoSzoveg() const override {
    string szoveg = "";
    szoveg += "[" + std::to_string(id) + "] ";
    szoveg += cim + " ";
    szoveg += "(" + std::to_string(kiadasiEv) + ") ";
    szoveg += "| Játékidő: " + std::to_string(jatekidoPerc) + " perc ";
    szoveg += "| Megtekintett: " + string(megtekintett ? "igen" : "nem") + " ";
    szoveg += "| Értékelés: " + std::to_string(ertekeles) + "/10";
    szoveg += "| Korhatár: " + std::to_string(korhatar) + " ";
    return szoveg;
  }
};

class DokumentumFilm : public Film {
  string leiras;

public:
  DokumentumFilm(int id, string cim, int jatekIdo, int kiadasiEv,
                 bool megtekintett, int ertekeles, string leiras)
      : Film(id, cim, jatekIdo, kiadasiEv, megtekintett, ertekeles),
        leiras(leiras) {}
  string getLeiras() { return leiras; }
  FilmTipus getTipus() const override { return FilmTipus::DOK; }
  string toMegjelenitoSzoveg() const override {
    string szoveg = "";
    szoveg += "[" + std::to_string(id) + "] ";
    szoveg += cim + " ";
    szoveg += "(" + std::to_string(kiadasiEv) + ") ";
    szoveg += "| Játékidő: " + std::to_string(jatekidoPerc) + " perc ";
    szoveg += "| Megtekintett: " + string(megtekintett ? "igen" : "nem") + " ";
    szoveg += "| Értékelés: " + std::to_string(ertekeles) + "/10";
    szoveg += "| Leírás: " + leiras + " ";
    return szoveg;
  }
};
