/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 10:56:02 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	{
		NS::vector<int>	v;
	
		printVector(v);
		std::cout << "Empty ? : " << v.empty() << std::endl;
		for (size_t i = 0; i < TEST_SIZE; ++i)
			v.push_back(i);
	
		printVector(v);
		std::cout << "Empty ? : " << v.empty() << std::endl;
	}
	{
		const NS::vector<int>	v;
	
		printVector(v);
		std::cout << "Empty ? : " << v.empty() << std::endl;
	}
}
