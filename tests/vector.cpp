// #include "../includes/vector.hpp"
// #include <memory>
#include <iostream>
// #include <iterator>
// #include <algorithm>
#include <vector>

void    test_construct ()
{

}

int main ()
{
    std::vector <int> v(3, 5);
    v.insert(v.begin(), 1337);
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    std::cout << "----------\n";
    std::cout << "capacity :" << v.capacity();
    std::cout << "\nsize :" << v.size();
}
/*template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(iterator position, const value_type& val) {
    if(_v_size == _v_capacity) {
        reserve(_v_capacity == 0 ? 1 : _v_capacity * 2);
    }
    for (iterator it = _v_size; it > position; --it) {
        *it = *(it - 1);
    }
    *position = val;
    _v_size++;
    return position;
}
*/

//-->To review:
//resize