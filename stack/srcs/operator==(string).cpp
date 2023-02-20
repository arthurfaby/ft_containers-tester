/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator==(int).cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:01:24 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 13:44:31 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <deque>

int	main(void)
{
	NS::stack<std::string>	s;

	std::cout << "Pushing " << TEST_SIZE << " elements to stack s." << std::endl;
	for (size_t i = 0; i < TEST_SIZE; ++i)
		s.push(tester::to_string(i));

	NS::stack<std::string>	s2(s);
	NS::stack<std::string>	s3(s);

	s3.push("-1");

	printStack(s, "s");
	printStack(s2, "s2");
	printStack(s3, "s3");

	std::cout << (s == s2) << std::endl;
	std::cout << (s2 == s) << std::endl;
	std::cout << (s3 == s2) << std::endl;
	std::cout << (s2 == s3) << std::endl;
	std::cout << (s == s3) << std::endl;
	std::cout << (s3 == s) << std::endl;

	return (0);
}
