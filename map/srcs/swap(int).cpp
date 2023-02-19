
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_swap(int).cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:25:37 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

int	main(void)
{
	std::vector<NS::pair<int, int> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<int, int>(i, i * 2));

	TMAP_INT			m(v.begin(), v.end());
	TMAP_INT			m2(++v.begin(), --v.end());

	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
	{
		try {
			std::cout << i << " --> " << m.at(i) << std::endl;
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "PRINTING const map m2 :" << std::endl;
	for (size_t i = 0; i < m2.size(); ++i)
	{
		try {
			std::cout << i << " --> " << m.at(i) << std::endl;
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	m.swap(m2);

	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
	{
		try {
			std::cout << i << " --> " << m.at(i) << std::endl;
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "PRINTING const map m2 :" << std::endl;
	for (size_t i = 0; i < m2.size(); ++i)
	{
		try {
			std::cout << i << " --> " << m.at(i) << std::endl;
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}
