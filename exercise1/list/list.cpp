#include <iostream>
#include <utility>
#include "list.hpp"
#include <stdexcept>

namespace lasd {

/* ************************************************************************** */
    // Node

    //Constructors

    // Data Copy constructor
    template <typename Data>
    List<Data>::Node::Node(const Data& data) : value{data} {}

    // Move constructor
    template <typename Data>
    List<Data>::Node::Node(Data&& data) noexcept : value{std::move(data)} {}

    // Copy constructor
    template <typename Data>
    List<Data>::Node::Node(const Node& node) : value{node.value} {}

    // Move constructor
    template <typename Data>
   List<Data>::Node::Node(Node&& node) noexcept : value{std::move(node.value)} {}

    // Destructor
    template <typename Data>
    List<Data>::Node::~Node() {
        delete next;
    }

    // Comparison operators

    //Equal operator
    template <typename Data>
    inline bool List<Data>::Node::operator==(const Node& node) const noexcept {
        return value == node.value;
    }

    //Not equal operator
    template <typename Data>
    inline bool List<Data>::Node::operator!=(const Node& node) const noexcept {
        return value != node.value;
    }

/* ************************************************************************** */
    //List

    //Constructors

    //Copy constructor from other type of structure
    template <typename Data>
    List<Data>::List(const TraversableContainer<Data>& container) {
        container.Traverse([this](const Data &currData) { InsertAtBack(currData); });
    }

    //Move constructor from other type of structure
    template <typename Data>
    List<Data>::List(MappableContainer<Data>&& container) {
        container.Map([this](Data &currData) { InsertAtBack(std::move(currData)); });
    }

    //Copy constructor
    template <typename Data>
    List<Data>::List(const List<Data>& otherList) {
        if (otherList.size == 0) {
            head = nullptr;
            tail = nullptr;
            size = 0;
        } else {
            Node* otherNode = otherList.head;
            head = new Node(*otherNode);
            Node* thisNode = head;

            while (otherNode->next) {
                otherNode = otherNode->next;
                thisNode->next = new Node(*otherNode);
                thisNode = thisNode->next;
            }
            tail = thisNode;
            size = otherList.size;
        }
    }

    //Move constructor
    template <typename Data>
    List<Data>::List(List &&list) {
        std::swap(size, list.size);
        std::swap(head, list.head);
        std::swap(tail, list.tail);
    }

