/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:38:53 by samajat           #+#    #+#             */
/*   Updated: 2023/02/12 15:48:36 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../utils.hpp"

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
        typedef const reference                                            const_reference;
        typedef const pointer                                              const_pointer;

        tree_iterator();
        
        template <class it>
        tree_iterator(const it &other);
        
        tree_iterator(pointer ptr);

        iterator_type           base() const;
        
        reference            operator*() const;
        tree_iterator&       operator++();
        tree_iterator        operator++(int);
        tree_iterator&       operator--();
        tree_iterator        operator--(int);
        
        tree_iterator        operator+(difference_type) const;
        tree_iterator        operator-(difference_type) const;
        
        template <class it>
        tree_iterator&       operator=(const it&)  ;
    
        pointer                 operator->();
        const_pointer           operator->() const;

    private:
        iterator_type   __node;
        iterator_type   __first_node;
        iterator_type   __last_node;

    private:
        iterator_type   find_last_node(iterator_type __node) const;
        iterator_type   find_first_node(iterator_type __node) const;
    };



template<class T>
tree_iterator<T>::tree_iterator():__node(0)
{
    
}

template<class T>
template <class it>
tree_iterator<T>::tree_iterator(const it &other):__node ( other.base())
{
    __last_node = other.find_last_node(__node);
    __first_node = other.find_first_node(__node);
}

template<class T>
tree_iterator<T>::tree_iterator(pointer ptr)
{
    this->__node = ptr;
}



template<class T>
typename tree_iterator<T>::iterator_type tree_iterator<T>::base() const 
{
    return (this->__node);
}


template<class T>
typename tree_iterator<T>::reference       tree_iterator<T>::operator*() const
{
    return (__node->data);
}

template<class T>
tree_iterator<T>&       tree_iterator<T>::operator++()
{
    if (__node == __last_node)
    {
        __node = nullptr;
        return;
    }
    if (!__node->parent)
    {
        __node = __node->right;
        while (__node->left)
            __node = __node->left;
    }
    if (__node->right )
        __node = __node->right;
    else //protect null parent
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
    if (__node == __first_node)
    {
        __node = nullptr;
        return;
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
typename tree_iterator<T>::pointer         tree_iterator<T>::operator->()
{
    return (&__node->data);
}

template<class T>
typename tree_iterator<T>::const_pointer   tree_iterator<T>::operator->() const
{
    return (&__node->data);
}


//
template<class T>
typename tree_iterator<T>::iterator_type   
tree_iterator<T>::find_last_node(iterator_type __node) const
{
    if (__node->right)
        return find_last_node(__node->right);
    return (__node);
}




template<class T>
typename tree_iterator<T>::iterator_type 
tree_iterator<T>::find_first_node(iterator_type __node) const 
{
    if (__node->left)
        return find_last_node(__node->left);
    return (__node);
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