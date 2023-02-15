/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/15 17:36:08 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include "../includes/map.hpp"
// #include "../includes/vector.hpp"




#define TESTED_NAMESPACE std
#define T1 char
#define T2 foo<float>
typedef TESTED_NAMESPACE::map<T1, T2> _map;
typedef _map::const_iterator const_it;

static unsigned int i = 0;

void    ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
        bool res[2];

        std::cout << "\t-- [" << ++i << "] --" << std::endl;
        res[0] = mp.key_comp()(it1->first, it2->first);
        res[1] = mp.value_comp()(*it1, *it2);
        std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
        std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

int             main(void)
{
        _map    mp;

        mp['a'] = 2.3;
        mp['b'] = 1.4;
        mp['c'] = 0.3;
        mp['d'] = 4.2;
        printSize(mp);

        for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
                for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
                        ft_comp(mp, it1, it2);

        printSize(mp);
        return (0);
}

int             main(void)
{
    TESTED_NAMESPACE::map<int, int> m;
    
    m.insert(TESTED_NAMESPACE::pair<int, int>(5, 5));
    m.insert(TESTED_NAMESPACE::pair<int, int>(1, 5));
    m.insert(TESTED_NAMESPACE::pair<int, int>(8, 5));
    m.insert(TESTED_NAMESPACE::pair<int, int>(2, 5));

    
    for (TESTED_NAMESPACE::map<int, int>::iterator i = m.begin(); i != m.end(); i++)
        std::cout << (*i).first << std::endl;
    return (0);
}