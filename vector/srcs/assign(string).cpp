/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign(string).cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:20 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 14:18:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"
#include <list>

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<std::string>	v(10);

	printVector(v);

	v.assign(120, "string 42");

	printVector(v);


	std::list<std::string>	l;

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		l.push_back("string " + tester::to_string(i));
	}
	v.assign(l.begin(), l.end());

	printVector(v);

	return (0);
}
