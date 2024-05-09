#include <iostream>
#include <utility>
#include "binarytree.hpp"

namespace lasd {

/* ************************************************************************** */

// Node

// Comparison operators

// Equality operator
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
    if (value != node.Element()) {
        return false;
    }

    // Check if the left child is equal using recursion
    if (HasLeftChild() != node.HasLeftChild() || (HasLeftChild() && !(LeftChild() == node.LeftChild()))) {
        return false;
    }

    // Check if the right child is equal using recursion
    if (HasRightChild() != node.HasRightChild() || (HasRightChild() && !(RightChild() == node.RightChild()))) {
        return false;
    }

    return true;
}

// Inequality operator
template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept {
    return (!(*this == node));
}
// Specific member functions

//! Element NOT NEEDDED
// template <typename Data>
// const Data& BinaryTree<Data>::Node::Element() const noexcept {
//     return value;
// }

// IsLeaf
template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept {
     return !HasLeftChild() && !HasRightChild();
}


/* ************************************************************************** */

// BinaryTree

// Comparison operators

// Equality operator
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& tree) const noexcept {
    if (size != tree.size) {
        return false;
    }

    if (size == 0) {
        return true;
    }

    return *root == *tree.root;
    // return (Root() == tree.Root()); //! Check!!!!!
}

// Inequality operator
template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& tree) const noexcept {
    return !(*this == tree);
}

// Specific member functions

// Traverse
template <typename Data>
inline void BinaryTree<Data>::Traverse(TraverseFun function) const {
    // todo chiedere a Mogavero se è giusto fare così
    // PostOrderTraverse(Root(), function);
    PreOrderTraverse(function);
}

// PreOrderTraverse
template <typename Data>
inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun function) const {
    PreOrderTraverse(&Root(), function);
}

// PostOrderTraverse
template <typename Data>
inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun function) const {
    PostOrderTraverse(&Root(), function);
}

// InOrderTraverse
template <typename Data>
inline void BinaryTree<Data>::InOrderTraverse(TraverseFun function) const {
    InOrderTraverse(&Root(), function);
}

// BreadthTraverse
template <typename Data>
inline void BinaryTree<Data>::BreadthTraverse(TraverseFun function) const {
    BreadthTraverse(&Root(), function);
}



// Internal Methods

// PreOrderTraversal
template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(const Node* node, TraverseFun function) const {
    if (node == nullptr) {
        return;
    }

    function(node->Element());

    if (node->HasRightChild()) {
        PreOrderTraverse(&(node->RightChild()), function); //!Vedi se è giusto fare così usando l'operatore & per passare il puntatore
    }
    if (node->HasLeftChild()) {
        PreOrderTraverse(&(node->LeftChild()), function);
    }
}


// PostOrderTraversal
template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(const Node* node, TraverseFun function) const {
    if (node == nullptr) {
        return;
    }
    if (node->HasLeftChild()) {
        PostOrderTraverse(&(node->LeftChild()), function);
    }

    if (node->HasRightChild()) {
        PostOrderTraverse(&(node->RightChild()), function);
    }

    function(node->Element());
}

// InOrderTraversal
template <typename Data>
void BinaryTree<Data>::InOrderTraverse(const Node* node, TraverseFun function) const {
    if (node == nullptr) {
        return;
    }

    if (node->HasLeftChild()) {
        InOrderTraverse(&(node->LeftChild()), function);
    }
    
    function(node->Element());

    if (node->HasRightChild()) {
        InOrderTraverse(&(node->RightChild()), function);
    }
}

// BreadthTraversal
template <typename Data>
void BinaryTree<Data>::BreadthTraverse(const Node* node, TraverseFun function) const {
    if (node == nullptr) {
        return;
    }
    // lasd::QueueLst<Node*> queue; //!Deve essere const perchè il nodo è const?
    lasd::QueueLst<const Node*> queue;
    queue.Enqueue(node);

    while (!queue.Empty()) {
        Node* current = queue.Head();
        queue.Dequeue();

        function(current->Element());

        if (current->HasLeftChild()) {
            queue.Enqueue(&(current->LeftChild()));
        }

        if (current->HasRightChild()) {
            queue.Enqueue(&(current->RightChild()));
        }
    }
}

/* ************************************************************************** */

// MutableBinaryTree

// Specific member functions

// Map
template <typename Data>
inline void MutableBinaryTree<Data>::Map(MapFun function) {
    // todo chiedere a Mogavero se è giusto fare così
    PreOrderMap(function);
    // PostOrderMap(Root(), function);
}

// PreOrderMap
template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun function) {
    PreOrderMap(&(Root()), function);
}

// PostOrderMap
template <typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun function) {
    PostOrderMap(&(Root()), function);
}

// InOrderMap
template <typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun function) {
    InOrderMap(&(Root()), function);
}

