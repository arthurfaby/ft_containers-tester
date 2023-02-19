/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(string).cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:53:30 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:34:57 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<std::string>	v;

	printVector(v);
	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back("string " + tester::to_string(i * 2));
	printVector(v);
	v.insert(v.begin() + TEST_SIZE / 2, TEST_SIZE / 10, "42");
	printVector(v);

	NS::vector<std::string>	v2(v);

	printVector(v2);
	v.insert(v.begin() + 5, v2.begin() + 5, v2.end() - 4);
	printVector(v);
	printVector(v2);
	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.insert(v.begin(), v.at(i));
	printVector(v);

}
