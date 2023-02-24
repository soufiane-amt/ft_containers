/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:13:44 by samajat           #+#    #+#             */
/*   Updated: 2023/02/24 18:23:19 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dependencies/utility.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../dependencies/tree.hpp"


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
    friend class binary_tree<Key, T, Compare, Allocator>;
    
    typedef     Key                                          key_type;
    typedef     T                                            mapped_type;
    typedef 	pair<const key_type,mapped_type>             value_type;
    typedef     Compare                                      key_compare;
    typedef     std::less<pair<const key_type,mapped_type> > value_compare;
    typedef     Allocator                                    allocator_type;
    typedef     value_type&                                  reference;
    typedef     value_type*	                                 pointer;
    typedef     size_t                                       size_type;
    typedef     ptrdiff_t                                    difference_type;
    
    typedef     binary_tree<key_type, mapped_type, key_compare, allocator_type>  binary_tree;
    typedef     binary_tree*                          binary_tree_pointer;

    //value_compare
    typedef     const value_type&                  const_reference;
    typedef     const pointer                      const_pointer;
    typedef     const binary_tree*                 binary_tree_const_pointer;


    /*Iterators*/
    typedef typename              ft::tree_iterator<binary_tree_pointer>                iterator;
    // typedef typename              ft::const__tree_iterator<binary_tree_const_pointer>    const_iterator;
    
    
    
    /*reverse_iterator*/
    // typedef typename              reverse_iterator<iterator >            reverse_iterator;
    // typedef typename              reverse_iterator<const_iterator >      const_reverse_iterator;


/* ************************************************************************** */
                            // Costructors :
/* ************************************************************************** */

    explicit 
    map( const key_compare& key_comp =  key_compare(),
                  const allocator_type& alloc = allocator_type() ):__key_comp(key_comp), __allocator(alloc){}

    template< class InputIt >
    map( InputIt first, InputIt last,
         const key_compare& key_comp = key_compare(),
         const allocator_type& alloc = allocator_type() ):__key_comp(key_comp), __allocator(alloc){   insert (first, last);}
         
    
    map( const map& other ) :__tree(other->__tree){   insert (other.begin(), other.end());}

/* ************************************************************************** */
                            // operator= :
/* ************************************************************************** */

    map&                                operator=( const map& other ){      this->__tree = other.__tree;    return (*this);}


/* ************************************************************************** */
                            // Capacity= :
/* ************************************************************************** */
    size_type                           size() const{   return (__tree.size());}
    size_type                           max_size() const{   return (__allocator.max_size());}
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

    pair<iterator,bool>                 insert (const value_type& val){    return (__tree->insert(val));}
    iterator                            insert (iterator position, const_reference val){    return (__tree->insert(position, val)); }
    
    template <class InputIterator> 
    void                                insert (InputIterator first, InputIterator last){   __tree->insert(first, last);}
    
    
    iterator                            erase (iterator position) { return (__tree->erase(position));}
    iterator                            erase (iterator first, iterator last){  return (__tree->erase(first,  last));    }
    size_type                           erase (const key_type& k){  return (__tree->erase(k));    }
    
    void                                swap (map& x) { __tree->swap (x)}
    void                                clear() {   __tree.clear(); }

/* ************************************************************************** */
                            // iterators= :
/* ************************************************************************** */
    iterator                            begin(){    return (iterator(__tree.begin()));}
    // const_iterator                      begin() const;
    iterator                            end(){return (iterator(__tree.end()));}
    // const_iterator                      end() const;
    
    //reverse iterators
    // reverse_iterator       rbegin();
    // const_reverse_iterator rbegin() const;
    // reverse_iterator       rend();
    // const_reverse_iterator rend() const;

/* ************************************************************************** */
                            // Observers= :
/* ************************************************************************** */

    key_compare                          key__key_comp() const {    return (__key_comp);}
    value_compare                        value__key_comp() const{        return (__value_cmp);};

/* ************************************************************************** */
                            // Operations= :
/* ************************************************************************** */

    iterator                             find (const key_type& k) { return (iterator (__tree->find(k)));  }
    // const_iterator                       find (const key_type& k) const;
    
    size_type                            count (const key_type& k) const {  return (__tree->find(k) != nullptr); }
        
    iterator                             lower_bound (const key_type& k) {  return (__tree->lower_bound (k));    }
    // const_iterator                       lower_bound (const key_type& k) const;
        
    iterator                             upper_bound (const key_type& k) {  return (__tree->upper_bound(k));}
    // const_iterator                       upper_bound (const key_type& k) const;

    // pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return (__tree->equal_range(k)); }
    pair<iterator,iterator>             equal_range (const key_type& k) {   return (__tree->equal_range(k)); }

    allocator_type                      get_allocator() const{      return (__allocator);  };
    
/* ************************************************************************** */
                            // Destructor= :
/* ************************************************************************** */
    ~map();

    private:
    //all the member functions of the __tree have to be friends and private 
    
    binary_tree                 __tree;
    key_compare                 __key_comp;
    allocator_type              __allocator;
    value_compare               __value_cmp;
};



template< class Key, class T, class Compare , class Allocator  > 
map<Key, T, Compare, Allocator>::~map()
{
}


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::mapped_type&    
map<Key, T, Compare, Allocator>::operator[] (const key_type& k)
{
    binary_tree   *node = __tree.find(k);
    if (!node)
        return (__tree.insert (value_type(k, mapped_type()))->second);
    return (node->data.second);
}


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::mapped_type&    
map<Key, T, Compare, Allocator>::at (const key_type& k)
{
    binary_tree   *node = __tree.find(k);
    if (!node)
        throw std::out_of_range ("Error: at member function is out of range!");
    return (node->data.second);
}

template< class Key, class T, class Compare , class Allocator  > 
const typename map<Key, T, Compare, Allocator>::mapped_type&    
map<Key, T, Compare, Allocator>::at (const key_type& k) const
{
    binary_tree   *node = __tree.find(k);
    if (!node)
        throw std::out_of_range ("Error: at member function is out of range!");
    return (node->data.second);
}


template< class Key, class T, class Compare , class Allocator  > 
void map<Key, T, Compare, Allocator>::swap (map& x)
{
    std::swap(__tree, x.__tree);
    std::swap(this->_v_size, x._v_size);
    std::swap(this->allocator, x.allocator);
}

}