/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_it.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:03:16 by samajat           #+#    #+#             */
/*   Updated: 2023/02/06 17:19:40 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../utils.hpp"

namespace ft 
{
template<class _ite>
class bidirectional_it
{

    public:                                       
        typedef _ite                                                       iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type        value_type;
        typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
        typedef typename iterator_traits<iterator_type>::pointer           pointer;
        typedef typename iterator_traits<iterator_type>::reference         reference;
        typedef const reference         const_reference;
        typedef const pointer           const_pointer;

        bidirectional_it();
        
        template <class it>
        bidirectional_it(const it &other);
        
        bidirectional_it(pointer ptr);

        iterator_type           base() const;
        
        
        reference               operator*() const;
        bidirectional_it&       operator++();
        bidirectional_it        operator++(int);
        bidirectional_it&       operator--();
        bidirectional_it        operator--(int);
        
        bidirectional_it        operator+(difference_type) const;
        bidirectional_it        operator-(difference_type) const;
        
        template <class it>
        bidirectional_it&       operator=(const it&)  ;
    
        pointer                 operator->();
        const_pointer           operator->() const;

    private:
        iterator_type   __value;
    };



template<class T>
bidirectional_it<T>::bidirectional_it():__value(0)
{
    
}

template<class T>
template <class it>
bidirectional_it<T>::bidirectional_it(const it &other):__value ( other.base())
{
}

template<class T>
bidirectional_it<T>::bidirectional_it(pointer ptr)
{
    this->__value = ptr;
}



template<class T>
typename bidirectional_it<T>::iterator_type bidirectional_it<T>::base() const 
{
    return (this->__value);
}


template<class T>
typename bidirectional_it<T>::reference       bidirectional_it<T>::operator*() const
{
    return (*this->__value);
}

template<class T>
bidirectional_it<T>&       bidirectional_it<T>::operator++()
{
    this->__value++;
    return (*this);
}

template<class T>
bidirectional_it<T>        bidirectional_it<T>::operator++(int)  
{
    bidirectional_it<T> tmp (this->__value);
    this->__value++;
    
    return (tmp);
}

template<class T>
bidirectional_it<T>&       bidirectional_it<T>::operator--()
{
    this->__value--;
    return (*this);
}

template<class T>
bidirectional_it<T>        bidirectional_it<T>::operator--(int)
{
    bidirectional_it<T> tmp (this->__value);
    this->__value--;
    
    return (tmp);
}



template<class T>
template <class it>
bidirectional_it<T>&       bidirectional_it<T>::operator=(const it& other) 
{
    this->__value = other.base();
    return (*this);
}



template<class T>
typename bidirectional_it<T>::pointer         bidirectional_it<T>::operator->()
{
    return (this->__value);
}

template<class T>
typename bidirectional_it<T>::const_pointer   bidirectional_it<T>::operator->() const
{
    return (this->__value);
}




//non members


template< class Iterator1, class Iterator2 >
bool operator==( const ft::bidirectional_it<Iterator1>& iter1,
                 const ft::bidirectional_it<Iterator2>& iter2 )
{
    return (iter1.base() == iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::bidirectional_it<Iterator1>& iter1,
                 const ft::bidirectional_it<Iterator2>& iter2 )
{
    return (iter1.base() != iter2.base());
}


}

#endif