// BreadthMap
template <typename Data>
inline void MutableBinaryTree<Data>::BreadthMap(MapFun function) {
    BreadthMap(&(Root()), function);
}

// Internal Methods

// PreOrderMap
template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableNode* node, MapFun function) {
    if (node == nullptr) {
        return;
    }

    function(node->Element());

    if (node->HasRightChild()) {
        PreOrderMap(&(node->RightChild()), function);
    }
    if (node->HasLeftChild()) {
        PreOrderMap(&(node->LeftChild()), function);
    }
}

// PostOrderMap
template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableNode* node, MapFun function) {
    if (node == nullptr) {
        return;
    }
    if (node->HasLeftChild()) {
        PostOrderMap(&(node->LeftChild()), function);
    }

    if (node->HasRightChild()) {
        PostOrderMap(&(node->RightChild()), function);
    }

    function(node->Element());
}

// InOrderMap
template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableNode* node, MapFun function) {
    if (node == nullptr) {
        return;
    }

    if (node->HasLeftChild()) {
        InOrderMap(&(node->LeftChild()), function);
    }
    
    function(node->Element());

    if (node->HasRightChild()) {
        InOrderMap(&(node->RightChild()), function);
    }
}

// BreadthMap
template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableNode* node, MapFun function) {
    if (node == nullptr) {
        return;
    }
    lasd::QueueLst<MutableNode*> queue;
    queue.Enqueue(node);

    while (!queue.Empty()) {
        MutableNode* current = queue.Head();
        queue.Dequeue();

        function(current->Element());

        if (current->HasLeftChild()) {
            queue.Enqueue(&(current->LeftChild()));
        }

        if (current->HasRightChild()) {
            queue.Enqueue(&(current->RightChild()));
        }
    }
}
/* ************************************************************************** */

// BTPreOrderIterator

// Specific constructors
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree) {
    if (tree.size != 0) {
        root = &tree.Root();
    }   
}

// Copy constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& iterator) : root(iterator.root), stack(iterator.stack) {}

// Move constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& iterator) noexcept {
    std::swap(root, iterator.root);
    std::swap(stack, iterator.stack);
}

// Specific Constructors
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree) {
    if (tree.size != 0) {
        //! Fab suggerisce di fare Root() che ritorna un puntatore a Node e poi fare il push del puntatore su stack
        stack.Push(root = &tree.Root());
    }
}

// Copy assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& iterator) {
    if (this != &iterator) {
        root = iterator.root;
        stack = iterator.stack;

        //! Check if this is better
        // BTPreOrderIterator<Data> *tmp = new BTPreOrderIterator<Data>(iterator);
        // std::swap(*tmp, *this);
        // delete tmp;
    }
    return *this;
}

// Move assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iterator) noexcept {
    if (this != &iterator) {
        std::swap(root, iterator.root);
        std::swap(stack, iterator.stack);//! Check
    }
    return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& iterator) const noexcept {
    return root == iterator.root && stack == iterator.stack;
}

// Inequality operator
template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& iterator) const noexcept {
    return !(*this == iterator);
}

// Operator* //! Check
template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const {
    if (!stack.Empty()) {
        return stack.Top()->Element();
        //! return current->Element(); ipotetico current?
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

// Terminated
template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return stack.Empty();
}

// Operator++
//! Check
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {

    if (Terminated()) {
        throw std::out_of_range("Iterator is terminated!");
    }
    const typename BinaryTree<Data>::Node* current = stack.TopNPop();

    if (current == nullptr) {
        throw std::runtime_error("Iterator is terminated!");
    }

    if (current->HasRightChild()) {
        stack.Push(&(current->RightChild()));
    }

    if (current->HasLeftChild()) {
        stack.Push(&(current->LeftChild()));
    }

    //! Check if it's necessary! but i think current is needed.
    // if(stack.Empty()) {
    //     current = nullptr;
    // } else {
    //     current = stack.TopNPop();
    // }
   
    return *this;
}

// Reset //! Check
template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    if (stack != nullptr) {
        stack.Clear();
        stack.Push(root);
    }
}

/* ************************************************************************** */

// BTPreOrderMutableIterator

// Default constructor
template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(MutableBinaryTree<Data>& tree) : BTPreOrderIterator<Data>(tree) {};

// Copy constructor
template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data>& iterator) : BTPreOrderIterator<Data>(iterator) {};

// Move constructor
template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data>&& iterator) noexcept : BTPreOrderIterator<Data>(std::move(iterator)) {};

// Copy assignment
template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data>& iterator) {
    BTPreOrderIterator<Data>::operator=(iterator);
    return *this;
}

// Move assignment
template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator<Data>&& iterator) noexcept {
    BTPreOrderIterator<Data>::operator=(std::move(iterator));
    return *this;
}

// Comparison operators

