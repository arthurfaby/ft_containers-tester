/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend(string).cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:44:39 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<std::string>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back("string " + tester::to_string(i));

	const NS::vector<std::string>	v2(v.rbegin(), v.rend());
	{	
		NS::vector<std::string>::reverse_iterator		it = v.rbegin();
		NS::vector<std::string>::reverse_iterator		ite = v.rend();
		NS::vector<std::string>::const_reverse_iterator	it2 = v.rbegin();
		NS::vector<std::string>::const_reverse_iterator	ite2 = v.rbegin();
		
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
		NS::vector<std::string>::const_reverse_iterator	it = v2.rbegin();
		NS::vector<std::string>::const_reverse_iterator	ite = v2.rend();
		printVector(v);
		for (; it != ite; ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		printVector(v);
	}
}
