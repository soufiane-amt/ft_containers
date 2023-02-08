/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/08 16:15:47 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP


namespace ft
{


template <typename T>
struct tree_node
{
    tree_node   *parent;
    tree_node   *left;
    tree_node   *right;
    T           data;
    
    tree_node(T d = T())
    {
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->data = d;
    }
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
    typedef 	data                                value_type;
    typedef     Compare                             key_compare;
    typedef     Allocator                           allocator_type;
    typedef     tree_node<value_type>               tree_node;

    private:
    allocator_type                                  __allocat;
    tree_node                                      *__tree_root;
    
    public:

    binary_tree(const   allocator_type& = allocator_type());
    binary_tree(const binary_tree& copy);
    binary_tree& operator=(const binary_tree& copy);
    ~binary_tree();
   
    //insertion
    void         insert_node (tree_node *sub_tree, tree_node *new_node);
    //searching
    tree_node   *search_node(key_type to_search);
    
    
    private:
    tree_node   *create_node(value_type value);
};


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator>::binary_tree(const   allocator_type&):__tree_root(nullptr)
{
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >

binary_tree<Key,T,Compare ,Allocator>::binary_tree(const binary_tree& copy)
{
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator>::binary_tree& operator=(const binary_tree& copy)
{
    
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator>::~binary_tree()
{
    
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
tree_node   *binary_tree<Key,T,Compare ,Allocator>::create_node(value_type value)
{
    return (new tree_node(value));
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
void    binary_tree<Key,T,Compare ,Allocator>::insert_node (tree_node *sub_tree, tree_node *new_node)
{
    if (!__tree_root)
        __tree_root = new_node;
    else
    {
        
        if (new_node->data.first < sub_tree->data.first && !sub_tree->left) { sub_tree->left = new_node; return;};
        if (new_node->data.first > sub_tree->data.first && !sub_tree->right) { sub_tree->right = new_node; return;};
        if (new_node->data.first < sub_tree->data.first)
            insert_node(sub_tree->left, new_node);
        else
            insert_node(sub_tree->right, new_node);
    }
}


}
#endif