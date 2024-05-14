
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

#define DEFAULT_QUEUE_SIZE 10 //! MUST BE > 0
#define RESIZE_FACTOR 2 //! MUST BE > 1
#define SHRINK_FACTOR 0.25 //! MUST BE > 0 AND < 1

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>, virtual protected Vector<Data> {
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

    using Vector<Data>::size;
    using Vector<Data>::data;
    unsigned long head{0}, tail{0}, elemInQueue {0};
  // ...

public:

  // Default constructor
    QueueVec();

  // QueueVec() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
    explicit QueueVec(const TraversableContainer<Data>&);

    // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer
    explicit QueueVec(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);
    QueueVec(const QueueVec<Data>&);

  // Move constructor
  // QueueVec(argument);
    QueueVec(QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
    QueueVec<Data>& operator=(const QueueVec<Data>&);

  // Move assignment
  // type operator=(argument);
    QueueVec<Data>& operator=(QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
    inline bool operator==(const QueueVec<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
    inline bool operator!=(const QueueVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
    inline const Data& Head() const override;

  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
    inline Data& Head() override;

  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
    inline void Dequeue() override;

  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
    inline Data HeadNDequeue() override;

  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
    inline void Enqueue(const Data&) override;

  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
    inline void Enqueue(Data&&) override;


  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
    inline bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
    inline unsigned long Size() const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
    inline void Clear() override;

    inline void Resize(unsigned long newSize) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
