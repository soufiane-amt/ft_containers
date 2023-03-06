/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:18 by samajat           #+#    #+#             */
/*   Updated: 2023/02/27 15:13:05 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "../iterators/tree_iterator.hpp"
#include "../iterators/const_tree_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "node.hpp"


namespace ft
{

/* ***************************************************************************************************************/
   ///////////////////                        Deletion_Arsenal :                             ///////////////////
/* ***************************************************************************************************************/



template<
    class BST
    >
class deletion_arsenal
{
    public:
    typedef typename BST::node_allocator_type   nd_allocator;
    typedef typename BST::node_ptr   node_ptr;
    typedef typename BST::iterator   iterator;

    nd_allocator __allocat;
    protected:
    void            delete_node(node_ptr  _node){    __allocat.destroy(_node);   __allocat.deallocate(_node, 1);}
    void            delete_leaf (node_ptr  _node, node_ptr& root);
    void            delete_1_child_parent (node_ptr  _node, node_ptr& root);
    void            delete_2_child_parent (iterator element);

};

template<class BST>
void    deletion_arsenal<BST >::delete_leaf (node_ptr  _node, node_ptr& root)
{    
    if (_node->parent->left == _node)
        _node->parent->left = nullptr;
    else
        _node->parent->right = nullptr;

    if (_node == root)
        root = nullptr;
    delete_node(_node);
}

template<class BST>
void    deletion_arsenal<BST >::delete_1_child_parent (node_ptr  _node, node_ptr& root)
{
    node_ptr child;

    child = _node->right ? _node->right : _node->left;
    if (_node->parent)
    {
        if (_node->parent->left == _node)
            _node->parent->left = child;
        else
            _node->parent->right = child;
    }
    child->parent = _node->parent;
    if (_node == root)
        root = child;
    delete_node(_node);
}

template<class BST>
void    deletion_arsenal<BST >::delete_2_child_parent (iterator element)
{
    node_ptr _node =  element.base();
    node_ptr _next_node =  (++element).base();
    (*_node).swap(*_next_node);
    if (_node ->has_1_child())
        delete_1_child_parent(_node);
    else if (_node->is_leaf())
        delete_leaf(_node);
}



/* ***************************************************************************************************************/
   ///////////////////                        RedBlack_tree_traits :                             ///////////////////
/* ***************************************************************************************************************/


template<
    class T,
    class Allocator 
    >
class traits_tree
{
    public:
        typedef 	T                                                   value_type;
        typedef     Node<value_type>                                    Node;
        typedef     Node*                                               node_ptr ;
        typedef     tree_iterator<node_ptr >                            iterator;
        typedef     typename Allocator::template rebind<Node>::other    node_allocator_type;
};

                                                    
/* ***************************************************************************************************************/
   ///////////////////                        RedBlack_tree :                                    ///////////////////
/* ***************************************************************************************************************/


template<
    class T,
    class Compare,
    class Allocator 
    >
class RedBlack_tree : public deletion_arsenal<traits_tree<T, Allocator> >
{
    public:

    typedef  traits_tree<T, Allocator>         base_traits;
    typedef  deletion_arsenal<traits_tree<T, Allocator> >         base_del;

    typedef typename base_traits::value_type                 value_type;
    typedef typename base_traits::Node                       Node;
    typedef typename Node::NODE_COLOR                        NODE_COLOR;
    typedef typename base_traits::node_ptr                   node_ptr ;
    typedef typename base_traits::node_allocator_type        node_allocator_type;
    
    typedef     size_t                                  size_type;
    typedef     Allocator                               allocator_type;
    typedef     Compare                                 value_compare;
    
    //iterator      
    typedef     tree_iterator<node_ptr >                    iterator;
    typedef     const_tree_iterator<node_ptr >              const_iterator;

    typedef     reverse_iterator<iterator>                  reverse_iterator;
    typedef     ft::reverse_iterator<const_iterator>            const_reverse_iterator;

    private:
    node_ptr        create_node(value_type value){  node_ptr  new_node; new_node = __allocat.allocate (1);   __allocat.construct(new_node, Node(value));    new_node->color = RED;
                                                        if(!__tree_root)
                                                            new_node->color = BLACK;
                                                        return (new_node);}
                                                    
    node_ptr        insert_node (node_ptr& start_node, node_ptr  new_node, bool& success);
    void            tarverseNodesPostOrder(node_ptr _tree, void (RedBlack_tree<T,Compare ,Allocator>::*func)(node_ptr));
    
