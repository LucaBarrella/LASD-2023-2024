
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)
  unsigned long operator()(const Data& data) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public DictionaryContainer<Data>,
                  virtual public ResizableContainer{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using DictionaryContainer<Data>::???;
  using DictionaryContainer<Data>::size; //! Table Size

  unsigned long a{}; //!Random number between 1 and prime - 1  
  unsigned long b{}; //!Random number between 0 and prime - 1

  static const unsigned long prime = 1000000016531; //! vorrei usare 2305843009213693951

  std::default_random_engine generator = std::default_random_engine(std::random_device()());
  std::uniform_int_distribution<unsigned long> distributionA = std::uniform_int_distribution<unsigned long>(1, prime - 1);
  std::uniform_int_distribution<unsigned long> distributionB = std::uniform_int_distribution<unsigned long>(0, prime - 1);

  // template <typename Data>
  static const Hashable<Data> hash; //todo perché fare sta stronzata?

  unsigned long tableSize = 128; //! Default table size is 128

  

  //todo Note:
  // Questo è un numero primo di Mersenne e ha la proprietà che la divisione 
  // per questo numero può essere implementata come operazioni di shift e 
  // addizione, che sono molto efficienti.

  

  // ...

public:

  // Constructor //! Suggerito da Agostino
  HashTable();

  // Copy constructor
  HashTable(const HashTable&);

  // Move constructor
  HashTable(HashTable&&) noexcept;

  // Destructor
  // ~HashTable() specifiers
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible. //! MA IL PROF LO FA, PERCHÈ?
  // HashTable& operator=(const HashTable&) = delete;
  protected:
  HashTable& operator=(const HashTable&);


  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible. //! MA IL PROF LO FA, PERCHÈ?
  // HashTable& operator=(HashTable&&) = delete;
  HashTable& operator=(HashTable&&) noexcept;

  /* ************************************************************************ */
  //todo Comparison operators
  public:
  // type operator==(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  // bool operator==(const HashTable&) const noexcept; //! Cause it's extremlly expensive to compare two hash tables
  bool operator==(const HashTable&) const noexcept = delete;


  // type operator!=(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  // bool operator!=(const HashTable&) const noexcept;
  bool operator!=(const HashTable&) const noexcept = delete;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  //! unsigned long HashKey(const Data&) const noexcept; Copilot and Agostino
  virtual unsigned long HashKey(const Data& data) const noexcept;
  virtual unsigned long HashKey(unsigned long key) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
