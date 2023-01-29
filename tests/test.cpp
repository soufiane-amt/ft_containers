/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/01/29 18:50:30 by samajat          ###   ########.fr       */
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


/*
single element (1)
        iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
        template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last);
*/


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

#define TESTED_TYPE int

int             main(void)
{
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct;
        TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);

        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);

        /* error expected
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit_(crit);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit2(cit);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it2(rit);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit2(crit);
        */

        std::cout << "OK" << std::endl;
        return (0);
}