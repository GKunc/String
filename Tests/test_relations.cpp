#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and                                                                              

int main(){ 
  {
    // TEST
    String test ("abcde");
    String test1("abcde");
  
    // Verify                                                                                
    assert( test == test1 );
    std::cout<<test1<<" == "<<test<<std::endl;  }
 
  {
    // TEST 
    String test("abcde");
    String test1("abcdf");
    // Verify

    assert( test < test1 );
    assert( test1 > test );
    assert( test <= test1 );
    assert( test1 >= test );
    std::cout<<test<<" < "<<test1<<std::endl;  }
  {
    // TEST                                  
    String test("aaaa");
    // Verify
    assert( test == "aaaa");
    assert( test != "abba");
    assert( test < "aaba" );
    assert( "xyz" > test );
    assert( test <= "aaaa" );
    assert( "aaaaaaa" >= test );
    std::cout<<"xyz > "<<test<<std::endl;

  }
  {
    // TEST                                                                                       
    String test('x');    
    String test1;   
    assert( test == 'x' );
    assert( test != test1);
    assert( test > test1 );
    assert( test <=  'z');
    assert( 'y' >= test );
    std::cout<<"y >= "<<test<<std::endl;

  }
  {
    // TEST                                                                                              
    String test('x');
    assert( test == 'x' );
    assert( test != 'z');
    assert( 'z' > test );
    assert( test <=  'z');
    assert( 'y' >= test );
    std::cout<<"y >= "<<test<<std::endl;

  }
  std::cout<<"Done testng relations"<<std::endl;
}
