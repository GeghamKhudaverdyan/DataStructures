#include <iostream>
#include "../hpp/Vector.hpp"

int main() {
    Vector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    std::cout << "Vector 1: ";
    vec1.printVector();

    Vector<int> vec2(5, 42);
    std::cout << "Vector 2: ";
    vec2.printVector();

    Vector<int> vec3 = {1, 2, 3, 4, 5};
    std::cout << "Vector 3: ";
    vec3.printVector();

    Vector<int> vec4(vec3);
    std::cout << "Vector 4 (copy of Vector 3): ";
    vec4.printVector();

    Vector<int> vec5(std::move(vec3));
    std::cout << "Vector 5 (moved from Vector 3): ";
    vec5.printVector();
    std::cout << "Vector 3 (after move): ";
    vec3.printVector();

    vec1 = vec2;
    std::cout << "Vector 1 (after assignment from Vector 2): ";
    vec1.printVector();

    vec1 = std::move(vec4);
    std::cout << "Vector 1 (after move assignment from Vector 4): ";
    vec1.printVector();
    std::cout << "Vector 4 (after move assignment): ";
    vec4.printVector();

    try {
        std::cout << "Front of Vector 5: " << vec5.front() << std::endl;
        std::cout << "Back of Vector 5: " << vec5.back() << std::endl;
        std::cout << "Element at index 2 of Vector 5: " << vec5.at(2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    vec5.push_back(99);
    std::cout << "Vector 5 after push_back: ";
    vec5.printVector();
    vec5.pop_back();
    std::cout << "Vector 5 after pop_back: ";
    vec5.printVector();

    vec5.insert(2, 88);
    std::cout << "Vector 5 after insert at index 2: ";
    vec5.printVector();

    vec5.erase(2);
    std::cout << "Vector 5 after erase at index 2: ";
    vec5.printVector();

    vec5.reserve(20);
    vec5.resize(10, 5);
    std::cout << "Vector 5 after reserve and resize: ";
    vec5.printVector();

    std::cout << "Vector 5 is empty: " << std::boolalpha << vec5.isEmpty() << std::endl;

    return 0;
}