/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multimap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:08:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 20:19:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIMAP_HPP
# define MULTIMAP_HPP

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <limits>
#include <utility>

#include "../../srcs/utils/utils.hpp"
#include "../../srcs/map/map.hpp"
#include "../../srcs/map/binaryTreeBlackRed.hpp"
#include "../../srcs/map/mapiterator.hpp"

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class multimap : public ft::map<Key, T, Compare > //public ft::map<Key, std::pair<Key, T>, Compare >
    {
    public:
        //typedef ft::map<Key, std::pair<Key, T>, Compare> map;
        typedef ft::map<Key, T, Compare> map;

        using typename map::size_type;
        using typename map::key_type;
        using typename map::value_type;
        using typename map::pointer;
        using typename map::const_pointer;
        using typename map::reference;
        using typename map::const_reference;
        using typename map::key_compare;
        using typename map::value_compare;

        using typename map::node;

        using typename map::iterator;
        using typename map::const_iterator;
        using typename map::reverse_iterator;
        using typename map::const_reverse_iterator;


    public:
        multimap(const std::pair<Key, T> &val) : map()
        {
            this->_tree.init_tree();
            insert(val);
        }
        multimap(const Compare &comp = Compare()): map()
        {
            (void)comp;
            this->_tree.init_tree();
        }
        template <class InputIterator>
        multimap(InputIterator first, InputIterator last)
        {
            this->_tree.init_tree();
            map::clear();
            insert(first, last);
        }
        multimap(multimap const &x): map(x)
        {
            this->_tree.init_tree();
            this->_allocator = (x._allocator);
            this->_comp = (x._comp);
            this->_size = (0);
            *this = x;
            map::clear();
            insert(x.begin(), x.end());
        }

        virtual ~multimap() {}

        multimap &operator=(multimap const &x)
        {
            this->map::operator=(x);
            return (*this);
        }

        std::pair<iterator, bool> insert(const value_type &val)
        {
            ++this->_size;
            return (std::make_pair(iterator(this->_tree.insert_node(this->_tree.getRoot(), val.first, val.second)), true));
        }
        iterator insert(const value_type &val) const
        {
            node inserted = this->_tree.insert_node(this->_tree.getRoot(), val.first, val.second, true);
            ++this->_size;
            return (iterator(inserted));
        }
        iterator insert(iterator position, const value_type &val)
        {
            ++this->_size;
            return (iterator(this->_tree.insert_node(position.node(), val.first, val.second)));
        }
        template<class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                this->insert(*first);
                ++first;
            }
        }
        value_compare value_comp(void) const
        {
            return (value_compare());
        }
    };

    template<typename Key, typename T, typename Compare>
    void swap(multimap<Key, T, Compare> &x, multimap<Key, T, Compare> &y)
    {
        x.swap(y);
    }
};

#endif
