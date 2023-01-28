/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/01/28 18:45:19 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../includes/vector.hpp"


struct A
{
    A(int a, int b)
    {
        std::cout << "int constr is called\n";
    }
    template<class X>
    A(X a, X b)
    {
        std::cout << "templ constr is called\n";
    }

};
int main()
{
    ft::vector <int > v(13, 43);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    
}
