//*********************************//
//Name: Cameron Salamone           //
//Date: 9/22/24                    //
//Purpose: Implementation of NNSet //
//*********************************
#include "NNSet.hpp"

// Constructors
NNSet::NNSet() { _maxVal = DEFAULT_MAX; }

NNSet::NNSet(unsigned int maxValPossible) : _maxVal(maxValPossible) {}

// Copy Constructor
NNSet::NNSet(const NNSet &other) { *this = other; }

// Methods


bool NNSet::add(unsigned int toAdd) {
  unsigned int mask = 1;
  mask = mask << toAdd;

  if(!contains(toAdd))
  {
    _elements = _elements | mask;
    return true;
  }
  return false;
}


bool NNSet::contains(unsigned int val) const {
  unsigned int mask = 1;

  // left shift mask 'val' times
  mask = mask << val;

  // bitwise to check bit position at 'val' if 1
  // the set contains 'val' else it doesnt
  return (bool)(_elements & mask);
}

// TODO
unsigned int NNSet::cardinality() const { return 0; }

// if _elements is 0 then the binary is all 0's meaning
// the set is empty anything > 0 means there is at least
// one 1 in the binary which means there's at least one element
// in the set
bool NNSet::isEmpty() const { 
	return !_elements; 
}


void NNSet::clear() 
{
  // all 0's in Binary
  _elements = 0; 
}

// Operators


const NNSet &NNSet::operator=(const NNSet &rhs) {
  _elements = rhs._elements;
  _maxVal = rhs._maxVal;
  return *this;
}

NNSet &NNSet::operator+(const NNSet &otherSet) const 
{
  NNSet* unionized ;  
  NNSet unioned; 
  unionized = &unioned; 
  unionized->_elements = _elements | otherSet._elements;
  return *unionized; 
}
NNSet &NNSet::operator-(const NNSet &rhsSet) const {}
NNSet &NNSet::operator/(const NNSet &otherSet) const {}
NNSet &NNSet::operator!() const {}



std::ostream& operator<<(std::ostream& os, const NNSet &nns)
{
  
}



