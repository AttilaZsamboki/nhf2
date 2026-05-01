class String {
  char *pData;
  size_t len;

public:
  void printDbg(const char *txt = "") const {
    std::cout << txt << "[" << len << "], " << (pData ? pData : "(NULL)") << '|'
              << std::endl;
  }
  String();

  size_t size() const { return len; }

  const char *c_str() const { return pData; }

  String(const char a);
  String(const char *a);
  ~String();
  String(const String &rhs);

  String &operator=(const String &rhs);
  String operator+(const String &rhs) const;
  char &operator[](const size_t rhs) const;

  friend std::ostream &operator<<(std::ostream &os, const String &rhs);
  friend String operator+(const char lhs, const String &rhs);
  friend std::istream &operator>>(std::istream &is, String &rhs);
};
