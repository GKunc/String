
#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and, uses swap
                                                          
int main(){
  {
    // TEST                                                                                 
    String test("");
    String test1;

    test1 = test;
    test1 = test;

    // Verify                                                                                
    assert(test1 == '\0');
    test1 = test1;
    assert(test1 == '\0');
    std::cout<<"' '  = "<<test1<<std::endl;
  }

  {
    String test("assignment");
    String test1;

    test1 = test; // checking if deallocate properly
    test1 = test;

    assert(test1 == "assignment");
    test1 = test1;
    assert(test1 == "assignment");
    std::cout<<"assignment = "<<test1<<std::endl;
  }
  {
    String test('a');
    String test1;
    
    test1 = test; // assign same obj                                                  
    test1 = test;
    
    assert(test1 == 'a');
    test1 = test1;
    assert(test1 == 'a'); 
    std::cout<<"a = "<<test1<<std::endl;
  }
  {
    String test("Same");
    String test1("test");

    assert(test == "Same");
    assert(test1 =="test");

    test1 = test; // assign same obj                                                  
    test1 = test;
    assert(test1 == "Same");
    std::cout<<"Same = "<<test1<<std::endl;
  }


  std::cout<<"Done testing assignment (=) operator."<<std::endl;
}
