/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 08:04:15 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 16:59:52 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <cstddef>

namespace ft
{
	template <class T, class Container = list<T> >
	class stack
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

			/*------------------Default Constructor (container constructor)--------------*/
			explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) {}

			/*---------------------------- empty() --------------------------------------*/
			bool empty() const 								{	return (_c.empty());	}

			/*----------------------------- size() --------------------------------------*/
			size_type size() const 							{	return (_c.size());		}

			/*----------------------------- top() --------------------------------------*/
			value_type& top() 								{	return (_c.back());		}

			const value_type& top() const					{	return (_c.back());		}

			/*----------------------------- push() --------------------------------------*/
			void push (const value_type& val)					{	_c.push_back(val);	}

			/*------------------------------ pop() --------------------------------------*/
			void pop ()												{	_c.pop_back();	}

			/*------------------------ overload operator == --------------------------------*/
			friend bool operator== (const stack & lhs, const stack & rhs)	{return (lhs._c == rhs._c);}

			/*------------------------ overload operator < --------------------------------*/
			friend bool operator<  (const stack & lhs, const stack & rhs)	{return (lhs._c < rhs._c);}

	};// class stack

			/*---------------------------------------------------------------------------*/
			/*---------------------------------------------------------------------------*/
			/*------------------------- NON MEMBERS OVERLOAD ----------------------------*/
			/*---------------------------------------------------------------------------*/
			/*---------------------------------------------------------------------------*/

			/*---------------------------------------------------------------------------*/
			/*------------------------ RELATIONNAL OPERATORS ----------------------------*/
			/*---------------------------------------------------------------------------*/

			template <class T, class Container>
			bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{	return (!(lhs == rhs));	}

			template <class T, class Container>
			bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{	return (!(rhs < lhs));	}

			template <class T, class Container>
			bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{	return (rhs < lhs);	}

			template <class T, class Container>
			bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{	return (!(lhs < rhs));	}

} //namespace ft