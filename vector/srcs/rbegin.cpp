/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 11:32:36 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<int>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(i);

	const NS::vector<int>	v2(v.begin(), v.end());
	{	
		NS::vector<int>::reverse_iterator		it = v.rbegin();
		NS::vector<int>::const_reverse_iterator	it2 = v.rbegin();
		std::cout << "rbegin() : " << *it << std::endl;
		std::cout << "rbegin() : " << *it2 << std::endl;
	}
	{
		NS::vector<int>::const_reverse_iterator	it = v2.rbegin();
		std::cout << "rbegin() : " << *it << std::endl;
	}
}
