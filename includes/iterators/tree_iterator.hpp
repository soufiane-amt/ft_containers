/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:38:53 by samajat           #+#    #+#             */
/*   Updated: 2023/02/21 15:53:09 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../dependencies/utility.hpp"
// #include "const_tree_iterator.hpp"

namespace ft 
{
template<class _ite>
class tree_iterator
{
    public:                                       
        typedef _ite                                                       iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type        value_type;
        typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
        typedef typename iterator_traits<iterator_type>::pointer           pointer;
        typedef typename iterator_traits<iterator_type>::reference         reference;
        
        typedef typename value_type::data_value_type                       data_value_type;
        typedef data_value_type*                                           data_value_type_ptr;
        typedef data_value_type&                                           data_value_type_ref;
        typedef const data_value_type_ptr                                  const_data_value_type_ptr;
        
        typedef const reference                                            const_reference;
        typedef const pointer                                              const_pointer;

        tree_iterator();
        
        tree_iterator(const tree_iterator &other);
        
        // tree_iterator(const const_tree_iterator &other);
        
        tree_iterator(iterator_type ptr);

        iterator_type           base() const;
        
        data_value_type_ref            operator*() const;
        tree_iterator&       operator++();
        tree_iterator        operator++(int);
        tree_iterator&       operator--();
        tree_iterator        operator--(int);
        
        tree_iterator        operator+(difference_type) const;
        tree_iterator        operator-(difference_type) const;
        
        template <class it>
        tree_iterator&       operator=(const it&)  ;
    
        data_value_type_ptr                 operator->();
        const_data_value_type_ptr           operator->() const;

        iterator_type       find_last_node(iterator_type _node) ;
        iterator_type       find_first_node(iterator_type _node) ;
    private:
        iterator_type   __node;
        iterator_type   __first_node;
        iterator_type   __last_node;
    };




template<class T>
tree_iterator<T>::tree_iterator():__node(0)
{
    
}

template<class T>
tree_iterator<T>::tree_iterator(const tree_iterator &other):__node ( other.base())
{
    __last_node = other.find_last_node(__node);
    __first_node = other.find_first_node(__node);
}


// template<class T>
// tree_iterator<T>::tree_iterator(const ft::const_tree_iterator<T> &other):__node ( other.base())
// {
     
// }


template<class T>
tree_iterator<T>::tree_iterator(iterator_type ptr)
{
    this->__node = ptr;
    if (__node)
    {
        __last_node = this->find_last_node(__node);
        __first_node = this->find_first_node(__node);
    }

}



template<class T>
typename tree_iterator<T>::iterator_type tree_iterator<T>::base() const 
{
    return (this->__node);
}


template<class T>
typename tree_iterator<T>::data_value_type_ref       tree_iterator<T>::operator*() const
{
    return (__node->data);
}

template<class T>
tree_iterator<T>&       tree_iterator<T>::operator++()
{
    if (__node == __last_node)
    {
        while (__node->parent)
            __node = __node->parent;
        return (*this);
    }
    if (!__node->has_parent())
    {
        __node = __node->right;
        while (__node->left)
            __node = __node->left;
        return *this;
    }
    if (__node->right )
        __node = __node->right;
    else 
    {
        while (__node->parent->data.first < __node->data.first)
            __node = __node->parent;
        __node = __node->parent;
    }
    return (*this);
}

template<class T>
tree_iterator<T>        tree_iterator<T>::operator++(int)  
{
    tree_iterator<T> tmp (this->__node);
    operator++();
    
    return (tmp); 
}

template<class T>
tree_iterator<T>&       tree_iterator<T>::operator  --()
{
    if (__node == _end)
    {
        __node = find_last_node(__node);
        return (*this);
    }
    if (__node == __first_node)
    {
        __node = nullptr;
        return (*this);
    }
    if (!__node->left)
    {
        while (__node->parent->data.first > __node->data.first)
            __node = __node->parent;
        __node = __node->parent;
    }
    else
    {
        __node = __node->left;
        while (__node->right)
            __node = __node->right;
    }
    return (*this);
}

template<class T>
tree_iterator<T>        tree_iterator<T>::operator--(int)
{
    tree_iterator<T> tmp (this->__node);
    operator--();
    
    return (tmp);
}



template<class T>
template <class it>
tree_iterator<T>&       tree_iterator<T>::operator=(const it& other) 
{
    this->__node = other.base();
    return (*this);
}




template<class T>
typename tree_iterator<T>::data_value_type_ptr         tree_iterator<T>::operator->()
{
    return (&__node->data);
}

template<class T>
typename tree_iterator<T>::const_data_value_type_ptr   tree_iterator<T>::operator->() const 
{
    return (&__node->data);
}


//
template<class T>  
typename tree_iterator<T>::iterator_type   
tree_iterator<T>::find_last_node(iterator_type _node) 
{
    iterator_type tmp = _node;
    while (tmp && tmp->parent)
        tmp = tmp->parent;
    while (tmp && tmp->right)
        tmp = tmp->right;
    return (tmp);
}



template<class T>
typename tree_iterator<T>::iterator_type 
tree_iterator<T>::find_first_node(iterator_type _node)  
{
    iterator_type tmp = _node;
    while (tmp && tmp->parent)
        tmp = tmp->parent;
    while (tmp && _node->left)
        tmp = tmp->left;
    return (tmp);
}




//non members


template< class Iterator1, class Iterator2 >
bool operator==( const ft::tree_iterator<Iterator1>& iter1,
                 const ft::tree_iterator<Iterator2>& iter2 )
{
    return (iter1.base() == iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::tree_iterator<Iterator1>& iter1,
                 const ft::tree_iterator<Iterator2>& iter2 )
{
    return (iter1.base() != iter2.base());
}








}

#endif