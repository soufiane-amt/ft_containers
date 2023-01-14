/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:05:29 by samajat           #+#    #+#             */
/*   Updated: 2023/01/14 18:50:09 by samajat          ###   ########.fr       */
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
        // typedef typename allocator_type::size_type       allocator_type;
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
        vector& operator= (const vector& x);
        
        //Capacity
        size_type size() const;
        size_type capacity() const;
        size_type max_size() const;
        void      resize(size_type n, value_type val = value_type());
        bool      empty() const;
        void      reserve (size_type n);
        void      shrink_to_fit();

        //Function overloading
        reference       operator[] (size_type n);
        const_reference operator[] (size_type n) const;

        //Element access:

        reference               at (size_type n);
        const_reference         at (size_type n) const;
        
        reference               front();
        const_reference         front() const;
        
        reference               back();
        const_reference         back() const;
        
        value_type*             data() noexcept;
        const value_type*       data() const noexcept;

        //Modifiers
        void assign (size_type n, const value_type& val);
       
        template <class InputIterator>  
        void assign (InputIterator first, InputIterator last);
        
        void push_back (const value_type& val);

    private:
        pointer                   elements;
        size_type                 capacity_e;
        size_type                 size_e;
        
        //utils
        value_type                *_alloc_double_capacity(size_type    acctual_capacity);
        void                      _copy_elements  (value_type* dst, value_type* src, size_t    n);
    };
        
        
}



/*/////////////////////////////////////////////////////////////////
                
                    /*ft::vector Implementation*/

/////////////////////////////////////////////////////////////////*/





/*/////////////////////////////////////////////////////////////////*/
//                   /*constructors*/                              //
/*/////////////////////////////////////////////////////////////////*/

template <class T, class Allocator  >
ft::vector <T, Allocator>::vector (const allocator_type& MyAllocator):capacity_e(0), size_t(0)
{
    this->elements = alloc.allocate(0);
}

template <class T, class Allocator  >
ft::vector <T, Allocator>::vector (size_type n, const value_type& val = value_type(),
    const allocator_type& alloc = allocator_type()):capacity_e(n), size_t(n)
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
    this->size_e = x.size();
    this->capacity_e = x.size();
    this->elements = alloc.allocate (this->size_e);
    for (size_t i = 0; i < this->size; i++)
        alloc.construct(this->elements + i, x[i]);
}

// template <class T, class Allocator >
// ~vector()
// {
//     std::allocator <T>  dealloc;

//     dealloc.destroy();
// }


template <class T, class Allocator >
ft::vector<T, Allocator>& ft::vector<T, Allocator>::operator=(const vector& x)
{
    
}

/*/////////////////////////////////////////////////////////////////*/
//                   /*Capacity*/                              //
/*/////////////////////////////////////////////////////////////////*/



template <class T, class Allocator >
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::size() const
{
    return (this->size_e);
}

template <class T, class Allocator >
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>:: capacity() const
{
    return  (this->capacity_e);
}

template <class T, class Allocator >
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::  max_size() const
{
    return (Allocator::ma);
}

// template <class T, class Allocator >
// void ft::vector<T, Allocator>::resize (size_type n, value_type val = value_type())
// {
//     vector temp     (*this);
//     std::allocator<T>  alloc;

//     this->size_e = n;
//     alloc.destroy(this->elements);
//     alloc.deallocate(this->elements, capacity_e);
//     this->elements = alloc.allocate(n);
//     for (size_t i = 0; i < this->size(); i++)
//         alloc.construct(this->elements + i, temp[i]);
//     for (size_t i = 0; i < temp.size(); i++)
//         alloc.construct(this->elements + i, val);
// }


template <class T, class Allocator >
bool ft::vector<T, Allocator>::empty() const
{
    return (size_e == 0);
}

/*If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).

In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.

This function has no effect on the vector size and cannot alter its elements.
*/

template <class T, class Allocator >
void      ft::vector<T, Allocator>::reserve (size_type n)
{
    vector              temp(*this);
    std::allocator <T>  alloc;

    n <= capacity_e ? return : NULL;
    alloc.destroy(this->elements);
    alloc.deallocate(this->elements, capacity_e);
    this->elements = alloc.allocate(n);
    for (size_t i = 0; i < temp.size(); i++)
        alloc.construct(this->elements + i, temp[i]);
}


