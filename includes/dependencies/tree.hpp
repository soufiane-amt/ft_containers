/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/22 18:16:43 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "../iterators/tree_iterator.hpp"
// #include "../iterators/const_tree_iterator.hpp"
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
    typedef     Compare                                 value_compare;
    typedef     size_t                                  size_type;
    
    typedef     Node<value_type>                            Node;
    typedef     Node*                                       node_ptr ;
    typedef     typename Allocator::template rebind<Node>::other          allocator_type;
    
    //iterator      
    typedef     tree_iterator<node_ptr >                    iterator;
    // typedef     const_tree_iterator<const node_ptr >        const_iterator;

    
    node_ptr  create_node(value_type value){  node_ptr  new_node; new_node = __allocat.allocate (1);   __allocat.construct(new_node, Node(value));
                                                                      return (new_node);}
    
    void delete_node(node_ptr  _node){    __allocat.destroy(_node);   __allocat.deallocate(_node, 1);}

    // private:

    public:

    binary_tree(const value_compare& comp =  value_compare(std::less<int>()),
                  const allocator_type& alloc = allocator_type());
        
    binary_tree(const binary_tree& copy);
    
    
    binary_tree& operator=(const binary_tree& copy);
    ~binary_tree(){}
   
    node_ptr  get_tree() const {  return (__tree_root);}
    
    
    //insertion
    node_ptr      find_parent(node_ptr  __tree, value_type& value, bool &node_is_left);
    node_ptr      insert_node (node_ptr  new_node, bool& success);
    
    pair<iterator,bool>                 insert (const value_type& val)
    {
        bool        success;
        node_ptr    new_node = create_node (val);
        iterator    it =  insert_node (new_node, success);
        return (make_pair(it, success));
    }
    iterator                            insert (iterator position, value_type&  val);
    template <class InputIterator> 
    void                                insert (InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            insert(*first);
            first++;
        }
        
    }

    
    //searching
    node_ptr  find( key_type to_search);
    

    //tarverseNodes
    void        tarverseNodesInOrder(node_ptr  _tree, void (*func)(node_ptr ));
    void        tarverseNodesPreOrder(node_ptr  _tree, void (*func)(node_ptr ));
    void        tarverseNodesPostOrder(node_ptr  _tree, void (*func)(node_ptr ));
    
    
    size_type   size() const{   return (__size);}

    void        clear();
    

    // iterator
    iterator                begin(){    return (iterator(max_left(__tree_root)));}
    // const_iterator          begin() const{    return (const_iterator(__tree_root->find_first_node(__tree_root)));};

    iterator                end(){    return (iterator(_end));}
    // const_iterator          end() const{    return (const_iterator(_end));}


    //deletion
    void    delete_leaf (node_ptr  _node);
    void    delete_1_child_parent (node_ptr  _node);
    void    delete_2_child_parent (iterator element);
    void    erase (iterator element);
    


    node_ptr                                         __tree_root;
    
    private:
    node_ptr                                         _begin;
    node_ptr                                         _end;
    size_type                                       __size;
    allocator_type                                  __allocat;
    value_compare                                   value_cmp;
};





template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator>::binary_tree(const value_compare& cmp, const   allocator_type& alloc ): value_cmp(cmp), __allocat(alloc), __tree_root(nullptr)
{
    _begin = create_node(value_type(key_type(), mapped_type()));
    _end = _begin;
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
typename binary_tree<Key,T,Compare ,Allocator>::node_ptr      
binary_tree<Key,T,Compare ,Allocator>::find_parent(node_ptr  __tree, value_type& value, bool &node_is_left)
{
    if (!__tree)
        return (nullptr);
    while (true)
    {
        if (value_cmp(__tree->data, value))//if __tree->data < value
        {
            node_is_left = false;
            if (!__tree->right)
                return (__tree);
            __tree = __tree->right;
        }
        else if (value_cmp(value, __tree->data))
        {
            node_is_left = true;
            if (!__tree->left)
                return (__tree);
            __tree = __tree->left;
        }
        else
            break;
    }
    return (__tree);
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
typename binary_tree<Key,T,Compare ,Allocator>::node_ptr 
binary_tree<Key,T,Compare ,Allocator>::insert_node ( node_ptr  new_node, bool& success)
{
    node_ptr  node;
    bool     left;

    success = false;
    if (!__tree_root)
    {
        __size++;
        __tree_root = new_node;
        __tree_root->parent = _end;
        _end->left = __tree_root;
        success  = true;

        return (new_node);
    }
    node = find_parent(__tree_root, new_node->data, left);
    if (keys_are_equal(node, new_node))
        return (node);
    success  = true;
    if(left)
        node->set_node_to_left(new_node);
    else
        node->set_node_to_right(new_node);
    return (new_node);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
typename binary_tree<Key,T,Compare ,Allocator>::Node   
*binary_tree<Key,T,Compare ,Allocator>::find( key_type to_search)
{
    node_ptr  node = __tree_root;
    if (!node)
        return (nullptr);
    while (true)
    {
        if (value_cmp(node->data, to_search))//if __tree->data < value
            node = node->right;
        else if (value_cmp(to_search, node->data))
            node = node->left;
        else
            return node;
    }
    return (nullptr);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesInOrder(node_ptr  _tree, void (*func)(node_ptr ))
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
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesPreOrder(node_ptr  _tree, void (*func)(node_ptr ))
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
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesPostOrder(node_ptr  _tree, void (*func)(node_ptr ))
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
void    binary_tree<Key,T,Compare ,Allocator>::delete_leaf (node_ptr  _node)
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

void    binary_tree<Key,T,Compare ,Allocator>::delete_1_child_parent (node_ptr  _node)
{
    node_ptr child;

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
    node_ptr _node =  element.base();
    node_ptr _next_node =  (++element).base();
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
    node_ptr _node  = e.base();
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




// template <typename U, typename V, typename Allocator > 
// void    print_node (Node<pair<U, V>, Allocator > *_node)
// {
//     std::cout << _node << std::endl;
//     std::cout << "key : " << _node->data.first << " -- " << "value : " << _node->data.second << std::endl;
// }

};

#endif