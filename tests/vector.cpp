#include "../includes/vector.hpp"
// #include <memory>
// #include <iostream>
// #include <iterator>
// #include <algorithm>
#include <vector>

void    test_construct ()
{

}

int main ()
{
    ft::vector <int> c(1337, 42);
    ft::vector <int> v(1, 1);
    c = v;
    // v.erase(v.begin(), v.end());
    for (size_t i = 0; i < c.size(); i++)
        std::cout << c[i] << std::endl;
    // std::cout << "----------\n";
    std::cout << "capacity :" << v.capacity();
    std::cout << "\nsize :" << v.size() << std::endl;
}
