/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:16:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:14:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array(unsigned int n) :
	_array(new T[n]), _array_size(n)
{
}

template<typename T>
Array<T>::Array(const Array& src) :
	_array(new T[src.size()]), _array_size(src.size())
{
	for (size_t i = 0; i < this->_array_size; i++)
         this->_array[i] = src.array[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template<typename T>
unsigned int
Array<T>::size() const
{
	return (this->_array_size);
}

template<typename T>
Array<T>&
Array<T>::operator=(const Array &rhs)
{
	delete [] this->_array;
	this->_array = new T[rhs.size()];
	this->_array_size = rhs.array_size;
	for (size_t i = 0 ; i < this->_array_size; i++)
		this->_array[i] = rhs.array[i];
	return (*this);
}

template<typename T>
const T&
Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_array_size)
		throw std::exception();
	return (this->_array[index]);
}

template<typename T>
T&
Array<T>::operator[](unsigned int index)
{
	if (index >= this->_array_size)
		throw std::exception();
	return (this->_array[index]);
}

template<typename T>
std::ostream&
operator<<(std::ostream& ostream, const Array<T>& rhs)
{
	ostream << "{";
	for(size_t i = 0; i < rhs.size(); i++)
		ostream << std::setw(4) << rhs[i] << (i < rhs.size() - 1 ? ", " : "");
	ostream << "}";
	return (ostream);
}
