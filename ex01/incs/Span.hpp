/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:42:24 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/28 02:53:59 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdint.h>
# include <vector>

typedef	std::vector<int32_t> container_t;

class Span
{
	private:
		container_t	_container;
		uint32_t	_N;

	public:
		Span(void);
		Span(uint32_t);
		Span(const Span &);

		~Span(void);

		Span	&operator=(const Span &);

		void		addNumber(uint32_t);
		void		addNumber(container_t::iterator, container_t::iterator);
		uint32_t	shortestSpan(void);
		uint32_t	longestSpan(void);
};

#endif /* ******************************************************************* */
