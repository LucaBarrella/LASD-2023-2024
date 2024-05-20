
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class Vector : virtual public ResizableContainer, virtual public LinearContainer<Data> {

    private:
        // ...

    protected:
        using Container::size;

        Data *data{nullptr};

    public:
        // Default constructor
        Vector() = default;

        /* ************************************************************************ */

        // Specific constructors
        explicit Vector(const unsigned long initialSize) {
            size = initialSize;
            data = new Data[initialSize]();
        };
        Vector(const TraversableContainer<Data> &);
        Vector(MappableContainer<Data> &&);

        /* ************************************************************************ */

        // Copy constructor
        explicit Vector(const Vector<Data> &);

        // Move constructor
        explicit Vector(Vector<Data> &&) noexcept;

        /* ************************************************************************ */

        // Destructor
        virtual ~Vector();

        /* ************************************************************************ */

        // Copy assignment
        inline Vector<Data> &operator=(const Vector<Data> &);

        // Move assignment
        inline Vector<Data> &operator=(Vector<Data> &&) noexcept;

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const Vector<Data> &) const noexcept;
        inline bool operator!=(const Vector<Data> &) const noexcept;

        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        inline void Clear() override; // Override ClearableContainer member

        /* ************************************************************************ */

        // Specific member function (inherited from ResizableContainer)

        void Resize(unsigned long) override; // Override ResizableContainer member

        /* ************************************************************************ */

        // Specific member functions (inherited from LinearContainer)

        inline const Data &operator[](unsigned long) const override;
        inline Data &operator[](unsigned long) override;

        inline const Data &Front() const override;

        inline Data &Front() override;

        inline const Data &Back() const override;
        inline Data &Back() override;

    protected:
        // Auxiliary functions, if necessary!
    };

/* ************************************************************************** */

    template <typename Data>
    class SortableVector final : virtual public Vector<Data>,
                                 virtual public SortableLinearContainer<Data> {

    private:
        // ...

    protected:
        using Container::size;

    public:
        // Default constructor
        // SortableVector() specifiers;

        SortableVector() = default;

        /* ************************************************************************ */

        // Specific constructors
         SortableVector(const unsigned long);

         SortableVector(const TraversableContainer<Data> &);

         SortableVector(MappableContainer<Data> &&);

        /* ************************************************************************ */

        // Copy constructor
        inline SortableVector(const SortableVector<Data> &container);

        // Move constructor
        inline SortableVector(SortableVector<Data> &&container) noexcept;

        /* ************************************************************************ */

        // Destructor
        // ~SortableVector() specifiers;
        virtual ~SortableVector() = default;

        /* ************************************************************************ */

        // Copy assignment
        inline SortableVector<Data> &operator=(const SortableVector<Data> &container);


        // Move assignment
        inline SortableVector<Data> &operator=(SortableVector<Data> &&container) noexcept;

    protected:
        // Auxiliary functions, if necessary!
    };

/* ************************************************************************** */

} // namespace lasd

#include "vector.cpp"

#endif