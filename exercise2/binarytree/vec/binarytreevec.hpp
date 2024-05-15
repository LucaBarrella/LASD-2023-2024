
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : public virtual MutableBinaryTree<Data>, public virtual ClearableContainer{
  // Must extend MutableBinaryTree<Data>

private:

  // ...

public:
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
  using typename TraversableContainer<Data>::TraverseFun; 
  using typename MappableContainer<Data>::MapFun;


protected:

  using MutableBinaryTree<Data>::size;

  struct NodeVec : virtual public MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    Data info;
    ulong curr=0;
    Vector<NodeVec*> *tree = nullptr;

    //Default constructor
    NodeVec() = default;

    //Specific constructor
    NodeVec(const Data & data, ulong index, Vector<NodeVec*>* v) : info(data), curr(index), tree(v) {};

    //Destructor 
    virtual ~NodeVec() = default;

    //Copy assignment
    NodeVec & operator=(const NodeVec &);

    //Move assignment
    NodeVec & operator=(NodeVec &&) noexcept;

    //Comparison operators
    bool operator==(const NodeVec& node) const noexcept {
      return BinaryTree<Data>::Node::operator==(node);
    };

    bool operator!=(const NodeVec& node) const noexcept {
      return BinaryTree<Data>::Node::operator!=(node);
    };

    //Specific member functions
    const Data& Element() const noexcept override;
    Data& Element() noexcept override;
    bool IsLeaf() const noexcept override;
    bool HasRightChild() const noexcept override;
    bool HasLeftChild() const noexcept override;
    virtual const Node & RightChild() const override;
    virtual const Node & LeftChild() const override;
    virtual MutableNode & RightChild() override;
    virtual MutableNode & LeftChild() override;
  };

Vector<NodeVec*>* vec = nullptr;

public:

  // Default constructor
  // BinaryTreeVec() specifiers;
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(const TraversableContainer<Data> &); 
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MappableContainer<Data> &&) noexcept;

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
  virtual ~BinaryTreeVec();

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
  bool operator==(const BinaryTreeVec<Data>& btv) const noexcept {
    return MutableBinaryTree<Data>::operator==(btv);
  };
  // type operator!=(argument) specifiers;
  bool operator!=(const BinaryTreeVec<Data>& btv) const noexcept {
    return !(*this == btv);
  };
  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)
  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  const Node & Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)
  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  MutableNode & Root() override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)
  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)
  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
  inline void BreadthTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)
  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  inline void BreadthMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
