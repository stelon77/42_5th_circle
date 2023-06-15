/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 23:00:59 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/24 15:27:02 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include <cstddef>

namespace ft
{
	template <typename T>
	struct Node
	{
		T		data;
		Node* 	prev;
		Node*	next;
	};

	template <typename T>
	class ListIterator
	{
		public:

			/*-------------------------ALIAS-----------------*/
			/*-----------------------------------------------*/
			typedef size_t 				size_type;
			typedef ptrdiff_t			difference_type;
			typedef T					value_type;
			typedef const T				const_value_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;
			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;

		protected:
			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/

			Node<T>*	_node; //pointeur sur noeud du container

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/


			/*------------Default Constructor-----------------*/
			/*-----create an iterator pointing on node---------*/
			ListIterator(Node<T>* node = 0):
				_node (node){}

			/*------------ Constructor const------------------------------*/
			/*-----create an iterator pointing on const node---------*/
			ListIterator(const Node<T>* node):
				_node (node){}

			/*------------Copy Constructor---------------------*/
			/*-----create an iterator by copy------------------*/
			ListIterator(ListIterator const & other):
				_node (other._node){}

			/*------------Destructor-----------------------*/
			/*---------------------------------------------*/
			~ListIterator(){}

			/*--------Assignement Constructor-------------------------*/
			/*-----create an iterator by assignement------------------*/
			ListIterator & operator=(const ListIterator & other)
			{
				if (this != &other)
					_node = other._node;
				return (*this);
			}

			/*-------------BIDIRECTIONNAL ITERATOR------------------*/
			/*------------------------------------------------------*/
			/*------------------------------------------------------*/

			/*---------------Incrementation (++)----------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			ListIterator & operator++()
			{
				_node = _node->next;
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			ListIterator operator++(int)
			{
				ListIterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*---------------Decrementation ()---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			ListIterator & operator--()
			{
				_node = _node->prev;
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			ListIterator operator--(int)
			{
				ListIterator tmp(*this);
				operator--();
				return (tmp);
			}

			/*-------------Equality comparison----------------------*/
			/*------------------------------------------------------*/
			bool operator==(const ListIterator & rhs) const {return (_node == rhs._node);}

			/*-------------Inequality comparison----------------------*/
			/*--------------------------------------------------------*/
			bool operator!=(const ListIterator & rhs) const {return (_node != rhs._node);}

			/*--------------Dereferencement---------------------------*/
			/*--------------------------------------------------------*/
			reference 		operator*() const {return (_node->data);}
			pointer			operator->() const {return (&(_node->data));}


			ListIterator	base()	const {return (*this);}
			Node<T>*		getNode() const {return (_node);}


	}; //class ListIterator

	template <typename T>
	class ListConst_iterator
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

			Node<T>*	_node; //pointeur sur noeud du container

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/

			/*------------Default Constructor-----------------*/
			/*-----create an iterator pointing on val---------*/
			ListConst_iterator(Node<T>* node = 0):
				_node (node){}

			/*------------ Constructor const------------------------------*/
			/*-----create an iterator pointing on const val---------*/
			ListConst_iterator(const Node<T>* node):
				_node (node){}

			/*------------Copy Constructor---------------------*/
			/*-----create an iterator by copy------------------*/
			ListConst_iterator(ListConst_iterator const & other):
				_node (other._node){}

			/*------------Destructor-----------------------*/
			/*---------------------------------------------*/
			~ListConst_iterator(){}

			/*--------Assignement Constructor-------------------------*/
			/*-----create an iterator by assignement------------------*/
			ListConst_iterator & operator=(const ListConst_iterator & other)
			{
				if (this != &other)
					_node = other._node;
				return (*this);
			}

			/*-------------BIDIRECTIONNAL ITERATOR------------------*/
			/*------------------------------------------------------*/
			/*------------------------------------------------------*/

			/*---------------Incrementation (++)----------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			ListConst_iterator & operator++()
			{
				_node = _node->next;
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			ListConst_iterator operator++(int)
			{
				ListConst_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*---------------Decrementation ()---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			ListConst_iterator & operator--()
			{
				_node = _node->prev;
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			ListConst_iterator operator--(int)
			{
				ListConst_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			/*-------------Equality comparison----------------------*/
			/*------------------------------------------------------*/
			bool operator==(const ListConst_iterator & rhs) const {return (_node == rhs._node);}

			/*-------------Inequality comparison----------------------*/
			/*--------------------------------------------------------*/
			bool operator!=(const ListConst_iterator & rhs) const {return (_node != rhs._node);}

			/*--------------Dereferencement---------------------------*/
			/*--------------------------------------------------------*/
			const_reference 	operator*() const {return (_node->data);}
			const_pointer		operator->() const {return (&(_node->data));}

