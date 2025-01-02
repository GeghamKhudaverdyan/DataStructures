#include "../hpp/Vector.hpp"

template <typename T>
Vector<T>::Vector() : m_size(0), m_capacity(0), m_arr(nullptr) {}

template <typename T>
Vector<T>::Vector(size_type size) : m_size(size), m_capacity(size), m_arr(new valueType[size]()) {}

template <typename T>
Vector<T>::Vector(size_type size, constReference val) : m_size(size), m_capacity(size), m_arr(new valueType[size]) {
    for(size_type i = 0; i < size; ++i) {
        m_arr[i] = val;
    }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<valueType> initList) {
    m_size = initList.size();
    m_capacity = m_size;
    m_arr = new valueType[m_capacity];
    for(size_type i = 0; i < m_capacity; ++i) {
        m_arr[i] = *(initList.begin() + i);
    }
}

template <typename T>
Vector<T>::Vector(const Vector& cp) : m_size(cp.m_size), m_capacity(cp.m_capacity), m_arr(new valueType[cp.m_size]) {
    for(size_type i = 0; i < m_size; ++i) {
        m_arr[i] = cp.m_arr[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector&& mv) : m_size(mv.m_size), m_capacity(mv.m_capacity), m_arr(mv.m_arr) {
    mv.m_arr = nullptr;
    mv.m_size = 0;
    mv.m_capacity = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& cpAs) {
    if(this != &cpAs) {
        m_size = cpAs.m_size;
        m_capacity = cpAs.m_capacity;
        delete[] m_arr;
        m_arr = new valueType[m_size];
        for(size_type i = 0; i < m_size; ++i) {
            m_arr[i] = cpAs.m_arr[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& mvAs) {
    if(this != &mvAs) {
        m_size = mvAs.m_size;
        m_capacity = mvAs.m_capacity;
        m_arr = mvAs.m_arr;
        mvAs.m_arr = nullptr;
        mvAs.m_size = 0;
        mvAs.m_capacity = 0;
    }
    return *this;
}

template <typename T>
void Vector<T>::printVector() {
    for(size_type i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::assign(size_type size, constReference val) {
    if(size <= m_capacity) {
        for(size_type i = 0; i < size; ++i) {
            m_arr[i] = val;
        }
        m_size = size;
    } else {
        delete[] m_arr;
        m_size = size;
        m_capacity = size;
        m_arr = new valueType[m_capacity];
        for(size_type i = 0; i < m_capacity; ++i) {
            m_arr[i] = val;
        }
    }
}

template <typename T>
void Vector<T>::push_back(const constReference val) {
    if (m_size == m_capacity) {
        reserve((m_capacity == 0) ? 1 : (m_capacity * 2));
    }
    m_arr[m_size++] = val;
}

template <typename T>
void Vector<T>::pop_back() {
    if(m_size > 0) {
        --m_size;
    } else {
        std::cerr << "Error: Vector is empty. Can no't pop back!" << std::endl;
    }
}

template <typename T>
typename Vector<T>::reference Vector<T>::front() {
    if(m_size > 0) {
        return m_arr[0];
    } else {
        throw std::out_of_range("Error: Vector is empty. Can no't return reference in first element!");
    }
}

template <typename T>
typename Vector<T>::constReference Vector<T>::front() const {
    if(m_size > 0) {
        return m_arr[0];
    } else {
        throw std::out_of_range("Error: Vector is empty. Can no't return reference in first element!");
    }
}

template <typename T>
typename Vector<T>::reference Vector<T>::back() {
    if(m_size > 0) {
        return m_arr[m_size - 1];
    } else {
        throw std::out_of_range("Error: Vector is empty. Cannot return reference to the last element!");
    }
}

template <typename T>
typename Vector<T>::constReference Vector<T>::back() const {
    if(m_size > 0) {
        return m_arr[m_size - 1];
    } else {
        throw std::out_of_range("Error: Vector is empty. Cannot return reference to the last element!");
    }
}

template <typename T>
typename Vector<T>::reference Vector<T>::at(size_type index) {
    if(index < m_size) {
        return m_arr[index];
    } else {
        throw std::out_of_range("Index out of range.");
    }
}

template <typename T>
typename Vector<T>::constReference Vector<T>::at(size_type index) const {
    if(index < m_size) {
        return m_arr[index];
    } else {
        throw std::out_of_range("Index out of range.");
    }
}

template <typename T>
typename Vector<T>::reference Vector<T>::operator[](size_type index) {
    return m_arr[index];
}

template <typename T>
typename Vector<T>::constReference Vector<T>::operator[](size_type index) const {
    return m_arr[index];
}

template <typename T>
typename Vector<T>::size_type Vector<T>::insert(size_type index, constReference val) {
    if (index > m_size) {
        throw std::out_of_range("Index out of range.");
    }
    if(m_size == m_capacity) {
        reserve((m_capacity == 0) ? 1 : (m_capacity * 2));
    }
    for(size_type i = m_size; i > index; --i) {
        m_arr[i] = m_arr[i - 1];
    }
    ++m_size;
    m_arr[index] = val;
    return (++index);
}

template <typename T>
typename Vector<T>::size_type Vector<T>::insert(size_type index, std::initializer_list<valueType> init) {
    if (index > m_size) {
        throw std::out_of_range("Index out of range.");
    }
    m_size += init.size();
    m_capacity = m_size;
    pointer tmp = new valueType[m_size];
    for(size_type i = 0; i < index; ++i) {
        tmp[i] = m_arr[i];
    }
    size_type indexSize = init.size();
    size_type i = index;
    for(size_type j = 0; j < indexSize; ++i, ++j) {
        tmp[i] = *(init.begin() + j);
    }
    for(size_type j = 0; i < m_size; ++i, ++j) {
        tmp[i] = m_arr[index + j];
    }
    delete[] m_arr;
    m_arr = tmp;
    return index;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::erase(size_type index) {
    if(index >= m_size) {
        throw std::out_of_range("Index out of range.");
    } else {
        for(size_type i = index; i < m_size - 1; ++i) {
            m_arr[i] = m_arr[i + 1];
        }
        --m_size;
    }
    return index;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::erase(size_type firstIndex, size_type lastIndex) {
    if(firstIndex >= m_size || lastIndex > m_size || firstIndex > lastIndex) {
        throw std::out_of_range("Invalid range");
    }
    int numElementsToRemove = lastIndex - firstIndex;
    int numElementsToShift = m_size - lastIndex;

    for(size_type i = 0; i < numElementsToShift; ++i) {
        m_arr[firstIndex + i] = m_arr[lastIndex + i];
    }
    m_size -= numElementsToRemove;
    return firstIndex;
}

template <typename T>
void Vector<T>::reserve(size_type capacity) {
    if(capacity > m_capacity) {
        valueType* tmp = new valueType[capacity];
        for(size_type i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
        m_capacity = capacity;
        tmp = nullptr;
    }
}

template <typename T>
void Vector<T>::resize(size_type size, constReference val) {
    if(size < m_size) {
        m_size = size;
    } else if (size > m_capacity) {
        reserve(size);
    }
    if(size > m_size) {
        for(size_type i = m_size; i < size; ++i) {
            m_arr[i] = val;
        }
    }
    m_size = size;
}

template <typename T>
bool Vector<T>::isEmpty() {
    return (m_size == 0);
}

template <typename T>
typename Vector<T>::valueType Vector<T>::size() {
    return m_size;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] m_arr;
    m_arr = nullptr;
}