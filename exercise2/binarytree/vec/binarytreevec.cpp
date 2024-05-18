
namespace lasd {

/* ************************************************************************** */

// NodeVec

// Constructor const
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& value, BinaryTreeVec *tree) : value(value), tree(tree) {};

// Constructor for Dummy Nodes
// template <typename Data>
// BinaryTreeVec<Data>::NodeVec::NodeVec(BinaryTreeVec *tree) : isDummy(true), tree(tree) {};

// Constructor mutable
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& value, BinaryTreeVec *tree) : value(std::move(value)),  tree(std::move(tree)) {};

// Copy Assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node) {
    //! value = node.value;
    // if (!node.isDummy) {
    //     value = node.value;
    //     isDummy = false;
    // }

    if (this != &node) {
        // if (!node.isDummy) {
            value = node.value;
            tree = node.tree;
        // }
    }

    return *this;
}

// Move Assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept {
    //! std::swap(value, node.value);
    // if (!node.isDummy) {
    //     std::swap(value, node.value);
    //     isDummy = false;
    // }

    if (this != &node) {
        // if (!node.isDummy) {
            std::swap(value, node.value);
            std::swap(tree, node.tree);
        // }
    }

    return *this;
}

//! Comparison operators
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec& node) const noexcept {
    return Node::operator==(node);
    //FIXME return BinaryTree<Data>::Node::operator==(node);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec& node) const noexcept {
    return Node::operator!=(node);
    //FIXME return BinaryTree<Data>::Node::operator!=(node);

}

// Specific member functions

//! Element const
template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    // return tree->data[index()];
    return value;
}

//! Element mutable
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    // return tree->data[index()];
    return value;
}

// IsLeaf
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return BinaryTree<Data>::Node::IsLeaf();
    //! return Node::IsLeaf();
}

//! HasLeftChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    // if (isDummy || left(index())->isDummy){
    //     return false;
    // }

    return left(index()) < tree->nodes.Size() && tree->nodes[left(index())] != nullptr;

    // return left(index()) < tree->Size();
}

//! HasRightChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    // if (isDummy || right(index())->isDummy){
    //     return false;
    // }
    // return right(index()) < tree->Size();

    return right(index()) < tree->nodes.Size() && tree->nodes[right(index())] != nullptr;
}

// LeftChild const
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if (!HasLeftChild()) {
        throw std::out_of_range("No left child");
    }
    // return tree->nodes[left(index())];
    return *tree->nodes[left(index())];
}

// LeftChild mutable
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if (!HasLeftChild()) {
        throw std::out_of_range("No left child");
    }
    // return tree->nodes[left(index())];
    return *tree->nodes[left(index())];
}

// RightChild const
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if (!HasRightChild()) {
        throw std::out_of_range("No right child");
    }
    // return tree->nodes[right(index())];
    return *tree->nodes[right(index())];
}

// RightChild mutable
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::RightChild() {
    if (!HasRightChild()) {
        throw std::out_of_range("No right child");
    }
    // return tree->nodes[right(index())];
    return *tree->nodes[right(index())];
}

// Auxiliary functions
template <typename Data>
unsigned long BinaryTreeVec<Data>::NodeVec::index() const noexcept {

    //FIXME return (this - tree->nodes); NON FUNZIONANTE, AL MOMENTO USO QUESTO:

    unsigned long i = 0;
    while (tree->nodes[i] != this) {
        i++;
    }
    return i;     
}

/* ************************************************************************** */

// BinaryTreeVec

//! Constructors from TraverasableContainer
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& container) {
    if (container.Size() > 0) {
        nodes.Resize(container.Size()); //! Resize the vector to hold the nodes
    
        unsigned long index = 0;
        container.Traverse([this, &index](const Data& data) {
            // nodes[index++] = NodeVec(data, this);
            this->nodes[index++] = new NodeVec(data, this);
        });
    }
    this -> size = container.Size(); //!
}

// Construct from a MappableContainer
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& container) noexcept {
    if (container.Size() > 0) {
        nodes.Resize(container.Size()); //! Resize the vector to hold the nodes
    
        unsigned long index = 0;
        container.Map([this, &index](const Data& data) {
            // nodes[index++] = NodeVec(data, this);
            this->nodes[index++] = new NodeVec(data, this);
       });
    }
    this -> size = container.Size(); //! 
}

// Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& tree) {
    nodes.Resize(tree.Size());
    this -> size = tree.Size(); //!
    for (unsigned long i = 0; i < tree.Size(); i++) {
        // nodes[i] = new NodeVec(tree.nodes[i]->Element(), this, tree.nodes[i]->isDummy);
        nodes[i] = new NodeVec(tree.nodes[i]->Element(), this);

    }
}

// Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& tree) noexcept {
    std::swap(nodes, tree.nodes);
    std::swap(size, tree.size);
    for (unsigned long i = 0; i < Size(); i++) {
        nodes[i]->tree = this;
    }
}

// Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
    Clear();
}

// Copy Assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& tree) {
    // if (this != &tree) {
    //     Clear();
    //     nodes.Resize(tree.Size());
    //     for (unsigned long i = 0; i < tree.Size(); i++) {
    //         nodes[i] = new NodeVec(tree.nodes[i]->Element(), this, tree.nodes[i]->isDummy);
    //     }
    // }
    Clear();
    nodes.Resize(tree.Size());
    this -> size = tree.Size(); //!


    for (unsigned long i = 0; i < this->Size(); i++) { //!
        this->nodes[i] = new NodeVec(tree.nodes[i]->Element(), this);
    }

    //todo better implemntation????
    // BinaryTreeVec<Data> *temp = new BinaryTreeVec<Data>(tree);
    // std::swap(*this, *temp);
    // delete temp;

    return *this;
}

// Move Assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& tree) noexcept {
    // std::swap(nodes, tree.nodes);
    // for (unsigned long i = 0; i < tree.Size(); i++) {
    //     nodes[i]->tree = this;
    // }


    // std::swap(size, tree.size);
    // std::swap(nodes, tree.nodes);

    // for (unsigned long i = 0; i < this->Size(); i++) { //!
    //     nodes[i]->tree = this;
    // }

    // for (unsigned long i = 0; i < tree.Size(); i++) { //!
    //     tree.nodes[i]->tree = &tree;
    // }

    // return *this;




    std::swap(this->nodes, tree.nodes);
    std::swap(this->size, tree.size);
    for(ulong i=0; i<this->Size(); i++) nodes[i]->tree = this;
    for(ulong i=0; i< tree.Size(); i++) tree.nodes[i]->tree = &tree;
    return *this;
}

// Comparison operators

// Equality Operator
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& tree) const noexcept {
    // if (Size() != tree.Size()) {
    //     return false;
    // }
    // for (unsigned long i = 0; i < Size(); i++) {
    //     if (nodes[i]->Element() != tree.nodes[i]->Element()) {
    //         return false;
    //     }
    // }
    // return true;

    return MutableBinaryTree<Data>::operator==(tree);
}

// Inequality Operator
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& tree) const noexcept {
    return !(*this == tree);
}

// Auxiliary member functions

// Root const version
template <typename Data>
const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::Root() const {
    if (Empty()) {
       throw std::length_error("Empty tree");
    }
    return *nodes[0];
}

// Root mutable version
template <typename Data>
typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if (Empty()) {
        throw std::length_error("Empty tree");
    }
    return *nodes[0];
}

// Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    // if (Size() > 0) {
    //     for (unsigned long i = 0; i < Size(); i++) {
    //         delete nodes[i];
    //     }
    //     nodes.Clear();
    // }

    for (unsigned long i = 0; i < nodes.Size(); i++) { //!
        if (nodes[i] != nullptr) {
            delete nodes[i];
            nodes[i] = nullptr;
        }
    }
    nodes.Clear();
    this -> size = 0; //!
}

// BreadthTraverse //todo controlla!
template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun function) const {
    if (Size() != 0) {
     
    //! Poiché utilizzo un vector per memorizzare i nodi dell'albero per livelli,
    //! Posso semplicemente iterare attraverso il vector
        for(unsigned long i = 0; i < Size(); i++) {
            // if(nodes->operator[](i) != nullptr) {
            //     // function(nodes[i]->Element());
            //     function(nodes->operator[](i)->Element());
            // }
            if (nodes[i] != nullptr) {
                function(nodes[i]->Element());
            }
        }
    }
}

// BreadthMap //todo controlla!
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun function) {
    if (Size() != 0) {
        for (unsigned long i = 0; i < Size(); i++) {
            // if (nodes->operator[](i) != nullptr) {
            //     function(nodes->operator[](i)->Element());
            //     //function(nodes->operator[](i)->Element());
            // }

            if (nodes[i] != nullptr) {
                function(nodes[i]->Element());
            }
        }
    }
}

/* ************************************************************************** */

}