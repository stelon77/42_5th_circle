/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 23:00:59 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 19:15:27 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* RANDOM ACCESS ITERATOR */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

namespace ft
{
	template <typename T>
	class Iterator
	{
		public:

			/*-------------------------ALIAS-----------------*/
			/*-----------------------------------------------*/
			typedef T					value_type;
			typedef const T				const_value_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;

		protected:
			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/

			T*	_current; //pointeur sur membre du container

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/

			/*------------Default Constructor-----------------*/
			/*-----create an iterator pointing on val---------*/
			Iterator(T* value = 0):
				_current (value){}

			/*------------ Constructor const------------------------------*/
			/*-----create an iterator pointing on const val---------*/
			Iterator(const T* value):
				_current (value){}

			/*------------Copy Constructor---------------------*/
			/*-----create an iterator by copy------------------*/
			Iterator(Iterator const & other):
				_current (other._current){}

			/*------------Destructor-----------------------*/
			/*---------------------------------------------*/
			~Iterator(){}

			/*--------Assignement Constructor-------------------------*/
			/*-----create an iterator by assignement------------------*/
			Iterator & operator=(const Iterator & other)
			{
				if (this != &other)
					_current = other._current;
				return (*this);
			}

			/*-------------BIDIRECTIONNAL ITERATOR------------------*/
			/*------------------------------------------------------*/
			/*------------------------------------------------------*/

			/*---------------Incrementation- (++)---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			Iterator & operator++()
			{
				_current++;
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			Iterator operator++(int)
			{
				Iterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*---------------Decrementation ()---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			Iterator & operator--()
			{
				_current--;
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			Iterator operator--(int)
			{
				Iterator tmp(*this);
				operator--();
				return (tmp);
			}

			/*-------------Equality comparison----------------------*/
			/*------------------------------------------------------*/
			bool operator==(const Iterator & rhs) const {return (_current == rhs._current);}

			/*-------------Inequality comparison----------------------*/
			/*--------------------------------------------------------*/
			bool operator!=(const Iterator & rhs) const {return (_current != rhs._current);}

			/*--------------Dereferencement---------------------------*/
			/*--------------------------------------------------------*/
			reference 	operator*() const {return (*_current);}
			pointer		operator->() const {return (_current);}


			/*-------------RANDOM ACCESS ITERATOR------------------*/
			/*------------------------------------------------------*/
			/*------------------------------------------------------*/

			/*--------------Inequality comparison--------------------------*/
			/*-------------------------------------------------------------*/
			bool operator>(const Iterator & rhs) const {return (_current > rhs._current);}
			bool operator<(const Iterator & rhs) const {return (_current < rhs._current);}
			bool operator>=(const Iterator & rhs) const {return (_current >= rhs._current);}
			bool operator<=(const Iterator & rhs) const {return (_current <= rhs._current);}

			/*--------------Compound operation += and -= --------------------------*/
			/*---------------------------------------------------------------------*/
			Iterator & operator+=(int value)
			{
				_current += value;
				return(*this);
			}

			Iterator & operator-=(int value)
			{
				_current -= value;
				return(*this);
			}

			/*--------------Arithmetic operator + and - ---------------------------*/
			/*---------------------------------------------------------------------*/
			Iterator operator+(int value) const
			{
				Iterator tmp(*this);
				tmp += value;
				return (tmp);
			}

			Iterator operator-(int value) const
			{
				Iterator tmp(*this);
				tmp -= value;
				return (tmp);
			}

			/*-------------- offset dereference operator---------------------------*/
			/*---------------------------------------------------------------------*/
			reference operator[](int n)
			{
				Iterator it(*this);
				it += n;
				return (*(it._current));
			}

			/*--------------Arithmetic operator - between iterators----------------*/
			/*---------------------------------------------------------------------*/
			long int operator-(Iterator const & it) const
			{
				long int ret = (_current - it._current);
				if (ret < 0)
					ret *= -1;
				return (ret);
			}

