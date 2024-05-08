
namespace lasd {

/* ************************************************************************** */

    // PreOrderMappableContainer

    // Overrided methods

    template <typename Data>

    inline void PreOrderMappableContainer<Data>::Map(MapFun function) {
        PreOrderMap(function);
    }

/* ************************************************************************** */

    // PostOrderMappableContainer

    // Overrided methods

    template <typename Data>
    inline void PostOrderMappableContainer<Data>::Map(MapFun function) {
        PostOrderMap(function);
    }

    // BreadthMappableContainer

    // Overrided methods

    template <typename Data>
    inline void BreadthMappableContainer<Data>::Map(MapFun function) {
        BreadthMap(function);
    }

    // InOrderMappableContainer

    // Overrided methods

    template <typename Data>
    inline void InOrderMappableContainer<Data>::Map(MapFun function) {
        InOrderMap(function);
    }

/* ************************************************************************** */

}
