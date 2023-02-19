/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin(int).cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:34:13 by afaby            ###   ########.fr       */
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

	printIt(m.rbegin());
	m.rbegin()->second = 123;
	printIt(m.rbegin());
	printIt(cm.rbegin());
	
	TMAP_STR_RIT		rit = m.rbegin();
	TMAP_STR_RCIT	rcit = cm.rbegin();

	printIt(rit);
	printIt(rcit);
}
