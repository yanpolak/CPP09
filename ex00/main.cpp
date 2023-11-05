/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:48:24 by ymarival          #+#    #+#             */
/*   Updated: 2023/10/14 21:48:24 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	std::string	input(argv[1]);

	BitcoinExchange	bce = BitcoinExchange();
	try
	{
		bce.loadCsv("data.csv");
		bce.loadInput(input);
	}
	catch (BitcoinExchange::CsvParsingException & e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	//bce.printExchange();
	return 0;
}