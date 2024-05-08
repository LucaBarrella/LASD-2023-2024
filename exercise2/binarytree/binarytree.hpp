
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

  // ...

  //using BreadthMappableContainer<Data>::size;
  using Container::size;
public:

  struct Node {

  protected:

    Data value{}; //! Suppongo serva

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    inline bool operator==(const Node& node) const noexcept;
    
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    inline bool operator!=(const Node& node) const noexcept;

  public:

    // friend class BinaryTree<Data>; //todo verificare se va bene!
    friend class BinaryTree<Data>;

    // Default constructor
    Node() = default;

    // Specific constructors 

    // Copy Data constructor
    Node(const Data& data);

    // Move Data constructor
    Node(Data&& data) noexcept;

    //! NOT NECESSARY, PROBABLY.

    // // Copy constructor    
    Node(const Node& node);

    // // Move constructor
    // Node(Node&&) noexcept;

    // Destructor 
    ~Node() = default;

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
  // Constructors???
  BinaryTree() = default;

  //! Copy constructor
  // BinaryTree(const BinaryTree&) = default;

  //! Move constructor
  // BinaryTree(BinaryTree&&) = default;

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
  virtual bool operator!=(const BinaryTree<Data>& tree) const noexcept;

  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
  virtual bool operator==(const BinaryTree<Data>& tree) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual const Node& Root() const = 0; //! Attento!

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;
  //! CONTROLLARE!!!

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
  void PreOrderTraverse(Node* node, TraverseFun function) const;

  // Auxiliary member functions for PostOrderTraversableContainer
  void PostOrderTraverse(Node* node, TraverseFun function) const;

  // Auxiliary member functions for InOrderTraversableContainer
  void InOrderTraverse(Node* node, TraverseFun function) const;

  // Auxiliary member functions for BreadthTraversableContainer
  void BreadthTraverse(Node* node, TraverseFun function) const;

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public BinaryTree<Data>,
                          //! Serve? virtual public MappableContainer<Data>,
                          virtual public PreOrderMappableContainer<Data>,
                          virtual public PostOrderMappableContainer<Data>,
                          virtual public InOrderMappableContainer<Data>,
                          virtual public BreadthMappableContainer<Data>{
  // Must extend ClearableContainer,
  //             BinaryTree<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>,
  //             InOrderMappableContainer<Data>,
  //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  struct MutableNode : public BinaryTree<Data>::Node {
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
    //! Vedi perchè sono virtuali

    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
    using BinaryTree<Data>::Node::Element;
    virtual Data& Element() noexcept = 0;

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    using BinaryTree<Data>::Node::LeftChild;
    virtual MutableNode& LeftChild() = 0;

    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    using BinaryTree<Data>::Node::RightChild;
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
  
  //! Vedi se è giusto metter solo using
  using BinaryTree<Data>::Root;
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
  //! CONTROLLARE!!! Chiedi a Fab domani!

  // Auxiliary member functions for PreOrderMappableContainer
  void PreOrderMap(MutableNode* node, MapFun functionmap);

  // Auxiliary member functions for PostOrderMappableContainer
  void PostOrderMap(MutableNode* node, MapFun functionmap);

  // Auxiliary member functions for InOrderMappableContainer
  void InOrderMap(MutableNode* node, MapFun functionmap);

  // Auxiliary member functions for BreadthMappableContainer
  void BreadthMap(MutableNode* node, MapFun functionmap);


  //todo cancella sta monnezza nel caso:
  // Auxiliary member functions for PreOrderMappableContainer
  // virtual void PreOrderMap(MapFun functionmap, MutableNode& node) const;

  // // Auxiliary member functions for PostOrderMappableContainer
  // virtual void PostOrderMap(MapFun functionmap, MutableNode& node) const;

  // // Auxiliary member functions for InOrderMappableContainer
  // virtual void InOrderMap(MapFun functionmap, MutableNode& node) const;

  // // Auxiliary member functions for BreadthMappableContainer
  // virtual void BreadthMap(MapFun functionmap, MutableNode& node) const;

  // using BinaryTree<Data>::PreOrderTraverse;
  // using BinaryTree<Data>::PostOrderTraverse;
  // using BinaryTree<Data>::InOrderTraverse;
  // using BinaryTree<Data>::BreadthTraverse;

  // void PreOrderTraverse(std::function<void(Data&)> function) override;
  // void PostOrderTraverse(std::function<void(Data&)> function) override;
  // void InOrderTraverse(std::function<void(Data&)> function) override;
  // void BreadthTraverse(std::function<void(Data&)> function) override;

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
  const typename BinaryTree<Data>::Node * root = nullptr; //! Devono essere const?
  StackLst<const typename BinaryTree<Data>::Node *> stack; //! Devono essere const typename?

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
  explicit BTPreOrderIterator (const BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  explicit BTPreOrderIterator(const BTPreOrderIterator& iterator);

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  explicit BTPreOrderIterator(BTPreOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  virtual ~BTPreOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  virtual BTPreOrderIterator& operator=(const BTPreOrderIterator& iterator);
  

  // Move assignment
  // type operator=(argument) specifiers;
  virtual BTPreOrderIterator& operator=(BTPreOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  virtual bool operator==(const BTPreOrderIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  virtual bool operator!=(const BTPreOrderIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  virtual Data& operator*() const override; //! Should be overrided method?
  //!devi solo fare l’override nella succ: operatore* con una const_cast

  // type Terminated() specifiers; // (should not throw exceptions)
  virtual bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  virtual BTPreOrderIterator& operator++() override;
 
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  virtual void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : public MutableIterator<Data>,
                                  public BTPreOrderIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTPreOrderIterator<Data>

private:

  // ...

protected:

  // ...
    //! typename BinaryTree<Data>::Node * root = nullptr;
    //! StackLst<typename BinaryTree<Data>::Node *> stack;
  using BTPreOrderIterator<Data>::stack;

public:

  // Specific constructors
  // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  explicit BTPreOrderMutableIterator (BinaryTree<Data>& tree);


  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  explicit BTPreOrderMutableIterator(const BTPreOrderMutableIterator& iterator);

  // Move constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  explicit BTPreOrderMutableIterator(BTPreOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  //! Destructor
  // ~BTPreOrderMutableIterator() specifiers;
  virtual ~BTPreOrderMutableIterator() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  virtual BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  virtual BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  virtual bool operator==(const BTPreOrderMutableIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  virtual bool operator!=(const BTPreOrderMutableIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  virtual Data& operator*() const;
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

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree
  explicit BTPostOrderIterator (const BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;
  explicit BTPostOrderIterator(const BTPostOrderIterator& iterator);

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
  explicit BTPostOrderIterator(BTPostOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
  // virtual ~BTPostOrderIterator() noexcept;
  virtual ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  virtual BTPostOrderIterator& operator=(const BTPostOrderIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  virtual BTPostOrderIterator& operator=(BTPostOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  virtual bool operator==(const BTPostOrderIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  virtual bool operator!=(const BTPostOrderIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  virtual Data& operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  //! virtual bool Terminated() const noexcept;
  using BTPreOrderIterator<Data>::Terminated;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  virtual BTPostOrderIterator& operator++();

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  virtual void Reset() noexcept;

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

  // ...
  using BTPostOrderIterator<Data>::stack;

public:

  // Specific constructors
  // BTPostOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  explicit BTPostOrderMutableIterator (BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  explicit BTPostOrderMutableIterator(const BTPostOrderMutableIterator& iterator);

  // Move constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  explicit BTPostOrderMutableIterator(BTPostOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderMutableIterator() specifiers;
  virtual ~BTPostOrderMutableIterator() noexcept;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  virtual BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  virtual BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  virtual bool operator==(const BTPostOrderMutableIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  virtual bool operator!=(const BTPostOrderMutableIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  virtual Data& operator*() const;

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
  explicit BTInOrderIterator (const BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
  explicit BTInOrderIterator(const BTInOrderIterator& iterator);

  // Move constructor
  // BTInOrderIterator(argument) specifiers;
  explicit BTInOrderIterator(BTInOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
  virtual ~BTInOrderIterator() noexcept;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  virtual BTInOrderIterator& operator=(const BTInOrderIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  virtual BTInOrderIterator& operator=(BTInOrderIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  virtual bool operator==(const BTInOrderIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  virtual bool operator!=(const BTInOrderIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  virtual Data& operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  virtual bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  virtual BTInOrderIterator& operator++();

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  virtual void Reset() noexcept;

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

  // ...

public:

  // Specific constructors
  // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  explicit BTInOrderMutableIterator (BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderMutableIterator(argument) specifiers;
  explicit BTInOrderMutableIterator(const BTInOrderMutableIterator& iterator);

  // Move constructor
  // BTInOrderMutableIterator(argument) specifiers;
  explicit BTInOrderMutableIterator(BTInOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderMutableIterator() specifiers;
  virtual ~BTInOrderMutableIterator() noexcept;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  virtual BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  virtual BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  virtual bool operator==(const BTInOrderMutableIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  virtual bool operator!=(const BTInOrderMutableIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  virtual Data& operator*() const;

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
  explicit BTBreadthIterator (const BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;
  explicit BTBreadthIterator(const BTBreadthIterator& iterator);

  // Move constructor
  // BTBreadthIterator(argument) specifiers;
  explicit BTBreadthIterator(BTBreadthIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
  virtual ~BTBreadthIterator() noexcept;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  virtual BTBreadthIterator& operator=(const BTBreadthIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  virtual BTBreadthIterator& operator=(BTBreadthIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  virtual bool operator==(const BTBreadthIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  virtual bool operator!=(const BTBreadthIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  virtual Data& operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  virtual bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  virtual BTBreadthIterator& operator++();

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  virtual void Reset() noexcept;

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

  // ...

public:

  // Specific constructors
  // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  explicit BTBreadthMutableIterator (BinaryTree<Data>& tree);

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthMutableIterator(argument) specifiers;
  explicit BTBreadthMutableIterator(const BTBreadthMutableIterator& iterator);

  // Move constructor
  // BTBreadthMutableIterator(argument) specifiers;
  explicit BTBreadthMutableIterator(BTBreadthMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthMutableIterator() specifiers;
  virtual ~BTBreadthMutableIterator() noexcept;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  virtual BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator& iterator);

  // Move assignment
  // type operator=(argument) specifiers;
  virtual BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&& iterator) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  virtual bool operator==(const BTBreadthMutableIterator& iterator) const noexcept;

  // type operator!=(argument) specifiers;
  virtual bool operator!=(const BTBreadthMutableIterator& iterator) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  virtual Data& operator*() const;

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
