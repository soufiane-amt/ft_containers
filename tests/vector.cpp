#include "../includes/vector.hpp"
// #include <memory>
// #include <iostream>
// // #include <iterator>
// #include <algorithm>

// void foo() {

//     int a = 1 > 0 ? 1 : return;
//     int a = if (1 > 0) ? 1 : return;
// }


int main ()
{
    ft::vector<int> v;
    std::cout << v.size() << std::endl << v.capacity() << std::endl;
    v.push_back(12);
    std::cout << v.size() << std::endl << v.capacity() << std::endl;
    v.push_back(12);
    std::cout << v.size() << std::endl << v.capacity() << std::endl;
    v.push_back(12);
    std::cout << v.size() << std::endl << v.capacity() << std::endl;
    v.push_back(12);
    std::cout << v.size() << std::endl << v.capacity() << std::endl;
    v.push_back(12);
    std::cout << v.size() << std::endl << v.capacity() << std::endl;
}