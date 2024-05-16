
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data>,
                      virtual public  ClearableContainer {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
  using Container::size;

  // ...

  struct NodeLnk : public MutableNode  { // Must extend MutableNode

  private:

    // ...

  protected:
    
    // friend class BinaryTreeLnk<Data>; // ! WRONG!
 
    // ...

  public:

    // ...
    Data value{};
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;

    // Default constructor
    NodeLnk() = default;

    // Specific constructor
    NodeLnk(const Data&);
    NodeLnk(Data&&) noexcept;

    // Copy constructor
    NodeLnk(const NodeLnk&);

    // Move constructor
    NodeLnk(NodeLnk&&) noexcept;

    //Copy assignment
    NodeLnk& operator=(const NodeLnk&);

    //Move assignment
    NodeLnk& operator=(NodeLnk&&) noexcept;

    // Comparison operators

    // type operator==(argument) specifiers;
    bool operator==(const NodeLnk&) const noexcept;

    // type operator==(argument) specifiers;
    bool operator!=(const NodeLnk&) const noexcept;

    // Destructor
    virtual ~NodeLnk();

    inline const Data& Element() const noexcept override;
    inline Data& Element() noexcept override;

    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    virtual const Node & RightChild() const override;
    virtual const Node & LeftChild() const override;

    virtual MutableNode & RightChild() override;
    virtual MutableNode & LeftChild() override;

    bool IsLeaf() const noexcept override;   
    // using Node::IsLeaf; //FIXME Colpa sua????

  };
  
  NodeLnk* root = nullptr;
  
  // Auxiliary member functions
  protected:
  void DeleteTree(NodeLnk*&) noexcept;
  NodeLnk* CopyTree(NodeLnk*);

  // void Insert (const Data&, NodeLnk*&);

public:

  //! Attento!!!
  using Container::Size;
  using Container::Empty; //! Sicuro che vada così?

  // Default constructor
  // BinaryTreeLnk() specifiers;
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(const TraversableContainer<Data>&);

  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeLnk(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // using MutableBinaryTree<Data>::MutableNode::operator==;

  inline bool operator==(const BinaryTreeLnk&) const noexcept;

  // type operator!=(argument) specifiers;
  // using MutableBinaryTree<Data>::MutableNode::operator!=;

  inline bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // Override BinaryTree member (throw std::length_error when empty)
  const Node& Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  MutableNode& Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif