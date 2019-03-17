#include<iostream>
#include<cassert>
#include<fstream>
#include "string.hpp"

int main() {
  {
    std::cout<<std::endl;
    std::ifstream file("test_istream.txt");
    if(!file){
      std::cout<<"Unbable to open file\n";
      exit(1);
    }
    std::cout<<"Some text should be here ! "<<std::endl;
    std::cout<<"Another   (tripple space) lane of text."<<std::endl;
    int i = 0;
    String test;
    while(!file.eof()){
      file>>test;
      if(test != '\0'){
      std::cout<<test<<"["<<i<<"]";
      ++i;
      }
    }
    std::cout<<std::endl;
    file.close();
  }

  std::cout<<"Done testing istream."<<std::endl;
}
