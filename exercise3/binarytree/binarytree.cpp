#include <iostream>
#include <utility>
#include "binarytree.hpp"
#include <stdexcept>

namespace lasd {

/* ************************************************************************** */

// Node

// Comparison operators

// Equality operator
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
    if (Element() != node.Element()) {
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

    return Root() == tree.Root();
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
    if (this->Empty()) {
        return;
    }
    PreOrderTraverse(function);
}

// PreOrderTraverse
template <typename Data>
inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun function) const {
    if (this->Empty()) {
        return;
    }
    PreOrderTraverse(&Root(), function);
}

// PostOrderTraverse
template <typename Data>
inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun function) const {
    if (this->Empty()) {
        return;
    }
    PostOrderTraverse(&Root(), function);
}

// InOrderTraverse
template <typename Data>
inline void BinaryTree<Data>::InOrderTraverse(TraverseFun function) const {
    if (this->Empty()) {
        return;
    }
    InOrderTraverse(&Root(), function);
}

// BreadthTraverse
template <typename Data>
inline void BinaryTree<Data>::BreadthTraverse(TraverseFun function) const {
    if (this->Empty()) {
        return;
    }
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

    if (node->HasLeftChild()) {
        PreOrderTraverse(&(node->LeftChild()), function);
    }
    if (node->HasRightChild()) {
        PreOrderTraverse(&(node->RightChild()), function);
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

// InOrderTraverse
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
    // lasd::QueueLst<Node*> queue; //?Deve essere const perchè il nodo è const?
    lasd::QueueLst<const Node*> queue;
    queue.Enqueue(node);

    while (!queue.Empty()) {
        const Node* current = queue.HeadNDequeue();

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
    if (this->Empty()) {
        return;
    }
    PreOrderMap(&(Root()), function);
}

// PostOrderMap
template <typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun function) {
    if (this->Empty()) {
        return;
    }
    PostOrderMap(&(Root()), function);
}

// InOrderMap
template <typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun function) {
    if (this->Empty()) {
        return;
    }
    InOrderMap(&(Root()), function);
}

// BreadthMap
template <typename Data>
inline void MutableBinaryTree<Data>::BreadthMap(MapFun function) {
    if (this->Empty()) {
        return;
    }
    BreadthMap(&(Root()), function);
}

// Internal Methods

// PreOrderMap
template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableNode* node, MapFun function) {
    if (node == nullptr || Empty()) {
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
    if (!tree.Empty()) {
        root = &tree.Root(); //! Grossi problemi in caso di modifica!
        stack.Push(&tree.Root()); //! Attenzione potrebbe causare problemi!
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

// Copy assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& iterator) {
    if (this != &iterator) {
        root = iterator.root;
        stack = iterator.stack;
    }
    return *this;
}

// Move assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iterator) noexcept {
    if (this != &iterator) {
        std::swap(root, iterator.root);
        std::swap(stack, iterator.stack);
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

// Operator*
template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    if (!stack.Empty()) {
        return stack.Top()->Element();
    } else {
        throw std::out_of_range("Iterator is terminated");
    }
}

// Terminated
template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return stack.Empty();
}

// Operator++
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
   
    return *this;
}

// Reset
template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    if (!stack.Empty()) {
        stack.Clear();
    }
    if (root != nullptr) {
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

// Equality operator
template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator<Data>& iterator) const noexcept {
    return BTPreOrderIterator<Data>::operator==(iterator);
}

// Inequality operator
template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data>& iterator) const noexcept {
    return BTPreOrderIterator<Data>::operator!=(iterator);
}

