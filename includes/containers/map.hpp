/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:13:44 by samajat           #+#    #+#             */
/*   Updated: 2023/02/24 15:16:53 by samajat          ###   ########.fr       */
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
    typedef     const  value_type&                  const_reference;
    typedef     const pointer                       const_pointer;
    typedef     const binary_tree*                    binary_tree_const_pointer;


    /*Iterators*/
    typedef typename              ft::tree_iterator<binary_tree_pointer>                iterator;
    // typedef typename              ft::const_tree_iterator<binary_tree_const_pointer>    const_iterator;
    
    
    
    /*reverse_iterator*/
    // typedef typename              reverse_iterator<iterator >            reverse_iterator;
    // typedef typename              reverse_iterator<const_iterator >      const_reverse_iterator;


//ft::map<char, foo<float>, std::__1::less<char>,
//      std::__1::allocator<ft::pair<const char, foo<float> > > >::const_iterator

    explicit map( const key_compare& comp =  key_compare(),
                  const allocator_type& alloc = allocator_type() );
    
    template< class InputIt >
    map( InputIt first, InputIt last,
         const key_compare& comp = key_compare(),
         const allocator_type& alloc = allocator_type() );
    
    map( const map& other );

    map&                                operator=( const map& other );

    //Capacity
    size_type                           size() const{   return (_tree.size());}
    size_type                           max_size() const{   return (_allocat.max_size());}
    bool                                empty() const{  return (!size());}

    //Element access:                   
    mapped_type&                        operator[] (const key_type& k);

        //Modifiers

    pair<iterator,bool>                  insert (const value_type& val){    return (_tree->insert(val));}

    iterator                            insert (iterator position, const_reference val){ }
    
    template <class InputIterator> 
    void                                insert (InputIterator first, InputIterator last);
    
    iterator                            erase (iterator position);
    iterator                            erase (iterator first, iterator last);
    size_type                           erase (const key_type& k);
    
    void                                swap (map& x);
    void                                clear();

    //iterators
    iterator                            begin();
    // const_iterator                      begin() const;
    iterator                            end();
    // const_iterator                      end() const;
    
    //reverse iterators
    // reverse_iterator       rbegin();
    // const_reverse_iterator rbegin() const;
    // reverse_iterator       rend();
    // const_reverse_iterator rend() const;

    //Observers:
    key_compare                          key_comp() const;
    value_compare                        value_comp() const;
    //Operations:
    iterator                             find (const key_type& k);
    // const_iterator                       find (const key_type& k) const;
    
    size_type                            count (const key_type& k) const;
        
    iterator                             lower_bound (const key_type& k);
    // const_iterator                       lower_bound (const key_type& k) const;
        
    iterator                             upper_bound (const key_type& k);
    // const_iterator                       upper_bound (const key_type& k) const;

    // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
    pair<iterator,iterator>             equal_range (const key_type& k);

    allocator_type                      get_allocator() const;

    ~map();

    private:
    //all the member functions of the _tree have to be friends and private 
    binary_tree                 _tree;
    key_compare                 _comp;
    value_compare               _v_cmp;
    allocator_type              _allocat;
};



template< class Key, class T, class Compare , class Allocator  > 
map<Key, T, Compare, Allocator>::map(const key_compare& comp, const allocator_type& alloc)
{
    (void)comp;(void)alloc;
}


template< class Key, class T, class Compare , class Allocator  > 
template <typename InputIt>
map<Key, T, Compare, Allocator>::map( InputIt first, InputIt last,
         const key_compare& comp ,
         const allocator_type& alloc  )
{
    (void)comp;
    (void)alloc;
    while (first != last)
    insert (*first);
}

template< class Key, class T, class Compare , class Allocator  > 
map<Key, T, Compare, Allocator>::map( const map& other )
{
    // for (const_iterator it = other.begin(); it != other.end() ; it++)
    //     insert(end(), *it);
    // _allocat = other._allocat;
    // _comp = other._comp;
}


