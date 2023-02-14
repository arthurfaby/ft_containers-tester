/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 11:30:28 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<int>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(i);

	const NS::vector<int>	v2(v.rbegin(), v.rend());
	{	
		NS::vector<int>::reverse_iterator		it = v.rbegin();
		NS::vector<int>::reverse_iterator		ite = v.rend();
		NS::vector<int>::const_reverse_iterator	it2 = v.rbegin();
		NS::vector<int>::const_reverse_iterator	ite2 = v.rbegin();
		
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
		NS::vector<int>::const_reverse_iterator	it = v2.rbegin();
		NS::vector<int>::const_reverse_iterator	ite = v2.rend();
		printVector(v);
		for (; it != ite; ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		printVector(v);
	}
}
