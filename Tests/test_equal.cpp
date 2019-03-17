
#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and                                                                              

int main(){ 
  {
    // TEST                                                                                                       
    String test("");
  
    // Verify                                                                                                     
    assert( test =="\0" );
    std::cout<<"\0 == "<<test<<std::endl;                                                                          
  }
 
  {
    // TEST                                                                                                      
    String test("A");
  
    // Verify                                                                                                    
  
    assert( test == 'A' );
    std::cout<<"A == "<<test<<std::endl;                                                                   
    
  
  }
  
  {
    // TEST                                                                                                      
    
    String test("abcdef");
    
    // Verify                                                                                                    
    
    assert( test == "abcdef");
    std::cout<<"abcdef == "<<test<<std::endl;                                                                   
  }
  
  {
    // TEST
    
    
    String test("abcdef");
    String test2("cdefgh");
    // Verify                                                                                                          
    assert( test != test2);
    std::cout<<test<<" != "<<test2<<std::endl;
  }
  
  std::cout<<"Done testing equal and printing."<<std::endl;                                                                                                     
}

