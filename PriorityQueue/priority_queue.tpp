#include "priority_queue.hpp"

template <typename T>
myStd::priority_queue<T>::priority_queue() : m_vec() {} 

template <typename T>
myStd::priority_queue<T>::priority_queue(std::initializer_list<T> list) : m_vec(list) {
    buildHeap(m_vec.size());
}

template <typename T>
myStd::priority_queue<T>::priority_queue(const priority_queue<T>& cp) : m_vec(cp.m_vec) {}

template <typename T>
myStd::priority_queue<T>::priority_queue(priority_queue<T>&& mv) noexcept : m_vec(std::move(mv.m_vec)) {}

template <typename T>
myStd::priority_queue<T>& myStd::priority_queue<T>::operator=(const priority_queue<T>& cpAs) {
    if(this != &cpAs) {
        m_vec = cpAs.m_vec;
    }
    return *this;
}

template <typename T>
myStd::priority_queue<T>& myStd::priority_queue<T>::operator=(priority_queue<T>&& mvAs) {
    if(this != &mvAs) {
        m_vec = std::move(mvAs.m_vec);
    }
    return *this;
}

template <typename T>
void myStd::priority_queue<T>::push(const T& element) {
    insert(element);
}

template <typename T>
void myStd::priority_queue<T>::pop() {
    deleteHead();
}

template <typename T>
typename myStd::priority_queue<T>::valueType myStd::priority_queue<T>::top() const {
    if (m_vec.empty()) {
        throw std::out_of_range("Priority queue is empty.");
    }
    return m_vec[0];
}

template <typename T>
bool myStd::priority_queue<T>::isEmpty() const {
    return (m_vec.empty());
}

template <typename T>
typename myStd::priority_queue<T>::sizeType myStd::priority_queue<T>::size() const {
    return m_vec.size();
}

template <typename T>

void myStd::priority_queue<T>::clear() {
    m_vec.clear();
}

template <typename T>
int myStd::priority_queue<T>::findLeft(int index) const {
    return 2 * index + 1;
}

template <typename T>
int myStd::priority_queue<T>::findParent(int index) const {
    return (index - 1) / 2;
}

template <typename T>
void myStd::priority_queue<T>::buildHeap(int size) {
    for(sizeType i  = (size / 2) - 1; i >= 0; --i) {
        heapify(m_vec, size, i);
    }
}

template <typename T>
void myStd::priority_queue<T>::heapify(int size, int index) {
    if(index >= size) {
        return;
    }

    int left = findLeft(index);
    int right = left + 1;
    int largest = index;

    if(left < size && m_vec[left] > m_vec[largest]) {
        largest = left;
    }
    if(right < size && m_vec[right] > m_vec[largest]) {
        largest = right;
    }
    if(largest != index) {
        std::swap(m_vec[index], m_vec[largest]);
        heapify(size, largest);
    }
}

template <typename T>
void myStd::priority_queue<T>::insert(T val) {
    m_vec.push_back(val);
    int index = m_vec.size() - 1;
    int parentIndex = 0;

    while(index > 0) {
        parentIndex = findParent(index);
        if(m_vec[index] > m_vec[parentIndex]) {
            std::swap(m_vec[index], m_vec[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

template <typename T>
void myStd::priority_queue<T>::deleteHead() {
    if(m_vec.empty()) {
        return;
    }
    std::swap(m_vec[0], m_vec[m_vec.size() - 1]);
    m_vec.pop_back();
    if(!m_vec.empty()) {
        heapify(m_vec.size(), 0);
    }
}

template <typename T>
void myStd::priority_queue<T>::print() {
    int size = m_vec.size();
    for(sizeType i = 0; i < size; ++i) {
        std::cout << m_vec[i] << " ";
    }
    std::cout << std::endl;
}