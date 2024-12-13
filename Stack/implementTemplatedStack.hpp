#ifndef __INPLEMENTATIONTEMPLATEDSTACK__
#define __INPLEMENTATIONTEMPLATEDSTACK__

#include <iostream>
#include <stdexcept>
#include <vector>

namespace myStd {
    template <typename T>
    class Stack {
    public:
        using valueType = T;
        using reference = valueType&;
        using const_reference = const valueType&;
        using sizeType = size_t;

    public:
        Stack() = default;
        Stack(const Stack& cp);
        Stack(Stack&& mv);
        Stack& operator=(const Stack& cpAs);
        Stack& operator=(Stack&& mvAs);

        void push(const T& item);
        void pop();
        const_reference peek() const;
        bool isEmpty() const;
        sizeType size() const;

    private:
        std::vector<T> m_data;
    };
}

#include "implementTemplatedStack.tpp"

#endif //__INPLEMENTATIONTEMPLATEDSTACK__