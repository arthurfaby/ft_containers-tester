/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_bound(int).cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:16:13 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

int	main(void)
{
	std::vector<NS::pair<std::string, std::string> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<std::string, std::string>(tester::to_string(i), tester::to_string(i * 2)));

	TMAP_STR		m(v.begin(), v.end());
	const TMAP_STR	cm(v.begin(), v.end());

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		TMAP_STR_IT		npair = m.lower_bound(tester::to_string(i));
		TMAP_STR_CIT	cpair = cm.lower_bound(tester::to_string(i));
		if (npair == m.end())
			std::cout << "[m] It first is end" << std::endl;
		else
			std::cout << "[m] first it : " << npair->first << " --> " << npair->second << std::endl;
		if (cpair == cm.end())
			std::cout << "[cm] It first is end" << std::endl;
		else
			std::cout << "[cm] first it : " << cpair->first << " --> " << cpair->second << std::endl;
	} 
}
