/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear(string).cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 5023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 18:59:23 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

int	main(void)
{
	std::vector<NS::pair<std::string, std::string> >	v;

	for (size_t i = 0; i < TEST_SIZE / 10; ++i)
		v.push_back(NS::make_pair<std::string, std::string>(tester::to_string(i), tester::to_string(i * 2)));

	TMAP_STR		m(v.begin(), v.end());

	for (size_t i = 0; i < TEST_SIZE / 10; ++i)
		std::cout << tester::to_string(i) << " --> " << m.at(tester::to_string(i)) << std::endl;
	m.clear();
	for (size_t i = 0; i < m.size(); ++i)
		std::cout << tester::to_string(i) << " --> " << m.at(tester::to_string(i)) << std::endl;
}
