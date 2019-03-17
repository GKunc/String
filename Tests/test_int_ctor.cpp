#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and                                                                              

int main() {
  {
    // TEST                                                                                                       
    String test(10);

    // Verify                                                                                                     
    assert( test == "" );
    assert( test.length() == 0);
    assert( test.capacity() == 10);
  }

  std::cout<<"Done testing int constructor."<<std::endl;
}
