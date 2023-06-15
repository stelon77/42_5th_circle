/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 06:56:30 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 16:59:46 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <cstddef>

namespace ft
{
	template <class T, class Container = list<T> >
	class queue
	{
		public:

			/*-------------------------------- ALIAS ------------------------------------*/
			/*---------------------------------------------------------------------------*/
			typedef T													value_type;
			typedef Container											container_type;
			typedef size_t												size_type;

		private:
			/*----------------------------- ATTRIBUTES ----------------------------------*/
			/*---------------------------------------------------------------------------*/
			container_type _c;

		public:
			/*---------------------------------------------------------------------------*/
			/*------------------------ MEMBER FUNCTIONS ---------------------------------*/
			/*---------------------------------------------------------------------------*/

			/*------------Default Constructor (empty container constructor)--------------*/
			explicit queue (const container_type& ctnr = container_type()) : _c(ctnr) {}

			/*---------------------------- empty() --------------------------------------*/
			bool empty() const 								{	return (_c.empty());	}

			/*----------------------------- size() --------------------------------------*/
			size_type size() const 							{	return (_c.size());		}

			/*----------------------------- front() -------------------------------------*/
			value_type& front() 							{	return (_c.front());	}

			const value_type& front() const					{	return (_c.front());	}

			/*----------------------------- back() --------------------------------------*/
			value_type& back() 								{	return (_c.back());		}

			const value_type& back() const					{	return (_c.back());		}

			/*----------------------------- push() --------------------------------------*/
			void push (const value_type& val)					{	_c.push_back(val);	}

			/*------------------------------ pop() --------------------------------------*/
			void pop()											{	_c.pop_front();	}


			/*------------------------ overload operator == --------------------------------*/
			friend bool operator== (const queue & lhs, const queue & rhs)	{return (lhs._c == rhs._c);}

			/*------------------------ overload operator < --------------------------------*/
			friend bool operator<  (const queue & lhs, const queue & rhs)	{return (lhs._c < rhs._c);}

	};// class queue

			/*---------------------------------------------------------------------------*/
			/*---------------------------------------------------------------------------*/
			/*------------------------- NON MEMBERS OVERLOAD ----------------------------*/
			/*---------------------------------------------------------------------------*/
			/*---------------------------------------------------------------------------*/

			/*---------------------------------------------------------------------------*/
			/*------------------------ RELATIONNAL OPERATORS ----------------------------*/
			/*---------------------------------------------------------------------------*/

			template <class T, class Container>
			bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
			{	return (!(lhs == rhs));	}

			template <class T, class Container>
			bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
			{	return (!(rhs < lhs));	}

			template <class T, class Container>
			bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
			{	return (rhs < lhs);	}

			template <class T, class Container>
			bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
			{	return (!(lhs < rhs));	}

} //namespace ft