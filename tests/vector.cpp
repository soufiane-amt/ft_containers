#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    std::vector <int> a (4, 42);
    for (size_t i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
    std::cout << "--------" << std::endl;
    a.resize(2, 999);
    for (size_t i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
}