/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:00:41 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/24 14:35:02 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include "rev_iterator.hpp"
#include "utils.hpp"
#include <memory>
#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <cstddef>

namespace ft
{
	template < typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			/*----------------------------------ALIAS------------------------------------*/
			/*---------------------------------------------------------------------------*/
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef size_t													size_type;
			typedef ptrdiff_t												difference_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;

			typedef typename ft::Iterator<T>								iterator;
			typedef typename ft::Const_iterator<T>							const_iterator;
            typedef typename ft::ReverseIterator<ft::Iterator<T> >  		reverse_iterator;
            typedef typename ft::ReverseIterator<ft::Const_iterator<T> >   	const_reverse_iterator;


		private:
			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/

			value_type*	 	_vector; 	//tableau de value type
			allocator_type	_alloc;		//copie  objet allocator_type
			size_type		_size;		//vector size
			size_type		_capacity;	//vector capacity

		public:
			/*------------------------------------------------------------------------------*/
			/*------------------------------COPLIEN FORM -----------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------Default Constructor (empty container constructor)-----------------*/
			explicit vector (const allocator_type& alloc = allocator_type()):
				_alloc(alloc),
				_size(0),
				_capacity(0)
			{
				_vector = _alloc.allocate(_capacity);
			}

			/*---------------------------Fill constructor------------------------------------*/

			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()):
				_alloc(alloc),
				_size(n),
				_capacity(n)
				{
					_vector = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; ++i)
						_alloc.construct(_vector + i, val);
				}

			/*---------------------------Range constructor------------------------------------*/

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0):
			_alloc(alloc), _size(0), _capacity(0)
			{
				for (InputIterator it = first; it != last; it++)
					_capacity++;
				_vector = _alloc.allocate(_capacity);
				for (; first != last; first++)
					push_back(*first);
			}

			/*---------------------------Copy constructor------------------------------------*/
			vector (const vector& x) :
				_alloc(x._alloc), _size(x._size), _capacity(x._capacity)
			{
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_vector + i, x[i]);
			}

			/*-------------------------------Destructor------------------------------------*/
			~vector()
			{
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(&_vector[i]);
				_alloc.deallocate(_vector, _capacity);
			}

			/*---------------------------Assignement by copy------------------------------------*/
			vector& operator=(const vector& x)
			{
				if (this != &x)
				{
					for (size_type i = 0; i < _size; ++i)
						_alloc.destroy(&_vector[i]);
					_alloc.deallocate(_vector, _capacity);
					_capacity = x._capacity;
					_size = x._size;
					_vector = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; ++i)
						_alloc.construct(_vector + i, x[i]);
				}
				return (*this);
			}
			/*------------------------------------------------------------------------------*/
			/*------------------------------ ITERATORS -------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ begin() -----------------------------------*/
			iterator begin(){
				return (iterator(_vector));
			}

			const_iterator begin() const {
				return(const_iterator(_vector));
			}

			/*------------------------------ end() -----------------------------------*/
      		iterator end(){
				  return(iterator(_vector + _size));
			  }

			const_iterator end() const{
				return(const_iterator(_vector + _size));
			}

			/*------------------------------ rbegin() -----------------------------------*/

			reverse_iterator rbegin(){
				return(reverse_iterator(_vector + _size));
			}

			const_reverse_iterator rbegin() const {
				return(const_reverse_iterator(_vector + _size));
			}

			/*------------------------------ rend() -----------------------------------*/

			reverse_iterator rend(){
				return(reverse_iterator(_vector));
			}

			const_reverse_iterator rend() const {
				return(const_reverse_iterator(_vector));
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------ CAPACITY --------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ size() -----------------------------------*/
			size_type size() const					{ return(_size);}

			/*------------------------------ max_size() -----------------------------------*/
			size_type max_size() const{
				if (sizeof(value_type) == 1)
					return(std::numeric_limits<difference_type>::max());
				return(std::numeric_limits<size_type>::max() / sizeof(value_type));
			}

			/*------------------------------ resize() -----------------------------------*/
			// MacOs
			// si (n <= capacity * 2): capacity => capacity * 2
			// sinon: capacity => n

			// Linux
			// si (n <= size * 2): capacity => size * 2
			// sinon: capacity => n

			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
					while (n < _size)
						pop_back();
				else
				{
					if (n > _capacity)
					{
						if (n <= _size * 2)
							reserve(_size * 2);
						else
							reserve(n);
					}
					while (n > _size)
						push_back(val);
				}
			}

			/*------------------------------ capacity() -----------------------------------*/
			size_type capacity() const				{return (_capacity);}

			/*------------------------------ empty() -----------------------------------*/
			bool empty() const						{return (_size == 0);}

			/*------------------------------ reserve() -----------------------------------*/
			void reserve (size_type n){
				if (n > max_size())
					throw(std::length_error("vector"));
				if (n > _capacity)
				{
					if (!_capacity)
						_vector = _alloc.allocate(n);
					else
					{
						T* next;
						next = _alloc.allocate(n);
						for (unsigned long i = 0; i < _size; ++i)
						{
							_alloc.construct(next + i, _vector[i]);
							_alloc.destroy(_vector + i);
						}
						_alloc.deallocate(_vector, _capacity);
						_vector  =  next;
					}
					_capacity = n;
				}
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------ ELEMENT ACCESS --------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ operator[] -----------------------------------*/
      		reference operator[] (size_type n)					{	return (_vector[n]);	}

			const_reference operator[] (size_type n) const		{	return (_vector[n]);	}

			/*---------------------------------- at() --------------------------------------*/
      		reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("vector");
				return (_vector[n]);
			  }

			const_reference at (size_type n) const {
				if (n >= _size || !n)
					throw std::out_of_range("vector");
				return (_vector[n]);
			  }

			/*-------------------------------- front() ------------------------------------*/
			reference front() 									{	return (_vector[0]);	}

			const_reference front() const						{	return (_vector[0]);	}

			/*-------------------------------- back() -------------------------------------*/
      		reference back()							{	return (_vector[_size - 1]);	}

			const_reference back() const				{	return (_vector[_size - 1]);	}


			/*------------------------------------------------------------------------------*/
			/*--------------------------------- MODIFIERS ----------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*-------------------------------- assign() -------------------------------------*/
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last,
			  		typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
				clear();
				for (InputIterator it = first; it != last; it++)
					_size++;
				if (_size > _capacity)
				{
					_alloc.deallocate(_vector, _capacity);
					_vector = _alloc.allocate(_size);
					_capacity = _size;
				}
				_size = 0;
				for (;first != last; first++)
					push_back(*first);
			}

			void assign (size_type n, const value_type& val){
				clear();
				if (n > _capacity)
				{
					_alloc.deallocate(_vector, _capacity);
					_vector = _alloc.allocate(n);
					_capacity = n;
				}
				for (size_t i = 0; i < n; ++i)
					_alloc.construct(_vector + i, val);
				_size = n;
			}

			/*-------------------------------- push_back() ----------------------------------*/
			void push_back (const value_type & val){
				if (_size ==_capacity)
				{
					int n;
					if (!_capacity)
						n = 1;
					else
						n = _capacity * 2;
					reserve(n);
				}
				_alloc.construct(_vector + _size, val);
				_size++;

			}

			/*-------------------------------- pop_back() -----------------------------------*/
			void pop_back(){
				_size--;
				_alloc.destroy(_vector + _size);
			}

			/*-------------------------------- insert() -------------------------------------*/
			iterator insert (iterator position, const value_type& val){
				difference_type start = position - begin();
				insert(position, 1, val);
				return (iterator(&_vector[start]));
			}


    		void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type	start = position - begin();

				if ((_size + n) > _capacity)
					reserve(size() + n);
				for (size_type j = 0; j < (_size - start); ++j)
					_vector[_size + n - j -1 ] = _vector[_size - j - 1];
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(_vector + start + i, val);
				_size += n;
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				difference_type	start = position - begin();
				size_type n = 0;

				for (InputIterator it = first; it != last; ++it)
					n++;
				if ((_size + n) > _capacity)
					reserve(size() + n);
				for  (size_type j = 0; j < (_size - start); ++j)
					_vector[_size + n - j -1 ] = _vector[_size - j - 1];
				for (size_type i = 0; i < n; ++i)
				{
					_alloc.construct(_vector + start + i, *first);
					first++;
				}
				_size += n;
			}

			/*-------------------------------- erase() ---------------------------------------*/
			iterator erase (iterator position){
				iterator last = this->end();

				if (position == last)
					return (position);
				_alloc.destroy(&(*position));
				for (iterator it = position + 1; it != last; ++it)
					*(it - 1) = *it;
				_size--;
				_vector[_size] = 0;
				return (position);
			}

			iterator erase (iterator first, iterator last)
			{
				if (last > end())
					last = end();
				if (first == last || first == end())
					return (first);
				int n = last - first;
				if ( last == end())
				{
					for (int i = 0; i < n; i++)
						pop_back();
					return (last);
				}
				else
				{
					for (iterator it = first; it != last; ++it)
						_alloc.destroy(&(*it));
					for (iterator it2 = last; it2 != end(); ++it2)
						*(it2 - n) = *it2;
					_size -= n;
					return (first);
				}
			}

			/*-------------------------------- swap() -------------------------------------*/
			void swap (vector& x){
				swapElt(_vector, x._vector);
				swapElt(_alloc, x._alloc);
				swapElt(_capacity, x._capacity);
				swapElt(_size,x._size);
			}

			/*-------------------------------- clear() -------------------------------------*/
			void clear(){
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_vector + i);
				_size = 0;
			}

			/*------------------------ overload operator == --------------------------------*/
  			friend bool operator== (const vector & lhs, const vector & rhs)
			{
				if (lhs.size() != rhs.size())
					return (false);
				const_iterator itl = lhs.begin();
				for (const_iterator itr = rhs.begin(); itr != rhs.end(); itr++)
				{
					if ((*itl) != (*itr))
						return (false);
					itl++;
				}
				return (true);
			}

			/*------------------------ overload operator < --------------------------------*/
			friend bool operator< (const vector & lhs, const vector & rhs)
			{
				const_iterator itl = lhs.begin();
				const_iterator itle = lhs.end();
				const_iterator itr = rhs.begin();
				const_iterator itre = rhs.end();

				while (itl != itle && itr != itre)
				{
					if (*itl < *itr)
						return (true);
					else if(*itl > *itr)
						return (false);
					itl++;
					itr++;
				}
				return (lhs.size() < rhs.size());
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------- PRIVATE FONCTIONS -- -------------------------------*/
			/*------------------------------------------------------------------------------*/
		private:
			template<typename U>
			void swapElt(U & a, U & b)
			{
				U tmp =  a;
				a = b;
				b = tmp;
			}



	}; //class vector
			/*------------------------------------------------------------------------------*/
			/*------------------------------------------------------------------------------*/
			/*------------------------- NON MEMBERS OVERLOAD -------------------------------*/
			/*------------------------------------------------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------------------------------------------------------*/
			/*------------------------ RELATIONNAL OPERATORS -------------------------------*/
			/*------------------------------------------------------------------------------*/

			template <class T, class Alloc>
  			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
				  return (!(lhs == rhs));
			}

			template <class T, class Alloc>
  			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
				  return (!(rhs < lhs));
			}

			template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
				return (rhs < lhs);
			}

			template <class T, class Alloc>
			bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
				return (!(lhs < rhs));
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------ SWAP ------------------------------------------*/
			/*------------------------------------------------------------------------------*/
			template <class T, class Alloc>
			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)				{	x.swap(y);	}

			
} //namespace ft

#endif