
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

// #include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp" 
// #include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>

// todo rimuovere tutti gli explicit!
// todo Inserire in ogni iteratore un puntatore al nodo corrente
// todo Cambiare nome alle funzioni ausiliarie  (es. getLeftMostLeaf)

class BinaryTree : virtual public PreOrderTraversableContainer<Data>,
                   virtual public PostOrderTraversableContainer<Data>,
                   virtual public InOrderTraversableContainer<Data>,
                   virtual public BreadthTraversableContainer<Data> {
  // Must extend PreOrderTraversableContainer<Data>,
  //             PostOrderTraversableContainer<Data>,
  //             InOrderTraversableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  struct Node {

  protected:

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    inline bool operator==(const Node& node) const noexcept;
    
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    inline bool operator!=(const Node& node) const noexcept;

  public:

    // friend class BinaryTree<Data>; //todo verificare se va bene!
    friend class BinaryTree<Data>;

    // Destructor 
    virtual ~Node() = default;

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.
    Node &operator=(const Node &node) = delete;

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.
    Node &operator=(Node &&node) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)
    virtual const Data& Element() const noexcept = 0;

    // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
    virtual bool IsLeaf() const noexcept = 0;

    // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0;

    // type HasRightChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0;

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual const Node& LeftChild() const = 0;

    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual const Node& RightChild() const = 0;

  };
  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  BinaryTree& operator=(const BinaryTree& tree) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  BinaryTree& operator=(BinaryTree&& tree) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree<Data>& tree) const noexcept;

  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator==(const BinaryTree<Data>& tree) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual const Node& Root() const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun function) const override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member
  inline void PreOrderTraverse (TraverseFun function) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member
  inline void PostOrderTraverse(TraverseFun function) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  // type InOrderTraverse(arguments) specifiers; // Override InOrderTraversableContainer member
  inline void InOrderTraverse(TraverseFun function) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)
  
  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
  inline void BreadthTraverse(TraverseFun function) const override;