			Iterator base()	const {return (*this);}

	}; //class iterator



	template <typename T>
	class Const_iterator
	{
		public:

			/*-------------------------ALIAS-----------------*/
			/*-----------------------------------------------*/
			typedef T					value_type;
			typedef const T				const_value_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;

		private:
			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/

			T*	_current; //pointeur sur membre du container

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/

			/*------------Default Constructor-----------------*/
			/*-----create an iterator pointing on val---------*/
			Const_iterator(T* value = 0):
				_current (value){}

			/*------------ Constructor const------------------------------*/
			/*-----create an iterator pointing on const val---------*/
			Const_iterator(const T* value):
				_current (value){}

			/*------------Copy Constructor---------------------*/
			/*-----create an iterator by copy------------------*/
			Const_iterator(Const_iterator const & other):
				_current (other._current){}

			/*------------Destructor-----------------------*/
			/*---------------------------------------------*/
			~Const_iterator(){}

			/*--------Assignement Constructor-------------------------*/
			/*-----create an iterator by assignement------------------*/
			Const_iterator & operator=(const Const_iterator & other)
			{
				if (this != &other)
					_current = other._current;
				return (*this);
			}

			/*-------------BIDIRECTIONNAL ITERATOR------------------*/
			/*------------------------------------------------------*/
			/*------------------------------------------------------*/

			/*---------------Incrementation- (++)---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			Const_iterator & operator++()
			{
				_current++;
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			Const_iterator operator++(int)
			{
				Const_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*---------------Decrementation ()---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			Const_iterator & operator--()
			{
				_current--;
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			Const_iterator operator--(int)
			{
				Const_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			/*-------------Equality comparison----------------------*/
			/*------------------------------------------------------*/
			bool operator==(const Const_iterator & rhs) const {return (_current == rhs._current);}

			/*-------------Inequality comparison----------------------*/
			/*--------------------------------------------------------*/
			bool operator!=(const Const_iterator & rhs) const {return (_current != rhs._current);}

			/*--------------Dereferencement---------------------------*/
			/*--------------------------------------------------------*/
			const_reference 	operator*() const {return (*_current);}
			const_pointer		operator->() const {return (_current);}


			/*-------------RANDOM ACCESS ITERATOR------------------*/
			/*------------------------------------------------------*/
			/*------------------------------------------------------*/

			/*--------------Inequality comparison--------------------------*/
			/*-------------------------------------------------------------*/
			bool operator>(const Const_iterator & rhs) const {return (_current > rhs._current);}
			bool operator<(const Const_iterator & rhs) const {return (_current < rhs._current);}
			bool operator>=(const Const_iterator & rhs) const {return (_current >= rhs._current);}
			bool operator<=(const Const_iterator & rhs) const {return (_current <= rhs._current);}

			/*--------------Compound operation += and -= --------------------------*/
			/*---------------------------------------------------------------------*/
			Const_iterator & operator+=(int value)
			{
				_current += value;
				return(*this);
			}

			Const_iterator & operator-=(int value)
			{
				_current -= value;
				return(*this);
			}

			/*--------------Arithmetic operator + and - ---------------------------*/
			/*---------------------------------------------------------------------*/
			Const_iterator operator+(int value) const
			{
				Const_iterator tmp(*this);
				tmp += value;
				return (tmp);
			}

			Const_iterator operator-(int value) const
			{
				Const_iterator tmp(*this);
				tmp -= value;
				return (tmp);
			}

			/*-------------- offset dereference operator---------------------------*/
			/*---------------------------------------------------------------------*/
			reference operator[](int n)
			{
				Const_iterator it(*this);
				it += n;
				return (*(it._current));
			}

			/*--------------Arithmetic operator - between iterators----------------*/
			/*---------------------------------------------------------------------*/
			long int operator-(Const_iterator const & it) const
			{
				long int ret = (_current - it._current);
				if (ret < 0)
					ret *= -1;
				return (ret);
			}
	}; //class const_iterator
} //namespace ft



#endif