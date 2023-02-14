/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end(string).cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:30:53 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<std::string>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back("string " + tester::to_string(i));

	const NS::vector<std::string>	v2(v.begin(), v.end());
	{	
		NS::vector<std::string>::iterator		it = v.begin();
		NS::vector<std::string>::iterator		ite = v.end();
		NS::vector<std::string>::const_iterator	it2 = v.begin();
		NS::vector<std::string>::const_iterator	ite2 = v.begin();
		
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
		NS::vector<std::string>::const_iterator	it = v2.begin();
		NS::vector<std::string>::const_iterator	ite = v2.end();
		printVector(v);
		for (; it != ite; ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		printVector(v);
	}
}