template <class T, class Allocator >
void      ft::vector<T, Allocator>::shrink_to_fit()
{
    vector              temp(*this);
    std::allocator <T>  alloc;

    capacity_e == size_e ? return : NULL;
    alloc.destroy(this->elements);
    alloc.deallocate(this->elements, capacity_e);
    this->elements = alloc.allocate(size_e);
    for (size_t i = 0; i < temp.size(); i++)
        alloc.construct(this->elements + i, temp[i]);
}



/*/////////////////////////////////////////////////////////////////*/
//                   /*function overloading*/                      //
/*/////////////////////////////////////////////////////////////////*/


template <class T, class Allocator >
typename ft::vector<T, Allocator>::reference       
ft::vector<T, Allocator>::operator[] (size_type i)
{
    if (this->size_e <= i)
        throw std::out_of_range ();
    return (this->elements[i]);
}

template <class T, class Allocator >
typename ft::vector<T, Allocator>::const_reference 
ft::vector<T, Allocator>::operator[] (size_type i) const
{
    if (this->size_e <= i)
        throw std::out_of_range ();
    return (this->elements[i]);
}

template <class T, class Allocator >
typename ft::vector<T, Allocator>::reference    
ft::vector<T, Allocator>::at (size_type n)
{
    if (this->size_e <= i)
        throw std::out_of_range ();
    return (this->elements[i]);
}

template <class T, class Allocator >
typename ft::vector<T, Allocator>::const_reference
ft::vector<T, Allocator>::at (size_type n) const
{
    if (this->size_e <= i)
        throw std::out_of_range ();
    return (this->elements[i]);
}


// I don't need that these following methods need to be protected as calling them on an empty vector causes an undefined behavior
template <class T, class Allocator >
typename ft::vector<T, Allocator>::reference    
ft::vector<T, Allocator>::front()
{
    return (this->elements[0]);
}

template <class T, class Allocator >
typename ft::vector<T, Allocator>::const_reference
ft::vector<T, Allocator>::front() const
{
    return (this->elements[0]);
}


template <class T, class Allocator >
typename ft::vector<T, Allocator>::reference    
ft::vector<T, Allocator>::back()
{
    return (this->elements[this->size() - 1]);
}

template <class T, class Allocator >
typename ft::vector<T, Allocator>::const_reference
ft::vector<T, Allocator>::back() const
{
    return (this->elements[this->size() - 1]);
}

template <class T, class Allocator >
typename ft::vector<T, Allocator>::value_type*
ft::vector<T, Allocator>::data() noexcept
{
    return (this->elements);
}


template <class T, class Allocator >
const typename ft::vector<T, Allocator>::value_type*
ft::vector<T, Allocator>::data() const noexcept
{
    return (this->elements);
}


//Modifiers:

template <class T, class Allocator> 
void ft::vector<T, Allocator>::assign (size_type n, const value_type& val)
{
    this->size_e = n;
    if (n > this->capacity_e)
    {
        std::allocator <T>  alloc;
    
        alloc.destroy(this->elements);
        alloc.deallocate(this->elements, capacity_e);
        this->elements = alloc.allocate(n);
    }
    for (size_t i = 0; i < n; i++)
        alloc.construct(this->elements + i, val);
}


template <class T, class Allocator> 
template <class InputIterator>
void ft::vector<T, Allocator>::assign (InputIterator first, InputIterator last)
{
    
}


template <class T, class Allocator> 
void ft::vector<T, Allocator>::push_back (const value_type& val)
{
    size_t  new_element_index;

    new_element_index = this->size_e;
    if (this->capacity_e == this->size_e)
    {
        pointer temp;
        temp = this->_alloc_double_capacity(this->capacity_e);
        this->_copy_elements(temp, this->elements,this->size());
        alloc.destroy(this->elements);
        alloc.deallocate(this->elements, capacity_e);
        this->elements = temp;
        this->capacity_e *= 2;
    }
    this->elements[new_element_index] = val;
}





/*/////////////////////////////////////////////////////////////////*/
//                   /*utils*/                                   //
/*/////////////////////////////////////////////////////////////////*/

template <class T, class Allocator> 
ft::vector<T, Allocator>::value_type  
*ft::vector<T, Allocator>::_alloc_double_capacity(size_type    acctual_capacity)
{
    Allocator alloc;

    return (alloc.allocate(acctual_capacity * 2));
}

template <class T, class Allocator> 
void ft::vector<T, Allocator>::_copy_elements  (value_type* dst, value_type* src, size_t    n)
{
    for (size_t i = 0; i < n; i++)
        dst[i] = src[i];
}


#endif