/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:57:43 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/12 21:41:38 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {

	public:
		Array<T>(): _len(0) {this->_arr = new T[0];}
		Array<T>(unsigned int n): _len(n) {this->_arr = new T[n]();}
		Array<T>(Array &A)
		{
			this->_len = A.size();
			this->_arr = new T[this->_len]();
			for (unsigned int i=0; i<this->_len; ++i)
				this->_arr[i] = A[i];
		}
//		~Array<T>() {delete this->_arr;}

		unsigned int	size(void) {return this->_len;}

		T	&operator[](unsigned int n)
		{
			if (n >= this->_len)
				throw std::out_of_range("out of range exception");
			return this->_arr[n];
		}

		Array<T>	&operator=(Array<T> &A)
		{
			delete this->_arr;
			this->_len = A.size();
			this->_arr = new T[this->_len]();
			for (unsigned int i=0; i<this->_len; ++i)
				this->_arr[i] = A[i];
			return *this;
		}

	private:
		T				*_arr;
		unsigned int	_len;

};

#endif
