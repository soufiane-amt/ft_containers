/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/12 11:27:02 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
// #include "../includes/tree.hpp"
// #include "../includes/vector.hpp"





// #define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type
// #define TESTED_NAMESPACE ft

// // --- Class foo
// template <typename T>
// class foo {
// 	public:
// 		typedef T	value_type;

// 		foo(void) : value(), _verbose(false) { };
// 		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
// 		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
// 		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
// 		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
// 		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
// 		foo &operator=(value_type src) { this->value = src; return *this; };
// 		foo &operator=(foo const &src) {
// 			if (this->_verbose || src._verbose)
// 				std::cout << "foo::operator=(foo) CALLED" << std::endl;
// 			this->value = src.value;
// 			return *this;
// 		};
// 		value_type	getValue(void) const { return this->value; };
// 		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

// 		operator value_type(void) const {
// 			return value_type(this->value);
// 		}
// 	private:
// 		value_type	value;
// 		bool		_verbose;
// };

// template <typename T>
// std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
// 	o << bar.getValue();
// 	return o;
// }
// // --- End of class foo

// template <typename T>
// T	inc(T it, int n)
// {
// 	while (n-- > 0)
// 		++it;
// 	return (it);
// }

// template <typename T>
// T	dec(T it, int n)
// {
// 	while (n-- > 0)
// 		--it;
// 	return (it);
// }


// template <typename T>
// void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
// {
// 	const T_SIZE_TYPE size = vct.size();
// 	const T_SIZE_TYPE capacity = vct.capacity();
// 	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
// 	// Cannot limit capacity's max value because it's implementation dependent

// 	std::cout << "size: " << size << std::endl;
// 	std::cout << "capacity: " << isCapacityOk << std::endl;
// 	std::cout << "max_size: " << vct.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
// 		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != ite; ++it)
// 			std::cout << "- " << *it << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }


#include <map>

template <class value_type = void>
struct comp
{
 
    bool    operator()(const value_type& a, const value_type& b)const 
    {
        return (a > b);
    }
};

#define TESTED_TYPE int
typedef std::vector<int> MyVector;
int             main(void)
{
    std::map<int, int> m;
    m.insert (std::pair<int, int>(1, 4));
    // m.insert (std::pair<int, int>(2, 4));
    // m.insert (std::pair<int, int>(3, 4));
    std::map<int, int>::iterator itr;
    itr = m.begin();
    std::cout << itr->first << std::endl;
    // std::map<int, int > m;
    // m[34] = 4;
    // m[3] = 24;
    // m[4] = 41;
    // m[2] = 14;
    // for (std::map<int, int >::iterator i = m.begin(); i != m.end(); i++)
    //     std::cout << (*i).first << std::endl;
    
    // ft::binary_tree<int , int > b;
    // srand(time(NULL));
    // std::pair<int, int> a;
    // ft::binary_tree<int, int > b; 
    // for (size_t i = 0; i < 100; i++)
    // {
        // b.insert_node(b.__tree_root, b.create_node(ft::pair< int, int>(5, 5 + 1)));
        // b.insert_node(b.__tree_root, b.create_node(ft::pair< int, int>(2, 2 + 1)));
        // b.insert_node(b.__tree_root, b.create_node(ft::pair< int, int>(3, 3 + 1)));
        // b.insert_node(b.__tree_root, b.create_node(ft::pair< int, int>(4, 4 + 1)));
        // b.insert_node(b.__tree_root, b.create_node(ft::pair< int, int>(7, 7 + 1)));
        // b.insert_node(b.__tree_root, b.create_node(ft::pair< int, int>(6, 6 + 1)));
        /* code */
    // }
    
    // b.tarverseNodesPreOrder(b.__tree_root, ft::print_node);
    // print_node (b.search_node(b.__tree_root, 5));
    return (0);
}