/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetBinaryTreeBlackRed.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:08:23 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 14:39:10 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETBINARYTREEBLACKRED_HPP
# define SETBINARYTREEBLACKRED_HPP

# include "../../srcs/utils/utils.hpp"
# include <utility>

# include "SetIterator.hpp"

namespace BT
{
    template <class K, class Compare = std::less<K>, class Allocator = std::allocator<K> >
    class BSetTree
    {
    public:
        typedef K value_type;
        typedef ft::BSetNode<K> *node;
        typedef ft::SetIterator<K> iterator;

    private:
        node    _root;
        size_t  _size;
        Compare _comp;

    public:
        node getRoot() { return (_root); }
        node getRoot() const { return (_root); }

    public:
        void debug_tree(node n)
        {
            if (!n)
                return;
            debug_tree(n->left);
            if (n->parent && !n->end)
                std::cout << n->value << "=" << n->value << std::endl;
            debug_tree(n->right);
        };
        node new_node(value_type key, node parent, bool end = false)
        {
            node el = new ft::BSetNode<value_type>();
            el->value = key;
            el->right = 0;
            el->left = 0;
            el->parent = parent;
            el->end = end;
            return (el);
        };
        void free_tree(node n)
        {
            if (n->right)
                free_tree(n->right);
            if (n->left)
                free_tree(n->left);
            if (n)
                delete n;
        };
        node insert_node(node n, value_type key, bool end = false)
        {
            if (n->end)
            {
                if (!n->left)
                {
                    n->left = new_node(key, n, end);
                    return (n->left);
                }
                return (insert_node(n->left, key));
            }
            if (key < n->value && !end)
            {
                if (!n->left)
                {
                    n->left = new_node(key, n, end);
                    return (n->left);
                }
                else
                return (insert_node(n->left, key));
            }
            else
            {
                if (!n->right)
                {
                    n->right = new_node(key, n, end);
                    return (n->right);
                }
                else
                return(insert_node(n->right, key));
            }
        };
        node find(node n, value_type key) const
        {
            node tmp;
            if (!n->end && n->value == key && n->parent)
            return (n);
            if (n->right)
            {
                if ((tmp = find(n->right, key)))
                return (tmp);
            }
            if (n->left)
            {
                if ((tmp = find(n->left, key)))
                return (tmp);
            }
            return (0);
        };
        void delete_node(node n)
        {
            node parent = n->parent;
            if (!n->left && !n->right)
            {
                if (parent->right == n)
                    parent->right = 0;
                else
                    parent->left = 0;
                delete n;
                return ;
            }
            if (n->right && !n->left)
            {
                if (parent->right == n)
                    parent->right = n->right;
                else
                    parent->left = n->right;
                n->right->parent = parent;
                delete n;
                return ;
            }
            if (n->left && !n->right)
            {
                if (parent->right == n)
                    parent->right = n->left;
                else
                    parent->left = n->left;
                n->left->parent = parent;
                delete n;
                return ;
            }
            node next = (++iterator(n)).node();
            if (!next)
                next = (--iterator(n)).node();
            ft::swap(next->value, n->value);
            delete_node(next);
        };
        void init_tree(void)
        {
            _root = new_node(value_type(), 0);
            _root->right  = new_node(value_type(), _root, true);
            _size = 0;
        };

        node end() const
        {
            return (_root->right);
        };

        node end()
        {
            return (_root->right);
        };

        Compare key_compare(void) const
        {
            return (this->_comp);
        };
    };
};

#endif
