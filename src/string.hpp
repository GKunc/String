#ifndef CS2_STRING_HPP_
#define CS2_STRING_HPP_

#include<iostream>
#include<cassert>

const int STRING_SIZE = 256;

class String{
public:
  
  String();
  String(const char);
  String(const char[]);
  
  bool operator==(const String&) const;
  bool operator<(const String&) const;
  String operator+(const String&) const;
  String& operator+=(const String);
  
  char& operator[](int);
  char operator[](int) const;
  int length() const;
  int capacity() const;
  
  String substr(int,int) const;
  int findch(int,char) const;
  int findstr(int,const String&) const;
  
  friend std::ostream& operator<<(std::ostream&,const String&);
  friend std::istream& operator>>(std::istream&,String&);
  
private:

  char str[STRING_SIZE];
};

String operator+ (const char[],const String&);
String operator+ (char,const String&);
bool operator==(const char[],const String&);
bool operator==(char,const String&);
bool operator< (const char[],const String&);
bool operator< (char,const String&);
bool operator<=(const String&,const String&);
bool operator!=(const String&,const String&);
bool operator>=(const String&,const String&);
bool operator>(const String&,const String&);

#endif
