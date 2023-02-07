/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/07 16:35:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP


namespace ft
{


template <typename data>
struct tree_node
{
    T           data;        
    tree_node   *left;
    tree_node   *right;
};


template<
    class data,
    class Compare ,
    class Allocator 
    >
class binary_tree

{
    public:
    typedef 	data                    value_type;
    typedef     Compare                 key_compare;
    typedef     Allocator               allocator_type;
    

    private:
    tree_node   __tree_root;
    
};

}

#endif