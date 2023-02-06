/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:05:29 by samajat           #+#    #+#             */
/*   Updated: 2023/02/06 14:57:00 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <cstring>
#include "iterators/iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include "utils.hpp"



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
            typedef value_type const *                        const_pointer;
            typedef size_t                                   size_type;   
            typedef typename allocator_type::difference_type difference_type;

        /*Iterators*/
        typedef typename              ft::iterator<pointer>                iterator;
        typedef typename              ft::iterator<const_pointer>          const_iterator;
        
        /*reverse_iterator*/
        typedef typename              ft::reverse_iterator<iterator >            reverse_iterator;
        typedef typename              ft::reverse_iterator<const_iterator >      const_reverse_iterator;
        
        
        
        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type());
        
        template <class InputIterator>         
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type* = nullptr);
        
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
        
        //Modifiers
        void                    assign (size_type n, const_reference val);
        
        template <class InputIterator>  
        typename enable_if<!is_integral<InputIterator>::value, void>::type
        assign (InputIterator first, InputIterator last);
        
        void                    push_back (const_reference val);
        void                    pop_back();

        iterator                insert (iterator position, const_reference val);
        void                    insert (iterator position, size_type n, const_reference val);    
        
        template <class InputIterator>
        typename enable_if<!is_integral<InputIterator>::value, void>::type
         insert (iterator position, InputIterator first, InputIterator last);

        iterator                erase (iterator position);
        iterator                erase (iterator first, iterator last);
        
        void                    swap (vector& x);
 
        void                    clear();

        allocator_type          get_allocator() const;

        //iterators
        iterator                begin();
        const_iterator          begin() const;

        iterator                end();
        const_iterator          end() const;

        //reverse iterators
        reverse_iterator       rbegin();
        const_reverse_iterator rbegin() const;

        reverse_iterator       rend();
        const_reverse_iterator rend() const;

        pointer data();
        const_pointer data() const;

        
    private:
        pointer                 elements;
        size_type               _v_capacity;
        size_type               _v_size;
        allocator_type          allocator;

        //utils
        value_type              *_alloc_double_capacity(size_type    acctual_capacity);
        void                    _copy_elements  (pointer dst, pointer src, size_t n);
        pointer                 _arrayCopy(pointer    arr, size_t    size);
        void                    _insert_element (pointer dst, pointer src, size_t i, const_reference element);
        template <class InputIterator>
        size_type               distance (InputIterator first, InputIterator  last);
    };


template <class T, class Allocator  >   
typename vector <T, Allocator>::pointer vector <T, Allocator>::_arrayCopy(pointer    arr, size_t size)
{
    pointer tmp;

    tmp = allocator.allocate (size);
    for (size_t i = 0; i < size; i++)
        allocator.construct(tmp + i, arr[i]);
    return (tmp);
}






/*/////////////////////////////////////////////////////////////////*/
//                   /*constructors*/                              //
/*/////////////////////////////////////////////////////////////////*/

template <class T, class Allocator  >
vector <T, Allocator>::vector (const allocator_type& MyAllocator):_v_capacity(0), _v_size(0), allocator(MyAllocator)
{
    this->elements = NULL;
}



template <class T, class Allocator  >
vector <T, Allocator>::vector (size_type n, const_reference val,
    const allocator_type& alloc):_v_capacity(n), _v_size(n), allocator(alloc) 
{
    this->elements = allocator.allocate (n);
    for (size_t i = 0; i < n; i++)
        allocator.construct(this->elements + i, val);
}


template <class T, class Allocator >
template <class InputIterator >
vector <T, Allocator >::vector (InputIterator first, InputIterator last,
    const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value,  InputIterator>::type*): allocator(alloc) 
{
    _v_capacity = distance(first, last);
    _v_size = _v_capacity;
    this->elements = allocator.allocate(_v_size);
    for (size_t i = 0; i < _v_size; i++)
        allocator.construct(this->elements + i, *first++);
}

