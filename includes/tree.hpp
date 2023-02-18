/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/18 14:56:01 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "iterators/tree_iterator.hpp"
#include "iterators/const_tree_iterator.hpp"

namespace ft
{
    

    enum Dir
    {
        BACK_FROM_RIGHT =  1,
        BACK_FROM_LEFT  = -1,
    };




//this struct is gonna be a class
template <typename T, typename Allocator>
struct tree_node
{
    typedef Allocator                               allocator_type;
    typedef T                                       data_value_type;
    typedef T&                                      data_value_type_ref;

    tree_node   *parent;
    tree_node   *left;
    tree_node   *right;
    T           data;
    
    tree_node(T d = T()): data(d)
    {
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    tree_node& operator=(const tree_node& node)
    {
        this->parent = node.parent;
        this->left = node.left;
        this->right = node.right;
    }
    
    void        set_node_to_left (tree_node *_node){    this->left = _node; _node->parent = this;}
    void        set_node_to_right (tree_node *_node){    this->right = _node; _node->parent = this;}


    tree_node   *find_last_node(tree_node   * _node) ;
    tree_node   *find_first_node(tree_node   * _node) ;

    void    swap(tree_node& x)
    {
        if (this->parent)
        {
            if (this->parent->right == this)
                std::swap(this->parent->right, &x);
            else if (this->parent->left == this)
                std::swap(this->parent->left, &x);
        }
        if (x.parent)
        {
            if (x.parent->right == &x)
                std::swap(x.parent->right, &x);
            else if (x.parent->left == &x)
                std::swap(x.parent->left, this);
        }
        if (x.right)
            x.right->parent = this;
        if (x.left)
            x.left->parent = this;
        std::swap(this->parent, x.parent);
        std::swap(this->left, x.left);
        std::swap(this->right, x.right);
    }
    bool    is_leaf () {    return (!this->left && ! this->right);}
    bool    has_2_child () {    return (this->left &&   this->right);}
    bool    has_1_child () {    return (!is_leaf() && !has_2_child());}
};


template <typename U, typename V, typename Allocator > 
void delete_node(tree_node<pair<U, V>, Allocator > *_node)
{
    delete _node;
}

template <typename T, typename Allocator>
tree_node<T, Allocator>*
tree_node<T, Allocator>::find_last_node(tree_node<T, Allocator>* _node) 
{
    tree_node<T, Allocator>* tmp = _node;
    while (tmp && tmp->parent)
        tmp = tmp->parent;
    while (tmp && tmp->right)
        tmp = tmp->right;
    return (tmp);
}



template <typename T, typename Allocator>
tree_node<T, Allocator>* 
tree_node<T, Allocator>::find_first_node(tree_node<T, Allocator>* _node)  
{
    tree_node<T, Allocator>* tmp = _node;
    while (tmp && tmp->parent)
        tmp = tmp->parent;
    while (tmp && tmp->left)
        tmp = tmp->left;
    return (tmp);
}



template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> >
    >
class binary_tree

{
    public:
    typedef     Key                                     key_type;
    typedef     T                                       mapped_type;
    typedef 	ft::pair<const key_type,mapped_type>    value_type;
    typedef     Compare                                 key_compare;
    typedef     Allocator                               allocator_type;
    typedef     tree_node<value_type, allocator_type>   tree_node;
    typedef     size_t                                  size_type;
    
    typedef     tree_iterator<tree_node*>               iterator;
    typedef     const_tree_iterator<const tree_node*>   const_iterator;

    
    tree_node   *create_node(value_type value);
    private:

    
    public:

    binary_tree(const   allocator_type& = allocator_type());
    binary_tree(const binary_tree& copy);
    binary_tree& operator=(const binary_tree& copy);
    ~binary_tree();
   
    tree_node   *get_tree() const;
    //insertion
    void         insert_node (tree_node *_tree, tree_node *new_node);
    
    //searching
    tree_node   *search_node(tree_node *_tree, key_type to_search);
    
    void        tarverseNodesInOrder(tree_node *_tree, void (*func)(tree_node*));
    void        tarverseNodesPreOrder(tree_node *_tree, void (*func)(tree_node*));
    void        tarverseNodesPostOrder(tree_node *_tree, void (*func)(tree_node*));
    
    // tree_node*  clone_binary_tree(tree_node *_copy);
    
    
    size_type   size() const;
    void        clear();
    
    iterator        begin();
    const_iterator          begin() const;

    
    iterator        end();
    const_iterator          end() const;

    //deletion
    void    delete_leaf (tree_node   * _node);
    void    delete_1_child_parent (tree_node   * _node);
    void    delete_2_child_parent (iterator element);

