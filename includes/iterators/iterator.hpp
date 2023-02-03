/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:26:42 by samajat           #+#    #+#             */
/*   Updated: 2023/02/03 10:28:34 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../utils.hpp"

namespace ft 
{
template<class _ite>
class iterator
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

        iterator();
        
        template <class it>
        iterator(const it &other);
        
        iterator(pointer ptr);

        iterator_type      base() const;
        
        
        reference       operator*() const;
        iterator&       operator++();
        iterator        operator++(int);
        iterator&       operator--();
        iterator        operator--(int);
        
        iterator        operator+(difference_type) const;
        iterator        operator-(difference_type) const;
        
                                                                                                                    difference_type operator+(const iterator&) const;
        difference_type operator-(const iterator&) const;
        
        iterator        operator+= (difference_type) ;
        iterator        operator-= (difference_type) ;

        reference       operator[] (size_t n) const;
        template <class it>
        iterator&       operator=(const it&)  ;
    
        pointer         operator->();
        const_pointer   operator->() const;

        //comparison
        // bool operator== (const iterator& iter1)   const;
        // bool operator!= (const iterator& iter1)   const;
        // bool operator<  (const iterator& iter1)   const;
        // bool operator<= (const iterator& iter1)   const;
        // bool operator>  (const iterator& iter1)   const;
        // bool operator>= (const iterator& iter1)   const;

    private:
        iterator_type   __value;
    };



template<class T>
iterator<T>::iterator():__value(0)
{
    
}

template<class T>
template <class it>
iterator<T>::iterator(const it &other):__value(other.base())
{

}

template<class T>
iterator<T>::iterator(pointer ptr)
{
    this->__value = ptr;
}



template<class T>
typename iterator<T>::iterator_type iterator<T>::base() const 
{
    return (this->__value);
}


template<class T>
typename iterator<T>::reference       iterator<T>::operator*() const
{
    return (*this->__value);
}

template<class T>
iterator<T>&       iterator<T>::operator++()
{
    this->__value++;
    return (*this);
}

template<class T>
iterator<T>        iterator<T>::operator++(int)  
{
    iterator<T> tmp (this->__value);
    this->__value++;
    
    return (tmp);
}

template<class T>
iterator<T>&       iterator<T>::operator--()
{
    this->__value--;
    return (*this);
}

template<class T>
iterator<T>        iterator<T>::operator--(int)
{
    iterator<T> tmp (this->__value);
    this->__value--;
    
    return (tmp);
}


//
template<class T>
iterator<T> iterator<T>::operator+(difference_type ele) const
{
    return (iterator<T>(this->__value + ele));
}


template<class T>
iterator<T> iterator<T>::operator-(difference_type ele) const
{
    return (iterator<T>(this->__value - ele));
}


template<class T>
typename iterator<T>::difference_type iterator<T>::operator+(const iterator<T>& iter) const
{
    return (this->__value + &(*iter));
}

template<class T>
typename iterator<T>::difference_type iterator<T>::operator-(const iterator<T>& iter) const
{
    return (this->__value - &(*iter));
}



template<class T>
template <class it>
iterator<T>&       iterator<T>::operator=(const it& other) 
{
    this->__value = other.base();
    return (*this);
}



template<class T>
typename iterator<T>::reference       
iterator<T>::operator[] (size_t i)const
{
    return (this->__value[i]);

}


template<class T>
typename iterator<T>::pointer         iterator<T>::operator->()
{
    return (this->__value);
}

template<class T>
typename iterator<T>::const_pointer   iterator<T>::operator->() const
{
    return (this->__value);
}



//comparison

//non members


template< class Iterator1, class Iterator2 >
bool operator==( const ft::iterator<Iterator1>& iter1,
                 const ft::iterator<Iterator2>& iter2 )
{
    return (iter1.base() == iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::iterator<Iterator1>& iter1,
                 const ft::iterator<Iterator2>& iter2 )
{
    return (iter1.base() != iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const ft::iterator<Iterator1>& iter1,
                const ft::iterator<Iterator2>& iter2 )
{
    return (iter1.base() < iter2.base());

}

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::iterator<Iterator1>& iter1,
                 const ft::iterator<Iterator2>& iter2 )
{
    return (iter1.base() <= iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator>( const ft::iterator<Iterator1>& iter1,
                const ft::iterator<Iterator2>& iter2 )
{
    return (iter1.base() > iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::iterator<Iterator1>& iter1,
                 const ft::iterator<Iterator2>& iter2 )
{
    return (iter1.base() >= iter2.base());

}
//non members


template<class T>
iterator<T> operator+(typename iterator<T>::difference_type value, iterator<T> iter ) 
{
    return (iter + value);
}

template<class T>
iterator<T> operator-(typename iterator<T>::difference_type diff, iterator<T> iter) 
{
    return (iter - diff);
}






template<class T>
iterator<T>        iterator<T>::operator+= (difference_type elem)
{
    return (iterator<T> (this->__value + elem));

}

template<class T>
iterator<T>        iterator<T>::operator-= (difference_type elem)
{
    return (iterator<T> (this->__value - elem));
}






// template< class Iterator1, class Iterator2 >
// bool operator==( const ft::iterator<Iterator1>& iter1,
//                  const ft::iterator<Iterator2>& iter2 )
// {
//     return (iter1.base() == iter2.base());
// }

// template< class Iterator1, class Iterator2 >
// bool operator!=( const ft::iterator<Iterator1>& iter1,
//                  const ft::iterator<Iterator2>& iter2 )
// {
//     return (iter1.base() != iter2.base());
// }

// template< class Iterator1, class Iterator2 >
// bool operator<( const ft::iterator<Iterator1>& iter1,
//                 const ft::iterator<Iterator2>& iter2 )
// {
//     return (iter1.base() < iter2.base());

// }

// template< class Iterator1, class Iterator2 >
// bool operator<=( const ft::iterator<Iterator1>& iter1,
//                  const ft::iterator<Iterator2>& iter2 )
// {
//     return (iter1.base() <= iter2.base());
// }

// template< class Iterator1, class Iterator2 >
// bool operator>( const ft::iterator<Iterator1>& iter1,
//                 const ft::iterator<Iterator2>& iter2 )
// {
//     return (iter1.base() > iter2.base());
// }

// template< class Iterator1, class Iterator2 >
// bool operator>=( const ft::iterator<Iterator1>& iter1,
//                  const ft::iterator<Iterator2>& iter2 )
// {
//     return (iter1.base() >= iter2.base());
// }



// template <class Iterator>
// class reverse_iterator
//     : public iterator<typename iterator_traits<Iterator>::iterator_category,
//                       typename iterator_traits<Iterator>::value_type,
//                       typename iterator_traits<Iterator>::difference_type,
//                       typename iterator_traits<Iterator>::pointer,
//                       typename iterator_traits<Iterator>::reference>
//     {
//     protected:
//         Iterator current;
//     public:
//         typedef Iterator                                              value_type;
//         typedef typename iterator_traits<Iterator>::difference_type   difference_type;
//         typedef typename iterator_traits<Iterator>::reference         reference;
//         typedef typename iterator_traits<Iterator>::pointer           pointer;
    
//         reverse_iterator();
//         explicit reverse_iterator(iterator_type x);
        
//         template <class U> 
//         reverse_iterator(const reverse_iterator<U>& u);
        
//         template <class U> 
//         reverse_iterator& operator=(const reverse_iterator<U>& u);
        
//         Iterator base() const;
//         reference operator*() const;
//         pointer   operator->() const;
//         reverse_iterator& operator++();
//         reverse_iterator  operator++(int);
//         reverse_iterator& operator--();
//         reverse_iterator  operator--(int);
//         reverse_iterator  operator+ (difference_type n) const;
//         reverse_iterator& operator+=(difference_type n);
//         reverse_iterator  operator- (difference_type n) const;
//         reverse_iterator& operator-=(difference_type n);
//         reference         operator[](difference_type n) const;
// };




// template <class Iterator>  
// bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

// template <class Iterator>  
// bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

// template <class Iterator>  
// bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

// template <class Iterator>  
// bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

// template <class Iterator>  
// bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

// template <class Iterator>  
// bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

}

#endif