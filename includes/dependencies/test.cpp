/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:55:57 by samajat           #+#    #+#             */
/*   Updated: 2023/02/25 20:43:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include "pair.hpp"
#include <functional>
#include <memory>
#include <iostream>
#include <algorithm>
#include <map>
#include "../containers/map.hpp"


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

template <typename Iterator>
void    print_node(Iterator node)
{
    std::cout << "Key: "<< node->first  << std::endl;
    if (node.base()->parent)
        std::cout << "parent: "<< node.base()->parent->data.first  << std::endl;
    if (node.base()->left)
        std::cout << "left: "<< node.base()->left->data.first  << std::endl;
    if (node.base()->right)
        std::cout << "right: "<< node.base()->right->data.first  << std::endl;
    std::cout << "--------------\n";
}



// int main ()
// {
//      bst a;
//     bool s;

//     a.insert(ft::make_pair(5, 3));
//     a.insert(ft::make_pair(1, 3));
//     a.insert(ft::make_pair(6, 3));
    
        
//     // bst::reverse_iterator i = a.rbegin() ;
//     // std::cout << (*a.rbegin()).first<< std::endl;
//     for (bst::reverse_iterator i = a.rbegin() ; i != a.rend() ; i++)
//         std::cout << (*i).first << std::endl;

//     // for (bst::iterator i = a.begin() ; i != a.end() ; i++)
//     //     print_node (i);
//     // print_node (i);

//     // for (bst::iterator it = a.begin(); it != a.end(); it++)
//     //     std::cout << it->first << "---" << it->second << std::endl;
    
// }

// typedef int bla;
int main ()
{
    // bool l;
    // std::cout << std::is_same<bla, int>::value << std::endl; // prints "true"

    std::map <int , int > a;
    a.insert(std::make_pair(5, 3));
    a.insert(std::make_pair(1, 3));
    a.insert(std::make_pair(6, 3));
    std::map <int , int >::iterator i = a.begin();
    i =  a.begin();
    // for (std::map <int , int >::reverse_iterator i = a.rbegin(); i != a.rend(); i++)
    //     std::cout << (*i).first << std::endl;


    // //     std::cout << i->first << std::endl;
    // std::cout << (*a.rbegin()).first << std::endl;
    // // std::cout << a.rend() << std::endl;
    
}
