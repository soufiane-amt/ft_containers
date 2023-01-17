#include <vector>
#include <memory>
#include <iostream>
// #include <iterator>
#include <algorithm>


int main ()
{
    std::vector <int>arr (5, 42);
    std::vector <int>arr1 ;
    // arr1.push_back(4);
    std::cout << "arr :" << "capacity: " << arr.capacity() << " size: " <<arr.size() << std::endl; 
    std::cout << "arr1 :" << "capacity: " << arr1.capacity() << " size: " <<arr1.size() << std::endl; 
    arr =arr1;
    std::cout << "arr :" << "capacity: " << arr.capacity() << " size: " <<arr.size() << std::endl; 
    std::cout << "arr1 :" << "capacity: " << arr1.capacity() << " size: " <<arr1.size() << std::endl; 
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
}