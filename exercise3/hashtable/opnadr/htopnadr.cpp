
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
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht) : HashTable<Data>(ht) {
    table = new Data[tableSize] {};
    tableStatus = new Status[tableSize] {};
    for(unsigned long i = 0; i < tableSize; i++){
        table[i] = ht.table[i];
        tableStatus[i] = ht.tableStatus[i];
    }
}

// Move constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept : HashTable<Data>(std::move(ht)) {
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
    //!  HashTable<Data>::operator=(std::move(ht));
    std::swap(table, ht.table);
    std::swap(tableStatus, ht.tableStatus);
    // std::swap(tableSize, ht.tableSize); //todo removable, maybe
    return *this;
}

// Comparison operators

// Equality operator
template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& ht) const noexcept {
    if(tableSize != ht.tableSize) return false;
    for(unsigned long i = 0; i < table.Size(); i++){
        if(table[i] != ht.table[i] || tableStatus[i] != ht.tableStatus[i]) return false;
    }
    return true;
}

// Inequality operator
template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}


// Specific member functions

// Insert //todo implementare una strategia di probing piu' efficiente, tipo quadratic probing o double hashing
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& value) {
    if (Exists(value)) return false;

    if(size >= table.Size()* LOAD_FACTOR) Resize(table.Size()* RESIZE_FACTOR);
    
    // Se non esiste, devo trovare la posizione in cui inserire il valore
    unsigned long index = FindEmpty(value, 0);

    // Inserisco il valore nella posizione trovata
    table[index] = value;
    tableStatus[index] = Status::Occupied;
    ++size;
    return true;
}

// Insert moving
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& value) {
    if (Exists(value)) return false;

    if(size >= table.Size()* LOAD_FACTOR) Resize(table.Size()* RESIZE_FACTOR);
    
    // Se non esiste, devo trovare la posizione in cui inserire il valore
    unsigned long index = FindEmpty(value, 0); // Cerco la prima posizione vuota

    // Inserisco il valore nella posizione trovata
    table[index] = std::move(value);
    tableStatus[index] = Status::Occupied;
    ++size;
    return true;
}

// Remove
template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& value) {
    // todo Migliorare, attualmente non è efficiente!
    // Se non esiste, restituisco false
    if(!Exists(value)) return false;

    // Se la size è minore del 50% della grandezza della tabella, la riduco del 25% 
    // todo chiedere a Mogavero se è giusto, ridurre del 25% nel caso in cui il numero di elementi sia minore del 50% della grandezza della tabella.
    if (size <= table.Size() / RESIZE_FACTOR) Resize(table.Size()* SHRINK_FACTOR);

    // Se esiste, devo trovare la posizione in cui si trova il valore
    unsigned long index = Find(value, index, 0); // Cerco la posizione in cui si trova il valore

    // Rimuovo il valore dalla posizione trovata
    tableStatus[index] = Status::Deleted;
    --size;
    return true;
}

// Exists
template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& value) const noexcept {
    unsigned long index = HashKey(Hashable<Data>()(value));
    return Find(value, 0, index);
}

// Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(const unsigned long newSize) {
    // todo Rivedere:
    // todo magari avrebbe più senso chiamare un costruttore di copia con la nuova size e poi fare uno swap
    Data* newTable = new Data[newSize] {};
    Status* newTableStatus = new Status[newSize] {};
    for(unsigned long i = 0; i < tableSize; i++){
        if(tableStatus[i] == Status::Occupied){
            unsigned long index = HashKey(Hashable<Data>()(table[i]));
            while(newTableStatus[index] == Status::Occupied){
                index = (index + 1) % newSize;
            }
            newTable[index] = table[i];
            newTableStatus[index] = Status::Occupied;
        }
    }
    delete[] table;
    delete[] tableStatus;
    table = newTable;
    tableStatus = newTableStatus;
    tableSize = newSize;
}

// Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    delete[] table;
    delete[] tableStatus;
    table = new Data[tableSize] {};
    tableStatus = new Status[tableSize] {};
    size = 0;
}


// Auxiliary member functions

// HashKey
template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& value, unsigned long i) const noexcept {
    ulong index = HashKey(Hashable<Data>()(value));
    // return (index + i*i) % tableSize;
    return (index + tableSize + ((i * i) + i)/2) % tableSize;
    // return (index + C1 * i + C2 * i^2) % table.Size();
    // return (((a * hash(d)) + b) % p) % table.Size();
    // return (a*Hashable<Data>()(value) + b) % tableSize;

}



// Find
template <typename Data>
bool HashTableOpnAdr<Data>::Find(const Data& value, unsigned long& i, unsigned long& index) const noexcept {
    // index = HashKey(value, i);
    // while(tableStatus[index] != Status::Free && table[index] != value){
    //     index = HashKey(value, ++i);
    // }
    // return tableStatus[index] == Status::Occupied;
    for (unsigned long i = 0; i < tableSize; i++) {
        if (table[i] == value && tableStatus[i] == Status::Occupied) {
            return true;
        }
    }
    return false;
}

// FindEmpty
template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& value, unsigned long& i) const noexcept{
    // unsigned long tmp = HashKey(value, i);
    // while(tableStatus[tmp] == Status::Occupied){
    //     tmp = HashKey(value, ++i);
    // }
    // return tmp;

    // Implementazione banale usando un linear probing, credo.
    for (unsigned long i = 0; i < tableSize; i++) {
        if (tableStatus[i] != Status::Occupied) {
            return i;
        }
    }
}




/* ************************************************************************** */

} // namespace lasd