    void            delete_node(node_ptr  _node){    __allocat.destroy(_node);   __allocat.deallocate(_node, 1);}

    node_ptr        find_parent(node_ptr  __tree, value_type& value, bool &node_is_left);
    
    void            make_node_leaf (node_ptr PosPtr)
    {
        node_ptr next_nod;
        while (PosPtr && !PosPtr->is_leaf())  
        {
                next_nod = next_node(PosPtr);
                if (next_nod ==  __end && PosPtr ->left)
                    next_nod = PosPtr ->left;
                PosPtr->swap_for_deletion (next_nod, __tree_root);
        }
    }
    public:
        void        insert_test (const value_type& val, bool color)
    {
        bool l;
        node_ptr    new_node = create_node (val);
        new_node->color = color;
        insert_node (__tree_root, new_node, l);
        __size++;

    }

/* ************************************************************************** */
                            // Costructors :
/* ************************************************************************** */

    RedBlack_tree(const value_compare & comp =  value_compare(),
                  const node_allocator_type& alloc = node_allocator_type());
    RedBlack_tree(const RedBlack_tree& copy);

/* ************************************************************************** */
                            // Overload func :
/* ************************************************************************** */

    RedBlack_tree& operator=(const RedBlack_tree& copy);

/* ************************************************************************** */
                            // Getters :
/* ************************************************************************** */

    node_ptr  get_tree() const {  return (__tree_root);}

    
/* ************************************************************************** */
                            // Insertion :
/* ************************************************************************** */

    ft::pair <node_ptr, bool>                 insert (const value_type& val)
    {
        bool success;
        node_ptr    new_node = create_node (val);
        node_ptr    node =  insert_node (__tree_root, new_node, success);
        if (success)
            RebalanceRedBlackTreeInsert (new_node);
        return (ft::make_pair (node, success));
    }
    /*
    Start at the root of the tree.
    Compare the value you want to insert to the value of the hint node.
    If the value is less than the hint node value, move to the left child of the hint node.
    If the value is greater than the hint node value, move to the right child of the hint node.
    Continue this process until you reach a node that has no child in the direction you need to go (i.e., you reach a leaf node or a null pointer).
    The parent of the null pointer or leaf node is the node you want to insert the new value under.
*/

/*If the hint iterator points to a valid element in the map, the function compares the key of the new element to the key of the element pointed to by the hint iterator. 
If the new element's key is less than the hint element's key, the function moves backwards through the map (towards the beginning) 
until it finds an element whose key is less than the new element's key or it reaches the beginning of the map. 
If the new element's key is greater than or equal to the hint element's key, the function moves forwards through the map (towards the end) 
until it finds an element whose key is greater than or equal to the new element's key or it reaches the end of the map.

*/
node_ptr    insert_hint (node_ptr __hint, node_ptr new_node, bool & success)
{
    int side;
    success = true;
        while (1)
        {
            if  (__value_cmp(__hint->data, new_node->data))
            {
                __hint = next_node (__hint);
                if (__hint->is_leaf())
                {
                    side = accurate_side_of_child (__hint, new_node->data, __value_cmp);
                    if (side == LEFT)
                        __hint->set_node_to_left(new_node);
                    else if (side == RIGHT)
                        __hint->set_node_to_right(new_node);
                    return (new_node);
                }
            }
            else if (__value_cmp(new_node->data, __hint->data))
            {
                __hint = prev_node(__hint);                
                if (__hint->is_leaf())
                {
                    side = accurate_side_of_child (__hint, new_node->data, __value_cmp);
                    if (side == LEFT)
                        __hint->set_node_to_left(new_node);
                    else if (side == RIGHT)
                        __hint->set_node_to_right(new_node);
                    return (new_node);
                }
            }
            else
                break;
        }
        success = false;
        return (__hint);
}

