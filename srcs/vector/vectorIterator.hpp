/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:29:18 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/24 16:26:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

	protected:
		pointer _ptr;

	public:

		// Default
		VectorIterator () {}
		VectorIterator(const pointer _ptr) : _ptr(_ptr) { };
		VectorIterator(VectorIterator const &copy) { *this = copy; }
		VectorIterator(VectorIterator const &rhs, pointer _ptr) : _ptr(_ptr) {(void)rhs;}

		VectorIterator &operator=(VectorIterator const &rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		}

		virtual ~VectorIterator () {}

		// Expressions

		// ++
		VectorIterator &operator++(void)
		{
			++this->_ptr;
			return (*this);
		}
		VectorIterator operator++(int)
		{
			VectorIterator tmp(*this);
			++(*this);
			return (tmp);
		}
		// --
		VectorIterator &operator--(void)
		{
			--this->_ptr;
			return (*this);
		}
		VectorIterator operator--(int)
		{
			VectorIterator tmp(*this);
			--(*this);
			return (tmp);
		}
		// +=
		VectorIterator &operator+=(VectorIterator const &vi)
		{
			_ptr += vi->_ptr;
			return (*this);
		}
		// -=
		VectorIterator &operator-=(VectorIterator const &vi)
		{
			_ptr -= vi->_ptr;
			return (*this);
		}
		// *=
		VectorIterator &operator*=(VectorIterator const &vi)
		{
			_ptr *= vi->_ptr;
			return (*this);
		}
		// /=
		VectorIterator &operator/=(VectorIterator const &vi)
		{
			_ptr /= vi->_ptr;
			return (*this);
		}

		// Bool Expressions

		// >=
		bool operator>=(const VectorIterator &vi) const { return (_ptr >= vi->_ptr); }
		// >
		bool operator>(const VectorIterator &vi) const { return (_ptr > vi->_ptr); }
		// ==
		bool operator==(const VectorIterator &vi) const { return (_ptr == vi->_ptr); }
		// <=
		bool operator<=(const VectorIterator &vi) const { return (_ptr <= vi->_ptr); }
		// <
		bool operator<(const VectorIterator &vi) const { return (_ptr < vi->_ptr); }
		// !=
		bool operator!=(const VectorIterator &vi) const { return (_ptr != vi._ptr); }

		// PTR Expressions

		value_type &operator*(void)  { return (*_ptr); }
		value_type *operator->(void) { return (_ptr); }

		// Expressions + & - with VectorIterator

		VectorIterator operator+(const int i) const
		{
			VectorIterator tmp(*this);
			tmp += i;
			return (tmp);
		}

		VectorIterator operator-(const int i) const
		{
			VectorIterator tmp(*this);
			tmp -= i;
			return (tmp);
		}

		// += & -=

		VectorIterator &operator+=(int i)
		{
			while (i < 0)
			{
				--(*this);
				++i;
			}
			while (i > 0)
			{
				++(*this);
				--i;
			}
			return (*this);
		}

		VectorIterator &operator-=(int i)
		{
			while (i > 0)
			{
				operator--();
				--i;
			}
			while (i < 0)
			{
				operator++();
				++i;
			}
			return (*this);
		}
		// Array
		value_type &operator[](const int i)
		{
			return (*(*this + i));
		}
	};
	template <class T>
	class ReverseVectorIterator
	{
		public:
			typedef T value_type;
			typedef T *pointer;
			typedef T &reference;

		public:

			ReverseVectorIterator(void)	{};
			ReverseVectorIterator(const ReverseVectorIterator &other) { *this = other; };
			ReverseVectorIterator(pointer ptr) { this->_ptr = ptr; };
			~ReverseVectorIterator(void) {};

			ReverseVectorIterator &operator=(const ReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			ReverseVectorIterator &operator++(void)
			{
				this->_ptr--;
				return (*this);
			};
			ReverseVectorIterator operator++(int)
			{
				ReverseVectorIterator tmp(*this);
				this->_ptr--;
				return (tmp);
			};
			ReverseVectorIterator &operator--(void)
			{
				this->_ptr++;
				return (*this);
			};
			ReverseVectorIterator operator--(int)
			{
				ReverseVectorIterator tmp(*this);
				tmp._ptr++;
				rteurn (tmp);
			};
			ReverseVectorIterator operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
				return (*this);
			};
			ReverseVectorIterator operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			};

			bool operator==(const ReverseVectorIterator &other) const {	return (this->_ptr == other._ptr); };
			bool operator!=(const ReverseVectorIterator &other) const {	return (this->_ptr != other._ptr); };
			bool operator>(const ReverseVectorIterator &other) const {	return (this->_ptr > other._ptr); };
			bool operator>=(const ReverseVectorIterator &other) const {	return (this->_ptr >= other._ptr); };
			bool operator<(const ReverseVectorIterator &other) const {	return (this->_ptr < other._ptr); };
			bool operator<=(const ReverseVectorIterator &other) const {	return (this->_ptr <= other._ptr); };

			value_type &operator*(void) { return (*this->_ptr); };
			value_type *operator->(void) { return (this->_ptr); };

			ReverseVectorIterator operator+(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			ReverseVectorIterator operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			value_type &operator[](int n) const
			{
				return (*(*this - n));
			};
	};
	template <class T>
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			ConstVectorIterator(void) {};
			ConstVectorIterator(pointer ptr) { this->_ptr = ptr; };
			ConstVectorIterator(const ConstVectorIterator &other) { *this = other; };
			~ConstVectorIterator(void) {};

			ConstVectorIterator &operator=(const ConstVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			const value_type &operator*(void) { return (*this->_ptr); };
			const value_type &operator[](int n) const { return (*(*this + n)); }
	};
	template <class T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			ConstReverseVectorIterator(void) {};
			ConstReverseVectorIterator(pointer ptr) { this->_ptr = ptr;	};
			ConstReverseVectorIterator(const ConstReverseVectorIterator &other) { *this = other; };
			~ConstReverseVectorIterator(void) {};
			ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			const value_type &operator*(void) { return (*this->_ptr); };
			const value_type &operator[](int n) const { return (*(*this - n)); }
	};
}

#endif
