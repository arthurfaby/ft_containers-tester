/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(int).cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:53:30 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 14:10:36 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

int	main(void)
{
	NS::vector<int>	v;

	printVector(v);
	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.insert(v.begin(), i * 2);
	printVector(v);
	v.insert(v.begin() + TEST_SIZE / 2, TEST_SIZE / 10, 42);
	printVector(v);

	NS::vector<int>	v2(v);

	printVector(v2);
	v.insert(v.begin() + 5, v2.begin() + 5, v2.end() - 4);
	printVector(v);
	printVector(v2);

}
