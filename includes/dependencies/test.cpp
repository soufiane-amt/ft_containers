/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:55:57 by samajat           #+#    #+#             */
/*   Updated: 2023/02/23 18:30:45 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include "pair.hpp"
#include <functional>
#include <memory>
#include <iostream>
#include <map>


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
    bool s;

    srand (time(NULL));
    for (size_t i = 0; i < 100; i++)
        a.insert(ft::make_pair(rand()%1000000000, 3));
    
    
    for (bst::iterator it = a.begin(); it != a.end(); it++)
        std::cout << it->first << "---" << it->second << std::endl;
    
}

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