    node_ptr                            insert (node_ptr pos, const value_type&  val)
    {
        bool        success;
        node_ptr    ret;


        if (!__size || (pos == end().__node ) || __tree_root == pos)
            return (insert (val).first);
        node_ptr    new_node = create_node (val);
        ret = insert_hint (pos, new_node, success);
        
        if (success)
            RebalanceRedBlackTreeInsert (new_node);
        return (ret);
    }
/*        bool _find_parent(node_ptr _hint, node_ptr &_parent_pos, const value_type &_val, bool &_is_left)
        {
            if (!_parent_pos)
                return(_parent_pos = _end_node, true);
                
            if (_hint != _end_node && value_comp()(_hint->_value, _val))
            {
                node_ptr _next = _tree_next(_hint);
                if (_next == _end_node || value_comp()(_val, _next->_value))
                {
                    if (_hint->_right)
                    {
                        _parent_pos = _tree_min(_hint->_right);
                        return (true);
                    }
                    else
                    {
                        _parent_pos = _hint;
                        return (_is_left = false, true);
                    }
                }
                else if (!value_comp()(_next->_value, _val))
                {
                    _parent_pos = _next;
                    return (false);
                }
            }
            else if (_hint != _end_node && !value_comp()(_val, _hint->_value))
            {
                _parent_pos = _hint;
                return (false);
            }
            return (_find_parent(_parent_pos, _val, _is_left));
        }
*/

    template <class InputIterator> 
    void                                insert (InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            insert(*first);
            first++;
        }
        
    }

/* ************************************************************************** */
                            // Searching :
/* ************************************************************************** */

    node_ptr  find( value_type to_search) const;
    
/* ************************************************************************** */
                            // Capacity :
/* ************************************************************************** */

    size_type   size() const{   return (__size);}
    size_type                           max_size() const{   return (__allocat.max_size());}


/* ************************************************************************** */
                            // erase :
/* ************************************************************************** */

    node_ptr erase (node_ptr position)
    {
        node_ptr    successor = next_node(position);
        make_node_leaf (position);
        RebalanceRedBlackTreeDelete (position);
        __size--;
        return (successor);
    }
    
    void    RebalanceRedBlackTreeDelete (node_ptr _node)
    {
        node_ptr db_node_sibling = sibling(_node);
        node_ptr node_to_delete = _node;

        if (_node->is_leaf () && _node->color == RED)
        {
            base_del::delete_leaf (_node, this->__tree_root);
            return;
        }
        while (_node ->color == BLACK )
        {
            if (_node == __tree_root)
                break;
            if (_node ->color == BLACK && db_node_sibling->color == RED)
            {
                std::swap (_node->parent->color, db_node_sibling->color);
                if (is_left_child(_node))
                    rotate_left (_node->parent);
                else
                    rotate_right (_node->parent);
                db_node_sibling = sibling(_node);
            }
            if (is_black_node(db_node_sibling) && children_are_black(db_node_sibling))
            {
                ReColor (db_node_sibling);
                if (_node->parent->color == RED)
                {
                    ReColor(_node->parent);
                    break;
                }
                _node = _node->parent;
                db_node_sibling = sibling(_node);
                continue;
            }
            if (is_black_node(db_node_sibling) && is_black_node(far_nephew(_node)) && 
                                                    !is_black_node(near_nephew (_node)))
                {
                    std::swap (near_nephew (_node)->color, db_node_sibling->color);
                    if (is_left_child (_node))
                        rotate_right (db_node_sibling);
                    else
                        rotate_left (db_node_sibling);
                    db_node_sibling = sibling (_node);
                }

            if (is_black_node(db_node_sibling) && !is_black_node(far_nephew(_node)))
            {
                    std::swap (_node->parent->color, db_node_sibling->color);
                    ReColor(far_nephew(_node));
                    if (is_left_child (_node))
                        rotate_left (_node->parent);
                    else
                        rotate_right (_node->parent);
                    db_node_sibling = sibling (_node);
                    break;
            }
        }
        base_del::delete_leaf (node_to_delete, this->__tree_root);
    }

    size_type erase (const value_type& k)
    {
        node_ptr nodeToFind = find(k);
        if (nodeToFind)
            erase (nodeToFind);
        return (nodeToFind != nullptr);
    }
    
    iterator erase (iterator first, iterator last)
    {
        iterator to_erase ;
        while (first != last)
        {
            to_erase = first++;
            erase (to_erase);
        }
        if (!__size){     __tree_root = nullptr;}
        return (to_erase);
    }


/* ************************************************************************** */
                            // Iterators :
