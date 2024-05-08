/* ************************************************************************** */

#include <algorithm>
#include <utility>

/* ************************************************************************** */

namespace lasd {

// Vector
/* ************************************************************************** */
    // Constructors

    //TraversableContainer
    template <typename Data>
    inline Vector<Data>::Vector(const TraversableContainer<Data> &container)
            : Vector(container.Size()) {
        unsigned long i{0};
        container.Traverse(
                [this, &i](const Data &currData) { data[i++] = currData; });
    }

    //MappableContainer
    template <typename Data>
    inline Vector<Data>::Vector(MappableContainer<Data> &&container)
        : Vector(container.Size()) {
        unsigned long i{0};
        container.Map(
            [this, &i](Data &currData) { std::swap(data[i++], currData); });
    }

    // Copy constructor
    template <typename Data>
    inline Vector<Data>::Vector(const Vector<Data> &vector) : Vector(vector.size) {
        for (unsigned long i = 0; i < size; i++) {
            data[i] = vector[i];
        }
    }

    // Move constructor
    template <typename Data>
    inline Vector<Data>::Vector(Vector<Data> &&vector) noexcept {
        std::swap(size, vector.size);
        std::swap(data, vector.data);
    }

    // Destructor
    template <typename Data>
    inline Vector<Data>::~Vector() {
        delete[] data;
    }
    // Operators

    // Copy assignment
    template <typename Data>
    inline Vector<Data> &Vector<Data>::operator=(const Vector<Data> &vector) {
        Vector<Data> temp{vector};
        std::swap(temp, *this);
        return *this;
    }

    // Move assignment
    template <typename Data>
    inline Vector<Data> &Vector<Data>::operator=(Vector<Data> &&vector) noexcept {
        std::swap(size, vector.size);
        std::swap(data, vector.data);
        return *this;
    }

    // Comparison operators

    // Equal to
    template <typename Data>
    inline bool Vector<Data>::operator==(const Vector<Data> &vector) const noexcept {
        if (size != vector.size) {
            return false;
        }

        for (unsigned long i = 0; i < size; i++) {
            if (data[i] != vector[i]) {
                return false;
            }
        }
        return true;
    }

    // Not equal to
    template <typename Data>
    inline bool Vector<Data>::operator!=(const Vector<Data> &vector) const noexcept {
        return !(*this == vector);
    }

    // Specific member functions

    // Clear
    template <typename Data>
    inline void Vector<Data>::Clear() {
        delete[] data;
        size = 0;
        data = nullptr;
    }

    // Resize
   template <typename Data>
    void Vector<Data>::Resize(unsigned long newSize) {
        if (newSize == size) {
            return;
        }

        if (newSize == 0) {
            Clear();
            return;
        }

        Data *newData = new Data[newSize];

        unsigned long minSize = std::min(size, newSize);

        for (unsigned long i = 0; i < minSize; i++) {
            std::swap(newData[i], data[i]);
        }

        if (newSize > size) {
            std::fill(newData + size, newData + newSize, Data());
        }

        delete[] data;
        data = newData;
        size = newSize;
    }

    // Specific member functions (inherited)

    // Lecture operators
    template <typename Data>
    inline const Data &Vector<Data>::operator[](unsigned long i) const {
        if (i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }

    // Write operators
    template <typename Data>
    inline Data &Vector<Data>::operator[](unsigned long i) {
        if (i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }

    // Front
    template <typename Data>
    inline const Data &Vector<Data>::Front() const {
        if (size == 0) {
            throw std::length_error("Empty vector");
        }
        return data[0];
    }

    template <typename Data>
    inline Data &Vector<Data>::Front() {
        if (size == 0) {
            throw std::length_error("Empty vector");
        }
        return data[0];
    }

    // Back
    template <typename Data>
    inline const Data &Vector<Data>::Back() const {
        if (size == 0) {
            throw std::length_error("Empty vector");
        }
        return data[size - 1];
    }

    template <typename Data>
    inline Data &Vector<Data>::Back() {
        if (size == 0) {
            throw std::length_error("Empty vector");
        }
        return data[size - 1];
    }

/* ************************************************************************** */

// Sortable Vector

    // Constructors

    // SortableVector with size
    template <typename Data>
    inline SortableVector<Data>::SortableVector(unsigned long size) : Vector<Data>(size){};

    // SortableVector from TraversableContainer
    template <typename Data>
    inline SortableVector<Data>::SortableVector(const TraversableContainer<Data> &container)
          : Vector<Data>(container){};

    // SortableVector from MappableContainer
    template <typename Data>
    inline SortableVector<Data>::SortableVector(MappableContainer<Data> &&container)
          : Vector<Data>(std::move(container)){};

    // Copy constructor
    template <typename Data>
    inline SortableVector<Data>::SortableVector(const SortableVector<Data> &container) : Vector<Data>(container) {}

    // Move constructor
    template <typename Data>
    inline SortableVector<Data>::SortableVector(SortableVector<Data> &&container) noexcept : Vector<Data>(std::move(container)) {}

    // Copy assignment
    template <typename Data>
    inline SortableVector<Data> &SortableVector<Data>::operator=(const SortableVector<Data> &vector) {
        Vector<Data>::operator=(vector);
        return *this;
    }

    // Move assignment
    template <typename Data>
    inline SortableVector<Data> &SortableVector<Data>::operator=(SortableVector<Data> &&vector) noexcept {
        Vector<Data>::operator=(std::move(vector));
        return *this;
    }

/* ************************************************************************** */
} // namespace lasd
