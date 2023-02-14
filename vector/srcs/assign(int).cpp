/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:20 by afaby             #+#    #+#             */
/*   Updated: 2023/02/13 18:25:34 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"
#include <list>

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<int>	v(10);

	printVector(v);

	v.assign(120, 42);

	printVector(v);


	std::list<int>	l;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		l.push_back(i);

	v.assign(l.begin(), l.end());

	printVector(v);

	return (0);
}
