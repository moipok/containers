/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <fbarbera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:26:16 by fbarbera          #+#    #+#             */
/*   Updated: 2021/03/31 19:39:36 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <stddef.h>

namespace ft
{
	template<class T>
	void swap(T &one, T &two)
	{
		T tmp = one;
		one = two;
		two = tmp;
	}	


	template<class T> 
	struct Node
	{
		T		content;
		Node	*Next;
		Node	*Prev;
	};

	template<bool B, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template<class T> 
		class List
		{
		private:
			Node<T>	*Head;
			Node<T>	*Tail;
			Node<T>	*_end;
			size_t _size;
			void ft_glue(Node<T> *one, Node<T> *two)
			{
				one->Next = two;
				two->Prev = one;
			}
			size_t ft_count(Node<T> *one, Node<T> *two)
			{
				Node<T>	*n = one;
				size_t s = 0;
				while (n != two)
				{
					n = n->Next;
					s++;
				}
				return s;
			}
			void nodeswap(Node<T> *one, Node<T> *two)
			{
				one->Next->Prev = two;
				two->Next->Prev = one;
				Node<T> *tmp = one->Next;
				one->Next = two->Next;
				two->Next = tmp;
			
				one->Prev->Next = two;
				two->Prev->Next = one;
				tmp = one->Prev;
				one->Prev = two->Prev;
				two->Prev = tmp;
			}
		public:
			class iterator
			{
			protected:
				Node<T>	*Head;
				friend class List;
				Node<T>	*Get_node() const {return Head;}
			public:
				iterator(Node<T> *Head) : Head(Head) {}
				iterator(iterator const &other) : Head(other.Get_node()) {}
				iterator() {}
				virtual ~iterator() {}
				T *operator->() { return &Head->content; }
				T &operator*() const { return Head->content; }
				iterator &operator++() { Head = Head->Next; return *this;}
				iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp;}
				iterator &operator--() { Head = Head->Prev; return *this;}
				iterator operator--(int) { iterator tmp = *this; --(*this); return tmp;}
				friend bool operator== (const iterator& a, const iterator& b) { return a.operator*() == b.operator*(); };
				friend bool operator!= (const iterator& a, const iterator& b) { return a.operator*() != b.operator*(); };
			};
			class const_iterator : public iterator
			{
			public:
				const_iterator(Node<T> *Head) : iterator(Head) {}
				const_iterator(iterator const &other) : iterator(other.Get_node()) {}
				const_iterator(const_iterator const &other) : iterator(other.Get_node()) {}
				const_iterator() {}
				virtual ~const_iterator() {}
				const T *operator->() const { return &this->Head->content; }
				const T &operator*() const { return this->Head->content; }
			};
			class reverse_iterator
			{
			protected:
				Node<T>	*Head;
				friend class List;
				Node<T>	*Get_node() const {return Head;}
			public:
				reverse_iterator(Node<T> *Head) : Head(Head) {}
				reverse_iterator(reverse_iterator const &other) : Head(other.Get_node()) {}
				reverse_iterator() {}
				virtual ~reverse_iterator() {}
				T *operator->() { return &Head->content; }
				T &operator*() const { return Head->content; }
				reverse_iterator &operator++() { Head = Head->Prev; return *this;}
				reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp;}
				reverse_iterator &operator--() { Head = Head->Next; return *this;}
				reverse_iterator operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp;}
				friend bool operator== (const reverse_iterator& a, const reverse_iterator& b) { return a.operator*() == b.operator*(); };
				friend bool operator!= (const reverse_iterator& a, const reverse_iterator& b) { return a.operator*() != b.operator*(); };
			};
			class const_reverse_iterator : public reverse_iterator
			{
			public:
				const_reverse_iterator(Node<T> *Head) : reverse_iterator(Head) {}
				const_reverse_iterator(reverse_iterator const &other) : reverse_iterator(other.Get_node()) {}
				const_reverse_iterator(const_reverse_iterator const &other) : reverse_iterator(other.Get_node()) {}
				const_reverse_iterator() {}
				virtual ~const_reverse_iterator() {}
				const T *operator->() const { return &this->Head->content; }
				const T &operator*() const { return this->Head->content; }
			};
			reverse_iterator rbegin() const { return reverse_iterator(Tail); }
			reverse_iterator rend() const { return reverse_iterator(_end); }
			iterator begin() const { return iterator(Head); }
			iterator end() const { return iterator(_end); }
			List() : _size(0) {
				_end = new Node<T>;
				_end->Next = _end;
				_end->Prev = _end;
				Head = Tail = _end;
			};
			List(List const &other)
			{
				_end = new Node<T>;
				_end->Next = _end;
				_end->Prev = _end;
				Head = Tail = _end;
				_size = 0;
				assign(iterator(other.Head), iterator(other._end));
			}
			List &operator=(List const &other)
			{
				this->clear();
				_end = new Node<T>;
				_end->Next = _end;
				_end->Prev = _end;
				Head = Tail = _end;
				_size = 0;
				assign(iterator(other.Head), iterator(other._end));
				return(*this);
			}
			~List()
			{
				std::cout << "destructor\n";
				while (_size)
				{
					Tail = Head->Next;
					delete Head;
					Head = Tail;
					_size--;
				}
			}
			void assign (size_t n, const T& val)
			{
				this->clear();
				for (size_t i = 0; i < n; i++)
					this->push_back(val);
			}
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
			{
				this->clear();
				while (first!=last)
				{
					this->push_back(*first);
					first++;
				}
			}
			bool empty() { return (_size) ? 0 : 1; }
			void clear()
			{
				while (_size)
				{
					Tail = Head->Next;
					delete Head;
					Head = Tail;
					_size--;
				}
				Head = Tail = _end;
				_end->Next = Head;
				_end->Prev = Tail;
			}
			void pop_back()
			{
				if (_size == 1)
				{
					delete Head;
					Head = _end;
					Tail = _end;
					_end->Next = Head;
					_end->Prev = Tail;
					_size--;
				}
				else if (_size)
				{
					Tail->Prev->Next = _end;
					_end->Prev = Tail->Prev;
					delete Tail;
					Tail = _end->Prev;
					_size--;
				}
			}
			void pop_front()
			{
				if (_size == 1)
				{
					delete Head;
					Head = _end;
					Tail = _end;
					_end->Next = Head;
					_end->Prev = Tail;
					_size--;
				}
				else if (_size)
				{
					Head->Next->Prev = _end;
					_end->Next = Head->Next;
					delete Head;
					Head = _end->Next;
					_size--;
				}
			}
			void push_back(T content)
			{
				Node<T> *temp = new Node<T>;
				temp->Next = _end;
				_end->Prev = temp;
				temp->content = content;
				_size++;
				if (Head != _end)
				{
					temp->Prev = Tail;
					Tail->Next = temp;
					Tail = temp;
				}
				else
				{
					temp->Prev = _end;
					Head = Tail = temp;
					_end->Next = Head;
				}
			}
			void push_front(T content)
			{
				Node<T>  *temp = new Node<T>;
				temp->Prev = _end;
				_end->Next = temp;
				temp->content = content;
				_size++;
				if (Head != _end)
				{
					temp->Next = Head;
					Head->Prev = temp;
					Head = temp;
				}
				else
				{
					temp->Next = _end;
					Head = Tail = temp;
					_end->Prev = temp;
				}
			}
			T	back() { return (Tail->content); }
			T	front() { return (Head->content); }
			size_t size() const { return _size; }
			size_t max_size() const { return (std::numeric_limits<size_t>::max() / sizeof(Node<T>)); }
			iterator insert( iterator pos, const T& value )
			{
				if (pos == _end)
				{
					push_back(value);
					return (iterator(Head));
				}
				Node<T> *temp = new Node<T>;
				temp->content = value;
				Node<T> *t= Head;
				size_t n = 0;
				for (iterator i = iterator(Head); i != pos; i++)
				{
					n++;
					Head = Head->Next;
				}
				
				temp->Next = Head;
				Head->Prev->Next = temp;
				temp->Prev = Head->Prev;
				Head->Prev = temp;

				n ? Head = t : Head = temp;
				Tail = _end->Prev;
				_size++;
				return (iterator(temp));
			}
			void insert( iterator pos, size_t count, const T& value )
			{
				for(size_t i = 0; i < count; i++)
					insert(pos, value);
			}
			template< class InputIt >
			void insert( iterator pos, InputIt first, InputIt last, typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
			{
				InputIt i;
				for(i = first; i !=last; i++)
					insert(pos, *i);
			}
			iterator erase( iterator pos )
			{
				iterator it(pos);
				it++;
				if (_size)
				{
					Node<T> *temp = pos.Get_node();
					temp->Next->Prev = temp->Prev;
					temp->Prev->Next = temp->Next;
					_size--;
					delete temp;
					Head = _end->Next;
					Tail = _end->Prev;
					return it;
				}
				return pos;
			}
			iterator erase(iterator first, iterator last)
			{
				iterator t = first;
				for (iterator it = first; it!=last; it++)
					t = erase(it);
				return t;
			}
			void resize(size_t count, T value = T())
			{
				if (count < _size)
				{
					iterator it(Head);
					for (size_t i = 0; i < count; i++)
						it++;
					for (size_t i = 0; i < _size - count; i++)
					{ it = erase(it); }
					_size = count;
				}
				else if (count > _size)
				{
					while (_size != count)
						push_back(value);
				}
			}
			void swap( List& other )
			{
				Node<T> *tmp;
				tmp = other.Head;
				other.Head = Head;
				Head = tmp;
				tmp = other.Tail;
				other.Tail = Tail;
				Tail = tmp;
				tmp = other._end;
				other._end = _end;
				_end = tmp;
				size_t n;
				n = other._size;
				other._size = _size;
				_size = n;
			}
			void splice( iterator pos, List& other )
			{
				splice(pos, other, other.begin(), other.end());
			}
			void splice ( iterator pos, List & other, iterator it )
			{
				List<T>::iterator i_end(it);
				i_end++;
				splice(pos, other, it, i_end);
			}
			void splice( iterator pos, List& other, iterator first, iterator last)
			{
				Node<T> *first_node = first.Head;
				Node<T> *last_node = last.Head->Prev;
				Node<T> *pos_start = pos.Head->Prev;
				Node<T> *pos_end = pos.Head;
				
				size_t len = ft_count(first_node,last_node->Next);

				ft_glue(first_node->Prev, last_node->Next);
				ft_glue(last_node, pos_end);
				ft_glue(pos_start, first_node);

				_size+=len;
				other._size-=len;
				Head = _end->Next;
				Tail = _end->Prev;
				other.Head = other._end->Next;
				other.Tail = other._end->Prev;
			}
			void sort()
			{
				Node<T> *tmp = Head;
				while (tmp->Next != _end)
				{
					if (tmp->content > tmp->Next->content)
					{
						nodeswap(tmp, tmp->Next);
						tmp = _end->Next;
						continue ;
					}
					tmp = tmp->Next;
				
				}
				Head = _end->Next;
				Tail = _end->Prev;
			}
			void    reverse()
			{
				if( Head == _end ) { return; }
				for(;;) {
					ft::swap (Head->Prev, Head->Next );
					Node<T>  *prev = Head->Prev;
					if (prev == _end ) { break; }
					Head = prev;
				}
				Tail = _end->Prev;
			}
			void merge( List& other )
			{
				Node<T> *tmp = Head;
				if (tmp == _end)
				{
					splice (iterator(tmp), other);
					return ;
				}
				while (tmp != _end)
				{
					if (other.Head->content < tmp->content)
					{
						if (other.Head == other._end)
							break;
						while (other.Head->content < tmp->content && other.Head != other._end)
							splice (iterator(tmp), other, iterator(other.Head));
					}
					else
						tmp = tmp->Next;
				}
			}
			void remove( const T& value )
			{
				Node<T> *tmp = Head;
				while (tmp != _end)
				{
					if (tmp->content == value)
					{
						Node<T> *t = tmp->Prev;
						erase(iterator(tmp));
						tmp = t->Next;
					}
					else
						tmp = tmp->Next;
				}
			}
			template< class UnaryPredicate >
			void remove_if( UnaryPredicate p )
			{
				Node<T> *tmp = Head;
				while (tmp != _end)
				{
					if (p(tmp->content))
					{
						Node<T> *t = tmp->Prev;
						erase(iterator(tmp));
						tmp = t->Next;
					}
					else
						tmp = tmp->Next;
				}
			}
			void unique()
			{
				Node<T> *tmp = Head;
				while (tmp != _end)
				{
					if (tmp->content == tmp->Next->content && tmp->Next != _end)
					{
						Node<T> *t = tmp->Prev;
						erase(iterator(tmp));
						tmp = t->Next;
					}
					else
						tmp = tmp->Next;
				}
			}
			template< class BinaryPredicate >
			void unique( BinaryPredicate p )
			{
				Node<T> *tmp = Head;
				while (tmp != _end)
				{
					if (p(tmp->content, tmp->Next->content) && tmp->Next != _end)
					{
						Node<T> *t = tmp->Prev;
						erase(iterator(tmp->Next));
						tmp = t->Next;
					}
					else
						tmp = tmp->Next;
				}
			}
			friend bool operator==( const List& lhs, const List& rhs )
			{
				iterator it = rhs.begin();
				for (iterator i = lhs.begin(); i != lhs.end(); i++)
				{
					if (*i != *it)
						return false;
					it++;
				}
				return true;
			}
			friend bool operator!=( const List& lhs, const List& rhs )
			{
				iterator it = rhs.begin();
				for (iterator i = lhs.begin(); i != lhs.end(); i++)
				{
					if (*i != *it)
						return true;
					it++;
				}
				return false;
			}
			friend bool operator<( const List& lhs, const List& rhs )
			{
				if (lhs.size() != rhs.size())
					return lhs.size() >= rhs.size();
				iterator it = rhs.begin();
				for (iterator i = lhs.begin(); i != lhs.end(); i++)
				{
					if (*i >= *it)
						return false;
					it++;
				}
				return true;
			}
			friend bool operator<=( const List& lhs, const List& rhs )
			{
				if (lhs.size() != rhs.size())
					return lhs.size() > rhs.size();
				iterator it = rhs.begin();
				for (iterator i = lhs.begin(); i != lhs.end(); i++)
				{
					if (*i > *it)
						return false;
					it++;
				}
				return true;
			}
			friend bool operator>( const List& lhs, const List& rhs )
			{
				if (lhs.size() != rhs.size())
					return lhs.size() <= rhs.size();
				iterator it = rhs.begin();
				iterator i = lhs.begin();
				for (; i != lhs.end(); i++)
				{
					if (*i <= *it)
						return false;
					it++;
				}
				return true;
			}
			friend bool operator>=( const List& lhs, const List& rhs )
			{
				if (lhs.size() != rhs.size())
					return lhs.size() < rhs.size();
				iterator it = rhs.begin();
				iterator i = lhs.begin();
				for (; i != lhs.end(); i++)
				{
					if (*i < *it)
						return false;
					it++;
				}
				return true;
			}
		};
};

#endif