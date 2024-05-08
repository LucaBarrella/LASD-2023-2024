
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>,
                      virtual public ClearableContainer {

  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // ...
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
  using BinaryTree<Data>::size;  

  struct NodeVec : virtual public MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...
    unsigned long index;
    unsigned long left;
    unsigned long right;
    // using BinaryTreeLnk<Data>::NodeLnk::value;
    Data value{};
    BinaryTreeVec<Data> *tree = nullptr;

    // lasd::Vector<NodeVec*> *tree;

    // Specific constructor

  public:

    // BinaryTreeVec *tree = nullptr;
    friend class BinaryTreeVec<Data>;

    // Default constructor
    NodeVec() = default;

    NodeVec(const Data&);
    NodeVec(Data&&);

    //! Specific constructor
    // NodeVec(const Data& value, bool isDummy, BinaryTreeVec *tree);

    // Copy constructor
    // NodeVec(NodeVec const& node);

    // Move constructor
    // NodeVec(NodeVec &&node) noexcept;

    // Destructor
    // ~NodeVec() = default;

    // Copy assignment
    // NodeVec& operator=(const NodeVec& node);

    // Move assignment
    // NodeVec& operator=(NodeVec &&node) noexcept;

    // Comparison operators
    // Equality operators
    // bool operator==(const NodeVec& node) const noexcept;

    // Inequality operators
    // bool operator!=(const NodeVec& node) const noexcept;

    // Specific member functions (inherited from MutableNode)

    using BinaryTree<Data>::Node::IsLeaf;

    virtual const Data& Element() const noexcept override;
    virtual Data& Element() noexcept override;

    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    // NodeVec& LeftChild() const override;
    // NodeVec& RightChild() const override;

    virtual const Node & RightChild() const override;
    virtual const Node & LeftChild() const override;

    virtual MutableNode & RightChild() override;
    virtual MutableNode & LeftChild() override;
    

    //! Auxiliary functions, if necessary!
    // virtual unsigned long index() const noexcept;

  };

  // NodeVec *Nodes = nullptr;
  // lasd::Vector<NodeVec*> containerP = lasd::Vector<NodeVec*>(0);

private:

  Vector<NodeVec*> treeVector;

public:

  // Default constructorß
  // BinaryTreeVec() specifiers;
  BinaryTreeVec() = default;
  
  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(const TraversableContainer<Data>& container);

  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MappableContainer<Data>&& container);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(const BinaryTreeVec<Data>& tree);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(BinaryTreeVec<Data>&& tree) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec& operator=(const BinaryTreeVec<Data>& tree);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec& operator=(BinaryTreeVec<Data>&& tree) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BinaryTreeVec<Data>& tree) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BinaryTreeVec<Data>& tree) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  virtual const Node& Root() const override;

  // const Data& Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  // Data& Root() override;
  virtual MutableNode& Root() override;

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
  inline void BreadthMap (MapFun) override;


protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
