/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:41 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 18:49:08 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#ifndef NS
	# define NS std
	# include <vector>
#else
	# define NS ft
	# include "../../../vector.hpp"
#endif

template<class V>
void	printVector(const NS::vector<V>& vec)
{
	std::cout << "########## CONTENT ##########" << std::endl;
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << " ############################" << std::endl;
	std::cout << " Size : " << vec.size() << std::endl;
	/* std::cout << " Capacity : " << vec.capacity() << std::endl; */
	std::cout << " Max_size : " << vec.max_size() << std::endl;
	if (vec.size() > 0)
	{
		std::cout << " Front : " << vec.front() << std::endl;
		std::cout << " Back : " << vec.back() << std::endl;
	}
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

}