/* ************************************************************************** */

    // iterator
    iterator                begin(){    if (!__tree_root)   return (iterator(__end));
                                        return (iterator(max_left(__tree_root)));}
    iterator                end(){    return (iterator(__end));}


    const_iterator          begin() const{  if (!__tree_root)   return (iterator(__end));
                                            return (const_iterator(__tree_root->find_first_node(__tree_root)));};
    const_iterator          end() const{    return (const_iterator(__end));}

    reverse_iterator        rbegin(){ return reverse_iterator(end());}
    reverse_iterator        rend(){ return reverse_iterator(begin());}

    const_reverse_iterator        rbegin() const { return const_reverse_iterator(end());}
    const_reverse_iterator        rend() const { return const_reverse_iterator(begin());}

    


    iterator lower_bound( const value_type& _value )
    {
        node_ptr  node = __tree_root;
        node_ptr  to_ret = __end;

        while (node)
        {
            if (!__value_cmp(node->data, _value))
            {
                to_ret = node;
                node = node->left;
            }
            else
                node = node->right;
        }
        return (iterator(to_ret));
    }

    const_iterator lower_bound( const value_type& _value ) const
    {
        node_ptr  node = __tree_root;
        node_ptr  to_ret = __end;

        while (node)
        {
            if (!__value_cmp(node->data, _value))
            {
                to_ret = node;
                node = node->left;
            }
            else
                node = node->right;
        }
        return (const_iterator(to_ret));
    }


    iterator upper_bound( const value_type& _value )
    {
        node_ptr  node = __tree_root;
        node_ptr  to_ret = __end;

        while (node)
        {
            if (__value_cmp(_value, node->data))
            {
                to_ret = node;
                node = node->left;
            }
            else
                node = node->right;
        }
        return (iterator(to_ret));
    }

    const_iterator upper_bound( const value_type& _value )const
    {
        node_ptr  node = __tree_root;
        node_ptr  to_ret = __end;

        while (node)
        {
            if (__value_cmp(_value, node->data))
            {
                to_ret = node;
                node = node->left;
            }
            else
                node = node->right;
        }
        return (const_iterator(to_ret));
    }
    pair<iterator,iterator>             
    equal_range (const value_type& v)
    {
        iterator first = lower_bound(v);
        iterator second = upper_bound(v);
        return (make_pair(first, second));
    }
    
    pair<const_iterator,const_iterator>             
    equal_range (const value_type& v) const
    {
        const_iterator first = lower_bound(v);
        const_iterator second = upper_bound(v);
        return (make_pair(first, second));
    }

    //deletion
/* ************************************************************************** */
                            // Destroy :
/* ************************************************************************** */

    void        clear();

    void        swap (RedBlack_tree &x)
    {
        std::swap (__end, x.__end);
        std::swap (__size, x.__size);
        std::swap (__tree_root, x.__tree_root);
        std::swap (__allocat, x.__allocat);
        std::swap (__value_cmp, x.__value_cmp);
    }
    ~RedBlack_tree() {       this->clear();  delete_node (__end); };
    

