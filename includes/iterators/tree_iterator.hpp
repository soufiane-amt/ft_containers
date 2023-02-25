/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:38:53 by samajat           #+#    #+#             */
/*   Updated: 2023/02/25 14:50:29 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../dependencies/utility.hpp"
// #include "const_tree_iterator.hpp"

namespace ft 
{

template<class _ite>
class tree_iterator
{
    public:                                       
        typedef _ite                                                       iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type        value_type;
        typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
        typedef typename iterator_traits<iterator_type>::pointer           pointer;
        typedef typename iterator_traits<iterator_type>::reference         reference;
        typedef typename value_type::data_value_type                       data_value_type;
        
        typedef data_value_type*                                           data_value_type_ptr;
        typedef data_value_type&                                           data_value_type_ref;
        
        typedef const data_value_type_ptr                                  const_data_value_type_ptr;
        typedef const reference                                            const_reference;
        typedef const pointer                                              const_pointer;
        

        private:
        
        tree_iterator(iterator_type ptr);
        
        public:
        tree_iterator();
        
        tree_iterator(const tree_iterator &other);
        
        tree_iterator&       operator=(const tree_iterator &other);

        
        iterator_type           base() const;
        
        data_value_type_ref            operator*() const;
        tree_iterator&       operator++();
        tree_iterator        operator++(int);
        tree_iterator&       operator--();
        tree_iterator        operator--(int);
        
        tree_iterator        operator+(difference_type) const;
        tree_iterator        operator-(difference_type) const;
        
        template <class it>
        tree_iterator&       operator=(const it&)  ;
    
        data_value_type_ptr                 operator->();
        const_data_value_type_ptr           operator->() const;

        template<
        class Key,
        class T,
        class Compare,
        class Allocator 
        >
        friend  class binary_tree;
    private:
        iterator_type   __node;

    };




template<class T>
tree_iterator<T>::tree_iterator():__node(0)
{
    
}

template<class T>
tree_iterator<T>::tree_iterator(const tree_iterator &other):__node ( other.base())
{
}


// template<class T>
// tree_iterator<T>::tree_iterator(const ft::const_tree_iterator<T> &other):__node ( other.base())
// {
     
// }


template<class T>
tree_iterator<T>::tree_iterator(iterator_type ptr)
{
    this->__node = ptr;
}



template<class T>
typename tree_iterator<T>::iterator_type tree_iterator<T>::base() const 
{
    return (this->__node);
}


template<class T>
typename tree_iterator<T>::data_value_type_ref       tree_iterator<T>::operator*() const
{
    return (__node->data);
}

template<class T>
tree_iterator<T>&       tree_iterator<T>::operator++()
{
    this->__node = next_node(__node);
    return (*this);
}

template<class T>
tree_iterator<T>        tree_iterator<T>::operator++(int)  
{
    tree_iterator<T> tmp (this->__node);
    operator++();
    
    return (tmp); 
}

template<class T>
tree_iterator<T>&       tree_iterator<T>::operator --()
{
    this->__node = prev_node(__node);
    return (*this);
}

template<class T>
tree_iterator<T>        tree_iterator<T>::operator--(int)
{
    tree_iterator<T> tmp (this->__node);
    operator--();
    
    return (tmp);
}



template<class T>
template <class it>
tree_iterator<T>&       tree_iterator<T>::operator=(const it& other) 
{
    this->__node = other.base();
    return (*this);
}




template<class T>
typename tree_iterator<T>::data_value_type_ptr         tree_iterator<T>::operator->()
{
    return (&__node->data);
}

template<class T>
typename tree_iterator<T>::const_data_value_type_ptr   tree_iterator<T>::operator->() const 
{
    return (&__node->data);
}





//non members


template< class Iterator1, class Iterator2 >
bool operator==( const ft::tree_iterator<Iterator1>& iter1,
                 const ft::tree_iterator<Iterator2>& iter2 )
{
    return (iter1.base() == iter2.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::tree_iterator<Iterator1>& iter1,
                 const ft::tree_iterator<Iterator2>& iter2 )
{
    return (iter1.base() != iter2.base());
}








}

#endif