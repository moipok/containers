/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <fbarbera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:55:42 by fbarbera          #+#    #+#             */
/*   Updated: 2021/04/07 20:13:23 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "list"
#include "iostream"
#include "list.hpp"
#include "unistd.h"
#include <stack>
#include "stack.hpp"
#include "queue.hpp"
#include "queue"
#include "vector"
#include "vector.hpp"
#include <map>
#include "map"
#include "map.hpp"

using namespace ft;

bool pppp(int n)
{
	return (n<3);
}

bool compare(double a, double b)
{
    return ((int)a == (int)b);
}

int main()
{
// 	{
// 	List<int> mylist;
// 	{
// 		List<int> list;
// 		list.insert(list.begin(), 3,3);
// 		List<int> list2;
// 		list2.insert(list2.begin(), 7,7);
// 		List<int>::iterator i = list2.begin();
// 		i++;
// 		List<int>::iterator i3 = list.begin();
// 		i3++;
// 		List<int>::iterator i2 = list2.end();
// 		i2--;
// 		list.splice(i3, list2, i);
// 		for (List<int>::iterator i = list.begin(); i != list.end(); i++)
// 			std::cout << *i << " ";
// 			std::cout << std::endl;
// 		for (List<int>::iterator i = list2.begin(); i != list2.end(); i++)
// 			std::cout << *i << " ";
// 			std::cout << std::endl;
// 	}

// 	mylist.insert(mylist.begin(), 5, 5);
// 	List<int> mylist2;
// 	mylist2.insert(mylist2.begin(), 4, 4);

// 	for (List<int>::iterator i = mylist2.begin(); i != mylist2.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout << " list2" << std::endl;
// 	for (List<int>::iterator i = mylist.begin(); i != mylist.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout << " list1" << std::endl;
	
// 	List<int>::iterator it = mylist2.begin();
// 	it++;
// 	it++;

// 	mylist2.splice(it, mylist);
// 	it = mylist2.begin();
// 	std::cout << *it++ << " ";
// 	*it = 2;
// 	std::cout << *it++ << " ";
// 	std::cout << *it++ << " ";
// 	std::cout << *it++ << " ";
// 	*it = 10;
// 	std::cout << *it++ << " ";
// 	std::cout << *it++ << " ";
// 	*it = 11;
// 	std::cout << *it++ << " ";
// 	std::cout << *it++ << " ";
// 	std::cout << *it++ << " ";
// 	std::cout << *it++ << " ";
// 	std::cout << *it++ << " ";
// 	std::cout << *it++ << " ";
// 	std::cout << *it-- << " qwert\n";
// 	// mylist.insert(mylist.begin(), 3, 3);
// 	mylist2.sort();
// 	mylist2.reverse();
// 	// mylist2.reverse();
// 	for (List<int>::iterator i = mylist2.begin(); i != mylist2.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout <<  std::endl;
// 	for (List<int>::iterator i = mylist.begin(); i != mylist.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout <<  std::endl;
// 	}
// 	{


//     std::list<int> list1;
// 	int a[5] = { 5,9,0,1,3 };
//     std::list<int> list2;
// 	int b[5] = { 8,7,2,6,4 };
// 	list1.assign(a, a+5);
// 	list2.assign(b, b+5);
//     // list1.sort();
//     // list2.sort();
// 	std::cout << "______________________\n";
// 	for (std::list<int>::iterator i = list1.begin(); i != list1.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout <<  std::endl;
// 	for (std::list<int>::iterator i = list2.begin(); i != list2.end(); i++)
// 		std::cout << *i << " ";
//     std::cout <<  std::endl;
// 	list1.merge(list2);
//     for (std::list<int>::iterator i = list1.begin(); i != list1.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout <<  std::endl;
//     for (std::list<int>::iterator i = list2.begin(); i != list2.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout <<  std::endl;
// 	}
// 	{
//     List<int> list1;
// 	int a[5] = { 5,9,0,1,3 };
//     List<int> list2;
// 	int b[5] = { 8,7,2,6,4 };
// 	list1.assign(a, a+5);
// 	list2.assign(b, b+5);
//     // list1.sort();
//     // list2.sort();
// 	std::cout << "______________________\n";
// 	for (List<int>::iterator i = list1.begin(); i != list1.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout <<  std::endl;
// 	for (List<int>::iterator i = list2.begin(); i != list2.end(); i++)
// 		std::cout << *i << " ";
//     std::cout <<  std::endl;
// 	list1.merge(list2);
//     for (List<int>::iterator i = list1.begin(); i != list1.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout <<  std::endl;
//     for (List<int>::iterator i = list2.begin(); i != list2.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout <<  std::endl;
// 	}
// 	{
// 	std::list<int> alice;
// 	int a[3] = {1, 2, 10};
// 	std::list<int> bob;
// 	int b[4] = {1, 2, 9, 10};
// 	std::list<int> eve;
// 	int c[3] = {1, 2, 10};
// 	alice.assign(a, a+3);
// 	bob.assign(b, b+4);
// 	eve.assign(c,c+3);
// 	std::cout << std::boolalpha;

// 	// Compare non equal containers
// 	std::cout << "alice == bob returns " << (alice == bob) << '\n';
// 	std::cout << "alice != bob returns " << (alice != bob) << '\n';
// 	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
// 	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
// 	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
// 	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';

// 	std::cout << '\n';

// 	// Compare equal containers
// 	std::cout << "alice == eve returns " << (alice == eve) << '\n';
// 	std::cout << "alice != eve returns " << (alice != eve) << '\n';
// 	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
// 	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
// 	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
// 	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
// 	}
// 	{
// 	List<int> alice;
// 	int a[3] = {1, 2, 10};
// 	List<int> bob;
// 	int b[4] = {1, 2, 9, 10};
// 	List<int> eve;
// 	int c[3] = {1, 2, 10};
// 	alice.assign(a, a+3);
// 	bob.assign(b, b+4);
// 	eve.assign(c,c+3);
// 	std::cout << std::boolalpha;
// std::cout << '\n';
// 	// Compare non equal containers
// 	std::cout << "alice == bob returns " << (alice == bob) << '\n';
// 	std::cout << "alice != bob returns " << (alice != bob) << '\n';
// 	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
// 	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
// 	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
// 	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';

// 	std::cout << '\n';

// 	// Compare equal containers
// 	std::cout << "alice == eve returns " << (alice == eve) << '\n';
// 	std::cout << "alice != eve returns " << (alice != eve) << '\n';
// 	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
// 	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
// 	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
// 	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
// 	}
// 	{
// 	List<int> l;
	
// 	int n[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 };
	
// 	l.assign(n, n + 11);

// 	for (List<int>::iterator i = l.begin(); i != l.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout << std::endl;
//     l.remove(100);
// 	l.unique();
// 	for (List<int>::iterator i = l.begin(); i != l.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout << std::endl;
// 	}
// 	{
	// List<double> l;
	
	// double n[8] = { -2.55, 3.15, 4.16, 4.17,
    //                       4.77, 12.66, 12.65, 13.59 };
	
	// l.assign(n, n + 8);

	// for (List<double>::const_iterator i = l.begin(); i != l.end(); i++)
	// {
	// 	std::cout << *i << " ";
	// }
	// std::cout << std::endl;
	// l.unique(compare);
	// for (List<double>::const_reverse_iterator i = l.rbegin(); i != l.rend(); i++)
	// {
	// 	std::cout << *i << " ";
	// }
	// std::cout << std::endl;
	// }
	// std::stack<int> stk2;
	
	// stk2.push(120);
	// stk2.push(121);
	
	// Stack<int> stl2;
	
	// stl2.push(120);
	// stl2.push(121);

	// std::stack<int> stk;
	// Stack<int> mystl(stl2);
	
	// stk.push(10);
	// std::cout << stk.empty() << std::endl;
	// stk.push(11);
	// stk.swap(stk2);
	// std::cout << stk.size() << std::endl;
	// std::cout << stk.top() << std::endl;
	// mystl.push(10);
	// std::cout << mystl.empty() << std::endl;
	// mystl.push(11);
	// std::cout << std::boolalpha;
	// // std::cout << (stl2 > mystl) << std::endl;
	// // mystl.pop();
	// for (; !mystl.empty(); mystl.pop())
    //     std::cout << mystl.top() << ' ';
	// std::queue<int> q;
	// q.push(2);
	// q.push(2);
	// q.push(3);
	// Queue<int> qq;
	// qq.push(1);
	// qq.push(2);
	// qq.push(4);
	// std::queue<int> q3;
	// q3.push(1);
	// q3.push(2);
	// q3.push(3);
	// std::cout << std::boolalpha;
	// std::cout << (q > q3) <<  std::endl;
	// std::queue<int> q1 =q;
	// Queue<int> qq1 = qq;
	// while (!q1.empty())
	// {
	// 	std::cout << q1.front() << " " << q1.back() << " - " << qq1.front() << " " << qq1.back() << std::endl;;
	// 	q1.pop();
	// 	qq1.pop();
	// }

	// std::vector<std::string> v;
	// Vector<std::string> vv;

	// vv.push_back("Hello");
	// vv.push_back("World");
	// vv.push_back("!");
	// vv.push_back("!");
	
	// v.push_back("Hello");
	// v.push_back("World");
	// v.push_back("!");
	// v.push_back("!");

	// v.pop_back();
	// v.pop_back();
	// v.pop_back();
	// v.pop_back();
	// vv.pop_back();
	// vv.pop_back();
	// vv.pop_back();
	// vv.pop_back();
	// v.pop_back();
	// vv.clear();
	// v.clear();
	// v.assign(5, "ooo");
	// vv.assign(5, "ooo");
	// v.push_back("!");
	// vv.push_back("!");
	// Vector<std::string> vv2;
	// std::vector<std::string> v2;
	// std::string array[3] = {"one", "two", "three"};
	// vv.assign(array, array + 3);
	// v.assign(array, array + 3);
	// v.push_back("!");
	// vv.push_back("!");
	// ft::swap(vv, vv2);
	// std::swap(v, v2);
	// ft::swap(vv, vv2);
	// std::swap(v, v2);
	// vv.push_back("Hello");
	// vv.push_back("World");
	// vv.push_back("!");
	// vv.push_back("1");
	
	// v.push_back("Hello");
	// v.push_back("World");
	// v.push_back("!");
	// v.push_back("1");
	
	// vv.push_back("2");
	// vv.push_back("3");
	// vv.push_back("4");
	// vv.push_back("5");
	
	// v.push_back("2");
	// v.push_back("3");
	// v.push_back("4");
	// v.push_back("5");
	// std::cout << std::endl;
	// std::vector<std::string>::iterator it = v.begin();
	// Vector<std::string>::iterator it2 = vv.begin();
	
	// std::cout << *v.erase(it + 1, it + 3) << std::endl;
	// std::cout << *vv.erase(it2 + 1, it2 + 3) << std::endl;
	// v.insert(v.end() - 3, 12, "nana");
	// vv.insert(vv.end() - 3, 12, "nana");
	// it2 = vv.begin();
	// it = v.begin();
	// vv.insert(it2 + 5, array, array + 3);
	// v.insert(it + 5, array, array + 3);
	// it2 = vv.begin();
	// it = v.begin();
	// v.reserve(10);
	// vv.reserve(10);
	// v2.reserve(100);
	// vv2.reserve(100);
	// v.at(5) = "wow";
	// vv.at(5) = "wow";
	// std::cout << v.at(5) << " - "		<< vv.at(5) << std::endl;
	// std::cout << v.empty() << " - " 	<< vv.empty() << std::endl;
	// std::cout << v.size() << " - "		<< vv.size() << std::endl;
	// std::cout << v.capacity() << " - "	<< vv.capacity() << std::endl;
	// std::cout << v.back() << " - "		<< vv.back()<< std::endl;
	// std::cout << v.front() << " - "		<< vv.front()<< std::endl;
	// std::vector<std::string>::reverse_iterator it4 = v.rbegin();
	// Vector<std::string>::reverse_iterator it5 = vv.rbegin();
	
	// std::string str[25];
	// size_t count = 0;
	// for (; it5 != vv.rend(); it5++)
	// {
	// 	std::cout << *it5 << " ";
	// 	str[count] = *it5;
	// 	count++;
	// }
	// std::cout << " - my" << std::endl;
	// Vector<std::string> vect(10, "111");
	// Vector<std::string>::iterator itvec = vect.begin();
	// for (; itvec != vect.end(); itvec++)
	// {
	// 	std::cout << *itvec << " ";
	// }
	// std::cout << " - my 2" << std::endl;


	
	// for (; it4 != v.rend(); it4++)
	// 	std::cout << *it4 << " ";
	// std::cout  << " - original" << std::endl;
	
	// {
    // Vector<int> alice;
	// int a[3] = {2, 2, 2};
	// alice.assign(a, a + 3);
    // Vector<int> bob;
	// int b[4] = {1, 1, 1, 1};
	// bob.assign(b, b + 4);
    // Vector<int> eve;
	// int c[3] = {1, 2, 3};
	// eve.assign(c, c+ 3);
    // std::cout << std::boolalpha;
	
    // // Compare non equal containers
    // std::cout << "alice == bob returns " << (alice == bob) << '\n';
    // std::cout << "alice != bob returns " << (alice != bob) << '\n';
    // std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    // std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    // std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    // std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    // std::cout << '\n';
 
    // // Compare equal containers
    // std::cout << "alice == eve returns " << (alice == eve) << '\n';
    // std::cout << "alice != eve returns " << (alice != eve) << '\n';
    // std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    // std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    // std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    // std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	// }
	
	// std::map<int, std::string> map;
	// std::pair<int, std::string> b(10, "qwerty");
	// map.insert(b);


	std::map<int, std::string> m;

	Map<int, std::string> mymap;
	std::pair<int, std::string> a9(2, "qwerty9");
	std::pair<int, std::string> a3(16, "qwerty3");
	std::pair<int, std::string> a4(24, "qwerty4");
	std::pair<int, std::string> a5(27, "qwerty5");
	std::pair<int, std::string> a1(1, "qwerty1");
	std::pair<int, std::string> a6(35, "qwerty6");
	std::pair<int, std::string> a8(99, "qwerty8");
	std::pair<int, std::string> a2(4, "qwerty2");
	std::pair<int, std::string> a7(60, "qwerty7");
	std::pair<int, std::string> a10(17, "qwert7y7");

	m.insert(a6);
	m.insert(a7);
	m.insert(a9);
	m.insert(a8);
	m.insert(a1);
	m.insert(a2);
	m.insert(a3);
	m.insert(a4);
	m.insert(a5);
	std::pair<std::map<int, std::string>::iterator,bool> in_it = m.insert(a10);
	std::cout << in_it.first->first << in_it.second << std::endl;

	

	mymap.insert(a6);
	mymap.insert(a7);
	mymap.insert(a9);
	mymap.insert(a8);
	mymap.insert(a1);
	mymap.insert(a2);
	mymap.insert(a3);

	mymap.insert(a4);
	mymap.insert(a5);
	mymap.insert(a10);
	std::cout << (m.upper_bound(27))->first << "______ " << std::endl;
	std::cout << (m.lower_bound(10))->first << "______ " << std::endl;	
	std::cout << (mymap.upper_bound(27))->first << "______ " << std::endl;
	std::cout << (mymap.lower_bound(10))->first << "______ " << std::endl;
		
		Map<int, std::string>::iterator it = mymap.begin();
	// mymap.erase(1);
	std::pair<Map<int, std::string>::iterator,bool> in_i = mymap.insert(a10);
	std::cout << in_i.first->first << in_i.second << std::endl;
	// mymap.erase(it, mymap.end());

	std::cout << mymap.empty() << " empty - size = " << mymap.size() << std::endl;
	
	it = mymap.begin();
	Map<int, std::string> mmap = mymap;
	it = mmap.begin();
	std::cout << (it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	mymap[777] = "12345";
	std::cout << mymap[777] << std::endl;
	mymap.print_three();
	// map.insert()
	// mymap.~Map();
	// sleep(10);


  std::pair<Map<int , std::string>::iterator,Map<int , std::string>::iterator> ret;
  ret = mymap.equal_range(17);

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

}