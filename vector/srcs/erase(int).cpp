/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:47:23 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 16:51:45 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"


#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<int>	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(i * 2);

	printVector(v);
	v.erase(v.begin() + TEST_SIZE / 2);
	printVector(v);
	v.erase(v.begin());
	while (!v.empty())
		v.erase(v.begin());
	printVector(v);

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(i * 3);

	printVector(v);
	v.erase(v.begin(), v.begin() + TEST_SIZE - 8);
	printVector(v);
}
