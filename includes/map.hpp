/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:13:44 by samajat           #+#    #+#             */
/*   Updated: 2023/02/06 16:31:52 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <utils.hpp>


namespace ft
{

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T>>
    > class map
{

    typedef     key_type	Key;
    typedef     mapped_type	T;
    typedef     value_type	pair<const key_type,mapped_type>;
    typedef     key_compare std::less<key_type>;
    //value_compare
    typedef     allocator_type allocator_type;
    typedef     reference      allocator_type::reference;
    typedef     const_reference      allocator_type::const_reference;
};
}