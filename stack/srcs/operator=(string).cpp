/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator=(int).cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:01:24 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 13:33:04 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <deque>

int	main(void)
{
	NS::stack<std::string>	s;

	printStack(s, "s");

	NS::stack<std::string>	s2;

	s2 = s;
	printStack(s, "s");
	printStack(s2, "s2");

	std::cout << "Pushing " << TEST_SIZE << " elements to stack s." << std::endl;
	for (size_t i = 0; i < TEST_SIZE; ++i)
		s.push(tester::to_string(i));


	s2 = s;
	printStack(s, "s");
	printStack(s2, "s2");
	s2 = s2;
	printStack(s2, "s2");

	return (0);
}
