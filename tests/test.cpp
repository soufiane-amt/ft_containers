/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/03 17:56:14 by samajat          ###   ########.fr       */
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

#define TESTED_TYPE foo<int>

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

int             main(void)
{
        const int size = 5;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_mid;

        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
        TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

        for (int i = size; it_0 != it_1; --i)
                *it_0++ = i;
        printSize(vct, 1);
        it_0 = vct.rbegin();
        cit_1 = vct.rend();
        it_mid = it_0 + 3;
        cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

        std::cout << std::boolalpha;
        std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

        std::cout << "\t\tft_eq_ope:" << std::endl;
        // regular it
        ft_eq_ope(it_0 + 3, it_mid);
        ft_eq_ope(it_0, it_1);
        ft_eq_ope(it_1 - 3, it_mid);
        // const it
        ft_eq_ope(cit_0 + 3, cit_mid);
        ft_eq_ope(cit_0, cit_1);
        ft_eq_ope(cit_1 - 3, cit_mid);
        // both it
        ft_eq_ope(it_0 + 3, cit_mid);
        ft_eq_ope(it_mid, cit_0 + 3);
        ft_eq_ope(it_0, cit_1);
        ft_eq_ope(it_1, cit_0);
        ft_eq_ope(it_1 - 3, cit_mid);
        ft_eq_ope(it_mid, cit_1 - 3);

        return (0);
}