/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:26:42 by samajat           #+#    #+#             */
/*   Updated: 2023/02/12 14:42:03 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../utils.hpp"

namespace ft 
{
template<class _ite>
class random_access_iterator
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

        random_access_iterator();
        
        template <class it>
        random_access_iterator(const it &other);
        
        random_access_iterator(pointer ptr);

        iterator_type      base() const;
        
        
        reference       operator*() const;
        random_access_iterator&       operator++();
        random_access_iterator        operator++(int);
        random_access_iterator&       operator--();
        random_access_iterator        operator--(int);
        
        random_access_iterator        operator+(difference_type) const;
        random_access_iterator        operator-(difference_type) const;
        
        
        random_access_iterator&        operator+= (difference_type) ;
        random_access_iterator&        operator-= (difference_type) ;

        reference       operator[] (size_t n) const;
        template <class it>
        random_access_iterator&       operator=(const it&)  ;
    
        pointer         operator->();
        const_pointer   operator->() const;

    private:
        iterator_type   __value;
    };



template<class T>
random_access_iterator<T>::random_access_iterator():__value(0)
{
    
}

template<class T>
template <class it>
random_access_iterator<T>::random_access_iterator(const it &other):__value ( other.base())
{
}

template<class T>
random_access_iterator<T>::random_access_iterator(pointer ptr)
{
    this->__value = ptr;
}



template<class T>
typename random_access_iterator<T>::iterator_type random_access_iterator<T>::base() const 
{
    return (this->__value);
}


template<class T>
typename random_access_iterator<T>::reference       random_access_iterator<T>::operator*() const
{
    return (*this->__value);
}

template<class T>
random_access_iterator<T>&       random_access_iterator<T>::operator++()
{
    this->__value++;
    return (*this);
}

template<class T>
random_access_iterator<T>        random_access_iterator<T>::operator++(int)  
{
    random_access_iterator<T> tmp (this->__value);
    this->__value++;
    
    return (tmp);
}

template<class T>
random_access_iterator<T>&       random_access_iterator<T>::operator--()
{
    this->__value--;
    return (*this);
}

template<class T>
random_access_iterator<T>        random_access_iterator<T>::operator--(int)
{
    random_access_iterator<T> tmp (this->__value);
    this->__value--;
    
    return (tmp);
}


template<class T>
random_access_iterator<T> random_access_iterator<T>::operator+(difference_type ele) const
{
    return (random_access_iterator<T>(this->__value + ele));
}


template<class T>
random_access_iterator<T> random_access_iterator<T>::operator-(difference_type ele) const
{
    return (random_access_iterator<T>(this->__value - ele));
}


template< class iterator1, class iterator2 >
typename random_access_iterator<iterator1>::difference_type
operator+( const random_access_iterator<iterator1>& it1, const random_access_iterator<iterator2>& it2)
{
    return (it2.base() - it1.base());
}

template< class iterator1, class iterator2 >
typename random_access_iterator<iterator1>::difference_type
operator-( const random_access_iterator<iterator1>& it1, const random_access_iterator<iterator2>& it2)
{
    return (it1.base() - it2.base());
}



template<class T>
template <class it>
random_access_iterator<T>&       random_access_iterator<T>::operator=(const it& other) 
{
    this->__value = other.base();
    return (*this);
}



template<class T>
typename random_access_iterator<T>::reference       
random_access_iterator<T>::operator[] (size_t i)const
{
    return (this->__value[i]);

}


template<class T>
typename random_access_iterator<T>::pointer         random_access_iterator<T>::operator->()
{
    return (this->__value);
}

template<class T>
typename random_access_iterator<T>::const_pointer   random_access_iterator<T>::operator->() const
{
    return (this->__value);
}



template<class T>
random_access_iterator<T>&        random_access_iterator<T>::operator+= (difference_type elem)
{
    this->__value += elem;
    return ( *this);

}

template<class T>
random_access_iterator<T>&        random_access_iterator<T>::operator-= (difference_type elem)
{
    this->__value -= elem;
    return ( *this);
}

//non members


template< class Iterator1, class Iterator2 >
bool operator==( const ft::random_access_iterator<Iterator1>& iter1,
                 const ft::random_access_iterator<Iterator2>& iter2 )
{
    return (iter1.base() == iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::random_access_iterator<Iterator1>& iter1,
                 const ft::random_access_iterator<Iterator2>& iter2 )
{
    return (iter1.base() != iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const ft::random_access_iterator<Iterator1>& iter1,
                const ft::random_access_iterator<Iterator2>& iter2 )
{
    return (iter1.base() < iter2.base());

}

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::random_access_iterator<Iterator1>& iter1,
                 const ft::random_access_iterator<Iterator2>& iter2 )
{
    return (iter1.base() <= iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator>( const ft::random_access_iterator<Iterator1>& iter1,
                const ft::random_access_iterator<Iterator2>& iter2 )
{
    return (iter1.base() > iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::random_access_iterator<Iterator1>& iter1,
                 const ft::random_access_iterator<Iterator2>& iter2 )
{
    return (iter1.base() >= iter2.base());

}

template<class T>
random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type value, random_access_iterator<T> iter ) 
{
    return (iter + value);
}

template<class T>
random_access_iterator<T> operator-(typename random_access_iterator<T>::difference_type diff, random_access_iterator<T> iter) 
{
    return (iter - diff);
}


}

#endif