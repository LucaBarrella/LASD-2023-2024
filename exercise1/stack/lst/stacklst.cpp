
namespace lasd {

/* ************************************************************************** */

    //Specific constructor from TraversableContainer
    template <typename Data>
    StackLst<Data>::StackLst(const TraversableContainer<Data>& container) : List<Data>::List(container) {}

    //Specific constructor from MappableContainer
    template <typename Data>
    StackLst<Data>::StackLst(MappableContainer<Data>&& container) : List<Data>::List(std::move(container)) {}

    //Copy constructor
    template <typename Data>
    StackLst<Data>::StackLst(const StackLst<Data>& stack) : List<Data>::List(stack) {}

    //Move constructor
    template <typename Data>
    StackLst<Data>::StackLst(StackLst<Data>&& stack) noexcept : List<Data>::List(std::move(stack)) {}

    //Copy assignment
    template <typename Data>
    inline StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stack) {
        List<Data>::operator=(stack);
        return *this;
    }

    //Move assignment
    template <typename Data>
    inline StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stack) noexcept {
        List<Data>::operator=(std::move(stack));
        return *this;
    }

    //Comparison operators

    //Eqauality operator
    template <typename Data>
    inline bool StackLst<Data>::operator==(const StackLst<Data>& stack) const noexcept {
        return List<Data>::operator==(stack);
    }

    //Inequality operator
    template <typename Data>
    inline bool StackLst<Data>::operator!=(const StackLst<Data>& stack) const noexcept {
        return !(*this == stack);
    }

    // Overrided methods

    //Top
    template <typename Data>
    inline Data& StackLst<Data>::Top() {
        if (!size) {
            throw std::length_error("The stack is empty");
        }
        return List<Data>::Front();
    }

    //Top (const)
    template <typename Data>
    inline const Data& StackLst<Data>::Top() const {
        if (!size) {
            throw std::length_error("The stack is empty");
        }
        return List<Data>::Front();
    }

    //Pop
    template <typename Data>
    inline void StackLst<Data>::Pop() {
        if (!size) {
            throw std::length_error("The stack is empty");
        }
        List<Data>::RemoveFromFront();
    }

    //TopNPop
    template <typename Data>
    inline Data StackLst<Data>::TopNPop() {
        if (!size) {
            throw std::length_error("The stack is empty");
        }
        return List<Data>::FrontNRemove();
    }

    //Push (copy)
    template <typename Data>
    void StackLst<Data>::Push(const Data& value) {
        List<Data>::InsertAtFront(value);
    }

    //Push (move)
    template <typename Data>
    void StackLst<Data>::Push(Data&& value) {
        List<Data>::InsertAtFront(std::move(value));
    }

/* ************************************************************************** */

}
