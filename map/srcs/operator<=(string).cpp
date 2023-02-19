/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<=(int).cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:26:26 by afaby            ###   ########.fr       */
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
	TMAP_STR			m2(++v.begin(), --v.end());
	TMAP_STR			m3(m);

	std::cout << (m <= m2) << std::endl;
	std::cout << (m2 <= m) << std::endl;
	std::cout << (m <= m3) << std::endl;
	std::cout << (m3 <= m) << std::endl;
	std::cout << (m3 <= m2) << std::endl;
	std::cout << (m2 <= m3) << std::endl;

	const TMAP_STR			cm(v.begin(), v.end());
	const TMAP_STR			cm2(++v.begin(), --v.end());
	const TMAP_STR			cm3(m);

	std::cout << (cm <= cm2) << std::endl;
	std::cout << (cm2 <= cm) << std::endl;
	std::cout << (cm <= cm3) << std::endl;
	std::cout << (cm3 <= cm) << std::endl;
	std::cout << (cm3 <= cm2) << std::endl;
	std::cout << (cm2 <= cm3) << std::endl;


	std::cout << (m <= cm) << std::endl;
	std::cout << (cm <= m) << std::endl;

	return (0);
}
