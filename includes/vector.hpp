/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:05:29 by samajat           #+#    #+#             */
/*   Updated: 2023/01/14 13:39:00 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>


/*/////////////////////////////////////////////////////////////////
                
                    /*ft::vector prototype*/

/////////////////////////////////////////////////////////////////*/

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
        typedef typename allocator_type::size_type       allocator_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        /*Iterators*/
        // typedef implementation-defined                   iterator;
        // typedef implementation-defined                   const_iterator;
        
        
        
        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
        template <class InputIterator>         
        vector (InputIterator first, InputIterator last,    const allocator_type& alloc = allocator_type());
        vector (const vector& x);
        ~vector();
        // vector& operator= (const vector& x);
        
        //Capacity
        size_type size() const;
    private:
        pointer                   elements;
        size_type                 capacity;
        size_type                 size;
    };
        
        
}



/*/////////////////////////////////////////////////////////////////
                
                    /*ft::vector Implementation*/

/////////////////////////////////////////////////////////////////*/





/*/////////////////////////////////////////////////////////////////*/
//                   /*constructors*/                              //
/*/////////////////////////////////////////////////////////////////*/

template <class T, class Allocator  >
ft::vector <T, Allocator>::vector (const allocator_type& MyAllocator):capacity(0), size(0)
{
    this->elements = alloc.allocate(0);
}

template <class T, class Allocator  >
ft::vector <T, Allocator>::vector (size_type n, const value_type& val = value_type(),
    const allocator_type& alloc = allocator_type()):capacity(n), size(n)
{
    this->elements = alloc.allocate (n);
    for (size_t i = 0; i < n; i++)
        alloc.construct(this->elements + i, val);
}

template <class T, class Allocator >
template <class InputIterator>
ft::vector <T, Allocator >::vector (InputIterator first, InputIterator last,
    const allocator_type& alloc = allocator_type())
{
    //push_back
}

template <class T, class Allocator >
ft::vector<T, Allocator>::vector (const vector& x)
{
    this->size = x.size;
    this->capacity = x.size;
    this->elements = alloc.allocate (this->size);
    for (this->size_t i = 0; i < this->size; i++)
        alloc.construct(this->elements + i, x[i]);
}

// template <class T, class Allocator >
// ~vector()
// {
//     const allocator_type& dealloc = allocator_type();

//     dealloc.dealloc
// }

/*/////////////////////////////////////////////////////////////////*/
//                   /*Capacity*/                              //
/*/////////////////////////////////////////////////////////////////*/

template <class T, class Allocator >
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::size() const
{
}


#endif