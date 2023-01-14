#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    std::vector <int> v(5, 1337);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    std::cout << "-------" << std::endl;
    v.reserve(6);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
}