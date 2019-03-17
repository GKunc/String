#include<iostream>
#include<cassert>
#include "string.hpp"

int main() {
  {
    //TEST
    String test("Example");
    //VERIFY
    assert( test == "Example");
    assert( test.findch(0,'E') == 0 );       // all chars starting from 0
    assert( test.findch(0,'x') == 1 );
    assert( test.findch(0,'a') == 2 );
    assert( test.findch(0,'m') == 3 );
    assert( test.findch(0,'p') == 4 );
    assert( test.findch(0,'l') == 5 );
    assert( test.findch(0,'e') == 6 );
    assert( test.findch(0,'w') == -1 );


    std::cout<<" Example: findch(0, 'm') = 3 -> "<<test.findch(0,'m')<<std::endl;
  }
  
  {
    //TEST
    String test("Longerword");
    
    //VERIFY
    assert( test == "Longerword");
    assert( test.findch(3,'o') == 7 );       // second time 'o', but we start further
    assert( test.findch(1,'o') == 1 );
    assert( test.findch(7,'o') == 7 );       // same position as startin
    assert( test.findch(-2,'n') == 2 );      // start < 0
    assert( test.findch(0,'X') == -1 );      // not in string
    assert( test.findch(20,'n') == -1 );    // starting position > length()

    
    std::cout<<" Longerword: findch(3,'o') = 7 -> "<<test.findch(3,'o')<<std::endl;
    std::cout<<" Longerword: findch(20,'n') = -1 -> "<<test.findch(20,'n')<<std::endl;
    
    
  }
  
  std::cout<<"Done testing findch."<<std::endl;
}
