/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:15:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/01 20:02:17 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEUE_HPP
#define DEQUEUE_HPP

#include <iostream>
#include <memory>
#include <string>
#include <limits>

#include "../srcs/utils/utils.hpp"
#include "../srcs/vector/vectorIterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class deque
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef T const &const_reference;
		typedef T *pointer;
		typedef T const *const_pointer;

		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference;

		typedef Alloc allocator_type;

		typedef ft::VectorIterator<T> iterator;
		typedef ft::ConstVectorIterator<T> const_iterator;
		typedef ft::ReverseVectorIterator<T> reverse_iterator;
		typedef ft::ConstReverseVectorIterator<T> const_reverse_iterator;

	private:
		size_type _size;
		pointer _array;
		allocator_type _allocator;

	private:
		std::out_of_range _out_of_range(size_type pos)
		{
			std::stringstream ss;

			ss << "vector::_M_range_check: __n (which is " << pos << ")"
			   << " >= this->size() (which is " << _size << ")";
			return (std::out_of_range(ss.str()));
		};

		const std::out_of_range _out_of_range(size_type pos) const
		{
			std::stringstream ss;

			ss << "vector::_M_range_check: __n (which is " << pos << ")"
			   << " >= this->size() (which is " << _size << ")";
			return (std::out_of_range(ss.str()));
		};

		size_t lengthIterator(iterator it, iterator it2)
		{
			size_t i = 0;

			while ((it != it2))
			{
				++i;
				++it;
			}
			return (i);
		}

	public:
		explicit deque(const allocator_type &alloc = allocator_type()) : _size(0), _array(0), _allocator(alloc)
		{
			_array = _allocator.allocate(0);
		}

		explicit deque(size_type count, const T &value = T(), const allocator_type &alloc = allocator_type()) : _size(0), _array(0), _allocator(alloc)
		{
			_array = _allocator.allocate(0);
			assign(count, value);
		}

		template <class InputIt>
		deque(InputIt first, InputIt last, const allocator_type &alloc = allocator_type()) : _size(0), _array(0), _allocator(alloc)
		{
			_array = _allocator.allocate(0);
			assign(first, last);
		}

		deque(const deque &other) : _size(0), _array(0), _allocator(other._allocator)
		{
			*this = other;
		}

		deque &operator=(const deque &other)
		{
			if (_array != 0 || this == &other)
				_allocator.deallocate(_array, _size);
			_allocator = other._allocator;
			_size = 0;
			_array = _allocator.allocate(0);
			assign(other.begin(), other.end());
			return (*this);
		}

		~deque()
		{

        }

		void assign(size_type count, const T &value)
		{
			if ((size_t)count < 0 || (size_t)count >= (size_t)std::numeric_limits<int>::max())
				throw std::overflow_error("ft::deque::_M_new_elements_at_front");
			clear();
			for (size_t i = 0; i < (size_t)count; i++)
			{
				push_back(value);
			}
		}

		template <class InputIt>
		void assign(InputIt first, InputIt last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		reference at(size_type pos)
        {
            if (pos < 0 || pos > _size || pos >= max_size())
                throw _out_of_range(pos);
            return (_array[pos]);
        }
		const_reference at(size_type pos) const
        {
            if (pos < 0 || pos > _size || pos >= max_size())
                throw _out_of_range(pos);
            return (_array[pos]);
        }

		reference operator[](size_type pos)
        {
            if (pos < 0 || pos > _size || pos >= max_size())
                throw _out_of_range(pos);
            return (_array[pos]);
        }
		const_reference operator[](size_type pos) const
        {
            if (pos < 0 || pos > _size || pos >= max_size())
                throw _out_of_range(pos);
            return (_array[pos]);
        }

		reference front() { return (_array[0]); }
		const_reference front() const { return (_array[0]); }

		reference back() { return (_array[_size - 1]); }
		const_reference back() const { return (_array[_size - 1]); }

		// Iterarors

		iterator begin(void) { return (iterator(_array)); };
		const_iterator begin(void) const { return (const_iterator(_array)); };
		iterator end(void) { return (iterator(_array + _size)); };
		const_iterator end(void) const { return (const_iterator(_array + _size)); };
		reverse_iterator rbegin(void) { return (reverse_iterator(_array + _size - 1)); };
		const_reverse_iterator rbegin(void) const { return (const_reverse_iterator(_array + _size - 1)); };
		reverse_iterator rend(void) { return (reverse_iterator(_array - 1)); };
		const_reverse_iterator rend(void) const { return (const_reverse_iterator(_array - 1)); };

		bool empty() const { return (_size == 0); }
		size_type size() const { return (_size); }
		size_type max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(value_type)); }

		void clear()
		{
			erase(begin(), end());
		}

		iterator insert(iterator pos, const T &value)
		{
            size_t i = 0;
            size_t j = 0;
            iterator it = begin();
            pointer new_array;

            while (it + i != pos && i < _size)
                ++i;
            new_array = _allocator.allocate((_size + 1) * sizeof(value));
            for (iterator it2 = begin() ; it2 != end(); it2++) {
                new_array[j] = _array[j];
                ++j;
            }
            while (j > i)
            {
                new_array[j] = new_array[j - 1];
                --j;
            }
            _allocator.deallocate(_array, _size - 1);
            new_array[i] = value;
            ++_size;
            _array = new_array;
            return (iterator(&_array[i]));
		}
		void insert(iterator pos, size_type count, const T &value)
		{
			while (count--)
				pos = insert(pos, value);
		}
		template <class InputIt>
		void insert(iterator pos, InputIt first, InputIt last)
		{
			while (first != last)
			{
				pos = insert(pos, *first) + 1;
				++first;
			}
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

		void push_back(const T &value)
		{
			pointer new_array = _allocator.allocate(((_size + 1) * (sizeof(value) * sizeof(value_type))));
			for (size_t i = 0; i < _size; i++)
			{
				new_array[i] = _array[i];
			}
			new_array[_size] = value;
			_array = new_array;
			++_size;
		}

		void pop_back()
		{
			pointer new_array = _allocator.allocate((_size - 1) * sizeof(value_type));
			for (size_t i = 0; i < _size - 1; i++)
			{
				new_array[i] = _array[i];
			}
			_allocator.deallocate(_array, _size);
			_array = new_array;
			--_size;
		}

		void push_front(const T &value)
		{
			pointer new_array;
            new_array = _allocator.allocate(((_size + 1) * (sizeof(value) * sizeof(value_type))));
            new_array[0] = value;
			for (size_t i = 1; i < _size + 1; i++)
			{
				new_array[i] = _array[i - 1];
			}
			_allocator.deallocate(_array, _size);
			_array = new_array;
			++_size;
		}

		void pop_front()
		{

			pointer new_array = _allocator.allocate((_size - 1) * sizeof(value_type));
			for (size_t i = 1; i < _size; i++)
			{
				new_array[i - 1] = _array[i];
			}
			_allocator.deallocate(_array, _size);
			_array = new_array;
			--_size;
		}

		void resize(size_type count, T value = T())
		{
			while (count < _size)
				pop_back();
			while (count > _size)
				push_back(value);
		}

		void swap(deque &other)
		{
			ft::swap(_array, other._array);
			ft::swap(_size, other._size);
		}
	};
	// Out of Class

	// template Swap
	template <class T, class Alloc>
	void swap(deque<T, Alloc> &a, deque<T, Alloc> &b)
	{
		a.swap(b);
	}

	// Operators
	template <class T, class Alloc>
	bool operator==(const deque<T, Alloc> &lhs, const deque<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}
	template <class T, class Alloc>
	bool operator!=(const deque<T, Alloc> &lhs, const deque<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<(const deque<T, Alloc> &lhs, const deque<T, Alloc> &rhs)
	{
		size_t elem = (lhs.size() > rhs.size() ? rhs.size() : lhs.size());
		for (size_t i = 0; i < elem; i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return (lhs.at(i) < rhs.at(i));
		}
		return (lhs.size() < rhs.size());
	}
	template <class T, class Alloc>
	bool operator<=(const deque<T, Alloc> &lhs, const deque<T, Alloc> &rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator>(const deque<T, Alloc> &lhs, const deque<T, Alloc> &rhs)
	{
		return (!(lhs < rhs) && !(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator>=(const deque<T, Alloc> &lhs, const deque<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
};

#endif
