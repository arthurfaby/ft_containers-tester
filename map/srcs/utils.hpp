/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:41 by afaby             #+#    #+#             */
/*   Updated: 2023/02/19 17:33:27 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#ifndef NS
	# define NS std
	# include <map>
#else
	# define NS ft
	# include "../../../map.hpp"
#endif

/* template<typename TMAP> */
/* void	printMap(const TMAP& m) */
/* { */
/* 	std::cout << "########## CONTENT ##########" << std::endl; */
/* 	typename TMAP::iterator	it = m.begin(); */
/* 	typename TMAP::iterator	ite = m.end(); */
/* 	while (it != ite) */
/* 	{ */
/* 		std::cout << it->first << " --> " << it->second << std::endl; */
/* 		++it; */
/* 	} */
/* 	std::cout << std::endl; */
/* 	std::cout << " ############################" << std::endl; */
/* 	std::cout << " Size : " << m.size() << std::endl; */
/* 	//std::cout << " Max_size : " << vec.max_size() << std::endl; */
/* } */

template<class InputIt>
void	printIt(InputIt it)
{
	std::cout << it->first << " --> " << it->second << std::endl;
}

#ifndef TEST_SIZE
	#define TEST_SIZE 100
#endif

typedef NS::map<int, int>											TMAP_INT;
typedef NS::map<std::string, std::string>							TMAP_STR;
typedef NS::map<int,int>::iterator									TMAP_INT_IT;
typedef NS::map<int,int>::const_iterator							TMAP_INT_CIT;
typedef NS::map<std::string, std::string>::iterator					TMAP_STR_IT;
typedef NS::map<std::string, std::string>::const_iterator			TMAP_STR_CIT;
typedef NS::map<int,int>::reverse_iterator							TMAP_INT_RIT;
typedef NS::map<int,int>::const_reverse_iterator					TMAP_INT_RCIT;
typedef NS::map<std::string, std::string>::reverse_iterator			TMAP_STR_RIT;
typedef NS::map<std::string, std::string>::const_reverse_iterator	TMAP_STR_RCIT;

namespace tester
{

std::string	to_string(int i)
{
	std::stringstream	stream;

	stream << i;
	std::string	res;

	stream >> res;
	return (res);
}

}
