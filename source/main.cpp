#include <iostream>

#include "NNSet.hpp"

using namespace std; 

int main(int argc, char ** argv)
{
  NNSet ns;
  cout << ns.contains(40000) << endl; 
  ns.add(40000);
  cout << ns.contains(40000) << endl; 


  return 0; 
}
