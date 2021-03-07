/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:34:10 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/01 20:01:19 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include <string>

#include "listIterator.hpp"
# include "../utils/utils.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class list
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef std::size_t size_type;

		// List Element

		typedef Element<value_type> *element;

		// iterators

		typedef ListIterator<value_type> iterator;
		typedef ConstListIterator<value_type> const_iterator;
		typedef ReverseListIterator<value_type> reverse_iterator;
		typedef ConstReverseListIterator<value_type> const_reverse_iterator;


	private:
		element			_list_first;
		element			_list_last;
		allocator_type	_allocator;
		size_t			_size;

	private:

		// Init new Element
		Element<value_type> *_newElement(value_type value, Element<value_type> *prev, Element <value_type> *next)
		{
			element element = new Element<value_type>();
			element->data = value;
			element->prev = prev;
			element->next = next;
			return (element);
		}

		// Init list
		void initList(void)
		{
			_list_first = _newElement(value_type(), 0, 0);
			_list_last = _newElement(value_type(), _list_first, 0);
			_list_first->next = _list_last;
		}

	public:

		// Constructor

		explicit list(const allocator_type &allocator = allocator_type()) :
		_list_first(0), _list_last(0), _allocator(allocator), _size(0)
		{
			initList();
		}

		explicit list(size_type count, const value_type &value = value_type(), const allocator_type &allocator = allocator_type()) :
		_list_first(0), _list_last(0), _allocator(allocator), _size(0)
		{
			initList();
			assign(count, value);
		}

		template <class InputIt>
		list(InputIt first, InputIt last, const allocator_type &alloc = allocator_type()) :
		_list_first(0), _list_last(0), _allocator(alloc), _size(0)
		{
			initList();
			assign(first, last);
		}

		list (const list &other) :
		_list_first(0), _list_last(0), _allocator(other._allocator), _size(0)
		{
			initList();
			*this = other;
		}

		~list()
		{
			clear();
		}

		list &operator==(const list &copy)
		{
			if (*this == &copy)
				return (*this);
			clear();
			assign(copy.begin(), copy.end());
			_size = copy._size;
			return (*this);
		}

		// Members functions

		void assign(size_type count, const value_type &value)
		{
			clear();
			for (size_t i = 0; i < count; i++) {
				push_back(value);
			}
		}

		template <class InputIt>
		void assign(InputIt first, InputIt last)
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		// Iterators

		iterator begin() { return(_list_first->next); }
		const_iterator begin() const { return(_list_first->next); }

		iterator end() { return(_list_last); }
		const_iterator end() const { return(_list_last); }

		reverse_iterator rbegin() { return(_list_last->prev); }
		const_reverse_iterator rbegin() const { return(_list_last->prev); }

		reverse_iterator rend() { return(_list_first); }
		const_reverse_iterator rend() const { return(_list_first); }

		// Element access

		reference front() {	return (_list_first->next->data); }
		const_reference front() const { return (_list_first->next->data); }
		reference back() { return (_list_last->prev->data); }
		const_reference back() const { return (_list_last->prev->data); }

		// Capacity

		bool empty() const { return (!_size); }
		size_type size() const { return (_size); }
		size_type max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(Element<T>)); }

		// Modifiers

		void clear()
		{
			element tmp = _list_first->next;
			while (tmp != _list_last)
			{
				element tmp_next = tmp->next;
				delete tmp;
				tmp = tmp_next;
			}
			_list_first->next = _list_last;
			_list_last->prev = _list_first;
			_size = 0;
		}


		iterator insert( iterator pos, const T& value )
		{
			if (pos == begin())
			{
				push_front(value);
				return (begin());
			}
			else if (pos == end())
			{
				push_back(value);
				return (end());
			}
			element last = pos.node();
			element first = last->prev;
			element elem = _newElement(value, first, last);
			first->next = elem;
			last->prev = elem;
			++_size;
			return (iterator(elem));
		}

		void insert( iterator pos, size_type count, const T& value )
		{
			for (size_t i = 0; i < count; i++) {
				pos = insert(pos, value);
			}
		}

		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last)
		{
			while (first != last)
			{
				pos = insert(pos, *first);
				++first;
				if (pos != end())
					++pos;
			}
		}

		iterator erase( iterator pos )
		{
			if (pos == begin())
			{
				pop_front();
				return (begin());
			}
			if (pos == end())
			{
				pop_back();
				return (end());
			}
			element next = pos.node()->next;
			element previous = pos.node()->prev;
			delete pos.node();
			previous->next = next;
			next->prev = previous;
			_size--;
			return (iterator(next));
		}

		iterator erase( iterator first, iterator last )
		{
			while (first != last)
				erase(first++);
			return (first);
		}


		template< class InputIt >
		void push_back(const InputIt &value)
		{
			element newElement = new Element<value_type>();

			newElement = _newElement(*value, _list_last->prev, _list_last);
			_list_last->prev->next = newElement;
			_list_last->prev = newElement;
			++_size;
		}

		void push_back(const value_type &value)
		{
			element newElement = new Element<value_type>();

			newElement = _newElement(value, _list_last->prev, _list_last);
			_list_last->prev->next = newElement;
			_list_last->prev = newElement;
			++_size;
		}

		void pop_back()
		{
			element poped = _list_last->prev->prev;
			delete _list_last->prev;
			poped->next = _list_last;
			_list_last->prev = poped;
			--_size;
		}

		void push_front (const T& value)
		{
			element newElement = new Element<value_type>();

			newElement = _newElement(value, _list_first, _list_first->next);
			_list_first->next->prev = newElement;
			_list_first->next = newElement;
			++_size;
		}

		void pop_front()
		{
			element deleteElement = _list_first->next->next;
			delete _list_first->next;
			_list_first->next = deleteElement;
			deleteElement->prev = _list_first;
			--_size;
		}

		void resize (value_type count, T value = T())
		{
			while ((size_t)count < _size)
				pop_back();
			while ((size_t)count > _size)
				push_back(value);
		}

		void swap (list &other)
		{
			ft::swap(_list_first, other._list_first);
			ft::swap(_list_last, other._list_last);
			ft::swap(_size, other._size);
		}



		// Operations

		template <typename C>
		struct _MES
		{
			bool operator()(const C&x, const C &y)
			{
				return (x == y);
			}
		};

		void merge(list &other)
		{
			merge(other, _MES<value_type>());
		}

		template <class Compare>
		void merge(list &other, Compare comp)
		{
			if (&other == this)
				return ;
			insert(end(), other.begin(), other.end());
			other.clear();
			sort(comp);
		}

		void splice( iterator pos, list &other )
		{
			splice(pos, other, other.begin(), other.end());
		}

		void splice( iterator pos, list& other, iterator it )
		{
			insert(pos, *it);
			other.erase(it);
		}

		void splice( iterator pos, list& other, iterator first, iterator last)
		{
			insert(pos, first, last);
			other.erase(first, last);
		}

		void remove( const T& value )
		{
			iterator it = begin();

			while (it != end())
			{
				if (*it == value)
					it = erase(it);
				else
					++it;
			}
		}

		template< class UnaryPredicate >
		void remove_if( UnaryPredicate p )
		{
			iterator it = begin();

			while (it != end())
			{
				if (p(*it))
					it = erase(it);
				else
					++it;
			}
		}

		void reverse()
		{
			list<value_type> nlist;
			iterator it = begin();

			while (it != end())
			{
				nlist.push_front(*it);
				++it;
			}
			*this = nlist;
		}

		template <typename C>
		struct _UEQ
		{
			bool operator()(const C&x, const C &y)
			{
				return (x == y);
			}
		};

		// delete duplicated elements
		void unique()
		{
			unique(_UEQ<value_type>());
		}


		template< class BinaryPredicate >
		void unique( BinaryPredicate p )
		{
			iterator start = begin();
			iterator s_next = start + 1;

			while (s_next != end())
			{
				if (p(*start, *s_next))
				{
					erase(s_next);
					s_next = start;
				}
				else
					start = s_next;
				++s_next;
			}
		}

		void sort()
		{
			sort(_MES<value_type>());
		}

		template< class Compare >
		void sort( Compare comp )
		{
			iterator start = begin();
			iterator s_next;

			while (start + 1 != end())
			{
				s_next = start + 1;
				while (s_next != end())
				{
					if (comp(*start, *s_next))
						ft::swap(*start, *s_next);
					++s_next;
				}
				++start;
			}
		}
	};
	template <class T, class Alloc>
	void swap(list<T, Alloc> &x, list<T, Alloc> &y)
	{
		x.swap(y);
	};

	template <typename T>
	bool operator==(const list<T> &lhs, const list<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
		{
			typename list<T>::const_iterator lhs_it = lhs.begin();
			typename list<T>::const_iterator rhs_it = rhs.begin();

			while (lhs_it != lhs.end())
			{
				if ((*lhs_it) != (*rhs_it))
					return (false);
				++lhs_it;
				++rhs_it;
			}
		}
		return (true);
	}

	template <typename T>
	bool operator!= (const list<T> &lhs,  const list<T> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <typename T>
	bool operator< (const list<T> &lhs, const list<T> &rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		else if (lhs.size() > rhs.size())
			return (false);
		else
		{
			typename list<T>::const_iterator lhs_it = lhs.begin();
			typename list<T>::const_iterator rhs_it = rhs.begin();
			while (lhs_it != lhs.end())
			{
				if (*lhs_it != *rhs_it)
					return (*lhs_it < *rhs_it);
				++lhs_it;
				++rhs_it;
			}
			return (false);
		}
		return (true);
	}

	template <typename T>
	bool operator<= (const list<T> &lhs,  const list<T> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename T>
	bool operator> (const list<T> &lhs, const list<T> &rhs)
	{
		return ((rhs < lhs));
	}

	template <typename T>
	bool operator>= (const list<T> &lhs,  const list<T> &rhs)
	{
		return (!(lhs < rhs));
	}
};


#endif
