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
	std::vector<NS::pair<std::string, std::string> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<std::string, std::string>(tester::to_string(i), tester::to_string(i * 2)));

	TMAP_STR		m(v.begin(), v.end());
	const TMAP_STR	cm(v.begin(), v.end());

	printIt(--m.end());
	(--m.end())->second = 123;
	printIt(--m.end());
	printIt(--cm.end());
	
	TMAP_STR_IT		it = m.end();
	TMAP_STR_CIT	cit = cm.end();

	printIt(--it);
	printIt(--cit);
}
