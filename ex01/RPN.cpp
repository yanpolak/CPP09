/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:28:04 by ymarival          #+#    #+#             */
/*   Updated: 2023/11/04 15:28:04 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	hsilop(std::string exp)
{
	std::deque<int>		filo;
	std::stringstream	ss;
	int					nb;
	opfun				op = 0;

	for (size_t i = 0; i < exp.length(); i++)
	{
		if (std::isdigit(exp[i]))
		{
			ss << exp[i];
			ss >> nb;
			ss.clear();
			filo.push_front(nb);
		}
		else if (!std::isspace(exp[i]))
		{
			op = getop(exp[i]);
			if (op)
			{
				if (filo.size() < 2)
					throw (RPNException());
				int rhs = filo.front();
				filo.pop_front();
				int	lhs = filo.front();
				filo.pop_front();
				filo.push_front(op(lhs, rhs));
			}
			else
				throw (RPNException());
		}
	}
	if (filo.size() != 1)
		throw (RPNException());
	std::cout << filo.front() << std::endl;
}

opfun	getop(char c)
{
	char	symbols[] = {'+','-','*','/'};
	opfun	operations[] = {&add, &subs, &multi, &divi};

	for (size_t i = 0; i < 4; i++)
	{
		if (c == symbols[i])
			return operations[i];
	}
	return 0;
}

int	add(int lhs, int rhs)
{
	return lhs + rhs;
}

int	subs(int lhs, int rhs)
{
	return lhs - rhs;
}

int	multi(int lhs, int rhs)
{
	return lhs * rhs;
}

int	divi(int lhs, int rhs)
{
	if (rhs == 0)
		throw (RPNException());
	return lhs / rhs;
}