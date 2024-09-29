/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/29 16:58:43 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

int main()
{
	std::cout << "Subject Tests\n";
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\nAdditional Tests\n";
	{
		Span sp = Span(8);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp.addNumber(-5);
		sp.addNumber(2);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		try {
			sp.addNumber(0);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	}
	std::cout << "\nComplexity Tests\n";
	{
		std::vector<int32_t>	vector;

		for (uint32_t i = 0; i < 100000; i++) {
			vector.push_back(i * 3);
		}

		Span	sp(100000);

		sp.addNumber(vector.begin(), vector.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		try {
			sp.addNumber(-42);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	}
	return 0;
}
