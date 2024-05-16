
namespace lasd {

/* ************************************************************************** */

// ...

// NodeLnk

// Specific constructors

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& data) : value{data} {}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& data) noexcept : value{std::move(data)} {}

// Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& node) : value{node.value} {
    if (node.HasLeftChild()) {
        left = new NodeLnk(node.LeftChild());
    }
    if (node.HasRightChild()) {
        right = new NodeLnk(node.RightChild());
    }
}

// Move constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& node) noexcept : value{std::move(node.value)}, left{std::move(node.left)}, right{std::move(node.right)} {}

// Copy Assignment
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& node) {
    if (this != &node) {
        value = node.value;
        if (HasLeftChild()) {
            delete left;
        }
        if (node.HasLeftChild()) {
            left = new NodeLnk(node.LeftChild());
        }
        if (HasRightChild()) {
            delete right;
        }
        if (node.HasRightChild()) {
            right = new NodeLnk(node.RightChild());
        }
    }
    return *this;
}

// Move Assignment
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept {
    if (this != &node) {

        //todo ATTENTO!!! NECESSARIO PER IL MOVE ASSIGNMENT?

        // std::swap(value, node.value);
        // std::swap(left, node.left);
        // std::swap(right, node.right);

        value = std::move(node.value);
        left = std::move(node.left);
        right = std::move(node.right);
    }
    return *this;
}

// Destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    if (HasLeftChild()) {
        delete left;
    }
    if (HasRightChild()) {
        delete right;
    }
}


// Element

// Const version
template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return value;
}

// Mutable version
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return value;
}

// LeftChild const version
template <typename Data>
const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if (HasLeftChild()) {
        return *left;
    } else {
        throw std::out_of_range("No child on the left");
    }
}

// LeftChild mutable version
template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    if (HasLeftChild()) {
        return *left;
    } else {
        throw std::out_of_range("No child on the left");
    }
}

// RightChild const version
template <typename Data>
const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if (HasRightChild()) {
        return *right;
    } else {
        throw std::out_of_range("No child on the right");
    }
}

// RightChild mutable version
template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    if (HasRightChild()) {
        return *right;
    } else {
        throw std::out_of_range("No child on the right");
    }
}

// HasLeftChild
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return left != nullptr;
}

// HasRightChild
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return right != nullptr;
}

// Comparison operators

// Equal operator
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& node) const noexcept {
    return BinaryTree<Data>::Node::operator==(node);
}

// Not equal operator
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& node) const noexcept {
    //! return BinaryTreeNode<Data>::operator!=(node);
    return !(*this == node);
}

// IsLeaf "ereditated" from BinaryTree<Data>::Node
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
    return BinaryTree<Data>::Node::IsLeaf();
    //! È un barbatrucco per riciclare il metodo
}

/* ************************************************************************** */

// BinaryTreeLnk

// Specific constructors

// TraversableContainer //! ATTENZIONE!!
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& container) {
    size = container.Size();
    QueueLst<NodeLnk**> queue;

    if (size > 0) {
        queue.Enqueue(&root);

        container.Traverse([&queue](const Data& currData) {
            if (!queue.Empty()) {
                NodeLnk* &current = *queue.HeadNDequeue();

                current = new NodeLnk(currData);
                queue.Enqueue(&(current->left));
                queue.Enqueue(&(current->right));
            }
        });
    }
}

// MappeableContainer //! ATTENZIONE!!
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& container) {
    size = container.Size();
    QueueLst<NodeLnk**> queue;

    if (size > 0) {
        queue.Enqueue(&root);

        container.Map([this, &queue](Data &currData) {
            if (!queue.Empty()) {
                NodeLnk* &current = *queue.HeadNDequeue();

                current = new NodeLnk(std::move(currData));
                queue.Enqueue(&((*current)->left));
                queue.Enqueue(&((*current)->right));
            }
        });
    }
}

//! Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& tree) : BinaryTreeLnk() {
    root = CopyTree(tree.root);
    size = tree.size;
}

// Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& tree) noexcept {
    std::swap(root, tree.root);
    std::swap(size, tree.size);
}

// Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}

//! Copy Assignment 
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& tree) {
    //FIXME Deve solo copiare i nodi, non la struttura dati?
    if (this != &tree) {
        Clear();
        root = CopyTree(tree.root);
        size = tree.size;
    }
    return *this;
}

//! Move Assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& tree) noexcept {
    if (this != &tree) {
        std::swap(root, tree.root);
        std::swap(size, tree.size);
    }
    return *this;
}

// Comparison operators

// Equal operator using the comparison operator of the Node class
template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& tree) const noexcept {
    if (size != tree.size){
        return false;
    }
    //! this is a call to the Node::operator==
    return (Root() == tree.Root()); 
}

// Not equal operator is the negation of the equal operator
template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& tree) const noexcept {
    return !(*this == tree);
}

// Specific member functions

// Root const version
template <typename Data>
const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::Root() const {
    if (root == nullptr) {
        throw std::length_error("Empty tree");
    }
    return *root;
}

// Root mutable version
template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {
    if (root == nullptr) {
        throw std::length_error("Empty tree");
    }
    return *root;
}

// Clear
template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    DeleteTree(root);
    size = 0;
}

// Auxiliary member functions

// DeleteTree
template <typename Data>
void BinaryTreeLnk<Data>::DeleteTree(NodeLnk*& node) noexcept {
    if (node != nullptr) {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
        node = nullptr;
    }
}

// RecursiveCopy
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CopyTree(NodeLnk* node) {
    if (node != nullptr) {
        NodeLnk* newNode = new NodeLnk(node->value);
        newNode->left = CopyTree(node->left);
        newNode->right = CopyTree(node->right);
        return newNode;
    }
    return nullptr;
}

// /* ************************************************************************** */
    
} // namespace lasd