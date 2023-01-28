/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:22:56 by samajat           #+#    #+#             */
/*   Updated: 2023/01/27 15:40:47 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>


#include <iostream>
using namespace std;
 
template<int n> struct funStruct
{
    enum { val = 2*funStruct<n-1>::val };
};
 
template<> struct funStruct<0>
{
    enum { val = 1 };
};
 
int main ()
{
    // int arr[] = {1 , 2, 3};
    // std::vector <int> v(arr, arr + 3);
    // // std::vector <int>::reverse_iterator riter = v.rbegin();
    // std::vector <int>::iterator iter = v.begin();
    // // for (std::vector <int>::reverse_iterator iter = v.rbegin(); iter != v.rend(); iter++)
    // // {
    // //     std::cout << *iter.operator->() << std::endl;
    // // }
    // std::cout << iter << std::endl;
    // std::cout << std::is_integral<int>::value << std::endl;    
    std::cout << sizeof(bool) << std::endl;
}