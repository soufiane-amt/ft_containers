/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:23:17 by samajat           #+#    #+#             */
/*   Updated: 2023/01/28 18:59:34 by samajat          ###   ########.fr       */
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
    
    ft::vector <int > v (13, 423);
    ft::vector <int > ::iterator iter = v.begin();
    ft::vector <int > ::iterator iter1 = v.end();
    ft::vector <int > temp (iter, iter1);
    for (size_t i = 0; i < temp.size(); i++)
    {
        std::cout << temp[i] << std::endl;
    }   
}
    
