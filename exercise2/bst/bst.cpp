
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
    while (!it1.Terminated() && !it2.Terminated()) {
        if (*it1 != *it2) {
            return false;
        }
        ++it1;
        ++it2;
    }
    // Check if both iterators have terminated, if not, trees are not equal
    return it1.Terminated() && it2.Terminated();
}

// Inequality operator
template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& binarySearchTree) const noexcept {
    return !(*this == binarySearchTree);
}

// Min
template <typename Data>
const Data& BST<Data>::Min() const {
    if (Empty()) {  // If the tree's size is 0, is empty, for this reason we throw an exception
        throw std::length_error("Empty tree");
    }
    return FindPointerToMin(root)->Element();
}

// MinNRemove
template <typename Data>
Data BST<Data>::MinNRemove() {
    if (Empty()) {  
        throw std::length_error("Empty tree");
    }
    return DataNDelete(DetachMin(root));
}

// RemoveMin
template <typename Data>
void BST<Data>::RemoveMin() {
    if (Empty()) { 
        throw std::length_error("Empty tree");
    }
    delete DetachMin(root);
}

// Max
template <typename Data>
const Data& BST<Data>::Max() const {
    if (Empty()) { 
        throw std::length_error("Empty tree");
    }
    return FindPointerToMax(root)->Element();
}

// MaxNRemove
template <typename Data>
Data BST<Data>::MaxNRemove() {
    if (Empty()) { 
        throw std::length_error("Empty tree");
    }
    return DataNDelete(DetachMax(root));
}

// RemoveMax
template <typename Data>
void BST<Data>::RemoveMax() {
    if (Empty()) { 
        throw std::length_error("Empty tree");
    }
    delete DetachMax(root);
}

// Predecessor
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const {
    if (this->Empty()) { 
        throw std::length_error("Empty tree");
    }
    NodeLnk* const * tmp = FindPointerToPredecessor(root, data);
    if (tmp == nullptr) {
        throw std::out_of_range("Data not found");
    }
    return (*tmp)->Element();
}

// PredecessorNRemove
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& data) {
    if (Empty()) { 
        throw std::length_error("Empty tree");
    }
    NodeLnk **tmp = FindPointerToPredecessor(root, data);
    if (tmp == nullptr) { //! ATTENZIONE
        throw std::out_of_range("Data not found");
    }
    return DataNDelete(Detach(*tmp));
}

// RemovePredecessor
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& data) {
    if (Empty()) { 
        throw std::length_error("Empty tree"); //! ATTENZIONE!
    }
    NodeLnk ** tmp = FindPointerToPredecessor(root, data);
    if (tmp == nullptr) { //! ATTENZIONE
        throw std::out_of_range("Data not found");
    }
    delete Detach(*tmp);
}

// Successor
template <typename Data>
const Data& BST<Data>::Successor(const Data& data) const {
    if (Empty()) { 
        throw std::length_error("Empty tree"); //! ATTENZIONE!
    }
    NodeLnk* const *tmp = FindPointerToSuccessor(root, data);
    if (tmp == nullptr) {
        throw std::out_of_range("Data not found");
    }
    return (*tmp)->Element();
}

// SuccessorNRemove
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& data) {
    if (Empty()) { 
        throw std::length_error("Empty tree"); //! ATTENZIONE!
    }
    NodeLnk ** tmp = FindPointerToSuccessor(root, data);
    if (tmp == nullptr) { //! ATTENZIONE
        throw std::out_of_range("Data not found");
    }
    return DataNDelete(Detach(*tmp));
}

// RemoveSuccessor
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& data) {
    if (Empty()) { 
        throw std::length_error("Empty tree"); //! ATTENZIONE!
    }
    NodeLnk ** tmp = FindPointerToSuccessor(root, data);
    if (tmp == nullptr) { //! ATTENZIONE
        throw std::out_of_range("Data not found");
    }
    delete Detach(*tmp);
}

// Root const version
template <typename Data>
const typename BST<Data>::Node& BST<Data>::Root() const {
    if (Empty()) {
        throw std::length_error("The tree is empty");
    }
    return *root;
}

// Root mutable version
template <typename Data>
typename BST<Data>::MutableNode& BST<Data>::Root() {
    if (Empty()) {
        throw std::length_error("The tree is empty");
    }
    return *root;
}

