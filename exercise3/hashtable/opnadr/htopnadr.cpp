
namespace lasd {

/* ************************************************************************** */

// Default Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    table = Vector<Data>(DEFAULT_TABLE_SIZE);
    tableStatus = Vector<Status>(DEFAULT_TABLE_SIZE);
    size = 0;
}

// Specific Constructor

// Constructor with size
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long insertedSize) {
    //! Otherwise, a not prime number will cause a bad performance during the quadratic probing.
    unsigned long newSize = nextPrime(insertedSize);
    if (insertedSize < DEFAULT_TABLE_SIZE) {
        newSize = DEFAULT_TABLE_SIZE;
    }
       
    table = Vector<Data>(newSize);
    tableStatus = Vector<Status>(newSize);
    size = 0;
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
        HashTableOpnAdr<Data> tmp(ht);
        std::swap(table, tmp.table);
        std::swap(tableStatus, tmp.tableStatus);
        std::swap(size, tmp.size);
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
        return !(Remove(value, ++tempIndex));
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

//! Exists
template <typename Data>
inline bool HashTableOpnAdr<Data>::Exists(const Data& value) const noexcept {
    //TODO IN VIA IPOETICA, LASCIARE INDEX A QUALSIASI VALORE È FARE L'HASHING IN Find direttamente.
    unsigned long tempIndex = 0;
    unsigned long index = HashKey(Hashable<Data>()(value));
    return Find(value, index, tempIndex);
}

// Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(const unsigned long insertedSize) {
    //TODO CHECK:
    // Round the newSize to the next prime number
    unsigned long newSize = nextPrime(insertedSize);

    // Use the copy constructor to create a new table
    HashTableOpnAdr<Data> newTable(newSize);

    // Use the insert function to copy all the elements from the old table to the new one
    for(unsigned long i = 0; i < table.Size(); i++) {
        if(tableStatus[i] == Occupied) {
            newTable.Insert(table[i]);
        }
    }

    // Swap the new table with the old one
    *this = std::move(newTable);
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
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& value, unsigned long& numberOfCollisions) const noexcept{
    unsigned long index = HashKey(Hashable<Data>()(value));
    //TODO: CHECK, IN CASE IMPROVE IT
    // return (index+ table.Size() +((tempIndex*tempIndex) + tempIndex)/2) % table.Size();
    return (index + (numberOfCollisions * numberOfCollisions)) % table.Size(); //! Classic Quadratic probing
}

//! Find
template <typename Data>
inline bool HashTableOpnAdr<Data>::Find(const Data& element, ulong& index, ulong& prob_index) const noexcept {
    ulong tmp_index = HashKey(element, prob_index);
    ulong jumps = 0;
    do{
        if(jumps == table.Size() - 1) {
            return false;
        }
        if((table[tmp_index] == element) && (tableStatus[tmp_index] == Occupied)) {
            index = tmp_index;
            return true;
        }
        tmp_index = HashKey(element, ++prob_index);
        jumps++;
    } while((!tableStatus[tmp_index]) == Empty);
    return false;
}

// FindEmpty
template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& value, unsigned long& index) const noexcept {
    index = 0; //! Useless, but sugar don't ruin the drink
    unsigned long tempIndex = HashKey(value, index);
    while (tableStatus[tempIndex] == Occupied) {
        tempIndex = HashKey(value, ++index);
    }
    return tempIndex;
}

// Remove (protected)
template <typename Data>
inline bool HashTableOpnAdr<Data>::Remove(const Data& value, unsigned long& index) noexcept{
    unsigned long tempIndex = 0;
    if (Find(value, index, tempIndex)) {
        tableStatus[index] = Deleted;
        size--;
        index = 0;
        
        // Check the load factor
        if (size < table.Size() * SHRINK_FACTOR && table.Size() > DEFAULT_TABLE_SIZE) { //! 1/8 is the minimum load factor
            Resize(table.Size() / RESIZE_FACTOR);
        }
        return true;
    }
    index = 0;
    return false;
}


// todo CHECK:

// NextPrime
//! It's a function that returns the next prime number after the given number, it's essential for the table size.
template <typename Data>
unsigned long HashTableOpnAdr<Data>::nextPrime(unsigned long num) const noexcept {
    while (!isPrime(num)) {
        num++;
    }
    return num;
}

// isPrime
//! Supplmentary function for the nextPrime function.
template <typename Data>
inline bool HashTableOpnAdr<Data>::isPrime(unsigned long num) const noexcept {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (unsigned long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
/* ************************************************************************** */

} // namespace lasd