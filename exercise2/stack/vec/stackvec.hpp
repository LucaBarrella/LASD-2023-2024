
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

#define DEFAULT_STACK_SIZE 10
#define RESIZE_FACTOR 2
#define SHRINK_FACTOR 0.25

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>, virtual protected Vector<Data>{
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  // ...

protected:

    using Vector<Data>::size;
    using Vector<Data>::data;
    unsigned long top = {0};

  // ...

public:

  // Default constructor
  // StackVec() specifier;
     StackVec();

  /* ************************************************************************ */

  // Specific constructor
  // StackVec(argument) specifiers; // A stack obtained from a TraversableContainer
    explicit StackVec(const TraversableContainer<Data>&);
  // StackVec(argument) specifiers; // A stack obtained from a MappableContainer
    explicit StackVec(MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  // StackVec(argument);
    explicit StackVec(const StackVec<Data>&);

  // Move constructor
  // StackVec(argument);
    explicit StackVec(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~StackVec() specifier;
    virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
    inline StackVec<Data>& operator=(const StackVec<Data>&);

  // Move assignment
  // type operator=(argument);
    inline StackVec<Data>& operator=(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
    inline bool operator==(const StackVec<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
    inline bool operator!=(const StackVec<Data>&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
    inline const Data& Top() const override;

  // type Top() specifiers; // Override Stack member (mutable version; must throw std::length_error when empty)
    inline Data& Top() override;

  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
    inline void Pop() override;

  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
    inline Data TopNPop() override;

  // type Push(argument) specifiers; // Override Stack member (copy of the value)
    inline void Push(const Data&) override;

  // type Push(argument) specifiers; // Override Stack member (move of the value)
    inline void Push(Data&&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
    inline bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
    inline unsigned long Size() const noexcept override;

  // Resize is not contemplated?
    inline void Resize(unsigned long) override;


  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
    inline void Clear() override;


protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
