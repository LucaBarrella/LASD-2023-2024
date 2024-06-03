
namespace lasd {

/* ************************************************************************** */
// Default Constructors
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
    table = Vector<BST<Data>>(DEFAULT_TABLE_SIZE); 
}

// Copy Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) {
    if (this != &ht) {
        table = Vector<BST<Data>>(ht.table.Size());
        for (unsigned long i = 0; i < table.Size(); ++i) {
            table[i] = ht.table[i]; //! Assuming the BST has a correct copy constructor
        }
        size = ht.size;  //! The elements present in the table
    }
}

// Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept {
    std::swap(table, ht.table);
    std::swap(size, ht.size);
}

// Specific Constructors

// Constructor with size
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long insertedSize) {
    unsigned long newSize = insertedSize;
    AdjustTableSize(newSize);

    table = Vector<BST<Data>>(newSize);
    size = 0;    
}

// Constructor obtained from a TraversableContainer
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& container) : HashTableClsAdr(container.Size()){
    InsertAll(container);
}

// Constructor obtained from a TraversableContainer with a specified size
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long newSize, const TraversableContainer<Data>& container) : HashTableClsAdr(newSize) {
    InsertAll(container);
}

// Constructor obtained from a MappableContainer
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& container) : HashTableClsAdr(container.Size()){
    InsertAll(std::move(container));
}

// Constructor obtained from a MappableContainer with a specified size
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long newSize, MappableContainer<Data>&& container) : HashTableClsAdr(newSize) {
    InsertAll(std::move(container));
}

// Destructor
template <typename Data>
HashTableClsAdr<Data>::~HashTableClsAdr() {
    Clear();
}

// Copy Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& ht) {

    if (this != &ht) {
        HashTable<Data>::operator=(ht);
        table = Vector<BST<Data>>(ht.table.Size());
    }
    return *this;
}

// Move Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept {
    if (this != &ht) {
        HashTable<Data>::operator=(std::move(ht));
        std::swap(table, ht.table);
    }
    
    return *this;
}

// Comparison operators
template <typename Data>
inline bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept {
    if (size != ht.size) {
        return false;
    }
    for (unsigned long i = 0; i < table.Size(); ++i) {
        bool allExist = true;
        table[i].Traverse(
            [&ht, &allExist](const Data& data) {
                if (!ht.Exists(data)) {
                    allExist = false;
                }
            }
        );
        if (!allExist) {
            return false;
        }
    }
    return true;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}

// Specific member functions

// Insert const version
template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& value) {
    unsigned long index = HashKey(Hashable<Data>()(value));
    if (table[index].Insert(value)) {
        size++;
        return true;
    }
    return false;
}

// Insert mutable version
template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& value) {
    unsigned long index = HashKey(Hashable<Data>()(std::move(value)));
    if (table[index].Insert(std::move(value))) {
        size++;
        return true;
    }
    return false;
}

// Remove
template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& value) {
    unsigned long index = HashKey(Hashable<Data>()(value));
    if (table[index].Remove(value)) {
        size--;
        return true;
    }
    return false;
}

// Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& value) const noexcept {
    unsigned long index = HashKey(Hashable<Data>()(value));
    return table[index].Exists(value);
}

// Resize
template <typename Data>
void HashTableClsAdr<Data>::Resize(const unsigned long newSize) {
    if (newSize != table.Size()) {
        unsigned long newTableSize = newSize;
        AdjustTableSize(newTableSize);

        if (newSize == 0) { 
            Clear();
            return; // Exit early since the table is cleared
        }
        
        if (newSize < GetTableSize()) {
            // Warning about performance degradation
            std::cerr << "WARN: This size is too small, and for this reason the performance will be very low." << std::endl;
        }

        Vector<BST<Data>> newTable(newTableSize);
        size = 0;
        std::swap(table, newTable);
       
        for (unsigned long i = 0; i < newTable.Size(); ++i) {
            InsertAll(newTable[i]);
        }
    }
}

// Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    for (unsigned long i = 0; i < table.Size(); ++i) {
        table[i].Clear(); //! Assuming the BST has a correct Clear method
    }
    size = 0;
}

// GetTableSize
template <typename Data>
unsigned long HashTableClsAdr<Data>::GetTableSize() const noexcept {
    return table.Size();
}
/* ************************************************************************** */

} // namespace lasd