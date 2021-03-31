/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <fbarbera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:55:42 by fbarbera          #+#    #+#             */
/*   Updated: 2021/03/31 18:48:56 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "list"
#include "iostream"
#include "list.hpp"
#include "unistd.h"

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
	{
	List<int> mylist;
	{
		List<int> list;
		list.insert(list.begin(), 3,3);
		List<int> list2;
		list2.insert(list2.begin(), 7,7);
		List<int>::iterator i = list2.begin();
		i++;
		List<int>::iterator i3 = list.begin();
		i3++;
		List<int>::iterator i2 = list2.end();
		i2--;
		list.splice(i3, list2, i);
		for (List<int>::iterator i = list.begin(); i != list.end(); i++)
			std::cout << *i << " ";
			std::cout << std::endl;
		for (List<int>::iterator i = list2.begin(); i != list2.end(); i++)
			std::cout << *i << " ";
			std::cout << std::endl;
	}

	mylist.insert(mylist.begin(), 5, 5);
	List<int> mylist2;
	mylist2.insert(mylist2.begin(), 4, 4);

	for (List<int>::iterator i = mylist2.begin(); i != mylist2.end(); i++)
		std::cout << *i << " ";
	std::cout << " list2" << std::endl;
	for (List<int>::iterator i = mylist.begin(); i != mylist.end(); i++)
		std::cout << *i << " ";
	std::cout << " list1" << std::endl;
	
	List<int>::iterator it = mylist2.begin();
	it++;
	it++;

	mylist2.splice(it, mylist);
	it = mylist2.begin();
	std::cout << *it++ << " ";
	*it = 2;
	std::cout << *it++ << " ";
	std::cout << *it++ << " ";
	std::cout << *it++ << " ";
	*it = 10;
	std::cout << *it++ << " ";
	std::cout << *it++ << " ";
	*it = 11;
	std::cout << *it++ << " ";
	std::cout << *it++ << " ";
	std::cout << *it++ << " ";
	std::cout << *it++ << " ";
	std::cout << *it++ << " ";
	std::cout << *it++ << " ";
	std::cout << *it-- << " qwert\n";
	// mylist.insert(mylist.begin(), 3, 3);
	mylist2.sort();
	mylist2.reverse();
	// mylist2.reverse();
	for (List<int>::iterator i = mylist2.begin(); i != mylist2.end(); i++)
		std::cout << *i << " ";
	std::cout <<  std::endl;
	for (List<int>::iterator i = mylist.begin(); i != mylist.end(); i++)
		std::cout << *i << " ";
	std::cout <<  std::endl;
	}
	// sleep(10);
	{


    std::list<int> list1;
	int a[5] = { 5,9,0,1,3 };
    std::list<int> list2;
	int b[5] = { 8,7,2,6,4 };
	list1.assign(a, a+5);
	list2.assign(b, b+5);
    // list1.sort();
    // list2.sort();
	std::cout << "______________________\n";
	for (std::list<int>::iterator i = list1.begin(); i != list1.end(); i++)
		std::cout << *i << " ";
	std::cout <<  std::endl;
	for (std::list<int>::iterator i = list2.begin(); i != list2.end(); i++)
		std::cout << *i << " ";
    std::cout <<  std::endl;
	list1.merge(list2);
    for (std::list<int>::iterator i = list1.begin(); i != list1.end(); i++)
		std::cout << *i << " ";
	std::cout <<  std::endl;
    for (std::list<int>::iterator i = list2.begin(); i != list2.end(); i++)
		std::cout << *i << " ";
	std::cout <<  std::endl;
	}
	{
    List<int> list1;
	int a[5] = { 5,9,0,1,3 };
    List<int> list2;
	int b[5] = { 8,7,2,6,4 };
	list1.assign(a, a+5);
	list2.assign(b, b+5);
    // list1.sort();
    // list2.sort();
	std::cout << "______________________\n";
	for (List<int>::iterator i = list1.begin(); i != list1.end(); i++)
		std::cout << *i << " ";
	std::cout <<  std::endl;
	for (List<int>::iterator i = list2.begin(); i != list2.end(); i++)
		std::cout << *i << " ";
    std::cout <<  std::endl;
	list1.merge(list2);
    for (List<int>::iterator i = list1.begin(); i != list1.end(); i++)
		std::cout << *i << " ";
	std::cout <<  std::endl;
    for (List<int>::iterator i = list2.begin(); i != list2.end(); i++)
		std::cout << *i << " ";
	std::cout <<  std::endl;
	}

	{
	std::list<int> alice;
	int a[3] = {1, 2, 10};
	std::list<int> bob;
	int b[4] = {1, 2, 9, 10};
	std::list<int> eve;
	int c[3] = {1, 2, 10};
	alice.assign(a, a+3);
	bob.assign(b, b+4);
	eve.assign(c,c+3);
	std::cout << std::boolalpha;

	// Compare non equal containers
	std::cout << "alice == bob returns " << (alice == bob) << '\n';
	std::cout << "alice != bob returns " << (alice != bob) << '\n';
	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';

	std::cout << '\n';

	// Compare equal containers
	std::cout << "alice == eve returns " << (alice == eve) << '\n';
	std::cout << "alice != eve returns " << (alice != eve) << '\n';
	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	}
	{
	List<int> alice;
	int a[3] = {1, 2, 10};
	List<int> bob;
	int b[4] = {1, 2, 9, 10};
	List<int> eve;
	int c[3] = {1, 2, 10};
	alice.assign(a, a+3);
	bob.assign(b, b+4);
	eve.assign(c,c+3);
	std::cout << std::boolalpha;
std::cout << '\n';
	// Compare non equal containers
	std::cout << "alice == bob returns " << (alice == bob) << '\n';
	std::cout << "alice != bob returns " << (alice != bob) << '\n';
	std::cout << "alice <  bob returns " << (alice < bob) << '\n';
	std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
	std::cout << "alice >  bob returns " << (alice > bob) << '\n';
	std::cout << "alice >= bob returns " << (alice >= bob) << '\n';

	std::cout << '\n';

	// Compare equal containers
	std::cout << "alice == eve returns " << (alice == eve) << '\n';
	std::cout << "alice != eve returns " << (alice != eve) << '\n';
	std::cout << "alice <  eve returns " << (alice < eve) << '\n';
	std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
	std::cout << "alice >  eve returns " << (alice > eve) << '\n';
	std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	}
	{
	List<int> l;
	
	int n[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 };
	
	l.assign(n, n + 11);

	for (List<int>::iterator i = l.begin(); i != l.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
    l.remove(100);
	l.unique();
	for (List<int>::iterator i = l.begin(); i != l.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	}
	{
	List<double> l;
	
	double n[8] = { 2.55, 3.15, 4.16, 4.17,
                          4.77, 12.66, 12.65, 13.59 };
	
	l.assign(n, n + 8);

	for (List<double>::iterator i = l.begin(); i != l.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	l.unique(compare);
	for (List<double>::iterator i = l.begin(); i != l.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	}
}