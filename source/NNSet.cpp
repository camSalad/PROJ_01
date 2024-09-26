//*********************************//
//Name: Cameron Salamone           //
//Date: 9/22/24                    //
//Purpose: Implementation of NNSet //
//*********************************
#include "NNSet.hpp"

// Constructors
NNSet::NNSet() 
{
  _size = 0;
  _arySize = DEFAULT_MAX / 32; 
  _maxVal = DEFAULT_MAX;  
  _elements = new unsigned int[_arySize + 1]; // +1 incase there is remainder 
}//DONE

NNSet::NNSet(unsigned int maxSize)
{
  _size = 0;
  _maxVal = maxSize; 
  _arySize = _maxVal / 32; 
  _elements = new unsigned int[_arySize + 1 ]; // +1 incase there is remainder
}//DONE

// Copy Constructor TODO
NNSet::NNSet(const NNSet &other) { *this = other; }

// Methods


bool NNSet::add(unsigned int toAdd) {
  unsigned int aryPos = toAdd / 32; // what position in the array 
  unsigned int bitPos = toAdd % 32; // what bit position in that element


  unsigned int mask = 1;
  mask = mask << bitPos;

  if(!contains(toAdd))
  {
    _elements[aryPos] = _elements[aryPos] | mask; // gonna assume user is smart and not check 'aryPos' is within bounds
    _size++; //increase size of set
    return true;
  }
  return false;
}//TEST 


bool NNSet::contains(unsigned int val) const {
  unsigned int aryPos = val / 32; // what position in the array 
  unsigned int bitPos = val % 32; // what bit position in that element

  unsigned int mask = 1;
  mask = mask << bitPos; // left shift mask 'val' times
  
  bool result = _elements[aryPos] & mask; 
  // bitwise to check bit position at 'val' if 1
  // the set contains 'val' else it doesnt
  return result;//(_elements & mask);
}

// TODO
unsigned int NNSet::cardinality() const { return 0; }

// if _elements is 0 then the binary is all 0's meaning
// the set is empty anything > 0 means there is at least
// one 1 in the binary which means there's at least one element
// in the set
bool NNSet::isEmpty() const 
{
  if (_size == 0) return true; 
  return false;  
}


void NNSet::clear() 
{
  // all 0's in Binary
  _elements = 0; 
}



// Operators


const NNSet &NNSet::operator=(const NNSet &rhs) {
  _arySize = rhs._arySize; 
  _size = rhs._size; 
  _elements = rhs._elements; // Memory leak? 
  _maxVal = rhs._maxVal;
  return *this;
}

NNSet &NNSet::operator+(const NNSet &otherSet) const 
{
  NNSet* unionized ;  
  NNSet unioned; 
  unionized = &unioned; 
//  unionized->_elements = _elements | otherSet._elements;
  return *unionized; 
}
NNSet &NNSet::operator-(const NNSet &rhsSet) const {}
NNSet &NNSet::operator/(const NNSet &otherSet) const {}
NNSet &NNSet::operator!() const {}



std::ostream& operator<<(std::ostream& os, const NNSet &nns)
{
  
}



