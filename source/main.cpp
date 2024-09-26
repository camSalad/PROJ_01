#include <iostream>

#include "NNSet.hpp"

using namespace std; 

int main(int argc, char ** argv)
{
  NNSet ns;
  unsigned int num1; 
  cout << "Enter a number to add: "; 
  cin >> num1; 
  ns.add(num1);


  unsigned int testNum; 
  cout << "Enter a number to check: " ; 
  cin >> testNum; 

  cout << ns.contains(testNum) << endl; 


  return 0; 
}
