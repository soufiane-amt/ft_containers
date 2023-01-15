#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    // std::vector <int> v;
    // v.push_back (100);
    std::vector <int> v1 (4, 1337);
    // std::cout << "v : Capacity : " << v.capacity() << std::endl;
    // std::cout << "v : size : " << v.size() << std::endl;
    // std::cout << "v1 : Capacity : " << v1.capacity() << std::endl;
    // std::cout << "v1 : size : " << v1.size() << std::endl;
    // v.swap(v1);
    // for (size_t i = 0; i < v1.size(); i++)
    // {
        // std::cout << v1[i] << std::endl;
    // }
    // std::cout << "v : Capacity : " << v.capacity() << std::endl;
    // std::cout << "v : size : " << v.size() << std::endl;
    std::cout << "v1 : Capacity : " << v1.capacity() << std::endl;
    std::cout << "v1 : size : " << v1.size() << std::endl;

    v1.clear();
    for (size_t i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;
    }
    std::cout << "v1 : Capacity : " << v1.capacity() << std::endl;
    std::cout << "v1 : size : " << v1.size() << std::endl;

}