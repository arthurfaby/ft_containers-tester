/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator==.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:08:37 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 11:12:37 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<int>	v;
	NS::vector<int>	v2;
	NS::vector<int>	v3;

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		v.push_back(i * 2);
		v2.push_back(i * 3);
		v3.push_back(i * 2);
	}

	std::cout << (v == v3) << std::endl;
	std::cout << (v3 == v) << std::endl;
	std::cout << (v == v2) << std::endl;
	std::cout << (v2 == v) << std::endl;
	std::cout << (v2 == v3) << std::endl;
	std::cout << (v3 == v2) << std::endl;
}
