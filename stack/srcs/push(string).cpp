
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty(int).cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:01:24 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 13:39:20 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(void)
{
	NS::stack<std::string>	s;

	printStack(s, "s");

	std::cout << "Pushing " << TEST_SIZE << " elements to stack s." << std::endl;
	for (size_t i = 0; i < TEST_SIZE; ++i)
		s.push(tester::to_string(i));

	printStack(s, "s");

	return (0);
}
