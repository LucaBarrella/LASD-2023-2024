
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec  : virtual public MutableBinaryTree<Data>, 
                       virtual protected Vector<Data>, 
                       virtual public ClearableContainer {
  // Must extend MutableBinaryTree<Data>

private:

  // ...



public:

using typename BinaryTree<Data>::Node;
using typename MutableBinaryTree<Data>::MutableNode;
using typename BinaryTree<Data>::BinaryTree;
using typename MutableBinaryTree<Data>::MutableBinaryTree;

protected:

  // ...

  using Vector<Data>::size;
  using Vector<Data>::data;


  struct NodeVec : virtual public MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...
    Data value{};
    BinaryTreeVec *tree = nullptr;
    bool isDummy = false;

  public:

    // Default constructor
    NodeVec() = default;

    // Specific constructor
    NodeVec(const Data&, BinaryTreeVec *tree);
    NodeVec(Data&&, BinaryTreeVec *tree);

    // Constructor for Dummy Nodes
    NodeVec(BinaryTreeVec *tree); //???? Probly for dummy nodes

    // Copy Assignment
    NodeVec& operator=(const NodeVec&);

    // Move Assignment
    NodeVec& operator=(NodeVec&&) noexcept;

    // Destructor
    virtual ~NodeVec() = default;

    // Comparison operators

    // Equality operator
    inline bool operator==(const NodeVec&) const noexcept;

    // Inequality operator
    inline bool operator!=(const NodeVec&) const noexcept;

    // Specific member functions

    // Element const
    const Data& Element() const noexcept override;

    // Element mutable
    Data& Element() noexcept override;

    // IsLeaf
    using Node::IsLeaf;

    // HasLeftChild
    inline bool HasLeftChild() const noexcept override;

    // HasRightChild
    inline bool HasRightChild() const noexcept override;

    // LeftChild const version
    virtual const Node& LeftChild() const override;

    // LeftChild mutable version
    virtual MutableNode& LeftChild() override;

    // RightChild const version
    virtual const Node& RightChild() const override;

    // RightChild mutable version
    virtual MutableNode& RightChild() override;

    protected:

    //! Auxiliary functions, if necessary!

    virtual unsigned long index() const noexcept;
    
  };

  NodeVec *nodes = nullptr;

public:

  // Default constructor
  // BinaryTreeVec() specifiers;
  BinaryTreeVec() = default;


  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(const TraversableContainer<Data>&);

  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
  ~BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BinaryTreeVec&) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  const Node& Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  MutableNode& Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)
  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member

  using typename TraversableContainer<Data>::TraverseFun;
  inline void BreadthTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)
  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member

  using typename MappableContainer<Data>::MapFun;
  inline void BreadthMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
