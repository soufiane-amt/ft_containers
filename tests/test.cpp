/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/21 14:23:15 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
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
#include <memory>

#define NAME_SPACE ft
int main()
{
	std::map <int , int> m;
	m.insert (std::pair <int, int> (1, 2));
	m.insert (std::pair <int, int> (2, 3));
	m.insert (std::pair <int, int> (3, 4));
	std::map <int , int>::iterator	it = m.begin();
	std::cout << it->first << std::endl;

	m.insert (std::pair <int, int> (0, 3));
	m.insert (std::pair <int, int> (-1, 4));
	std::map <int , int>::iterator	it1 = m.begin();
	std::cout << it->first << std::endl;
	std::cout << it1->first << std::endl;

	return 0;
}