// Insert copy version
template <typename Data>
bool BST<Data>::Insert(const Data& data) {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp) return false;
    tmp = new NodeLnk(data);
    size++;
    return true;
}

//Insert move version
template <typename Data>
bool BST<Data>::Insert(Data&& data) noexcept {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp) return false;
    tmp = new NodeLnk(std::move(data));
    size++;
    return true;
}

// Remove
template <typename Data>
bool BST<Data>::Remove(const Data& data) {
    NodeLnk *&tmp = FindPointerTo(root, data);
    if (tmp == nullptr) return false;
    delete Detach(tmp);
    return true;
}

// Exists
template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept {
    return FindPointerTo(root, data) != nullptr;
}

// Clear
template <typename Data>
void BST<Data>::Clear() noexcept {
    BinaryTreeLnk<Data>::Clear();
}

// DataNDelete
template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* node) {
    Data value {};
    std::swap(value, node->Element());
    delete node;
    return value;
}

// Detach 
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& node) noexcept {
    if (!Empty()) {
        if (!node->HasLeftChild()) {
            return Skip2Right(node);
        } else if (!node->HasRightChild()) {
            return Skip2Left(node);
        } else {
            NodeLnk* tmp = DetachMax(node->left);
            std::swap(node->Element(), tmp->Element());
            return tmp;
        }
    }
    return nullptr;
}

// DetachMin
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& node) noexcept {
    return Skip2Right(FindPointerToMin(node));
}

// DetachMax
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& node) noexcept {
    return Skip2Left(FindPointerToMax(node));
}

//! Skip2Right
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;

    if (node != nullptr) {
        std::swap(tmp, node->right);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}

//! Skip2Left
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if (node != nullptr) {
        std::swap(tmp, node->left);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}

//! FindPointerToMin const version
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMin(NodeLnk* const & node) const noexcept {
    NodeLnk* const * tmp = &node;
    NodeLnk* curr = node;
    if (curr != nullptr) {
        while (curr->HasLeftChild()) {
            tmp = &(curr->left);
            curr = curr->left;
        }
    }
    return *tmp;
}

// FindPointerToMin mutable version
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(node));
}


// FindPointerToMax const version
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMax(NodeLnk* const & node) const noexcept {
    NodeLnk* const * tmp = &node;
    NodeLnk* curr = node;
    if (curr != nullptr) {
        while (curr->HasRightChild()) {
            tmp = &(curr->right);
            curr = curr->right;
        }
    }
    return *tmp;
}
// FindPointerToMax mutable version
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(node));
}

//! FindPointerTo const version
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * tmp = &node;
    if(*tmp != nullptr) {
        if(node->Element() == data) {
            return *tmp;
        }
        else if(node->Element() < data) {
            tmp = &(FindPointerTo(node->right, data));
        }
        else {
            tmp = &(FindPointerTo(node->left, data));
        }
    }
    return *tmp;
}

// FindPointerTo mutable version
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(node, data));
}

//! FindPointerToPredecessor const version
template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToPredecessor(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * predecessor = nullptr;
    NodeLnk* const * current = &node;

    while (*current != nullptr && (*current)->Element() != data) {
        if ((*current)->Element() < data) {
            predecessor = current;
            current = &((*current)->right);
        } else {
            current = &((*current)->left);
        }
    }

    if (*current != nullptr && (*current)->HasLeftChild()) {
        return &FindPointerToMax((*current)->left);
    }

    return predecessor;
}

// FindPointerToPredecessor mutable version
template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(node, data));
}

//! FindPointerToSuccessor const version
template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToSuccessor(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * current = &node;
    NodeLnk* const * successor = nullptr;
    while(*current != nullptr && (*current)->Element() != data) {
        if((*current)->Element() > data) {
            successor = current;
            current = &((*current)->left);
        }
        else if((*current)->Element() < data) {
            current = &((*current)->right);
        }
    }
    if(*current != nullptr && (*current)->HasRightChild()) {
        return &FindPointerToMin((*current)->right);
    }
    return successor;
}


// FindPointerToSuccessor mutable version
template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(node, data));
}


/* ************************************************************************** */

} // namespace lasd