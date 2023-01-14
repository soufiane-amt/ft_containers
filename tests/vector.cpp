#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    int a[] = {1,23 ,1 ,44};
    std::vector<int> v(a, a  + 1);
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << v[i] << std::endl;
    }
    
}