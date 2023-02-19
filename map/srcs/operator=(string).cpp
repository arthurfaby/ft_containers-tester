
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct(int).cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 16:43:04 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

int	main(void)
{
	std::vector<NS::pair<std::string, std::string> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<std::string, std::string>(tester::to_string(i), tester::to_string(i * 2)));

	TMAP_STR			me;
	TMAP_STR			m(v.begin(), v.end());

	std::cout << "PRINTING empty map me:" << std::endl;
	for (size_t i = 0; i < me.size(); ++i)
		std::cout << i << " --> " << me.at(tester::to_string(i)) << std::endl;

	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
		std::cout << i << " --> " << m.at(tester::to_string(i)) << std::endl;

	me = m;
	std::cout << "PRINTING empty map me:" << std::endl;
	for (size_t i = 0; i < me.size(); ++i)
		std::cout << i << " --> " << me.at(tester::to_string(i)) << std::endl;
	m = m;

	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
		std::cout << i << " --> " << m.at(tester::to_string(i)) << std::endl;
}
