/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:18:36 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/02 14:49:49 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <sstream>

namespace ft
{
	// swap elements
	template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};

	// Double linked list
	template <class T>
	struct Element
	{
		T data;
		Element *prev;
		Element *next;
	};

	enum BNodeColor {BLACK, RED};

	// Map Binary tree
	template <class Key, class T>
	struct BNode
	{
		std::pair<Key, T> 	pair;		// data
		BNode				*left;		// node  left
		BNode				*right;		// node right
		BNode				*parent;	// node parent
		BNodeColor			color;		// node color
		bool				end;        // end of branch tree ?
	};

    // Set Binary tree
    template <class T>
    struct BSetNode
    {
        T           value;  // data
        BSetNode    *left;  // node left
        BSetNode    *right; // node right
        BSetNode    *parent; // node parent
        BNodeColor  color;  // node color
        bool        end;    // end of branch tree ?
    };

}

#endif
