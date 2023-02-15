/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friend_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:35:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/14 13:56:08 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

template <typename T>
class A 
{
    int a;
    friend class B;
};

template <typename T>
class B 
{
    public :
    void    print()
    {
        A a;
        std::cout << a.a << std::endl;
    }
};


int main ()
{
    B b;
    b.print();
}

