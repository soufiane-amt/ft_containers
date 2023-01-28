/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/01/28 17:18:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <iostream>
#include <type_traits>
#include <tuple>

template<bool Condition, typename T = void>
struct enable_if
{
};
 
template<typename T>
struct enable_if<true, T>
{
    typedef T type;
};


template <typename T>
typename enable_if < std::is_integral<T>::value, T >::type sum (const T& a, const T& b)
{
    return (a + b);
}

int main()
{
    std::pair<> result ; 
    std::cout << result.first << std::endl;
    std::cout << result.second << std::endl;
}
