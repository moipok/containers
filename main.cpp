/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:55:42 by fbarbera          #+#    #+#             */
/*   Updated: 2021/03/16 01:37:27 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "list"
#include "iostream"
#include "list.hpp"

int main()
{
	std::list<std::string> list;
	List<std::string> f_list;
	
	f_list.push_back("Hello ");
	f_list.push_back("world");
	list.push_back("Hello ");
	list.push_back("world");
	std::cout << list.size() << std::endl;
	std::cout << f_list.size() << std::endl;
	std::cout << list.front() << list.back() << std::endl;
	std::cout << f_list.front() << f_list.back() << std::endl;
}