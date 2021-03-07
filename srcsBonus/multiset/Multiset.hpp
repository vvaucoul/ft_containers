/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multiset.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:16:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 18:16:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MULTISET_HPP
# define MULTISET_HPP

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <limits>
#include <utility>

#include "../../srcs/utils/utils.hpp"
#include "../set/Set.hpp"
#include "../set/SetIterator.hpp"
#include "../set/SetBinaryTreeBlackRed.hpp"

namespace ft
{
    template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class multiset : public ft::set<T>
    {
    public:
        typedef ft::set<T> set;
        using typename set::size_type;
        using typename set::key_type;
        using typename set::value_type;
        using typename set::pointer;
        using typename set::const_pointer;
        using typename set::reference;
        using typename set::const_reference;
        using typename set::key_compare;
        using typename set::value_compare;
        using typename set::node;

        using typename set::iterator;
        using typename set::const_iterator;
        using typename set::reverse_iterator;
        using typename set::const_reverse_iterator;

    public:
        multiset(const Compare &comp = Compare()) : set()
        {
            (void)comp;
            this->_tree.init_tree();
        }
        template <class InputIterator>
        multiset(InputIterator first, InputIterator last)
        {
            set::clear();
            this->_tree.init_tree();
            insert(first, last);
        }
        multiset(multiset const &x) : set(x)
        {
            this->_tree.init_tree();
            this->_allocator = (x._allocator);
            this->_comp = (x._comp);
            this->_size = (0);
            *this = x;
            set::clear();
            insert(x.begin(), x.end());
        }
        virtual ~multiset() {}

        multiset &operator=(multiset const &x) {
            this->set::operator=(x);
            return (*this);
        }

        iterator insert(const_reference val)
        {
            node inserted = this->_tree.insert_node(this->_tree.getRoot(), val);
            ++this->_size;
            return (iterator(inserted));
        }
        iterator insert(iterator position, const_reference val)
        {
            ++this->_size;
            return (iterator(this->_tree.insert_node(position.node(), val)));
        }
        template<class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            this->insert(*first++);
        }

        value_compare value_comp(void) const
        {
            return (this->_tree.key_compare());
        }
    };

    template<typename T, typename Compare>
    void swap(multiset<T, Compare> &x, multiset<T, Compare> &y)
    {
        x.swap(y);
    }
};

# endif
