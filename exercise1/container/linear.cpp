#include <stdexcept>
namespace lasd {


/* ************************************************************************** */
    // Linear Container

    // Comparison operators

    // Equal operator
    template<typename Data>
    inline bool LinearContainer<Data>::operator==(const LinearContainer <Data> &con) const noexcept {
        if (size != con.size) {
            return false;
        }
        for (unsigned long i = 0; i<size; ++i) {
            if ((*this)[i] != con[i]) {
                return false;
            }
        }
        return true;
    }

    // Not equal operator
    template <typename Data>
    inline bool LinearContainer<Data>::operator!=(
        const LinearContainer<Data> &container
    ) const noexcept {
        return !(*this == container);
    }


    // Specific member function

    template <typename Data>
    inline Data &LinearContainer<Data>::Front() {
        if (size == 0) {
            throw std::length_error("The container is empty");
        }
        return operator[](0);
    }


    template <typename Data>
    inline const Data &LinearContainer<Data>::Front() const {
        if (size == 0) {
            throw std::length_error("The container is empty");
        }
        return operator[](0);
    }

    template <typename Data>
    inline Data &LinearContainer<Data>::Back() {
        if (size == 0) {
            throw std::length_error("The container is empty");
        }
        return operator[](size - 1);
    }

    template <typename Data>
    inline const Data &LinearContainer<Data>::Back() const {
        if (size == 0) {
            throw std::length_error("The container is empty");
        }
        return operator[](size - 1);
    }

    // Overrided Methods

    template <typename Data>
    inline void LinearContainer<Data>::Traverse(TraverseFun func) const {
        PreOrderTraverse(func);
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(const TraverseFun function) const {
        for (unsigned long i = 0; i < size; i++) {
            function(operator[](i));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(const TraverseFun function) const {
        for (unsigned long i = size; i > 0; i--) {
            function(operator[](i-1));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::Map(MapFun function) {
        PreOrderMap(function);
    }

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderMap(const MapFun function) {
        for (unsigned long i = 0; i < size; i++) {
            function((*this)[i]);
//            operator[](i) = function(operator[](i));
        }
    }

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderMap(const MapFun function) {
        for (unsigned long i = size - 1; i > 0; i--) {
            function(operator[](i));
        }
    }


    /* ************************************************************************** */
    // Sortable Linear Container

    // Comparison operators

    // Equal operator
    template <typename Data>
    inline bool SortableLinearContainer<Data>::operator==(
        const SortableLinearContainer<Data> &container) const noexcept {
        return LinearContainer<Data>::operator==(container);

    }

    // Not equal operator
    template <typename Data>
    inline bool SortableLinearContainer<Data>::operator!=(
        const SortableLinearContainer<Data> &container) const noexcept {
        return LinearContainer<Data>::operator!=(container);
    }

    // Specific member functions

    template <typename Data>
    inline void SortableLinearContainer<Data>::Sort() noexcept {
        HeapSort(0, size);
    }

    // HeapSort
    template <typename Data>
    inline void SortableLinearContainer<Data>::HeapSort(unsigned long i, unsigned long n) noexcept {
        for (long i = n / 2 - 1; i >= 0; i--) { // Modifica qui
            Heapify(i, n);
        }
        for (long i = n - 1; i > 0; i--) { // Modifica qui
            std::swap((*this)[0], (*this)[i]);
            Heapify(0, i);
        }
    }
    
    // Heapify
    template <typename Data>
    inline void SortableLinearContainer<Data>::Heapify(unsigned long i, unsigned long n) noexcept {
        unsigned long left = 2 * i + 1;
        unsigned long right = 2 * i + 2;
        unsigned long largest = i;
        if (left < n && (*this)[left] > (*this)[i]) {
            largest = left;
        }
        if (right < n && (*this)[right] > (*this)[largest]) {
            largest = right;
        }
        if (largest != i) {
            std::swap((*this)[i], (*this)[largest]);
            Heapify(largest, n);
        }
    }

    /* ************************************************************************** */
}
