/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend(int).cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:35:24 by afaby            ###   ########.fr       */
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

	printIt(--m.rend());
	(--m.rend())->second = 123;
	printIt(--m.rend());
	printIt(--cm.rend());
	
	TMAP_INT_RIT		rit = m.rend();
	TMAP_INT_RCIT	rcit = cm.rend();

	printIt(--rit);
	printIt(--rcit);
}
