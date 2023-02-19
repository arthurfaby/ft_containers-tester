/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/13 18:32:57 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<int>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(i);

	const NS::vector<int>	v2(v.begin(), v.end());
	{	
		NS::vector<int>::iterator		it = v.begin();
		NS::vector<int>::const_iterator	it2 = v.begin();
		std::cout << "begin() : " << *it << std::endl;
		std::cout << "begin() : " << *it2 << std::endl;
	}
	{
		NS::vector<int>::const_iterator	it = v2.begin();
		std::cout << "begin() : " << *it << std::endl;
	}
}
