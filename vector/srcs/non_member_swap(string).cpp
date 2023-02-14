/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_swap(string).cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:00:09 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:36:24 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#define TEST_SIZE 10000

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
	NS::swap(v, v2);
	printVector(v);
	printVector(v2);
}
