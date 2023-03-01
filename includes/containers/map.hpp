/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:13:44 by samajat           #+#    #+#             */
/*   Updated: 2023/03/01 19:57:30 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dependencies/utility.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../dependencies/red_black_tree.hpp"


namespace ft
{

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<pair<const Key, T> >
    > class map 
{

    public:
    
    typedef     Key                                          key_type;
    typedef     T                                            mapped_type;
    typedef 	pair<const key_type,mapped_type>             value_type;
    typedef     Compare                                      key_compare;
    typedef     Allocator                                    allocator_type;
    typedef     value_type&                                  reference;
    typedef     value_type*	                                 pointer;
    typedef     size_t                                       size_type;
    typedef     ptrdiff_t                                    difference_type;
    typedef     Node<value_type>                             Node;
    typedef     Node*                                        node_ptr;
    
    class value_compare
    {
        key_compare comp;
        public:
            value_compare(key_compare c) : comp(c) {}
        public:
            bool operator()(const value_type &a, const value_type &b) const
            {
                return comp(a.first, b.first);
            }
    };


    typedef     const value_type&                  const_reference;
    typedef     const pointer                      const_pointer;

    typedef     RedBlack_tree<key_type, mapped_type, value_compare, allocator_type>  RedBlack_tree;

    /*Iterators*/
    typedef typename              RedBlack_tree::iterator                iterator;
    typedef typename              RedBlack_tree::const_iterator         const_iterator;
    
    
    
    /*reverse_iterator*/
    typedef typename              ft::reverse_iterator<iterator >            reverse_iterator;
    typedef typename              ft::reverse_iterator<const_iterator >      const_reverse_iterator;


    private:
    
    RedBlack_tree                 __tree;

/* ************************************************************************** */
                            // Costructors :
/* ************************************************************************** */
    public:
    explicit 
    map( const key_compare& key_comp =  key_compare(),
                  const allocator_type& alloc = allocator_type() ):__tree(value_compare(key_comp), alloc){}

    template< class InputIt >
    map( InputIt first, InputIt last,
         const key_compare& key_comp = key_compare(),
         const allocator_type& alloc = allocator_type() ):__tree(key_comp, alloc){   insert (first, last);}
         
    
    map( const map& other ) :__tree(other.__tree){   }

/* ************************************************************************** */
                            // operator= :
/* ************************************************************************** */

    map&                                operator=( const map& other ){      this->__tree = other.__tree;    return (*this);}


/* ************************************************************************** */
                            // Capacity= :
/* ************************************************************************** */
    size_type                           size() const{   return (__tree.__size);}
    size_type                           max_size() const{   return (__tree.max_size());}
    bool                                empty() const{  return (__tree.size() != 0);}


/* ************************************************************************** */
                            // Element access= :
/* ************************************************************************** */

    mapped_type&                        operator[] (const key_type& k);
    mapped_type&                        at (const key_type& k);
    const mapped_type&                  at (const key_type& k) const;

/* ************************************************************************** */
                            // Modifiers= :
/* ************************************************************************** */

    pair<iterator,bool>                 insert (const value_type& val){    return (__tree.insert(val));}
    iterator                            insert (iterator position, const_reference val){    return (__tree.insert(position, val)); }
    
    template <class InputIterator> 
    void                                insert (InputIterator first, InputIterator last){   __tree.insert(first, last);}
    
    
    iterator                            erase (iterator position) { return (__tree.erase(position));}
    iterator                            erase (iterator first, iterator last){  return (__tree.erase(first,  last));    }
    size_type                           erase (const key_type& k){  return (__tree.erase(k));    }
    
    void                                swap (map& x) { __tree.swap (x);}
    void                                clear() {   __tree.clear(); }

/* ************************************************************************** */
                            // iterators= :
/* ************************************************************************** */
    iterator                            begin(){    return (__tree.begin());}
    const_iterator                      begin() const{      return (__tree.begin());};
    iterator                            end(){return (__tree.end());}
    const_iterator                      end() const{return (__tree.end());}
    
    // reverse iterators
    reverse_iterator                    rbegin(){    return (__tree.rbegin());}
    const_reverse_iterator              rbegin() const{      return (__tree.rbegin());};
    reverse_iterator                    rend(){return (__tree.rend());}
    const_reverse_iterator              rend()  const{return (__tree.rend());}

/* ************************************************************************** */
                            // Observers= :
/* ************************************************************************** */

    key_compare                          key_comp() const {    return (key_compare());}
    value_compare                        value_comp() const{        return (value_compare());};

/* ************************************************************************** */
                            // Operations= :
/* ************************************************************************** */

    iterator                             find (const key_type& k) { return (iterator (__tree.find(k)));  }
    const_iterator                       find (const key_type& k) const {   return (const_iterator (__tree.find(k)));};
    
    size_type                            count (const key_type& k) const {  return (__tree.find(k) != nullptr); }
        
    iterator                             lower_bound (const key_type& k) {  return (__tree.lower_bound (make_pair(k, mapped_type())));    }
    const_iterator                       lower_bound (const key_type& k) const{  return (__tree.lower_bound (make_pair(k, mapped_type())));    };
        
    iterator                             upper_bound (const key_type& k) {  return (__tree.upper_bound(make_pair(k, mapped_type())));}
    const_iterator                       upper_bound (const key_type& k) const{  return (__tree.upper_bound(make_pair(k, mapped_type())));}

    pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return (__tree.equal_range(k)); }
    pair<iterator,iterator>             equal_range (const key_type& k) {   return (__tree.equal_range(k)); }

    allocator_type                      get_allocator() const{      return (allocator_type());  };
    
/* ************************************************************************** */
                            // Destructor= :
/* ************************************************************************** */
    ~map(){}

};




template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::mapped_type&    
map<Key, T, Compare, Allocator>::operator[] (const key_type& k)
{
    node_ptr   node = __tree.find(k);
    if (!node)
        return (__tree.insert (value_type(k, mapped_type())).first->second);
    return (node->data.second);
}


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::mapped_type&    
map<Key, T, Compare, Allocator>::at (const key_type& k)
{
    node_ptr   node = __tree.find(k);
    if (!node)
        throw std::out_of_range ("Error: at member function is out of range!");
    return (node->data.second);
}

template< class Key, class T, class Compare , class Allocator  > 
const typename map<Key, T, Compare, Allocator>::mapped_type&    
map<Key, T, Compare, Allocator>::at (const key_type& k) const
{
    node_ptr   node = __tree.find(k);
    if (!node)
        throw std::out_of_range ("Error: at member function is out of range!");
    return (node->data.second);
}

}