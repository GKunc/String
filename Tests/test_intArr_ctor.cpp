#include<iostream>
#include<cassert>
#include "string.hpp"

int main() {
  {
    // TEST                                                                                                       
    String test(0,"");

    // Verify                                                                                                     
    assert( test == "" );
    assert( test.length() == 0 );
    assert( test.capacity() == 0 );
    std::cout<<"'' == "<<test<<std::endl;
  }

  {
    // TEST
    String test(1,"");

    // Verify
    assert( test == "" );
    assert( test.length() == 0 );
    assert( test.capacity() == 1 );
    std::cout<<"'' == "<<test<<std::endl;
  }
  {
    // TEST
    String test(1,"a");

    // Verify
    assert( test == "a" );
    assert( test.length() == 1 );
    assert( test.capacity() == 1 );
    std::cout<<"a == "<<test<<std::endl;
  }
  {
    // TEST
    String test(10,"a");

    // Verify
    assert( test == "a" );
    assert( test.length() == 1 );
    assert( test.capacity() == 10 );
    std::cout<<"a == "<<test<<std::endl;
  }
  {
    // TEST
    String test(3,"abc");

    // Verify
    assert( test == "abc" );
    assert( test.length() == 3 );
    assert( test.capacity() == 3 );
    std::cout<<"abc == "<<test<<std::endl;
  }
  {
    // TEST
    String test(5,"abc");

    // Verify
    assert( test == "abc" );
    assert( test.length() == 3 );
    assert( test.capacity() == 5 );
    std::cout<<"abc == "<<test<<std::endl;
  }
  std::cout<<"Done testing int_Arr_ctor."<<std::endl;
}
