/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:05:29 by samajat           #+#    #+#             */
/*   Updated: 2023/03/05 13:30:32 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <cstring>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../dependencies/utility.hpp"



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
        typedef typename              ft::random_access_iterator<pointer>                iterator;
        typedef typename              ft::random_access_iterator<const_pointer>          const_iterator;
        
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

        void    destroy_and_deallocate();
        void    destroy (iterator first, iterator last);
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
        this->_v_capacity = this->_v_capacity > 0 ? (this->_v_capacity * 2) : 1;
        this->elements = this->allocator.allocate(_v_capacity);

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
    delete []tmp;
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
    pointer              temp = new T[this->_v_size];

    // std::copy(this->elements, this->elements + _v_size, tmp);
    if (n <= _v_capacity)  return; 
    std::copy(this->elements, this->elements + _v_size, temp);
    // temp = _arrayCopy(this->elements, this->_v_size);
    for (size_t i = 0; i < this->_v_size; i++)        
        allocator.destroy(this->elements + i);
    allocator.deallocate(this->elements, _v_capacity);
    this->elements = allocator.allocate(n);
    for (size_t i = 0; i < this->_v_size; i++)
        allocator.construct(this->elements + i, temp[i]);
    this->_v_capacity = n;
    delete []temp;
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
        if (this->elements)
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
        
        for (size_t i = 0; i < _v_size; i++)        
            allocator.destroy(this->elements + i);
        if (this->elements)
            allocator.deallocate(this->elements, _v_capacity);
        this->elements = temp;

        this->_v_capacity = this->_v_capacity > 0 ? (this->_v_capacity * 2) : 1;
    }
    allocator.construct (this->elements + new_element_index, val);
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

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(iterator position, const T& val)
{
    if (_v_size == _v_capacity ) {
        size_type index = position - begin();
        std::cout << "-----\n";
        _v_capacity = _v_capacity == 0 ? 1 : _v_capacity * 2;
        pointer new_elements = allocator.allocate(_v_capacity);
        if (_v_size)
        {
            for (size_type i = 0; i < index; ++i)
                allocator.construct(new_elements + i, elements[i]);
        }
        allocator.construct(new_elements + index, val);
        position = iterator(new_elements + index);
        for (size_type i = index; i < _v_size; ++i)
            allocator.construct(new_elements + i + 1, elements[i]);
        for (size_type i = 0; i < _v_size; ++i)
            allocator.destroy(elements + i);
        if (elements)
            allocator.deallocate(elements, _v_size);
        elements = new_elements;
    } else {
        if (position == end()) {
            allocator.construct(elements + _v_size, val);
        } else {
            allocator.construct(elements + _v_size, elements[_v_size - 1]);
            for (iterator it = end() - 1; it != position; --it)
                *it = *(it - 1);
            *position = val;
        }

    }
    ++_v_size;
    return position;
}



template <typename T, typename Allocator>
void vector<T, Allocator>::insert(iterator position, size_type n, const T& val)
{
    size_type index = position - begin();
    size_type newSize = _v_size + n;

    if (newSize > _v_capacity) {
        size_type newCapacity = _v_capacity == 0 ? 1 : _v_capacity * 2;
        while (newSize > newCapacity) newCapacity *= 2;
        pointer newElements = allocator.allocate(newCapacity);
        for (size_type i = 0; i < index; ++i) {
            allocator.construct(newElements + i, elements[i]);
        }
        for (size_type i = 0; i < n; ++i) {
            allocator.construct(newElements + index + i, val);
        }
        for (size_type i = index; i < _v_size ; ++i) {
            allocator.construct(newElements + index + n + i, elements[i]);
        }
        for (size_type i = 0; i < _v_size; ++i) {
            allocator.destroy(elements + i);
        }
        if (elements) {
            allocator.deallocate(elements, _v_capacity);
        }
        elements = newElements;
        _v_capacity = newCapacity;
    } else {
        if (n > 0)
            std::copy_backward(elements + index, elements + _v_size, elements + _v_size + n);
        for (size_type i = 0; i < n; ++i) {
            allocator.construct(elements + index + i, val);
        }
    }

    _v_size = newSize;
        
}


template <typename T, typename Allocator>
void vector<T, Allocator>::destroy (iterator first, iterator last)
{
    iterator to_erase ;
    while (first != last)
    {
        to_erase = first++;
        allocator.destroy(to_erase.__value);
    }
}

template <typename T, typename Allocator>
void vector<T, Allocator>::destroy_and_deallocate() {

    if (elements)
    {
        destroy(begin(), end());
        allocator.deallocate(elements, capacity());
    }
}

template <class T, class Allocator> 
template <class InputIterator>
typename enable_if<!is_integral<InputIterator>::value, void>::type
vector<T, Allocator>::insert (iterator position, InputIterator first, InputIterator last)
{
  size_t num_elements = std::distance(first, last);
  if (size() + num_elements > capacity()) {
        size_t new_capacity = std::max(size() + num_elements, 2 * capacity());
        T* new_data = allocator.allocate(new_capacity);
        T* new_data_ptr = new_data;
        try {
            new_data_ptr = std::uninitialized_copy(begin(), position, new_data);
            new_data_ptr = std::uninitialized_copy(first, last, new_data_ptr);
            std::uninitialized_copy(position, end(), new_data_ptr);
            destroy_and_deallocate();
            this->elements = new_data;
            _v_size += num_elements;
            _v_capacity = new_capacity;
        } catch (...) {
          destroy(new_data, new_data_ptr);
          allocator.deallocate(new_data, new_capacity);
          throw;
        }
  } 
  else {
        std::move_backward(position, end(), end() + num_elements);
        std::copy(first, last, position);
        _v_size += num_elements;
  }

}



template <class T, class Allocator>
typename vector<T, Allocator>::iterator    
vector<T, Allocator>::erase (iterator position)
{
    pointer last = end().__value - 1;
    pointer pos = position.__value;
    std::move(pos + 1, last + 1, pos);
    allocator.destroy(this->elements + _v_size - 1);
    --_v_size;
    return position;
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator    
vector<T, Allocator>::erase (iterator first, iterator last)
{
    size_t  index_of_first = distance(begin(), first);
    size_t  range = distance(first, last);

    if (last == end()) {
        while (_v_size > index_of_first) 
            allocator.destroy(this->elements + --_v_size);
    } else {
        iterator dest = first;
        for (iterator src = last; src != end(); ++src, ++dest)
            *dest = std::move(*src);
        for (size_t i = _v_size - range; i < _v_size; ++i)
            allocator.destroy(this->elements + i);
        _v_size -= range;
    }
    return (this->elements + index_of_first);

}


//*-*//






template <class T, class Allocator> 
void vector<T, Allocator>::clear()
{
    for (size_t i = 0; i < _v_size; i++)
        allocator.destroy(this->elements + i);
    this->_v_size = 0;
    this->elements = nullptr;
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
    return (v1.size() == v2.size() && ft::equal(v1.begin(), v1.end(), v2.begin()));
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
{
    return !(v1 == v2);
}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& v1, const vector<T,Alloc>& v2)
{
    return (ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
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


template <class T, class Allocator> 
void vector<T, Allocator>::swap (vector& x)
{
    std::swap(this->elements, x.elements);
    std::swap(this->_v_capacity, x._v_capacity);
    std::swap(this->_v_size, x._v_size);
    std::swap(this->allocator, x.allocator);
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

    template <class T, class Allocator>
    void swap(ft::vector<T, Allocator> &_lhs, ft::vector<T, Allocator> &_rhs)
    {
       _lhs.swap(_rhs);
    }


}

namespace std
{
    template <class T, class Allocator>
    void swap(ft::vector<T, Allocator> &_lhs, ft::vector<T, Allocator> &_rhs)
    {
       ft::swap(_lhs, _rhs);
    }
}
#endif