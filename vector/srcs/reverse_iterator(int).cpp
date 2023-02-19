/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 11:06:02 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	std::cout << "TESTING ON NON CONST VECTOR" << std::endl;
	NS::vector<int>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(i);

	printVector(v);

	{
		NS::vector<int>::reverse_iterator	cit = v.rbegin();
		NS::vector<int>::reverse_iterator	cite = v.rend();
	
		for (; cit != cite; ++cit)
			std::cout << *cit << " "; 
		std::cout << std::endl;

		--cit;
		cit--;
		std::cout << *cit << std::endl;

		cit -= 50;
		std::cout << *cit << std::endl;
		++cit;
		cit++;
		std::cout << *cit << std::endl;

		cit += 2;
		std::cout << *cit << std::endl;

		cit = cit - 2;
		std::cout << *cit << std::endl;
		cit = cit + 5;
		cit = 5 + cit;
		std::cout << *cit << std::endl;

		std::cout << (v.rend() - cit) << std::endl;

		std::cout << cit[12] << std::endl;

		NS::vector<int>::reverse_iterator	other	= v.rbegin();
		std::cout << (other == cit) << std::endl;
		std::cout << (other == v.rbegin()) << std::endl;
		std::cout << (other != cit) << std::endl;
		std::cout << (other != v.rbegin()) << std::endl;
		std::cout << (other > cit) << std::endl;
		std::cout << (other > v.rbegin()) << std::endl;
		std::cout << (other < cit) << std::endl;
		std::cout << (other < v.rbegin()) << std::endl;
		std::cout << (other >= cit) << std::endl;
		std::cout << (other >= v.rbegin()) << std::endl;
		std::cout << (other <= cit) << std::endl;
		std::cout << (other <= v.rbegin()) << std::endl;
	}

}
