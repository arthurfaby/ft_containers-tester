/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator(string)>.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby >afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:08:37 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:39:57 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<std::string>	v;
	NS::vector<std::string>	v2;
	NS::vector<std::string>	v3;

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		v.push_back("string " + tester::to_string(i * 2));
		v2.push_back("string " + tester::to_string(i * 2));
		v3.push_back("string " + tester::to_string(i * 3));
	}

	std::cout << (v > v3) << std::endl;
	std::cout << (v3 > v) << std::endl;
	std::cout << (v > v2) << std::endl;
	std::cout << (v2 > v) << std::endl;
	std::cout << (v2 > v3) << std::endl;
	std::cout << (v3 > v2) << std::endl;
}
