/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:42 by samajat           #+#    #+#             */
/*   Updated: 2023/01/29 18:47:31 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <cstddef>
namespace ft
{

template<class T>
class reverse_iterator
{

    public:                                       
        typedef T                                        value_type;
        typedef typename std::random_access_iterator_tag rreverse_iterator_category;
        typedef ptrdiff_t                                difference_type;
        typedef T*                                       pointer;
        typedef const T*                                 const_pointer;
        typedef T&                                       reference;
        typedef const T&                                 const_reference;
    
        reverse_iterator();
        reverse_iterator(const reverse_iterator &other);
        reverse_iterator(pointer ptr);
        
        
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
        bool operator== (const reverse_iterator<value_type>& iter1)   const;
        bool operator!= (const reverse_iterator<value_type>& iter1)   const;
        bool operator<  (const reverse_iterator<value_type>& iter1)   const;
        bool operator<= (const reverse_iterator<value_type>& iter1)   const;
        bool operator>  (const reverse_iterator<value_type>& iter1)   const;
        bool operator>= (const reverse_iterator<value_type>& iter1)   const;

    private:
        pointer   __value;
    };








template<class T>
reverse_iterator<T>::reverse_iterator():__value(0)
{
    
}

template<class T>
reverse_iterator<T>::reverse_iterator(const reverse_iterator &other)
{
    this->__value = other.get_pointer();
}

template<class T>
reverse_iterator<T>::reverse_iterator(pointer ptr)
{
    this->__value = ptr;
}


template<class T>
typename reverse_iterator<T>::pointer reverse_iterator<T>::get_pointer() const 
{
    return (this->__value);
}

template<class T>
typename reverse_iterator<T>::reference       reverse_iterator<T>::operator*() const
{
    return (*this->__value);
}

template<class T>
reverse_iterator<T>&       reverse_iterator<T>::operator++()
{
    this->__value--;
    return (*this);
}

template<class T>
reverse_iterator<T>        reverse_iterator<T>::operator++(int)
{
    reverse_iterator<T> tmp (this->__value);
    this->__value--;
    
    return (tmp);
}

template<class T>
reverse_iterator<T>&       reverse_iterator<T>::operator--()
{
    this->__value++;
    return (*this);
}

template<class T>
reverse_iterator<T>        reverse_iterator<T>::operator--(int)
{
    reverse_iterator<T> tmp (this->__value);
    this->__value++;
    
    return (tmp);
}

template<class T>
bool            reverse_iterator<T>::operator==(const reverse_iterator<T>& iter) const
{
    return (this->__value == &(*iter));
}

template<class T>
bool            reverse_iterator<T>::operator!=(const reverse_iterator<T>& iter) const
{
    return (this->__value != &(*iter));
}


//
template<class T>
reverse_iterator<T> reverse_iterator<T>::operator+(difference_type ele) const
{
    return (reverse_iterator<T>(this->__value + ele));
}


template<class T>
reverse_iterator<T> reverse_iterator<T>::operator-(difference_type ele) const
{
    return (reverse_iterator<T>(this->__value - ele));
}


template<class T>
typename reverse_iterator<T>::difference_type reverse_iterator<T>::operator+(const reverse_iterator<T>& iter) const
{
    return (this->__value + &(*iter));
}

template<class T>
typename reverse_iterator<T>::difference_type reverse_iterator<T>::operator-(const reverse_iterator<T>& iter) const
{
    return (this->__value - &(*iter));
}



template<class T>
reverse_iterator<T>&       reverse_iterator<T>::operator=(const reverse_iterator& other)
{
    this->__value = other.get_pointer();
    return (*this);
}



template<class T>
typename reverse_iterator<T>::reference       
reverse_iterator<T>::operator[] (size_t i)
{
    return (this->__value[i]);

}

template<class T>
typename reverse_iterator<T>::const_reference 
reverse_iterator<T>::operator[] (size_t i) const
{
    return (this->__value[i]);
}


template<class T>
typename reverse_iterator<T>::pointer         reverse_iterator<T>::operator->()
{
    return (this->__value);
}

template<class T>
typename reverse_iterator<T>::const_pointer   reverse_iterator<T>::operator->() const
{
    return (this->__value);
}



//comparison


template<class T>
bool reverse_iterator<T>::operator<  (const reverse_iterator<T>& iter1) const
{
    return (iter1.get_pointer() < this->__value);

}

template<class T>
bool reverse_iterator<T>::operator<= (const reverse_iterator<T>& iter1) const
{
    return (iter1.get_pointer() <= this->__value);
}

template<class T>
bool reverse_iterator<T>::operator>  (const reverse_iterator<T>& iter1) const
{
    return (iter1.get_pointer() > this->__value);
}

template<class T>
bool reverse_iterator<T>::operator>= (const reverse_iterator<T>& iter1) const
{
    return (iter1.get_pointer() >= this->__value);

}


//non members


template<class T>
reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type value, reverse_iterator<T> iter ) 
{
    return (iter + value);
}

template<class T>
reverse_iterator<T> operator-(typename reverse_iterator<T>::difference_type diff, reverse_iterator<T> iter) 
{
    return (iter - diff);
}






template<class T>
reverse_iterator<T>        reverse_iterator<T>::operator+= (difference_type elem)
{
    return (reverse_iterator<T> (this->__value - elem));

}

template<class T>
reverse_iterator<T>        reverse_iterator<T>::operator-= (difference_type elem)
{
    return (reverse_iterator<T> (this->__value + elem));
}


}
#endif