
namespace lasd {

/* ************************************************************************** */

// Default Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    table = Vector<Data>(DEFAULT_TABLE_SIZE);
    tableStatus = Vector<Status>(DEFAULT_TABLE_SIZE);
    this->size = 0;
}

// Specific Constructor

// Constructor with size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long insertedSize) {
    //! Otherwise, a not prime number will cause a bad performance during the quadratic probing.
    unsigned long newSize = insertedSize;
    if (insertedSize < DEFAULT_TABLE_SIZE) {
        newSize = DEFAULT_TABLE_SIZE;
    }
    
    table = Vector<Data>(newSize);
    tableStatus = Vector<Status>(newSize);
    this->size = 0;
}

// Copy Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht) {
    table = ht.table;
    tableStatus = ht.tableStatus;
    size = ht.size;
}

// Move Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(table, ht.table);
    std::swap(tableStatus, ht.tableStatus);
    std::swap(size, ht.size);
}

// Constructor obtained from a TraversableContainer
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& container) : HashTableOpnAdr(container.Size() * RESIZE_FACTOR) { //! To mantain a good load factor
    InsertAll(container);
}

// Constructor obtained from a TraversableContainer with a specified size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long size, const TraversableContainer<Data>& container) : HashTableOpnAdr(size) {
    InsertAll(container);
}

// Constructor obtained from a MappableContainer
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& container) : HashTableOpnAdr(container.Size() *  RESIZE_FACTOR) { //! To mantain a good load factor
    InsertAll(std::move(container));
}

// Constructor obtained from a MappableContainer with a specified size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long size, MappableContainer<Data>&& container) : HashTableOpnAdr(size) {
    InsertAll(std::move(container));
}

// Copy Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& ht) {
    if(this != &ht) {
    //     HashTableOpnAdr<Data> newTable(ht);
    //     std::swap(table, newTable.table);
    //     std::swap(tableStatus, newTable.tableStatus);
    //     std::swap(this->size, newTable.size);
    // }
    Clear();
    // HashTable<Data>::operator=(ht);

    for (unsigned long i = 0; i < ht.table.Size(); i++) {
        if (ht.tableStatus[i] == Occupied) {
            Insert(ht.table[i]);
        }
    }
    }

    return *this;
}

//! Move Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& ht) noexcept {
    //todo: Attento a leak di memoria!
    if(this != &ht) {
        std::swap(table, ht.table);
        std::swap(tableStatus, ht.tableStatus);
        std::swap(size, ht.size);
    }
    return *this;
}

// Comparison Operator

// Equality Operator
template <typename Data>
inline bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& ht) const noexcept {
    //! Check if the size is the same (therefore, the number of elements is the same).
    if(size != ht.size) {
        return false;
    }
    for(unsigned long i = 0; i < table.Size(); i++) {
        if(tableStatus[i] == Occupied) { //! Therefore logically present
            if(!ht.Exists(table[i])) { //! I don't care about the order of the elements
                return false;
            }
        }
    }

    return true;
}

// Inequality Operator
template <typename Data>
inline bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}

// Specific Member Functions

// Insert copy
template <typename Data>
inline bool HashTableOpnAdr<Data>::Insert(const Data& value) {
    // Check the load factor
    if (size >= table.Size() * LOAD_FACTOR) {
        Resize(table.Size() * RESIZE_FACTOR);
    }

    unsigned long tempIndex = 0;
    unsigned long index = FindEmpty(value, tempIndex);

    if (tableStatus[index] != Occupied) {
        table[index] = value;
        tableStatus[index] = Occupied;
        size++;
        return !Remove(value, ++tempIndex);
    }
    return false;
}

