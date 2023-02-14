/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin(string).cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:25:49 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<std::string>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back("string " + tester::to_string(i));

	const NS::vector<std::string>	v2(v.begin(), v.end());
	{	
		NS::vector<std::string>::iterator		it = v.begin();
		NS::vector<std::string>::const_iterator	it2 = v.begin();
		std::cout << "begin() : " << *it << std::endl;
		std::cout << "begin() : " << *it2 << std::endl;
	}
	{
		NS::vector<std::string>::const_iterator	it = v2.begin();
		std::cout << "begin() : " << *it << std::endl;
	}
}
