/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:45:19 by samajat           #+#    #+#             */
/*   Updated: 2023/02/23 16:46:34 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "../dependencies/utility.hpp"

namespace ft
{
    




//swap arsenal
template <class Node>
struct swap_arsenal
{
    typedef Node* node_ptr;
    
    protected:

    void 
    define_NodeB_parentOfNodeA_relation (node_ptr NodeA, node_ptr NodeB , node_ptr parentOfNodeA )
    { 
        NodeB->parent = parentOfNodeA;
        if (is_left_child(NodeA))
            parentOfNodeA->left = NodeB;
        else
            parentOfNodeA->right = NodeB;
    }
    
    void 
    define_NodeB_bro_relation (node_ptr NodeA, node_ptr NodeB )
    {
        node_ptr broNdToNodeB;
    
        if (is_left_child(NodeB))
            NodeB->right = NodeA->right; 
        else
            NodeB->left = NodeA->left;
        broNdToNodeB->parent = NodeB;
    }
    
    void 
    define_NodeB_NodeA_node_relation (node_ptr NodeA, node_ptr NodeB )
    {
        if (is_left_child(NodeB))
            NodeB->left = NodeA;
        else
            NodeB->right = NodeA;
        NodeA->parent = NodeB;
    }
    
    void 
    define_NodeA_new_childen_relation (node_ptr NodeA, node_ptr left,  node_ptr right)
    {
        NodeA->set_node_to_left (left);
        NodeA->set_node_to_left (right);
    }
    

    void    swap_relatives(node_ptr NodeA, node_ptr NodeB)
    {
        node_ptr NodeB_left  = NodeB->left;
        node_ptr NodeB_right = NodeB->right;

        define_NodeB_parentOfNodeA_relation (NodeA, NodeB ,  NodeA->parent);
        define_NodeB_bro_relation (NodeA, NodeB );
        define_NodeB_NodeA_node_relation (NodeA, NodeB );
        define_NodeA_new_childen_relation (NodeA, NodeB_left,  NodeB_right);

    }
    
    void 
    define_new_parents_for_NodeA_and_NodeB (node_ptr NodeA, node_ptr NodeB)
    {
        node_ptr parentOfNodeA = NodeA->parent;
        node_ptr parentOfNodeB= NodeB->parent;
        bool     NodeB_is_left_child = is_left_child(NodeB);
    
        NodeB->parent = parentOfNodeA;
        if (is_left_child(NodeA))
            parentOfNodeA->left = NodeB;
        else
            parentOfNodeA->right = NodeB;
    
        NodeA->parent = parentOfNodeB;
        if (NodeB_is_left_child)
            parentOfNodeB->left = NodeA;
        else
            parentOfNodeB->right = NodeA;
    }
    
    void 
    define_new_childer_for_NodeA_and_NodeB(node_ptr NodeA, node_ptr NodeB)
    {
        swap(NodeA->left, NodeB->left);
        swap(NodeA->right, NodeB->right);
        
        NodeA->left ->parent = NodeA;
        NodeB->left ->parent = NodeB;
        
        NodeA->right ->parent = NodeA;
        NodeB->right ->parent = NodeB;
        
    }
};



template <typename T>
struct Node : public swap_arsenal<Node<T> >
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
        if (nodes_are_relatives (this, &x))
            
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




template <class T>
  bool nodes_are_relatives (const Node<T>* node , const Node<T>* node_seccessor )
{   
    return (node->left == node_seccessor || node->right == node_seccessor); 
}





};

#endif