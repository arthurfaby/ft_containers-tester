/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 10:59:50 by afaby            ###   ########.fr       */
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
		v.push_back(i);

	const NS::vector<int>	v2(v.begin(), v.end());
	{	
		NS::vector<int>::iterator		it = v.begin();
		NS::vector<int>::iterator		ite = v.end();
		NS::vector<int>::const_iterator	it2 = v.begin();
		NS::vector<int>::const_iterator	ite2 = v.begin();
		
		printVector(v);
		for (; it != ite; ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		printVector(v);
		for (; it2 != ite2; ++it2)
			std::cout << *it << " ";
		std::cout << std::endl;
		printVector(v);
	}
	{
		NS::vector<int>::const_iterator	it = v2.begin();
		NS::vector<int>::const_iterator	ite = v2.end();
		printVector(v);
		for (; it != ite; ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		printVector(v);
	}
}
