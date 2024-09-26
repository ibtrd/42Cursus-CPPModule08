/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:20:55 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/28 03:10:36 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <functional>
#include <iterator>
#include <exception>

#include "Span.hpp"

/* CONSTRUCTORS ************************************************************* */

Span::Span(void) : _N(0) {}

Span::Span(uint32_t N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N) {
	*this = other;
}

Span::~Span(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

Span	&Span::operator=(const Span &other) {
	if (this == &other)
		return (*this);
	this->_container = container_t(other._container);
	this->_N = other._N;
	return (*this);
}

/* ************************************************************************** */

void		Span::addNumber(uint32_t toAdd) {
	if (this->_container.size() == this->_N) {
		throw std::runtime_error("Span: maximum amout of element reached");
	}
	this->_container.push_back(toAdd);
}

void		Span::addNumber(container_t::iterator first, container_t::iterator last) {
	container_t::iterator	curr = first;
	
	while (curr != last) {
		if (this->_container.size() == this->_N) {
			throw std::runtime_error("Span: maximum amout of element reached");
		}
		this->_container.push_back(*curr++);
	}
}

uint32_t	Span::shortestSpan(void) {
	if (this->_container.size() < 2) {
		throw std::runtime_error("Span: invalid amount of elements");
	}

	std::sort(this->_container.begin(), this->_container.end());
	std::vector<int32_t>::iterator curr = this->_container.begin();
	std::vector<int32_t>::iterator prev = curr++;
	uint32_t shortest = *curr - *prev;
	while (curr != this->_container.end()) {
		uint32_t span = *curr - *prev;
		if (span < shortest) {
			shortest = span;
		}
		prev = curr++;
	}
	return (shortest);
}

uint32_t	Span::longestSpan(void) {
	if (this->_container.size() < 2) {
		throw std::runtime_error("Span: invalid amount of elements");
	}
	container_t::iterator first = this->_container.begin();
	container_t::iterator last = this->_container.end();

	return (*std::max_element(first, last) - *std::min_element(first, last));
}
