
#include<iostream>
#include<cassert>
#include "string.hpp"

//copy constructor, uses == and                                                

int main(){
  {
    // TEST                                                                                                                                            
    String test("abcdef");
    String test1(test);
    // Verify                                                                                
    assert( test1 == "abcdef" );
    std::cout<<"abcdef == "<<test1<<std::endl;                                                    

  }

  {
    // TEST                                                                                  
    String test("");
    String test1(test);
    // Verify                                                                                                                                                                             
    assert( test1 == '\0' );
    std::cout<<"' ' == "<<test1<<std::endl;                                                     

  }
  {
    // TEST                                                                    
                                                                                   String test;
    String test1(test);
    // Verify                                                                  
    assert( test1 == '\0' );
    std::cout<<"' ' == "<<test1<<std::endl;                                    

  }

  {
    // TEST                                                                    
                                                                               
    String test('a');
    String test1(test);
    // Verify                                                                  
    assert( test1 == 'a' );
    std::cout<<"a == "<<test1<<std::endl;                                    


  }
  std::cout<<"Done testing copy constructor."<<std::endl;
}