    void    delete_random_node (iterator element);
    
    
    tree_node                                      *__tree_root;
    tree_node                                      *_begin;
    tree_node                                      *_end;
    private:
    size_type                                       __size;
    allocator_type                                  __allocat;
};


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator>::binary_tree(const   allocator_type& alloc): _begin(nullptr),
                                                         _end(nullptr), __allocat(alloc) 
{
    __size = 0;
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator>::binary_tree(const binary_tree& copy)
{
    __tree_root = copy.__tree_root;
    this->__size = copy.__size;
    __allocat = copy.__allocat;
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator> & binary_tree<Key,T,Compare ,Allocator>::operator=(const binary_tree& copy)
{
    (void)copy;
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
typename binary_tree<Key,T,Compare ,Allocator>::tree_node   
*binary_tree<Key,T,Compare ,Allocator>::create_node(value_type value)
{
    return (new tree_node(value));
}




template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
void    binary_tree<Key,T,Compare ,Allocator>::insert_node (tree_node *_tree, tree_node *new_node)
{
    _begin      = nullptr;
    _end        = nullptr;
    if (!__tree_root)
    {
        __size++;
        __tree_root = new_node;
    }
    else
    {
        if (new_node->data.first < _tree->data.first && !_tree->left) { _tree->set_node_to_left(new_node); __size++; return;};
        if (new_node->data.first > _tree->data.first && !_tree->right) { _tree->set_node_to_right(new_node); __size++; return;};
        
        if (new_node->data.first < _tree->data.first)
            insert_node(_tree->left, new_node);
        else
            insert_node(_tree->right, new_node);
    }
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
typename binary_tree<Key,T,Compare ,Allocator>::tree_node   
*binary_tree<Key,T,Compare ,Allocator>::search_node(tree_node *_tree, key_type to_search)
{
    if (_tree)
    {
        if (_tree->data.first == to_search) { return (_tree);};
        
        if (to_search < _tree->data.first)
            search_node(_tree->left, to_search);
        else
            search_node(_tree->right, to_search);
    }
    return (nullptr);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesInOrder(tree_node *_tree, void (*func)(tree_node*))
{
    if (!_tree)
        return;
    tarverseNodesInOrder(_tree->left, func);
    func(_tree);
    tarverseNodesInOrder(_tree->right, func);
}




template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesPreOrder(tree_node *_tree, void (*func)(tree_node*))
{
    if (!_tree)
        return;
    func(_tree);
    tarverseNodesPreOrder(_tree->right, func);
    tarverseNodesPreOrder(_tree->left, func);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesPostOrder(tree_node *_tree, void (*func)(tree_node*))
{
    if (!_tree)
        return;
    tarverseNodesPreOrder(_tree->right, func);
    tarverseNodesPreOrder(_tree->left, func);
    func(_tree);
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
typename binary_tree<Key,T,Compare ,Allocator>::tree_node   
*binary_tree<Key,T,Compare ,Allocator>::get_tree() const
{
    return (__tree_root);
}



template<
    class Key,
    class T,
    class Compare ,
    class Allocator >
typename binary_tree<Key,T,Compare ,Allocator>::size_type   
binary_tree<Key,T,Compare ,Allocator>::size() const 
{
    return (__size);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator >
void    binary_tree<Key,T,Compare ,Allocator>::clear()
{
    tarverseNodesPostOrder(this->__tree_root, &delete_node);
    __size      = 0;
    _begin      = nullptr;
    _end        = nullptr;
    __tree_root = nullptr;
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

typename binary_tree<Key,T,Compare ,Allocator>::iterator
binary_tree<Key,T,Compare ,Allocator>::begin()
{
    return (iterator(__tree_root->find_first_node(__tree_root)));
}



template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

typename binary_tree<Key,T,Compare ,Allocator>::iterator
binary_tree<Key,T,Compare ,Allocator>::end()
{
    return (iterator(_end));
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator >


typename binary_tree<Key,T,Compare ,Allocator>::const_iterator
binary_tree<Key,T,Compare ,Allocator>::begin() const
{
    return (__tree_root->find_first_node(__tree_root));
}



template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

typename binary_tree<Key,T,Compare ,Allocator>::const_iterator
binary_tree<Key,T,Compare ,Allocator>::end() const
{
    return (const_iterator(_end));
}



template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

  }

template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

void    binary_tree<Key,T,Compare ,Allocator>::delete_1_child_parent (tree_node   * _node)
{
    tree_node   *child;

    child = _node->right ? _node->right : _node->left;
    if (_node->parent->left == _node)
        _node->parent->left = child;
    else
        _node->parent->right = child;
    delete_node(_node);
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

void    binary_tree<Key,T,Compare ,Allocator>::delete_2_child_parent (iterator element)
{
    tree_node   * _node =  element.base();
    tree_node   * _next_node =  (++element).base();
    
    
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

void    binary_tree<Key,T,Compare ,Allocator>::delete_random_node (iterator element)
{
    
}




template <typename U, typename V, typename Allocator > 
void    print_node (tree_node<pair<U, V>, Allocator > *_node)
{
    std::cout << _node << std::endl;
    std::cout << "key : " << _node->data.first << " -- " << "value : " << _node->data.second << std::endl;
}

}
#endif