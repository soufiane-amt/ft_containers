/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:24:33 by samajat           #+#    #+#             */
/*   Updated: 2023/03/03 18:29:44 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"
#include <vector>


namespace ft
{
template <class T, class Container = ft::vector<T> > 
class stack
{
    public:
    typedef T               value_type;
    typedef Container       container_type;
    typedef size_t          size_type;

    
    explicit stack (const container_type& ctnr = container_type()) : c(ctnr){}
    
    stack& operator=( const stack& other )
    { 
        this->c = other.c;
        return (*this);
    }
    
    bool empty() const {    return (c.empty()); }

    size_type size() const{    return (c.size()); }

    value_type& top(){  return (c.back());}
    const value_type& top() const{  return (c[c.size() - 1]);}

    void push (const value_type& val)   {   c.push_back(val);}

    void pop(){ c.pop_back(); }

    ~stack(){};

    template <class t, class c>  
    friend bool operator== (const stack<t,c>& lhs, const stack<t,c>& rhs);
    
    template <class t, class c>  
    friend bool operator!= (const stack<t,c>& lhs, const stack<t,c>& rhs);
    
    template <class t, class c>  
    friend bool operator<  (const stack<t,c>& lhs, const stack<t,c>& rhs);
    
    template <class t, class c>  
    friend bool operator<= (const stack<t,c>& lhs, const stack<t,c>& rhs);
    
    template <class t, class c>  
    friend bool operator>  (const stack<t,c>& lhs, const stack<t,c>& rhs);
    
    template <class t, class c>  
    friend bool operator>= (const stack<t,c>& lhs, const stack<t,c>& rhs);


    protected:
    container_type  c;
    
};


template <class T, class Container>  
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c == rhs.c);
}

template <class T, class Container>  
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c != rhs.c);
}

template <class T, class Container>  
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c < rhs.c);
}

template <class T, class Container>  
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c <= rhs.c);
}

template <class T, class Container>  
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c > rhs.c);
}

template <class T, class Container>  
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
    return (lhs.c >= rhs.c);
}
}

#endif