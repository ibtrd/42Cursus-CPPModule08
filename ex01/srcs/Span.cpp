/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:20:55 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/30 20:28:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iterator>

#include "Span.hpp"

/* CONSTRUCTORS ************************************************************* */

Span::Span(void) : _N(0) {}

Span::Span(uint32_t N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N) {
	*this = other;
}

Span::~Span(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

Span &Span::operator=(const Span &other) {
	if (this == &other)
		return (*this);
	this->_container = std::vector<int32_t>(other._container);
	this->_N = other._N;
	return (*this);
}

/* ************************************************************************** */

void Span::addNumber(int32_t toAdd) {
	if (this->_container.size() == this->_N) {
		throw std::runtime_error("Span: maximum amout of element reached");
	}
	this->_container.push_back(toAdd);
}

void Span::addNumber(std::vector<int32_t>::iterator first, std::vector<int32_t>::iterator last) {
	std::vector<int32_t>::iterator	curr = first;
	
	while (curr != last) {
		if (this->_container.size() == this->_N) {
			throw std::runtime_error("Span: maximum amout of element reached");
		}
		this->_container.push_back(*curr++);
	}
}

uint32_t Span::shortestSpan(void) {
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

uint32_t Span::longestSpan(void) {
	if (this->_container.size() < 2) {
		throw std::runtime_error("Span: invalid amount of elements");
	}
	std::vector<int32_t>::iterator first = this->_container.begin();
	std::vector<int32_t>::iterator last = this->_container.end();

	return (*std::max_element(first, last) - *std::min_element(first, last));
}
