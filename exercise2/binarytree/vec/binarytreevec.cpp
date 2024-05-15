
namespace lasd {

/* ************************************************************************** */

///////////////////////////////NODEVEC/////////////////////////////////////////////

//Copy assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node) {
    info = node.info;
    curr = node.curr;
    tree = node.tree;
    return *this;
}

//Move assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept {
    std::swap(info, node.info);
    std::swap(curr, node.curr);
    std::swap(tree, node.tree);
    return *this;
}

//Element
template <typename Data>
const Data & BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return info;
}

//Element mutable
template <typename Data>
Data & BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return info;
}

//IsLeaf
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return !(HasRightChild() && HasLeftChild());
}

//HasRightChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return ((2*curr+2) < tree->Size());
}

//HasLeftChild
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return ((2*curr+1) < tree->Size());
}

//RightChild
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(HasRightChild()) {
        return *(tree->operator[](2*curr+2));
    } else {
        throw std::out_of_range("Right child does not exists!");
    }
}

//LeftChild
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(HasLeftChild()) {
        return *(tree->operator[](2*curr+1));
    } else {
        throw std::out_of_range("Left child does not exists!");
    }
}

//RightChild (mutable)
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(HasRightChild()) {
        return *(tree->operator[](2*curr+2));
    } else {
        throw std::out_of_range("Right child does not exists!");
    }
}

//LeftChild (mutable)
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(HasLeftChild()) {
        return *(tree->operator[](2*curr+1));
    } else {
        throw std::out_of_range("Left child does not exists!");
    }    
}

///////////////////////////////BINARYTREEVEC/////////////////////////////////////////////

//Specific constructors
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data> & trav_con) {

    size = trav_con.Size();

    if(size>0) {
        //We create a new vector wich contains NodeVec*
        vec = new Vector<NodeVec*>(size);
        ulong i = 0;

        trav_con.Traverse([this, &i](const Data & data){
            //For each element of the vector we create a node
            NodeVec* node = new NodeVec(data, i, vec);
            //We add the newly created node in the vector
            vec->operator[](i) = node;
            i++;
        });

    }    
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> && map_con) noexcept {
    size = map_con.Size();
    if(size > 0) {
        vec = new Vector<NodeVec*>(size);
        ulong i=0;
        map_con.Map([this, &i](Data& data) {
            NodeVec* node = new NodeVec(data, i, vec);
            vec->operator[](i) = node;
            i++;
        });
    } 
}

//Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec & bt) {

    size = bt.Size();

    if(size>0) {
        vec = new Vector<NodeVec*>(size);
        for(ulong i=0; i<size; i++) {
            NodeVec* node = new NodeVec(bt.vec->operator[](i)->Element(), i, vec);
            vec->operator[](i) = node;
        }
    }
}

//Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data> && bt) noexcept {
    std::swap(size, bt.size);
    std::swap(vec, bt.vec);
}

//Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {

    //We delete all node in the vector with Clear
    Clear();

}

//Copy assigment
template <typename Data>
BinaryTreeVec<Data> & BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data> & bt) {

    //We create tmp tree with copy constructor
    BinaryTreeVec<Data>* copied_tree = new BinaryTreeVec<Data>(bt);

    std::swap(*this, *copied_tree);

    delete copied_tree;
    return *this;
}

//Move assigment 
template <typename Data>
BinaryTreeVec<Data> & BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data> && bt) noexcept {

    std::swap(size, bt.size);
    std::swap(vec, bt.vec);

    return *this;
}

//Root
template <typename Data>
const BinaryTreeVec<Data>::Node & BinaryTreeVec<Data>::Root() const{

    if(size>0) {
        return *(vec->operator[](0));
    } else {
        throw std::length_error("Empty tree");
    }
}

//Mutable Root
template <typename Data>
BinaryTreeVec<Data>::MutableNode & BinaryTreeVec<Data>::Root(){

    if(size>0) {
        return *(vec->operator[](0));
    } else {
        throw std::length_error("Empty tree");
    }
}

//Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear() {

    if(size>0) {

        for(ulong i=0; i<size; i++) {

            delete vec->operator[](i);
            
        }
        delete vec;
    }

    vec = nullptr;
    size = 0;
}

//BreadthTraverse
template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun trav_fun) const {
    for(ulong i=0; i<size; i++) {
        if(vec->operator[](i) != nullptr) {
            trav_fun(vec->operator[](i)->Element());
        }
    }
}

//BreadthMap
template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun map_fun) {
    for(ulong i=0; i<size; i++) {
        if(vec->operator[](i) != nullptr) {
            map_fun(vec->operator[](i)->Element());
        }
    }
}

























}
/* ************************************************************************** */

