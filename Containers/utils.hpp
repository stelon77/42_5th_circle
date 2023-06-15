/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:15:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 16:59:57 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* FONCTIONS UTILITAIRES */
#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>
#include <functional>

namespace ft
{

	/*
    * ------------------------------------------------------------- *
    * ---------------------- FT::ENABLE_IF ------------------------ *
    */

	template<bool Cond, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T>
			{ typedef T type; };

// 	template <class T>
// T foo(T t, typename enable_if<is_arithmetic<T>::value >::type* dummy = 0);

	/*
    * ------------------------------------------------------------- *
    * --------------------- FT::IS_INTEGRAL ----------------------- *
    */

	template <typename T>
	struct is_integral { static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<wchar_t> { static const bool value = true; };

	template <>
	struct is_integral<signed char> { static const bool value = true; };

	template <>
	struct is_integral<short int> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long int> { static const bool value = true; };

	template <>
	struct is_integral<long long int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long int> { static const bool value = true; };

	/*
	* ------------------------------------------------------------- *
	* ---------------------------- FT::PAIR ----------------------- *
	*/

	template <class T1, class T2>
	class pair
	{
		public:

			/*----------------------------------ALIAS------------------------------------*/
			/*---------------------------------------------------------------------------*/
			typedef T1														first_type;
			typedef T2														second_type;

			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/
		public:
			first_type	 	first;
			second_type		second;

		public:
			/*------------------------------------------------------------------------------*/
			/*------------------------------COPLIEN FORM -----------------------------------*/
			/*------------------------------------------------------------------------------*/
			/*---------------- Default Constructor -----------------------------------------*/
			pair() {}

			/*---------------- initialization Constructor ----------------------------------*/
			pair (const first_type& a, const second_type& b) :
				first(a), second(b) {}

			/*------------------------------ copy Constructor ------------------------------*/
			template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

			/*------------------------------ destructor ------------------------------------*/
			~pair() {}

			/*------------------------------ assignement -----------------------------------*/
			pair& operator= (const pair& pr) {
				if (this != &pr)
				{
					first = pr.first;
					second = pr.second;
				}
				return (*this);
			}
	}; //class pair

			/*------------------------------------------------------------------------------*/
			/*------------------------------------------------------------------------------*/
			/*-----------------------PAIR NON MEMBERS OVERLOAD -----------------------------*/
			/*------------------------------------------------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------------------------------------------------------*/
			/*------------------------ RELATIONNAL OPERATORS -------------------------------*/
			/*------------------------------------------------------------------------------*/

			template <class T1, class T2>
			bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return lhs.first==rhs.first && lhs.second==rhs.second; }

			template <class T1, class T2>
			bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return !(lhs==rhs); }

			template <class T1, class T2>
			bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

			template <class T1, class T2>
			bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return !(rhs<lhs); }

			template <class T1, class T2>
			bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return rhs<lhs; }

			template <class T1, class T2>
			bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return !(lhs<rhs); }

			/*------------------------------------------------------------------------------*/
			/*------------------------ MAKE_PAIR -------------------------------------------*/
			template <class T1,class T2>
			pair<T1,T2> make_pair (T1 x, T2 y)
			{
				return ( pair<T1,T2>(x,y) );
			}

	/*
	* ------------------------------------------------------------- *
	* ---------------------------- FT::LESS ----------------------- *
	*/

			template <class T>
			struct less : std::binary_function <T,T,bool>
			{
  				bool operator() (const T& x, const T& y) const
				{
					return (x < y);
				}
			};

} //namespace ft

#endif