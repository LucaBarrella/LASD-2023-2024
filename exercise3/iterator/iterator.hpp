
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Iterator() specifiers
  virtual ~Iterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract is not possible.
  Iterator& operator=(const Iterator&) = delete;


  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  Iterator& operator=(Iterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  inline bool operator==(const Iterator& it) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  inline bool operator!=(const Iterator& it) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type operator*() specifiers; // (non-mutable version; concrete function must throw std::out_of_range when terminated)
  virtual const Data& operator*() const = 0;

  // type Terminated() specifiers; // (concrete function should not throw exceptions)
  virtual bool Terminated() const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutableIterator : public virtual Iterator<Data>{
  // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableIterator() specifiers
  virtual ~MutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  MutableIterator& operator=(const MutableIterator&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  MutableIterator& operator=(MutableIterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  inline bool operator==(const MutableIterator& it) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  inline bool operator!=(const MutableIterator& it) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type operator*() specifiers; // (mutable version; concrete function must throw std::out_of_range when terminated)
  virtual Data& operator*() = 0;

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : public virtual Iterator<Data>{
  // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ForwardIterator() specifiers
  virtual ~ForwardIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ForwardIterator& operator=(const ForwardIterator&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ForwardIterator& operator=(ForwardIterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  inline bool operator==(const ForwardIterator& it) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  inline bool operator!=(const ForwardIterator& it) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type operator++() specifiers; // (concrete function must throw std::out_of_range when terminated)
  virtual ForwardIterator& operator++() = 0;

};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator : public virtual Iterator<Data>{
  // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ResettableIterator() specifiers
  virtual ~ResettableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ResettableIterator& operator=(const ResettableIterator&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ResettableIterator& operator=(ResettableIterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  inline bool operator==(const ResettableIterator& it) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  inline bool operator!=(const ResettableIterator& it) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Reset() specifiers; // (concrete function should not throw exceptions)
  virtual void Reset() noexcept = 0;

};

/* ************************************************************************** */

}

#endif
