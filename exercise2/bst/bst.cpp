
namespace lasd {

/* ************************************************************************** */

// Constructor from TraversableContainer
template <typename Data>
BST<Data>::BST(const TraversableContainer<Data>& container) {
  container.Traverse([this](const Data &currData) { Insert(currData); });
}

// Constructor from MappableContainer
template <typename Data>
BST<Data>::BST(MappableContainer<Data>&& container) noexcept {
  container.Map([this](Data &currData) { Insert(std::move(currData)); });
}

// Copy constructor
template <typename Data>
BST<Data>::BST(const BST<Data>& binarySearchTree) : BinaryTreeLnk<Data>(binarySearchTree) {};

// Move constructor
template <typename Data>
BST<Data>::BST(BST<Data>&& binarySearchTree) noexcept : BinaryTreeLnk<Data>(std::move(binarySearchTree)) {};

// Copy assignment
template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& binarySearchTree) {
  BinaryTreeLnk<Data>::operator=(binarySearchTree);
  return *this;
}

// Move assignment
template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& binarySearchTree) noexcept {
  BinaryTreeLnk<Data>::operator=(std::move(binarySearchTree));
  return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool BST<Data>::operator==(const BST<Data>& binarySearchTree) const noexcept {
    if (Size() != binarySearchTree.Size()) {
        return false;
    }

    if (Size() == 0) {
        return true;
    }

    BTInOrderIterator<Data> it1(*this);
    BTInOrderIterator<Data> it2(binarySearchTree);
    while (!it1.IsEnded() && !it2.IsEnded()) {
        if (it1.Element() != it2.Element()) {
            return false;
        }
        ++it1;
        ++it2;
    }
    if (it1.Terminated() && it2.Terminated()) {
        return true;
    }
    return false;
}



/* ************************************************************************** */

}
