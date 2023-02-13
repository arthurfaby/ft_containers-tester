/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:08:54 by afaby             #+#    #+#             */
/*   Updated: 2023/02/13 18:37:20 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<int>	v;

		std::cout << "Capacity : " << v.capacity() << std::endl;
	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		v.push_back(i);
		std::cout << "Capacity : " << v.capacity() << std::endl;
	}

	printVector(v);
}
