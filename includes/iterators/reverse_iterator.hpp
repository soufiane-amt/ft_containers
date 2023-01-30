/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:42 by samajat           #+#    #+#             */
/*   Updated: 2023/01/30 16:44:54 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <cstddef>
#include <iterator>
#include "../utils.hpp"
namespace ft
{

template<class iter>
class reverse_iterator
    : public std::iterator<typename iterator_traits<iter>::iterator_category,
                      typename iterator_traits<iter>::value_type,
                      typename iterator_traits<iter>::difference_type,
                      typename iterator_traits<iter>::pointer,
                      typename iterator_traits<iter>::reference>

{

    public:                                       
        typedef iter                                            iterator_type;
        typedef typename iterator_traits<iter>::difference_type difference_type;
        typedef typename iterator_traits<iter>::reference       reference;
        typedef const typename iterator_traits<iter>::reference       const_reference;
        typedef typename iterator_traits<iter>::pointer         pointer;
        typedef const typename iterator_traits<iter>::pointer         const_pointer;

        reverse_iterator();
        explicit reverse_iterator(iter x );
       
        template< class U >
        reverse_iterator( const reverse_iterator<U>& other );

        iter      base() const;
        reference operator*() const;
        pointer   operator->() const;
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
reverse_iterator<iter>::reverse_iterator():__iter(0)
{
    
}

template<class iter>
template< class U >
reverse_iterator<iter>::reverse_iterator( const reverse_iterator<U>& other ):__iter(this->__iter)
{
}

template<class iter>
reverse_iterator<iter>::reverse_iterator(iter __iter_other):__iter(__iter_other)
{
}

template<class iter>
iter      reverse_iterator<iter>::base() const
{
    return (this->__iter);
}



template<class iter>
typename reverse_iterator<iter>::reference       reverse_iterator<iter>::operator*() const
{
    return (*this->__iter);
}


template<class iter>
typename reverse_iterator<iter>::pointer   reverse_iterator<iter>::operator->() const
{
    return (&(*this->__iter));
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
    iter tmp (this->__iter);
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
    return (this->__iter + ele);
}


template<class iter>
reverse_iterator<iter> reverse_iterator<iter>::operator-(difference_type ele) const
{
    return (this->__iter - ele);
}


template<class iter>
typename reverse_iterator<iter>::reference
reverse_iterator<iter>::operator[](difference_type n) const
{
    return(this->__iter[n]);
}

template<class iter>
reverse_iterator<iter>&        reverse_iterator<iter>::operator+= (difference_type elem)
{
    return ( this->__iter - elem);
}

template<class iter>
reverse_iterator<iter>&        reverse_iterator<iter>::operator-= (difference_type elem)
{
    return ( this->__iter + elem);
}





//non members


template< class Iterator1, class Iterator2 >
bool operator==( const std::reverse_iterator<Iterator1>& iter1,
                 const std::reverse_iterator<Iterator2>& iter2 )
{
    return (iter1.base() == iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const std::reverse_iterator<Iterator1>& iter1,
                 const std::reverse_iterator<Iterator2>& iter2 )
{
    return (iter1.base() == iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const std::reverse_iterator<Iterator1>& iter1,
                const std::reverse_iterator<Iterator2>& iter2 )
{
    return (iter1.base() < iter2.base());

}

template< class Iterator1, class Iterator2 >
bool operator<=( const std::reverse_iterator<Iterator1>& iter1,
                 const std::reverse_iterator<Iterator2>& iter2 )
{
    return (iter1.base() <= iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator>( const std::reverse_iterator<Iterator1>& iter1,
                const std::reverse_iterator<Iterator2>& iter2 )
{
    return (iter1.base() > iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=( const std::reverse_iterator<Iterator1>& iter1,
                 const std::reverse_iterator<Iterator2>& iter2 )
{
    return (iter1.base() >= iter2.base());
}




template< class Iter >
typename reverse_iterator<Iter>::difference_type
operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
{
    return (it.base() + n);
}

template< class Iter >
typename reverse_iterator<Iter>::difference_type
operator-( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
{
    return (it.base() - n);
}





}
#endif