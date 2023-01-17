#include <vector>
#include <memory>
#include <iostream>
// #include <iterator>
#include <algorithm>


int main ()
{
    std::vector <int>arr (5, 42);
    // for (size_t i = 0; i < arr.size(); i++)
    // {
        // /* 
    // }
    arr.assign(2, 0);
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
    std::cout << "\n" << arr.capacity() << std::endl;
    std::cout << arr.size() << std::endl;
    
    
}