// void    RebalanceRedBlackTreeInsert (node_ptr node)
// {
//     while (node->parent != __end && node->parent->color == RED) {
//         if (node->parent == node->parent->parent->left) {
//             node_ptr uncle = node->parent->parent->right;
//             if (uncle != nullptr && uncle->color == RED) {
//                 // Case 1: Uncle is red
//                 node->parent->color = BLACK;
//                 uncle->color = BLACK;
//                 node->parent->parent->color = RED;
//                 node = node->parent->parent;
//             } else {
//                 if (node == node->parent->right) {
//                     // Case 2: Uncle is black and node is a right child
//                     node = node->parent;
//                     rotate_left(node);
//                 }
//                 // Case 3: Uncle is black and node is a left child
//                 node->parent->color = BLACK;
//                 node->parent->parent->color = RED;
//                 rotate_right(node->parent->parent);
//             }
//         } else {
//             node_ptr uncle = node->parent->parent->left;
//             if (uncle != nullptr && uncle->color == RED) {
//                 // Case 1: Uncle is red
//                 node->parent->color = BLACK;
//                 uncle->color = BLACK;
//                 node->parent->parent->color = RED;
//                 node = node->parent->parent;
//             } else {
//                 if (node == node->parent->left) {
//                     // Case 2: Uncle is black and node is a left child
//                     node = node->parent;
//                     rotate_right(node);
//                 }
//                 // Case 3: Uncle is black and node is a right child
//                 node->parent->color = BLACK;
//                 node->parent->parent->color = RED;
//                 rotate_left(node->parent->parent);
//             }
//         }
//     }
//     __tree_root->color = BLACK;
// }

    // void    RebalanceRedBlackTreeInsert (node_ptr new_node)
    // {
    //     while (new_node != __tree_root)
    //     {
    //         if ( is_black_node(new_node ->parent))
    //             return;
            
    //         if (node_uncle(new_node) && node_uncle(new_node)->color == RED)
    //         {
    //             if(node_forms_triangle (new_node) == LEFT)
    //             {
    //                 ReColor (new_node->parent);
    //                 ReColor (node_uncle(new_node));
    //             }
    //             else if (node_forms_line (new_node))
    //             {
    //                 ReColor(node_uncle(new_node));
    //                 ReColor(new_node->parent);
    //                 ReColor(new_node->parent->parent);
    //             }
    //             new_node = new_node->parent->parent;
    //             continue;
    //         }
    //         if (is_black_node(node_uncle(new_node)))
    //         {
    //             if (node_forms_triangle (new_node) == RIGHT)
    //             {
    //                 node_ptr grand_parent = new_node->parent->parent; 
    //                 rotate_left(new_node->parent);
    //                 rotate_right(grand_parent);
    //                 ReColor (grand_parent);
    //                 ReColor (new_node);
    //             }
    //             else if(node_forms_triangle (new_node) == LEFT)
    //             {
    //                 node_ptr grand_parent = new_node->parent->parent; 
    //                 rotate_right(grand_parent);
    //                 rotate_left(new_node->parent);
    //                 ReColor (new_node->parent);
    //                 ReColor (node_uncle(new_node)); 
    //             }

    //         }
    //     }
    // }

    void    RebalanceRedBlackTreeInsert (node_ptr new_node)
    {
        node_ptr nd_uncle;
        int      nds_form;

    while (new_node != __tree_root )
    {
        if ( is_black_node(new_node ->parent))
            return;
        nd_uncle = node_uncle(new_node);
        if (is_black_node(nd_uncle))
        {
            nds_form = node_forms_triangle (new_node);// new node is not a leaf if the prev cond checked
            if (nds_form == LEFT)
            {
                rotate_right(new_node->parent);
                rotate_left(new_node->parent); 
                ReColor (new_node);
                ReColor (new_node->left);
                break;
            }
            else if (nds_form == RIGHT)
            {
                rotate_left(new_node->parent);
                rotate_right(new_node->parent);
                ReColor (new_node);
                ReColor (new_node->right);
                break;
            }
            else
            {
                nds_form = node_forms_line (new_node);
                if (nds_form == LEFT)
                {
                    rotate_right(new_node->parent->parent);
                    ReColor (new_node->parent);
                    ReColor (new_node->parent->right);

                }
                else if (nds_form == RIGHT)
                {
                    rotate_left(new_node->parent->parent);
                    ReColor (new_node->parent);
                    ReColor (new_node->parent->left);
                }
            }
        }
        else if (nd_uncle && nd_uncle->color == RED )
        {
            if (__tree_root != new_node->parent->parent)
                ReColor (new_node->parent->parent);
            ReColor (new_node->parent);
            ReColor (nd_uncle);
            new_node = nd_uncle->parent;
        }
        }
}


/* ************************************************************************** */
                            // Red Black tree helpers :
/* ************************************************************************** */
    void    rotate_left (node_ptr   x)
    {
        node_ptr    y = x->right;
        node_ptr    p = x->parent;
        node_ptr    B  = nullptr;
        node_ptr    L ;
    
        if (y)
        {
            B = y->left;
            L = y->right;
        }
        if (is_left_child (x))
        {
            if (p)
                p->left = y;
            y->parent = p;
            if (p == __end)
                __tree_root = y;
        }
        else
        {
            p->right = y;
            y->parent = p;
        }
        if (y)
        {
            y->left = x;
            x->parent = y;
        }
        
        x->right = B;
        if (B)
            B->parent = x;
    }
    
    void    rotate_right (node_ptr   y)
    {
        node_ptr    x = y->left;
        node_ptr    p = y->parent;
        node_ptr    B = nullptr ;
        node_ptr    L ;

        if (x)
        {
            B = x->right;
            L = x->left;
        }
        if (is_left_child (y))
        {
            if (p)
                p->left = x;
            x->parent = p;
            if (p == __end)
                __tree_root = x;
        }
        else
        {
            p->right = x;
            x->parent = p;
        }
        if (x)
        {
            x->right = y;
            y->parent = x;
        }
        y->left = B;
        if (B)
            B->parent = y;
    }
    

        template<
        class K,
        class V,
        class C,
        class A 
        >
        friend  class map;
        
        template < class t,
        class Co,
        class Al> 
        friend class set;

    private:
    
    node_ptr                                        __tree_root;
    node_ptr                                        __end;
    size_type                                       __size;
    node_allocator_type                             __allocat;
    value_compare                                   __value_cmp;
};





