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
    class Key,
    class T,
    class Allocator 
    >
class traits_tree
{
    public:
        typedef     Key                                                 key_type;
        typedef     T                                                   mapped_type;
        typedef 	ft::pair<const key_type,mapped_type>                value_type;
        typedef     Node<value_type>                                    Node;
        typedef     Node*                                               node_ptr ;
        typedef     tree_iterator<node_ptr >                            iterator;
        typedef     typename Allocator::template rebind<Node>::other    node_allocator_type;
};

                                                    
/* ***************************************************************************************************************/
   ///////////////////                        RedBlack_tree :                                    ///////////////////
/* ***************************************************************************************************************/


template<
    class Key,
    class T,
    class Compare,
    class Allocator 
    >
class RedBlack_tree : public deletion_arsenal<traits_tree<Key, T, Allocator> >
{
    public:

    typedef  traits_tree<Key, T, Allocator>         base_traits;
    typedef  deletion_arsenal<traits_tree<Key, T, Allocator> >         base_del;

    typedef typename base_traits::key_type                   key_type;
    typedef typename base_traits::mapped_type                mapped_type;
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
    void            tarverseNodesPostOrder(node_ptr _tree, void (RedBlack_tree<Key,T,Compare ,Allocator>::*func)(node_ptr));
    
    void            delete_node(node_ptr  _node){    __allocat.destroy(_node);   __allocat.deallocate(_node, 1);}

    node_ptr        find_parent(node_ptr  __tree, value_type& value, bool &node_is_left);
    
    void            make_node_leaf (node_ptr PosPtr)
    {
        node_ptr next_nod;
        while (!PosPtr->is_leaf())  
        {
                next_nod = next_node(PosPtr);
                if (next_nod ==  __end && PosPtr ->left)
                    next_nod = PosPtr ->left;
                PosPtr->swap_for_deletion (next_nod, __tree_root);
        }
    }
    public:
    
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

    pair<iterator,bool>                 insert (const value_type& val)
    {
        bool        success;
        node_ptr    new_node = create_node (val);
        iterator    it =  insert_node (__tree_root, new_node, success);
        if (success)
            RebalanceRedBlackTreeInsert (new_node);
        return (ft::make_pair(it, success));
    }
    iterator                            insert (iterator position, const value_type&  val)
    {
        bool        success;
        node_ptr pos = position.base();
        iterator    it;
        if (position != __end && !find(position->first))
            pos = __end;
        if (position !=__end && __value_cmp((*position), val))
            pos = __tree_root;

        node_ptr    new_node = create_node (val);
        if (__size)
            it = insert_node(pos, new_node, success);
        else
            it = insert_node(__tree_root, new_node, success);
        if (success)
            RebalanceRedBlackTreeInsert (new_node);
        return (it);
    }


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

    node_ptr  find( key_type to_search) const;
    
/* ************************************************************************** */
                            // Capacity :
/* ************************************************************************** */

    size_type   size() const{   return (__size);}
    size_type                           max_size() const{   return (__allocat.max_size());}


/* ************************************************************************** */
                            // erase :
/* ************************************************************************** */

    void        insert_test (const value_type& val, bool color)
    {
        bool l;
        node_ptr    new_node = create_node (val);
        new_node->color = color;
        insert_node (__tree_root, new_node, l);
        __size++;

    }
    iterator erase (iterator position)
    {
        node_ptr PosPtr = position.base();
        iterator    successor = next_node(PosPtr);
        make_node_leaf (PosPtr);
        RebalanceRedBlackTreeDelete (PosPtr);
        __size--;
        return (successor);
    }
    
    void    RebalanceRedBlackTreeDelete (node_ptr _node)
    {
        node_ptr node_sibl = node_sibling (_node);

        node_ptr to_delete_node = _node;
        if (_node->is_leaf () && _node->color == RED)
        {
            base_del::delete_leaf (_node, this->__tree_root);
            return;
        }
        while (_node->color == BLACK)
        {
            if (is_black_node(node_sibl) && node_sibl && is_black_node (node_sibl->left) &&  is_black_node (node_sibl->right))
            {
                if (_node == __tree_root)
                    return;
                node_ptr node_parent = _node->parent;
                if (_node ==  to_delete_node)
                    base_del::delete_leaf (_node, this->__tree_root);

                ReColor (node_sibl);
                if (node_parent->color == RED)
                {
                    ReColor(node_parent) ;//if node_parent is black you have now DB
                    return;
                }
                else
                {
                    _node = node_parent;
                    node_sibl = node_sibling (_node);
                }
            }
            if (_node == __tree_root)
                return;
            if (node_sibl && node_sibl->color == RED)
            {
                ft::swap (_node->parent->color, node_sibl->color);
                if (is_left_child(_node))
                    rotate_left (_node->parent);
                else
                    rotate_right (_node->parent);
                node_sibl = node_sibling (_node);
            }
            bool    node_is_left = is_left_child(_node);
            node_ptr node_far_sibl_child = node_is_left ? node_sibl->right : node_sibl->left;
            node_ptr node_near_sibl_child = node_is_left ? node_sibl->left : node_sibl->right;
            if (is_black_node(node_sibl) && is_black_node (node_far_sibl_child) && !is_black_node (node_near_sibl_child) )
            {
                ft::swap (node_near_sibl_child->color, node_sibl->color);
                if (node_is_left)
                    rotate_right (node_sibl);
                else
                    rotate_left (node_sibl);
                node_sibl = node_sibling (_node);
            }
            node_is_left = is_left_child(_node);
            node_far_sibl_child = node_is_left ? node_sibl->right : node_sibl->left;
            if (is_black_node(node_sibl) && !is_black_node(node_far_sibl_child))
            {
                ft::swap (_node->parent->color, node_sibl->color);
                if (is_left_child(_node))
                    rotate_left (_node->parent);
                else
                    rotate_right (_node->parent);
                ReColor(node_far_sibl_child);
                return;
            }
        }
    }