// Operator*
template <typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*() {
    if (!(this->Terminated())) {
        return const_cast<Data&>(stack.Top()->Element());
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
    if(!tree.Empty()){
        root = &tree.Root();
        stack.Push(root);
        getLeftMostLeaf();  
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
const Data& BTPostOrderIterator<Data>::operator*() const {
    if (!Terminated()) {
        return stack.Top()->Element();
        //! return current->Element(); Il top è il current node!
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

// Terminated
template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return stack.Empty();
}

// Operator++
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }

    const typename BinaryTree<Data>::Node* current = stack.TopNPop();

    if (current == nullptr) {
        throw std::runtime_error("Iterator is terminated!");
    }
    
    if (!stack.Empty()){
        const typename BinaryTree<Data>::Node* parent = stack.Top();
        if (parent->HasLeftChild() && current == &(parent->LeftChild()) && parent->HasRightChild()) {
            stack.Push(&(parent->RightChild()));
            getLeftMostLeaf();
        }
    }
    
    return *this;
}

// Reset //! Check, it's probably ok!
template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    if (!stack.Empty()) {
        stack.Clear();
    }
    stack.Push(root);
    getLeftMostLeaf();
}

// Auxiliary function

//todo getLeftMostLeaf change name
template <typename Data>
void BTPostOrderIterator<Data>::getLeftMostLeaf() {
    const typename BinaryTree<Data>::Node* current = stack.Top();
    while (current != nullptr && (current->HasLeftChild() || current->HasRightChild())) {  
        if (current->HasLeftChild()) {
            current = &(current->LeftChild());
        } else if (current->HasRightChild()) {
            current = &(current->RightChild());
        }
        stack.Push(current);
    }
}

/* ************************************************************************** */

// BTPostOrderMutableIterator

// Default constructor
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(MutableBinaryTree<Data>& tree) : BTPostOrderIterator<Data>(tree) {};

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
Data& BTPostOrderMutableIterator<Data>::operator*() {
    if (!(this->Terminated())) {
        return const_cast<Data&>(stack.Top()->Element());
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

/* ************************************************************************** */

// BTInOrderIterator

// Specific Constructors
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree) {
    if (!tree.Empty()) {
        root = &tree.Root();
        stack.Push(root);
        getLeftMostNode();
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
const Data& BTInOrderIterator<Data>::operator*() const {
    if (!stack.Empty()) {
        return stack.Top()->Element();
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

// Operator++
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Iterator is terminated!");
    }

    const typename BinaryTree<Data>::Node* current = stack.TopNPop();

    if (current->HasRightChild()) {
        stack.Push(&(current->RightChild()));
        getLeftMostNode();
    }

    return *this;
}

// Reset
template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    if (!stack.Empty()) {
        stack.Clear();
    }

    stack.Push(root);
    getLeftMostNode();
}

// Terminated
template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return stack.Empty();
}

// Auxiliary function

//todo getLeftMostNode change name
template <typename Data>
void BTInOrderIterator<Data>::getLeftMostNode() {
    const typename BinaryTree<Data>::Node* current = stack.Top();

    while (current != nullptr && current->HasLeftChild()) {
        current = &(current->LeftChild());
        stack.Push(current);
    }
}
/* ************************************************************************** */

// BTInOrderMutableIterator

// Default constructor
template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data>& tree) : BTInOrderIterator<Data>(tree) {};

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
Data& BTInOrderMutableIterator<Data>::operator*() {
    if (!this->Terminated()) {
        return const_cast<Data&>(stack.Top()->Element());
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

/* ************************************************************************** */

// BTBreadthIterator

// Specific Constructors
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree) {
    if (!tree.Empty()) {
        root = &tree.Root();
        queue.Enqueue(root);
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
const Data& BTBreadthIterator<Data>::operator*() const {
    if (!queue.Empty()) {
        return queue.Head()->Element();
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

// Terminated
template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return queue.Empty();
}

// Operator++
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Iterator is terminated!");
    }

    const typename BinaryTree<Data>::Node* current = queue.HeadNDequeue();

    if (current->HasLeftChild()) {
        queue.Enqueue(&(current->LeftChild()));
    }

    if (current->HasRightChild()) {
        queue.Enqueue(&(current->RightChild()));
    }

    return *this;
}

// Reset
template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    if (queue.Empty()) {
        queue.Clear();
    }
    queue.Enqueue(root);
}

/* ************************************************************************** */

// BTBreadthMutableIterator

// Default constructor
template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(MutableBinaryTree<Data>& tree) : BTBreadthIterator<Data>(tree) {};

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
Data& BTBreadthMutableIterator<Data>::operator*() {
    if (!this->Terminated()) {
        return const_cast<Data&>(queue.Head()->Element());
    }else {
        throw std::out_of_range("Iterator is terminated");
    }
}

/* ************************************************************************** */

}