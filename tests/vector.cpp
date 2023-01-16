#include <vector>
#include <memory>
#include <iostream>
// #include <iterator>
#include <algorithm>


template<class Iterator>
struct iterator_traits
{
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

struct input_iterator_tag  {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag         {};
struct bidirectional_iterator_tag : public forward_iterator_tag       {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template<class T>
struct iterator_traits <T*>
{
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef random_access_iterator_tag iterator_category;
};


template <typename Iterator> 
typename iterator_traits<Iterator>::value_type    func (Iterator first, Iterator end)
{

    typedef typename iterator_traits<Iterator>::value_type value_type;
    value_type sum = value_type();

    for ( Iterator i = first; i != end; i++)
        sum += *i;    
    return (sum);
}


int main ()
{
    // std::vector <int> arr (5, 42);
    int arr[] = {1, 2, 3 ,4};
    std::cout << func(arr , arr + 4) << std::endl;
}