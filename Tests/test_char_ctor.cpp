
#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and                                                                              

int main() {
  {
  // TEST                                                                                                       
  String test('s');

  // Verify                                                                                                     
  assert( test == 's' );
  std::cout<<"s == "<<test<<std::endl;                                                                        
  }

  {
    // TEST                                                                    
                                                                              
    String test('\0');

    // Verify                                                                 
                                                                                
    assert( test == '\0' );
    std::cout<<"'\0' == "<<test<<std::endl;                                       

  }

  std::cout<<"Done testing char constructor."<<std::endl;

}

