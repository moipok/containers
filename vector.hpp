/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <fbarbera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:50:40 by fbarbera          #+#    #+#             */
/*   Updated: 2021/04/03 20:39:46 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <exception>
# include "list.hpp"
namespace ft
{

template<class T, class Allocator = std::allocator<T> >
class Vector
{
private:
	T *array;
	size_t _size;
	size_t _cap;
	std::allocator<T> _alloc;
	void ft_copy(T *array, T *array_new)
	{
		for (size_t i = 0; i < _size; i++)
			_alloc.construct(array_new + i, array[i]);
	}
	void	ft_destroy(T *array)
	{
		for (size_t i = 0; i < _size; i++)
			_alloc.destroy(array+i);
	}
	class SegExceptionn : public std::exception 
	{
	private:
		std::string ex;
	public:
		SegExceptionn()  { this->ex = "vector"; }
		const char *what() const throw() { return (ex.c_str()); }
		virtual ~SegExceptionn() throw() { }
	};
public:
	Vector(const Vector &other)
	{
		reserve(other.size());
		_size = other.size();
		for (size_t i = 0; i < _size; i++)
			_alloc.construct(array + i, other[i]);
	}
	Vector &operator=(const Vector &other)
	{
		clear();
		reserve(other.size());
		_size = other.size();
		for (size_t i = 0; i < _size; i++)
			_alloc.construct(array + i, other[i]);
		return (*this);
	}
	Vector() : _size(0), array(NULL), _cap(0) {}
	~Vector() { ft_destroy(array);
			_alloc.deallocate(array, _cap);};
	T&		operator[] (const size_t index) { 
		if (index >= _size)
			return array[_size];
		return array[index];
	}
	const	T& operator[] (const size_t index) const
	{
		if (index >= _size)
			return array[_size];
		return array[index];
	}
	void	push_back(const T &value)
	{
		if (_size == 0 && _cap == 0)
		{
			_size = 1;
			_cap = 1;
			array = _alloc.allocate(_cap, array);
			_alloc.construct(array, value);
			return ;
		}
		if (_size + 1 > _cap)
		{
			_cap *= 2;
			T *array_new = _alloc.allocate(_cap, array_new);
			ft_copy(array, array_new);
			ft_destroy(array);
			_alloc.deallocate(array, _cap/2);
			array = array_new;
			_alloc.construct(array + _size, value);
			_size++;
		}
		else
		{
			_alloc.construct(array + _size, value);
			_size++;
		}
	}
	void	pop_back() {_size--; _alloc.destroy(array + _size);}
	void	clear() { for (; _size;) pop_back(); }
	bool	empty() const {return (_size == 0);}
	size_t	size() const { return _size;}
	T		&back() { 
		if (_size)
			return array[_size - 1];
		return array[_cap - 1];
	}
	const T	&back() const { 
		if (_size)
			return array[_size - 1];
		return array[_cap - 1];
	}
	T		&front() { return array[0];}
	const T	&front() const {return array[0];}
	size_t	capacity() const { return _cap;}
	size_t	max_size() const { return (std::numeric_limits<size_t>::max() / sizeof(T)); }
	void	reserve( size_t new_cap )
	{
		if (new_cap <= _cap)
			return ;
		size_t tmp_cap = _cap;
		_cap = new_cap;
		T *array_new = _alloc.allocate(_cap, array_new);
		ft_copy(array, array_new);
		ft_destroy(array);
		_alloc.deallocate(array, tmp_cap);
		array = array_new;
	}
	void	assign(size_t count, const T& value )
	{
		clear(); reserve(count);
		for (size_t i = 0; i < count; i++)
			push_back(value);
	}
	template< class InputIt >
	void	assign( InputIt first, InputIt last, typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
	{
		clear();
		size_t count = 0;
		for (InputIt i = first; i != last; i++)
			count++;
		reserve(count);
		for (; first != last; first++)
			push_back(*first);
	}
	T		&at(size_t pos) {
		if (!(pos < size()))
			throw SegExceptionn();
		return *(array + pos);
	}
	const T	&at( size_t pos ) const {
		if (!(pos < size()))
			throw SegExceptionn();
		return *(array + pos); 
	}
	void	swap( Vector& other )
	{
		ft::swap(this->_size, other._size);
		ft::swap(this->_cap, other._cap);
		ft::swap(this->array, other.array);
	}
	// iterator erase( iterator pos );
	// iterator erase( iterator first, iterator last );
	// iterator insert( iterator pos, const T& value );
	// void insert( iterator pos, size_type count, const T& value );
	// template< class InputIt >
	// void insert( iterator pos, InputIt first, InputIt last);
	void	resize( size_t count, T value = T() )
	{
		if (count == _size)
			return ;
		else if (count < _size)
		{
			while (count != _size)
				pop_back();
		}
		else
		{
			if (count > _cap)
				reserve(_cap * 2);
			reserve(count);
			while (_size != count)
				push_back(value);
		}
	}
};

template< class T, class Allocator>
void swap( Vector<T,Allocator>& lhs, Vector<T,Allocator>& rhs )
	{ lhs.swap(rhs); }

}

#endif