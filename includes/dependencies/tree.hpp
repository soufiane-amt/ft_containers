/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/20 17:34:26 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "../iterators/tree_iterator.hpp"
#include "../iterators/const_tree_iterator.hpp"
#include "node.hpp"


namespace ft
{
    //typedef typename _Alloc::template rebind<_Ty>::other _Alty;
    
template<
    class Key,
    class T,
    class Compare,
    class Allocator 
    >
class binary_tree

{
    public:
    typedef     Key                                     key_type;
    typedef     T                                       mapped_type;
    typedef 	ft::pair<const key_type,mapped_type>    value_type;
    typedef     Compare                                 key_compare;
    typedef     Allocator                               allocator_type;
    typedef     size_t                                  size_type;
    
    typedef     Node<value_type, allocator_type>        Node;

    //iterator      
    typedef     tree_iterator<Node*>                    iterator;
    typedef     const_tree_iterator<const Node*>        const_iterator;

    
    private:
    Node   *create_node(value_type value){  Node   *new_node; new_node = __allocat.allocate (1);   __allocat.construct(new_node, Node(value));
                                                                        return (new_node);}

    public:

    binary_tree(const   allocator_type& = allocator_type()): _begin(nullptr), __allocat(alloc) {    
                                                         _end = create_node(value_type(key_type(), mapped_type())); __size = 0;}
    binary_tree(const binary_tree& copy);
    
    
    binary_tree& operator=(const binary_tree& copy);
    ~binary_tree(){}
   
    Node   *get_tree() const {  return (__tree_root);}
    
    
    //insertion
    void         insert_node (Node *_tree, Node *new_node);
    
    //searching
    Node   *find(Node *_tree, key_type to_search);
    

    //tarverseNodes
    void        tarverseNodesInOrder(Node *_tree, void (*func)(Node*));
    void        tarverseNodesPreOrder(Node *_tree, void (*func)(Node*));
    void        tarverseNodesPostOrder(Node *_tree, void (*func)(Node*));
    
    
    size_type   size() const{   return (__size);}

    void        clear();
    

    // iterator
    iterator                begin(){    return (iterator(__tree_root->find_first_node(__tree_root)));}
    const_iterator          begin() const{    return (const_iterator(__tree_root->find_first_node(__tree_root)));};

    iterator                end(){    return (iterator(_end));}
    const_iterator          end() const{    return (const_iterator(_end));}


    //deletion
    void    delete_leaf (Node   * _node);
    void    delete_1_child_parent (Node   * _node);
    void    delete_2_child_parent (iterator element);
    void    erase (iterator element);
    


    private:
    Node                                            *__tree_root;
    Node                                            *_begin;
    Node                                            *_end;
    size_type                                       __size;
    allocator_type                                  __allocat;
};





template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator>::binary_tree(const   allocator_type& = allocator_type()): __allocat(alloc)
{
    _begin = create_node(value_type(key_type(), mapped_type()));
    _end = create_node(value_type(key_type(), mapped_type()));
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
void    binary_tree<Key,T,Compare ,Allocator>::insert_node (Node *_tree, Node *new_node)
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
typename binary_tree<Key,T,Compare ,Allocator>::Node   
*binary_tree<Key,T,Compare ,Allocator>::find(Node *_tree, key_type to_search)
{
    if (_tree)
    {
        if (_tree->data.first == to_search) { return (_tree);};
        
        if (to_search < _tree->data.first)
            find(_tree->left, to_search);
        else
            find(_tree->right, to_search);
    }
    return (nullptr);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesInOrder(Node *_tree, void (*func)(Node*))
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
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesPreOrder(Node *_tree, void (*func)(Node*))
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
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesPostOrder(Node *_tree, void (*func)(Node*))
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
void    binary_tree<Key,T,Compare ,Allocator>::delete_leaf (Node   * _node)
{    
    if (_node->parent->left == _node)
        _node->parent->left = nullptr;
    else
        _node->parent->right = nullptr;

    delete_node(_node);
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

void    binary_tree<Key,T,Compare ,Allocator>::delete_1_child_parent (Node   * _node)
{
    Node   *child;

    child = _node->right ? _node->right : _node->left;
    if (_node->parent)
    {
        if (_node->parent->left == _node)
            _node->parent->left = child;
        else
            _node->parent->right = child;
    }
    child->parent = _node->parent;

    delete_node(_node);
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

void    binary_tree<Key,T,Compare ,Allocator>::delete_2_child_parent (iterator element)
{
    Node   *_node =  element.base();
    Node   *_next_node =  (++element).base();
    (*_node).swap(*_next_node);
    if (_node ->has_1_child())
        delete_1_child_parent(_node);
    else if (_node->is_leaf())
        delete_leaf(_node);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator >

void    binary_tree<Key,T,Compare ,Allocator>::erase (iterator element)
{
    iterator e = element;
    Node   *_node  = e.base();
    if (_node && !_node->parent)
        this->__tree_root  = (++e).base();
    // std::cout << "self " << _node->data.first << std::endl;
    // std::cout << "right " << _node->right->data.first << std::endl;
    // std::cout << "left " << _node->left->data.first << std::endl;
    if (_node->is_leaf())
        delete_leaf(_node);
    else if (_node ->has_1_child())
        delete_1_child_parent(_node);
    else  
        delete_2_child_parent(element);
}




template <typename U, typename V, typename Allocator > 
void    print_node (Node<pair<U, V>, Allocator > *_node)
{
    std::cout << _node << std::endl;
    std::cout << "key : " << _node->data.first << " -- " << "value : " << _node->data.second << std::endl;
}

};

#endif