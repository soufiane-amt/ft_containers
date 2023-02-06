/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/06 10:26:07 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include "../includes/vector.hpp"





#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type
#define TESTED_NAMESPACE ft

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


template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
        std::cout << (first < second) << std::endl;
        std::cout << (first <= second) << std::endl;
        std::cout << (first > second) << std::endl;
        std::cout << (first >= second) << std::endl;
        if (redo)
                ft_eq_ope(second, first, 0);
}


/*
single element (1)
        iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
        template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last);
*/

#define TESTED_TYPE int

int             main(void)
{
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(4, 1337);
		vct.insert(vct.begin() + 1, 12);
		for (size_t i = 0; i < vct.size(); i++)
			std::cout << vct[i] << std::endl;		
        // TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
        // TESTED_NAMESPACE::vector<TESTED_TYPE> vct3;

        // for (unsigned long int i = 0; i < vct.size(); ++i)
        //         vct[i] = (vct.size() - i) * 3;
        // printSize(vct);

        // vct2.insert(vct2.end(), 42);
        // vct2.insert(vct2.begin(), 2, 21);
        // printSize(vct2);

        // vct2.insert(vct2.end() - 2, 42);
        // printSize(vct2);

        // vct2.insert(vct2.end(), 2, 84);
        // printSize(vct2);

        // vct2.resize(4);
        // printSize(vct2);

        // vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
        // vct.clear();
        // printSize(vct2);

        // printSize(vct);

        // for (int i = 0; i < 5; ++i)
        //         vct3.insert(vct3.end(), i);
        // vct3.insert(vct3.begin() + 1, 2, 111);
        // printSize(vct3);

        return (0);
}