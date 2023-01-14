/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:22:56 by samajat           #+#    #+#             */
/*   Updated: 2023/01/14 18:03:48 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>

int main ()
{
    std::vector <int> arr(1, 1337);
    arr.assign (3, 42);
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
    std::cout << arr.capacity() << std::endl;
    std::cout << arr.size() << std::endl;
}