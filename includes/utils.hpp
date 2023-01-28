/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:22:18 by samajat           #+#    #+#             */
/*   Updated: 2023/01/28 16:45:34 by samajat          ###   ########.fr       */
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








//is_integral

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


'




'
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

}
#endif