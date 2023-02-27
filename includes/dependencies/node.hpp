/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:45:19 by samajat           #+#    #+#             */
/*   Updated: 2023/02/27 20:18:55 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "../dependencies/utility.hpp"
namespace ft
{
//     template<
//     class Key,
//     class T,
//     class Compare,
//     class Allocator 
//     >


#define  BLACK 0
#define  RED   1

#define  LEFT   2
#define  RIGHT  3

//swap arsenal
template <class Node>
struct swap_deletion_arsenal
{
    typedef Node*   node_ptr;


    protected:

    void 
    define_NodeB_parentOfNodeA_relation (node_ptr NodeA, node_ptr NodeB , node_ptr parentOfNodeA , const bool& NodeA_is_left_child)
    { 
        NodeB->parent = parentOfNodeA;
        if (NodeA_is_left_child)
            parentOfNodeA->left = NodeB;
        else
            parentOfNodeA->right = NodeB;

    }
    
    void 
    define_NodeB_bro_relation (node_ptr NodeA, node_ptr NodeB , const bool& NodeB_is_left_child)
    {
        if (NodeB_is_left_child)
        {
            NodeB->right = NodeA->right; 
            if (NodeB->right)
                NodeB->right->parent = NodeB; 
        }
        else
        {
            NodeB->left = NodeA->left;
            if (NodeB->left)
                NodeB->left->parent = NodeB;
        }

    }
    
    void 
    define_NodeB_NodeA_node_relation (node_ptr NodeA, node_ptr NodeB , const bool& NodeB_is_left_child)
    {
        if (NodeB_is_left_child)
            NodeB->left = NodeA;
        else
            NodeB->right = NodeA;
        NodeA->parent = NodeB;
    }
    
    void 
    define_NodeA_new_childen_relation (node_ptr NodeA, node_ptr left,  node_ptr right)
    {
        NodeA->set_node_to_left (left);
        NodeA->set_node_to_right (right);
    }
    



    void    swap_relatives(node_ptr NodeA, node_ptr NodeB)
    {
        node_ptr NodeB_left  = NodeB->left;
        node_ptr NodeB_right = NodeB->right;
        
        node_ptr NodeA_left  = NodeA->left;
        node_ptr NodeA_right = NodeA->right;

        bool NodeAisLeftChild = is_left_child (NodeA);
        bool NodeBisLeftChild = is_left_child (NodeB);
        define_NodeB_parentOfNodeA_relation (NodeA, NodeB ,  NodeA->parent, NodeAisLeftChild);
        define_NodeB_bro_relation (NodeA, NodeB, NodeBisLeftChild );
        define_NodeB_NodeA_node_relation (NodeA, NodeB , NodeBisLeftChild);
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
        
        if (NodeA->left)
            NodeA->left ->parent = NodeA;
        if (NodeB->left)
            NodeB->left ->parent = NodeB;
        if (NodeA->right)
            NodeA->right ->parent = NodeA;
        if (NodeB->right)
            NodeB->right ->parent = NodeB;
    }
    
    void    swap_non_relatives(node_ptr NodeA, node_ptr NodeB)
    {
        node_ptr NodeB_left  = NodeB->left;
        node_ptr NodeB_right = NodeB->right;

        define_new_parents_for_NodeA_and_NodeB  (NodeA, NodeB);
        define_new_childer_for_NodeA_and_NodeB  (NodeA, NodeB);
    }

};



template <typename T>
struct Node : public swap_deletion_arsenal<Node<T> >
{
    
    typedef T                                       data_value_type;
    typedef T*                                      data_value_type_point;
    typedef T&                                      data_value_type_ref;
    typedef bool                                    NODE_COLOR;

    Node            *parent;
    Node            *left;
    Node            *right;
    T                data;
    NODE_COLOR       color;

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
    
    void        set_node_to_left (Node *_node){     this->left = _node; if (!_node)return; _node->parent = this;}
    void        set_node_to_right (Node *_node){     this->right = _node; if (!_node)return; _node->parent = this;}


    Node   *find_last_node(Node   * _node) ;
    Node   *find_first_node(Node   * _node) ;

    
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
    
    void    swap_for_deletion(Node* x, Node*& root)
    {
        if (nodes_are_relatives (this, x))
            this->swap_relatives (this, x);
        else
            this->swap_non_relatives(this, x);
        root = (root == this) ? x : root;
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
bool   is_left_child(const Node<T>* node)
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

template <class T>
  bool has_left_subtree (const Node<T>* node )
{   
    return (node ->left != nullptr);
}

template <class T>
  bool has_right_subtree (const Node<T>* node )
{   
    return (node ->right != nullptr);
}

template <class T>
  bool is_black_node (const Node<T>* node )
{   
    return (!node || node->color == BLACK);
}


template <class T>
void ReColor (Node<T>* node )
{   
    if(!node)
        return;
    if (node->color == BLACK)
        node->color = RED;
    else
        node->color = BLACK;
}

template <class T>
Node<T>* node_uncle (const Node<T>* node )
{  
    const Node<T>* node_parent = node->parent;

    if (is_left_child (node_parent))
        return (node_parent->parent->right);
    return (node_parent->parent->left);
}

template <class T>
int node_forms_triangle (const Node<T>* node )
{
    bool node_left = is_left_child (node) ;
    bool node_parent_left = is_left_child (node->parent) ;
    bool node_gParent_left = is_left_child (node->parent->parent) ;

    if (node_left && !node_parent_left && node_gParent_left)
        return (LEFT);
    if (!node_left && node_parent_left && !node_gParent_left)
        return (RIGHT);
    return (false);
}


template <class T>
int node_forms_line (const Node<T>* node )
{
    bool node_left = is_left_child (node) ;
    bool node_parent_left = is_left_child (node->parent) ;
    bool node_gParent_left = is_left_child (node->parent->parent) ;

    if (node_left && node_parent_left && node_gParent_left)
        return (LEFT);
    if (!node_left && !node_parent_left && !node_gParent_left)
        return (RIGHT);
    return (false);
}




};

#endif