template <class T, class Allocator >
vector<T, Allocator>::vector (const vector& x): _v_size(x.size())
{
    _v_capacity = _v_size;
    this->elements = allocator.allocate (this->_v_size);
    for (size_t i = 0; i < this->_v_size; i++)
        allocator.construct(this->elements + i, x[i]);
}

template <class T, class Allocator >
vector<T, Allocator>:: ~vector()
{
    if (this->elements)
    {
        for (size_t i = 0; i < _v_size; i++)
            allocator.destroy(this->elements + i);
        allocator.deallocate(this->elements, _v_capacity);
    }
}


template <class T, class Allocator >
vector<T, Allocator>& vector<T, Allocator>::operator=(const vector& x)
{
    if(this == &x) return *this;
    this->_v_size = x.size();
    if (this->_v_capacity < this->_v_size)
    {
        if (this->elements)
        {
            for (size_t i = 0; i < _v_size; i++)
                allocator.destroy(this->elements + i);
            allocator.deallocate(this->elements, _v_capacity);
        }
        this->_v_capacity = this->_v_size;
        this->elements = allocator.allocate (this->_v_size);
    }
    for (size_t i = 0; i < this->_v_size; i++)
        allocator.construct(this->elements + i, x[i]);
    return (*this);
}

/*/////////////////////////////////////////////////////////////////*/
//                   /*Capacity*/                              //
/*/////////////////////////////////////////////////////////////////*/



template <class T, class Allocator >
typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const
{
    return (this->_v_size);
}

template <class T, class Allocator >
typename vector<T, Allocator>::size_type vector<T, Allocator>:: capacity() const
{
    return  (this->_v_capacity);
}

template <class T, class Allocator >
typename vector<T, Allocator>::size_type vector<T, Allocator>::  max_size() const
{
    return (allocator.max_size());
}



template <class T, class Allocator >
void vector<T, Allocator>::resize (size_type n, value_type val)
{
    pointer tmp = new value_type[_v_size];
    std::copy(this->elements, this->elements + _v_size, tmp);
    if (n > this->_v_capacity)
    {
        if (this->elements)
        {
            for (size_t i = 0; i < _v_size; i++)
                allocator.destroy(this->elements + i);
            allocator.deallocate(this->elements, _v_capacity);
        }
        this->elements = this->allocator.allocate(n);
        this->_v_capacity = n;
    }
    if (n < this->_v_size)
        for (size_t i = n; i < this->_v_size; i++)
            allocator.destroy(this->elements + i);
    else if (n > this->_v_size)
        for (size_t i = this->_v_size; i < n; i++)
            allocator.construct(this->elements + i, val);
    for (size_t i = 0; i < this->_v_size; i++)
        allocator.construct(this->elements + i, tmp[i]);
    this->_v_size = n;
}


template <class T, class Allocator >
bool vector<T, Allocator>::empty() const
{
    return (_v_size == 0);
}

/*If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).

In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.

This function has no effect on the vector size and cannot alter its elements.
*/

template <class T, class Allocator >
void      vector<T, Allocator>::reserve (size_type n)
{
    pointer              temp;

    if (n <= _v_capacity)  return;;
    temp = _arrayCopy(this->elements, this->_v_size);
    for (size_t i = 0; i < this->_v_size; i++)        
        allocator.destroy(this->elements + i);
    allocator.deallocate(this->elements, _v_capacity);
    this->elements = allocator.allocate(n);
    for (size_t i = 0; i < this->_v_size; i++)
        allocator.construct(this->elements + i, temp[i]);
    this->_v_capacity = n;
}




/*/////////////////////////////////////////////////////////////////*/
//                   /*function overloading*/                      //
/*/////////////////////////////////////////////////////////////////*/


template <class T, class Allocator >
typename vector<T, Allocator>::reference       
vector<T, Allocator>::operator[] (size_type i)
{
    if (this->_v_size <= i)
        throw std::out_of_range ("Out of range please provide a valid index!");
    return (this->elements[i]);
}

