/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:59:17 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/30 20:24:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <vector>
#include <list>
#include <iostream>

#include "easyfind.hpp"

template <typename T>
void	test(T &container, int32_t target) {
	std::cout << "container content: ";
	for (int32_t i = 0; i < 10; i++) {
		container.insert(container.end(), rand() % 10);
		std::cout << *container.rbegin() << (i < 10 - 1 ? " " : "\n");
	}

	typename T::iterator	search = easyfind(container, target);	

	std::cout << "searching : " << target << "\n";
	if (search != container.end()) {
		std::cout << "found : " << *search << "\n" << std::endl;
	} else {
		std::cout << "not found..." << "\n" <<  std::endl;
	}
}

int main( void ) {
	std::srand(std::time(NULL));

	int32_t	target = rand() % 10;

	std::vector<int>	vector;
	std::list<int>		list;

	test(vector, target);
	test(list, target);
	return 0;
}
