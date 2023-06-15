/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:53:07 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/24 14:31:09 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ITERATOR_HPP
#define REV_ITERATOR_HPP

#include "iterator.hpp"
#include <cstddef>

namespace ft
{
	template <class Iterator>
	class ReverseIterator : public Iterator
	{
		public:

			/*-------------------------ALIAS-----------------*/
			/*-----------------------------------------------*/
			typedef Iterator								iterator_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::const_value_type		const_value_type;
			typedef typename Iterator::reference 			reference;
			typedef typename Iterator::const_reference 		const_reference;
			typedef typename Iterator::pointer 				pointer;
			typedef typename Iterator::const_pointer 		const_pointer;

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/

			/*------------Default Constructor------------------------------------*/
			/*-----create an reverseiterator pointing on null--------------------*/
			ReverseIterator(): Iterator() {}

			/*------------Constructor with initialisation-------------------------*/
			ReverseIterator(const iterator_type & it) : Iterator(it){}

			/*------------Constructor by copy-------------------------------------*/
			ReverseIterator(const ReverseIterator & other) : Iterator(other._current){}

			/*------------Destructor----------------------------------------------*/
			~ReverseIterator(){}

			/*------------operator = (assignation)-------------------------------------*/
			ReverseIterator operator=(const ReverseIterator & other){
				if (this != &other)
					this->_current = other._current;
				return (*this);
			}


			/*------------- MEMBER FUNCTIONS ------------------*/
			/*-------------------------------------------------*/

			/*------------ base() ----------------------------------------------*/
			iterator_type base() const {
				return (iterator_type::base());
			}

			/*--------------Dereferencement---------------------------*/
			/*--------------------------------------------------------*/
			reference 	operator*() const {
				Iterator tmp(*this);
				return (*--tmp);
			}

			pointer		operator->() const {return (&(operator*()));}


			/*--------------Addition operator---------------------------*/
			ReverseIterator operator+ (int n) const
			{
				ReverseIterator tmp(*this);
				return(tmp.iterator_type::operator-(n));
			}

			/*---------Increment operator position -------------------*/
			/*--------------------prefix------------------------------*/
			ReverseIterator & operator++()
			{
				iterator_type::operator--();
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			ReverseIterator operator++(int)
			{
				ReverseIterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*--------------Advance operator---------------------------*/
			ReverseIterator& operator+= (int n)
			{
				return(this->iterator_type::operator-=(n));
			}

			/*--------------Subtraction operator---------------------------*/
			ReverseIterator operator- (int n) const
			{
				ReverseIterator tmp(*this);
				return(tmp.iterator_type::operator+(n));
			}


			/*---------Decrement operator position -------------------*/
			/*--------------------prefix------------------------------*/
			ReverseIterator & operator--()
			{
				iterator_type::operator++();
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			ReverseIterator operator--(int)
			{
				ReverseIterator tmp(*this);
				operator--();
				return (tmp);
			}

			/*--------------Retrocede operator---------------------------*/
			ReverseIterator& operator-= (int n)
			{
				return(this->iterator_type::operator+=(n));
			}


			/*--------Dereference iterator with offset-------------------*/

			reference operator[] (int n) const
			{
				return (iterator_type::base()[-n - 1]);
			}
	}; //ReverseIterator

			/*------------ NON MEMBER FUNCTION OVERLOAD ------------------*/
			/*------------------------------------------------------------*/

			/*--------------Relationnal operator----------------------------*/

		template <class Iterator>
		bool operator== (const ReverseIterator<Iterator>& lhs,
						 const ReverseIterator<Iterator>& rhs){
							return (lhs.base().operator==(rhs.base()));
						}

		template <class Iterator>
		bool operator!= (const ReverseIterator<Iterator>& lhs,
						const ReverseIterator<Iterator>& rhs){
							return (lhs.base().operator!=(rhs.base()));
						}

		template <class Iterator>
		bool operator<  (const ReverseIterator<Iterator>& lhs,
						const ReverseIterator<Iterator>& rhs){
							return (lhs.base().operator>(rhs.base()));
						}

		template <class Iterator>
		bool operator<= (const ReverseIterator<Iterator>& lhs,
                   		const ReverseIterator<Iterator>& rhs){
							return (lhs.base().operator>=(rhs.base()));
						}

		template <class Iterator>
		bool operator>  (const ReverseIterator<Iterator>& lhs,
						const ReverseIterator<Iterator>& rhs){
							return (lhs.base().operator<(rhs.base()));
						}

		template <class Iterator>
		bool operator>= (const ReverseIterator<Iterator>& lhs,
                   		const ReverseIterator<Iterator>& rhs){
							return (lhs.base().operator<=(rhs.base()));
						}

		template <class Iterator>
		ReverseIterator<Iterator> operator+ (int n,
             const ReverseIterator<Iterator>& rev_it){
				 return (rev_it.operator+(n));
			 }

		template <class Iterator>
		int operator- (const ReverseIterator<Iterator>& lhs,
						const ReverseIterator<Iterator>& rhs){
				return (lhs.base().operator-(rhs.base()));
			}

} //namesapce ft

#endif