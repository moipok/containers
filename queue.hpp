/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <fbarbera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:24:23 by fbarbera          #+#    #+#             */
/*   Updated: 2021/04/01 16:49:32 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP
# include "list.hpp"

namespace ft
{
	template<class T> 
		class Queue
		{
		private:
			Node<T>	*Head;
			Node<T>	*Tail;
			size_t _size;
		protected:
			Node<T>	*Get_node() const {return Tail;}
		public:
			Queue() : Head(NULL), _size(0) {}
			Queue(Queue const &other)
			{
				_size = 0;
				Node<T> *tmp = other.Head;
				while (tmp->Next)
					tmp = tmp->Next;
				Head = NULL;
				while (tmp)
				{
					push(tmp->content);
					tmp = tmp->Prev;
				}
			}
			Queue &operator=(Queue const &other)
			{
				while (_size) pop();
				Node<T> *tmp = other.Head;
				while (tmp->Next)
					tmp = tmp->Next;
				Head = NULL;
				while (tmp)
				{
					push(tmp->content);
					tmp = tmp->Prev;
				}
				return *this;
			}
			~Queue() { while (_size) pop(); }
			void push(const T &value)
			{
				Node<T>  *temp = new Node<T>;
				temp->Prev = NULL;
				temp->content = value;
				_size++;
				if (Head != NULL)
				{
					temp->Next = Head;
					Head->Prev = temp;
					Head = temp;
				}
				else
				{
					temp->Next = NULL;
					Head = Tail = temp;
				}
			}
			const T &back() const { return (Head->content); }
			T &back() { return (Head->content);}
			const T &front() const { return (Tail->content); }
			T &front() { return (Tail->content);}
			size_t size() const { return _size; }
			bool empty() const { return _size==0;}
			void pop()
			{
				if (_size)
				{
					Node<T> *tmp = Tail->Prev;
					delete Tail;
					Tail = tmp;
					_size--;
				}
			}
			void swap( Queue& other )
			{
				ft::swap(this->_size, other._size);
				ft::swap(this->Head, other.Head);
			}
			friend bool operator==( const Queue& lhs, const Queue& rhs )
			{
				Node<T> *one =  lhs->Get_node();
				Node<T> *two =  rhs->Get_node();
				if (lhs->size() != rhs->size())
					return false;
				while (one)
				{
					if (one->content != two->content)
						return false;
					one = one->Prev;
					two = two->Prev;
				}
				return true;
			}
			friend bool operator!=( const Queue& lhs, const Queue& rhs )
			{
				Node<T> *one =  lhs->Get_node();
				Node<T> *two =  rhs->Get_node();
				if (lhs->size() != rhs->size())
					return true;
				while (one)
				{
					if (one->content != two->content)
						return true;
					one = one->Prev;
					two = two->Prev;
				}
				return false;
			}
			friend bool operator>( const Queue& lhs, const Queue& rhs )
			{
				Node<T> *one =  lhs->Get_node();
				Node<T> *two =  rhs->Get_node();
				if (lhs->size() > rhs->size())
					return true;
				else if (lhs->size() < rhs->size())
					return false;
				while (one)
				{
					if (one->content <= two->content)
						return false;
					one = one->Prev;
					two = two->Prev;
				}
				return true;
			}
			friend bool operator>=( const Queue& lhs, const Queue& rhs )
			{
				Node<T> *one =  lhs->Get_node();
				Node<T> *two =  rhs->Get_node();
				if (lhs->size() > rhs->size())
					return true;
				else if (lhs->size() < rhs->size())
					return false;
				while (one)
				{
					if (one->content < two->content)
						return false;
					one = one->Prev;
					two = two->Prev;
				}
				return true;
			}
			friend bool operator<( const Queue& lhs, const Queue& rhs )
			{
				Node<T> *one =  lhs->Get_node();
				Node<T> *two =  rhs->Get_node();
				if (lhs->size() < rhs->size())
					return true;
				else if (lhs->size() > rhs->size())
					return false;
				while (one)
				{
					if (two->content <= one->content)
						return false;
					one = one->Prev;
					two = two->Prev;
				}
				return true;
			}
			friend bool operator<=( const Queue& lhs, const Queue& rhs )
			{
				Node<T> *one =  lhs->Get_node();
				Node<T> *two =  rhs->Get_node();
				if (lhs->size() < rhs->size())
					return true;
				else if (lhs->size() > rhs->size())
					return false;
				while (one)
				{
					if (two->content < one->content)
						return false;
					one = one->Prev;
					two = two->Prev;
				}
				return true;
			}
		};
};

#endif