/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:26:16 by fbarbera          #+#    #+#             */
/*   Updated: 2021/03/16 01:37:07 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <stddef.h>

template<class T> 
struct Node
{
	T		content;
	Node	*Next;
	Node	*Prev;
};

template<class T> 
	class List
	{
	private:
		Node<T>	*Head;
		Node<T>	*Tail;
	public:
		List() :Head(NULL), Tail(NULL) {};
		~List()
		{
			while (Head)
			{
				Tail = Head->Next;
				delete Head;
				Head = Tail;
			}
		}
		void push_back(T content)
		{
			Node<T> *temp = new Node<T>;
			temp->Next = NULL;
			temp->content = content;

			if (Head != NULL)
			{
				temp->Prev = Tail;
				Tail->Next = temp;
				Tail = temp;
			}
			else
			{
				temp->Prev = NULL;
				Head = Tail = temp;
			}
		}
		void push_front(T content)
		{
			Node<T>  *temp = new Node<T>;
			temp->Prev = NULL;
			temp->content = content;

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
		T	back()
		{
			return (Tail->content);
		}
		T	front()
		{
			return (Head->content);
		}
		size_t size()
		{
			Node<T>	*tmp;
			size_t	count = 0;
			tmp = Head;
			
			while (tmp)
			{
				tmp = tmp->Next;
				count++;
			}
			return count;
		}
	};


#endif