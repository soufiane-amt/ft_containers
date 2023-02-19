/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/19 15:54:45 by samajat          ###   ########.fr       */
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



// template <typename T_MAP>
// void	printSize(T_MAP const &mp, bool print_content = 1)
// {
// 	std::cout << "size: " << mp.size() << std::endl;
// 	std::cout << "max_size: " << mp.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename T_MAP::const_iterator it = mp.begin();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != mp.end(); ++it)
// 			std::cout << "- " << printPair(it, false) << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }

#define NAME_SPACE ft
int main()
{
	NAME_SPACE::map <int, int> m;
	m.insert(NAME_SPACE::pair <int, int>(2, 3));
	m.insert(NAME_SPACE::pair <int, int>(3, 5));
	m.insert(NAME_SPACE::pair <int, int>(1, 4));
	
	std::cout << m.begin()->first << std::endl;
	m.erase(m.begin());
	std::cout << m.begin()->first << std::endl;

	return 0;
}