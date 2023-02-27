/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:55:57 by samajat           #+#    #+#             */
/*   Updated: 2023/02/27 13:54:45 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"
#include "pair.hpp"
#include <functional>
#include <memory>
#include <iostream>
#include <algorithm>
#include <map>
#include "../containers/map.hpp"

#include <math.h>

class value_compare
{
    
        std::less<int> comp;
        typedef 	ft::pair<const int,int>    value_type;
    public:
        value_compare(std::less<int> c) : comp(c) {}
        bool operator()(const value_type &_lhs, const value_type &_rhs) const
        {
            return comp(_lhs.first, _rhs.first);
        }
};


typedef ft::binary_tree <int, int, value_compare ,std::allocator<int> > bst;

typedef ft::Node<ft::pair <const int, int> >*  NodePtr;


template <typename Iterator>
void    print_node(Iterator node)
{
    std::cout << "Key: "<< node->first  << std::endl;
    if (node.base()->parent)
        std::cout << "parent: "<< node.base()->parent->data.first  << std::endl;
    if (node.base()->left)
        std::cout << "left: "<< node.base()->left->data.first  << std::endl;
    if (node.base()->right)
        std::cout << "right: "<< node.base()->right->data.first  << std::endl;
    std::cout << "--------------\n";
}


 void padding(char c, int n) 
        {
            for (int i = 0; i < n; i++)
                std::cout << c;
        }

  void find_node_next(NodePtr root, int lvl, NodePtr *arr, size_t &indx)
        {
            if (!root)
            {
                lvl = pow(2, lvl);
                while (lvl-- > 0)
                    arr[indx++] = NULL;
                return ;
            }
            if (lvl == 1)
            {
                arr[indx++] = root->left;
                arr[indx++] = root->right;
                return;
            }
            find_node_next(root->left, lvl-1, arr, indx);
            find_node_next(root->right, lvl-1, arr, indx);
        }

 void print_tree_2(NodePtr _root)
        {
            NodePtr arr[1000000];
            size_t index = 1;
            size_t height = 2 * log2(3);
            
            arr[0] = _root;
            for (size_t j = 0 ; j < height; j++)
                    find_node_next(_root, j + 1, arr, index);
            size_t lvl = 1;
            int pad = height * 16;
            while (arr[--index] == NULL);
            for (size_t i = 0; i <= index; i++)
            {
                if (i + 1 == lvl)
                {                
                    std::cout << "\n\n\n";
                    lvl *= 2;
                    pad /= 2;
                }
                padding(' ', pad);
                if (arr[i])
                {
                    // if (arr[i]->color == RED)
                        // std::cout << "\e[0;31m";
                    std::cout << '(' << arr[i]->data.first << ')' << "\e[0m";
                }
                else
                    std::cout << "  ";
                padding(' ', pad);
            }
            std::cout << "\n\n\n";
            (void)_root;
            (void)arr;
        }

int main ()
{
     bst a;
    bool s;
    srand(time(nullptr));
    // for (size_t i = 1; i < 5; i++)
        a.insert(ft::make_pair(20, 3));
        a.insert(ft::make_pair(10, 3));
        a.insert(ft::make_pair(30, 3));
        a.insert(ft::make_pair(35, 3));
        a.insert(ft::make_pair(15, 3));
        a.insert(ft::make_pair(5, 3));
        // a.insert(ft::make_pair(32, 3));
        // a.insert(ft::make_pair(25, 3));
        // a.insert(ft::make_pair(21, 3));
        
    // a.insert(ft::make_pair(1, 3));
    // a.insert(ft::make_pair(6, 3));
    print_tree_2 (a.__tree_root);
    a.rotate_right (a.__tree_root->left);
    print_tree_2 (a.__tree_root);

    for ( bst::iterator i = a.begin(); i != a.end(); i++)
    {
        std::cout << i->first << std::endl;
    }
    
}

// typedef int bla;
// int main ()
// {
//     // bool l;
//     // std::cout << std::is_same<bla, int>::value << std::endl; // prints "true"

//     std::map <int , int > a;
//     a.insert(std::make_pair(5, 3));
//     a.insert(std::make_pair(1, 3));
//     a.insert(std::make_pair(6, 3));
//     std::map <int , int >::iterator i = a.begin();
//     i =  a.begin();
//     // for (std::map <int , int >::reverse_iterator i = a.rbegin(); i != a.rend(); i++)
//     //     std::cout << (*i).first << std::endl;


//     // //     std::cout << i->first << std::endl;
//     // std::cout << (*a.rbegin()).first << std::endl;
//     // // std::cout << a.rend() << std::endl;
    
// }
