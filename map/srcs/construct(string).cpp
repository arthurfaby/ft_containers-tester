/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct(string).cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:43:19 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 18:15:50 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <vector>

int	main(void)
{
	std::vector<NS::pair<std::string, std::string> >	v;

	for (size_t i = 0; i < TEST_SIZE; ++i)
		v.push_back(NS::make_pair<std::string, std::string>(tester::to_string(i), tester::to_string(i * 2)));

	TMAP_STR			me;
	const TMAP_STR		cme;
	TMAP_STR			m(v.begin(), v.end());
	const TMAP_STR		cm(v.begin(), v.end());

	std::cout << "PRINTING empty map me:" << std::endl;
	for (size_t i = 0; i < me.size(); ++i)
		std::cout << i << " --> " << me.at(tester::to_string(i)) << std::endl;
	std::cout << "PRINTING empty const map cme :" << std::endl;
	for (size_t i = 0; i < cme.size(); ++i)
		std::cout << i << " --> " << cme.at(tester::to_string(i)) << std::endl;
	std::cout << "PRINTING map m :" << std::endl;
	for (size_t i = 0; i < m.size(); ++i)
		std::cout << i << " --> " << m.at(tester::to_string(i)) << std::endl;
	std::cout << "PRINTING const map cm :" << std::endl;
	for (size_t i = 0; i < cm.size(); ++i)
		std::cout << i << " --> " << cm.at(tester::to_string(i)) << std::endl;

	TMAP_STR		meq(m);
	TMAP_STR		meq2(cm);
	const TMAP_STR	cmeq(m);
	const TMAP_STR	cmeq2(cm);

	std::cout << "PRINTING map meq:" << std::endl;
	for (size_t i = 0; i < meq.size(); ++i)
		std::cout << i << " --> " << meq.at(tester::to_string(i)) << std::endl;
	std::cout << "PRINTING const map cmeq :" << std::endl;
	for (size_t i = 0; i < cmeq.size(); ++i)
		std::cout << i << " --> " << cmeq.at(tester::to_string(i)) << std::endl;
	std::cout << "PRINTING map meq2 :" << std::endl;
	for (size_t i = 0; i < meq2.size(); ++i)
		std::cout << i << " --> " << meq2.at(tester::to_string(i)) << std::endl;
	std::cout << "PRINTING const map cmeq2 :" << std::endl;
	for (size_t i = 0; i < cmeq2.size(); ++i)
		std::cout << i << " --> " << cmeq2.at(tester::to_string(i)) << std::endl;
}
