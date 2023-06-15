/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:40:19 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 16:57:39 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "list_iterator.hpp"
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
	class list
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

			typedef typename ft::ListIterator<T>									iterator;
			typedef typename ft::ListConst_iterator<T>								const_iterator;
            typedef typename ft::ListReverseIterator<ft::ListIterator<T> >  		reverse_iterator;
            typedef typename ft::ListReverseIterator<ft::ListConst_iterator<T> >   	const_reverse_iterator;


		private:
			typedef typename ft::Node<T> 									Node;
			typedef typename Alloc::template rebind<Node>::other 			NodeAlloc;


			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/
			Node*	 		_neutralNode; 	//pointeur sur le node neutre
			NodeAlloc		_nodeAlloc;  //allocateur de noeud
			allocator_type	_alloc;		//copie  objet allocator_type
			size_type		_size;		//list size

		public:
			/*------------------------------------------------------------------------------*/
			/*------------------------------COPLIEN FORM -----------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------Default Constructor (empty container constructor)-----------------*/
			explicit list (const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _size(0)
			{
				_neutralNode = createNeutralNode();
			}

			/*---------------------------Fill constructor------------------------------------*/
			explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()):
					_alloc(alloc),_size(0)
			{
				_neutralNode = createNeutralNode();
				for (size_type i = 0; i < n; ++i)
					push_front(val);
			}

			/*---------------------------Range constructor------------------------------------*/
			template <class InputIterator>
			list (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0):
				_alloc(alloc), _size(0)
			{
				_neutralNode = createNeutralNode();
				for (; first != last; first++)
					push_back(*first);
			}

			/*---------------------------Copy constructor------------------------------------*/
			list (const list& x) :
				_nodeAlloc(x._nodeAlloc), _alloc(x._alloc), _size(0)
			{
				_neutralNode = createNeutralNode();
				Node* tmp  = x._neutralNode->next;
				for (size_type i = 0; i < x._size ; i++)
					push_back(tmp->data);
			}

			/*-------------------------------Destructor------------------------------------*/
			~list()
			{
				for (size_type i = 0; i < _size ; i++)
					destroyNode(_neutralNode->next);
				_nodeAlloc.deallocate(_neutralNode, 1);
			}

			/*---------------------------Assignement by copy------------------------------------*/
			list& operator=(const list& x)
			{
				if (this != &x)
				{
					for (size_type i = 0; i < _size; ++i)
						destroyNode(_neutralNode->next);
					_size = 0;
					for (const_iterator it = x.begin(); it != x.end(); it++)
						push_back(*it);
				}
				return (*this);
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------ ITERATORS -------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ begin() -----------------------------------*/
			iterator begin(){
				return (iterator(_neutralNode->next));
			}

			const_iterator begin() const {
				return(const_iterator(_neutralNode->next));
			}

			/*------------------------------ end() -----------------------------------*/
      		iterator end(){
				  return(iterator(_neutralNode));
			  }

			const_iterator end() const{
				return(const_iterator(_neutralNode));
			}
			/*------------------------------ rbegin() -----------------------------------*/

			reverse_iterator rbegin(){
				return(reverse_iterator(_neutralNode));
			}

			const_reverse_iterator rbegin() const {
				return(const_reverse_iterator(_neutralNode));
			}

			/*------------------------------ rend() -----------------------------------*/

			reverse_iterator rend(){
				return(reverse_iterator(_neutralNode->next));
			}

			const_reverse_iterator rend() const {
				return(const_reverse_iterator(_neutralNode->next));
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------ CAPACITY --------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ empty() -----------------------------------*/
			bool empty() const						{	return(_size == 0);	}

			/*------------------------------ size() -----------------------------------*/
			size_type size() const					{	return(_size);		}

			/*------------------------------ max_size() -----------------------------------*/
			size_type max_size() const				{	return(_nodeAlloc.max_size());	}


			/*------------------------------------------------------------------------------*/
			/*------------------------------ ELEMENT ACCESS --------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ front() ---------------------------------------*/
			reference front()						{	return(_neutralNode->next->data);	}

			const_reference front() const			{	return(_neutralNode->next->data);	}

			/*------------------------------ back() ---------------------------------------*/

			reference back()						{	return(_neutralNode->prev->data);	}

			const_reference back() const			{	return(_neutralNode->prev->data);	}


			/*------------------------------------------------------------------------------*/
			/*--------------------------------- MODIFIERS ----------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*-------------------------------- assign() -------------------------------------*/
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
			  	typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				clear();
				for (; first != last; first++)
					push_back(*first);
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				while (_size < n)
					push_back(val);
			}


			/*------------------------------ push_front() ---------------------------------------*/
			void push_front (const value_type& val)
			{
				Node* newNode = createNode(val);
				newNode->next = _neutralNode->next;
				_neutralNode->next = newNode;
				newNode->next->prev = newNode;
				newNode->prev = _neutralNode;
				_size++;
			}

			/*------------------------------ pop_front() ---------------------------------------*/
			void pop_front()
			{
				if (_size)
				{
					destroyNode(_neutralNode->next);
					_size--;
				}
			}

			/*------------------------------ push_back() ---------------------------------------*/
			void push_back (const value_type& val)
			{
				Node* newNode = createNode(val);
				newNode->next = _neutralNode;
				newNode->prev = _neutralNode->prev;
				newNode->prev->next = newNode;
				_neutralNode->prev = newNode;
				_size++;
			}

			/*------------------------------ pop_back() ---------------------------------------*/
			void pop_back()
			{
				if (_size)
				{
					destroyNode(_neutralNode->prev);
					_size--;
				}
			}

			/*------------------------------ insert() ---------------------------------------*/
			iterator insert (iterator position, const value_type& val)
			{

				Node* newNode = createNode(val);

				newNode->next = position.getNode();
				newNode->prev = position.getNode()->prev;
				newNode->prev->next = newNode;
				position.getNode()->prev = newNode;
				_size++;
				return (--position);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				while (n)
				{
					insert(position, val);
					n--;
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				for(; first != last; first++)
				{
					Node* newNode = createNode(*first);

					newNode->next = position.getNode();
					newNode->prev = position.getNode()->prev;
					newNode->prev->next = newNode;
					position.getNode()->prev = newNode;
					_size++;
				}
			}

			/*-------------------------------- erase() -------------------------------------*/

			iterator erase (iterator position)
			{
				iterator it = position;
				it++;
				return(erase(position, it));
			}

			iterator erase (iterator first, iterator last)
			{
				if (first == end() || first == last)
					return (first);
				while (first != last)
				{
					iterator tmp = first++;
					destroyNode(tmp.getNode());
					_size--;
				}
				return (last);
			}

			/*-------------------------------- swap() -------------------------------------*/
			void swap (list& x)
			{
				swapElt(_neutralNode, x._neutralNode);
				swapElt(_alloc, x._alloc);
				swapElt(_nodeAlloc, x._nodeAlloc);
				swapElt(_size, x._size);
			}

			/*-------------------------------- resize() --------------------------------------*/
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
					while (_size > n)
						pop_back();
				else
				{
					while(_size < n)
						push_back(val);
				}
			}

			/*-------------------------------- clear() -------------------------------------*/
			void clear(){
				while (_size)
					pop_back();
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------- OPERATIONS -----------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*-------------------------------- splice() -------------------------------------*/
			void splice (iterator position, list& x)
			{
				if (this != &x)
					splice(position, x, x.begin(), x.end());
				else
					clear(); //comportement macOs, a voir sur linux
			}

			void splice (iterator position, list& x, iterator i)
			{
				splice(position, x, i, ++i);
			}

			void splice (iterator position, list& x, iterator first, iterator last)
			{
				//on verifie d'abord que position n'est pas entre first et last si x = this
				if (this == &x)
					for (iterator it = first; it != last; it++)
						if (it == position)
							return;
				if (first == x.end())
					return;
				while (first != last)
				{
					iterator tmp = first;
					tmp++; //pointe sur le prochain elt dans  la liste x
					//on deconnecte first de x
					first.getNode()->next->prev = first.getNode()->prev;
					first.getNode()->prev->next = first.getNode()->next;
					//on le raccroche a la nouvelle liste
					first.getNode()->next = position.getNode();
					first.getNode()->prev = position.getNode()->prev;
					first.getNode()->prev->next = first.getNode();
					position.getNode()->prev = first.getNode();
					_size++;
					x._size--;
					first = tmp;
				}
			}

			/*-------------------------------- remove() -------------------------------------*/
			void remove (const value_type& val)
			{
				iterator it = begin();
				while(it != end())
				{
					if (*it == val)
						it = erase(it);
					else
						it++;
				}
			}

			/*-------------------------------- remove_if() -------------------------------------*/
			template <class Predicate>
			void remove_if (Predicate pred)
			{
				iterator it = begin();
				while(it != end())
				{
					if (pred(*it))
						it = erase(it);
					else
						it++;
				}
			}

			/*---------------------------------- unique() ---------------------------------------*/
			void unique()
			{
				iterator it = ++(begin());
				iterator tmp;
				while (it != end())
				{
					tmp = it;
					tmp--;
					if (*it == *tmp)
						it = erase(it);
					else
						it++;
				}
			}

			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				iterator it = ++(begin());
				iterator tmp;
				while (it != end())
				{
					tmp = it;
					tmp--;
					if (binary_pred(*it, *tmp))
						it = erase(it);
					else
						it++;
				}
			}

			/*---------------------------------- merge() ---------------------------------------*/
			void merge (list& x)
			{
				if (this == &x)
					return;
				iterator it = begin();
				while (it != end() && x.size() > 0)
				{
					while (x.size() && (*(x.begin()) < *it))
						splice(it, x, x.begin());
					it++;
				}
				while (x.size())
					splice (end(), x);
			}

			template <class Compare>
			void merge (list& x, Compare comp)
			{
				if (this == &x)
					return;
				iterator it = begin();
				while (it != end() && x.size() > 0)
				{
					while (x.size() && comp((*(x.begin())), *it))
						splice(it, x, x.begin());
					it++;
				}
				while (x.size())
					splice (end(), x);
			}

			/*---------------------------------- sort() ---------------------------------------*/
			void sort()
			{
				iterator it = begin();
				iterator it2;

				while (it != --end())
				{
					it2 = it;
					it2++;
					while (it2 != end())
					{
						if (*it2 < *it)
							swapElt(*it2, *it);
						it2++;
					}
					it++;
				}
			}

			template <class Compare>
			void sort (Compare comp)
			{
				iterator it = begin();
				iterator it2;

				while (it != --end())
				{
					it2 = it;
					it2++;
					while (it2 != end())
					{
						if (comp(*it2, *it))
							swapElt(*it2, *it);
						it2++;
					}
					it++;
				}
			}

			/*---------------------------------- reverse() ---------------------------------------*/
			void reverse()
			{
				iterator it = begin();
				for (size_type n = 1; n < _size; n++)
					splice(it, *this, --end());
			}


			/*------------------------ overload operator == --------------------------------*/
  			friend bool operator== (const list & lhs, const list & rhs)
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
			friend bool operator< (const list & lhs, const list & rhs)
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
			/*------------------ PRIVATE MEMBER FUNCTION -----------------------------------*/
			/*------------------------------------------------------------------------------*/
		private:
			/* ----------------createNeutralNode() ----------------------------------------**
			** cree et renvoie le noeud neutre de la liste circulaire ,
			** data non construite car nulle
			*/
			Node* createNeutralNode(void)
			{
				Node* neutralNode = _nodeAlloc.allocate(1);
				neutralNode->next = neutralNode;
				neutralNode->prev = neutralNode;
				return (neutralNode);
			}

			/* ---------------- createNode(value) ----------------------------------------**
			** cree et renvoie un noeud de la liste circulaire ,
			** data remplie avec value
			*/
			Node* createNode(const value_type & val)
			{
				Node* newNode = _nodeAlloc.allocate(1);
				_alloc.construct(&newNode->data, val);
				return (newNode);
			}

			/* ---------------- destroyNode(node*) ----------------------------------------**
			** detruit la data  et desalloue le noeud pointe
			*/
			void destroyNode(Node* node)
			{
				node->prev->next = node->next;
				node->next->prev = node->prev;

				_alloc.destroy(&node->data);
				_nodeAlloc.deallocate(node, 1);
			}

			/* ---------------- swapElt() ----------------------------------------**
			** echange 2 elements
			*/
			template<typename U>
				void swapElt(U & a, U & b)
				{
					U tmp =  a;
					a = b;
					b = tmp;
				}

	};//class list

			/*------------------------------------------------------------------------------*/
			/*------------------------------------------------------------------------------*/
			/*------------------------- NON MEMBERS OVERLOAD -------------------------------*/
			/*------------------------------------------------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------------------------------------------------------*/
			/*------------------------ RELATIONNAL OPERATORS -------------------------------*/
			/*------------------------------------------------------------------------------*/

			template <class T, class Alloc>
  			bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
				  return (!(lhs == rhs));
			}

			template <class T, class Alloc>
  			bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
				  return (!(rhs < lhs));
			}

			template <class T, class Alloc>
			bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
				return (rhs < lhs);
			}

			template <class T, class Alloc>
			bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
				return (!(lhs < rhs));
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------ SWAP ------------------------------------------*/
			/*------------------------------------------------------------------------------*/
			template <class T, class Alloc>
			void swap (list<T,Alloc>& x, list<T,Alloc>& y)				{	x.swap(y);	}

} //namespace ft

#endif