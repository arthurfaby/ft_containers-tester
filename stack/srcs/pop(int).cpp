/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop(int).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:01:24 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 13:40:53 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(void)
{
	NS::stack<int>	s;

	printStack(s, "s");

	std::cout << "Pushing " << TEST_SIZE << " elements to stack s." << std::endl;
	for (size_t i = 0; i < TEST_SIZE; ++i)
		s.push(i);

	printStack(s, "s");

	for (size_t i =0; i < TEST_SIZE; ++i)
		s.pop();

	printStack(s, "s");

	return (0);
}
