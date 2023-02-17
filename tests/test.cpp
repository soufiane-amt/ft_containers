/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/02/17 18:06:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
// #include "../includes/map.hpp"
// #include "../includes/vector.hpp"


#include <iostream>
#include <map>



template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != mp.end(); ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


int main()
{
	std::map <int, int> m;
	m.insert(std::pair<int, int>(1,4));
	m.insert(std::pair<int, int>(2,4));
	m.insert(std::pair<int, int>(4,4));
	std::map <int, int>::iterator it = m.begin();
	m.erase(++m.begin());
	for (; it !=  m.end(); it++)
	std::cout << it->first << std::endl;	
	return 0;
}