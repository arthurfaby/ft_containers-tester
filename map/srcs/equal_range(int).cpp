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
	std::vector<NS::pair<int, int> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<int, int>(i, i * 2));

	TMAP_INT		m(v.begin(), v.end());
	const TMAP_INT	cm(v.begin(), v.end());

	for (size_t i = 0; i < TEST_SIZE; ++i)
	{
		NS::pair<TMAP_INT_IT, TMAP_INT_IT>	npair = m.equal_range(i);
		NS::pair<TMAP_INT_CIT, TMAP_INT_CIT>	cpair = cm.equal_range(i);
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
