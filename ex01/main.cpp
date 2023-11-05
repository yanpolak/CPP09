/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:30:43 by ymarival          #+#    #+#             */
/*   Updated: 2023/11/04 15:30:43 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please enter an inverted Polish expression\n";
		return 1;
	}
	try
	{
		hsilop(argv[1]);
	}
	catch (RPNException & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}