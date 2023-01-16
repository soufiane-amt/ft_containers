/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:22:56 by samajat           #+#    #+#             */
/*   Updated: 2023/01/16 15:41:31 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>

int main ()
{
    int arr[] = {1 , 2, 3};
    std::vector <int> v(arr, arr + 3);
    std::vector <int>::reverse_iterator riter = v.rbegin();
    std::vector <int>::iterator iter = v.begin();
    // for (std::vector <int>::reverse_iterator iter = v.rbegin(); iter != v.rend(); iter++)
    // {
    //     std::cout << *iter.operator->() << std::endl;
    // }
    
}