//! Check Equality operator
template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator<Data>& iterator) const noexcept {
    return BTPreOrderIterator<Data>::operator==(iterator);
}

// Inequality operator
template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data>& iterator) const noexcept {
    return BTPreOrderIterator<Data>::operator!=(iterator);
}

//! Operator*
template <typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*() const {
    if (!Terminated()) {
        return stack.Top()->Element();
        // return const_cast<Data&>(curr->Element());
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

/* ************************************************************************** */
// BTPostOrderIterator

// Specific Constructors

// Default constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree) {
    if(tree.Size()!= 0) {
        root = &tree.Root();
        const typename BinaryTree<Data>::Node* current = root;
        // funzione che arriva alla foglia più a sinistra
        getLeftMostLeaf(current);
    }
}

// Copy constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& iterator) : root(iterator.root), stack(iterator.stack){}

// Move constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& iterator) noexcept {
    std::swap(root, iterator.root);
    std::swap(stack, iterator.stack);
}

// Copy assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& iterator) {
    if (this != &iterator) {
        root = iterator.root;
        stack = iterator.stack;
    }
    return *this;
}

// Move assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& iterator) noexcept {
    if (this != &iterator) {
        std::swap(root, iterator.root);
        std::swap(stack, iterator.stack);
    }
    return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& iterator) const noexcept {
    return root == iterator.root && stack == iterator.stack;
}

// Inequality operator
template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& iterator) const noexcept {
    return !(*this == iterator);
}

// Operator*
template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const {
    if (!Terminated()) {
        return stack.Top()->Element();
        //! return current->Element(); ipotetico current?
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

// Operator++
// todo da implementare e attualmente impossibile da fare senza l'uso di un current!
//FIXME Check, it's probably wrong!
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Iterator is terminated!");
    }

    const typename BinaryTree<Data>::Node* current = stack.TopNPop();
    const typename BinaryTree<Data>::Node* parent = nullptr;

    if (!stack.Empty()) {
        current = stack.Top();
    }

    if (parent != nullptr) {
        if (current == parent->LeftChild() && parent->HasRightChild()) {
            getLeftMostLeaf(&(parent->RightChild()));
            //! Mari usa una stackFill function
        }
    }

    if (!stack.Empty()) {
        current = stack.Top();
    }

    return *this;
}

// Reset //! Check
template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    if (stack != nullptr) {
        stack.Clear();
        const typename BinaryTree<Data>::Node* current = root;
        while (current != nullptr) {
            stack.Push(current);
            if (current->HasLeftChild()) {
                current = current->LeftChild();
            } else {
                current = current->RightChild();
            }
        }
    }
}

// Auxiliary function

// getLeftMostLeaf
template <typename Data>
void BTPostOrderIterator<Data>::getLeftMostLeaf(const typename BinaryTree<Data>::Node* node) {
    if (node == nullptr) {
        return;
    }

    stack.Push(node);

    if (node->HasLeftChild()) {
        getLeftMostLeaf(&(node->LeftChild()));
    }

    if (node->HasRightChild()) {
        getLeftMostLeaf(&(node->RightChild()));
    }
}
/* ************************************************************************** */

// BTPostOrderMutableIterator

// Default constructor
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BinaryTree<Data>& tree) : BTPostOrderIterator<Data>(tree) {};

// Copy constructor
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& iterator) : BTPostOrderIterator<Data>(iterator) {};

// Move constructor
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data>&& iterator) noexcept : BTPostOrderIterator<Data>(std::move(iterator)) {};

// Copy assignment
template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator<Data>& iterator) {
    BTPostOrderIterator<Data>::operator=(iterator);
    return *this;
}

// Move assignment
template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator<Data>&& iterator) noexcept {
    BTPostOrderIterator<Data>::operator=(std::move(iterator));
    return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator<Data>& iterator) const noexcept {
    return BTPostOrderIterator<Data>::operator==(iterator);
}

// Inequality operator
template <typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator<Data>& iterator) const noexcept {
    return BTPostOrderIterator<Data>::operator!=(iterator);
}

// Operator*
template <typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*() const {
    return const_cast<Data&>(BTPostOrderIterator<Data>::operator*());
}

/* ************************************************************************** */

// BTInOrderIterator //! Tutti i metodi sono da rivedere

// Specific Constructors
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree) {
    if (tree.size != 0) {
        const typename BinaryTree<Data>::Node* current = &tree.Root();
        while (current != nullptr) {
            stack.Push(current);
            current = current->LeftChild();
        }
    }
}

// Copy constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& iterator) : root(iterator.root), stack(iterator.stack) {}

// Move constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& iterator) noexcept {
    std::swap(root, iterator.root);
    std::swap(stack, iterator.stack);
}