template<
    class T,
    class Compare ,
    class Allocator 
    >
RedBlack_tree<T,Compare ,Allocator>::RedBlack_tree(const value_compare & value_cmp, const   node_allocator_type& alloc ):  __allocat(alloc),__value_cmp(value_cmp)
{
    __tree_root = nullptr;
    __end = create_node(value_type());
    __size = 0;
}



template<
    class T,
    class Compare ,
    class Allocator 
    >
RedBlack_tree<T,Compare ,Allocator>::RedBlack_tree(const RedBlack_tree& copy):__tree_root(nullptr), __value_cmp (copy.__value_cmp)
{
    __allocat = copy.__allocat;
    __end = create_node(value_type());
    __size = 0;

    insert (copy.begin(), copy.end());
}


template<
    class T,
    class Compare ,
    class Allocator 
    >
RedBlack_tree<T,Compare ,Allocator> & RedBlack_tree<T,Compare ,Allocator>::operator=(const RedBlack_tree& copy)
{
    if (this != &copy)
    {
        this->clear();
        __value_cmp = copy.__value_cmp;
        insert (copy.begin(), copy.end());
    }
    return (*this);
}


template<
    class T,
    class Compare ,
    class Allocator 
    >
typename RedBlack_tree<T,Compare ,Allocator>::node_ptr      
RedBlack_tree<T,Compare ,Allocator>::find_parent(node_ptr  __tree, value_type& value, bool &node_is_left)
{
    if (!__tree)
        return (nullptr);
    while (true)
    {
        if (__value_cmp(value, __tree->data))
        {
            node_is_left = true;
            if (!__tree->left)
                return (__tree);
            __tree = __tree->left;
        }
        else if (__value_cmp(__tree->data, value))//if __tree->data < value
        {
            node_is_left = false;
            if (!__tree->right)
                return (__tree);
            __tree = __tree->right;
        }
        else
            break;
    }
    return (__tree);
}

template<
    class T,
    class Compare ,
    class Allocator 
    >
typename RedBlack_tree<T,Compare ,Allocator>::node_ptr 
RedBlack_tree<T,Compare ,Allocator>::insert_node (node_ptr& start_node, node_ptr  new_node, bool& success)
{
    node_ptr  node;
    bool     left;


    success = false;
    if (!start_node)
    {
        __size++;
        start_node = new_node;
        start_node->parent = __end;
        __end->left = start_node;
        success  = true;
        return (new_node);
    }
    node_ptr tree = start_node;
    node = find_parent(tree, new_node->data, left);

    if (!__value_cmp(node->data, new_node->data) && !__value_cmp(new_node->data, node->data ))
        return (node);
    success  = true;
    if(left)
        node->set_node_to_left(new_node);
    else
        node->set_node_to_right(new_node);
        __size++;

    return (new_node);
}


template<
    class T,
    class Compare ,
    class Allocator 
    >
typename RedBlack_tree<T,Compare ,Allocator>::node_ptr   ///$$$$$$$$$$$$$$ find seg falt when it is given non existing element
RedBlack_tree<T,Compare ,Allocator>::find( value_type to_search) const
{
    node_ptr  node = __tree_root;

    while (node)
    {
        if (__value_cmp(node->data, to_search))//if __tree->data < value
            node = node->right;
        else if (__value_cmp(to_search, node->data))
            node = node->left;
        else
            return node;
    }
    return (nullptr);
}



template<
    class T,
    class Compare ,
    class Allocator 
    >
void    RedBlack_tree<T,Compare ,Allocator>::tarverseNodesPostOrder(node_ptr _tree, void (RedBlack_tree<T,Compare ,Allocator>::*func)(node_ptr))
{
    if (!_tree)
        return;
    tarverseNodesPostOrder(_tree->right, func);
    tarverseNodesPostOrder(_tree->left, func);
    (this->*func)(_tree);
}


template<
    class T,
    class Compare ,
    class Allocator >
void    RedBlack_tree<T,Compare ,Allocator>::clear()
{
    tarverseNodesPostOrder(this->__tree_root, &RedBlack_tree::delete_node);
    __size      = 0;
    __tree_root = nullptr;
}





};

#endif
