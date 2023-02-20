/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:41 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 13:09:05 by afaby            ###   ########.fr       */
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
void	printStack(NS::stack<T>& s)
{
	if (s.empty())
		return ;

	T	x = s.top();
	s.pop();
	printStack(s);
	std::cout << x << " ";
	s.push(x);
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
