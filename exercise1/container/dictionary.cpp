
namespace lasd {

// Specific member functions (DictionaryContainer)
    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& container) {
        std::cout << "BlaBlaBlaCar" << std::endl;
        bool result = true;
        container.Traverse(
                //this è un puntatore all'oggetto DictionaryContainer
            [this, &result](const Data & currData) {
                std::cout << "ITERAZIONE" << std::endl;
                result &= this->Insert(currData);
            }
        );
        return result;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& container) {
        bool result = true;
        container.Map(
            [this, &result](Data &currData) {
                result &= this->Insert(std::move(currData));
            }
        );
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> &container) {
        bool result = true;
        container.Traverse(
                [this, &result](const Data &currData) {
            result &= this->Remove(currData);
        });
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> &container) {
        bool result = false;
        container.Traverse(
                [this, &result](const Data &currData) {
            result |= this->Insert(currData);
        });
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> &&container) {
        bool result = false;
        container.Map(
                [this, &result](Data &currData) {
            result |= this->Insert(std::move(currData));
        });
        return result;
    }

    template <typename Data>
    inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data> &container) {
        bool result = false;
        container.Traverse(
                [this, &result](const Data &currData) {
            result |= this->Remove(currData);
        });
        return result;
    }
}
