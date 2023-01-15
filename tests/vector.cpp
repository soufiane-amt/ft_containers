#include <vector>
#include <memory>
#include <iostream>
#include <iterator>

int main ()
{
    int arr[] = {1, 2, 3 ,4 ,5 , 6};
    std::vector <int> v(arr , arr + 6);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
}