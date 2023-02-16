/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/16 15:20:40 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include "../includes/map.hpp"
// #include "../includes/vector.hpp"


#include <iostream>
#include <map>



int main()
{
    std::map <int, int> m;
    m.insert(std::pair<int, int>(1,4));
    m.insert(std::pair<int, int>(2,4));
    m.insert(std::pair<int, int>(4,4));

    std::map <int, int>::iterator iter = m.cbegin();
        // std::map <int, int>::const_iterator iter1 = m.begin();;
        return 0;
}