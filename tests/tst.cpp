#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
     int a = 44245;
    std::allocator<int>::reference ref = a;
    std::cout << ref << std::endl;
    // int *ptr = alloc.allocate(2);
    // alloc.construct(ptr, 45);
    // alloc.construct(ptr + 1, 100);
    // std::cout << ptr[0] << std::endl;
    // std::cout << ptr[1] << std::endl;
    // alloc.deallocate(ptr, 1);
}