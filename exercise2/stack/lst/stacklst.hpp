
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>, virtual protected List<Data> {
  // Must extend Stack<Data>,
  //             List<Data>

private:

  // ...

protected:

   using List<Data>::size;

  // ...

public:

  // Default constructor
  // StackLst() specifier;
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  // StackLst(argument) specifiers; // A stack obtained from a TraversableContainer
    explicit StackLst(const TraversableContainer<Data>&);

  // StackLst(argument) specifiers; // A stack obtained from a MappableContainer
    explicit StackLst(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // StackLst(argument);
    StackLst(const StackLst<Data>&);

  // Move constructor
  // StackLst(argument);
    StackLst(StackLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~StackLst() specifier;
    virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
    StackLst& operator=(const StackLst<Data>&);

  // Move assignment
  // type operator=(argument);
    StackLst& operator=(StackLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
    inline bool operator==(const StackLst<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
    inline bool operator!=(const StackLst<Data>&) const noexcept;

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

  // Specific member function (inherited from ClearableContainer)

    using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
