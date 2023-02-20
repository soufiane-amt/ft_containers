/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:45:19 by samajat           #+#    #+#             */
/*   Updated: 2023/02/20 16:39:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include "../dependencies/utility.hpp"

namespace ft
{
    

template <typename T, typename Allocator>
struct Node
{
    typedef Allocator                               allocator_type;
    typedef T                                       data_value_type;
    typedef T&                                      data_value_type_ref;

    Node   *parent;
    Node   *left;
    Node   *right;
    T           data;
    
    Node(T d = T()): data(d)
    {
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    Node& operator=(const Node& node)
    {
        this->parent = node.parent;
        this->left = node.left;
        this->right = node.right;
    }
    
    bool operator>(const Node& node {    return (this->data > node.data); }
    
    bool operator<(const Node& node {    return (this->data < node.data); }
    
    void        set_node_to_left (Node *_node){    this->left = _node; _node->parent = this;}
    void        set_node_to_right (Node *_node){    this->right = _node; _node->parent = this;}


    Node   *find_last_node(Node   * _node) ;
    Node   *find_first_node(Node   * _node) ;

    void    swap(Node& x)
    {
        //the Goal of the next two conditions is to make the parent 
        //of the swapped node point to the new node
        if (this->parent)
        {
            if (this->parent->right == this)
                this->parent->right = &x;
            else if (this->parent->left == this)
                this->parent->left = &x;
        }
        if (x.parent && this != x.parent)
        {
            if (x.parent->right == &x)
                x.parent->right =  this;
            else if (x.parent->left == &x)
                x.parent->left =  this;
        }
        if (this->right && this->right != &x)
            this->right->parent = &x;
        if (this->left && this->left != &x)
            this->left->parent = &x;
        std::swap(this->parent, x.parent);
        if (this->left != &x)
            std::swap(this->left, x.left);
        if (this->right != &x)
            std::swap(this->right, x.right);
    }


    
    bool    is_leaf () {    return (!this->left && ! this->right);}
    bool    has_2_child () {    return (this->left &&   this->right);}
    bool    has_1_child () {    return (!is_leaf() && !has_2_child());}
    bool    has_parent() {    return (this->parent != nullptr );}

    ~Node(){    _alloc.destroy(data);}
    
    private:
    allocator_type _alloc;
};

/*            allocator.destroy(this->elements + i);
        allocator.deallocate(this->elements, _v_capacity);


            this->elements = allocator.allocate (this->_v_size);
        allocator.construct(this->elements + i, x[i]);
*/


template <typename U, typename V, typename Allocator > 
void delete_node(Node<pair<U, V>, Allocator > *_node)
{
    allocator.destroy(_node);
    allocator.deallocate(_node, 1);
}

template <typename T, typename Allocator>
Node<T, Allocator>*
Node<T, Allocator>::find_last_node(Node<T, Allocator>* _node) 
{
    Node<T, Allocator>* tmp = _node;
    while (tmp && tmp->parent)
        tmp = tmp->parent;
    while (tmp && tmp->right)
        tmp = tmp->right;
    return (tmp);
}



template <typename T, typename Allocator>
Node<T, Allocator>* 
Node<T, Allocator>::find_first_node(Node<T, Allocator>* _node)  
{
    Node<T, Allocator>* tmp = _node;
    while (tmp && tmp->parent)
        tmp = tmp->parent;
    while (tmp && tmp->left)
        tmp = tmp->left;
    return (tmp);
}


};

#endif