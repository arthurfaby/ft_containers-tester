/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 11:01:15 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	std::cout << "TESTING ON NON CONST VECTOR" << std::endl;
	NS::vector<int>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(i);

	printVector(v);

	{
		NS::vector<int>::iterator	cit = v.begin();
		NS::vector<int>::iterator	cite = v.end();
	
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

		cit = cit - 100;
		std::cout << *cit << std::endl;
		cit = cit + 5;
		cit = 5 + cit;
		std::cout << *cit << std::endl;

		std::cout << (v.end() - cit) << std::endl;

		std::cout << cit[12] << std::endl;

		NS::vector<int>::iterator	other	= v.begin();
		std::cout << (other == cit) << std::endl;
		std::cout << (other == v.begin()) << std::endl;
		std::cout << (other != cit) << std::endl;
		std::cout << (other != v.begin()) << std::endl;
		std::cout << (other > cit) << std::endl;
		std::cout << (other > v.begin()) << std::endl;
		std::cout << (other < cit) << std::endl;
		std::cout << (other < v.begin()) << std::endl;
		std::cout << (other >= cit) << std::endl;
		std::cout << (other >= v.begin()) << std::endl;
		std::cout << (other <= cit) << std::endl;
		std::cout << (other <= v.begin()) << std::endl;
	}

}
