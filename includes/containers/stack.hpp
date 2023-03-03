/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:24:33 by samajat           #+#    #+#             */
/*   Updated: 2023/03/03 17:34:59 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include <vector>

template <class T, class Container = std::vector<T> > 
class stack
{
    typedef T               value_type;
    typedef Container       container_type;
    typedef size_t          size_type;

    public:
    explicit stack (const container_type& ctnr = container_type()) : under_container(ctnr){}
    
    bool empty() const {    return (under_container.empty()); }

    size_type size() const{    return (under_container.size()); }

    value_type& top(){  return (under_container[0]);}
    const value_type& top() const{  return (under_container[under_container.size() - 1]);}

    void push (const value_type& val)   {   under_container.push_back(val);}

    void pop(){ under_container.pop_back(); }

    private:
    container_type  under_container;
    
}

#endif