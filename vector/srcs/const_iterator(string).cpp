/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator(string).cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 17:13:46 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	std::cout << "TESTING ON NON CONST VECTOR" << std::endl;
	NS::vector<std::string>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back("string " + tester::to_string(i));

	printVector(v);

	{
		NS::vector<std::string>::const_iterator	cit = v.begin();
		NS::vector<std::string>::const_iterator	cite = v.end();
	
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

		std::cout << (v.end() - cit) << std::endl;

		std::cout << cit[12] << std::endl;

		NS::vector<std::string>::const_iterator	other	= v.begin();
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

	std::cout << "TESTING ON CONST VECTOR" << std::endl;
	const NS::vector<std::string>	v2(v.begin(), v.end());
	printVector(v2);
	{


		NS::vector<std::string>::const_iterator	cit = v2.begin();
		NS::vector<std::string>::const_iterator	cite = v2.end();
	
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

		std::cout << (v2.end() - cit) << std::endl;

		std::cout << cit[12] << std::endl;

		NS::vector<std::string>::const_iterator	other	= v2.begin();
		std::cout << (other == cit) << std::endl;
		std::cout << (other == v2.begin()) << std::endl;
		std::cout << (other != cit) << std::endl;
		std::cout << (other != v2.begin()) << std::endl;
		std::cout << (other > cit) << std::endl;
		std::cout << (other > v2.begin()) << std::endl;
		std::cout << (other < cit) << std::endl;
		std::cout << (other < v2.begin()) << std::endl;
		std::cout << (other >= cit) << std::endl;
		std::cout << (other >= v2.begin()) << std::endl;
		std::cout << (other <= cit) << std::endl;
		std::cout << (other <= v2.begin()) << std::endl;
	}
}
