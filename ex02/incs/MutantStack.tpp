/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:30:52 by ibertran          #+#    #+#             */
/*   Updated: 2024/09/30 16:09:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

/* CONSTRUCTORS ************************************************************* */

template <typename T>
MutantStack<T>::MutantStack(void) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) {
	*this = other;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

/* OPERATOR OVERLOADING ***************************************************** */

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this == &other)
		return (*this);
	this->c = other.c;
	return (*this);
}

/* ITERATORS **************************************************************** */

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void) {
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void) {
	return this->c.rend();
}

#endif
