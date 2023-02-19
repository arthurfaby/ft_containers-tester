/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range(int).cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:16:22 by afaby            ###   ########.fr       */
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
		NS::pair<TMAP_STR_IT, TMAP_STR_IT>	npair = m.equal_range(tester::to_string(i));
		NS::pair<TMAP_STR_CIT, TMAP_STR_CIT>	cpair = cm.equal_range(tester::to_string(i));
		if (npair.first == m.end())
			std::cout << "[m] It first is end" << std::endl;
		else
			std::cout << "[m] first it : " << npair.first->first << " --> " << npair.first->second << std::endl;
		if (npair.second == m.end())
			std::cout << "[m] It second is end" << std::endl;
		else
			std::cout << "[m] second it : " << npair.second->first << " --> " << npair.second->second << std::endl;
		if (cpair.first == cm.end())
			std::cout << "[cm] It first is end" << std::endl;
		else
			std::cout << "[cm] first it : " << cpair.first->first << " --> " << cpair.first->second << std::endl;
		if (cpair.second == cm.end())
			std::cout << "[cm] It second is end" << std::endl;
		else
			std::cout << "[cm] second it : " << cpair.second->first << " --> " << cpair.second->second << std::endl;
	} 
}