// Copy assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& iterator) {
    if (this != &iterator) {
        root = iterator.root;
        stack = iterator.stack;
    }
    return *this;
}

// Move assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iterator) noexcept {
    if (this != &iterator) {
        std::swap(root, iterator.root);
        std::swap(stack, iterator.stack);
    }
    return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iterator) const noexcept {
    return root == iterator.root && stack == iterator.stack;
}

// Inequality operator
template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iterator) const noexcept {
    return !(*this == iterator);
}

// Operator*
template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const {
    if (!stack.Empty()) {
        return stack.Top()->Element();
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

// Operator++
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if (!stack.Empty()) {
        const typename BinaryTree<Data>::Node* current = stack.TopNPop();
        if (current->HasRightChild()) {
            current = current->RightChild();
            while (current != nullptr) {
                stack.Push(current);
                current = current->LeftChild();
            }
        }
    }
    return *this;
}

// Reset
template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    if (stack != nullptr) {
        stack.Clear();
        const typename BinaryTree<Data>::Node* current = root;
        while (current != nullptr) {
            stack.Push(current);
            current = current->LeftChild();
        }
    }
}

/* ************************************************************************** */

// BTInOrderMutableIterator

// Default constructor
template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BinaryTree<Data>& tree) : BTInOrderIterator<Data>(tree) {};

// Copy constructor
template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& iterator) : BTInOrderIterator<Data>(iterator) {};

// Move constructor
template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& iterator) noexcept : BTInOrderIterator<Data>(std::move(iterator)) {};

// Copy assignment
template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data>& iterator) {
    BTInOrderIterator<Data>::operator=(iterator);
    return *this;
}

// Move assignment
template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator<Data>&& iterator) noexcept {
    BTInOrderIterator<Data>::operator=(std::move(iterator));
    return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator<Data>& iterator) const noexcept {
    return BTInOrderIterator<Data>::operator==(iterator);
}

// Inequality operator
template <typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator<Data>& iterator) const noexcept {
    return BTInOrderIterator<Data>::operator!=(iterator);
}

// Operator*
template <typename Data>
Data& BTInOrderMutableIterator<Data>::operator*() const {
    return const_cast<Data&>(BTInOrderIterator<Data>::operator*());
}

/* ************************************************************************** */

// BTBreadthIterator

// Specific Constructors
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree) {
    if (tree.size != 0) {
        queue.Enqueue(root = &tree.Root());
    }
}

// Copy constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& iterator) : root(iterator.root), queue(iterator.queue) {}

// Move constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& iterator) noexcept {
    std::swap(root, iterator.root);
    std::swap(queue, iterator.queue);
}

// Copy assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& iterator) {
    if (this != &iterator) {
        root = iterator.root;
        queue = iterator.queue;
    }
    return *this;
}

// Move assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& iterator) noexcept {
    if (this != &iterator) {
        std::swap(root, iterator.root);
        std::swap(queue, iterator.queue);
    }
    return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& iterator) const noexcept {
    return root == iterator.root && queue == iterator.queue;
}

// Inequality operator
template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& iterator) const noexcept {
    return !(*this == iterator);
}

// Operator*
template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const {
    if (!queue.Empty()) {
        return queue.Head()->Element();
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

// Operator++
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (!queue.Empty()) {
        const typename BinaryTree<Data>::Node* current = queue.HeadNDequeue();
        if (current->HasLeftChild()) {
            queue.Enqueue(current->LeftChild());
        }
        if (current->HasRightChild()) {
            queue.Enqueue(current->RightChild());
        }
    }
    return *this;
}

// Reset
template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    if (queue != nullptr) {
        queue.Clear();
        queue.Enqueue(root);
    }
}

/* ************************************************************************** */

// BTBreadthMutableIterator

// Default constructor
template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BinaryTree<Data>& tree) : BTBreadthIterator<Data>(tree) {};

// Copy constructor
template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator<Data>& iterator) : BTBreadthIterator<Data>(iterator) {};

// Move constructor
template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator<Data>&& iterator) noexcept : BTBreadthIterator<Data>(std::move(iterator)) {};

// Copy assignment
template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data>& iterator) {
    BTBreadthIterator<Data>::operator=(iterator);
    return *this;
}

// Move assignment
template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator<Data>&& iterator) noexcept {
    BTBreadthIterator<Data>::operator=(std::move(iterator));
    return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator<Data>& iterator) const noexcept {
    return BTBreadthIterator<Data>::operator==(iterator);
}

// Inequality operator
template <typename Data>
bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator<Data>& iterator) const noexcept {
    return BTBreadthIterator<Data>::operator!=(iterator);
}

// Operator*
template <typename Data>
Data& BTBreadthMutableIterator<Data>::operator*() const {
    return const_cast<Data&>(BTBreadthIterator<Data>::operator*());
}

/* ************************************************************************** */

}