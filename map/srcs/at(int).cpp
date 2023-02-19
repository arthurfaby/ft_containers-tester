/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at(int).cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 15:55:28 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

int	main(void)
{
	std::vector<NS::pair<int, int> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<int, int>(i, i * 2));

	TMAP_INT		m(v.begin(), v.end());
	const TMAP_INT	cm(v.begin(), v.end());

	for (size_t i = 0.; i < TEST_SIZE; ++i)
	{
		std::cout << m.at(i) << std::endl;
		std::cout << cm.at(i) << std::endl;
	}
	try {
		m.at(TEST_SIZE + 100);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		m.at(-10);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
