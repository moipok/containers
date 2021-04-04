/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <fbarbera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:47:26 by fbarbera          #+#    #+#             */
/*   Updated: 2021/04/04 20:20:23 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "list.hpp"

namespace ft
{
	template<class T> 
		class Stack
		{
		private:
			Node<T>	*Head;
			size_t _size;
		protected:
			Node<T>	*Get_node() const {return Head;}
		public:
			Stack() : Head(NULL), _size(0) {}
			Stack(Stack const &other)
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
			Stack &operator=(Stack const &other)
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
			~Stack() { while (_size) pop(); }
			void push(const T &value)
			{
				Node<T> *temp = new Node<T>;
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
					Head =  temp;
				}
			}
			const T &top() const { return (Head->content); }
			T &top() { return (Head->content);}
			size_t size() const { return _size; }
			bool empty() const { return _size==0;}
			void pop()
			{
				if (_size)
				{
					Node<T> *tmp = Head->Next;
					delete Head;
					Head = tmp;
					_size--;
				}
			}
			void swap( Stack& other )
			{
				ft::swap(this->_size, other._size);
				ft::swap(this->Head, other.Head);
			}
			friend bool operator==( const Stack& lhs, const Stack& rhs )
			{
				Node<T> *one =  lhs->Get_node();
				Node<T> *two =  rhs->Get_node();
				if (lhs->size() != rhs->size())
					return false;
				while (one)
				{
					if (one->content != two->content)
						return false;
					one = one->Next;
					two = two->Next;
				}
				return true;
			}
			friend bool operator!=( const Stack& lhs, const Stack& rhs )
			{
				return !(lhs == rhs);
			}
			friend bool operator>( const Stack& lhs, const Stack& rhs )
			{
				Node<T> *one =  lhs->Get_node();
				Node<T> *two =  rhs->Get_node();
				while (one)
				{
					if (two == NULL)
						return true;
					if (one->content < two->content)
						return false;
					else if (one->content > two->content)
						return true;
					one = one->Next;
					two = two->Next;
				}
				if (two != NULL)
					return false;
				return true;
			}
			friend bool operator>=( const Stack& one, const Stack& two )
			{
				return (one > two || one == two);
			}
			friend bool operator<( const Stack& one, const Stack& two )
			{
				return !(one >= two);
			}
			friend bool operator<=( const Stack& one, const Stack& two )
			{
				return !(one > two);
			}
		};
};

#endif