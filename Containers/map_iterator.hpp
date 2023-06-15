
#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "utils.hpp"
#include "iostream"
#include <cstddef>

namespace ft
{
	template <typename Key, typename T>
	struct MapNode
	{
		private:
			bool _unused;
			#if __APPLE__ == 0
			int _unused_for_linux;
			#endif

		public:
			pair<Key, T>				data;
			MapNode* 					left;
			MapNode*					right;
			MapNode*					parent;

			MapNode() : data(ft::pair< Key, T>()) {}
			MapNode(const ft::pair<Key, T> pair) : data(pair) {}
			MapNode(const MapNode<Key, T> & other) :
				data(other.data), left(other.left), right(other.right), parent(other.parent) {}
			MapNode* operator=(const MapNode<Key, T> & other){
				if (this != &other)
				{
					data = other.data;
					left = other.left;
					right = other.right;
					parent = other.parent;
				}
				return (*this);
			}
	};


	template <typename Key, typename T>
	class MapIterator
	{
		public:

			/*-------------------------ALIAS-----------------*/
			/*-----------------------------------------------*/
			typedef size_t 					size_type;
			typedef ptrdiff_t				difference_type;
			typedef pair<Key, T>			value_type;
			typedef const pair<Key, T>		const_value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef value_type*				pointer;
			typedef const value_type*		const_pointer;

		protected:
			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/

			MapNode<Key, T>*	_node; //pointeur sur noeud du container

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/

			/*------------Default Constructor------------------*/
			/*-----create an iterator pointing on node---------*/
			MapIterator(MapNode<Key, T>* node = 0):
				_node (node){}

			/*------------ Constructor const------------------------------*/
			/*-----create an iterator pointing on const node---------*/
			MapIterator(const MapNode<Key, T>* node):
				_node (node){}

			/*------------Copy Constructor---------------------*/
			/*-----create an iterator by copy------------------*/
			MapIterator(MapIterator const & other):
				_node (other._node){}

			/*------------Destructor-----------------------*/
			/*---------------------------------------------*/
			~MapIterator(){}

			/*--------Assignement Constructor-------------------------*/
			/*-----create an iterator by assignement------------------*/
			MapIterator & operator=(const MapIterator & other)
			{
				if (this != &other)
					_node = other._node;
				return (*this);
			}

			/*-------------BIDIRECTIONNAL ITERATOR------------------*/
			/*------------------------------------------------------*/
			/*------------------------------------------------------*/

			/*---------------Incrementation- (++)---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			MapIterator & operator++()
			{
				MapNode<Key, T>* back;

				if (_node->right)
				{
					_node = _node->right;
					while (_node && _node->left != NULL && _node->left->right != _node)//le dernier c'est le noeud neutre
						_node = _node->left;
				}
				else if (_node == _node->parent->left)
					_node = _node->parent;
				else
				{
					back = _node->parent;
					_node = back->parent;
					if (back == _node->right)
					{
						while (_node == _node->parent->right)
							_node = _node->parent;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			MapIterator operator++(int)
			{
				MapIterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*---------------Decrementation ()---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			MapIterator & operator--()
			{
				MapNode<Key, T>* back;

				if (_node->left && _node->left->right == _node) // on est sur begin()
					_node = _node->left;
				else if (_node->left)
				{
					_node = _node->left;
					while (_node && _node->right != NULL && _node->left->right != _node) //le dernier c'est le noeud neutre
						_node = _node->right;
				}
				else if (_node == _node->parent->right)
					_node = _node->parent;
				else
				{
					back = _node->parent;
					_node = back->parent;
					if (back == _node->left)
					{
						while (_node == _node->parent->left)
							_node = _node->parent;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			MapIterator operator--(int)
			{
				MapIterator tmp(*this);
				operator--();
				return (tmp);
			}

			/*-------------Equality comparison----------------------*/
			/*------------------------------------------------------*/
			bool operator==(const MapIterator & rhs) const {return (_node == rhs._node);}

			/*-------------Inequality comparison----------------------*/
			/*--------------------------------------------------------*/
			bool operator!=(const MapIterator & rhs) const {return (_node != rhs._node);}

			/*--------------Dereferencement---------------------------*/
			/*--------------------------------------------------------*/
			reference			operator*() const {return (_node->data);}
			pointer				operator->() const {return (&(_node->data));}

