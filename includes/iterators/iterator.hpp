/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:26:42 by samajat           #+#    #+#             */
/*   Updated: 2023/01/17 18:03:08 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

namespace ft {

// class vector;
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

 
template<class T>
class iterator
{

    public:
        typedef T                                                          value_type;
        typedef typename iterator_traits<value_type>::iterator_category iterator_category;
        typedef typename iterator_traits<value_type>::difference_type   difference_type;
        typedef typename iterator_traits<value_type>::pointer           pointer;
        typedef typename iterator_traits<value_type>::reference         reference;
    
        iterator();
        iterator(const ft::vector<int>::iterator &other);
        iterator(value_type *ptr);
        
        
        reference       operator*() const;
        iterator&       operator++();
        iterator        operator++(int);
        iterator&       operator--();
        iterator        operator--(int);
        bool            operator==(const iterator&) const;
        bool            operator!=(const iterator&) const;
        iterator        operator+(difference_type) const;
        iterator        operator-(difference_type) const;
        difference_type operator-(const iterator&) const;
    private:
        pointer   __value;

};











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

template<class T>
iterator<T>        iterator<T>::operator+(difference_type add) const
{
    return (iterator<T> (this->__value + diff));
}

template<class T>
iterator<T>        iterator<T>::operator-(difference_type diff) const
{
    return (iterator<T> (this->__value - diff));
}

template<class T>
typename iterator<T> ::difference_type iterator<T>::operator-(const iterator<T>& iter) const
{
    return (this->__value - &(*iter));
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