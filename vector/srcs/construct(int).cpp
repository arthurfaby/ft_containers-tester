/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:08:14 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 10:20:53 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<int>			v;
	const NS::vector<int>	v2;

	printVector(v);
	printVector(v2);

	NS::vector<int>			v3(TEST_SIZE, 42);
	const NS::vector<int>	v4(TEST_SIZE, 42);

	printVector(v3);
	printVector(v4);

	std::vector<int>		v5(TEST_SIZE, 42);
	const std::vector<int>	v6(TEST_SIZE, 42);

	std::vector<int>::iterator	it = v5.begin();
	std::vector<int>::iterator	ite = v5.end();

	std::vector<int>::const_iterator	cit = v6.begin();
	std::vector<int>::const_iterator	cite = v6.end();

	NS::vector<int>			v7(it, ite);
	const NS::vector<int>	v8(it, ite);

	printVector(v7);
	printVector(v8);

	NS::vector<int>			v9(cit, cite);
	const NS::vector<int>	v10(cit, cite);

	printVector(v9);
	printVector(v10);
}
