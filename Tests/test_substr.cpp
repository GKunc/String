#include<iostream>
#include<cassert>
#include "string.hpp"

int main() {
  {
    //TEST
    String test("Example");
    String test1("LongWord");
    String test2("TheLastChance");
    //VERIFY
    assert( test == "Example");
    assert( test.substr(0,0) == "E");           // starting from 0, one char
    assert( test.substr(0,3) == "Exam" );       // start from 0, string
    assert( test.substr(-2, 0) == "E" );        // start < 0, char
    assert( test.substr(-2, 2) == "Exa" );      // start < 0, string
    assert( test.substr(3, 3) == "m" );         // start != 0, char
    assert( test.substr(3, 5) == "mpl" );       // start != 0, string
    assert( test.substr(3, 12) == "mple" );     // start != 0, end > length()
    assert( test.substr( 9, 10) == "\0" );      // start > length() , can be wrong
    assert( test.substr(3, -2) == "\0" );       // end < 0
    assert( test.substr(5, 2) == "\0" );        // start < end
    assert( test.substr(0, 12) == "Example" );   // start = 0, end > length()   
  
    std::cout<<" Exam : test.substr(0,3) == 'Exam' -> "<<test.substr(0,3)<<std::endl;
    std::cout<<" LongWord : test1.substr(-2,12) == 'LongWord' -> "<<test1.substr(-2,12)<<std::endl;
    std::cout<<" TheLastChance : test2.substr(3,6) == 'Last' -> "<<test2.substr(3,6)<<std::endl;

  }
    
  std::cout<<"Done testing substr."<<std::endl;
}


