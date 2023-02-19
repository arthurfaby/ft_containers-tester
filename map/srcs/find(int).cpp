/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find(int).cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:18:02 by afaby            ###   ########.fr       */
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

	TMAP_INT_IT	it = m.find(TEST_SIZE - 1);
	TMAP_INT_CIT	cit = cm.find(TEST_SIZE - 1);

	if (it == m.end())
		std::cout << "[m] it is end" << std::endl;
	else
		std::cout << "[m] it : " << it->first << " --> " << it->second << std::endl;

	if (cit == cm.end())
		std::cout << "[cm] it is end" << std::endl;
	else
		std::cout << "[cm] it : " << cit->first << " --> " << cit->second << std::endl;

	it = m.find(TEST_SIZE + 10);
	cit = cm.find(TEST_SIZE + 10);

	if (it == m.end())
		std::cout << "[m] it is end" << std::endl;
	else
		std::cout << "[m] it : " << it->first << " --> " << it->second << std::endl;

	if (cit == cm.end())
		std::cout << "[cm] it is end" << std::endl;
	else
		std::cout << "[cm] it : " << cit->first << " --> " << cit->second << std::endl;
}
