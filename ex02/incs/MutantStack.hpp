/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:29:23 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/30 20:34:51 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &);

		~MutantStack(void);

		MutantStack	&operator=(const MutantStack &);
	
		typedef typename std::deque<T>::iterator iterator;
		iterator			begin(void);
		iterator			end(void);

		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin(void);
		reverse_iterator	rend(void);
};

# include "MutantStack.tpp"

#endif /* ******************************************************************* */
