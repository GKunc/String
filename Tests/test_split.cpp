#include<iostream>
#include<cassert>
#include<vector>
#include "string.hpp"

int main(){ 
  { 
    String test("TextWithoutSplit");
    std::vector<String> result;

    assert(test == "TextWithoutSplit");
    result = test.split('.');

    assert(result[0] == "TextWithoutSplit");

    std::cout<<"TextWithoutSplit = "<<result[0]<<std::endl;

  }
  
  {
    // TEST                                                                                                       
    String test("Some,text,is,given,here");
    std::vector<String> result;
    // Verify                                                                                                 
    assert( test =="Some,text,is,given,here" );
    result = test.split(',');

    assert(result[0] == "Some");
    assert(result[1] == "text");
    assert(result[2] == "is");
    assert(result[3] == "given");
    assert(result[4] == "here");
    
    std::cout<<"Some text is given here = "<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3]<<" "<<result[4]<<std::endl;
    
  }
 
  {
   
    String test("A;b;c;d");
    std::vector<String> result;
    // Verify                                                                                                    
  
    assert( test == "A;b;c;d" );
    result = test.split(';');

    assert(result[0] == "A");
    assert(result[1] == "b");
    assert(result[2] == "c");
    assert(result[3] == "d");
    std::cout<<"A;b;c;d == "<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3]<<std::endl;                                                                   
  }


  {

    String test("One more test");
    std::vector<String> result;
    assert( test == "One more test");
    result = test.split(' ');

    assert(result[0] == "One");
    assert(result[1] == "more");
    assert(result[2] == "test");
    std::cout<<"One more test = "<<result[0]<<" "<<result[1]<<" "<<result[2]<<std::endl; 
  }

  {
    String test;
    std::vector<String> result;
    assert( test == '\0');
    result = test.split(' ');
    assert( result[0] == '\0');
  }
  
  {

    String test("-a--b-");
    std::vector<String> result;
    // Verify                                                                                              
                                                                                                           

    assert( test == "-a--b-" );
    result = test.split('-');

    assert(result[0] == "");
    assert(result[1] == "a");
    assert(result[2] == "");
    assert(result[3] == "b");
    assert(result[4] == "");
    
    std::cout<<"-a--b- == "<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3]<<" "<<result[4]<<std::endl;       

  }

  std::cout<<"Done testing split."<<std::endl;
}
