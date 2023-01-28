/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:26:42 by samajat           #+#    #+#             */
/*   Updated: 2023/01/28 16:42:34 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

// #include "../vector.hpp"
namespace ft {

template<class Iterator>
struct iterator_traits
{
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag iterator_category;
};

template <class T> 
struct is_integral : std::integral_constant
{
    typedef bool value_type;
    typedef type 
};

template<class T>
class iterator
{

    public:                                       
        typedef T                                        value_type;
        typedef typename std::random_access_iterator_tag iterator_category;
        typedef ptrdiff_t                                difference_type;
        typedef T*                                       pointer;
        typedef const T*                                 const_pointer;
        typedef T&                                       reference;
        typedef const T&                                 const_reference;
    
        iterator();
        iterator(const iterator &other);
        iterator(pointer ptr);
        
        
        reference       operator*() const;
        iterator&       operator++();
        iterator        operator++(int);
        iterator&       operator--();
        iterator        operator--(int);
        bool            operator==(const iterator&) const;
        bool            operator!=(const iterator&) const;
        
        iterator        operator+(difference_type) const;
        iterator        operator-(difference_type) const;
        
        difference_type operator+(const iterator&) const;
        difference_type operator-(const iterator&) const;
        
        iterator        operator+= (difference_type) ;
        iterator        operator-= (difference_type) ;

        reference       operator[] (size_t n);
        const_reference operator[] (size_t n) const;
        iterator&       operator=(const iterator&);
        pointer         get_pointer() const ;
    
        pointer         operator->();
        const_pointer   operator->() const;

        //comparison
        bool operator== (const iterator<value_type>& iter1);        
        bool operator!= (const iterator<value_type>& iter1);        
        bool operator<  (const iterator<value_type>& iter1);        
        bool operator<= (const iterator<value_type>& iter1);        
        bool operator>  (const iterator<value_type>& iter1);        
        bool operator>= (const iterator<value_type>& iter1);

    private:
        pointer   __value;
    };








template<class T>
iterator<T>::iterator():__value(0)
{
    
}

template<class T>
iterator<T>::iterator(const iterator &other)
{
    this->__value = other.get_pointer();
}

template<class T>
iterator<T>::iterator(pointer ptr)
{
    this->__value = ptr;
}


template<class T>
typename iterator<T>::pointer iterator<T>::get_pointer() const 
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

template<class T>
bool            iterator<T>::operator==(const iterator<T>& iter) const
{
    return (this->__value == &(*iter));
}

template<class T>
bool            iterator<T>::operator!=(const iterator<T>& iter) const
{
    return (this->__value != &(*iter));
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
iterator<T>&       iterator<T>::operator=(const iterator& other)
{
    this->__value = other.get_pointer();
    return (*this);
}



template<class T>
typename iterator<T>::reference       
iterator<T>::operator[] (size_t i)
{
    return (this->__value[i]);

}

template<class T>
typename iterator<T>::const_reference 
iterator<T>::operator[] (size_t i) const
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

template<class T>
bool iterator<T>::operator== (const iterator<T>& iter1)
{
    return (iter1.get_pointer() == this->__value);
}

template<class T>
bool iterator<T>::operator!= (const iterator<T>& iter1)
{
    return (iter1.get_pointer() != this->__value);

}

template<class T>
bool iterator<T>::operator<  (const iterator<T>& iter1)
{
    return (iter1.get_pointer() < this->__value);

}

template<class T>
bool iterator<T>::operator<= (const iterator<T>& iter1)
{
    return (iter1.get_pointer() <= this->__value);
}

template<class T>
bool iterator<T>::operator>  (const iterator<T>& iter1)
{
    return (iter1.get_pointer() > this->__value);
}

template<class T>
bool iterator<T>::operator>= (const iterator<T>& iter1)
{
    return (iter1.get_pointer() >= this->__value);

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