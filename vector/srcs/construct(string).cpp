/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct(string).cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:08:14 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:29:31 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

#define TEST_SIZE 10000

int	main(void)
{
	NS::vector<std::string>			v;
	const NS::vector<std::string>	v2;

	printVector(v);
	printVector(v2);

	NS::vector<std::string>			v3(TEST_SIZE, "42");
	const NS::vector<std::string>	v4(TEST_SIZE, "42");

	printVector(v3);
	printVector(v4);

	std::vector<std::string>		v5(TEST_SIZE, "42");
	const std::vector<std::string>	v6(TEST_SIZE, "42");

	std::vector<std::string>::iterator	it = v5.begin();
	std::vector<std::string>::iterator	ite = v5.end();

	std::vector<std::string>::const_iterator	cit = v6.begin();
	std::vector<std::string>::const_iterator	cite = v6.end();

	NS::vector<std::string>			v7(it, ite);
	const NS::vector<std::string>	v8(it, ite);

	printVector(v7);
	printVector(v8);

	NS::vector<std::string>			v9(cit, cite);
	const NS::vector<std::string>	v10(cit, cite);

	printVector(v9);
	printVector(v10);
}
