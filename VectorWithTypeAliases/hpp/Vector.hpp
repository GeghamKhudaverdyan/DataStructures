#ifndef __VECTOR__ 
#define __VECTOR__

#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Vector {
public:
    //TYPE_ALIASES//
    using valueType = T;
    using reference = valueType&;
    using constReference = const valueType&;
    using pointer = valueType*;
    using constPointer = const valueType*;
    using size_type = size_t;

public:
    //CONSTRUCTORS//
    Vector();
    Vector(size_type size);
    Vector(size_type size, constReference val);
    Vector(std::initializer_list<valueType> initList);

    Vector(const Vector& cp);
    Vector(Vector&& mv);
    Vector& operator=(const Vector& cpAs);
    Vector& operator=(Vector&& mvAs);
    ~Vector();

    //MEMBER_FUNCTIONS//
    void printVector();
    void assign(size_type size, constReference val);
    void push_back(const constReference val);
    void pop_back();
    reference front();
    constReference front() const;
    reference back();
    constReference back() const;
    reference at(size_type index);
    constReference at(size_type index) const;
    reference operator[](size_type index);
    constReference operator[](size_type index) const;
    size_type insert(size_type index, constReference val);
    size_type insert(size_type index, std::initializer_list<valueType> init);
    size_type erase(size_type index);
    size_type erase(size_type index, size_type init);

    void reserve(size_type capacity);
    void resize(size_type size, constReference val = valueType());
    bool isEmpty();
    valueType size();

public:
    //CONST_ITERATOR//
    class const_iterator {
    public:

    };

private:
    size_type m_size;
    size_type m_capacity;
    pointer m_arr;
};

#include "../src/Vector.tpp"

#endif //__VECTOR__