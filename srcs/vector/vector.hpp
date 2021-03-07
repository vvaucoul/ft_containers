/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:10:12 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/04 15:55:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <string>
# include <limits>

# include "vectorIterator.hpp"
# include "../utils/utils.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;

		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference;

		typedef ft::VectorIterator<T> iterator;
		typedef ft::ConstVectorIterator<T> const_iterator;
		typedef ft::ReverseVectorIterator<T> reverse_iterator;
		typedef ft::ConstReverseVectorIterator<T> const_reverse_iterator;

	private:
		size_type		_size;
		size_type		_capacity;
		pointer			_array;
		allocator_type 	_allocator;

	private:
		std::out_of_range	_out_of_range(size_type pos)
		{
			std::stringstream ss;

			ss << "vector::_M_range_check: __n (which is " << pos << ")" <<	\
			" >= this->size() (which is " << _size << ")";
			return (std::out_of_range(ss.str()));
		};

		const std::out_of_range	_out_of_range(size_type pos) const
		{
			std::stringstream ss;

			ss << "vector::_M_range_check: __n (which is " << pos << ")" <<	\
			" >= this->size() (which is " << _size << ")";
			return (std::out_of_range(ss.str()));
		};

	public:
		// Constructors;
		explicit vector (const allocator_type &allocator = allocator_type()) :
		_size(0), _capacity(0), _array(0), _allocator(allocator)
		{
			_array = _allocator.allocate(0);
		};

		template <class InputIterator>
		vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type()) :
		_size(0), _capacity(0), _array(0), _allocator(allocator)
		{
			_array = _allocator.allocate(0);
			assign(begin, end);
		};

		explicit vector (size_t const &elements, size_t const &value, const allocator_type &allocator = allocator_type()) :
		_size(0), _capacity(0), _array(0), _allocator(allocator)
		{
			_array = _allocator.allocate(0);
			assign(elements, value);
		};
		explicit vector(size_type elements, const_reference value = value_type(), const allocator_type &allocator = allocator_type()) :
		_size(0), _capacity(0), _array(0), _allocator(allocator)
		{
			_array = _allocator.allocate(0);
			assign(elements, value);
		};

		// Copy
		vector (vector const &copy) :
		_size(0), _capacity(0), _array(0), _allocator(copy._allocator)
		{
			*this = copy;
		}

		// Copy vector
		vector &operator=(vector const &copy)
		{
			if (_array != 0 || this == &copy)
				_allocator.deallocate(_array, _capacity);
			_allocator = copy._allocator;
			_size = 0;
			_capacity = 0;
			_array = _allocator.allocate(0);
			assign(copy.begin(), copy.end());
			return (*this);
		}

		// Destructor
		~vector ()
		{
			_allocator.deallocate(_array, _capacity);
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			for (iterator it = first; it != last; it++) {
				push_back(*it);
			}
		};
		void assign(size_type elements, const value_type &value)
		{
			if (elements < 0 || elements >= std::numeric_limits<size_t>::max())
				throw std::overflow_error("Elements out of bounds");
			clear();
			for (size_t i = 0; i < elements; i++) {
				push_back(value);
			}
		};

		// Iterators

		iterator begin(void) { return (iterator(_array)); };
		const_iterator begin(void) const { return (const_iterator(_array)); };
		iterator end(void) { return (iterator(_array + _size)); };
		const_iterator end(void) const { return (const_iterator(_array + _size)); };
		reverse_iterator rbegin(void) { return (reverse_iterator(_array + _size - 1)); };
		const_reverse_iterator rbegin(void) const { return (const_reverse_iterator(_array + _size - 1)); };
		reverse_iterator rend(void) { return (reverse_iterator(_array - 1)); };
		const_reverse_iterator rend(void) const { return (const_reverse_iterator(_array - 1)); };

		// Capacity

		size_type size(void) const { return (_size); }
		size_type capacity(void) const { return (_capacity); }
		bool empty(void) const { return (_size == 0);	}
		size_type max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(value_type)); }

		void reserve(size_type value)
		{
			if (value <= _capacity)
				return ;
			pointer	tmp;
			tmp  = _allocator.allocate(value * sizeof(value_type));
			for (size_type i = 0; i < _size; i++)
				tmp[i] = _array[i];
			_allocator.deallocate(_array, _capacity);
			_capacity = value;
			_array = tmp;
		}

		// Element access

		reference at(const size_type index)
		{
			if ((index > _size) || index < 0)
				throw _out_of_range(index);
			return (_array[index]);
		}
		const_reference at(const size_type index) const
		{
			if ((index > _size) || index < 0)
				throw _out_of_range(index);
			return (_array[index]);
		}

		reference operator[](const size_type index) { return (_array[index]); }
		const_reference operator[](const size_type index) const { return (_array[index]); }
		reference	front(void) { return (_array[0]); }
		const_reference	front(void) const { return (_array[0]); }
		reference	back(void) { return (_array[_size - 1]); }
		const_reference	back(void) const{ return (_array[_size - 1]); }

		// Modifiers

		void clear(void)
		{
			erase(begin(), end());
		}

		iterator insert(iterator pos, const value_type &value)
		{
			size_t i = 0;
			iterator itmp = begin();
			while (itmp + i != pos && i < _size)
				++i;
			if (_capacity < _size + 1)
				reserve((_size + 1) * sizeof(value));
			size_type j = _capacity - 1;
			while (j > i)
			{
				_array[j] = _array[j - 1];
				j--;
			}
			_array[i] = value;
			_size++;
			return (iterator(&_array[i]));
		}
		void insert(iterator position, size_type n, const value_type &value)
		{
			while (n--)
				position = insert(position, value);
		};

		template< class InputIt >
		void insert(iterator pos, InputIt first, InputIt last)
		{
			while (first != last)
			{
				pos = insert(pos, *first) + 1;
				++first;
			}
		}

		void push_back(value_type const &value)
		{
			if (_size + 1 > _capacity)
				reserve((_size + 1) * sizeof(value));
			_array[_size] = value;
			_size++;
		}

		void pop_back(void)
		{
			if (_size)
				--_size;
		}

		iterator erase(iterator pos)
		{
			iterator start = pos;

			if (!(start != end()))
				throw std::range_error("Error range");

			while (start + 1 != end())
			{
				*start = *(start + 1);
				++start;
			}
			_size--;
			return (iterator(pos));
		}
		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first);
				--last;
			}
			return (iterator(first));
		}

		void resize(size_type count, value_type value = value_type())
		{
			while (count < _size)
				pop_back();
			while (count > _size)
				push_back(value);
		}

		void swap(vector &other)
		{
			ft::swap(_array, other._array);
			ft::swap(_capacity, other._capacity);
			ft::swap(_size, other._size);
		}
	};

	// Out of Class

	// template Swap
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &a, vector<T, Alloc> &b)
	{
		a.swap(b);
	}

	// Operators
	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		if (a.size() != b.size())
			return (false);
		for (size_t i = 0; i < a.size(); i++) {
			if (a[i] != b[i])
				return (false);
		}
		return (true);
	}
	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		// use operator==
		return (!(a == b));
	}
	template<class T, class Alloc>
	bool operator<(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		size_t elem = (a.size() > b.size() ? b.size() : a.size());
		for (size_t i = 0; i < elem; i++) {
			if (a.at(i) != b.at(i))
				return (a.at(i) < b.at(i));
		}
		return (a.size() < b.size());
	}
	template<class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		// use operator < && operator==
		return (a < b || a == b);
	}
	template<class T, class Alloc>
	bool operator>(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		// use operator < && operator==
		return (!(a < b) && !(a == b));
	}
	template<class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		// use operator <
		return (!(a < b));
	}
};

#endif
