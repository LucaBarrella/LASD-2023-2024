
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    table = new Data[tableSize] {};
    tableStatus = new Status[tableSize] {};
}

// Specific constructor

// Constructor of a given size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long size) {
    table = new Data[size] {};
    tableStatus = new Status[size] {};
    tableSize = size; //todo removable, maybe
}

// Constructor obtained from a TraversableContainer
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& container) : HashTableOpnAdr(container.Size()*2) { //todo why *2?
    InsertAll(container);
}

// Constructor obtained from a TraversableContainer with specification of the size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long size, const TraversableContainer<Data>& container) : HashTableOpnAdr(size) {
    InsertAll(container);
}

// Constructor obtained from a MappableContainer
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& container) : HashTableOpnAdr(container.Size()*2) {
    InsertAll(std::move(container));
}

// Constructor obtained from a MappableContainer with specification of the size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long size, MappableContainer<Data>&& container) : HashTableOpnAdr(size) {
    InsertAll(std::move(container));
}

// Copy constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht) : HashTableOpnAdr(ht.tableSize) {
    table = new Data[tableSize] {};
    tableStatus = new Status[tableSize] {};
    for(unsigned long i = 0; i < tableSize; i++){
        table[i] = ht.table[i];
        tableStatus[i] = ht.tableStatus[i];
    }
}

// Move constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(table, ht.table);
    std::swap(tableStatus, ht.tableStatus);
    // std::swap(tableSize, ht.tableSize); //todo removable, maybe
}

// Destructor
template <typename Data>
HashTableOpnAdr<Data>::~HashTableOpnAdr() {
    delete[] table;
    delete[] tableStatus;
}

// Copy assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& ht) {
    if(this != &ht){
        HashTableOpnAdr<Data> temp(ht);
        std::swap(table, temp.table);
        std::swap(tableStatus, temp.tableStatus);
    }
    return *this;
}

// Move assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& ht) noexcept {
    //! It's the fucking same as the move constructor
    std::swap(table, ht.table);
    std::swap(tableStatus, ht.tableStatus);
    // std::swap(tableSize, ht.tableSize); //todo removable, maybe
    return *this;
}

// Comparison Operator

// Equality Operator
//todo implemntare as soon as possible.




/* ************************************************************************** */

} // namespace lasd