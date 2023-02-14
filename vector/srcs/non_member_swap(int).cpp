/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_swap.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:00:09 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 17:02:57 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<int>	v;
	NS::vector<int>	v2;

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		v.push_back(i * 2);
		v2.push_back(i * 3);
	}
	printVector(v);
	printVector(v2);
	NS::swap(v, v2);
	printVector(v);
	printVector(v2);
}
