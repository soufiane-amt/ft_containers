/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:42 by samajat           #+#    #+#             */
/*   Updated: 2023/01/30 14:46:17 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <cstddef>
namespace ft
{

template<class iter>
class reverse_iterator 
{

    public:                                       
        typedef iter                                        iterator_type;
        typedef typename std::iterator_traits<iter>::iterator_category iterator_category;
        typedef ptrdiff_t                                difference_type;
        typedef T*                                       pointer;
        typedef const T*                                 const_pointer;
        typedef T&                                       reference;
        typedef const T&                                 const_reference;
    
        reverse_iterator();
        explicit reverse_iterator(iter x );
       
        template< class U >
        reverse_iterator( const reverse_iterator<U>& other );

        
        reference       operator*() const;
        reverse_iterator&       operator++();
        reverse_iterator        operator++(int);
        reverse_iterator&       operator--();
        reverse_iterator        operator--(int);
        
        reverse_iterator        operator+(difference_type) const;
        reverse_iterator        operator-(difference_type) const;
        
        difference_type operator+(const reverse_iterator&) const;
        difference_type operator-(const reverse_iterator&) const;
        
        reverse_iterator        operator+= (difference_type) ;
        reverse_iterator        operator-= (difference_type) ;

        reference       operator[] (size_t n);
        const_reference operator[] (size_t n) const;
        reverse_iterator&       operator=(const reverse_iterator&);
        pointer         get_pointer() const ;
    
        pointer         operator->();
        const_pointer   operator->() const;

        //comparison
        bool operator== (const reverse_iterator& iter1)   const;
        bool operator!= (const reverse_iterator& iter1)   const;
        bool operator<  (const reverse_iterator& iter1)   const;
        bool operator<= (const reverse_iterator& iter1)   const;
        bool operator>  (const reverse_iterator& iter1)   const;
        bool operator>= (const reverse_iterator& iter1)   const;

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
reverse_iterator<iter>::reverse_iterator(iter ptr):__iter(other)
{
    this->__iter = ptr;
}


template<class iter>
typename reverse_iterator<iter>::pointer reverse_iterator<iter>::get_pointer() const 
{
    return (this->__iter);
}

template<class iter>
typename reverse_iterator<iter>::reference       reverse_iterator<iter>::operator*() const
{
    return (*this->__iter);
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
    reverse_iterator<iter> tmp (this->__iter);
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

template<class iter>
bool            reverse_iterator<iter>::operator==(const reverse_iterator<iter>& iter) const
{
    return (this->__iter == &(*iter));
}

template<class iter>
bool            reverse_iterator<iter>::operator!=(const reverse_iterator<iter>& iter) const
{
    return (this->__iter != &(*iter));
}


//
template<class iter>
reverse_iterator<iter> reverse_iterator<iter>::operator+(difference_type ele) const
{
    return (reverse_iterator<iter>(this->__iter + ele));
}


template<class iter>
reverse_iterator<iter> reverse_iterator<iter>::operator-(difference_type ele) const
{
    return (reverse_iterator<iter>(this->__iter - ele));
}


template<class iter>
typename reverse_iterator<iter>::difference_type reverse_iterator<iter>::operator+(const reverse_iterator<iter>& iter) const
{
    return (this->__iter + &(*iter));
}

template<class iter>
typename reverse_iterator<iter>::difference_type reverse_iterator<iter>::operator-(const reverse_iterator<iter>& iter) const
{
    return (this->__iter - &(*iter));
}



template<class iter>
reverse_iterator<iter>&       reverse_iterator<iter>::operator=(const reverse_iterator& other)
{
    this->__iter = other.get_pointer();
    return (*this);
}



template<class iter>
typename reverse_iterator<iter>::reference       
reverse_iterator<iter>::operator[] (size_t i)
{
    return (this->__iter[i]);

}

template<class iter>
typename reverse_iterator<iter>::const_reference 
reverse_iterator<iter>::operator[] (size_t i) const
{
    return (this->__iter[i]);
}


template<class iter>
typename reverse_iterator<iter>::pointer         reverse_iterator<iter>::operator->()
{
    return (this->__iter);
}

template<class iter>
typename reverse_iterator<iter>::const_pointer   reverse_iterator<iter>::operator->() const
{
    return (this->__iter);
}



//comparison


template<class iter>
bool reverse_iterator<iter>::operator<  (const reverse_iterator<iter>& iter1) const
{
    return (iter1.get_pointer() < this->__iter);

}

template<class iter>
bool reverse_iterator<iter>::operator<= (const reverse_iterator<iter>& iter1) const
{
    return (iter1.get_pointer() <= this->__iter);
}

template<class iter>
bool reverse_iterator<iter>::operator>  (const reverse_iterator<iter>& iter1) const
{
    return (iter1.get_pointer() > this->__iter);
}

template<class iter>
bool reverse_iterator<iter>::operator>= (const reverse_iterator<iter>& iter1) const
{
    return (iter1.get_pointer() >= this->__iter);

}


//non members


template<class iter>
reverse_iterator<iter> operator+(typename reverse_iterator<iter>::difference_type value, reverse_iterator<iter> iter ) 
{
    return (iter + value);
}

template<class iter>
reverse_iterator<iter> operator-(typename reverse_iterator<iter>::difference_type diff, reverse_iterator<iter> iter) 
{
    return (iter - diff);
}






template<class iter>
reverse_iterator<iter>        reverse_iterator<iter>::operator+= (difference_type elem)
{
    return (reverse_iterator<iter> (this->__iter - elem));

}

template<class iter>
reverse_iterator<iter>        reverse_iterator<iter>::operator-= (difference_type elem)
{
    return (reverse_iterator<iter> (this->__iter + elem));
}


}
#endif