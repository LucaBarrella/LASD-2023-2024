
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...
#define DEFAULT_TABLE_SIZE 128
#define RESIZE_FACTOR 2
#define HASHTABLE_SHRINK_FACTOR 0.125
#define LOAD_FACTOR 0.50

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data>{
  // Must extend HashTable<Data>

private:

  // ...
  enum Status {Empty, Occupied, Deleted};

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::AdjustTableSize;
  using HashTable<Data>::GetTableSize;

  Vector<Data> table;
  Vector<Status> tableStatus;

  using DictionaryContainer<Data>::InsertAll;

  // ...

public:

  // Default constructor
  // HashTableOpnAdr() specifiers;
  HashTableOpnAdr();

  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  HashTableOpnAdr(unsigned long size);

  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableOpnAdr(const TraversableContainer<Data>& container);

  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableOpnAdr(unsigned long size, const TraversableContainer<Data>& container);

  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableOpnAdr(MappableContainer<Data>&& container);

  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(unsigned long size, MappableContainer<Data>&& container);

  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(const HashTableOpnAdr<Data>& ht);

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;
  ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr<Data>& operator=(const HashTableOpnAdr<Data>& ht);

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr<Data>& operator=(HashTableOpnAdr<Data>&& ht) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const HashTableOpnAdr<Data>& ht) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const HashTableOpnAdr<Data>& ht) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  inline bool Insert(const Data& value) override;

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  inline bool Insert(Data&& value) override;

  // type Remove(argument) specifiers; // Override DictionaryContainer member
  inline bool Remove(const Data& value) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  inline bool Exists(const Data& value) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  void Resize(unsigned long newSize);

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member
  void Clear() override;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  unsigned long HashKey(const Data& value, unsigned long& tempIndex) const noexcept;

  // type Find(argument) specifiers;
  // inline bool Find(const Data& value, unsigned long& index, unsigned long& tempIndex) const noexcept;
  inline bool Find(unsigned long&, unsigned long&, const Data&) const noexcept;

  // type FindEmpty(argument) specifiers;
  unsigned long FindEmpty(const Data&, unsigned long&) const noexcept;

  // type Remove(argument) specifiers;
  inline bool Remove(const Data&, unsigned long&) noexcept;

  // type GetTableSize() specifiers;
  unsigned long GetTableSize() const noexcept override;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
