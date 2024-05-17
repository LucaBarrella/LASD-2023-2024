
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : public BinaryTreeLnk<Data>,
            public BinaryTree<Data>,
            public DictionaryContainer<Data>,
            public ClearableContainer {
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;
  using BinaryTree<Data>::size;
  using BinaryTreeLnk<Data>::root;
  using typename BinaryTreeLnk<Data>::NodeLnk;


//   //! Copyed from Luca's code
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
// //!   using BinaryTreeLnk<Data>::size;


  // ...

public:

  // Default constructor
  // BST() specifiers;
  BST() = default;

//   /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a TraversableContainer
  BST(const TraversableContainer<Data>&);

  // BST(argument) specifiers; // A bst obtained from a MappableContainer
  BST(MappableContainer<Data>&&) noexcept;

//   /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;
  BST(const BST&);

  // Move constructor
  // BST(argument) specifiers;
  BST(BST&&) noexcept;

//   /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;
  virtual ~BST() = default;

//   /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BST& operator=(const BST&);

  // Move assignment
  // type operator=(argument) specifiers;
  BST& operator=(BST&&) noexcept;

//   /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BST&) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BST&) const noexcept;

//   /* ************************************************************************ */

  // Specific member functions

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
//   const Data& Min() const;

  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
//   Data MinNRemove();

  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
//   void RemoveMin();

  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
//   const Data& Max() const;

  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
//   Data MaxNRemove();

  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
//   void RemoveMax();

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
//   const Data& Predecessor(const Data&) const;

  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
//   Data PredecessorNRemove(const Data&);

  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
//   void RemovePredecessor(const Data&);

  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
//   const Data& Successor(const Data&) const;

  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
//   Data SuccessorNRemove(const Data&);

  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
//   void RemoveSuccessor(const Data&);

//   /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  // type Root(argument) specifiers; // Override BinaryTree member
//   const Data& Root() const override;

//   /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
//   bool Insert(const Data&) override;

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
//   bool Insert(Data&&) override;

  // type Remove(argument) specifiers; // Override DictionaryContainer member
//   bool Remove(const Data&) override;

//   /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
//   bool Exists(const Data&) const noexcept override;

//   /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear(argument) specifiers; // Override ClearableContainer membe
//   virtual void Clear() noexcept override;

// protected:

  // Auxiliary functions, if necessary!

  // type DataNDelete(argument) specifiers;
  // Data DataNDelete(NodeLnk*);

  // type Detach(argument) specifiers;
//   NodeLnk* Detach(NodeLnk* &) noexcept;

  // type DetachMin(argument) specifiers;
//   NodeLnk* DetachMin(NodeLnk* &) noexcept;

  // type DetachMax(argument) specifiers;
//   NodeLnk* DetachMax(NodeLnk* &) noexcept;

  // type Skip2Left(argument) specifiers;
//   NodeLnk* Skip2Left(NodeLnk* &) noexcept;

  // type Skip2Right(argument) specifiers;
//   NodeLnk* Skip2Right(NodeLnk* &) noexcept;

  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
//   NodeLnk* &FindPointerToMin(NodeLnk* &) noexcept;

//   NodeLnk* const &FindPointerToMin(NodeLnk* const &) const noexcept; 

  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions
//   NodeLnk* FindPointerToMax(NodeLnk*) const noexcept;

  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions
//   NodeLnk* FindPointerTo(const Data&, NodeLnk*) const noexcept;

  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
//   NodeLnk* FindPointerToPredecessor(const Data&, NodeLnk*) const noexcept;

  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions
//   virtual NodeLnk** FindPointerToSuccessor(const Data&, NodeLnk*&) noexcept;


};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
