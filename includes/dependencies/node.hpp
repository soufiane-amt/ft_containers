/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:45:19 by samajat           #+#    #+#             */
/*   Updated: 2023/02/23 16:10:37 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "../dependencies/utility.hpp"

namespace ft
{
    

template <typename T>
struct Node
{
    
    typedef T                                       data_value_type;
    typedef T&                                      data_value_type_ref;

    Node   *parent;
    Node   *left;
    Node   *right;
    T       data;
    
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
    
    bool operator>(const Node& node) {    return (this->data > node.data); }
    
    bool operator<(const Node& node) {    return (this->data < node.data); }
    
    void        set_node_to_left (Node *_node){    this->left = _node; _node->parent = this;}
    void        set_node_to_right (Node *_node){    this->right = _node; _node->parent = this;}


    Node   *find_last_node(Node   * _node) ;
    Node   *find_first_node(Node   * _node) ;

    void    swap(Node& x)
    {
    }


    
    bool    is_leaf () {        return (!this->left && ! this->right);}
    bool    has_2_child () {    return (this->left &&   this->right);}
    bool    has_1_child () {    return (!is_leaf() && !has_2_child());}
    bool    has_parent() {      return (this->parent != nullptr );}
    Node*    get_root ()  {     Node    *node = this;while (node->parent)    node = node->parent;return (node);};
    
    bool    is_last_node () 
    {
        Node*   root = get_root();
        bool    first_case = !this->parent && !this->right;
        bool    second_case = this->parent && (this->parent->data < this->data) && !this->right && root->data < this->data ;
        return (first_case || second_case);
    }
    
    bool    is_first_node () 
    {
        Node*   root = get_root();
        bool    first_case = !this->parent && !this->right;
        bool    second_case = this->parent && (this->parent->data < this->data) && !this->right && root->data < this->data ;
        return (first_case || second_case);
    }
};

/*            allocator.destroy(this->elements + i);
        allocator.deallocate(this->elements, _v_capacity);


            this->elements = allocator.allocate (this->_v_size);
        allocator.construct(this->elements + i, x[i]);
*/



template <typename T>
Node<T>*
Node<T>::find_last_node(Node<T>* _node) 
{
    Node<T>* tmp = _node;
    while (tmp && tmp->parent)
        tmp = tmp->parent;
    while (tmp && tmp->right)
        tmp = tmp->right;
    return (tmp);
}



template <typename T>
Node<T>* 
Node<T>::find_first_node(Node<T>* _node)  
{
    Node<T>* tmp = _node;
    while (tmp && tmp->parent)
        tmp = tmp->parent;
    while (tmp && tmp->left)
        tmp = tmp->left;
    return (tmp);
}


template <typename T>
bool   is_left_child(Node<T>* node)
{
    return (node->parent->left == node);
}


template <typename T>
Node<T>*   max_left(Node<T>* node)
{
    while (node->left)
        node = node->left;
    return (node);
}
template <typename T>
Node<T>*   max_right(Node<T>* node)
{
    while (node->right)
        node = node->right;
    return (node);
}


template <typename T>
Node<T>*   next_node(Node<T>* node)
{
    if (!node)
        return (nullptr);
    if (node->right)
        return(max_left(node->right));
    while (!is_left_child(node))
        node = node->parent;
    return (node->parent);
}

template <typename T>
Node<T>*   prev_node(Node<T>* node)
{
    if (!node)
        return (nullptr);
    if (node->left)
        return(max_right(node->left));
    while (is_left_child(node))
        node = node->parent;
    return (node->parent);
}


template <class T>
  bool keys_are_equal (const Node<T>* node1 , const Node<T>* node2 )
{ return node1->data.first==node2->data.first; }



//swap arsenal
template <class T>
void 
define_successor_fatherOfToDelete_relation (Node<T>* to_delete, Node<T>* successor , Node<T>* fatherOfToDelete )
{ 
    successor->parent = fatherOfToDelete;
    if (is_left_child(to_delete))
        fatherOfToDelete->left = successor;
    else
        fatherOfToDelete->right = successor;
}

template <class T>
void 
define_successor_bro_relation (Node<T>* to_delete, Node<T>* successor )
{
    Node<T>* broNdToSuccessor;

    if (is_left_child(successor))
        successor->right = to_delete->right; 
    else
        successor->left = to_delete->left;
    broNdToSuccessor->parent = successor;
}

template <class T>
void 
define_successor_to_delete_node_relation (Node<T>* to_delete, Node<T>* successor )
{
    if (is_left_child(successor))
        successor->left = to_delete;
    else
        successor->right = to_delete;
    to_delete->parent = successor;
}

template <class T>
void 
define_to_delete_new_childen_relation (Node<T>* to_delete, Node<T>* left,  Node<T>* right)
{
    to_delete->set_node_to_left (left);
    to_delete->set_node_to_left (right);
}


template <class T>
void 
define_new_parents_for_to_delete_and_successor (Node<T>* to_delete, Node<T>* successor)
{
    Node<T>* fatherOfToDelete = to_delete->parent
    Node<T>* fatherOfSuccessor= successor->parent
    bool     successor_is_left_child = is_left_child(successor);

    successor->parent = fatherOfToDelete;
    if (is_left_child(to_delete))
        fatherOfToDelete->left = successor;
    else
        fatherOfToDelete->right = successor;

    to_delete->parent = fatherOfSuccessor;
    if (successor_is_left_child)
        fatherOfSuccessor->left = to_delete;
    else
        fatherOfSuccessor->right = to_delete;

}




};

#endif