template <class T, class Allocator >
typename vector<T, Allocator>::const_reference 
vector<T, Allocator>::operator[] (size_type i) const
{
    if (this->_v_size <= i)
        throw std::out_of_range ("Out of range please provide a valid index!");
    return (this->elements[i]);
}

template <class T, class Allocator >
typename vector<T, Allocator>::reference    
vector<T, Allocator>::at (size_type n)
{
    if (this->_v_size <= n)
        throw std::out_of_range ("Out of range please provide a valid index!");
    return (this->elements[n]);
}

template <class T, class Allocator >
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::at (size_type n) const
{
    if (this->_v_size <= n)
        throw std::out_of_range ("Out of range please provide a valid index!");
    return (this->elements[n]);
}


// I don't need that these following methods need to be protected as calling them on an empty vector causes an undefined behavior
template <class T, class Allocator >
typename vector<T, Allocator>::reference    
vector<T, Allocator>::front()
{
    return (this->elements[0]);
}

template <class T, class Allocator >
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::front() const
{
    return (this->elements[0]);
}


template <class T, class Allocator >
typename vector<T, Allocator>::reference    
vector<T, Allocator>::back()
{
    return (this->elements[this->size() - 1]);
}

template <class T, class Allocator >
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::back() const
{
    return (this->elements[this->size() - 1]);
}



//Modifiers:

template <class T, class Allocator> 
void vector<T, Allocator>::assign (size_type n, const_reference val)
{
    if (n > this->_v_capacity)
    {
        for (size_t i = 0; i < _v_size; i++)        
            allocator.destroy(this->elements + i);
        allocator.deallocate(this->elements, _v_capacity);
        this->elements = allocator.allocate(n);
        this->_v_capacity = n;
    }
    else
    {
        for (size_t i = 0; i < this->_v_size; i++)        
            allocator.destroy(this->elements + i);
    }
    for (size_t i = 0; i < n; i++)
        allocator.construct(this->elements + i, val);
    this->_v_size = n;
}


template <class T, class Allocator> 
template <class InputIterator>
typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
vector<T, Allocator>::assign (InputIterator first, InputIterator last)
{
    size_t          _distance;

    _distance = distance(first, last);    
    if (_distance > this->_v_capacity)
    {
        if (this->elements)
        {
            for (size_t i = 0; i < _v_size; i++)        
                allocator.destroy(this->elements + i);
            allocator.deallocate(this->elements, _v_capacity);
        }
        this->elements = allocator.allocate(_distance);
        this->_v_capacity = _distance;
    }
    else
    {
        for (size_t i = 0; i < this->_v_size; i++)        
            allocator.destroy(this->elements + i);
    }
    for (size_t i = 0; i < _distance; i++)
        allocator.construct(this->elements + i, *first++);
    this->_v_size = _distance;
}


template <class T, class Allocator> 
void vector<T, Allocator>::push_back (const_reference val)
{
    size_t  new_element_index;

    new_element_index = this->_v_size;
    if (this->_v_capacity == _v_size)
    {
        pointer temp;
        temp = this->_alloc_double_capacity(this->_v_capacity);
        this->_copy_elements(temp, this->elements,this->_v_size);
        if (this->_v_size)
        {
            for (size_t i = 0; i < _v_size; i++)        
                allocator.destroy(this->elements + i);
            if (this->elements)
                allocator.deallocate(this->elements, _v_capacity);
        }
        this->elements = temp;
        this->_v_capacity = this->_v_capacity > 0 ? (this->_v_capacity * 2) : 1;
    }
    this->elements[new_element_index] = val;
    this->_v_size++;
}




template <class T, class Allocator> 
void vector<T, Allocator>::pop_back()
{
    allocator.destroy   (this->elements + _v_size - 1);
    this->_v_size--;
}



    // size_type  index = distance (position ,  begin());

    // this->push_back(val);
    // for (iterator it = end() ; it > position ; --it)
    //     *it = *(it - 1);
    // if (this->_v_size)
    // {
    //     allocator.destroy(this->elements + index);
    //     allocator.construct(this->elements + index, val);
    // }    
