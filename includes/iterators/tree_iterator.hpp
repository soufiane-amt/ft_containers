/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:38:53 by samajat           #+#    #+#             */
/*   Updated: 2023/02/12 11:07:09 by samajat          ###   ########.fr       */
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
        iterator_type   __value;
    };



template<class T>
tree_iterator<T>::tree_iterator():__value(0)
{
    
}

template<class T>
template <class it>
tree_iterator<T>::tree_iterator(const it &other):__value ( other.base())
{
}

template<class T>
tree_iterator<T>::tree_iterator(pointer ptr)
{
    this->__value = ptr;
}



template<class T>
typename tree_iterator<T>::iterator_type tree_iterator<T>::base() const 
{
    return (this->__value);
}


template<class T>
typename tree_iterator<T>::reference       tree_iterator<T>::operator*() const
{
    return (__value->data);
}

template<class T>
tree_iterator<T>&       tree_iterator<T>::operator++()
{
    if (!__value->parent)
    {
        __value = __value->right;
        while (__value->left)
            __value = __value->left;
    }
    if (__value->right)
        __value = __value->right;
    else //protect null parent
    {
        if (__value->parent->data.first > __value->data.first)
            __value = __value->parent;
        else
            while (__value->parent->data.first < __value->data.first)
                __value = __value->parent;
    }
    return (*this);
}

template<class T>
tree_iterator<T>        tree_iterator<T>::operator++(int)  
{
    tree_iterator<T> tmp (this->__value);
    operator++();
    
    return (tmp);
}

template<class T>
tree_iterator<T>&       tree_iterator<T>::operator--()
{
    this->__value--;
    return (*this);
}

template<class T>
tree_iterator<T>        tree_iterator<T>::operator--(int)
{
    tree_iterator<T> tmp (this->__value);
    this->__value--;
    
    return (tmp);
}



template<class T>
template <class it>
tree_iterator<T>&       tree_iterator<T>::operator=(const it& other) 
{
    this->__value = other.base();
    return (*this);
}



template<class T>
typename tree_iterator<T>::pointer         tree_iterator<T>::operator->()
{
    return (&__value->data);
}

template<class T>
typename tree_iterator<T>::const_pointer   tree_iterator<T>::operator->() const
{
    return (&__value->data);
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