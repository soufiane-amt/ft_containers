#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    int *arr;
    std::allocator <int> alloc;
    arr = alloc.allocate (5);
    for (size_t i = 0; i < 5; i++)
    {
        alloc.construct(arr + i, 1337);
    }    
    //print
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    

}