template <class T, class Allocator> 
typename vector<T, Allocator>::iterator    
vector<T, Allocator>::insert (iterator position, const_reference val)
{
    pointer new_elements = this->elements;
    iterator    _begin = begin();
    iterator    _end = end() ;
    iterator    _dup_position = position;
    size_t       pos_index = 0;

    ++_v_size;
    if (_v_size > _v_capacity)
    {
        new_elements = this->allocator.allocate(_v_size);
        for (size_t i = 0; _begin != _dup_position; _begin++)
        {
            allocator.construct(new_elements + (i++), *_begin);
            pos_index = i;
        }
        allocator.construct(new_elements + pos_index, val);
        for (size_t i = pos_index + 1 ; _dup_position != _end; _dup_position++)
            allocator.construct(new_elements + (i++), *_dup_position);
    }
    else
    {
        for ( pos_index++; _end != _dup_position ; _end--)
        {
            allocator.destroy(_end.base());
            allocator.construct(_end.base(), *(_end.base() - 1));
        }
        allocator.destroy(position.base());
        *position = val;
    }
    _v_capacity = _v_size;
    this->elements = new_elements;
    return (this->elements + pos_index);
}


template <class T, class Allocator> 
void                    vector<T, Allocator>::insert (iterator position, size_type n, const_reference val)
{
    pointer new_elements = this->elements;
    iterator    _begin = begin();
    iterator    _end = end() ;
    iterator    _dup_position = position;
    size_t       pos_index = 0;

    _v_size += n;
    if (_v_size > _v_capacity)
    {

        new_elements = this->allocator.allocate(_v_size);
        for (size_t i = 0; _begin != _dup_position; _begin++)
        {
            allocator.construct(new_elements + (i++), *_begin);
            pos_index = i;
        }
        n += pos_index;
        while( pos_index <  n)
            allocator.construct(new_elements + (pos_index++), val);
        for (size_t i = pos_index ; _dup_position != _end; _dup_position++)
        {
            allocator.construct(new_elements + (i++), *_dup_position);
        }
    }
    else
    {
        for ( ; _end != _dup_position ; _end--)
        {
            allocator.destroy(_end.base());
            allocator.construct(_end.base(), *(_end.base() - 1));
        }
        for (size_t i = 0; i < n; i++)
        {
            allocator.destroy(position.base() + i);
            position[i] = val;
        }
        
    }
    _v_capacity = _v_size;
    this->elements = new_elements;
}   


 template <class T, class Allocator> 

template <class InputIterator>
typename enable_if<!is_integral<InputIterator>::value, void>::type
vector<T, Allocator>::insert (iterator position, InputIterator first, InputIterator last)
{
    InputIterator lastTmp = last - 1;
    size_t pos = position - begin();
    while (first != last)
    {
        insert(elements + pos, *lastTmp);
        lastTmp--;
        first++;
    }
}



