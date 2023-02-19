/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count(int).cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 16:45:46 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

int	main(void)
{
	std::vector<NS::pair<std::string, std::string> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<std::string, std::string>(tester::to_string(i), tester::to_string(i * 2)));

	TMAP_STR			m(v.begin(), v.end());
	const TMAP_STR		cm(v.begin(), v.end());

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		std::cout << "m.count(" << tester::to_string(i*2) << ") : " << m.count(tester::to_string(i*2)) << std::endl;
		std::cout << "cm.count(" << tester::to_string(i*2) << ") : " << cm.count(tester::to_string(i*2)) << std::endl;
	}
}
