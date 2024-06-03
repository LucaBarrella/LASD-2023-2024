
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../bst/bst.hpp"
#include "../../vector/vector.hpp"
#define DEFAULT_TABLE_SIZE 128
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::GetTableSize;
  using HashTable<Data>::AdjustTableSize;
  Vector<BST<Data>> table; //! Oppure convine usare un puntatore a un vettore di BST?

  // type getTableSize() specifiers;
  unsigned long GetTableSize() const noexcept override;

public:

  using DictionaryContainer<Data>::InsertAll;
  

  // ...

  // Default constructor
  // HashTableClsAdr() specifiers;
  HashTableClsAdr();

  /* ************************************************************************ */

  // Specific constructors
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  HashTableClsAdr(const unsigned long newTableSize);

  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableClsAdr(const TraversableContainer<Data>& container);

  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(const unsigned long newTableSize, const TraversableContainer<Data>& container);

  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableClsAdr(MappableContainer<Data>&& container);

  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableClsAdr(const unsigned long newTableSize, MappableContainer<Data>&& container);

  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(const HashTableClsAdr<Data>&);

  // Move constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableClsAdr() specifiers;
  ~HashTableClsAdr();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr<Data>& operator=(const HashTableClsAdr<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr<Data>& operator=(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const HashTableClsAdr<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const HashTableClsAdr<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(const Data&) override;

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  virtual bool Insert(Data&&) override;

  // type Remove(argument) specifiers; // Override DictionaryContainer member
  virtual bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  virtual bool Exists(const Data&) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  virtual void Resize(const unsigned long newTableSize) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member
  virtual void Clear() override;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
