/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/24 18:43:39 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "../iterators/tree_iterator.hpp"
// #include "../iterators/const_tree_iterator.hpp"
#include "node.hpp"


namespace ft
{


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
    typedef     Compare                                 value_compare;
    typedef 	ft::pair<const key_type,mapped_type>    value_type;
    typedef     Node<value_type>                        Node;
    typedef     Node*                                   node_ptr ;
    
    typedef     size_t                                  size_type;
    typedef     Allocator                               allocator_type;
    typedef     typename Allocator::template rebind<Node>::other          node_allocator_type;
    
    //iterator      
    typedef     tree_iterator<node_ptr >                    iterator;

    

    private:
    node_ptr        create_node(value_type value){  node_ptr  new_node; new_node = __allocat.allocate (1);   __allocat.construct(new_node, Node(value));
                                                                      return (new_node);}
    node_ptr        insert_node (node_ptr& start_node, node_ptr  new_node, bool& success);
    void            tarverseNodesPostOrder(node_ptr _tree, void (binary_tree<Key,T,Compare ,Allocator>::*func)(node_ptr));
    
    void            delete_node(node_ptr  _node){    __allocat.destroy(_node);   __allocat.deallocate(_node, 1);}
    void            delete_leaf (node_ptr  _node);
    void            delete_1_child_parent (node_ptr  _node);
    void            delete_2_child_parent (iterator element);

    node_ptr        find_parent(node_ptr  __tree, value_type& value, bool &node_is_left);
    

    public:
    
/* ************************************************************************** */
                            // Costructors :
/* ************************************************************************** */

    binary_tree(const value_compare& comp =  value_compare(std::less<int>()),
                  const node_allocator_type& alloc = node_allocator_type());
    binary_tree(const binary_tree& copy);

/* ************************************************************************** */
                            // Overload func :
/* ************************************************************************** */

    binary_tree& operator=(const binary_tree& copy);

/* ************************************************************************** */
                            // Getters :
/* ************************************************************************** */

    node_ptr  get_tree() const {  return (__tree_root);}

    
/* ************************************************************************** */
                            // Insertion :
/* ************************************************************************** */

    pair<iterator,bool>                 insert (const value_type& val)
    {
        bool        success;
        node_ptr    new_node = create_node (val);
        iterator    it =  insert_node (__tree_root, new_node, success);
        return (make_pair(it, success));
    }
    iterator                            insert (iterator position, value_type&  val)
    {
        node_ptr pos = position.base();
        if (!find(val->first))
            pos = __end;
        node_ptr    new_node = create_node (val);
        return (iterator(insert_node(pos, new_node, bool())));
    }


    template <class InputIterator> 
    void                                insert (InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            insert(*first);
            first++;
        }
        
    }

/* ************************************************************************** */
                            // Searching :
/* ************************************************************************** */

    node_ptr  find( key_type to_search);
    
/* ************************************************************************** */
                            // Capacity :
/* ************************************************************************** */

    size_type   size() const{   return (__size);}


/* ************************************************************************** */
                            // Iterators :
/* ************************************************************************** */

    void erase (iterator position)
    {
        node_ptr PosPtr = position.base();
        while (PosPtr->has_2_child())
            PosPtr->swap_for_deletion (next_node(PosPtr), __tree_root);
        if (PosPtr->has_1_child())
            delete_1_child_parent (PosPtr);
        else
            delete_leaf (PosPtr);
        __size--;
    }
    
    size_type erase (const key_type& k)
    {
        node_ptr nodeToFind = find(k);
        erase (iterator (nodeToFind));
        return (nodeToFind != nullptr);
    }
    
    void erase (iterator first, iterator last)
    {
        iterator next_element = first;
        while (first != last)
        {
            ++first;
            erase (next_element);
            next_element = first;
        }
        // std::cout << __size <<std::endl;
        if (!__size){     __tree_root = nullptr;}
    }


/* ************************************************************************** */
                            // Iterators :
/* ************************************************************************** */

    // iterator
    iterator                begin(){    if (!__tree_root)   return (iterator(__end));
                                        return (iterator(max_left(__tree_root)));}

    iterator                end(){    return (iterator(__end));}

    pair<iterator,iterator>             
    equal_range (const key_type& k)
    {
        node_ptr to_find;

        to_find = this->find(k);
        if (to_find)
            return make_pair(iterator(to_find), iterator(next_node(to_find)));
        return (make_pair(iterator(__end), iterator(next_node(__end))));
    }
    

    iterator lower_bound( const Key& key )
    {
        node_ptr  node = __tree_root;

        while (node)
        {
            if (!__value_cmp(node->data, key))//if __tree->data >= value
                return iterator (node);
            else if (__value_cmp(key, node->data))
                node = node->left;
            else
                node = node->right;
        }
        return (iterator(__end));
    }


    iterator upper_bound( const Key& key )
    {
        node_ptr  node = __tree_root;

        while (node)
        {
            if (__value_cmp(node->data, key))//if __tree->data < value
                return iterator (node);
            else if (__value_cmp(key, node->data))
                node = node->left;
            else
                node = node->right;
        }
        return (iterator(__end));
    }

    //deletion