template< class Key, class T, class Compare , class Allocator  > 
map<Key, T, Compare, Allocator>::~map()
{
}


template< class Key, class T, class Compare , class Allocator  > 
map<Key, T, Compare, Allocator>&    
map<Key, T, Compare, Allocator>::operator=( const map& other )
{
    // clear();
    // for (const_iterator it = other.begin(); it != other.end() ; it++)
    //     insert(end(), *it);
    // _allocat = other._allocat;
    // _comp = other._comp;
    return (*this);
}


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::mapped_type&    
map<Key, T, Compare, Allocator>::operator[] (const key_type& k)
{
    binary_tree   *node = _tree.search_node( _tree.get_tree(), k);
    if (!node)
        insert (pair<key_type, mapped_type >(k, mapped_type()) );//this insert is wrong
    return (node->data.second);
}

// template< class Key, class T, class Compare , class Allocator  > 
// pair<typename iterator,bool> 
// map<Key, T, Compare, Allocator>::insert (const value_type& val)
// {
    
//     _tree.insert_node(_tree.__tree_root, _tree.create_node(val));
//     return (val);
// }


template< class Key, class T, class Compare , class Allocator  > 
template <class InputIterator> 
void    map<Key, T, Compare, Allocator>::insert (InputIterator first, InputIterator last)
{
    while (first != last)
    {
        _tree.insert_node(_tree.__tree_root, _tree.create_node(*first));
        first++;
    }
}


template< class Key, class T, class Compare , class Allocator  > 
void map<Key, T, Compare, Allocator>::swap (map& x)
{
    std::swap(_tree, x._tree);
    std::swap(this->_v_size, x._v_size);
    std::swap(this->allocator, x.allocator);
}

template< class Key, class T, class Compare , class Allocator  > 
void map<Key, T, Compare, Allocator>::clear()
{
    _tree.clear();
}


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::key_compare
map<Key, T, Compare, Allocator>::key_comp() const
{
    return (_comp);
}


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::value_compare
map<Key, T, Compare, Allocator>::value_comp() const
{
    return (_v_cmp);
}
template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::iterator  
map<Key, T, Compare, Allocator>::erase (iterator position)
{
    iterator    next_2_pos = position;
    iterator    next_2_posl = ++position;
    
    _tree.delete_random_node(next_2_pos);

    return (next_2_posl);
}


// template< class Key, class T, class Compare , class Allocator  > 
// typename map<Key, T, Compare, Allocator>::iterator                            
// map<Key, T, Compare, Allocator>::find (const key_type& k)
// {
    
// }

// template< class Key, class T, class Compare , class Allocator  > 
// typename map<Key, T, Compare, Allocator>::const_iterator                     
// map<Key, T, Compare, Allocator>::find (const key_type& k) const
// {
    
// }

template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::size_type 
map<Key, T, Compare, Allocator>::count (const key_type& k) const
{
    return (_tree.search(_tree.get_tree(), k) != nullptr);
}

template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::iterator 
map<Key, T, Compare, Allocator>::begin ()
{
    return (iterator(_tree.begin()));
}


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::iterator 
map<Key, T, Compare, Allocator>::end ()
{
    return (iterator(_tree.end()));
}



template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::const_iterator 
map<Key, T, Compare, Allocator>::begin () const
{
    
    return (const_iterator(_tree.begin()));
}


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::const_iterator 
map<Key, T, Compare, Allocator>::end ()const
{
    return (const_iterator(_tree.end()));
}



// iterator                            lower_bound (const key_type& k);
// const_iterator                      lower_bound (const key_type& k) const;


template< class Key, class T, class Compare , class Allocator  > 
typename map<Key, T, Compare, Allocator>::allocator_type 
map<Key, T, Compare, Allocator>::get_allocator() const
{
    return (_allocat);
}

}