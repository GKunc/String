#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and 

int main() {
  {
    // TEST
    String test("Some");
    
    // Verify
    assert( test[0] == 'S' );
    assert( test[1] == 'o' );
    assert( test[2] == 'm' );
    assert( test[3] == 'e' );
   
    std::cout<<"Some == "<<test[0]<<test[1]<<test[2]<<test[3]<<std::endl;
    
}  
  std::cout<<"Done testing subscript."<<std::endl;
  
}
