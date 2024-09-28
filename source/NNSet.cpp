//*********************************//
//Name: Cameron Salamone           //
//Date: 9/22/24                    //
//Purpose: Implementation of NNSet //
//*********************************//
#include "NNSet.hpp"
#include <iostream> 

// Constructors
NNSet::NNSet() 
{
  _size = 0;
  _arySize = (DEFAULT_MAX / 32) + 1; 
  _maxVal = DEFAULT_MAX;  
  _elements = new unsigned int[_arySize + 1]; // +1 incase there is remainder 
}//DONE

NNSet::NNSet(unsigned int maxSize)
{
  _size = 0;
  _maxVal = maxSize; 
  _arySize = (_maxVal / 32) + 1; 
  _elements = new unsigned int[_arySize + 1 ]; // +1 incase there is remainder
}//DONE

// Copy Constructor TODO
NNSet::NNSet(const NNSet &other) 
{ 
  _size = other._size; 
  _maxVal = other._maxVal; 
  _arySize = other._arySize;
  _elements = new unsigned int[_arySize + 1]; 
  copyAry(other._elements);

}

// Methods

//DONE
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
}

// DONE
bool NNSet::contains(unsigned int val) const {
  unsigned int aryPos = val / 32; // what position in the array 
  unsigned int bitPos = val % 32; // what bit position in that element

  unsigned int mask = 1;
  mask = mask << bitPos; // left shift mask 'val' times
  
  bool result = _elements[aryPos] & mask; 
  // bitwise to check bit position at 'val' if 1
  // the set contains 'val' else it doesnt
  return result;
}



//DONE
unsigned int NNSet::cardinality() const 
{
  
  unsigned int count = 0; 
  for(unsigned int i = 0; i <= _maxVal; i++)
  {
    if( contains(i))
    {
      count++; 
    }
  }
  return count;
}

//DONE
bool NNSet::isEmpty() const 
{
  if (_size == 0) return true; 
  return false;  
}

//DONE
void NNSet::clear() 
{
  for(int i = 0; i < _arySize; i++)
  {
    _elements[i] = 0; // each slot is all 0's in binary
  }
  _size = 0; // no elements = no size
}

//Copies passed in array to *this array
void NNSet::copyAry (unsigned int * toCopy)
{
  for(int i = 0; i < _arySize; i++) // ** think about whether there is an edge case at _arySize + 1 **
  {
    _elements[i] = toCopy[i]; 
  }
}//DONE




// Operators

//DONE
const NNSet &NNSet::operator=(const NNSet &rhs) {
  _arySize = rhs._arySize; 
  _size = rhs.cardinality(); 
  copyAry(rhs._elements);
  _maxVal = rhs._maxVal;
  return *this;
}

//DONE
NNSet &NNSet::operator+(const NNSet &otherSet) const 
{
  NNSet * newSet = new NNSet(_maxVal);//heap allocation 

  // can assume that two set have the same max possible value
  for(int i = 0; i < otherSet._arySize; i++)
  {
    newSet->_elements[i] = otherSet._elements[i] | _elements[i]; 
  }

  return *newSet;
}


//DONE
NNSet &NNSet::operator-(const NNSet &rhsSet) const
{
  NNSet * newSet = new NNSet(_maxVal); 
  NNSet intersection = *this / rhsSet; // xD 

  
  for(int i = 0; i < _arySize; i++)
  {
    newSet->_elements[i] = _elements[i] -intersection._elements[i]; 
  }

  return *newSet; 
}

//DONE
NNSet &NNSet::operator!() const 
{
  NNSet * newSet = new NNSet(_maxVal); 
  for(int i = 0; i < _arySize; i++)
  {
    newSet->_elements[i] = ~_elements[i]; 
  }
  return *newSet;
}

//DONE
NNSet &NNSet::operator/(const NNSet &rhs) const 
{
  NNSet * newSet  = new NNSet(_maxVal); 
  for(unsigned int i = 0; i < _arySize; i++)
  {
    newSet->_elements[i] = _elements[i] & rhs._elements[i]; 
  }
  return *newSet;
}

// O(n^3) ;(((
// DONE
std::ostream& operator<<(std::ostream& os, const NNSet &nns)
{
  int printCount = 0; 
  os << "{ "; 

  for(int i = 0; i < nns._arySize; i++)
  {
    for (int pos = 0; pos < 32; pos++)
    {
      unsigned int mask  = 1 << pos; 
      if (nns._elements[i] & mask) 
      {

        if( printCount == nns.cardinality()- 1) // without comma
        {
          os << ((i * 32) + pos);
        } 
        else if (printCount == nns.cardinality())// forgot why this is here
        {
          return os << " }"; 
        }
        else // with comma 
        {
          os << ((i * 32) + pos) << ", " ; 
        }
        printCount++; 
      }
    }
  }
  os << " }"; 
  return os;
}



