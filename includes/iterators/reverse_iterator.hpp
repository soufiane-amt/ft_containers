/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:42 by samajat           #+#    #+#             */
/*   Updated: 2023/02/25 18:50:22 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>

#include <cstddef>
#include <iterator>
#include "../dependencies/utility.hpp"
#include "../dependencies/node.hpp"
namespace ft
{

template<class iter>
class reverse_iterator

{

    public:                                       
        typedef iter                                            iterator_type;
        typedef typename iterator_traits<iter>::difference_type difference_type;
        typedef typename iterator_traits<iter>::reference       reference;
        typedef typename iterator_traits<iter>::pointer         pointer;

        reverse_iterator();
        explicit reverse_iterator(iter x );
       
        template< class U >
        reverse_iterator( const reverse_iterator<U>& other );

        iter              base() const;
        reference         operator*() const;
        pointer           operator->() const;
        reverse_iterator& operator++();
        reverse_iterator  operator++(int);
        reverse_iterator& operator--();
        reverse_iterator  operator--(int);
        reverse_iterator  operator+ (difference_type n) const;
        reverse_iterator  operator- (difference_type n) const;
        reference         operator[](difference_type n) const;
        reverse_iterator& operator+=(difference_type n);
        reverse_iterator& operator-=(difference_type n);

    private:
        iter   __iter;
    };








template<class iter>
reverse_iterator<iter>::reverse_iterator():__iter()
{
    std::cout << std::is_same< ft::Node<ft::pair<const int, int> >::data_value_type_ref  , reverse_iterator<iter>::reference>::value << std::endl; // prints "true"
    
}

template<class iter>
template< class U >
reverse_iterator<iter>::reverse_iterator( const reverse_iterator<U>& other ):__iter(other.base())
{
}

template<class iter>
reverse_iterator<iter>::reverse_iterator(iter __iter_other):__iter(__iter_other)
{
}

template<class iter>
typename reverse_iterator<iter>::iterator_type      reverse_iterator<iter>::base() const
{
    return (this->__iter);
}



template<class iter>
typename reverse_iterator<iter>::reference       reverse_iterator<iter>::operator*() const
{
    iter tmp = this->__iter;

    return (*--tmp);
}


template<class iter>
typename reverse_iterator<iter>::pointer   reverse_iterator<iter>::operator->() const
{
    iter tmp = this->__iter;
    return &(*--tmp);
}


template<class iter>
reverse_iterator<iter>&       reverse_iterator<iter>::operator++()
{
    this->__iter--;
    return (*this);
}

template<class iter>
reverse_iterator<iter>        reverse_iterator<iter>::operator++(int)
{
    reverse_iterator<iter> tmp(*this);
    this->__iter--;
    
    return (tmp);
}

template<class iter>
reverse_iterator<iter>&       reverse_iterator<iter>::operator--()
{
    this->__iter++;
    return (*this);
}

template<class iter>
reverse_iterator<iter>        reverse_iterator<iter>::operator--(int)
{
    reverse_iterator<iter> tmp (this->__iter);
    this->__iter++;
    
    return (tmp);
}


//
template<class iter>
reverse_iterator<iter> reverse_iterator<iter>::operator+(difference_type ele) const
{
    return (reverse_iterator<iter>(this->__iter - ele));
}


template<class iter>
reverse_iterator<iter> reverse_iterator<iter>::operator-(difference_type ele) const
{
    return (reverse_iterator(this->__iter + ele));
}


template<class iter>
typename reverse_iterator<iter>::reference
reverse_iterator<iter>::operator[](difference_type n) const
{
    return(base()[-n - 1]);
}

template<class iter>
reverse_iterator<iter>&        reverse_iterator<iter>::operator+= (difference_type elem)
{
    this->__iter -= elem;
    return ( *this);
}

template<class iter>
reverse_iterator<iter>&        reverse_iterator<iter>::operator-= (difference_type elem)
{
    this->__iter += elem;
    return ( *this);
}





//non members


template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& iter1,
                 const ft::reverse_iterator<Iterator2>& iter2 )
{
    return (iter1.base() == iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& iter1,
                 const ft::reverse_iterator<Iterator2>& iter2 )
{
    return (iter1.base() != iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& iter1,
                const ft::reverse_iterator<Iterator2>& iter2 )
{
    return ((iter1.base() > iter2.base()));

}

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& iter1,
                 const ft::reverse_iterator<Iterator2>& iter2 )
{
    return ((iter1.base() >= iter2.base()));
}

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& iter1,
                const ft::reverse_iterator<Iterator2>& iter2 )
{
    return ((iter1.base() < iter2.base()));
}

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& iter1,
                 const ft::reverse_iterator<Iterator2>& iter2 )
{
    return ((iter1.base() <= iter2.base()));
}




template< class Iter >
reverse_iterator<Iter>
operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
{
    return (it + n);
}

template< class iterator1, class iterator2 >
typename reverse_iterator<iterator1>::difference_type
operator-( const reverse_iterator<iterator1>& it1, const reverse_iterator<iterator2>& it2)
{
    return (it2.base() - it1.base());
}
 




}
#endif