
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data>{
  // Must extend HashTable<Data>

private:

  // ...
  enum Status {EMPTY, OCCUPIED, DELETED};

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::tableSize; //todo remove and use a macro

  Data* table = nullptr;
  Status* tableStatus = nullptr;

  // ...

public:

  // Default constructor
  // HashTableOpnAdr() specifiers;
  HashTableOpnAdr() = default;

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
  ~HashTableOpnAdr(); //todo controllare!

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
  inline bool Remove(const KeyType& key) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  inline bool Exists(const KeyType& key) const noexcept override;

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
  unsigned long HashKey(const Data&, unsigned long) const noexcept;

  // type Find(argument) specifiers;
  bool Find(unsigned long&, unsigned long&, const Data&) const noexcept;

  // type FindEmpty(argument) specifiers;
  unsigned long FindEmpty(const Data&, unsigned long&) const noexcept;

  // type Remove(argument) specifiers;
  bool Remove(unsigned long&, const Data&) noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
