/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:55:57 by samajat           #+#    #+#             */
/*   Updated: 2023/02/22 19:07:26 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <functional>
#include <memory>
#include <iostream>

// struct value_compare
// {
//     int a;
//     bool operator()(i)
// };

// class value_compare
// {
    
//         std::less<int> comp;
//         typedef 	ft::pair<const int,int>    value_type;
//     public:
//         value_compare(std::less<int> c) : comp(c) {}
//         bool operator()(const value_type &_lhs, const value_type &_rhs) const
//         {
//             return comp(_lhs.first, _rhs.first);
//         }
// };

// typedef ft::binary_tree <int, int, value_compare ,std::allocator<int> > bst;

// int main ()
// {
    // bst a;
    // bool s;
    // for (size_t i = 0; i < 10; i++)
        // a.insert_node(a.create_node( ft::pair <const int, int> (i, 3)), s);
    // 
    // for (bst::iterator it = a.begin(); it != a.end(); it++)
        // std::cout << it->first << "---" << it->second << std::endl;
    // ft::Node<ft::pair <const int, int > >* ptr  = a.insert_node(a.create_node( ft::pair <const int, int> (5, 5)), s);
    // std::cout << ptr->data.first << "<--->" << ptr->data.second << std::endl;
// }

// int main ()
// {
    // bst a;
    // bool s;
    // ft::pair<bst::iterator,bool> p;
    // for (size_t i = 0; i < 100; i++)
        // p = a.insert(ft::pair <const int, int> (i, 3));
    // 
    // for (bst::iterator it = a.begin(); it != a.end(); it++)
        // std::cout << it->first << "---" << it->second << std::endl;
    // ft::pair<bst::iterator,bool> p = a.insert(ft::pair <const int, int> (5, 45));
    // std::cout << p.first->first << "+++++" << p.first->second << std::endl;
    // std::cout << p.second << std::endl;
// }

#include <map>
int main ()
{
    std::map<int, int> my_map;
    my_map.insert(std::pair<int, int>(1, 45));
    my_map.insert(std::pair<int, int>(2, 45));
    my_map.insert(std::pair<int, int>(3, 45));
    my_map.clear();
    for (std::map<int, int>::iterator it = my_map.begin(); it != my_map.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}