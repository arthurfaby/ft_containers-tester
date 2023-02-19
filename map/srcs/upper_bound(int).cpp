/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_bound(int).cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:42:36 by afaby            ###   ########.fr       */
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
		TMAP_INT_IT		npair = m.upper_bound(i);
		TMAP_INT_CIT	cpair = cm.upper_bound(i);
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