    //Destructor
    template <typename Data>
    List<Data>::~List() {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Copy assignment
    template <typename Data>
    List<Data>& List<Data>::operator=(const List<Data>& otherList) {
        if (this != &otherList) {
            Clear(); // Clear the current list first
            Node* otherNode = otherList.head;
            if (otherNode) { // If the other list is not empty
                head = new Node(*otherNode); // Copy the first node
                Node* thisNode = head;
                while (otherNode->next) {
                    otherNode = otherNode->next;
                    thisNode->next = new Node(*otherNode); // Copy subsequent nodes
                    thisNode = thisNode->next;
                }
                tail = thisNode;
                size = otherList.size;
            }
        }
        return *this;
    }
    //Move assignment
    template <typename Data>
    List<Data>& List<Data>::operator=(List<Data>&& otherList) noexcept {
        std::swap(size, otherList.size);
        std::swap(head, otherList.head);
        std::swap(tail, otherList.tail);
        return *this;
    }

    //Comparison operators

    //Equal operator
    template <typename Data>
    inline bool List<Data>::operator==(const List<Data>& otherList) const noexcept {
        if (size != otherList.size) {
            return false;
        }

        Node* thisNode = head;
        Node* otherNode = otherList.head;

        while (thisNode && otherNode) {
            if (*thisNode != *otherNode) {
                return false;
            }
            thisNode = thisNode->next;
            otherNode = otherNode->next;
        }
        return true;

    }

    //Not equal operator
    template <typename Data>
    inline bool List<Data>::operator!=(const List<Data>& otherList) const noexcept {
        return !(*this == otherList);
    }


    //Specific member functions

    //InsertAtFront
    template <typename Data>
    void List<Data>::InsertAtFront(const Data& data) {
        Node* newNode = new Node(data);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data&& data) {
        Node* newNode = new Node(std::move(data));
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    //RemoveFromFront
    template <typename Data>
    void List<Data>::RemoveFromFront() {
        if (Empty()) {
            throw std::length_error("List is empty");
        }

        Node* nodePtr = head;
        head = head->next;

        nodePtr-> next = nullptr;
        delete nodePtr;
        nodePtr = nullptr;

        size--;
        if (size == 0) {
            tail = head = nullptr;
        }
    }

    //FrontNRemove
    template <typename Data>
    Data List<Data>::FrontNRemove() {
        if (Empty()) {
            throw std::length_error("List is empty");
        }

        Data tempData{head->value};
        RemoveFromFront();
        return tempData;
    }

    //InsertAtBack
    template <typename Data>
    void List<Data>::InsertAtBack(const Data& data) {
        Node* newNode = new Node(data);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data&& data) {
        Node* newNode = new Node(std::move(data));
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    //Todo controllare da qui!
    //Insert
    template <typename Data>
    inline bool List<Data>::Insert(const Data &data){
        if (Exists(data)) {
            return false;
        }
        InsertAtBack(data);
        return true;
    }

    //Insert
    template <typename Data>
    inline bool List<Data>::Insert(Data &&data){
        if (Exists(data)) {
            return false;
        }
        InsertAtBack(std::move(data));
        return true;
    }

    //Remove
    template <typename Data>
    inline bool List<Data>::Remove(const Data &data){
        std:: cout << "Removing... " << data << std::endl;
        if (Empty() || head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return false;
        }


        if (head->value == data) {
            RemoveFromFront();
            std::cout << "Removed from front" << std::endl;
            return true;
        }

        Node* currNode = head->next;
        Node* prevNode = head;

        while (currNode != nullptr && currNode->value != data) {
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (currNode != nullptr) {
            prevNode->next = currNode->next;
            if (currNode == tail) {
                tail = prevNode;
            }
            delete currNode;
            size--;
            std::cout << "Removed ok" << std::endl;
            return true;
        }
        std::cout << "Not found" << std::endl;
        return false;
    }

    //Reading operator
    template <typename Data>
    inline const Data& List<Data>::operator[](const unsigned long index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* currNode = head;
        for (unsigned long i = 0; i < index; i++) {
            currNode = currNode->next;
        }
        return currNode->value;
    }

    //Writing operator
    template <typename Data>
    inline Data& List<Data>::operator[](const unsigned long index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* currNode = head;
        for (unsigned long i = 0; i < index; i++) {
            currNode = currNode->next;
        }
        return currNode->value;
    }

    //Front
    template <typename Data>
    inline const Data& List<Data>::Front() const {
        if (size == 0) {
            throw std::length_error("List is empty");
        }
        return head->value;
    }

    template <typename Data>
    inline Data& List<Data>::Front() {
        if (size == 0) {
            throw std::length_error("List is empty");
        }
        return head->value;
    }

    //Back
    template <typename Data>
    inline const Data& List<Data>::Back() const {
        if (size == 0) {
            throw std::length_error("List is empty");
        }
        return tail->value;
    }

    template <typename Data>
    inline Data& List<Data>::Back() {
        if (size == 0) {
            throw std::length_error("List is empty");
        }
        return tail->value;
    }

    //Clear
    template <typename Data>
    inline void List<Data>::Clear() {
        // Node* currNode = head;
        // while (currNode != nullptr) {
        //     Node* nextNode = currNode->next;
        //     delete currNode;
        //     currNode = nextNode;
        // }
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //Traverse
    template <typename Data>
    inline void List<Data>::Traverse(TraverseFun function) const {
        PreOrderTraverse(function);
    }

    //PreOrderTraverse
    template <typename Data>
    inline void List<Data>::PreOrderTraverse(TraverseFun function) const {
        PreOrderTraverse(head, function);
    }

    //PostOrderTraverse
    template <typename Data>
    inline void List<Data>::PostOrderTraverse(TraverseFun function) const {
        PostOrderTraverse(head, function);
    }

    //Map
    template <typename Data>
    inline void List<Data>::Map(MapFun function) {
        PreOrderMap(function);
    }

    //PreOrderMap
    template <typename Data>
    inline void List<Data>::PreOrderMap(MapFun function) {
        PreOrderMap(head, function);
    }

    //PostOrderMap
    template <typename Data>
    inline void List<Data>::PostOrderMap(MapFun function) {
        PostOrderMap(head, function);
    }

    // Internal Methods

    //PreOrderTraverse
    template <typename Data>
    void List<Data>::PreOrderTraverse(Node* node, TraverseFun function) const {
        if (node != nullptr) {
            function(node->value);
            PreOrderTraverse(node->next, function);
        }
    }

    //PostOrderTraverse
    template <typename Data>
    void List<Data>::PostOrderTraverse(Node* node, TraverseFun function) const {
        if (node != nullptr) {
            PostOrderTraverse(node->next, function);
            function(node->value);
        }
    }

    //PreOrderMap
    template <typename Data>
    void List<Data>::PreOrderMap(Node* node, MapFun function) const{
        if(node != nullptr){
            function(node->value);
            PreOrderMap(node->next, function);
        }
    }

    //PostOrderMap
    template <typename Data>
    void List<Data>::PostOrderMap(Node* node, MapFun function) const{
        if(node != nullptr){
            PostOrderMap(node->next, function);
            function(node->value);
        }
    }

/* ************************************************************************** */

} // namespace lasd