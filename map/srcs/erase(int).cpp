/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(int).cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 19:00:26 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

int	main(void)
{
	std::vector<NS::pair<int, int> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<int, int>(i, i * 2));

	TMAP_INT			me;
	TMAP_INT			m(v.begin(), v.end());

	std::cout << "PRINTING map me:" << std::endl;
	for (size_t i = 0; i < me.size(); ++i)
	{
		try {
			std::cout << i << " --> " << me.at(i) << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
	{
		try {
			std::cout << i << " --> " << m.at(i) << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << me.erase(34) << std::endl;
	me.erase(me.begin(), me.end());
	std::cout << "PRINTING map me:" << std::endl;
	for (size_t i = 0; i < me.size(); ++i)
	{
		try {
			std::cout << i << " --> " << me.at(i) << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	m.erase(m.begin());
	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
	{
		try {
			std::cout << i << " --> " << m.at(i) << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	try {
		std::cout << m.erase(TEST_SIZE - 10) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << m.erase(TEST_SIZE + 10) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	for (size_t i = 0; i < m.size(); ++i)
	{
		try {
			std::cout << i << " --> " << m.at(i) << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}
	
