
namespace lasd {

/* ************************************************************************** */

// Default constructor  
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    table = Vector<Data>(DEFAULT_TABLE_SIZE);
    tableStatus = Vector<Status>(DEFAULT_TABLE_SIZE);
    this->size = 0;
}

// Specific constructor

// Constructor with size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long insertedSize) {
    unsigned long newSize = insertedSize;
    AdjustTableSize(newSize);
    table = Vector<Data>(newSize);
    tableStatus = Vector<Status>(newSize);
    this->size = 0;
}

// Copy constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& hashTable): HashTable<Data>(hashTable) {
    table = hashTable.table;
    tableStatus = hashTable.tableStatus;
}

// Move constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& hashTable) noexcept : HashTable<Data>(std::move(hashTable)) {
    Swap(table, hashTable.table);
    Swap(tableStatus, hashTable.tableStatus);
}

// Constructor obtained from a TraversableContainer
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& container) : HashTableOpnAdr(container.Size() * RESIZE_FACTOR) { //! To mantain a good load factor
    InsertAll(container);
}

// Constructor obtained from a TraversableContainer with specific size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long size, const TraversableContainer<Data>& container) : HashTableOpnAdr(size) {
    InsertAll(container);
}

// Constructor obtained from a MappableContainer
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& container) : HashTableOpnAdr(container.Size() *  RESIZE_FACTOR) { //! To mantain a good load factor
    InsertAll(std::move(container));
}

// Constructor obtained from a MappableContainer with specific size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long size, MappableContainer<Data>&& container) : HashTableOpnAdr(size) {
    InsertAll(std::move(container));
}

// Copy Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& hashTable) {
    HashTable<Data>::operator=(hashTable);
    table = hashTable.table;
    tableStatus = hashTable.tableStatus;
    return *this;
}

// Move Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& hashTable) noexcept {
    HashTable<Data>::operator=(std::move(hashTable));
    std::swap(table, hashTable.table);
    std::swap(tableStatus, hashTable.tableStatus);
    return *this;
}

// Comparison operators

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

// Specific member functions

// Insert Copy
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

// Insert Move
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
    unsigned long tempIndex = 0;
    unsigned long index = HashKey(Hashable<Data>()(value));
    return Find(index, tempIndex, value);
}

// Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(const unsigned long insertedSize) {
    Vector<Data> oldTable = std::move(table);
    Vector<Status> oldTableStatus = std::move(tableStatus);

    unsigned long newSize = insertedSize;
    AdjustTableSize(newSize);
    table = Vector<Data>(newSize);
    tableStatus = Vector<Status>(newSize);
    size = 0;

    for(unsigned long i = 0; i < oldTable.Size(); i++) {
        if(oldTableStatus[i] == Occupied) {
            Insert(std::move(oldTable[i]));
        }
    }
}

// Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    table.Clear();
    tableStatus.Clear();
    size = 0;
}

// Auxiliary Member Functions

// HashKey
template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& value, unsigned long& tempIndex) const noexcept{
    unsigned long index = HashKey(Hashable<Data>()(value));

    // return (index + tempIndex) % GetTableSize();
    return (index + (tempIndex * tempIndex)) % GetTableSize();

}

// Find
template <typename Data>
inline bool HashTableOpnAdr<Data>::Find(unsigned long& index, unsigned long& probing, const Data& value) const noexcept {
    unsigned long currentIndex = HashKey(value, probing);
    unsigned long attempts = 0;

    while (attempts < GetTableSize()) {
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

    return false;

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

// Remove (protected)
template <typename Data>
inline bool HashTableOpnAdr<Data>::Remove(const Data& value, unsigned long& index) noexcept{
    unsigned long tempIndex = 0;
    if (Find(tempIndex, index, value)) {
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

// GetTableSize
template <typename Data>
unsigned long HashTableOpnAdr<Data>::GetTableSize() const noexcept {
    return table.Size();
}



/* ************************************************************************** */

}
