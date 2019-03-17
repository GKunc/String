#include "string.hpp" // should be string1.hpp after change

int String::length() const{
  int length = 0;
  while(str[length] != 0){
    ++length;
  }
  return length;// Return length with NULL terminaor
}

int String::capacity() const {
  return STRING_SIZE - 1; // Size - NULL terminator
}

String::String() {
  str[0] = 0; // Array with only NULL
}

String::String(const char c) {
  str[0] = c; // First char
  str[1] = 0; // Always NULL on the end
}

String::String(const char array[]) {
  int i = 0;
  while(array[i] != 0) {
    str[i] = array[i];
    ++i;
    if(i >= capacity()) break;
  }
  str[i] = 0;
}

char String::operator[](int index) const{
  assert(index >= 0); // PRE:
  assert(index <= length());
  return str[index];
}

char& String::operator[](int index) { // If you need to modify lhs
  assert(index >= 0);
  assert(index <= length());
  return str[index];
}

std::ostream& operator<<(std::ostream& os,const String& obj) {
  os<<obj.str; // Work on char array
  return os;
}

std::istream& operator>>(std::istream& is, String& obj) {
  char temp[STRING_SIZE];
  is>>temp;  // Read to char array till white space character
  obj = String(temp); // Using char[] constructor
  return is;
}

bool String::operator==(const String& rhs) const {
  int i=0;
  while( (str[i] != 0) && (str[i] == rhs.str[i]) ) { // Till the end of word or same char
    ++i;
  }
  return str[i] == rhs.str[i]; // Return true if same, flase if different
}

bool operator==(const char lhs[], const String& rhs) {
  return String(lhs) == rhs; // Change with constructor 
}

bool operator==(char lhs, const String& rhs) {
  return String(lhs) == rhs; // Change with constructor
}

String String::operator+(const String& rhs) const{
  int offset = length();
  String result(str); // Constructor for first part
  int i = 0;
  while(rhs.str[i] != 0){ // Do untill the end of word
    if((offset + i) >= capacity() ) break; // If length + i > SIZE in array 
    result.str[offset + i] = rhs.str[i];
    ++i;  
  }
  result.str[offset + i] = 0; // NULL on the end
  return result;
}

String& String::operator+=(const String rhs) {
  int start = length();
  int i = 0;
  while(rhs.str[i] != 0) { 
    if ( (start + i) >= capacity() ) break;
    str[start + i] = rhs[i];
    ++i;
  }
  str[start + i] = 0;
  return *this; // Return pointer to lhs obj 
}

String operator+ (const char lhs[], const String& rhs) {
  String result;
  String temp(lhs); // Change with constructor 
  result = temp + rhs;
  return result;
}

String operator+ (char lhs, const String& rhs) {
  String result;
  String temp(lhs); // Change with contructor
  result = temp + rhs;
  return result;
}

bool String::operator< (const String& obj) const { // checking like in dictionary
  int i = 0;  
  while( (str[i] != 0 ) && (obj[i] != 0) && ( str[i] == obj.str[i]))  {
      ++i; // Untill the end of lhs or rhs word and untill they have same char on same place 
    }
  return str[i] < obj.str[i]; // bool operation for one char
}

bool operator< ( const char lhs[], const String& rhs) {
  return String(lhs) < rhs;
}

bool operator< (char lhs, const String& rhs) {
  return String(lhs) < rhs;
}

bool operator<=(const String& lhs, const String& rhs) {
  return !(rhs < lhs); // using < operator 
}

bool operator!=(const String& lhs, const String& rhs) {
  return !(lhs == rhs); // using == operator
}

bool operator>=(const String& lhs, const String& rhs) {
  return !(lhs < rhs); 
}

bool operator> (const String& lhs, const String& rhs) {
  return rhs < lhs;
}

String String::substr(int start, int end) const {
  if(start < 0) start = 0;
  if(start > end) return String(); // Return empty                                      
  if(end < 0) return String();
  if(end >= length()) end = length() - 1; // Change end to lenght of word, without NULL 

  /////////////////////////////////

  String result;
  
  int i;
  for(i=start;i<=end;++i){
    result.str[i - start] = str[i];
  }
  result.str[i - start] = 0; // Last is NULL
  return result;
}

int String::findch(int index, char ch) const {
  if(index < 0) index = 0;
  if(index > length()) return -1;

  int i = index;
  while(str[i] != 0){
    if(str[i] == ch) return i; // If array spot has same char as given return index
    ++i;
  }
  return -1; // If not found
}

int String::findstr(int index, const String& obj) const {
  if(index < 0) index = 0;
  if(index > length() - obj.length()) return -1; // If index is greater then number of characters in words which left 
  if(index > length()-1) return -1; 

  int i = index;
  while(str[i] != 0) {
    if( substr(i,obj.length() + i - 1) == obj) // Using of substr and == operator
      return i;
    ++i;
  }
  return -1; // Not found
}
