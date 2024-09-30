/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:42:24 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/30 20:28:51 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdint.h>
# include <vector>

class Span
{
	private:
		std::vector<int32_t>	_container;
		uint32_t				_N;

	public:
		Span(void);
		Span(uint32_t);
		Span(const Span &);

		~Span(void);

		Span	&operator=(const Span &);

		void		addNumber(int32_t);
		void		addNumber(std::vector<int32_t>::iterator, std::vector<int32_t>::iterator);
		uint32_t	shortestSpan(void);
		uint32_t	longestSpan(void);
};

#endif /* ******************************************************************* */
