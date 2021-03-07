/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:36:28 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/25 12:41:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

#include <iostream>
#include <string>

#include "../list/list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
	private:
		typedef T value_type;
		typedef T &reference;
		typedef T const &const_reference;
		typedef T *pointer;
		typedef T const *const_pointer;

		typedef Container container_type;
		typedef size_t size_type;

	protected:
		container_type c;

	public:
		explicit queue(const Container &c = container_type()) : c(c) {}
		explicit queue(queue const &copy) :c(copy.c) {}

		queue &operator=(const queue &copy)
		{
			c = copy.c;
			*this = copy;
		}

		virtual ~queue() { }

		reference front() { return (c.front()); }
		const_reference front() const { return (c.front()); }

		reference back() { return (c.back()); }
		const_reference back() const { return (c.back()); }

		bool empty() const { return (c.empty()); }
		size_type size() const { return (c.size()); }

		void push(const T &value) { c.push_back(value); }
		void pop() { c.pop_front(); }
	};

	template <class T, class Container>
	bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	};
	template <class T, class Container>
	bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	};
	template <class T, class Container>
	bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	};
	template <class T, class Container>
	bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	};
	template <class T, class Container>
	bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	};
	template <class T, class Container>
	bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	};
};

#endif
