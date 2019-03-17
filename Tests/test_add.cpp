#include<iostream>
#include<cassert>
#include "string.hpp"

//default constructor, uses == and 

int main() {
  {
    // TEST                                                                                                     
    String test;
    String result;
    
    // Verify                                                                                                     
    result = test +"";
    assert( result == '\0' );
    assert( result.length() == 0);
    assert( result.capacity() >= 0);
    std::cout<<"\0 + ' ' = \0 -> "<<result<<std::endl; 

  }
  
  {
    // TEST	
    String test;												   
    String test1;
    String result;

    // Verify	
    
    result = test + test1;
    assert( result == '\0');
    assert( result.length() == 0);
    assert( result.capacity() >= 0);
  }  

  {
    // TEST	
    
    String test;
    
    
    // Verify	
    
    test+="";
    assert( test == '\0' );
    assert( test.length() == 0);    
    assert( test.capacity() >= 0);
  }
  {
    // TEST	
    
    String test;
    String result;
    
    // Verify	
    
    result += test;
    assert( result == '\0' );
    assert( result.capacity() >= 0);
  }
  
  {
    // TEST	
    
    String test("abcd");
    String result;
    
    // Verify	
    
    result = test +"";
    assert( result == "abcd");
    assert( result.length() == 4);
    assert( result.capacity() >= 4);
    std::cout<<"abcd + ' ' = abcd -> "<<result<<std::endl;
    
  }
  
  {
    // TEST	
    
    String test("abcd");
    String result;
    
 // Verify					
    
    result += test;
    assert( result == "abcd");
    assert( result.length() == 4);
    assert( result.capacity() >= 4);  
    std::cout<<"' ' += abcd -> "<<result<<std::endl;
    
  }

  {
    // TEST     
    String test("abcd");
    String test1("efgh");
    String result;

    // Verify                                                                                                          
    result = test + test1;
    assert( result == "abcdefgh");
    assert( result.length() == 8);
    assert( result.capacity() >= 8);
    std::cout<<"abcd + efgh = abcdefgh -> "<<result<<std::endl;
    
  }
  {
    // TEST     
                                                                                                          
    String test("abcd");
    String result("efgh");
    
    // Verify                                                                                                 

    result += test;
    assert( result == "efghabcd");
    assert( result.length() == 8);
    assert( result.capacity() >= 8);
    std::cout<<"efgh += abcd -> "<<result<<std::endl;

  }

  {
    // TEST     

    String test("xxxxxx");
    String result("qqq");

    // Verify                                                                                                  

    result += test;
    assert( result == "qqqxxxxxx");
    assert( result.length() == 9 );
    assert( result.capacity() >= 9);
    std::cout<<"qqq += xxxxxx -> "<<result<<std::endl;
    
  }
  
  {
    // TEST     

    String test("xxx");

    // Verify                                                                                                  

    test += "jhgf";
    assert( test == "xxxjhgf");
    assert( test.length() == 7);
    assert( test.capacity() >= 7);
    std::cout<<"xxx += jhgf -> "<<test<<std::endl;

  }

  {
    // TEST     

    String test("polk");
  
    // Verify                                                                                                  

    test += 'j';
    assert( test == "polkj");
    assert( test.length() == 5);
    assert( test.capacity() >= 5);
    std::cout<<"polk += j  -> "<<test<<std::endl;

  }

  {
    // TEST     
                                                                                                       
    String test("polk");
    String result;

    // Verify                                                                                                  

    result = test + 'j';
    assert( result == "polkj");
    assert( result.length() == 5);
    assert( result.capacity() >= 5);
    std::cout<<"polk + j = polkj -> "<<result<<std::endl;

  }

  {
    // TEST     
                                                                                                            
    String test("losi");
    String result;

    // Verify                                                                                                  

    result = test +  "iem";
    assert( result == "losiiem");
    assert( result.length() == 7);
    assert( result.capacity() >= 7);
    std::cout<<"losi + iem = losiiem -> "<<result<<std::endl;

  }

  std::cout<<"Done add test."<<std::endl;
  
}
