/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/08 12:27:34 by samajat          ###   ########.fr       */
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
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
class binary_tree

{
    public:
    typedef     Key                                 key_type;
    typedef     T                                   mapped_type;
    typedef 	pair<const key_type,mapped_type>    value_type;
    typedef 	data                    value_type;
    typedef     Compare                 key_compare;
    typedef     Allocator               allocator_type;
    

    binary_tree();
    binary_tree(const binary_tree& copy);
    binary_tree& operator=(const binary_tree& copy);
    ~binary_tree();

    private:
    tree_node   *__tree_root;
    
    
    public:
    tree_node   *create_node(value_type value);

    //insertion
    void         insert_node (tree_node *new_node);

    //searching
    tree_node   *search_node(key_type to_search);
};

}

#endif