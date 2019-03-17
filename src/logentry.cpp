

//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

int stringToInt(const String& s) {
  int i = 0, j = 0;
  while(s[i] >= '0' && s[i] <= '9') { // we check for number so if the will be - it will be j = 0;
    j = (j*10) + (s[i] - '0'); // change to int and move to 10^j
    ++i;
  }
  return j;
} 

Time::Time() {
  hour = 0;
  minute = 0;
  second = 0;
}

Time::Time(const String& s) {
    std::vector<String> vec = s.split(':');
    hour = stringToInt(vec.at(1)); 
    minute = stringToInt(vec.at(2)); // will be 5 instead of 05
    second = stringToInt(vec.at(3).substr(0,1));  
}

int Time::getHour() const {
  return hour;
}

int Time::getMinute() const {
  return minute;
}

int Time::getSecond() const {
  return second;
}

Date::Date() {
  day = "";
  month = "";
  year = 0;
}

Date::Date(const String& s) {
    std::vector<String> vec = s.split('/');
    day = vec[0].substr(1,2); // just to digits
    month = vec.at(1); // whole string
    year = stringToInt(vec.at(2).substr(0,3)); // 4 digits
  
}

String Date::getDay() const {
  return day;
}

String Date::getMonth() const {
  return month;
}

int Date::getYear() const {
  return year;
} 

LogEntry::LogEntry() { // empty LogEntry
  host = "";
  Date blank1;
  Time blank2;
  date = blank1;
  time = blank2;
  request = "";
  status = "";
  number_of_bytes = 0;
}

////////////////////////////////////////////////////////// 
// REQUIRES: get String    
// ENSURES: create new LogEntry
//
LogEntry::LogEntry(const String& s) { // constructor of LogEntry
  std::vector<String> vec = s.split(' ');
  if(vec.size() == 10){ // iv valid
  host = vec.at(0);
  date = Date(vec.at(3)); // then convert to day month year
  time = Time(vec.at(3)); // then convert to hour min sec
  request = vec.at(5).substr(1,100); // GET, just skipping "
  status = vec.at(8);
  number_of_bytes = stringToInt(vec.at(9));
   } else {
    LogEntry blank;
  }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  in.open() && while(!in.eof())
// ENSURES: retrun vector<LogEntry> 
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result; 
    while(!in.eof()) { // till the end of the file
      char buffer[256];
      String temp;
      char c;
      int i = 0;
      while(in.get(c)) { 
	if(c == '\n') break; // read till end of the line
	buffer[i] = c;
	++i;
      }
      buffer[i] = 0;
      temp = buffer; // change to string
      if(temp == "") break; // if empty lane break ( end of file)
      LogEntry line(temp); // make logentry
      result.push_back(line);
    }
    return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES: get LogEntry  
// ENSURES: return ostream to do a<<b<<c<<..<<x;
//
std::ostream& operator<<(std::ostream& out, const LogEntry & path) {
  out<<path.host<<" "<<path.date.getDay()<<"/"<<path.date.getMonth()<<"/"<<path.date.getYear()<<" ";
  if(path.time.getHour() < 10) // add 0 if its 1 digit number
    std::cout<<"0"<<path.time.getHour()<<":";
  else
    std::cout<<path.time.getHour()<<":"; // print number if > 9

 if(path.time.getMinute() < 10) 
   std::cout<<"0"<<path.time.getMinute()<<":";
 else
   std::cout<<path.time.getMinute()<<":";

 if(path.time.getSecond() < 10) 
   std::cout<<"0"<<path.time.getSecond()<<" ";
 else
   std::cout<<path.time.getSecond()<<" ";
  
 std::cout<<path.request<<" "<<path.status<<" "<<path.number_of_bytes<<std::endl; // output all information
  return out;    
}

//////////////////////////////////////////////////////////                     
// REQUIRES: valid vector<LogEntry>                                            
// ENSURES:  not reading out of vector (<=end())                              
//                          
void output_all(std::ostream& out, const std::vector<LogEntry>& obj) {
  for(auto it = obj.begin();it!=obj.end();++it){
    out << *it; // output all using << operator
  }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  valid vector<LogEntry>
// ENSURES:   not reading out of vector ( <= end()) 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& obj) {
  for(auto it = obj.begin();it!=obj.end();++it) {
    out << it->host<<std::endl; // print only hosts
  }
}
////////////////////////////////////////////////////////// 
// REQUIRES: get valid vector<LogEntry> 
// ENSURES: return sum (int)
//
int byte_count(const std::vector<LogEntry> & obj) {
  int result = 0;
  for(auto it = obj.begin();it!=obj.end();++it) { // printing whole vector
    result += it->number_of_bytes; // add to result current value
  }
  return result;
}

