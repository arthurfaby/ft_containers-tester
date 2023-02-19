/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin(int).cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 16:10:58 by afaby            ###   ########.fr       */
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

	printIt(m.begin());
	m.begin()->second = 123;
	printIt(m.begin());
	printIt(cm.begin());
	
	TMAP_INT_IT		it = m.begin();
	TMAP_INT_CIT	cit = cm.begin();

	printIt(it);
	printIt(cit);
}
