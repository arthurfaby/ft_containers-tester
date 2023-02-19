/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 16:52:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<int>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		v.push_back(i);
		std::cout << "Front : " << v.front() << std::endl;
	}
	printVector(v);

	const NS::vector<int>	v2(v.begin(), v.end());
	printVector(v2);
	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		std::cout << v2.at(i) << " ";
		std::cout << "Front : " << v2.front() << std::endl;
	}
	std::cout << std::endl;
	printVector(v2);

}