// template <class T, class Allocator>
// typename vector<T, Allocator>::iterator    
// vector<T, Allocator>::erase (iterator position)
// {
//     for (iterator it = end() - 1; it > position; --it)
//     {
//         // allocator.destroy(&(*it));
//         allocator.construct(&(*it), *(it - 1));
//     }
//     allocator.destroy(this->elements + _v_size - 1);
//     _v_size--;
//     return (this->elements);
// }
template <class T, class Allocator>
typename vector<T, Allocator>::iterator    
vector<T, Allocator>::erase (iterator position)
{
    for (iterator it = position; it < end() - 1; it++)
        *it = *(it + 1);
    allocator.destroy(this->elements + _v_size - 1);
    _v_size--;
    return (this->elements);
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator    
vector<T, Allocator>::erase (iterator first, iterator last)
{
    size_t  range = distance(first, last);
    while (first != end())
    {
        *first = *(first + range);
        first++;
    }
    for (size_t i = _v_size - 1; i >= range; i--)
        allocator.destroy(this->elements + i);
    return (this->elements);
}


//*-*//






template <class T, class Allocator> 
void vector<T, Allocator>::clear()
{
    for (size_t i = 0; i < _v_size; i++)
        allocator.destroy(this->elements + i);
    this->_v_size = 0;       
}



template <class T, class Allocator> 
typename vector<T, Allocator>::allocator_type 
vector<T, Allocator>::get_allocator() const
{
    return (this->allocator);
}





/*/////////////////////////////////////////////////////////////////*/
//                   /*Non-member function overloads*/             //
/*/////////////////////////////////////////////////////////////////*/

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
{
    return (v1.size() == v2.size() && equal(v1.begin(), v1.end(), v2.begin()));
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
{
    return !(v1 == v2);
}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
{
    return (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
}

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
{
    return !(v2 < v1);
}

template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
{
    return (v2 < v1);
}

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
{
    return !(v1 < v2);
}


/////-----
// template <class T, class Alloc>
// bool operator== (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
// {
//     if (v1.size() != v2.size())
//         return (false);
//     return (equal(v1.begin(), v1.end(), v2.begin()));
// }

// template <class T, class Alloc>
// bool operator!= (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
// {
//     if (v1.size() != v2.size())
//         return (true);
//     return (!equal(v1.begin(), v1.end(), v2.begin()));
// }

// template <class T, class Alloc>
// bool operator<  (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
// {
//     // typedef typename ft::vector<T,Alloc>::const_iterator              const_iterator;
    
//     // const_iterator   first1 = v1.begin();
//     // const_iterator   first2 = v2.begin();
//     // const_iterator   last1  = v1.end();

//     // while (first1!=last1)
//     // {
//     //     if (*first1 < *first2)
//     //         return true;
//     //     ++first1;
//     //     ++first2;
//     // }
//     // return false;
//     return !(v1>v2);
// }

// template <class T, class Alloc>
// bool operator<= (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
// {
//     // typedef typename ft::vector<T,Alloc>::const_iterator              const_iterator;

//     // const_iterator   first1 = v1.begin();
//     // const_iterator   first2 = v2.begin();
//     // const_iterator   last1  = v1.end();

//     // while (first1!=last1)
//     // {
//     //     if (*first1 > *first2)
//     //         return false;
//     //     ++first1;
//     //     ++first2;
//     // }
//     // return true;
//     return !(v1 > v2);
// }

// template <class T, class Alloc>
// bool operator>  (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
// {
//     typedef typename ft::vector<T,Alloc>::const_iterator              const_iterator;

//     const_iterator   first1 = v1.begin();
//     const_iterator   first2 = v2.begin();
//     const_iterator   last1  = v1.end();
//     const_iterator   last2  = v1.end();

//     // while (first1!=last1)
//     // {
//     //     if (*first1 > *first2)
//     //         return true;
//     //     ++first1;
//     //     ++first2;
//     // }
//     // return false;
//     return (lexicographical_compare(first1, first2, last1, last2));
// }

// template <class T, class Alloc>
// bool operator>= (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
// {
//     // typedef typename ft::vector<T,Alloc>::const_iterator              const_iterator;

//     // const_iterator   first1 = v1.begin();
//     // const_iterator   first2 = v2.begin();
//     // const_iterator   last1  = v1.end();

//     // while (first1!=last1)
//     // {
//     //     if (*first1 < *first2)
//     //         return false;
//     //     ++first1;
//     //     ++first2;
//     // }
//     // return true;
//     return !(v1 < v2);
// }

template <class T, class Allocator> 
void vector<T, Allocator>::swap (vector& x)
{
    std::swap(this->elements, x.elements);
    std::swap(this->_v_capacity, x._v_capacity);
    std::swap(this->_v_size, x._v_size);
    std::swap(this->allocator, x.allocator);
}


        //*swap*//
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
    vector<T,Alloc> tmp (x);

    x = y;
    y = tmp;
}




template <class InputIterator1, class InputIterator2>  
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    while (first1!=last1)
    {
        if (*first1 != *first2)
            return false;
        ++first1;
        ++first2;
    }
    return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>  
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
    while (pred(first1, last1))
    {
        if (*first1 != *first2)
            return false;
        ++first1;
        ++first2;
    }
    return true;
}


template <class InputIterator1, class InputIterator2>  
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
    while (first1!=last1)
    {
      if (first2==last2 || *first2<*first1) return false;
      else if (*first1<*first2) return true;
      ++first1; ++first2;
    }
    return (first2!=last2);
}

