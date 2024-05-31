
namespace lasd {

/* ************************************************************************** */
// todo RIMUOVERE tableSize come attributo e usare una macro, in modo tale da risparmiare spazio in memoria
// Default Constructors
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
    table = Vector<BST<Data>>(tableSize); 
}

// Copy Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) {
    // todo Da controllare!
    if (this != &ht) {
        table = Vector<BST<Data>>(ht.table.Size());
        for (unsigned long i = 0; i < table.Size(); ++i) {
            table[i] = ht.table[i]; //! Assuming the BST has a correct copy constructor
        }
        size = ht.size;  //! The elements present in the table
        tableSize = ht.tableSize; //? Serve davvero, oppure posso usare una macro?
    }
}

// Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept {
    std::swap(table, ht.table);
    std::swap(size, ht.size);
    std::swap(tableSize, ht.tableSize); //? Serve davvero?
}

// Specific Constructors

// Constructor with size
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long newSize) {
    // unsigned long newTableSize = newSize;
    //? Devo controllare che newSize sia potenza di 2? Impostando tableSize alla potenza di 2 più vicina??
    if (newSize < tableSize) {
        // todo gestire il caso in cui newSize sia più piccolo di tableSize e quindi fargli fare una tabella che conseguentemente renderà la performance peggiori
        // todo controllare:  tableSize = std::pow(2, std::ceil(log2((newSize <= 16) ? 16 : newSize))); //! Se vuoi mantenere la dimensione della tabella come una potenza di 2
        std::cerr << "WARN: This size is too small, and for this reason the performance will be very low." << std::endl;
        // newTableSize = tableSize;
    }else {
        tableSize = newSize;
    }
    table = Vector<BST<Data>>(tableSize);
    size = 0; //! The elements present in the table
}

// Constructor obtained from a TraversableContainer
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& container) : HashTableClsAdr(container.Size()){
    InsertAll(container); //! Controllare per bene la Insert classica!
}

// Constructor obtained from a TraversableContainer with a specified size
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long newSize, const TraversableContainer<Data>& container) : HashTableClsAdr(newSize) {
    InsertAll(container); //! Controllare per bene la Insert classica!
}

// Constructor obtained from a MappableContainer
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& container) : HashTableClsAdr(container.Size()){
    InsertAll(std::move(container)); //! Controllare per bene la Insert classica!
}

// Constructor obtained from a MappableContainer with a specified size
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long newSize, MappableContainer<Data>&& container) : HashTableClsAdr(newSize) {
    InsertAll(std::move(container)); //! Controllare per bene la Insert classica!
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
        HashTableClsAdr<Data> temp(ht); // Copy Constructor used
        std::swap(*this, temp);
        //temp will be destroyed automatically
    }
    return *this;
}

// Move Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept {

    //! Praticamente il move constructor
    // if (this != &ht) {
    //     std::swap(tableSize, ht.tableSize);
    //     std::swap(table, ht.table);
    //     std::swap(size, ht.size);
    // }

    if (this != &ht) {
        tableSize = std::move(ht.tableSize);
        table = std::move(ht.table);
        size = std::move(ht.size);

        ht.tableSize = 0;
        ht.size = 0;
    }
    
    return *this;
}

// Comparison operators
template <typename Data>
inline bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept {
    if (size != ht.size || table.Size() != ht.table.Size()) { //todo Ha senso ritornare false se le dimensioni delle due tabelle sono diverse?
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
    if (table[index].Remove(value)) { //! Exists() is necessary? table[index].Exists(value) && 
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
        unsigned long newTableSize = newSize;;

        if (newSize == 0) { 
            Clear();
            return; // Exit early since the table is cleared
        }
        
        if (newSize < tableSize) {
            // Warning about performance degradation
            newTableSize = tableSize;
            std::cerr << "WARN: This size is too small, and for this reason the performance will be very low." << std::endl;
        }

        Vector<BST<Data>> newTable(newTableSize);
        size = 0;
        std::swap(table, newTable);
        std::swap(tableSize, newTableSize);
       
        for (unsigned long i = 0; i < newTableSize; ++i) {
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
/* ************************************************************************** */

} // namespace lasd