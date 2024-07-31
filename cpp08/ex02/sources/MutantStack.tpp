/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:16:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:20:27 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src)
{
	*this = src;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	
}

template <typename T>
MutantStack<T>&
MutantStack<T>::operator=(MutantStack &src)
{
	for (MutantStack<T>::iterator it = src.c.begin(); it != src.c.end(); it++)
		this->push(*it);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator
MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator
MutantStack<T>::end()
{
	return (this->c.end());
}
