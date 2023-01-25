#include "../includes/vector.hpp"
// #include <memory>
#include <iostream>
#include <iterator>
// #include <algorithm>
#include <vector>
#include <vector>
template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}



#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
#define TESTED_TYPE foo<int>
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


#define TESTED_TYPE foo<int>

int             main(void)
{
        const int size = 5;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it(vct.begin());
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite(vct.end());

        for (int i = 1; it != ite; ++i)
                *it++ = i;
        printSize(vct, 1);

        it = vct.begin();
        ite = vct.begin();

        std::cout << *(++ite) << std::endl;
        std::cout << *(ite++) << std::endl;
        std::cout << *ite++ << std::endl;
        std::cout << *++ite << std::endl;

        it->m();
        ite->m();

        std::cout << *(++it) << std::endl;
        std::cout << *(it++) << std::endl;
        std::cout << *it++ << std::endl;
        std::cout << *++it << std::endl;

        std::cout << *(--ite) << std::endl;
        std::cout << *(ite--) << std::endl;
        std::cout << *--ite << std::endl;
        std::cout << *ite-- << std::endl;

        (*it).m();
        (*ite).m();

        std::cout << *(--it) << std::endl;
        std::cout << *(it--) << std::endl;
        std::cout << *it-- << std::endl;
        std::cout << *--it << std::endl;

        return (0);
}
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