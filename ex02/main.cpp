/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:03:42 by ymarival          #+#    #+#             */
/*   Updated: 2023/11/04 18:03:42 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac < 2)
			throw "Error: not the right number of arguments.";
		PmergeMe test;
		test.ft_sort(av);
	}
 	catch(const char *str)
 	{
 		std::cerr << str << '\n';
 	}
}