/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:13:44 by samajat           #+#    #+#             */
/*   Updated: 2023/02/06 16:46:43 by samajat          ###   ########.fr       */
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

    typedef     Key                                 key_type;
    typedef     T                                   mapped_type;
    typedef 	pair<const key_type,mapped_type>    value_type;
    typedef     Compare                 key_compare;
    //value_compare
    typedef     Allocator               allocator_type;
    typedef     value_type&             reference;
    typedef     const  value_type&      const_reference;
    typedef     value_type*	            pointer;
    typedef     const pointer           const_pointer;
    typedef     size_t                  size_type;
    typedef     ptrdiff_t               difference_type;


    /*Iterators*/
    typedef typename              ft::iterator<pointer>                iterator;
    typedef typename              ft::iterator<const_pointer>          const_iterator;
    
    /*reverse_iterator*/
    typedef typename              ft::reverse_iterator<iterator >            reverse_iterator;
    typedef typename              ft::reverse_iterator<const_iterator >      const_reverse_iterator;

};
}