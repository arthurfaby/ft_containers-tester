/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(int).cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:22:02 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 15:34:47 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

typedef NS::map<int, int>	TMAP;

int	main(void)
{
	TMAP	m;
	TMAP::iterator	it = m.begin();
	TMAP::iterator	ite = m.end();

	while (it != ite)
		std::cout << it->first << " --> " << (it++)->second << std::endl;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		m.insert(NS::make_pair<int, int>(i, i * 2));
	it = m.begin();
	while (it != ite)
		std::cout << it->first << " --> " << (it++)->second << std::endl;

	TMAP::iterator	pos = m.begin();
	for (size_t i = 0; i < TEST_SIZE; ++i)
		m.insert(pos++, NS::make_pair<int, int>(i, i * 3));
	it = m.begin();
	while (it != ite)
		std::cout << it->first << " --> " << (it++)->second << std::endl;

	TMAP	m2;

	m2.insert(++m.begin(), --m.end());
	it = m2.begin();
	ite = m2.end();
	while (it != ite)
		std::cout << it->first << " --> " << (it++)->second << std::endl;


	return (0);
}
