#include <vector>
#include <memory>
#include <iostream>
// #include <iterator>
#include <algorithm>


int main ()
{
    // int a [] = {1, 1, 3 ,4};
    std::vector <int>arr (452);
    // std::vector <int>::iterator iter1 (arr.begin());
    // std::vector <int>::iterator iter2 (arr.begin() + 1);

    // std::cout << iter1 - iter2 << std::endl;
    std::cout << arr.size() << std::endl << arr.capacity();
    // std::vector <int>::iterator iter = arr.begin();
    // std::cout << *iter << std::endl;
}