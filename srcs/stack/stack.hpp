/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:35:27 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/24 19:45:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../utils/utils.hpp"
# include <iostream>
# include "../vector/vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
	private:
		typedef T value_type;
		typedef T* pointer;
		typedef T const * const_pointer;
		typedef T& reference;
		typedef T const & const_reference;

		typedef Container container_type;
		typedef size_t size_type;

	protected :
		container_type c;

	public:
		explicit stack(const container_type &c = container_type()) : c(c) { }
		explicit stack (stack const &copy) : c(copy.c) {}

		stack &operator=(const stack &copy)
		{
			c = copy.c;
			*this = copy;
		}

		virtual ~stack() { }

		bool empty(void) const { return(c.empty()); }
		size_t size(void) const { return(c.size()); }

		reference top(void) { return(c.back()); }
		const_reference top(void) const { return(c.back()); }

		void push(const value_type &value) { c.push_back(value); }
		void pop(void) { c.pop_back(); }

	};

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	};
	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	};
	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	};
	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	};
	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	};
	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	};
};

#endif
