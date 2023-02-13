/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/13 18:29:58 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<int>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(i);

	printVector(v);
	for (size_t i = 0; i < TEST_SIZE; ++i)
		std::cout << v.at(i) << " ";
	std::cout << std::endl;
	printVector(v);

	const NS::vector<int>	v2(v.begin(), v.end());
	printVector(v2);
	for (size_t i = 0; i < TEST_SIZE; ++i)
		std::cout << v2.at(i) << " ";
	std::cout << std::endl;
	printVector(v2);

	try {
		std::cout << "TRYING AT OUT OF RANGE POSITIVE" << std::endl;
		v.at(TEST_SIZE + 5);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "TRYING AT OUT OF RANGE NEGATIVE" << std::endl;
		v.at(-12);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