    size_type erase (const key_type& k)
    {
        node_ptr nodeToFind = find(k);
        erase (iterator (nodeToFind));
        return (nodeToFind != nullptr);
    }
    
    iterator erase (iterator first, iterator last)
    {
        iterator next_element ;
        while (first != last)
        {
            next_element = first++;
            erase (next_element);
        }
        if (!__size){     __tree_root = nullptr;}
        return (next_element);
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
    equal_range (const key_type& k)
    {
        iterator first = lower_bound(make_pair(k, mapped_type()));
        iterator second = upper_bound(make_pair(k, mapped_type()));
        return (make_pair(first, second));
    }
    
    pair<const_iterator,const_iterator>             
    equal_range (const key_type& k) const
    {
        const_iterator first = lower_bound(make_pair(k, mapped_type()));
        const_iterator second = upper_bound(make_pair(k, mapped_type()));
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
    
    // void    RebalanceRedBlackTreeInsert (node_ptr new_node)
    // {

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

    private:
    
    node_ptr                                        __tree_root;
    node_ptr                                        __end;
    size_type                                       __size;
    node_allocator_type                             __allocat;
    value_compare                                   __value_cmp;
};





template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
RedBlack_tree<Key,T,Compare ,Allocator>::RedBlack_tree(const value_compare & value_cmp, const   node_allocator_type& alloc ):  __allocat(alloc),__value_cmp(value_cmp)
{
    __tree_root = nullptr;
    __end = create_node(value_type(key_type(), mapped_type()));
    __size = 0;
}



template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
RedBlack_tree<Key,T,Compare ,Allocator>::RedBlack_tree(const RedBlack_tree& copy):__tree_root(nullptr), __value_cmp (copy.__value_cmp)
{
    __allocat = copy.__allocat;
    __end = create_node(value_type(key_type(), mapped_type()));
    __size = 0;

    insert (copy.begin(), copy.end());
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
RedBlack_tree<Key,T,Compare ,Allocator> & RedBlack_tree<Key,T,Compare ,Allocator>::operator=(const RedBlack_tree& copy)
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
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
typename RedBlack_tree<Key,T,Compare ,Allocator>::node_ptr      
RedBlack_tree<Key,T,Compare ,Allocator>::find_parent(node_ptr  __tree, value_type& value, bool &node_is_left)
{
    if (!__tree)
        return (nullptr);
    while (true)
    {
        if (__value_cmp(__tree->data, value))//if __tree->data < value
        {
            node_is_left = false;
            if (!__tree->right)
                return (__tree);
            __tree = __tree->right;
        }
        else if (__value_cmp(value, __tree->data))
        {
            node_is_left = true;
            if (!__tree->left)
                return (__tree);
            __tree = __tree->left;
        }
        else
            break;
    }
    return (__tree);
}

template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
typename RedBlack_tree<Key,T,Compare ,Allocator>::node_ptr 
RedBlack_tree<Key,T,Compare ,Allocator>::insert_node (node_ptr& start_node, node_ptr  new_node, bool& success)
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
    if (start_node == __end)
        start_node--;
    node = find_parent(start_node, new_node->data, left);
    if (keys_are_equal(node, new_node))
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
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
typename RedBlack_tree<Key,T,Compare ,Allocator>::node_ptr   ///$$$$$$$$$$$$$$ find seg falt when it is given non existing element
RedBlack_tree<Key,T,Compare ,Allocator>::find( key_type to_search) const
{
    node_ptr  node = __tree_root;
    value_type to_search_value  = ft::make_pair(to_search, mapped_type());

    while (node)
    {
        if (__value_cmp(node->data, to_search_value))//if __tree->data < value
            node = node->right;
        else if (__value_cmp(to_search_value, node->data))
            node = node->left;
        else
            return node;
    }
    return (nullptr);
}



template<
    class Key,
    class T,
    class Compare ,
    class Allocator 
    >
void    RedBlack_tree<Key,T,Compare ,Allocator>::tarverseNodesPostOrder(node_ptr _tree, void (RedBlack_tree<Key,T,Compare ,Allocator>::*func)(node_ptr))
{
    if (!_tree)
        return;
    tarverseNodesPostOrder(_tree->right, func);
    tarverseNodesPostOrder(_tree->left, func);
    (this->*func)(_tree);
}


template<
    class Key,
    class T,
    class Compare ,
    class Allocator >
void    RedBlack_tree<Key,T,Compare ,Allocator>::clear()
{
    tarverseNodesPostOrder(this->__tree_root, &RedBlack_tree::delete_node);
    __size      = 0;
    __tree_root = nullptr;
}





};

#endif
