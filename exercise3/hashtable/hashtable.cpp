
namespace lasd {

/* ************************************************************************** */

// Hashable

// Operator ()
template <>
class Hashable <int> {
public:
    unsigned long operator()(const int& data) const noexcept {
        return data * data;
    }
};

template <>
class Hashable <double> {
public:
    unsigned long operator()(const double& data) const noexcept {
        // long integerPart = static_cast<long>(data);
        long integerPart = floor(data); //! implementation by my Professor
        // long decimalPart = static_cast<long>((data - integerPart) * 1000000);
        long decimalPart = pow(2, 24) * (data - integerPart); //! implementation by my Professor
        return integerPart * decimalPart;
    }
};

// string
template <>
//! I used the FNV-1a (Fowler-Noll-Vo) hash function
class Hashable <std::string> {
public:
    unsigned long operator()(const std::string& data) const noexcept {
        unsigned long hash = 2166136261UL;
        for (unsigned long i = 0; i < data.length(); i++) {
            hash ^= data[i];
            hash *= 16777619;
        }
        return hash;
    }
};


/* ************************************************************************** */

// HashTable

// Constructors

// Default constructor
template <typename Data> //FIXME ERROR
HashTable<Data>::HashTable() {
    a = distributionA(generator);
    b = distributionB(generator);
}

// Copy constructor
template <typename Data>
HashTable<Data>::HashTable(const HashTable<Data>& hashTable) {
    size = hashTable.size;
    // tableSize = hashTable.tableSize;
    a = hashTable.a;
    b = hashTable.b;
}

// Move constructor
template <typename Data>
HashTable<Data>::HashTable(HashTable<Data>&& hashTable) noexcept {
    std::swap(size, hashTable.size);
    std::swap(a, hashTable.a);
    std::swap(b, hashTable.b);
}

// Copy assignment
template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(const HashTable<Data>& hashTable) {
    a = hashTable.a;
    b = hashTable.b;
    size = hashTable.size;
    return *this;
}

// Move assignment
template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(HashTable<Data>&& hashTable) noexcept {
    std::swap(a, hashTable.a);
    std::swap(b, hashTable.b);
    std::swap(size, hashTable.size);
    return *this;
}

// HashKey
template <typename Data>
unsigned long HashTable<Data>::HashKey(const Data& data) const noexcept {
    // return (a * data + b) % tableSize;
    return HashKey(hash(data));
}

template <typename Data>
unsigned long HashTable<Data>::HashKey(unsigned long key) const noexcept {
    return (((a * key + b) % prime) % GetTableSize());
}

// AdjustTableSize
template <typename Data>
void HashTable<Data>::AdjustTableSize(unsigned long &newTableSize) const noexcept {
    if (newTableSize < DEFAULT_TABLE_SIZE) {
        newTableSize = DEFAULT_TABLE_SIZE;
    }

    newTableSize = pow(2, ceil(log2(newTableSize)));
}

/* ************************************************************************** */

}
