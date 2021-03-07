/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryTreeBlackRed.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:39:39 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/23 16:04:29 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYTREEBLACKRED_HPP
# define BINARYTREEBLACKRED_HPP

# include "../utils/utils.hpp"
# include "mapiterator.hpp"

# include <iostream>
# include <string>

namespace BT
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class BTree
	{
		private:
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::BNode<key_type, mapped_type>* node;

			node _root;
			size_t _size;

		public :

			typedef ft::MapIterator<key_type, mapped_type> iterator;

	void debug_tree(node n)
	{
		if (!n)
		return;
		debug_tree(n->left);
		if (n->parent && !n->end)
		std::cout << n->pair.first << "=" << n->pair.second << std::endl;
		debug_tree(n->right);
	};
	node new_node(key_type key, mapped_type value, node parent, bool end = false)
	{
		node el = new ft::BNode<key_type, mapped_type>();
		el->pair = std::make_pair(key, value);
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
	node insert_node(node n, key_type key, mapped_type value, bool end = false)
	{
		if (n->end)
		{
			if (!n->left)
			{
				n->left = new_node(key, value, n, end);
				return (n->left);
			}
			return (insert_node(n->left, key, value));
		}
		if (key < n->pair.first && !end)
		{
			if (!n->left)
			{
				n->left = new_node(key, value, n, end);
				return (n->left);
			}
			else
			return (insert_node(n->left, key, value));
		}
		else
		{
			if (!n->right)
			{
				n->right = new_node(key, value, n, end);
				return (n->right);
			}
			else
			return(insert_node(n->right, key, value));
		}
	};
	node find(node n, key_type key) const
	{
		node tmp;
		if (!n->end && n->pair.first == key && n->parent)
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
		ft::swap(next->pair, n->pair);
		delete_node(next);
	};
	void init_tree(void)
	{
		_root = new_node(key_type(), mapped_type(), 0);
		_root->right  = new_node(key_type(), mapped_type(), _root, true);
		_size = 0;
	};
	node end(void) const
	{
		return (_root->right);
	};

	node getRoot() { return (_root); }
	node getRoot() const { return (_root); }
	};
};

#endif
