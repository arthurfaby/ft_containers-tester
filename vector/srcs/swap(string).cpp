/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap(string).cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:00:09 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:46:03 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<std::string>	v;
	NS::vector<std::string>	v2;

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		v.push_back("string " + tester::to_string(i * 2));
		v2.push_back("string " + tester::to_string(i * 3));
	}
	printVector(v);
	printVector(v2);
	v.swap(v2);
	printVector(v);
	printVector(v2);
}
