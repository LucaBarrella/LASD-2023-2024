
namespace lasd {

/* ************************************************************************** */

// NodeVec

// Constructor const
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& value, BinaryTreeVec *tree) : value(value), tree(tree), isDummy(false) {};

// Constructor for Dummy Nodes
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(BinaryTreeVec *tree) : isDummy(true), tree(tree) {};

// Constructor mutable
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& value, BinaryTreeVec *tree) : value(std::move(value)),  tree(std::move(tree)), isDummy(false) {};

// Copy Assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node) {
    //! value = node.value;
    if (!node.isDummy) {
        value = node.value;
        isDummy = false;
    }

    return *this;
}

// Move Assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept {
    //! std::swap(value, node.value);
    if (!node.isDummy) {
        std::swap(value, node.value);
        isDummy = false;
    }

    return *this;
}

// Comparison operators
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec& node) const noexcept {
    return Node::operator==(node);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec& node) const noexcept {
    return Node::operator!=(node);
}

// Specific member functions

// Element const
template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return tree->data[index()];
}

// Element mutable
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return tree->data[index()];
}

// HasLeftChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    if (isDummy || left(index())->isDummy){
        return false;
    }
    return left(index()) < tree->Size();
}

// HasRightChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    if (isDummy || right(index())->isDummy){
        return false;
    }
    return right(index()) < tree->Size();
}

// LeftChild const
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if (!HasLeftChild()) {
        throw std::out_of_range("No left child");
    }
    return tree->nodes[left(index())];
}

// LeftChild mutable
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if (!HasLeftChild()) {
        throw std::out_of_range("No left child");
    }
    return tree->nodes[left(index())];
}

// RightChild const
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if (!HasRightChild()) {
        throw std::out_of_range("No right child");
    }
    return tree->nodes[right(index())];
}

// RightChild mutable
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::RightChild() {
    if (!HasRightChild()) {
        throw std::out_of_range("No right child");
    }
    return tree->nodes[right(index())];
}

// Auxiliary functions
template <typename Data>
unsigned long BinaryTreeVec<Data>::NodeVec::index() const noexcept {
    return (this - &(*tree->nodes[0])) / sizeof(NodeVec);

    //! this è un puntatore al nodo corrente, &(*tree->nodes[0]) è un puntatore al primo nodo nell'array, 
    //! sizeof(NodeVec) è la dimensione di un nodo. 
    //! Quindi, la differenza tra this e il puntatore al primo nodo, diviso per la dimensione di un nodo,
    //! dovrebbe dare l'indice del nodo corrente.
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
            nodes[index++] = NodeVec(data, this);
        });
    }
}

// Construct from a MappableContainer
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& container) {
    if (container.Size() > 0) {
        nodes.Resize(container.Size()); //! Resize the vector to hold the nodes
    
        unsigned long index = 0;
        container.Map([this, &index](const Data& data) {
            nodes[index++] = NodeVec(data, this);
       });
    }
}

// Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& tree) {
    nodes.Resize(tree.Size());
    for (unsigned long i = 0; i < tree.Size(); i++) {
        nodes[i] = new NodeVec(tree.nodes[i]->Element(), this, tree.nodes[i]->isDummy);
    }
}

// Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& tree) noexcept {
    std::swap(nodes, tree.nodes);
    for (unsigned long i = 0; i < tree.Size(); i++) {
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

    BinaryTreeVec<Data> *temp = new BinaryTreeVec<Data>(tree);
    std::swap(*this, *temp);
    delete temp;

    return *this;
}

// Move Assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& tree) noexcept {
    // std::swap(nodes, tree.nodes);
    // for (unsigned long i = 0; i < tree.Size(); i++) {
    //     nodes[i]->tree = this;
    // }

    std::swap(size, tree.size);
    std::swap(nodes, tree.nodes);

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
    if (Size() == 0) {
        throw std::length_error("Empty tree");
    }
    return *nodes[0];
}

// Root mutable version
template <typename Data>
typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if (Size() == 0) {
        throw std::length_error("Empty tree");
    }
    // return *nodes[0];
    return *(nodes->operator[](0));
}

// Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    if (Size() > 0) {
        for (unsigned long i = 0; i < Size(); i++) {
            delete nodes[i];
        }
        nodes.Clear();
    }
}

// BreadthTraverse
template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun function) const {
    // if (Size() == 0) {
    //     throw std::length_error("Empty tree");
    // }
    // QueueVec<NodeVec*> queue(Size());
    // queue.Enqueue(&Root());
    // while (!queue.Empty()) {
    //     NodeVec* node = queue.Dequeue();
    //     functor(node->Element());
    //     if (node->HasLeftChild()) {
    //         queue.Enqueue(&node->LeftChild());
    //     }
    //     if (node->HasRightChild()) {
    //         queue.Enqueue(&node->RightChild());
    //     }
    // }

    //! Poiché utilizzo un vector per memorizzare i nodi dell'albero per livelli,
    //! Posso semplicemente iterare attraverso il vector
    for(unsigned long i = 0; i < Size(); i++) {
        if(nodes->operator[](i) != nullptr) {
            // function(nodes[i]->Element());
            function(nodes->operator[](i)->Element());
        }
    }
}

// BreadthMap
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun function) {
    if (Size() == 0) {
    //     throw std::length_error("Empty tree");
    // }
    // QueueVec<NodeVec*> queue(Size());
    // queue.Enqueue(&Root());
    // while (!queue.Empty()) {
    //     NodeVec* node = queue.Dequeue();
    //     node->Element() = functor(node->Element());
    //     if (node->HasLeftChild()) {
    //         queue.Enqueue(&node->LeftChild());
    //     }
    //     if (node->HasRightChild()) {
    //         queue.Enqueue(&node->RightChild());
    //     }
    // }
    for (unsigned long i = 0; i < Size(); i++) {
        if (nodes->operator[](i) != nullptr) {
            function(nodes->operator[](i)->Element());
            //function(nodes->operator[](i)->Element());
        }
    }
}


//! InitializeVector
// template <typename Data>
// void BinaryTreeVec<Data>::InitializeVector(unsigned long size) {
// }



/* ************************************************************************** */

}
