/*******************************************************/
/* FILE:NNSet.hpp                                      */
/* AUTHER: S. Blythe                                   */
/* DATE: 8/2024                                        */
/* PURPOSE: Header file for NNSet class for CSC28500   */
/*******************************************************/

#ifndef _NNSET_HPP_
#define _NNSET_HPP_

#include <iostream>

#define DEFAULT_MAX 4000000000

class NNSet
{
private:
  unsigned int _maxVal;
  unsigned int _elements; 
public:
  NNSet();
  NNSet(unsigned int biggestElementPossible);
  NNSet(const NNSet &other);

  const NNSet& operator=(const NNSet &rhs); 
  
  bool add(unsigned int newElement);
  bool contains(unsigned int lookupElement) const;

  unsigned int cardinality() const; 


  NNSet& operator+(const NNSet &otherSet) const;
  NNSet& operator-(const NNSet &rhsSet) const;
  NNSet& operator/(const NNSet &otherSet) const;
  NNSet& operator!() const;

  bool isEmpty() const;
  void clear();

  friend std::ostream& operator<< (std::ostream &os, const NNSet &nns);

  // you may wish to add some more private methods below, but you
  // do not have to
private:
};

#endif
