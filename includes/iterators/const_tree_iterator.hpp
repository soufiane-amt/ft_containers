/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_const_tree_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:01:41 by samajat           #+#    #+#             */
/*   Updated: 2023/02/25 14:59:25 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CONST_const_TREE_ITERATOR_HPP
#define CONST_const_TREE_ITERATOR_HPP

#include "../dependencies/utility.hpp"

namespace ft 
{

template<class _ite>
class const_tree_iterator
{
    public:                                       
        typedef _ite                                                       iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type        value_type;
        typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
        typedef const typename value_type::const_data_value_type_point     pointer;
        typedef const typename value_type::data_value_type                       data_value_type;
        typedef  const data_value_type&                                  reference;
        
        typedef data_value_type*                                           data_value_type_ptr;
        typedef const data_value_type&                                           data_value_type_ref;
        
        typedef const data_value_type_ptr                                  const_data_value_type_ptr;
        typedef const pointer                                              const_pointer;
        typedef tree_iterator< iterator_type >                              non_const_iterator; 

        private:
        
        const_tree_iterator(iterator_type ptr);
        
        public:
        const_tree_iterator():__node(0){}

        
        const_tree_iterator(const const_tree_iterator &other):__node ( other.__node){}

        const_tree_iterator(const non_const_iterator &other):__node ( other.base()){}
        
        
        iterator_type                        base() const    {   return (this->__node);}
        
        data_value_type_ref                  operator*() const {    return (__node->data);}
        
        const_tree_iterator&                 operator++(){      this->__node = next_node(__node);   return (*this);}
        const_tree_iterator                  operator++(int);
                
        const_tree_iterator&                 operator--(){      this->__node = prev_node(__node);   return (*this);}
        const_tree_iterator                  operator--(int);
                
                    
        // template <class it>
        // const_tree_iterator&                 operator=(const it&)  {    this->__node = it.base(); return (*this);};
    
        const_data_value_type_ptr            operator->() const  {    return (&__node->data);}

        bool operator==(const_tree_iterator const & rhs) const {
            return (__node == rhs.__node);
        }
        bool operator!=(const_tree_iterator const & rhs) const {
            return (__node != rhs.__node);
        }

        template<
        class Key,
        class T,
        class Compare,
        class Allocator 
        >
        friend  class RedBlack_tree;
        
        template<
        class Key,
        class T,
        class Compare,
        class Allocator 
        >
        friend  class map;
    private:
        iterator_type   __node;

    };




template<class T>
const_tree_iterator<T>::const_tree_iterator(iterator_type ptr)
{
    this->__node = ptr;
}

template<class T>
const_tree_iterator<T>        const_tree_iterator<T>::operator++(int)  
{
    const_tree_iterator<T> tmp (this->__node);
    operator++();
    
    return (tmp); 
}

template<class T>
const_tree_iterator<T>        const_tree_iterator<T>::operator--(int)
{
    const_tree_iterator<T> tmp (this->__node);
    operator--();
    
    return (tmp);
}








}


#endif