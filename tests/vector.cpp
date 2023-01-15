#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    std::vector <int> v(2 , 42);
    std::vector <int> v1(1 , 42);
    v1.push_back (42);
    std::cout << std::lexicographical_compare(v1.begin(), v1.end(), v.begin(), v.end()) << std::endl;
}