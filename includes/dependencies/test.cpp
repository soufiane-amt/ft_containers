/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:55:57 by samajat           #+#    #+#             */
/*   Updated: 2023/02/21 20:58:56 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <functional>
#include <memory>
#include <iostream>


template <typename T>
class comp
{
private:
    std::less<T> key_cmp;
    
public:
    
    bool operator () (const T& a, const T& b)const
    {
        return key_cmp()(a < b);
    }
};
typedef ft::binary_tree <int, int, comp<int>() ,std::allocator<int> > bst;

int main ()
{
    bst a;
    
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (4, 3)));
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (5, 3)));
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (1, 3)));
    bst::iterator it = a.begin();
    std::cout << it->first << std::endl;
}