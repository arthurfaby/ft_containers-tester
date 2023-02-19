/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity(string).cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:26:29 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif
int	main(void)
{
	NS::vector<std::string>	v;

	std::cout << "Capacity : " << v.capacity() << std::endl;
	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		v.push_back("string " + tester::to_string(i));
		std::cout << "Capacity : " << v.capacity() << std::endl;
	}

	printVector(v);
}
