#include "../includes/vector.hpp"
// #include <memory>
#include <iostream>
#include <iterator>
// #include <algorithm>
#include <vector>


#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
#define TESTED_TYPE int
#define TESTED_NAMESPACE ft
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


void    prepost_incdec(TESTED_NAMESPACE::vector<TESTED_TYPE> &vct)
{
        TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

        std::cout << "Pre inc" << std::endl;
        it_tmp = ++it;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Pre dec" << std::endl;
        it_tmp = --it;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Post inc" << std::endl;
        it_tmp = it++;
        std::cout << *it_tmp << " | " << *it << std::endl;

        std::cout << "Post dec" << std::endl;
        it_tmp = it--;
        std::cout << *it_tmp << " | " << *it << std::endl;
        std::cout << "###############################################" << std::endl;
}

int main ()
{
        TESTED_NAMESPACE::vector<TESTED_TYPE> foo(3, 15);
        TESTED_NAMESPACE::vector<TESTED_TYPE> bar(5, 42);

        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();

        std::cout << "BEFORE SWAP" << std::endl;

        std::cout << "foo contains:" << std::endl;
        printSize(foo);
        std::cout << "bar contains:" << std::endl;
        printSize(bar);

        foo.swap(bar);

        std::cout << "AFTER SWAP" << std::endl;

        std::cout << "foo contains:" << std::endl;
        printSize(foo);
        std::cout << "bar contains:" << std::endl;
        printSize(bar);

        std::cout << "Iterator validity:" << std::endl;
        std::cout << (it_foo == bar.begin()) << std::endl;
        std::cout << (it_bar == foo.begin()) << std::endl;

        return (0);
}// void    test_construct ()
// {

// }

// int main ()
// {
//     ft::vector <int> v (1337, 4);
    
// }




//To focus

//-->resize
//-->reserve
//-->assign
//-->push_back
//-->insert
//-->erase



//swap