#include <iostream>
#include <algorithm>
#include "priority_queue.hpp"

int main() {

    myStd::priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(30);

    std::cout << "Priority Queue after pushes: ";
    pq.print();

    std::cout << "Top element: " << pq.top() << std::endl;

    pq.pop();
    std::cout << "Priority Queue after pop: ";
    pq.print();

    std::cout << "Size of the queue: " << pq.size() << std::endl;

    pq.clear();
    std::cout << "Priority Queue after clear: ";
    pq.print();

    pq.push(5);
    pq.push(25);
    pq.push(12);

    std::cout << "Priority Queue after pushing new elements: ";
    pq.print();

    std::cout << "Top element: " << pq.top() << std::endl;

    return 0;
}