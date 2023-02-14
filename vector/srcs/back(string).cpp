/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back(string).cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:25:17 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<std::string>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		v.push_back("string " + tester::to_string(i));
		std::cout << "Back : " << v.back() << std::endl;
	}
	printVector(v);

	const NS::vector<std::string>	v2(v.begin(), v.end());
	printVector(v2);
	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		std::cout << v2.at(i) << " ";
		std::cout << "Back : " << v2.back() << std::endl;
	}
	std::cout << std::endl;
	printVector(v2);

}
