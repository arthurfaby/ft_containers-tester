/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:41 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 13:37:05 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#ifndef NS
	# define NS std
	# include <stack>
#else
	# define NS ft
	# include "../../../stack.hpp"
#endif

template<class T>
void	printStackRec(NS::stack<T>& s)
{
	if (s.empty())
		return ;

	T	x = s.top();
	s.pop();
	printStackRec(s);
	std::cout << x << " ";
	s.push(x);
}


template<class T>
void	printStack(NS::stack<T>& s, const std::string& str)
{
	std::cout << "Printing stack " << str << " :" << std::endl;
	if (!s.empty())
		std::cout << "  - top : " << s.top() << std::endl;
	std::cout << "  - empty : " << s.empty() << std::endl;
	std::cout << "  - size : " << s.size() << std::endl;
	std::cout << "  - content : " << std::endl;
	printStackRec(s);
	std::cout << std::endl;
	std::cout << std::endl;
}
namespace tester
{

std::string	to_string(int i)
{
	std::stringstream	stream;

	stream << i;
	std::string	res;

	stream >> res;
	return (res);
}

#ifndef TEXT_SIZE
	#define TEST_SIZE 100
#endif

}
