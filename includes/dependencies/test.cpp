/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:55:57 by samajat           #+#    #+#             */
/*   Updated: 2023/02/21 18:41:39 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include <functional>
#include <memory>
#include <iostream>

typedef ft::binary_tree <int, int, std::less<int> ,std::allocator<int> > bst;
int main ()
{
    bst a;
    
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (4, 3)));
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (5, 3)));
    a.insert_node(a.__tree_root, a.create_node( ft::pair <int, int> (1, 3)));
    bst::iterator it = a.begin();
    std::cout << it->first << std::endl;
}