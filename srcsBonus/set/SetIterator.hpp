/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:52:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/02 19:47:35 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETITERATOR_HPP
# define SETITERATOR_HPP

# include "../../srcs/utils/utils.hpp"
# include <utility>

namespace ft
{
    template <class T>
        class SetIterator {
        private:
            typedef T value_type;
            typedef T &reference;
            typedef BSetNode<T> *pointer;

        protected:
            pointer _ptr;

        private:
			pointer _successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer _predecessor(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			};
		public:
			SetIterator(void)
			: _ptr(0)
			{};
			SetIterator(const pointer ptr)
			: _ptr(ptr)
			{};
			SetIterator(const SetIterator &other)
			{
				*this = other;
			};
			SetIterator &operator=(const SetIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			pointer node(void)
			{
				return (_ptr);
			};
			value_type &operator*(void)
			{
				return (_ptr->value);
			};
			value_type *operator->(void)
			{
				return (&_ptr->value);
			};
			bool operator==(const SetIterator<T> &other)
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const SetIterator<T> &other)
			{
				return (!(*this == other));
			};
			bool operator>(const SetIterator<T> &other)
			{
				return (_ptr > other._ptr);
			};
			bool operator<(const SetIterator<T> &other)
			{
				return (_ptr < other._ptr);
			};
			bool operator>=(const SetIterator<T> &other)
			{
				return (_ptr >= other._ptr);
			};
			bool operator<=(const SetIterator<T> &other)
			{
				return (_ptr <= other._ptr);
			};
			SetIterator &operator++(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			SetIterator &operator--(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			SetIterator operator++(int)
			{
				SetIterator tmp(*this);
				this->operator++();
				return (tmp);
			};
			SetIterator operator--(int)
			{
				SetIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
	template <class T>
	class ConstSetIterator
	{
		public:
			typedef T value_type;
			typedef T &reference;
			typedef BSetNode<T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer _predecessor(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			};
		public:
			ConstSetIterator(void)
			: _ptr(0)
			{};
			ConstSetIterator(const pointer ptr)
			: _ptr(ptr)
			{};
			ConstSetIterator(const ConstSetIterator &other)
			{
				*this = other;
			};
			ConstSetIterator &operator=(const ConstSetIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			pointer node(void)
			{
				return (_ptr);
			};
			value_type &operator*(void) const
			{
				return (_ptr->value);
			};
			value_type *operator->(void) const
			{
				return (&_ptr->value);
			};
			bool operator==(const ConstSetIterator<T> &other)
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const ConstSetIterator<T> &other)
			{
				return (!(*this == other));
			};
			bool operator>(const ConstSetIterator<T> &other)
			{
				return (_ptr > other._ptr);
			};
			bool operator<(const ConstSetIterator<T> &other)
			{
				return (_ptr < other._ptr);
			};
			bool operator>=(const ConstSetIterator<T> &other)
			{
				return (_ptr >= other._ptr);
			};
			bool operator<=(const ConstSetIterator<T> &other)
			{
				return (_ptr <= other._ptr);
			};
			ConstSetIterator &operator++(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			ConstSetIterator &operator--(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			ConstSetIterator operator++(int)
			{
				ConstSetIterator tmp(*this);
				this->operator++();
				return (tmp);
			};
			ConstSetIterator operator--(int)
			{
				ConstSetIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
	template <class T>
	class ReverseSetIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef BSetNode<T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer _predecessor(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			};
		public:
			ReverseSetIterator(void)
			: _ptr(0)
			{};
			ReverseSetIterator(const pointer ptr)
			: _ptr(ptr)
			{};
			ReverseSetIterator(const ReverseSetIterator &other)
			{
				*this = other;
			};
			ReverseSetIterator &operator=(const ReverseSetIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			pointer node(void)
			{
				return (_ptr);
			};
			value_type &operator*(void)
			{
				return (_ptr->value);
			};
			value_type *operator->(void)
			{
				return (&_ptr->value);
			};
			bool operator==(const ReverseSetIterator<T> &other)
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const ReverseSetIterator<T> &other)
			{
				return (!(*this == other));
			};
			bool operator>(const ReverseSetIterator<T> &other)
			{
				return (_ptr > other._ptr);
			};
			bool operator<(const ReverseSetIterator<T> &other)
			{
				return (_ptr < other._ptr);
			};
			bool operator>=(const ReverseSetIterator<T> &other)
			{
				return (_ptr >= other._ptr);
			};
			bool operator<=(const ReverseSetIterator<T> &other)
			{
				return (_ptr <= other._ptr);
			};
			ReverseSetIterator &operator++(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			ReverseSetIterator &operator--(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			ReverseSetIterator operator++(int)
			{
				ReverseSetIterator tmp(*this);
				this->operator++();
				return (tmp);
			};
			ReverseSetIterator operator--(int)
			{
				ReverseSetIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
	template <class T>
	class ConstReverseSetIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef BSetNode<T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer _predecessor(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			};
		public:
			ConstReverseSetIterator(void)
			: _ptr(0)
			{};
			ConstReverseSetIterator(const pointer ptr)
			: _ptr(ptr)
			{};
			ConstReverseSetIterator(const ConstReverseSetIterator &other)
			{
				*this = other;
			};
			ConstReverseSetIterator &operator=(const ConstReverseSetIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			pointer node(void)
			{
				return (_ptr);
			};
			value_type &operator*(void) const
			{
				return (_ptr->value);
			};
			value_type *operator->(void) const
			{
				return (&_ptr->value);
			};
			bool operator==(const ConstReverseSetIterator<T> &other)
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const ConstReverseSetIterator<T> &other)
			{
				return (!(*this == other));
			};
			bool operator>(const ConstReverseSetIterator<T> &other)
			{
				return (_ptr > other._ptr);
			};
			bool operator<(const ConstReverseSetIterator<T> &other)
			{
				return (_ptr < other._ptr);
			};
			bool operator>=(const ConstReverseSetIterator<T> &other)
			{
				return (_ptr >= other._ptr);
			};
			bool operator<=(const ConstReverseSetIterator<T> &other)
			{
				return (_ptr <= other._ptr);
			};
			ConstReverseSetIterator &operator++(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			ConstReverseSetIterator &operator--(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			ConstReverseSetIterator operator++(int)
			{
				ConstReverseSetIterator tmp(*this);
				this->operator++();
				return (tmp);
			};
			ConstReverseSetIterator operator--(int)
			{
				ConstReverseSetIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
};

#endif
