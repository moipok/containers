/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <fbarbera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:49:59 by fbarbera          #+#    #+#             */
/*   Updated: 2021/04/07 20:11:06 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{


template <class Key> 
struct less
{
  bool operator() (const Key& x, const Key& y) const {return x<y;}
};


template < class Key, class T, class Compare = less<Key> >
class Map
{
private:
	typedef std::pair<const Key, T>	value_type;
	enum COLOR {Red, Black};
	
	class			tree_node {
	public:
		tree_node(value_type const &data) : data(data) {
			left = NULL;
			right = NULL;
			parent = NULL;
			color = Red;
		}
		value_type			data;
		struct tree_node	*right;
		struct tree_node	*left;
		struct tree_node	*parent;
		enum COLOR			color;
	};
	
	typedef struct		red_black_tree {
		tree_node		*root;
		tree_node		*NIL;
	}					red_black_tree;
	
	tree_node*			new_tree_node(value_type &data) {
		tree_node* n = new tree_node(data);
		return n;
	}
	typedef size_t		size_type;
	typedef Key			key_type;
	red_black_tree		*t;
	size_t				_size;
	public:
		class iterator
		{
		protected:
		tree_node			*Head;
		red_black_tree		*t;
		friend class Map;
		tree_node	*Get_node() const {return Head;}
		tree_node *ft_min() const
		{
			tree_node *tmp = t->root;
			if (tmp == t->NIL)
				return tmp;
			while (tmp->left != t->NIL)
				tmp = tmp->left;
			return tmp;
		}
		tree_node *ft_max() const
		{
			tree_node *tmp = t->root;
			if (tmp == t->NIL)
				return tmp;
			while (tmp->right != t->NIL)
				tmp = tmp->right;
			return tmp;
		}
		void next()
		{
			tree_node *max = ft_max();
			tree_node *tmp = Head;
			if (tmp == t->NIL)
				Head = ft_min();
			else if (tmp->right != t->NIL)
			{
				tmp = tmp->right;
				while (tmp->left != t->NIL)
					tmp = tmp->left;
				Head = tmp;
			}
			else if (tmp == max)
				Head =  t->NIL;
			else if (tmp == tmp->parent->left)
				Head = tmp->parent;
			else
			{
				while (tmp->parent->right == tmp)
					tmp = tmp->parent;
				Head = tmp->parent;
			}
		}
		void prev()
		{
			tree_node *min = ft_min();
			tree_node *tmp = Head;
			if (tmp == t->NIL)
				Head = ft_max();
			else if (tmp->left != t->NIL)
			{
				tmp = tmp->left;
				while (tmp->right != t->NIL)
					tmp = tmp->right;
				Head = tmp;
			}
			else if (tmp == min)
				Head =  t->NIL;
			else if (tmp == tmp->parent->right)
				Head = tmp->parent;
			else
			{
				while (tmp->parent->left == tmp)
					tmp = tmp->parent;
				Head = tmp->parent;
			}
		}
		public:
		iterator(red_black_tree *t, tree_node *Head) : Head(Head) , t(t) {}
		iterator(iterator const &other) : Head(other.Get_node()), t(other.t) {}
		iterator() {}
		virtual ~iterator() {}
		value_type *operator->() { return &(Head->data); }
		value_type &operator*() const { return (Head->data); }
		iterator &operator++() { next() ; return *this;}
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp;}
		iterator &operator--() { prev(); return *this;}
		iterator operator--(int) { iterator tmp = *this; --(*this); return tmp;}

		friend bool operator== (const iterator& a, const iterator& b) { return a.operator*() == b.operator*(); };
		friend bool operator!= (const iterator& a, const iterator& b) { return a.operator*() != b.operator*(); };
	};
	class const_iterator : public iterator
	{
	public:
		const_iterator() : iterator() {}
		// const_iterator(const const_iterator &other) : iterator(other) {}
		const_iterator(const iterator &other) : iterator(other) {}
		// const_iterator& operator=(const_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
		const value_type *operator->() const { return &(this->Head->data); }
		const value_type &operator*() const { return (this->Head->data); }
	};
		class reverse_iterator
		{
		protected:
		tree_node			*Head;
		red_black_tree		*t;
		friend class Map;
		tree_node	*Get_node() const {return Head;}
		tree_node *ft_min() const
		{
			tree_node *tmp = t->root;
			if (tmp == t->NIL)
				return tmp;
			while (tmp->left != t->NIL)
				tmp = tmp->left;
			return tmp;
		}
		tree_node *ft_max() const
		{
			tree_node *tmp = t->root;
			if (tmp == t->NIL)
				return tmp;
			while (tmp->right != t->NIL)
				tmp = tmp->right;
			return tmp;
		}
		void next()
		{
			tree_node *max = ft_max();
			tree_node *tmp = Head;
			if (tmp == t->NIL)
				Head = ft_min();
			else if (tmp->right != t->NIL)
			{
				tmp = tmp->right;
				while (tmp->left != t->NIL)
					tmp = tmp->left;
				Head = tmp;
			}
			else if (tmp == max)
				Head =  t->NIL;
			else if (tmp == tmp->parent->left)
				Head = tmp->parent;
			else
			{
				while (tmp->parent->right == tmp)
					tmp = tmp->parent;
				Head = tmp->parent;
			}
		}
		void prev()
		{
			tree_node *min = ft_min();
			tree_node *tmp = Head;
			if (tmp == t->NIL)
				Head = ft_max();
			else if (tmp->left != t->NIL)
			{
				tmp = tmp->left;
				while (tmp->right != t->NIL)
					tmp = tmp->right;
				Head = tmp;
			}
			else if (tmp == min)
				Head =  t->NIL;
			else if (tmp == tmp->parent->right)
				Head = tmp->parent;
			else
			{
				while (tmp->parent->left == tmp)
					tmp = tmp->parent;
				Head = tmp->parent;
			}
		}
		public:
		reverse_iterator(red_black_tree *t, tree_node *Head) : Head(Head) , t(t) {}
		reverse_iterator(reverse_iterator const &other) : Head(other.Get_node()), t(other.t) {}
		reverse_iterator() {}
		virtual ~reverse_iterator() {}
		value_type *operator->() { return &(Head->data); }
		value_type &operator*() const { return (Head->data); }
		reverse_iterator &operator++() { prev() ; return *this;}
		reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp;}
		reverse_iterator &operator--() { next(); return *this;}
		reverse_iterator operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp;}

		friend bool operator== (const reverse_iterator& a, const reverse_iterator& b) { return a.operator*() == b.operator*(); };
		friend bool operator!= (const reverse_iterator& a, const reverse_iterator& b) { return a.operator*() != b.operator*(); };
	};
	class const_reverse_iterator : public reverse_iterator
	{
	public:
		const_reverse_iterator() : reverse_iterator() {}
		// const_reverse_iterator(const const_reverse_iterator &other) : reverse_iterator(other) {}
		const_reverse_iterator(const reverse_iterator &other) : reverse_iterator(other) {}
		// const_reverse_iterator& operator=(const_reverse_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
		const value_type *operator->() const { return &(this->Head->data); }
		const value_type &operator*() const { return (this->Head->data); }
	};
	template< class InputIt >
	Map( InputIt first, InputIt last, const Compare& comp = Compare(), typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
	{
		ft_red_black_tree();
		_size = 0;
		insert(first, last);
	}
	Map() {
		ft_red_black_tree();
		_size = 0;
	}
	Map(const Compare& comp) {
		ft_red_black_tree();
		_size = 0;
	}
	Map( const Map& other )
	{
		ft_red_black_tree();
		_size = 0;
		insert(other.begin(), other.end());
	}
	Map& operator=( const Map& other )
	{
		clear();
		insert(other.begin(), other.end());
		return *this;
	}
	~Map() {
		clear();
		delete t->NIL;
		delete t;
	}
	T& operator[]( const Key& key )
	{
		return insert(std::make_pair(key, T())).first->second;
	}
	iterator begin() { return iterator(t, ft_min());}
	iterator end() { return iterator(t, t->NIL);}
	const_iterator begin() const { return iterator(t, ft_min());}
	const_iterator end() const { return iterator(t, t->NIL);}
	reverse_iterator rbegin() { return reverse_iterator(t, ft_min());}
	reverse_iterator rend() { return reverse_iterator(t, t->NIL);}
	const_reverse_iterator rbegin() const { return reverse_iterator(t, ft_min());}
	const_reverse_iterator rend() const { return reverse_iterator(t, t->NIL);}
	void clear()
	{
		clear(t, t->root);
		_size = 0;
		t->root = t->NIL;
	}
	void clear(red_black_tree *tr, tree_node *n)
	{
		if (n != tr->NIL) {
			clear(tr, n->left);
			tree_node *m = n->right;
			delete n;
			clear(tr, m);
		}
	}
	bool empty() const { return _size == 0; }
	size_type size() const { return _size;}
	size_t max_size() const { return (std::numeric_limits<size_t>::max() / sizeof(tree_node)); }
	std::pair<iterator, bool>  insert( const value_type& value )
	{
		std::pair<iterator, bool> p;
		if ((p.first = find(value.first)) != end())
		{
			p.second = 0;
			return p;
		} 
		tree_node *node = new tree_node(value);
		_size++;
		insert(t, node);
		p.first = iterator(t, node);
		p.second = 1;
		return p;
	}
	iterator insert( iterator hint, const value_type& value )
	{
		hint++;
		return (insert(value));
	}
	template< class InputIt >
	void insert( InputIt first, InputIt last , typename enable_if<!std::numeric_limits<InputIt>::is_specialized>::type * = 0)
	{
		size_t n = 0;
		for (InputIt it = first; it != last; it++)
			n++;
		for (;n;n--)
		{
			insert(*first);
			first++;
		}
	}
	size_type count( const Key& key ) const
	{
		iterator it = begin();
		for (; it != end(); it++)
		{
			if (it->first == key)
				return 1;
		}
		return 0;
	}
	
	
		void print_three()
		{
			print(t->root, 4);
		}
	
		void print(tree_node* root, int deep)
		{
			if (root != this->t->NIL) {
				print(root->right, deep + 1);
				if (root->color == Black)
					std::cout << "\e[34m";
				else if (root->color == Red)
					std::cout << "\e[33m";
				for (int i = 0; i < deep; i++)
					std::cout << "    ";
				if (root != this->t->NIL)
					std::cout << root->data.first << "\e[0m" << "\n";
				print(root->left, deep + 1);
			}
			std::cout << "\e[0m";
		}

	iterator find( const Key& key )
	{
		iterator it = begin();
		for (; it != end(); it++)
		{
			if (it->first == key)
				return it;
		}
		return it;
	}
	const_iterator find( const Key& key ) const
	{
		const_iterator it = begin();
		for (; it != end(); it++)
		{
			if (it->first == key)
				return it;
		}
		return it;
	}
	void erase( iterator pos )
	{
		tree_node *del = ft_count(pos->first);
		if (del == NULL)
			return ;
		rb_delete(t, del);
		_size--;
	}
	void erase( iterator first, iterator last )
	{
		while (first != last)
		{
			erase(first);
			first++;
		}
	}
	size_type erase( const key_type& key )
	{
		tree_node *del = ft_count(key);
		if (del == NULL)
			return 0;
		rb_delete(t, del);
		_size--;
		return 1;
	}

	void swap( Map& other )
	{
		ft::swap(this->t, other.t);
		ft::swap(this->_size, other._size);
	}

	void print1()
	{
		inorder(t, t->root);
	}
	iterator lower_bound (const key_type& k)
	{
		iterator it = begin();
		while (it != end() && k > it->first)
			it++;
		return it;
	}
	const_iterator lower_bound (const key_type& k) const
	{
		const_iterator it = begin();
		while (it != end() && k > it->first)
			it++;
		return it;
	}
	iterator upper_bound (const key_type& k)
	{
		iterator it = begin();
		while (it != end() && k >= it->first)
			it++;
		return it;
	}
	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator it = begin();
		while (it != end() && k >= it->first)
			it++;
		return it;	
	}
	std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		const_iterator a = lower_bound(k);
		const_iterator b = upper_bound(k);
		return std::make_pair(a, b);
	}
	std::pair<iterator,iterator>             equal_range (const key_type& k)
	{
		iterator a = lower_bound(k);
		iterator b = upper_bound(k);
		return std::make_pair(a, b);
	}
private:
	tree_node *ft_min() const
	{
		tree_node *tmp = t->root;
		if (tmp == t->NIL)
			return tmp;
		while (tmp->left != t->NIL)
			tmp = tmp->left;
		return tmp;
	}
	tree_node *ft_max()
	{
		tree_node *tmp = t->root;
		if (tmp == t->NIL)
			return tmp;
		while (tmp->right != t->NIL)
			tmp = tmp->right;
		return tmp;
	}
	tree_node *ft_count( const Key& key )
	{
		tree_node* y = t->NIL;
		tree_node* temp = t->root;
		while (temp != t->NIL) {
			y = temp;
			if (key < temp->data.first)
				temp = temp->left;
			else if (key > temp->data.first)
				temp = temp->right;
			else
				return temp;
		}
		return NULL;
	}
	void	ft_red_black_tree()
	{
		t = new red_black_tree;
		tree_node *nil_node = new tree_node(value_type());
		nil_node->left = NULL;
		nil_node->right = NULL;
		nil_node->parent = NULL;
		nil_node->color = Black;
		t->NIL = nil_node;
		t->root = t->NIL;
	}
	void left_rotate(red_black_tree *t, tree_node *x) {
		tree_node *y = x->right;
		x->right = y->left;
		if (y->left != t->NIL)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == t->NIL) //x is root
			t->root = y;
		else if (x == x->parent->left) //x is left child
			x->parent->left = y;
		else //x is right child
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	void right_rotate(red_black_tree *t, tree_node *x) {
		tree_node *y = x->left;
		x->left = y->right;
		if (y->right != t->NIL)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == t->NIL) //x is root
			t->root = y;
		else if (x == x->parent->right) //x is left child
			x->parent->right = y;
		else //x is right child
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	void insertion_fixup(red_black_tree *t, tree_node *z) {
		while (z->parent->color == Red)
		{
			if (z->parent == z->parent->parent->left) { //z.parent is the left child
				tree_node *y = z->parent->parent->right; //uncle of z
				if (y->color == Red) { //case 1
					z->parent->color = Black;
					y->color = Black;
					z->parent->parent->color = Red;
					z = z->parent->parent;
				}
				else { //case2 or case3
					if (z == z->parent->right) { //case2
						z = z->parent; //marked z.parent as new z
						left_rotate(t, z);
					}
					//case3
					z->parent->color = Black; //made parent black
					z->parent->parent->color = Red; //made parent red
					right_rotate(t, z->parent->parent);
				}
			}
			else { //z.parent is the right child
				tree_node *y = z->parent->parent->left; //uncle of z

				if (y->color == Red) {
					z->parent->color = Black;
					y->color = Black;
					z->parent->parent->color = Red;
					z = z->parent->parent;
				}
				else {
					if (z == z->parent->left) {
						z = z->parent; //marked z.parent as new z
						right_rotate(t, z);
					}
					z->parent->color = Black; //made parent black
					z->parent->parent->color = Red; //made parent red
					left_rotate(t, z->parent->parent);
				}
			}
		}
		t->root->color = Black;
	}

	void insert(red_black_tree *t, tree_node *z) {
		tree_node* y = t->NIL; //variable for the parent of the added node
		tree_node* temp = t->root;
		while (temp != t->NIL) {
			y = temp;
			if (z->data < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		z->parent = y;

		if (y == t->NIL) //newly added node is root
			t->root = z;
		else if (z->data < y->data) //data of child is less than its parent, left child
			y->left = z;
		else
			y->right = z;

		z->right = t->NIL;
		z->left = t->NIL;

		insertion_fixup(t, z);
	}

	void rb_transplant(red_black_tree *t, tree_node *u, tree_node *v) {
		if (u->parent == t->NIL)
			t->root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	tree_node* minimum(red_black_tree *t, tree_node *x) {
		while(x->left != t->NIL)
			x = x->left;
		return x;
	}

	void rb_delete_fixup(red_black_tree *t, tree_node *x) {
		while(x != t->root && x->color == Black) {
			if (x == x->parent->left) {
				tree_node *w = x->parent->right;
				if (w->color == Red) {
					w->color = Black;
					x->parent->color = Red;
					left_rotate(t, x->parent);
					w = x->parent->right;
				}
				if (w->left->color == Black && w->right->color == Black) {
					w->color = Red;
					x = x->parent;
				}
				else {
					if (w->right->color == Black) {
						w->left->color = Black;
						w->color = Red;
						right_rotate(t, w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = Black;
					w->right->color = Black;
					left_rotate(t, x->parent);
					x = t->root;
				}
			}
			else {
				tree_node *w = x->parent->left;
				if	(w->color == Red) {
					w->color = Black;
					x->parent->color = Red;
					right_rotate(t, x->parent);
					w = x->parent->left;
				}
				if (w->right->color == Black && w->left->color == Black) {
					w->color = Red;
					x = x->parent;
				}
				else {
					if(w->left->color == Black) {
						w->right->color = Black;
						w->color = Red;
						left_rotate(t, w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = Black;
					w->left->color = Black;
					right_rotate(t, x->parent);
					x = t->root;
				}
			}
		}
		x->color = Black;
	}

	void rb_delete(red_black_tree *t, tree_node *z) {
		tree_node *y = z;
		tree_node *x;
		enum COLOR y_orignal_color = y->color;
		if (z->left == t->NIL) {
			x = z->right;
			rb_transplant(t, z, z->right);
		}
		else if (z->right == t->NIL) {
			x = z->left;
			rb_transplant(t, z, z->left);
		}
		else {
			y = minimum(t, z->right);
			y_orignal_color = y->color;
			x = y->right;
			if (y->parent == z)
				x->parent = z;
			else {
				rb_transplant(t, y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			rb_transplant(t, z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		if (y_orignal_color == Black)
			rb_delete_fixup(t, x);
	}

	void inorder(red_black_tree *t, tree_node *n) {
		if (n != t->NIL) {
			inorder(t, n->left);
			std::cout <<  n->data.first << std::endl;
			inorder(t, n->right);
		}
	}
};

template < class Key, class T, class Compare >
void swap( Map<Key,T,Compare>& lhs, Map<Key,T,Compare>& rhs )
{
	lhs.swap(rhs);   
}

// template < class Key, class T>
// class pair
// {
// public:
// 	Key	first;
// 	T	second;
// 	pair(Key key, T value) : first(key), second(value) {}
// 	friend bool operator==( const pair& one, const pair& two) { return (one.first == two.first); }
// 	friend bool operator!=( const pair& one, const pair& two) { return (one.first != two.first); }
// 	friend bool operator>( const pair& one, const pair& two) { return (one.first > two.first); }
// 	friend bool operator>=( const pair& one, const pair& two) { return (one.first >= two.first); }
// 	friend bool operator<( const pair& one, const pair& two) { return (one.first < two.first); }
// 	friend bool operator<=( const pair& one, const pair& two) { return (one.first <= two.first); }
// 	pair() {}
// 	pair( const pair<Key, T>& other ) : first(other.first) { second = other.second; }
// 	pair& operator=( const pair& other ) { first = other.first; second = other.second; return *this; }
// private:
// };

}
