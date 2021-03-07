/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:57:49 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 20:44:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <limits>
#include <utility>

#include "../../srcs/utils/utils.hpp"
#include "SetIterator.hpp"
#include "SetBinaryTreeBlackRed.hpp"

namespace ft
{
    template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
    class set
    {
    public:
        typedef Allocator allocator_type;
        typedef std::ptrdiff_t difference;
        typedef std::size_t size_type;

        typedef T key_type;
        typedef T value_type;

        typedef Compare comp;

        typedef Compare key_compare;
        typedef Compare value_compare;

        typedef T &reference;
        typedef T const &const_reference;
        typedef T *pointer;
        typedef T const *const_pointer;

        typedef ft::SetIterator<T> iterator;
        typedef ft::ConstSetIterator<T> const_iterator;
        typedef ft::ReverseSetIterator<T> reverse_iterator;
        typedef ft::ConstReverseSetIterator<T> const_reverse_iterator;

        typedef BSetNode<value_type> *node;

    protected:
        allocator_type _allocator;
        comp _comp;
        size_type _size;

        BT::BSetTree<value_type, Compare, Allocator> _tree;

    public:
        // Constructors
        explicit set(const Compare &comp = Compare(), const allocator_type &alloc = allocator_type()) :
        _allocator(alloc), _comp(comp), _size(0)
        {
            _tree.init_tree();
        }

        template <class InputIterator>
        set(InputIterator first, InputIterator last, const Compare &comp = Compare(), const allocator_type &alloc = allocator_type()) :
        _allocator(alloc), _comp(comp), _size(0)
        {
            _tree.init_tree();
            insert(first, last);
        }

        // Copy
        set(const set &x) :
        _allocator(x._allocator), _comp(x._comp), _size(0)
        {
            _tree.init_tree();
            *this = x;
        }

        // Destructor
        ~set()
        {
            _tree.free_tree(_tree.getRoot());
        }

        // =
        set &operator=(const set &x)
        {
            if (this == &x)
                return (*this);
            clear();
            insert(x.begin(), x.end());
            return (*this);
        }

        // Iterators
        iterator begin()
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

        const_iterator begin() const
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

        iterator end()
        {
            return (iterator(_tree.end()));
        }

        const_iterator end() const
        {
            return (const_iterator(_tree.end()));
        }
        reverse_iterator rbegin()
        {
            iterator it = end();
            --it;
            return (reverse_iterator(it.node()));
        }

        const_reverse_iterator rbegin() const
        {
            iterator it = end();
            --it;
            return (const_reverse_iterator(it.node()));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(_tree.getRoot()));
        }

        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(_tree.getRoot()));
        }

        // Capacity
        bool empty() const
        {
            return (_size == 0);
        }
        size_type size() const
        {
            return (_size);
        }
        size_type max_size() const
        {
            return (std::numeric_limits<size_type>::max() / sizeof(ft::BSetNode<value_type>));
        }

        // Modifiers
        std::pair<iterator, bool> insert(const value_type &val)
        {
            iterator it = find(val);
            if (it != end())
                return (std::make_pair(it, false));
            ++_size;
            return (std::make_pair(iterator(_tree.insert_node(_tree.getRoot(), val)), true));
        }

        iterator insert(iterator position, const value_type &val)
        {
            iterator it = find(val);
            if (it != end())
                return (it);
            ++_size;
            return (iterator(_tree.insert_node(position.node(), val)));
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
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

        size_type erase(const value_type &val)
        {
            size_t elem_deleted = 0;
            iterator itw = begin();
            while (itw != end())
            {
                iterator it = find(val);
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

        void erase(iterator first, iterator last)
        {
            iterator it = first;

            while (it != last)
                erase(it++);
        }

        void swap(set &x)
        {
            ft::swap(_size, x._size);
            ft::swap(_tree, x._tree);
        }

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

        // Observers
        Compare key_comp() const
        {
            return (_tree.key_compare());
        }

        Compare value_comp(void) const
        {
    		return (_tree.key_compare());
    	}

        // Operations

        iterator find(const value_type &val) const
        {
            if (empty())
                return (end());
            node tmp = _tree.find(_tree.getRoot(), val);
            if (tmp)
                return (const_iterator(tmp));
            return (end());
        }

        iterator find(const value_type &val)
        {
            if (empty())
                return (end());
            node tmp = _tree.find(_tree.getRoot(), val);
            if (tmp)
                return (iterator(tmp));
            return (end());
        }

        size_type count(const value_type &val) const
        {
            size_t nb_matching_elements = 0;
            const_iterator itw = begin();

            while (itw != end())
            {
                if (*itw == val)
                    ++nb_matching_elements;
                ++itw;
            }
            return (nb_matching_elements);
        }

        iterator lower_bound(const value_type &val)
        {
            iterator it = begin();

            while (it != end())
            {
                if (_comp(*it, val) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        const_iterator lower_bound(const value_type &val) const
        {
            const_iterator it = begin();

            while (it != end())
            {
                if (_comp(*it, val) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        iterator upper_bound(const value_type &val)
        {
            iterator it = begin();

            while (it != end())
            {
                if (*it != val && _comp(*it, val) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        const_iterator upper_bound(const value_type &val) const
        {
            const_iterator it = begin();

            while (it != end())
            {
                if (*it != val && _comp(*it, val) <= 0)
                    return (it);
                ++it;
            }
            return (end());
        }

        std::pair<const_iterator, const_iterator> equal_range(const value_type &val) const
        {
            return (std::make_pair<const_iterator, const_iterator>(lower_bound(val), upper_bound(val)));
        }

        std::pair<iterator, iterator> equal_range(value_type &val)
        {
            return (std::make_pair<iterator, iterator>(lower_bound(val), upper_bound(val)));
        }
    };
    template <class T, class Compare, class Alloc>
    void swap(ft::set<T, Compare, Alloc> &x, ft::set<T, Compare, Alloc> &y)
    {
        x.swap(y);
    };
    template <class T, class Compare, class Alloc>
    bool operator==(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename ft::set<T, Compare, Alloc>::const_iterator it_lhs = rhs.begin();
        typename ft::set<T, Compare, Alloc>::const_iterator it_rhs = lhs.begin();
        while (it_lhs != rhs.end())
        {
            if (*it_lhs != *it_rhs)
                return (false);
            ++it_rhs;
            ++it_lhs;
        }
        return (true);
    };
    template <class T, class Compare, class Alloc>
    bool operator!=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (!(lhs == rhs));
    };
    template <class T, class Compare, class Alloc>
    bool operator>(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        if (lhs.size() > rhs.size())
            return (true);
        typename ft::set<T, Compare, Alloc>::const_iterator it_lhs = lhs.begin();
        typename ft::set<T, Compare, Alloc>::const_iterator it_rhs = rhs.begin();
        while (it_lhs != lhs.end() && it_rhs != rhs.end())
        {
            if (*it_lhs > *it_rhs)
                return (true);
            ++it_rhs;
            ++it_lhs;
        }
        return (false);
    };
    template <class T, class Compare, class Alloc>
    bool operator<(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (!(lhs > rhs) && !(lhs == rhs));
    };
    template <class T, class Compare, class Alloc>
    bool operator>=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (!(lhs < rhs));
    };
    template <class T, class Compare, class Alloc>
    bool operator<=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
    {
        return (!(lhs > rhs));
    };
};

#endif
