/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/06 15:20:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include "../includes/vector.hpp"





#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type
#define TESTED_NAMESPACE std

// --- Class foo
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


template <typename T>
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


#define TESTED_TYPE std::string

void    checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
                                        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
        static int i = 0;
        std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
        printSize(vct);
}

int             main(void)
{
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = std::string((vct.size() - i), i + 65);
        // printSize(vct);

        // checkErase(vct, vct.erase(vct.begin() + 2));

        // checkErase(vct, vct.erase(vct.begin()));
        // checkErase(vct, vct.erase(vct.end() - 1));

        checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
        checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

        vct.push_back("Hello");
        vct.push_back("Hi there");
        printSize(vct);
        checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

        vct.push_back("ONE");
        vct.push_back("TWO");
        vct.push_back("THREE");
        vct.push_back("FOUR");
        printSize(vct);
        checkErase(vct, vct.erase(vct.begin(), vct.end()));

        return (0);
}