/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:35:57 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 20:43:55 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <limits>
#include <utility>

#include "../utils/utils.hpp"
#include "mapiterator.hpp"
#include "binaryTreeBlackRed.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {
    protected:
        class value_compare
        {
        private:
            typedef T value_type;
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;

        protected:
            Compare comp;
        };

    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const Key, T> value_type;
        typedef size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef Allocator allocator_type;
        typedef T &reference;
        typedef T const &const_reference;
        typedef T *pointer;
        typedef T *const_pointer;

        typedef BNode<key_type, mapped_type> *node;

        typedef MapIterator<key_type, mapped_type> iterator;
        typedef ReverseMapIterator<key_type, mapped_type> reverse_iterator;
        typedef ConstMapIterator<key_type, mapped_type> const_iterator;
        typedef ConstReverseMapIterator<key_type, mapped_type> const_reverse_iterator;

    protected:
        allocator_type _allocator;
        key_compare _comp;
        size_type _size;
        BT::BTree<Key, T, Compare, Allocator> _tree; // binary tree with class main system of map

    public:
        explicit map(const Compare &comp = Compare(), const allocator_type &allocator = allocator_type()) : _allocator(allocator), _comp(comp), _size(0)
        {
            _tree.init_tree();
        }

        template <class InputIt>
        map(InputIt first, InputIt last, const Compare &comp = Compare(), const allocator_type &allocator = allocator_type()) : _allocator(allocator), _comp(comp), _size(0)
        {
            _tree.init_tree();
            insert(first, last);
        }

        map(const map &other)
        {
            _tree.init_tree();
            *this = other;
        }

        virtual ~map()
        {
            _tree.free_tree(_tree.getRoot());
        }

        map &operator=(const map &other)
        {
            if (this == &other)
                return (*this);
            clear();
            insert(other.begin(), other.end());
            return (*this);
        }

        mapped_type &operator[](const key_type &key)
        {
            iterator tmp = find(key);
            if (tmp != end())
                return (tmp->second);
            mapped_type &it = insert(std::make_pair(key, mapped_type())).first->second;
            return (it);
        }

        iterator begin(void)
        {
            node n = _tree.getRoot();
            if (!n->left && !n->right)
                return (end());
            if (!n->left && n->right)
                n = n->right;
            while (n->left)
                n = n->left;
            return (iterator(n));
        }
        const_iterator begin(void) const
        {
            node n = _tree.getRoot();
            if (!n->left && !n->right)
                return (end());
            if (!n->left && n->right)
                n = n->right;
            while (n->left)
                n = n->left;
            return (const_iterator(n));
        }

        iterator end(void) { return (iterator(_tree.end())); }
        const_iterator end(void) const { return (const_iterator(_tree.end())); }
        reverse_iterator rbegin(void)
        {
            iterator it = end();
            --it;
            return (reverse_iterator(it.node()));
        }
        const_reverse_iterator rbegin(void) const
        {
            iterator it = end();
            --it;
            return (const_reverse_iterator(it.node()));
        }
        reverse_iterator rend(void) { return (reverse_iterator(_tree.getRoot())); }
        const_reverse_iterator rend(void) const { return (const_reverse_iterator(_tree.getRoot())); }

        bool empty() const { return (!_size); }
        size_type size() const { return (_size); }
        size_type max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(ft::BNode<key_type, mapped_type>)); }

        void clear()
        {
            iterator it = begin();

            while (it != end())
            {
                _tree.delete_node(it.node());
                --_size;
                ++it;
            }
        }

        std::pair<iterator, bool> insert(const value_type &value)
        {
            iterator it = find(value.first);
            if (it != end())
                return (std::make_pair(it, false));
            ++_size;
            return (std::make_pair(iterator(_tree.insert_node(_tree.getRoot(), value.first, value.second)), true));
        }

        iterator insert(iterator hint, const value_type &value)
        {
            iterator it = find(value.first);
            if (it != end())
                return (it);
            ++_size;
            return (iterator(_tree.insert_node(hint.node(), value.first, value.second)));
        }

        template <class InputIt>
        void insert(InputIt first, InputIt last)
        {
            while (first != last)
            {
                insert(*first);
                ++first;
            }
        }

        void erase(iterator position)
        {
            _tree.delete_node(position.node());
            --_size;
        }

        void erase(iterator first, iterator last)
        {
            iterator it = first;

            while (it != last)
                erase(it++);
        }

        size_type erase(const Key &key)
        {
            size_t elem_deleted = 0;
            iterator itw = begin();
            while (itw != end())
            {
                iterator it = find(key);
                if (it != end())
                {
                    erase(it);
                    ++elem_deleted;
                }
                else
                    return (elem_deleted);
                ++itw;
            }
            return (elem_deleted);
        }

        void swap(map &other)
        {
            ft::swap(_size, other._size);
            ft::swap(_tree, other._tree);
        }

        size_type count(const Key &key) const
        {
            size_t nb_matching_elements = 0;
            const_iterator itw = begin();

            while (itw != end())
            {
                if (itw->first == key)
                    ++nb_matching_elements;
                ++itw;
            }
            return (nb_matching_elements);
        }

        iterator find(const Key &key)
        {
            if (empty())
                return (end());
            node tmp = _tree.find(_tree.getRoot(), key);
            if (tmp)
                return (iterator(tmp));
            return (end());
        }
        const_iterator find(const Key &key) const
        {
            if (empty())
                return (end());
            node tmp = _tree.find(_tree.getRoot(), key);
            if (tmp)
                return (const_iterator(tmp));
            return (end());
        }

        std::pair<iterator, iterator> equal_range(const Key &key)
        {
            return (std::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
        }
        std::pair<const_iterator, const_iterator> equal_range(const Key &key) const
        {
            return (std::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
        }

        iterator lower_bound(const Key &key)
        {
            iterator it = begin();

            while (it != end())
            {
                if (_comp(it->first, key) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        const_iterator lower_bound(const Key &key) const
        {
            const_iterator it = begin();

            while (it != end())
            {
                if (_comp(it->first, key) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        iterator upper_bound(const Key &key)
        {
            iterator it = begin();

            while (it != end())
            {
                if (it->first != key && _comp(it->first, key) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        const_iterator upper_bound(const Key &key) const
        {
            const_iterator it = begin();

            while (it != end())
            {
                if (it->first != key && _comp(it->first, key) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        key_compare key_comp() const { return (_comp); }

        map::value_compare value_comp() const { return (value_comp); }
    };
    template <class Key, class T, class Compare, class Alloc>
    void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
    {
        x.swap(y);
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename ft::map<Key, T, Compare, Alloc>::const_iterator it_lhs = rhs.begin();
        typename ft::map<Key, T, Compare, Alloc>::const_iterator it_rhs = lhs.begin();
        while (it_lhs != rhs.end())
        {
            if (*it_lhs != *it_rhs)
                return (false);
            ++it_rhs;
            ++it_lhs;
        }
        return (true);
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(lhs == rhs));
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs.size() > rhs.size())
            return (true);
        typename ft::map<Key, T, Compare, Alloc>::const_iterator it_lhs = lhs.begin();
        typename ft::map<Key, T, Compare, Alloc>::const_iterator it_rhs = rhs.begin();
        while (it_lhs != lhs.end() && it_rhs != rhs.end())
        {
            if (*it_lhs > *it_rhs)
                return (true);
            ++it_rhs;
            ++it_lhs;
        }
        return (false);
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(lhs > rhs) && !(lhs == rhs));
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(lhs < rhs));
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(lhs > rhs));
    };
};

#endif
