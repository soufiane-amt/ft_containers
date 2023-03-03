/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:54:40 by samajat           #+#    #+#             */
/*   Updated: 2023/03/03 22:53:31 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{

template< class T1, class T2 > 
struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;

    first_type  first;
    second_type second;

    pair();
    
    template<class U, class V>
    pair (const pair<U,V>& pr);
    
    pair (const first_type& a, const second_type& b);

    pair& operator= (const pair& pr)
    {
          this->first = pr.first;
          this->second = pr.second;
          return (*this);
    }

};


template< class T1, class T2 > 
pair<T1, T2>::pair() : first(T1()), second(T2())
{
    
}


template< class T1, class T2 > 
template<class U, class V>
pair<T1, T2>::pair (const pair<U,V>& pr):  first(pr.first), second(pr.second)
{
    
}

template< class T1, class T2 > 
pair<T1, T2>::pair (const first_type& a, const second_type& b) : first(a), second(b)
{
    
}



template <class T1, class T2>
  bool operator== (const pair<T1,T2>& p1, const pair<T1,T2>& p2)
{ return p1.first==p2.first && p1.second==p2.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& p1, const pair<T1,T2>& p2)
{ return !(p1==p2); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& p1, const pair<T1,T2>& p2)
{ return p1.first<p2.first || (!(p2.first<p1.first) && p1.second<p2.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& p1, const pair<T1,T2>& p2)
{ return !(p2<p1); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& p1, const pair<T1,T2>& p2)
{ return p2<p1; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& p1, const pair<T1,T2>& p2)
{ return !(p1<p2); }






//make pair
template <class T1,class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
  return ( pair<T1,T2>(x,y) );
}

};
#endif