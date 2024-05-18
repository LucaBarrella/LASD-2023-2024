
namespace lasd {

/* ************************************************************************** */

    // Constructor

    // Default constructor
    template <typename Data>
    QueueVec<Data>::QueueVec(): Vector<Data>::Vector(DEFAULT_QUEUE_SIZE) {}

    // Specific constructor from a TraversableContainer
    template <typename Data>
    QueueVec<Data>::QueueVec(const TraversableContainer<Data>& container): Vector<Data>::Vector(container),
    tail(container.Size()), elemInQueue(container.Size()) {
        if(size < DEFAULT_QUEUE_SIZE) {
            Resize(DEFAULT_QUEUE_SIZE);
        }
    }

    // Specific constructor from a MappableContainer
    template <typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data>&& container): Vector<Data>::Vector(std::move(container)),
    tail(container.Size()), elemInQueue(container.Size()) {
        if(size < DEFAULT_QUEUE_SIZE) {
            Resize(DEFAULT_QUEUE_SIZE);
        }
    }
    // Copy constructor
    template <typename Data>
    QueueVec<Data>::QueueVec(const QueueVec<Data>& queue): Vector<Data>::Vector(queue), head(queue.head),
    tail(queue.tail), elemInQueue(queue.elemInQueue) {}

    // Move constructor
    template <typename Data>
    QueueVec<Data>::QueueVec(QueueVec<Data>&& queue) noexcept:
    Vector<Data>::Vector(std::move(queue)) {
        std::swap(head, queue.head);
        std::swap(tail, queue.tail);
        std::swap(elemInQueue, queue.elemInQueue);
    }

    // Copy assignment
    template <typename Data>
    QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& queue) {
        Vector<Data>::operator=(queue);
        head = queue.head;
        tail = queue.tail;
        elemInQueue = queue.elemInQueue;
        return *this;
    }

    // Move assignment
    template <typename Data>
    QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& queue) noexcept {
        Vector<Data>::operator=(std::move(queue));
        std::swap(head, queue.head);
        std::swap(tail, queue.tail);
        std::swap(elemInQueue, queue.elemInQueue);
        return *this;
    }

    // Comparison operators

    // Equality operator
    template <typename Data>
    inline bool QueueVec<Data>::operator==(const QueueVec<Data>& queue) const noexcept {
        if(elemInQueue != queue.elemInQueue) {
            return false;
        }
        for(unsigned long i = 0; i < elemInQueue; i++) {
            if(data[(head + i) % size] != queue.data[(queue.head + i) % queue.size]) {
                return false;
            }
        }
        return true;
    }

    // Inequality operator
    template <typename Data>
    inline bool QueueVec<Data>::operator!=(const QueueVec<Data>& queue) const noexcept {
        return !(*this == queue);
    }

    // Ovverdided methods

    //Head
    template <typename Data>
    inline const Data& QueueVec<Data>::Head() const {
        if(elemInQueue == 0) {
            throw std::length_error("Queue is empty");
        }
        return data[head];
    }

    // Head (mutable)
    template <typename Data>
    inline Data& QueueVec<Data>::Head() {
        if(elemInQueue == 0) {
            throw std::length_error("Queue is empty");
        }
        return data[head];
    }

    // Dequeue
    template <typename Data>
    inline void QueueVec<Data>::Dequeue() {
        if(elemInQueue == 0) {
            throw std::length_error("Queue is empty");
        }
        head = (head + 1) % size;
        elemInQueue--;
        if(elemInQueue <= DEFAULT_QUEUE_SIZE * SHRINK_FACTOR) {// elemInQueue <= 1/4 of the size
            Resize(size / RESIZE_FACTOR);// 1/2 of the original size
        }
    }

    // HeadNDequeue
    template <typename Data>
    inline Data QueueVec<Data>::HeadNDequeue() {
        if(elemInQueue == 0) {
            throw std::length_error("Queue is empty");
        }
        Data temp = std::move(data[head]);
        head = (head + 1) % size;
        elemInQueue--;
        return temp;
    }

    // Enqueue (copy of the value)
    template <typename Data>
    inline void QueueVec<Data>::Enqueue(const Data& value) {
        if(elemInQueue == size) {
            Resize(size * RESIZE_FACTOR);
        }
        data[tail] = value;
        tail = (tail + 1) % size;
        elemInQueue++;
    }

    // Enqueue (move of the value)
    template <typename Data>
    inline void QueueVec<Data>::Enqueue(Data&& value) {
        if(elemInQueue == size) {
            Resize(size * RESIZE_FACTOR);
        }
        data[tail] = std::move(value);
        tail = (tail + 1) % size;
        elemInQueue++;
    }

    // Empty
    template <typename Data>
    inline bool QueueVec<Data>::Empty() const noexcept {
        return elemInQueue == 0;
    }

    // Size
    template <typename Data>
    inline unsigned long QueueVec<Data>::Size() const noexcept {
        return elemInQueue;
    }

    // Clear
    template <typename Data>
    inline void QueueVec<Data>::Clear() {
        Resize(DEFAULT_QUEUE_SIZE);
        head = 0;
        tail = 0;
        elemInQueue = 0;
    }

    // Resize
    template <typename Data>
    inline void QueueVec<Data>::Resize(unsigned long newSize) {
        if(newSize < DEFAULT_QUEUE_SIZE) {
            newSize = DEFAULT_QUEUE_SIZE;
        }
        Data* temp = new Data[newSize];
        for(unsigned long i = 0; i < elemInQueue; i++) {
            temp[i] = std::move(data[(head + i) % size]);
        }
        std::swap(data, temp);
        delete[] temp;
        size = newSize;
        head = 0;
        tail = elemInQueue;
    }

/* ************************************************************************** */

} // namespace lasd
