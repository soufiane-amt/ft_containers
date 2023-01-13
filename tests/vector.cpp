#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    // int *arr;
    std::allocator <int> alloc;
    // arr = alloc.allocate (5);
    // for (size_t i = 0; i < 5; i++)
    // {
    
    //     /* code */

    // }
    
    // alloc.construct(arr, 1337);
    std::vector <int > arr2 (0, 1337,alloc);
    for (size_t i = 0; i < 0; i++)
    {
        std::cout << arr[i] << std::endl;
    }

}