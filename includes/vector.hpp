/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:05:29 by samajat           #+#    #+#             */
/*   Updated: 2023/01/11 17:28:30 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
/*ft::vector implementation*/

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        typedef T                                        value_type;
        typedef Allocator                                allocator_type;
        typedef value_type&                              reference;
        typedef const value_type&                        const_reference;
        typedef value_type*                              pointer;
        typedef const value_type*                        const_pointer;
        typedef size_t                                   size_type;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        /*Iterators
                        */
        
        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type& val = value_type(),  const allocator_type& alloc = allocator_type());
        // template <class InputIterator>         vector (InputIterator first, InputIterator last,                 const allocator_type& alloc = allocator_type());
        // vector (const vector& x);
    };
        
        
}



/*/////////////////////////////////////////////////////////////////
                
                    ft::vector Implementation

/////////////////////////////////////////////////////////////////*/

template <class T, class Allocator  >
ft::vector <T, Allocator>::vector (const allocator_type& alloc)
{
    
}

#endif