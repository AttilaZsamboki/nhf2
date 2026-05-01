#include <iostream>

#include "memtrace.h"
#include "seged.h"
#include <cstring>

String::String() {
  pData = (char *)"\0";
  len = 0;
}
String::String(const char a) {
  pData = new char[2];
  pData[0] = a;
  pData[1] = '\0';
  len = 1;
}
String::String(const char *a) {
  len = strlen(a);
  pData = new char[len + 1];
  strcpy(pData, a);
  pData[len] = '\0';
}
String::~String() {
  if (len)
    delete[] pData;
}
String::String(const String &rhs) {
  if (this == &rhs)
    return;
  len = rhs.len;
  if (rhs.len) {

    pData = new char[len + 1];
    strcpy(pData, rhs.pData);
    pData[len] = '\0';
  } else {
    pData = (char *)"\0";
    len = 0;
  }
}
String &String::operator=(const String &rhs) {
  if (this == &rhs)
    return *this;
  if (rhs.len) {
    if (len) {
      delete[] pData;
    }
    len = rhs.len;
    pData = new char[len + 1];
    strcpy(pData, rhs.pData);
    pData[len] = '\0';
  } else {
    pData = (char *)"\0";
    len = 0;
  }
  return *this;
}

String String::operator+(const String &rhs) const {
  String newString;
  newString.len = rhs.len + len;
  newString.pData = new char[newString.len + 1];
  strcpy(newString.pData, pData);
  strcat(newString.pData, rhs.pData);
  return newString;
}

String operator+(const char lhs, const String &rhs) {
  return String(String(lhs) + rhs);
}
char &String::operator[](const size_t rhs) const {
  if (rhs >= len)
    throw "BSC260";
  return pData[rhs];
}

std::ostream &operator<<(std::ostream &os, const String &rhs) {
  os << rhs.pData;
  return os;
}

std::istream &operator>>(std::istream &is, String &rhs) {
  char temp[1000];
  is >> std::setw(1000) >> temp;
  rhs = String(temp);
  return is;
}
