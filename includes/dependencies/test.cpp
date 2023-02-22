/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:55:57 by samajat           #+#    #+#             */
/*   Updated: 2023/02/22 14:59:06 by samajat          ###   ########.fr       */
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

class value_compare
{
    
        std::less<int> comp;
        typedef 	ft::pair<const int,int>    value_type;
    public:
        value_compare(std::less<int> c) : comp(c) {}
        bool operator()(const value_type &_lhs, const value_type &_rhs) const
        {
            return comp(_lhs.first, _rhs.first);
        }
};

typedef ft::binary_tree <int, int, value_compare ,std::allocator<int> > bst;

int main ()
{
    bst a;
    
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (4, 3)));
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (5, 3)));
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (1, 3)));
    bst::iterator it = a.begin();
    std::cout << it->first << std::endl;
}