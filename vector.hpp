/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <fbarbera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:50:40 by fbarbera          #+#    #+#             */
/*   Updated: 2021/04/05 14:01:27 by fbarbera         ###   ########.fr       */
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
	class iterator {
	public:
		iterator() : _ptr(nullptr) {}
		iterator(T* rhs) : _ptr(rhs) {}
		iterator(const iterator &rhs) : _ptr(rhs._ptr) {}
		iterator& operator=(T* rhs) {_ptr = rhs; return *this;} 
		iterator& operator=(const iterator &rhs) {_ptr = rhs._ptr; return *this;}
		iterator& operator+=( size_t rhs) {_ptr += rhs; return *this;}
		iterator& operator-=( size_t rhs) {_ptr -= rhs; return *this;}
		T& operator*() const {return *_ptr;}
		T* operator->() const {return _ptr;}
		T& operator[]( size_t rhs) const {return _ptr[rhs];}

		iterator operator + (int n) const{ return iterator(_ptr + n); }
		iterator operator++(int) {    iterator tmp(_ptr++);  return tmp;}
		iterator& operator++() { ++_ptr;  return *this; }
		iterator operator - (int n) const{  return iterator(_ptr - n); }
		iterator operator--(int) { iterator tmp(_ptr--); return tmp; }
		iterator& operator--() { --_ptr; return *this; }

		size_t operator-(const iterator& rhs) const {return _ptr - rhs._ptr;}

		bool operator==(const iterator& rhs) const {return _ptr == rhs._ptr;}
		bool operator!=(const iterator& rhs) const {return _ptr != rhs._ptr;}
		bool operator>(const iterator& rhs) const {return _ptr > rhs._ptr;}
		bool operator<(const iterator& rhs) const {return _ptr < rhs._ptr;}
		bool operator>=(const iterator& rhs) const {return _ptr >= rhs._ptr;}
		bool operator<=(const iterator& rhs) const {return _ptr <= rhs._ptr;}
	protected:
		T* _ptr;
	};
	class const_iterator : public iterator
	{
	public:
		const_iterator() : iterator() {}
		// const_iterator(const const_iterator &other) : iterator(other) {}
		const_iterator(const iterator &other) : iterator(other) {}
		// const_iterator& operator=(const_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
		const T& operator*() const {return *(this->_ptr);}
		const T* operator->() const {return this->_ptr;}
		const T& operator[]( size_t rhs) const {return this->_ptr[rhs];}
	};
	class reverse_iterator {
	public:
		reverse_iterator() : _ptr(nullptr) {}
		reverse_iterator(T* rhs) : _ptr(rhs) {}
		reverse_iterator(const reverse_iterator &rhs) : _ptr(rhs._ptr) {}
		reverse_iterator& operator=(T* rhs) {_ptr = rhs; return *this;} 
		reverse_iterator& operator=(const reverse_iterator &rhs) {_ptr = rhs._ptr; return *this;}
		reverse_iterator& operator+=( size_t rhs) {_ptr -= rhs; return *this;}
		reverse_iterator& operator-=( size_t rhs) {_ptr += rhs; return *this;}
		T& operator*() const {return *_ptr;}
		T* operator->() const {return _ptr;}
		T& operator[]( size_t rhs) const {return _ptr[rhs];}

		reverse_iterator operator + (int n) const{ return reverse_iterator(_ptr - n); }
		reverse_iterator operator++(int) {    reverse_iterator tmp(_ptr--);  return tmp;}
		reverse_iterator& operator++() { --_ptr;  return *this; }
		reverse_iterator operator - (int n) const{  return reverse_iterator(_ptr + n); }
		reverse_iterator operator--(int) { reverse_iterator tmp(_ptr++); return tmp; }
		reverse_iterator& operator--() { ++_ptr; return *this; }

		size_t operator-(const reverse_iterator& rhs) const {return _ptr - rhs._ptr;}

		bool operator==(const reverse_iterator& rhs) const {return _ptr == rhs._ptr;}
		bool operator!=(const reverse_iterator& rhs) const {return _ptr != rhs._ptr;}
		bool operator>(const reverse_iterator& rhs) const {return _ptr > rhs._ptr;}
		bool operator<(const reverse_iterator& rhs) const {return _ptr < rhs._ptr;}
		bool operator>=(const reverse_iterator& rhs) const {return _ptr >= rhs._ptr;}
		bool operator<=(const reverse_iterator& rhs) const {return _ptr <= rhs._ptr;}
	protected:
		T* _ptr;
	};
	class const_reverse_iterator : public reverse_iterator
	{
	public:
		const_reverse_iterator() : reverse_iterator() {}
		// const_reverse_iterator(const const_reverse_iterator &other) : reverse_iterator(other) {}
		const_reverse_iterator(const reverse_iterator &other) : reverse_iterator(other) {}
		// const_reverse_iterator& operator=(const_reverse_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
		const T& operator*() const {return *(this->_ptr);}
		const T* operator->() const {return this->_ptr;}
		const T& operator[]( size_t rhs) const {return this->_ptr[rhs];}
	};
	const_iterator begin() const { return const_iterator(array); }
	const_iterator end() const { return const_iterator(array + _size); }
	iterator begin() { return iterator(array); }
	iterator end() { return iterator(array + _size); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(array + _size - 1); }
	const_reverse_iterator rend() const { return const_reverse_iterator(array - 1); }
	reverse_iterator rbegin() { return reverse_iterator(array + _size - 1); }
	reverse_iterator rend() { return reverse_iterator(array - 1); }
	explicit Vector( const Allocator& alloc ) : _alloc(alloc), _size(0), array(NULL), _cap(0) {}
	explicit Vector( size_t count, const T& value = T(), const Allocator& alloc = Allocator()) : _alloc(alloc), _size(0), array(NULL), _cap(0)
	{
		reserve(count);
		for (size_t i = 0; i < count; i++)
			push_back(value);
	}
	Vector(const Vector &other)
	{
		reserve(other.size());
		_size = other.size();
		for (size_t i = 0; i < _size; i++)
			_alloc.construct(array + i, other[i]);
	}
	template< class InputIt >
	Vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() , typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
	: _alloc(alloc), _size(0), array(NULL), _cap(0)
	{
		size_t count = 0;
		for (InputIt i = first; i != last; i++)
			count++;
		reserve(count);
		for (; first != last; first++)
			push_back(*first);	
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
	iterator erase( iterator pos )
	{
		iterator tmp = pos;
		for (; pos != end(); pos++)
			*pos = *(pos+1);
		_size--;
		return tmp;
	}
	iterator erase( iterator first, iterator last )
	{
		size_t n = last - first;
		for (size_t i = 0; i < n; i++)
			erase(first);
		return first;
	}
	void insert( iterator pos, size_t count, const T& value )
	{
		size_t tmp_size = _size;
		size_t tmp_pos = pos - begin();
		if (count + _size > _cap)
			reserve(_cap * 2);
		reserve(count + _size);
		while (_size != tmp_size + count)
			push_back(value);
		pos = begin() + tmp_pos;
		for (size_t k = 0; k < tmp_size - tmp_pos; k++)
		{
			array[_size - 1 - k] = array[tmp_size - 1 - k];
			array[tmp_size - 1 - k] = value;
		}
	}
	iterator insert( iterator pos, const T& value )
	{
		iterator it = pos;
		this->insert(pos, 1, value);
		return it;
	}
	template< class InputIt >
	void insert( iterator pos, InputIt first, InputIt last, typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
	{
		size_t n = 0;
		for (InputIt it = first; it != last; it++)
			n++;
		while (n)
		{
			pos = insert(pos, *first) + 1;
			first++;
			n--;
		}
	}
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
	friend bool operator==( const Vector& one, const Vector& two )
	{
		if (one.size() != two.size())
			return false;
		iterator it2 = two.begin();
		for (iterator it = one.begin(); it != one.end(); it++)
		{
			if (*it != *it2)
				return false;
			it2++;
		}
		return true;
	}
	friend bool operator!=( const Vector& one, const Vector& two )
	{
		return !(one==two);
	}
	friend bool operator>( const Vector& one, const Vector& two )
	{
		iterator it2 = two.begin();
		for (iterator it = one.begin(); it != one.end(); it++)
		{
			if (it2 == two.end())
				return true;
			if (*it > *it2)
				return true;
			if (*it < *it)
				return false;
			it2++;
		}
		if (it2 != two.end())
			return false;
		return true;
	}
	friend bool operator>=( const Vector& one, const Vector& two )
	{
		return (one > two || one == two);
	}
	friend bool operator<( const Vector& one, const Vector& two )
	{
		return !(one >= two);
	}
	friend bool operator<=( const Vector& one, const Vector& two )
	{
		return !(one > two);
	}
};

template< class T, class Allocator>
void swap( Vector<T,Allocator>& lhs, Vector<T,Allocator>& rhs ) { lhs.swap(rhs); }

}

#endif