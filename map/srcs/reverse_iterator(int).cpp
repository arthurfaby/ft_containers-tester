/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator(int).cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:47:28 by afaby            ###   ########.fr       */
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
	
	TMAP_INT_RIT		it = m.rbegin();
	TMAP_INT_RCIT	cit = cm.rbegin();
	TMAP_INT_RCIT	cite = cm.rend();

	for (; cit != cite; ++cit)
		printIt(cit);
	std::cout << std::endl;

	--cit;
	printIt(cit);
	--cit;
	printIt(cit);
	cit--;
	printIt(cit);

	printIt(cit);
	++cit;
	printIt(cit);
	cit++;
	printIt(cit);

	std::cout << (it == cit) << std::endl;
	std::cout << (cit == it) << std::endl;
	std::cout << (it != cit) << std::endl;
	std::cout << (cit != it) << std::endl;
	
	return (0);
}
