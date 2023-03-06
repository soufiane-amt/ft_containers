/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:38:53 by samajat           #+#    #+#             */
/*   Updated: 2023/03/06 22:38:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../dependencies/utility.hpp"

namespace ft 
{

template<class _ite>
class tree_iterator
{
    public:                                       
        typedef _ite                                                       iterator_type;
        typedef typename std::bidirectional_iterator_tag                   iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type        value_type;
        typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
        typedef typename value_type::data_value_type_point                 pointer;
        
        typedef typename value_type::data_value_type                       data_value_type;
        
        typedef data_value_type*                                           data_value_type_ptr;
        typedef data_value_type&                                           reference;
        
        typedef const data_value_type_ptr                                  const_data_value_type_ptr;
        

        private:
        
        tree_iterator(iterator_type ptr);
        
        public:
        tree_iterator():__node(0){}

        
        tree_iterator(const tree_iterator &other):__node ( other.__node){}
        
        
        iterator_type                  base() const    {   return (this->__node);}
        
        reference            operator*() const {    return (__node->data);}
        
        tree_iterator&                 operator++(){      this->__node = next_node(__node);   return (*this);}
        tree_iterator                  operator++(int);
                
        tree_iterator&                 operator--(){      this->__node = prev_node(__node);   return (*this);}
        tree_iterator                  operator--(int);
                
        tree_iterator                  operator+(difference_type) const;
        tree_iterator                  operator-(difference_type) const;
                    
        // template <class it>
        // tree_iterator&                 operator=(const it&)  {    this->__node = it.base(); return (*this);};
    
        data_value_type_ptr            operator->()    {    return (&__node->data);}
        const_data_value_type_ptr      operator->() const  {    return (&__node->data);}
        bool operator==(tree_iterator const & rhs) const {
            return (__node == rhs.__node);
        }
        bool operator!=(tree_iterator const & rhs) const {
            return (__node != rhs.__node);
        }


        template<
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
        
        template<
        class T,
        class Compare,
        class Allocator 
        >
        friend  class set;
    private:
        iterator_type   __node;

    };


template<class T>
tree_iterator<T>::tree_iterator(iterator_type ptr)
{
    this->__node = ptr;
}

template<class T>
tree_iterator<T>        tree_iterator<T>::operator++(int)  
{
    tree_iterator<T> tmp (this->__node);
    operator++();
    
    return (tmp); 
}

template<class T>
tree_iterator<T>        tree_iterator<T>::operator--(int)
{
    tree_iterator<T> tmp (this->__node);
    operator--();
    
    return (tmp);
}

}

#endif