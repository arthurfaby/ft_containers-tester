/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve(string).cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:33:02 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:44:45 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(void)
{
	NS::vector<std::string>	v;

	printVector(v);
	v.reserve(100);
	printVector(v);
	v.reserve(100000000);
	printVector(v);
	try {
		v.reserve(10000000000000000);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printVector(v);
	try {
		v.reserve(-21);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	printVector(v);
}
