
namespace lasd {

/* ************************************************************************** */

// NodeVec

// todo Problematico a causa dei nodi vuoti!
// todo Togliere lef e right e calcolarseli al volo ogni volta che servono
// Constructors

// Specific constructor
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& value) : value(value) {}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& value) : value(std::move(value)) {}

// Copy Assignment
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node){
    if (this != &node){
        value = node.value;
    }
    return *this;
}

// Move Assignment
template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept{
    if (this != &node){
        value = std::move(node.value);
    }
    return *this;
}

// Comparison operators

// Equalilty operator
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec& node) const noexcept{
    return value == node.value;
}

// Inequality operator
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec& node) const noexcept{
    return value != node.value;
}

// Element const
template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return value;
}

// Element
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return value;
}

// HasLeftChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return left(index()) < tree->size;
}

// HasRightChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
  if (right < tree->treeVector.Size()){
    return (tree->treeVector[right] != nullptr);
  }
    return false;
}

// IsLeaf ereditated from BinaryTree

// LeftChild ereditated from Node
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if (HasLeftChild()){
        return *tree->treeVector[left];
    }
    throw std::out_of_range("No left child");
}

// LeftChild ereditated from MutableNode
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if (HasLeftChild()){
        return *tree->treeVector[left];
    }
    throw std::out_of_range("No left child");
}

// RightChild ereditated from Node
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if (HasRightChild()){
        return *tree->treeVector[right];
    }
    throw std::out_of_range("No right child");
}

// RightChild ereditated from MutableNode
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::RightChild() {
    if (HasRightChild()){
        return *tree->treeVector[right];
    }
    throw std::out_of_range("No right child");
}

/* ************************************************************************** */
// BinaryTreeVec

// Constructor from TraversableContainer
// template <typename Data>
// BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& container) {
//   treeVector.Resize(container.Size());
//   for (unsigned long i = 0; i < container.Size(); i++){
//     treeVector[i] = new NodeVec(container[i]);
//     treeVector[i]->index = i;
//     treeVector[i]->tree = this;
//   }
//   for (unsigned long i = 0; i < container.Size(); i++){
//     if (2*i+1 < container.Size()){
//       treeVector[i]->left = 2*i+1;
//     }
//     if (2*i+2 < container.Size()){
//       treeVector[i]->right = 2*i+2;
//     }
//   }
// }

// template <typename Data>
// BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& container) {
//     InitializeVector(container.Size()); //Fa la resize e pulisce il vettore treeVector 
    
//     size = container.Size();
//     for (unsigned long i = 0; i < container.Size(); i++) {
//         treeVector[i] = new NodeVec(lc[i]);
//         treeVector[i]->index = i;
//         treeVector[i]->left = i*2+1;
//         treeVector[i]->right = i*2+2;
//         treeVector[i]->ptr = this;
//     }
// }

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& container) : treeVector(container.Size()){
    unsigned long i{0};
    container.Traverse(
        [this, &i](const Data &currData) { 
            //! Si poteva fare un costruttore e fare tutto in una riga e ignorare l'indice.
            treeVector[i] = new NodeVec(currData); //FIXME
            treeVector[i]->index = i;
            treeVector[i]->left = i*2+1;
            treeVector[i]->right = i*2+2;
            treeVector[i]->tree = this;
            i++;
        });
}

// Constructor from MappableContainer
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& container) : treeVector(container.Size()){
    unsigned long i{0};
    container.Map(
        [this, &i](const Data &currData) { 
            treeVector[i] = new NodeVec(currData);
            treeVector[i]->index = i;
            treeVector[i]->left = i*2+1;
            treeVector[i]->right = i*2+2;
            treeVector[i]->tree = this;
            i++;
        });
}

// Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& tree) : treeVector(tree.treeVector.Size()){
    for (unsigned long i = 0; i < size; i++){
        treeVector[i] = new NodeVec(tree.treeVector[i]->Element());
        treeVector[i]->index = i;
        treeVector[i]->left = tree.treeVector[i]->left;
        treeVector[i]->right = tree.treeVector[i]->right;
        treeVector[i]->tree = this;
    }
}

// Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& tree) noexcept : treeVector(std::move(tree.treeVector)){
    size = tree.size;
    tree.size = 0;
    for (unsigned long i = 0; i < size; i++){
        treeVector[i]->tree = this;
    }
}

// Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    Clear();
}

// Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& tree){
    if (this != &tree){
        Clear();
        treeVector.Resize(tree.treeVector.Size());
        size = tree.size;
        for (unsigned long i = 0; i < size; i++){
            treeVector[i] = new NodeVec(tree.treeVector[i]->Element());
            treeVector[i]->index = i;
            treeVector[i]->left = tree.treeVector[i]->left;
            treeVector[i]->right = tree.treeVector[i]->right;
            treeVector[i]->tree = this;
        }
    }
    return *this;
}

// Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& tree) noexcept{
    if (this != &tree){
        Clear();
        treeVector = std::move(tree.treeVector);
        size = tree.size;
        tree.size = 0;
        for (unsigned long i = 0; i < size; i++){
            treeVector[i]->tree = this;
        }
    }
    return *this;
}

// Comparison operators

// Equalilty operator
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& tree) const noexcept{
    if (size != tree.size){
        return false;
    }
    for (unsigned long i = 0; i < size; i++){
        if (treeVector[i]->Element() != tree.treeVector[i]->Element()){
            return false;
        }
    }
    return true;
}

// Inequality operator
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& tree) const noexcept{
    return !(*this == tree);
}

// Specific member functions (inherited from BinaryTree)

// Root 
template <typename Data>
const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::Root() const{
    if (size > 0){
        return *treeVector[0];
    }
    throw std::length_error("Empty tree");
}

// Root Mutable
template <typename Data>
typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::Root(){
    if (size > 0){
        return *treeVector[0];
    }
    throw std::length_error("Empty tree");
}

// Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    for (unsigned long i = 0; i < size; i++){
        delete treeVector[i];
    }
    treeVector.Clear();
    size = 0;
}

// BreadthTraverse
template <typename Data>
inline void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun function) const {
    if (function == nullptr) {
        throw std::invalid_argument("Null function passed to BreadthTraverse");
    }
    for(ulong i = 0; i < size; i++) {
        if(treeVector->operator[](i) != nullptr) {
            function(treeVector->operator[](i)->Element());
        }
    }
}


// BreadthTraverse Mutable
template <typename Data>
inline void BinaryTreeVec<Data>::BreadthMap(MapFun function) {
    if (function == nullptr) {
        throw std::invalid_argument("Null function passed to BreadthMap");
    }
    for(ulong i = 0; i < size; i++) {
        if(treeVector->operator[](i) != nullptr) {
            function(treeVector->operator[](i)->Element());
        }
    }
}

/* ************************************************************************** */

}
