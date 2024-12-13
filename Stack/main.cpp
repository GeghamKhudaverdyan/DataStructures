#include "implementTemplatedStack.hpp"

int main() {
    myStd::Stack<int> stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    myStd::Stack<int> stack2 = stack1;

    myStd::Stack<int> stack3;
    stack3 = stack1;

    stack1.pop();
    stack2.pop();
    stack3.push(40);

    std::cout << stack1.peek() << std::endl;
    std::cout << stack2.peek() << std::endl;
    std::cout << stack3.peek() << std::endl;

    return 0;
}