/* ************************************************************************** */
                            // Destroy :
/* ************************************************************************** */

    void        clear();

    void        swap (binary_tree &x)
    {
        swap (__end, x.__end);
        swap (__size, x.__size);
        swap (__allocat, x.__allocat);
        swap (__value_cmp, x.__value_cmp);
    }
    ~binary_tree() {       this->clear();  delete_node (__end); };
    
    private:
    
    node_ptr                                        __tree_root;
    node_ptr                                        __end;
    size_type                                       __size;
    node_allocator_type                             __allocat;
    value_compare                                   __value_cmp;
};





template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator>::binary_tree(const value_compare& cmp, const   node_allocator_type& alloc ): __value_cmp(cmp), __allocat(alloc), __tree_root(nullptr)
{
    __end = create_node(value_type(key_type(), mapped_type()));
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
    __allocat = copy.__allocat;
    insert (other.begin(), other.end());
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
binary_tree<Key,T,Compare ,Allocator> & binary_tree<Key,T,Compare ,Allocator>::operator=(const binary_tree& copy)
{
    if (this != &copy)
    {
        this->clear();
        __value_cmp = copy.__value_cmp;
        insert (copy.begin(), copy.end());
    }
    return (*this);
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
        if (__value_cmp(__tree->data, value))//if __tree->data < value
        {
            node_is_left = false;
            if (!__tree->right)
                return (__tree);
            __tree = __tree->right;
        }
        else if (__value_cmp(value, __tree->data))
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
binary_tree<Key,T,Compare ,Allocator>::insert_node (node_ptr& start_node, node_ptr  new_node, bool& success)
{
    node_ptr  node;
    bool     left;


    success = false;
    if (!start_node)
    {
        __size++;
        start_node = new_node;
        start_node->parent = __end;
        __end->left = start_node;
        success  = true;
        return (new_node);
    }
    node = find_parent(start_node, new_node->data, left);
    if (keys_are_equal(node, new_node))
        return (node);
    success  = true;
    if(left)
        node->set_node_to_left(new_node);
    else
        node->set_node_to_right(new_node);
        __size++;

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
    value_type to_search_value  = make_pair(to_search, key_type());

    while (node)
    {
        if (__value_cmp(node->data, to_search_value))//if __tree->data < value
            node = node->right;
        else if (__value_cmp(to_search_value, node->data))
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
void    binary_tree<Key,T,Compare ,Allocator>::tarverseNodesPostOrder(Node *_tree, void (binary_tree<Key,T,Compare ,Allocator>::*func)(node_ptr))
{
    if (!_tree)
        return;
    tarverseNodesPostOrder(_tree->right, func);
    tarverseNodesPostOrder(_tree->left, func);
    (this->*func)(_tree);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator >
void    binary_tree<Key,T,Compare ,Allocator>::clear()
{
    tarverseNodesPostOrder(this->__tree_root, &binary_tree::delete_node);
    __size      = 0;
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






// template <typename U, typename V, typename Allocator > 
// void    print_node (Node<pair<U, V>, Allocator > *_node)
// {
//     std::cout << _node << std::endl;
//     std::cout << "key : " << _node->data.first << " -- " << "value : " << _node->data.second << std::endl;
// }

};

#endif

    // typedef     const_tree_iterator<const node_ptr >        const_iterator;
    // const_iterator          begin() const{    return (const_iterator(__tree_root->find_first_node(__tree_root)));};
    // const_iterator          end() const{    return (const_iterator(__end));}
    // pair<const_iterator,const_iterator> 
    // equal_range (const key_type& k) const
    // {
        // node_ptr to_find;

        // to_find = this->find(k);
        // if (to_find)
        //     return make_pair(const_iterator(to_find), const_iterator(next_node(to_find)));
        // return (make_pair(iterator(__end), iterator(next_node(__end))));
    // }

    // const_iterator lower_bound( const Key& key ) const
    // {
        //node_ptr  node = __tree_root;

        // while (node)
        // {
        //     if (!__value_cmp(node->data, to_search))//if __tree->data >= value
        //         return const_iterator (node);
        //     else if (__value_cmp(to_search, node->data))
        //         node = node->left;
        //     else
        //         node = node->right;
        // }
        // return (const_iterator(__end));
    // }

    // const_iterator upper_bound( const Key& key ) const;
    // {
    //     node_ptr  node = __tree_root;

    //     while (node)
    //     {
    //         if (__value_cmp(node->data, to_search))//if __tree->data < value
    //             return iterator (node);
    //         else if (__value_cmp(to_search, node->data))
    //             node = node->left;
    //         else
    //             node = node->right;
    //     }
    //     return (iterator(__end));
    // }
