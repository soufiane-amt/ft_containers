#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    // std::vector <int> v;
    // v.push_back (100);
    // std::cout << v.capacity() << std::endl;
    // std::cout << v.size() << std::endl;
    int *arr;
    std::allocator<int> alloc;
    alloc.deallocate (arr);
}