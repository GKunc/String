
#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and                                                                              

int main(){ 
  {
    // TEST                                                                                                       
    String test("");
    
    // Verify                                                                                                     
    assert( test.length() == 0 );
    std::cout<<"'' length() 0 == "<<test.length()<<std::endl; 
    std::cout<<"Capacity() 0 == "<<test.capacity()<<std::endl;
    
  }
  {
    // TEST                                                                                             
                                                                                                        
    String test('\0');

    // Verify                                                                                           
                                                                                                        
    assert(test.length() == 0);
    std::cout<<"'' length() 0 == "<<test.length()<<std::endl;
    std::cout<<"Capacity() 0 == "<<test.capacity()<<std::endl;

  }
   
  {
    // TEST                                                                                             
                                                                                                        
    String test;

    // Verify					
                                                                                                        
    assert( test.length() == 0 );
    std::cout<<"'' length() 0 == "<<test.length()<<std::endl;
    std::cout<<"Capacity() 0 == "<<test.capacity()<<std::endl;

  }
  {
    // TEST                                                                                                      
   
    String test("abcdef");
  
    // Verify                                                                                                    
  
    assert( test.length() == 6);
    std::cout<<"abcdef length() 6 == "<<test.length()<<std::endl;                                   
    std::cout<<"Capacity() 255 == " <<test.capacity()<<std::endl;
            
  }
  {
    // TEST                                                                                                    
                                                                                                             
    String test("ahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqaahsbcksoqalsaqw");

    // Verify                                                                                                  
                                                                                                              
    assert( test.length() == 255);
    std::cout<<"abcdef length() 255 == "<<test.length()<<std::endl;                                   
    std::cout<<"Capacity() 255 == " <<test.capacity()<<std::endl;

  }

  std::cout<<"Done testing length() and capacity() ."<<std::endl;                                                                                                     
}