// Insert move
template <typename Data>
inline bool HashTableOpnAdr<Data>::Insert(Data&& value) {
    // Check the load factor
    if (size >= table.Size() * LOAD_FACTOR) {
        Resize(table.Size() * RESIZE_FACTOR);
    }

    unsigned long tempIndex = 0;
    unsigned long index = FindEmpty(value, tempIndex);

    if (tableStatus[index] != Occupied) {
        table[index] = std::move(value);
        tableStatus[index] = Occupied;
        size++;
        return !Remove(value, ++tempIndex);
    }
    return false;

}

// Remove
template <typename Data>
inline bool HashTableOpnAdr<Data>::Remove(const Data& value) {
    unsigned long tempIndex = 0;
    return Remove(value, tempIndex);
}

// Exists
template <typename Data>
inline bool HashTableOpnAdr<Data>::Exists(const Data& value) const noexcept {
    //TODO IN VIA IPOETICA, LASCIARE INDEX A QUALSIASI VALORE È FARE L'HASHING IN Find direttamente.
    unsigned long tempIndex = 0;
    unsigned long index = HashKey(Hashable<Data>()(value));
    // return Find(value, index, tempIndex);
    return Find(index, tempIndex, value);
}

// Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(const unsigned long newSize) {
    Vector<Data> oldTable = std::move(table);
    Vector<Status> oldTableStatus = std::move(tableStatus);

    table = Vector<Data>(newSize);
    tableStatus = Vector<Status>(newSize);
    size = 0; // Reset the size

    for (unsigned long i = 0; i < oldTable.Size(); i++) {
        if (oldTableStatus[i] == Occupied) {
            Insert(std::move(oldTable[i]));
        }
    }
}


// Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear() {   
    HashTableOpnAdr<Data> newTable(DEFAULT_TABLE_SIZE);
    *this = std::move(newTable);
}

// Auxiliary Member Functions

//! HashKey
template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& value, unsigned long& tempIndex) const noexcept{
    unsigned long index = HashKey(Hashable<Data>()(value));
    //TODO: CHECK, IN CASE IMPROVE IT
    return (index+ table.Size() +((tempIndex*tempIndex) + tempIndex)/2) % table.Size();
    // return (((a * index) + b* (tempIndex*tempIndex)) % prime) % table.Size();
    // return ((a * index + b) + (tempIndex * tempIndex)) % table.Size();
}
//todo CHECK:
//! Find
template <typename Data>
inline bool HashTableOpnAdr<Data>::Find(unsigned long& index, unsigned long& probing, const Data& value) const noexcept {
    unsigned long currentIndex = HashKey(value, probing);
    unsigned long attempts = 0;
    
    while (attempts < table.Size()) {
        if (tableStatus[currentIndex] == Empty) {
            return false; // Element not found
        }

        if (tableStatus[currentIndex] == Occupied && table[currentIndex] == value) {
            index = currentIndex; // Element found
            return true;
        }

        currentIndex = HashKey(value, ++probing);
        attempts++;
    }

    return false; // Element not found after checking entire table
}


// FindEmpty
template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& value, unsigned long& index) const noexcept {
    unsigned long tempIndex = HashKey(value, index);
    while (tableStatus[tempIndex] == Occupied && table[tempIndex] != value) {
        tempIndex = HashKey(value, ++index);
    }
    return tempIndex;
}

//! Remove (protected)
template <typename Data>
inline bool HashTableOpnAdr<Data>::Remove(const Data& value, unsigned long& index) noexcept{
    unsigned long tempIndex = 0;
    if (Find(tempIndex, index, value)) { //!Find(value, index, tempIndex)
        tableStatus[tempIndex] = Deleted;
        size--;
        index = 0;
        
        // Check the load factor
        if (size < table.Size() * HASHTABLE_SHRINK_FACTOR && table.Size() > DEFAULT_TABLE_SIZE) { //! 1/8 is the minimum load factor
            Resize(table.Size() / RESIZE_FACTOR);
        }
        return true;
    }
    index = 0;
    return false;
}

/* ************************************************************************** */

} // namespace lasd