protected:

  // Auxiliary functions, if necessary!

  // Auxiliary member functions for PreOrderTraversableContainer
  void PreOrderTraverse(const Node* node, TraverseFun function) const;

  // Auxiliary member functions for PostOrderTraversableContainer
  void PostOrderTraverse(const Node* node, TraverseFun function) const;

  // Auxiliary member functions for InOrderTraversableContainer
  void InOrderTraverse(const Node* node, TraverseFun function) const;

  // Auxiliary member functions for BreadthTraversableContainer
  void BreadthTraverse(const Node* node, TraverseFun function) const;

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public BinaryTree<Data>,
                          virtual public PreOrderMappableContainer<Data>,
                          virtual public PostOrderMappableContainer<Data>,
                          virtual public InOrderMappableContainer<Data>,
                          virtual public BreadthMappableContainer<Data>,
                          virtual public ClearableContainer {
  // Must extend ClearableContainer,
  //             BinaryTree<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>,
  //             InOrderMappableContainer<Data>,
  //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;
  using typename BinaryTree<Data>::Node;

public:

  struct MutableNode : public Node { //! Vedi se è giusto metter public
    // Must extend Node

    // friend class MutableBinaryTree<Data>;
    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~MutableNode() specifiers
    virtual ~MutableNode() = default;

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.
    MutableNode& operator=(const MutableNode& node) = delete;

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.
    MutableNode& operator=(MutableNode&& node) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
    virtual Data& Element() noexcept = 0;

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& LeftChild() = 0;

    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& RightChild() = 0;
    
  };

  /* ************************************************************************ */

  // Destructor
  // ~MutableBinaryTree() specifiers
  virtual ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  MutableBinaryTree& operator=(const MutableBinaryTree& tree) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  MutableBinaryTree& operator=(MutableBinaryTree&& tree) noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  
  virtual MutableNode& Root() = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member
  inline void Map(MapFun functionmap) override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  inline void PreOrderMap(MapFun functionmap) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  inline void PostOrderMap(MapFun functionmap) override;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Override InOrderMappableContainer member
  inline void InOrderMap(MapFun functionmap) override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  inline void BreadthMap(MapFun functionmap) override;

protected:

  // Auxiliary functions, if necessary!

  // Auxiliary member functions for PreOrderMappableContainer
  void PreOrderMap(MutableNode* node, MapFun functionmap);

  // Auxiliary member functions for PostOrderMappableContainer
  void PostOrderMap(MutableNode* node, MapFun functionmap);

  // Auxiliary member functions for InOrderMappableContainer
  void InOrderMap(MutableNode* node, MapFun functionmap);

  // Auxiliary member functions for BreadthMappableContainer
  void BreadthMap(MutableNode* node, MapFun functionmap);

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : public ForwardIterator<Data>,
                           public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  const typename BinaryTree<Data>::Node * root = nullptr;
  //const typename BinaryTree<Data>::Node * current = nullptr; //! Non serve?
  StackLst<const typename BinaryTree<Data>::Node *> stack; //! Perchè deve essere const typename?

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPreOrderIterator (const BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(const BTPreOrderIterator& iterator);

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(BTPreOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  virtual ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator& operator=(const BTPreOrderIterator& iterator);
  
  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator& operator=(BTPreOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTPreOrderIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPreOrderIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const override;

  // type Terminated() specifiers; // (should not throw exceptions)
  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTPreOrderIterator& operator++() override;
 
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : public MutableIterator<Data>,
                                  public BTPreOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTPreOrderIterator<Data>

private:

  // ...

protected:

  // ...
  //! Ha senso usare lo stack???
  using BTPreOrderIterator<Data>::stack;

public:

  // Specific constructors
  // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTPreOrderMutableIterator (MutableBinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator& iterator);

  // Move constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderMutableIterator() specifiers;
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPreOrderMutableIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BTPreOrderMutableIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : public ForwardIterator<Data>,
                            public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  const typename BinaryTree<Data>::Node * root = nullptr;
  StackLst<const typename BinaryTree<Data>::Node *> stack;
  //! typename BinaryTree<Data>::Node * current = nullptr; //! Non serve?

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPostOrderIterator (const BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(const BTPostOrderIterator& iterator);

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(BTPostOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
  virtual ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(const BTPostOrderIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(BTPostOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPostOrderIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BTPostOrderIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTPostOrderIterator &operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;


  // Auxiliary functions, if necessary!
  protected:
  void getLeftMostLeaf();

/* ************************************************************************** */
  
};

template <typename Data>
class BTPostOrderMutableIterator : public MutableIterator<Data>,
                                   public BTPostOrderIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTPostOrderIterator<Data>

private:

  // ...

protected:

  using BTPostOrderIterator<Data>::stack;

  // ...

public:

  // Specific constructors
  BTPostOrderMutableIterator(MutableBinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  // explicit BTPostOrderMutableIterator(const BTPostOrderMutableIterator& iterator);
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator& iterator);

  // Move constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  // explicit BTPostOrderMutableIterator(BTPostOrderMutableIterator&& iterator) noexcept;
  BTPostOrderMutableIterator(BTPostOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderMutableIterator() specifiers;
  virtual ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTPostOrderMutableIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPostOrderMutableIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : public ForwardIterator<Data>,
                          public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

  const typename BinaryTree<Data>::Node * root = nullptr;
  StackLst<const typename BinaryTree<Data>::Node *> stack;

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTInOrderIterator (const BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(const BTInOrderIterator& iterator);

  // Move constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(BTInOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
  virtual ~BTInOrderIterator() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(const BTInOrderIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(BTInOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTInOrderIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTInOrderIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const override;

  // type Terminated() specifiers; // (should not throw exceptions)
  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTInOrderIterator& operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

  // Auxiliary functions, if necessary!
  protected:
  void getLeftMostNode();

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : public MutableIterator<Data>,
                                 public BTInOrderIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTInOrderIterator<Data>

private:

  // ...

protected:

  using BTInOrderIterator<Data>::stack;

  // ...

public:

  // Specific constructors
  // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTInOrderMutableIterator(MutableBinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderMutableIterator(argument) specifiers;
  BTInOrderMutableIterator(const BTInOrderMutableIterator& iterator);

  // Move constructor
  // BTInOrderMutableIterator(argument) specifiers;
  BTInOrderMutableIterator(BTInOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderMutableIterator() specifiers;
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTInOrderMutableIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTInOrderMutableIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : public ForwardIterator<Data>,
                          public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  // const typename BinaryTree<Data>::root = nullptr;
  // QueueLst<BinaryTree<Data>::Node*> queue;
  const BinaryTree<Data>::Node* root = nullptr;
  QueueLst<const typename BinaryTree<Data>::Node*> queue;

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree
  BTBreadthIterator (const BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator(const BTBreadthIterator& iterator);

  // Move constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator(BTBreadthIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(const BTBreadthIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(BTBreadthIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTBreadthIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTBreadthIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const override;

  // type Terminated() specifiers; // (should not throw exceptions)
  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTBreadthIterator& operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : public MutableIterator<Data>,
                                 public BTBreadthIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTBreadthIterator<Data>

private:

  // ...

protected:

  using BTBreadthIterator<Data>::queue;

  // ...

public:

  // Specific constructors
  // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTBreadthMutableIterator(MutableBinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthMutableIterator(argument) specifiers;
  BTBreadthMutableIterator(const BTBreadthMutableIterator& iterator);

  // Move constructor
  // BTBreadthMutableIterator(argument) specifiers;
  BTBreadthMutableIterator(BTBreadthMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthMutableIterator() specifiers;
  virtual ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTBreadthMutableIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTBreadthMutableIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() override;

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