			MapIterator					base()	const {return (*this);}
			MapNode<Key, T>*			getNode() const {return (_node);}


	}; //class MapIterator

	template <typename Key, typename T>
	class MapConst_iterator
	{
		public:

			/*-------------------------ALIAS-----------------*/
			/*-----------------------------------------------*/
			typedef pair<Key, T>				value_type;
			typedef const pair <Key, T>			const_value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;

		protected:
			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/

			MapNode<Key, T>*	_node; //pointeur sur noeud du container

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/

			/*------------Default Constructor-----------------*/
			/*-----create an iterator pointing on val---------*/
			MapConst_iterator(MapNode<Key, T>* node = 0):
				_node (node){}

			/*------------ Constructor const------------------------------*/
			/*-----create an iterator pointing on const val---------*/
			MapConst_iterator(const MapNode<Key, T>* node):
				_node (node){}

			/*------------Copy Constructor---------------------*/
			/*-----create an iterator by copy------------------*/
			MapConst_iterator(MapConst_iterator const & other):
				_node (other._node){}

			/*------------Destructor-----------------------*/
			/*---------------------------------------------*/
			~MapConst_iterator(){}

			/*--------Assignement Constructor-------------------------*/
			/*-----create an iterator by assignement------------------*/
			MapConst_iterator & operator=(const MapConst_iterator & other)
			{
				if (this != &other)
					_node = other._node;
				return (*this);
			}

			/*-------------BIDIRECTIONNAL ITERATOR------------------*/
			/*------------------------------------------------------*/
			/*------------------------------------------------------*/