			ListConst_iterator	base()	const {return (*this);}
			const Node<T>*		getNode() const {return (_node);}

	}; //class ListConst_iterator


	template <typename ListIterator >
	class ListReverseIterator : public ListIterator
	{
		public:

			/*-------------------------ALIAS-----------------*/
			/*-----------------------------------------------*/
			typedef ListIterator								iterator_type;
			typedef typename ListIterator::value_type			value_type;
			typedef typename ListIterator::const_value_type		const_value_type;
			typedef typename ListIterator::reference 			reference;
			typedef typename ListIterator::const_reference 		const_reference;
			typedef typename ListIterator::pointer 				pointer;
			typedef typename ListIterator::const_pointer 		const_pointer;

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/

			/*------------Default Constructor------------------------------------*/
			/*-----create an reverseiterator pointing on null--------------------*/
			ListReverseIterator(): ListIterator() {}

			/*------------Constructor with initialisation-------------------------*/
			ListReverseIterator(const iterator_type & it) : ListIterator(it){}

			/*------------Constructor by copy-------------------------------------*/
			ListReverseIterator(const ListReverseIterator & other) : ListIterator(other._node){}

			/*------------Destructor----------------------------------------------*/
			~ListReverseIterator(){}

			/*------------operator = (assignation)-------------------------------------*/
			ListReverseIterator operator=(const ListReverseIterator & other){
				if (this != &other)
					this->_node = other._node;
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
				ListIterator tmp(*this);
				return (*--tmp);//ie _node->previous->data
			}

			pointer		operator->() const {return (iterator_type::operator->());}

			// /*--------------Addition operator---------------------------*/
			// ListReverseIterator operator+ (int n) const
			// {
			// 	ListReverseIterator tmp(*this);
			// 	return(tmp.iterator_type::operator-(n));
			// }

			/*---------Increment operator position -------------------*/
			/*--------------------prefix------------------------------*/
			ListReverseIterator & operator++()
			{
				iterator_type::operator--();
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			ListReverseIterator operator++(int)
			{
				ListReverseIterator tmp(*this);
				operator++();
				return (tmp);
			}

			// /*--------------Advance operator---------------------------*/
			// ListReverseIterator& operator+= (int n)
			// {
			// 	return(this->iterator_type::operator-=(n));
			// }

			// /*--------------Subtraction operator---------------------------*/
			// ListReverseIterator operator- (int n) const
			// {
			// 	ListReverseIterator tmp(*this);
			// 	return(tmp.iterator_type::operator+(n));
			// }


			/*---------Decrement operator position -------------------*/
			/*--------------------prefix------------------------------*/
			ListReverseIterator & operator--()
			{
				iterator_type::operator++();
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			ListReverseIterator operator--(int)
			{
				ListReverseIterator tmp(*this);
				operator--();
				return (tmp);
			}

			// /*--------------Retrocede operator---------------------------*/
			// ListReverseIterator& operator-= (int n)
			// {
			// 	return(this->iterator_type::operator+=(n));
			// }


			// /*--------Dereference iterator with offset-------------------*/

			// reference operator[] (int n) const
			// {
			// 	return (iterator_type::base()[- n - 1]);
			// }
	}; //ListReverseIterator

			/*------------ NON MEMBER FUNCTION OVERLOAD ------------------*/
			/*------------------------------------------------------------*/

			/*--------------Relationnal operator----------------------------*/

		template <class Iterator>
		bool operator== (const ListReverseIterator<Iterator>& lhs,
						 const ListReverseIterator<Iterator>& rhs){
							return (lhs.base().operator==(rhs.base()));
						}

		template <class Iterator>
		bool operator!= (const ListReverseIterator<Iterator>& lhs,
						const ListReverseIterator<Iterator>& rhs){
							return (lhs.base().operator!=(rhs.base()));
						}

		// template <class Iterator>
		// bool operator<  (const ListReverseIterator<Iterator>& lhs,
		// 				const ListReverseIterator<Iterator>& rhs){
		// 					return (lhs.base().operator>(rhs.base()));
		// 				}

		// template <class Iterator>
		// bool operator<= (const ListReverseIterator<Iterator>& lhs,
        //            		const ListReverseIterator<Iterator>& rhs){
		// 					return (lhs.base().operator>=(rhs.base()));
		// 				}

		// template <class Iterator>
		// bool operator>  (const ListReverseIterator<Iterator>& lhs,
		// 				const ListReverseIterator<Iterator>& rhs){
		// 					return (lhs.base().operator<(rhs.base()));
		// 				}

		// template <class Iterator>
		// bool operator>= (const ListReverseIterator<Iterator>& lhs,
        //            		const ListReverseIterator<Iterator>& rhs){
		// 					return (lhs.base().operator<=(rhs.base()));
		// 				}

		// template <class Iterator>
		// ListReverseIterator<Iterator> operator+ (int n,
        //      const ListReverseIterator<Iterator>& rev_it){
		// 		 return (rev_it.operator+(n));
		// 	 }

		// template <class Iterator>
		// int operator- (const ListReverseIterator<Iterator>& lhs,
		// 				const ListReverseIterator<Iterator>& rhs){
		// 		return (lhs.base().operator-(rhs.base()));
		// 	}
} //namespace ft

#endif