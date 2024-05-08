
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
            left = new NodeLnk(node.LeftChild()); //FIXME Forse non devo creare un nodo ma solo copiare il valore nel nodo già creato...
        }
        if (HasRightChild()) {
            delete right;
        }
        if (node.HasRightChild()) {
            right = new NodeLnk(node.RightChild()); //FIXME Forse non devo creare un nodo ma solo copiare il valore nel nodo già creato...
        }
    }
    return *this;
}

// Move Assignment
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept {
    if (this != &node) {
        std::swap(value, node.value);
        std::swap(left, node.left);
        std::swap(right, node.right);
    }
    return *this;
}

// Destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete left;
    delete right;
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
    if (value != node.value) {
        return false;
    }

    if (HasLeftChild() != node.HasLeftChild() || HasRightChild() != node.HasRightChild()) {
        return false;
    }

    if (HasLeftChild() && LeftChild() != node.LeftChild()) {
        return false;
    }

    if (HasRightChild() && RightChild() != node.RightChild()) {
        return false;
    }

    return true;
}

// Not equal operator
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& node) const noexcept {
    return !(*this == node);
}

//! IsLeaf ereditated from BinaryTree<Data>::Node

/* ************************************************************************** */

// BinaryTreeLnk

// Specific constructors

// TraversableContainer //! Posso pure fare la insert creando anche un albero degenere, volendo?
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& container) {
    container.Traverse([this](const Data& currData) { Insert(currData); });
}

// MappeableContainer
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& container) {
    container.Map([this](Data &currData) { Insert(std::move(currData)); });
}

// Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& tree) : BinaryTreeLnk() {
    CopyTree(&root, tree.root);
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

// Copy Assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& tree) {
    if (this != &tree) {
        DeleteTree(root);
        CopyTree(&root, tree.root);
        size = tree.size;
    }
    return *this;
}

// Move Assignment
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
    if (size != tree.size || Empty() != tree.Empty()){
        return false;
    }
    return *root == *tree.root; //! Attenzione
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

//! Insert Iterativo (BST)
template <typename Data>
void BinaryTreeLnk<Data>::Insert(const Data& data) {
    if (Empty()) {
        root = new NodeLnk(data);
    } else {
        lasd::QueueLst<NodeLnk*> queue;
        queue.Enqueue(root);

        while (!queue.Empty()) {
            NodeLnk* current = queue.Front();
            queue.Dequeue();

            if (data < current->value) {
                if (current->HasLeftChild()) {
                    queue.Enqueue(current->left);
                } else {
                    current->left = new NodeLnk(data);
                    break;
                }
            } else {
                if (current->HasRightChild()) {
                    queue.Enqueue(current->right);
                } else {
                    current->right = new NodeLnk(data);
                    break;
                }
            }
        }
    }
    size++;
}

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

//! RecursiveCopy
template <typename Data>
void BinaryTreeLnk<Data>::CopyTree(NodeLnk** node, const NodeLnk* other) {
    if (other != nullptr) {
        *node = new NodeLnk(other->value);
        CopyTree(&(*node)->left, other->left);
        CopyTree(&(*node)->right, other->right);
    }
}

//todo IterativeCopy
// template <typename Data>
// void BinaryTreeLnk<Data>::CopyTree(NodeLnk** node, const NodeLnk* other) {
//     if (other != nullptr) {
//         *node = new NodeLnk(other->value);
//         lasd::QueueLst<NodeLnk*> queue;
//         queue.Enqueue(*node);

//         while (!queue.Empty()) {
//             NodeLnk* current = queue.Front();
//             queue.Dequeue();

//             if (other->HasLeftChild()) {
//                 current->left = new NodeLnk(other->LeftChild());
//                 queue.Enqueue(current->left);
//             }

//             if (other->HasRightChild()) {
//                 current->right = new NodeLnk(other->RightChild());
//                 queue.Enqueue(current->right);
//             }
//         }
//     }
// }


// /* ************************************************************************** */

}













































// //TODO TUTTO DA RIFARE, AL MASSIMO POSSO RICICLARE PER BTLINK, MAYBE!
// //! Node is not accessible from outside the class BinaryTree.

// // Data Copy Constructor
// template <typename Data>
// BinaryTree<Data>::Node::Node(const Data& data) : value{data} {}

// // Data Move constructor
// template <typename Data>
// BinaryTree<Data>::Node::Node(Data&& data) noexcept {
//     std::swap(data, value);
// }

// // Copy constructor
// template <typename Data>
// BinaryTree<Data>::Node::Node(const Node& node) : value{node.value} {}

// // Move constructor
// template <typename Data>
// BinaryTree<Data>::Node::Node(Node&& other) noexcept {
//     std::swap(other.value, value);
//     std::swap(other.left, left);
//     std::swap(other.right, right);
// }

// // Destructor
// template <typename Data>
// BinaryTree<Data>::Node::~Node() {
//     delete left;
//     delete right;
// }

// // Comparison operators

// //Equal operator
// template <typename Data>
// bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
//     if (value != node.value) {
//         return false;
//     }

//     if (HasLeftChild() != node.HasLeftChild() || HasRightChild() != node.HasRightChild()) {
//         return false;
//     }

//     if (HasLeftChild() && LeftChild() != node.LeftChild()) {
//         return false;
//     }

//     if (HasRightChild() && RightChild() != node.RightChild()) {
//         return false;
//     }

//     return true;
// }

// //Not equal operator
// template <typename Data>
// bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept {
//     return !(*this == node);
// }

// /* ************************************************************************** */

// // BinaryTree

// // Constructor

// // Copy constructor
// template <typename Data>
// BinaryTree<Data>::BinaryTree(const BinaryTree<Data>& tree) : BinaryTree() {
//     container.Traverse([this](const Data &currData) { Insert(currData); });
// }

// // Move constructor
// template <typename Data>
// BinaryTree<Data>::BinaryTree(BinaryTree<Data>&& tree) noexcept {
//     container.Map([this](Data &currData) { Insert(std::move(currData)); });
// }



/* ************************************************************************** */
