
#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and 

int main() {
  // TEST
  String test;

  // Verify
  assert( test == '\0' );
  std::cout<<"\0 == "<<test<<std::endl;

  std::cout<<"Done testing default constructor."<<std::endl;

}
