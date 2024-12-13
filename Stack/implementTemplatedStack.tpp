#include "implementTemplatedStack.hpp"

template <typename T>
myStd::Stack<T>::Stack(const Stack& cp) : m_data(cp.m_data) {}

template <typename T>
myStd::Stack<T>::Stack(Stack&& mv) {
    m_data = std::move(mv.m_data);
}

template <typename T>
myStd::Stack<T>& myStd::Stack<T>::operator=(const Stack& cpAs){
    if(this != &cpAs) {
        m_data = cpAs.m_data;
    }
    return *this;
}

template <typename T>
myStd::Stack<T>& myStd::Stack<T>::operator=(Stack&& mvAs) {
    if(this != &mvAs) {
        m_data = std::move(mvAs.m_data);
    }
    return * this;
}

template <typename T>
void myStd::Stack<T>::push(const T& item) {
    m_data.push_back(item);
}

template <typename T>
void myStd::Stack<T>::pop() {
    if (!isEmpty()) {
        m_data.pop_back();
    } else {
        std::cerr << "There is no data in Stack." << std::endl;
    }
}

template <typename T>
typename myStd::Stack<T>::const_reference myStd::Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return m_data.back();
}

template <typename T>
bool myStd::Stack<T>::isEmpty() const {
    return m_data.empty();
}

template <typename T>
typename myStd::Stack<T>::sizeType myStd::Stack<T>::size() const {
    return m_data.size();
}