/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors(int).cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:01:24 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 13:08:52 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <deque>

int	main(void)
{
	NS::stack<int>	s;

	std::cout << "Printing stack s : " << std::endl;
	printStack(s);
	std::cout << "Printing stack sc : " << std::endl;
	NS::stack<int, std::deque<int> >	sc(std::deque<int>);
	/* printStack(sc); */

	std::cout << "Pushing " << TEST_SIZE << " elements to stack s." << std::endl;
	for (size_t i = 0; i < TEST_SIZE; ++i)
		s.push(i);

	NS::stack<int>	s2(s);
	std::cout << "Printing stack s : " << std::endl;
	printStack(s);
	std::cout << "Printing stack s2 : " << std::endl;
	printStack(s2);

	return (0);
}
