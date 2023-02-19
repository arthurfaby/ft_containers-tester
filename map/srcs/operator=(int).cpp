
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
	std::vector<NS::pair<int, int> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<int, int>(i, i * 2));

	TMAP_INT			me;
	TMAP_INT			m(v.begin(), v.end());

	std::cout << "PRINTING empty map me:" << std::endl;
	for (size_t i = 0; i < me.size(); ++i)
		std::cout << i << " --> " << me.at(i) << std::endl;

	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
		std::cout << i << " --> " << m.at(i) << std::endl;

	me = m;
	std::cout << "PRINTING empty map me:" << std::endl;
	for (size_t i = 0; i < me.size(); ++i)
		std::cout << i << " --> " << me.at(i) << std::endl;
	m = m;

	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
		std::cout << i << " --> " << m.at(i) << std::endl;
}
