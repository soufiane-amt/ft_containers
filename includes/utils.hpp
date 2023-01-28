/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:22:18 by samajat           #+#    #+#             */
/*   Updated: 2023/01/28 17:34:09 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {


//iterator_traits


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








//is_integral  .////Inherited from integral_constant:

template <typename T>
struct is_integral {
    static const bool value = false;
};

template <>
struct is_integral<bool> {
    static const bool value = true;
};

template <>
struct is_integral<char> {
    static const bool value = true;
};

template <>
struct is_integral<signed char> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned char> {
    static const bool value = true;
};

template <>
struct is_integral<wchar_t> {
    static const bool value = true;
};

template <>
struct is_integral<char16_t> {
    static const bool value = true;
};

template <>
struct is_integral<char32_t> {
    static const bool value = true;
};

template <>
struct is_integral<short> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned short> {
    static const bool value = true;
};

template <>
struct is_integral<int> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned int> {
    static const bool value = true;
};

template <>
struct is_integral<long> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned long> {
    static const bool value = true;
};

template <>
struct is_integral<long long> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned long long> {
    static const bool value = true;
};



//enable_if

template<bool Condition, typename T = void>
struct enable_if
{
};
 
template<typename T>
struct enable_if<true, T>
{
    typedef T type;
};








//pair


template< class T1, class T2 > 
struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;

    first_type  first;
    second_type second;

    pair();
    
    template<class U, class V>
    pair (const pair<U,V>& pr);
    
    pair (const first_type& a, const second_type& b);

    pair& operator= (const pair& pr);

};


template< class T1, class T2 > 
pair<T1, T2>::pair() : first(T1()), second(T2())
{
    
}


template< class T1, class T2 > 
template<class U, class V>
pair<T1, T2>::pair (const pair<U,V>& pr):  first(pr.first), second(pr.second)
{
    
}

template< class T1, class T2 > 
pair<T1, T2>::pair (const first_type& a, const second_type& b) : first(a), second(b)
{
    
}


template< class T1, class T2 > 
pair<T1, T2>& pair<T1, T2>::operator= (const pair& pr)
{
    this->first = pr.first;
    this->second = pr.second;
}



}
#endif