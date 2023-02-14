/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size(string).cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:02:24 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 18:36:05 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(void)
{
	NS::vector<std::string>	v;

	for (size_t i = 1; i < 100; ++i)
		std::cout << v.max_size() * i * 10 << std::endl;
}
