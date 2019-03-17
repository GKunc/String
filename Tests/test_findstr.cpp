#include<iostream>
#include<cassert>
#include "string.hpp"

int main() {
  {
    //TEST
    String test("Example");
    //VERIFY
    assert( test == "Example");
    assert( test.findstr(0,"amp") == 2 );       // starting from 0
    assert( test.findstr(-2,"E") == 0 );        // start < 0
    assert( test.findstr(2,"le") == 5 );       // last letters, not starting from 0
    assert( test.findstr(10,"xample") == -1 ); // start > length()
    assert( test.findstr(0,"word") == -1 );    // not in string
    assert( test.findstr(0,"Example") == 0 );  // whole word
    
    std::cout<<" Example findstr(0,'amp') = 2 -> "<<test.findstr(0,"amp")<<std::endl;
  }
    
  {
    //TEST
    String test("");
        
    //VERIFY
    assert( test == "\0");
    assert( test.findstr(3,"o") == -1 );          //  we start further
    assert( test.findstr(1,"one") == -1 );
    assert( test.findstr(0,"") == -1 );            // same position as starting, if mistake it  will be here!!!
    assert( test.findstr(-2,"two") == -1 );       // start < 0
    assert( test.findstr(0,"through") == -1 );    // not in string
    assert( test.findstr(20,"") == -1 );         // starting position > length()
        
    std::cout<<" Example findstr(3,'o') = -1 -> "<<test.findstr(3,"o")<<std::endl;
    std::cout<<" Example findstr(20,'') = -1 -> "<<test.findstr(20,"")<<std::endl;
        
        
    }
    
    std::cout<<"Done testing findstr."<<std::endl;
}