			/*---------------Incrementation- (++)---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			MapConst_iterator & operator++()
			{
				MapNode<Key, T>* back;

				if (_node->right)
				{
					_node = _node->right;
					while (_node && _node->left != NULL && _node->left->right != _node)//le dernier c'est le noeud neutre
						_node = _node->left;
				}
				else if (_node == _node->parent->left)
					_node = _node->parent;
				else
				{
					back = _node->parent;
					_node = back->parent;
					if (back == _node->right)
					{
						while (_node == _node->parent->right)
							_node = _node->parent;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			MapConst_iterator operator++(int)
			{
				MapConst_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*---------------Decrementation ()---------------------*/
			/*--------------------------------------------------------*/
			/*--------------------prefix------------------------------*/
			MapConst_iterator & operator--()
			{
				MapNode<Key, T>* back;

				if (_node->left->right == _node) // on est sur begin()
					_node = _node->left;
				else if (_node->left)
				{
					_node = _node->left;
					while (_node && _node->right != NULL && _node->left->right != _node) //le dernier c'est le noeud neutre
						_node = _node->right;
				}
				else if (_node == _node->parent->right)
					_node = _node->parent;
				else
				{
					back = _node->parent;
					_node = back->parent;
					if (back == _node->left)
					{
						while (_node == _node->parent->left)
							_node = _node->parent;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			MapConst_iterator operator--(int)
			{
				MapConst_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			/*-------------Equality comparison----------------------*/
			/*------------------------------------------------------*/
			bool operator==(const MapConst_iterator & rhs) const {return (_node == rhs._node);}

			/*-------------Inequality comparison----------------------*/
			/*--------------------------------------------------------*/
			bool operator!=(const MapConst_iterator & rhs) const {return (_node != rhs._node);}

			/*--------------Dereferencement---------------------------*/
			/*--------------------------------------------------------*/
			const_reference 	operator*() const {return (_node->data);}
			const_pointer		operator->() const {return (&(_node->data));}

			MapConst_iterator	base()	const {return (*this);}
			const MapNode<Key, T>*		getNode() const {return (_node);}

	}; //class MapConst_iterator


	template <typename MapIterator >
	class MapReverseIterator : public MapIterator
	{
		public:

			/*-------------------------ALIAS-----------------*/
			/*-----------------------------------------------*/
			typedef MapIterator									iterator_type;
			typedef typename MapIterator::value_type			value_type;
			typedef typename MapIterator::const_value_type		const_value_type;
			typedef typename MapIterator::reference 			reference;
			typedef typename MapIterator::const_reference 		const_reference;
			typedef typename MapIterator::pointer 				pointer;
			typedef typename MapIterator::const_pointer 		const_pointer;

		public:
			/*-------------COPLIEN FORM (all)------------------*/
			/*-------------------------------------------------*/

			/*------------Default Constructor------------------------------------*/
			/*-----create an reverseiterator pointing on null--------------------*/
			MapReverseIterator(): MapIterator() {}

			/*------------Constructor with initialisation-------------------------*/
			MapReverseIterator(const iterator_type & it) : MapIterator(it){}

			/*------------Constructor by copy-------------------------------------*/
			MapReverseIterator(const MapReverseIterator & other) : MapIterator(other._node){}

			/*------------Destructor----------------------------------------------*/
			~MapReverseIterator(){}

			/*------------operator = (assignation)-------------------------------------*/
			MapReverseIterator operator=(const MapReverseIterator & other){
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
				MapIterator tmp(*this);
				return (*--tmp);//ie _node->previous->data
			}

			pointer		operator->() const {return (&(operator*()));}

			/*--------------Addition operator---------------------------*/
			// MapReverseIterator operator+ (int n) const
			// {
			// 	MapReverseIterator tmp(*this);
			// 	return(tmp.iterator_type::operator-(n));
			// }

			/*---------Increment operator position -------------------*/
			/*--------------------prefix------------------------------*/
			MapReverseIterator & operator++()
			{
				iterator_type::operator--();
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			MapReverseIterator operator++(int)
			{
				MapReverseIterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*--------------Advance operator---------------------------*/
			// MapReverseIterator& operator+= (int n)
			// {
			// 	return(this->iterator_type::operator-=(n));
			// }

			/*--------------Subtraction operator---------------------------*/
			// MapReverseIterator operator- (int n) const
			// {
			// 	MapReverseIterator tmp(*this);
			// 	return(tmp.iterator_type::operator+(n));
			// }


			/*---------Decrement operator position -------------------*/
			/*--------------------prefix------------------------------*/
			MapReverseIterator & operator--()
			{
				iterator_type::operator++();
				return (*this);
			}

			/*--------------------postfix------------------------------*/
			MapReverseIterator operator--(int)
			{
				MapReverseIterator tmp(*this);
				operator--();
				return (tmp);
			}

			/*--------------Retrocede operator---------------------------*/
			// MapReverseIterator& operator-= (int n)
			// {
			// 	return(this->iterator_type::operator+=(n));
			// }


			/*--------Dereference iterator with offset-------------------*/

			// reference operator[] (int n) const
			// {
			// 	return (iterator_type::base()[- n - 1]);
			// }
	}; //MapReverseIterator

			/*------------ NON MEMBER FUNCTION OVERLOAD ------------------*/
			/*------------------------------------------------------------*/

			/*--------------Relationnal operator----------------------------*/

		template <class Iterator>
		bool operator== (const MapReverseIterator<Iterator>& lhs,
						 const MapReverseIterator<Iterator>& rhs){
							return (lhs.base().operator==(rhs.base()));
						}

		template <class Iterator>
		bool operator!= (const MapReverseIterator<Iterator>& lhs,
						const MapReverseIterator<Iterator>& rhs){
							return (lhs.base().operator!=(rhs.base()));
						}

		// template <class Iterator>
		// bool operator<  (const MapReverseIterator<Iterator>& lhs,
		// 				const MapReverseIterator<Iterator>& rhs){
		// 					return (lhs.base().operator>(rhs.base()));
		// 				}

		// template <class Iterator>
		// bool operator<= (const MapReverseIterator<Iterator>& lhs,
        //            		const MapReverseIterator<Iterator>& rhs){
		// 					return (lhs.base().operator>=(rhs.base()));
		// 				}

		// template <class Iterator>
		// bool operator>  (const MapReverseIterator<Iterator>& lhs,
		// 				const MapReverseIterator<Iterator>& rhs){
		// 					return (lhs.base().operator<(rhs.base()));
		// 				}

		// template <class Iterator>
		// bool operator>= (const MapReverseIterator<Iterator>& lhs,
        //            		const MapReverseIterator<Iterator>& rhs){
		// 					return (lhs.base().operator<=(rhs.base()));
		// 				}

		// template <class Iterator>
		// MapReverseIterator<Iterator> operator+ (int n,
        //      const MapReverseIterator<Iterator>& rev_it){
		// 		 return (rev_it.operator+(n));
		// 	 }

		// template <class Iterator>
		// int operator- (const MapReverseIterator<Iterator>& lhs,
		// 				const MapReverseIterator<Iterator>& rhs){
		// 		return (lhs.base().operator-(rhs.base()));
		// 	}
} //namespace ft

#endif