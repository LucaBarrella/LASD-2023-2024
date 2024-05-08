
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer, virtual public LinearContainer<Data>, virtual public DictionaryContainer<Data>{
  // Must extend ClearableContainer,
  //             LinearContainer<Data>,
  //             DictionaryContainer<Data>

private:

  // ...

protected:

    using Container::size;

    struct Node {

        Data value{};

        Node* next = nullptr;

        Node () = default;

        /* ********************************************************************** */

        // Specific constructors

        Node(const Data &);

        Node(Data &&) noexcept;

        /* ********************************************************************** */

        // Copy constructor

        Node(const Node &);

        // Move constructor

        Node(Node &&) noexcept;

        /* ********************************************************************** */

        // Destructor

        virtual ~Node();
        //virtual ~Node() = default; todo POTREBBE CAUSARE PROBLEMI?

        /* ********************************************************************** */

        // Comparison operators

        bool operator==(const Node &) const noexcept;

        bool operator!=(const Node &) const noexcept;

        /* ********************************************************************** */

        // Specific member functions

        // ...

    };

    Node* head = nullptr;
    Node* tail = nullptr;

  // ...

public:

  // Default constructor
  // List() specifiers;
    List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
    List(const TraversableContainer<Data>&);
  // List(argument) specifiers; // A list obtained from a MappableContainer
    List(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
    List(const List&);

  // Move constructor
  // List(argument) specifiers;
    List(List&&);

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
    virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
    inline List& operator=(const List&);

  // Move assignment
  // type operator=(argument) specifiers;
    inline List& operator=(List&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
    inline bool operator==(const List&) const noexcept;
  // type operator!=(argument) specifiers;
    inline bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
    void InsertAtFront(const Data&);

  // type InsertAtFront(argument) specifier; // Move of the value
    void InsertAtFront(Data&&);

  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
    void RemoveFromFront();

  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
    Data FrontNRemove();

  // type InsertAtBack(argument) specifier; // Copy of the value
    void InsertAtBack(const Data&);

  // type InsertAtBack(argument) specifier; // Move of the value
    void InsertAtBack(Data&&);

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
    inline void Clear() override;

    using TestableContainer<Data>::Exists;
    /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifier; // Copy of the value
    inline bool Insert(const Data&) override;

  // type Insert(argument) specifier; // Move of the value
    inline bool Insert(Data&&) override;

  // type Remove(argument) specifier;
    inline bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
    inline const Data& operator[](unsigned long) const override;

  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
    inline Data& operator[](unsigned long) override;

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
    inline const Data& Front() const override;

  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
    inline Data& Front() override;

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
    inline const Data& Back() const override;

  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
    inline Data& Back() override;

  /* ************************************************************************ */

    using typename TraversableContainer<Data>::TraverseFun;

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

    inline void Traverse(TraverseFun) const override;

    /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member

    inline void PreOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member

    inline void PostOrderTraverse (TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member

    inline void Map (MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

    inline void PreOrderMap (MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

    inline void PostOrderMap (MapFun) override;

protected:

  // Auxiliary functions, if necessary! //todo da rifare 99/100!

    void PreOrderTraverse(Node*, TraverseFun) const;

    void PostOrderTraverse(Node*, TraverseFun) const;

    void PreOrderMap(Node*, MapFun) const;

    void PostOrderMap(Node*, MapFun) const;
    
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
