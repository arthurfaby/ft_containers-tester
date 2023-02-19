/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end(int).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 16:48:17 by afaby            ###   ########.fr       */
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

	printIt(--m.end());
	(--m.end())->second = 123;
	printIt(--m.end());
	printIt(--cm.end());
	
	TMAP_INT_IT		it = m.end();
	TMAP_INT_CIT	cit = cm.end();

	printIt(--it);
	printIt(--cit);
}
