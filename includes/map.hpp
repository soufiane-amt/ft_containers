/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:13:44 by samajat           #+#    #+#             */
/*   Updated: 2023/02/06 16:59:21 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <utils.hpp>


namespace ft
{

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T>>
    > class map
{

    typedef     Key                                 key_type;
    typedef     T                                   mapped_type;
    typedef 	pair<const key_type,mapped_type>    value_type;
    typedef     Compare                 key_compare;
    //value_compare
    typedef     Allocator               allocator_type;
    typedef     value_type&             reference;
    typedef     const  value_type&      const_reference;
    typedef     value_type*	            pointer;
    typedef     const pointer           const_pointer;
    typedef     size_t                  size_type;
    typedef     ptrdiff_t               difference_type;


    /*Iterators*/
    typedef typename              ft::iterator<pointer>                iterator;
    typedef typename              ft::iterator<const_pointer>          const_iterator;
    
    /*reverse_iterator*/
    typedef typename              ft::reverse_iterator<iterator >            reverse_iterator;
    typedef typename              ft::reverse_iterator<const_iterator >      const_reverse_iterator;




    map();
    
    explicit map( const key_compare& comp,
                  const allocator_type& alloc = allocator_type() );
    
    template< class InputIt >
    map( InputIt first, InputIt last,
         const key_compare& comp = key_compare(),
         const allocator_type& alloc = allocator_type() );
    
    map( const map& other );

    map& operator=( const map& other );

    //Capacity

    size_type size() const;
    size_type max_size() const;
    bool      empty() const;

    //Element access:
    mapped_type& operator[] (const key_type& k);
    mapped_type& at (const key_type& k);
    const mapped_type& at (const key_type& k) const;

        //Modifiers
    iterator                insert (iterator position, const_reference val);
    
    template <class InputIterator> 
    void insert (InputIterator first, InputIterator last);
    
    iterator                erase (iterator position);
    iterator                erase (iterator first, iterator last);
    size_type               erase (const key_type& k);
    void                    swap (map& x);
    void                    clear();

    //Observers:
    key_compare key_comp() const;
    value_compare value_comp() const;

    //Operations:
    iterator       find (const key_type& k);
    const_iterator find (const key_type& k) const;

    size_type count (const key_type& k) const;
    
    iterator lower_bound (const key_type& k);
    const_iterator lower_bound (const key_type& k) const;
    
    iterator upper_bound (const key_type& k);
    const_iterator upper_bound (const key_type& k) const;

    pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
    pair<iterator,iterator>             equal_range (const key_type& k);

    allocator_type get_allocator() const;

    ~map();

};
}