template <class InputIterator1, class InputIterator2, class Compare>  
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
    while (first1!=last1)
    {
      if (first2==last2 || comp (*first2, *first1))
        return false;
      else if (comp (*first1, *first2))
        return true;
      ++first1; ++first2;
    }
    return (first2!=last2);
}



/*/////////////////////////////////////////////////////////////////*/
//                   /*iteraors*/                                  //
/*/////////////////////////////////////////////////////////////////*/


template <class T, class Allocator> 
typename vector<T, Allocator>::iterator       vector<T, Allocator>::begin()
{
    return (vector<T, Allocator>::iterator(this->elements));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const
{
    return (vector<T, Allocator>::iterator(this->elements));
}

template <class T, class Allocator> 
typename vector<T, Allocator>::iterator       vector<T, Allocator>::end()
{
    return (vector<T, Allocator>::iterator(this->elements + _v_size));
}

template <class T, class Allocator> 
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const
{
    return (vector<T, Allocator>::iterator(this->elements + _v_size));
}




/*/////////////////////////////////////////////////////////////////*/
//                   /*reverse iteraors*/                                  //
/*/////////////////////////////////////////////////////////////////*/
template <class T, class Allocator> 
typename vector<T, Allocator>::reverse_iterator       
vector<T, Allocator>::rbegin()
{
    return (reverse_iterator(end()));
}

template <class T, class Allocator> 
typename vector<T, Allocator>::const_reverse_iterator 
vector<T, Allocator>::rbegin() const
{
    return (const_reverse_iterator(end()));
}

template <class T, class Allocator> 
typename vector<T, Allocator>::reverse_iterator       
vector<T, Allocator>::rend()
{
    return (reverse_iterator(begin()));
}

template <class T, class Allocator> 
typename vector<T, Allocator>::const_reverse_iterator 
vector<T, Allocator>::rend() const
{
    return (const_reverse_iterator(begin()));
}


template <class T, class Allocator> 
typename vector<T, Allocator>::pointer vector<T, Allocator>::data()
{
    return (this->elements);
}

template <class T, class Allocator> 
typename vector<T, Allocator>::const_pointer vector<T, Allocator>::data() const
{
    return (this->element);
}



/*/////////////////////////////////////////////////////////////////*/
//                   /*utils*/                                   //
/*/////////////////////////////////////////////////////////////////*/

template <class T, class Allocator> 
typename vector<T, Allocator>::value_type  
*vector<T, Allocator>::_alloc_double_capacity(size_type    acctual_capacity)
{
    if (acctual_capacity > 0 ) 
        return (allocator.allocate(acctual_capacity * 2));
    return (allocator.allocate(1));
}

template <class T, class Allocator> 
void vector<T, Allocator>::_copy_elements  (value_type* dst, value_type* src, size_t    n)
{
    for (size_t i = 0; i < n; i++)
        allocator.construct(dst + i, src [i] );
}

template <class T, class Allocator> 
template <class InputIterator>
typename vector<T, Allocator>::size_type               
vector<T, Allocator>::distance (InputIterator first, InputIterator  last)
{
    size_type distance = 0;

    while (first != last)
    {
        distance++;
        first++;
    }
    return (distance);
}


// template <class T, class Allocator> 
// void vector<T, Allocator>::_insert_element (pointer dst, pointer src, size_t    i, const_reference element)
// {
//     _copy_elements(dst, src, i);
//     this->allocator.construct(dst + i, element);
//     for (size_t index =  i + 1; index < this->_v_size + 1; index++)
//         this->allocator.construct(dst + index, element);
// }


}
#endif