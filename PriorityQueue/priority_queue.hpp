#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#include <vector>
#include <stdexcept>
#include <iostream>

namespace myStd {
    template<typename T>
    class priority_queue {
    public:
        using valueType = T;
        using sizeType = size_t;
    public:
        //CONSTRUCTORS//
        priority_queue();
        priority_queue(std::initializer_list <T> list);
        priority_queue(const priority_queue<T>& cp);
        priority_queue(priority_queue<T>&& mv) noexcept;
        priority_queue& operator=(const priority_queue<T>& cpAs);
        priority_queue& operator=(priority_queue<T>&& mvAs);

        //DESTRUCTOR//
        ~priority_queue() = default;

    //BASIC FUNCTION IN PRIORITY QUEUE//
        void push(const T& element);
        void pop();
        valueType top() const;
        bool isEmpty() const;
        sizeType size() const;
        void clear();
        void print();

    private:
        int findLeft(int index) const;
        int findParent(int index) const;
        void buildHeap(int size);
        void heapify(int size, int index);
        void insert(T val);
        void deleteHead();

    private:
        std::vector<valueType> m_vec;       
    };
}

#include "priority_queue.tpp"

#endif //__PRIORITYQUEUE__