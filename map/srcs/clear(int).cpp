/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear(int).cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 16:17:35 by afaby            ###   ########.fr       */
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

	for (size_t i = 0; i < TEST_SIZE; ++i)
		std::cout << i << " --> " << m.at(i) << std::endl;
	m.clear();
	for (size_t i = 0; i < m.size(); ++i)
		std::cout << i << " --> " << m.at(i) << std::endl;
}
