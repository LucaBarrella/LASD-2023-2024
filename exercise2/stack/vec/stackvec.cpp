
namespace lasd {

/* ************************************************************************** */

    // Default constructor
    template <typename Data>
    StackVec<Data>::StackVec() : Vector<Data>::Vector(DEFAULT_STACK_SIZE) {}

    // Specific constructor from a Traversable container
    template <typename Data>
    StackVec<Data>::StackVec(const TraversableContainer<Data>& container) : Vector<Data>::Vector(container), top(container.Size()) {
        if (size < DEFAULT_STACK_SIZE) {
            Resize(DEFAULT_STACK_SIZE);
        }
    }

    // Specific constructor from a Mappable container
    template <typename Data>
    StackVec<Data>::StackVec(MappableContainer<Data>&& container) : Vector<Data>::Vector(std::move(container)), top(container.Size()) {
        if (size < DEFAULT_STACK_SIZE) {
            Resize(DEFAULT_STACK_SIZE);
        }
    }

    // Copy constructor
    template <typename Data>
    StackVec<Data>::StackVec(const StackVec<Data>& stack) : Vector<Data>::Vector(stack), top(stack.top) {}

    // Move constructor
    template <typename Data>
    StackVec<Data>::StackVec(StackVec<Data>&& stack) noexcept : Vector<Data>::Vector(std::move(stack)) {
        std::swap(top, stack.top);
    }

    // Destructor

    // Copy assignment
    template <typename Data>
    inline StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stack) {
        Vector<Data>::operator=(stack);
        top = stack.top;
        return *this;
    }

    // Move assignment
    template <typename Data>
    inline StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stack) noexcept {
        Vector<Data>::operator=(std::move(stack));
        std::swap(top, stack.top);
        return *this;
    }

    // Comparison operators

    //Equal to
    template <typename Data>
    inline bool StackVec<Data>::operator==(const StackVec<Data>& stack) const noexcept {
        if (top != stack.top) {
            return false;
        }
        for (unsigned long i = 0; i < top; i++) {
            if (data[i] != stack.data[i]) {
                return false;
            }
        }
        return true;
    }



    //Not equal to
    template <typename Data>
    inline bool StackVec<Data>::operator!=(const StackVec<Data>& stack) const noexcept {
        return !(*this == stack);
    }

    // Ovverrided methods

    //Top
    template <typename Data>
    inline const Data& StackVec<Data>::Top() const {
        if (Empty()) {
            throw std::length_error("Stack is empty");
        }
        return data[top - 1];
    }

    //Top mutable
    template <typename Data>
    inline Data& StackVec<Data>::Top() {
        if (Empty()) {
            throw std::length_error("Stack is empty");
        }
        return data[top - 1];
    }

    //Pop
    template <typename Data>
    inline void StackVec<Data>::Pop() {
        if (Empty()) {
            throw std::length_error("Stack is empty");
        }
        if (top-- < size * SHRINK_FACTOR) {
            Resize(size / RESIZE_FACTOR);
        }
    }

    //TopNPop
    template <typename Data>
    inline Data StackVec<Data>::TopNPop() {
        if (Empty()) {
            throw std::length_error("Stack is empty");
        }
        return data[--top];
    }

    //Push copy
    template <typename Data>
    inline void StackVec<Data>::Push(const Data& value) {
        if (top == size) {
            Resize(size * RESIZE_FACTOR);
        }
        data[top++] = value;
    }

    //Push move
    template <typename Data>
    inline void StackVec<Data>::Push(Data&& value) {
        if (top == size) {
            Resize(size * RESIZE_FACTOR);
        }
        data[top++] = std::move(value);
    }

    //Empty
    template <typename Data>
    inline bool StackVec<Data>::Empty() const noexcept {
        return top == 0;
    }

    //Size
    template <typename Data>
    inline unsigned long StackVec<Data>::Size() const noexcept {
        return top;
    }

    //Clear
    template <typename Data>
    inline void StackVec<Data>::Clear() {
        Resize(DEFAULT_STACK_SIZE);
        top = 0;
    }

    //Resize
    template <typename Data>
    inline void StackVec<Data>::Resize(unsigned long newSize) {
        if (DEFAULT_STACK_SIZE < newSize) {
            Vector<Data>::Resize(newSize);
        }
    }

/* ************************************************************************** */

}
