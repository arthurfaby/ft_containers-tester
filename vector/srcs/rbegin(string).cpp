/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin(string).cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:44:27 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<std::string>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back("string " + tester::to_string(i));

	const NS::vector<std::string>	v2(v.begin(), v.end());
	{	
		NS::vector<std::string>::reverse_iterator		it = v.rbegin();
		NS::vector<std::string>::const_reverse_iterator	it2 = v.rbegin();
		std::cout << "rbegin() : " << *it << std::endl;
		std::cout << "rbegin() : " << *it2 << std::endl;
	}
	{
		NS::vector<std::string>::const_reverse_iterator	it = v2.rbegin();
		std::cout << "rbegin() : " << *it << std::endl;
	}
}
