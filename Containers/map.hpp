/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:48:28 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/24 15:46:00 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_iterator.hpp"
#include "utils.hpp"
#include <memory>
#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <cstddef>

namespace ft
{
	template < typename Key, typename T, typename Compare = ft::less<Key>,
					typename Alloc = std::allocator<ft::pair<Key,T> > >
	class map
	{
		public:

			/*----------------------------------ALIAS------------------------------------*/
			/*---------------------------------------------------------------------------*/
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const key_type, mapped_type>				value_type;
			typedef Compare												key_compare;
			typedef	Alloc												allocator_type;
			typedef	typename allocator_type::reference					reference;
			typedef	typename allocator_type::const_reference			const_reference;
			typedef	typename allocator_type::pointer					pointer;
			typedef	typename allocator_type::const_pointer				const_pointer;

			typedef	typename ft::MapIterator<Key, T>									iterator;
			typedef typename ft::MapConst_iterator<Key, T>								const_iterator;
            typedef typename ft::MapReverseIterator<ft::MapIterator<Key, T> >  			reverse_iterator;
            typedef typename ft::MapReverseIterator<ft::MapConst_iterator<Key, T> >   	const_reverse_iterator;

			typedef size_t												size_type;
			typedef ptrdiff_t											difference_type;

		private:
			typedef typename ft::MapNode<Key, T> 						MapNode;
			typedef typename Alloc::template rebind<MapNode>::other		MapNodeAlloc;


		//nested function class to compare elements
		public:
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object

				public:
					bool operator() (const value_type& x, const value_type& y) const
						{
							return comp(x.first, y.first);
						}
			};


			/*--------------------ATTRIBUTES-----------------*/
			/*-----------------------------------------------*/
		private:
			MapNode*	 		_neutralNode; 	//pointeur sur le node neutre ie end() ou --begin()
			MapNode*			_root; //racine de l'arbre
			MapNodeAlloc		_mapNodeAlloc;  //allocateur de noeud
			allocator_type		_alloc;		//copie  objet allocator_type
			size_type			_size;		//tree size
			key_compare			_comp;

		public:
			/*------------------------------------------------------------------------------*/
			/*------------------------------COPLIEN FORM -----------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------Default Constructor (empty container constructor)-----------------*/
			explicit map (const key_compare& comp = key_compare(),
            	const allocator_type& alloc = allocator_type()):
					_root(0), _alloc(alloc), _size(0), _comp(comp)
			{
				_neutralNode = createNeutralNode();
			}

			/*---------------------------Range constructor------------------------------------*/

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
					_root(0), _alloc(alloc), _size(0), _comp(comp)
			{
				_neutralNode = createNeutralNode();
				for (; first != last; ++first)
					_root = insertion(_root, *first);
			}

			// /*---------------------------Copy constructor------------------------------------*/
			map (const map& x):
				_root(0), _mapNodeAlloc(x._mapNodeAlloc), _alloc(x._alloc), _size(0), _comp(x._comp)
			{
				_neutralNode = createNeutralNode();
				for (const_iterator it = x.begin(); it != x.end(); it++)
					_root = insertion(_root, *it);
			}

			// /*-------------------------------Destructor--------------------------------------*/
			~map ()
			{
				clear();
				destroyNode(_neutralNode);
			}

			// /*----------------------------- Assignation -------------------------------------*/
			map & operator= (const map & x)
			{
				if (this != &x)
				{
					clear();
					_comp = x._comp;
					for (const_iterator it = x.begin(); it !=x.end(); it++)
						_root = insertion(_root, *it);
				}
				return (*this);
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------ ITERATORS -------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ begin() -----------------------------------*/
			iterator begin(){
				return (iterator(_neutralNode->right));
			}

			const_iterator begin() const {
				return(const_iterator(_neutralNode->right));
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
				return(reverse_iterator(_neutralNode->right));
			}

			const_reverse_iterator rend() const {
				return(const_reverse_iterator(_neutralNode->right));
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------ CAPACITY --------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ empty() -----------------------------------*/
			bool empty() const						{	return(_size == 0);	}

			/*------------------------------ size() -----------------------------------*/
			size_type size() const					{	return(_size);		}

			/*------------------------------ max_size() -----------------------------------*/
			size_type max_size() const				{	return(_mapNodeAlloc.max_size());	}


			/*------------------------------------------------------------------------------*/
			/*------------------------- ELEMENT ACCESS -------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ operator[]() ----------------------------------*/
			mapped_type& operator[] (const key_type& k)
			{
				iterator found = find(k);
				if (found != end())
					return (found->second);
				else
					return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
			}



			/*------------------------------------------------------------------------------*/
			/*------------------------------- MODIFIER -------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*-------------------------------- insert() ------------------------------------*/
			pair<iterator,bool> insert (const value_type& val)
			{
				iterator found = find(val.first);
				if (found != end())
					return (ft::make_pair<iterator, bool>(found, false));
				_root = insertion(_root, val);
				return (ft::make_pair<iterator, bool> (lower_bound(val.first), true));
			}

			iterator insert (iterator position, const value_type& val)
			{
				iterator next = position;
				next++;
				if (_comp(position->first, val.first) && (!(next != end()) || (_comp(val.first, next->first)))) //position est le noeud juste en dessous
				{
					if ((!position.getNode()->right) || (!(next != end())))
						insertion(position.getNode(), val);
					else
						insertion(next.getNode(), val);
					checkAndBalance(&_root, val.first);
					return (find(val.first));
				}
				else
					return (insert(val).first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				for (; first != last; ++first)
					_root = insertion(_root, *first);
			}

			/*-------------------------------- erase() -------------------------------------*/
			void erase (iterator position)
			{
				_root = destruction(_root, position->first);
				_size--;
			}

			size_type erase (const key_type& k)
			{
				if (count(k))
				{
					_root = destruction(_root, k);
					_size--;
					return (1);
				}
				return (0);
			}

			void erase (iterator first, iterator last)
			{
				if (first == last)
					return;
				iterator tmp = first;
				tmp++;
				while (tmp != last)
				{
					erase(tmp);
					tmp = first;
					tmp++;
				}
				erase(first);
			}

			/*-------------------------------- swap() --------------------------------------*/
			void swap (map& x)
			{
				if (this == &x)
					return ;
				swapElt(_alloc, x._alloc);
				swapElt(_mapNodeAlloc, x._mapNodeAlloc);
				swapElt(_comp, x._comp);
				swapElt(_neutralNode, x._neutralNode);
				swapElt(_root, x._root);
				swapElt(_size, x._size);
			}

			/*-------------------------------- clear() -------------------------------------*/
			void clear()
			{
				erase(begin(), end());
			}

			/*------------------------------------------------------------------------------*/
			/*------------------------------- OBSERVERS ------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*-------------------------------- key_comp() ------------------------------------*/
			key_compare key_comp() const								{	return (_comp);	}

			/*------------------------------- value_comp() -----------------------------------*/
			value_compare value_comp() const			{	return (value_compare(_comp));	}


			/*------------------------------------------------------------------------------*/
			/*---------------------------- OPERATIONS --------------------------------------*/
			/*------------------------------------------------------------------------------*/

			/*------------------------------ find() -----------------------------------*/
			iterator find (const key_type& k)
			{
				MapNode* root = _root;
				while (root && (root != _neutralNode))
				{
					if (_comp(k, root->data.first))
						root = root->left;
					else if (_comp(root->data.first, k))
						root = root->right;
					else
						return (iterator(root));
				}
				return (iterator(_neutralNode));
			}

			const_iterator find (const key_type& k) const
			{
				MapNode* root = _root;
				while (root && (root != _neutralNode))
				{
					if (_comp(k, root->data.first))
						root = root->left;
					else if (_comp(root->data.first, k))
						root = root->right;
					else
						return (const_iterator(root));
				}
				return (const_iterator(_neutralNode));
			}

			/*------------------------------ count() -----------------------------------*/
			size_type count (const key_type& k) const{
				MapNode* root = _root;
				while (root && (root != _neutralNode))
				{
					if (_comp(k, root->data.first))
						root = root->left;
					else if (_comp(root->data.first, k))
						root = root->right;
					else
						return (1);
				}
				return (0);
			}

			/*--------------------------- lower_bound() --------------------------------*/
			iterator lower_bound (const key_type& k)
			{
				if (!_root || _comp(_neutralNode->left->data.first, k))
					return (end());
				if (_comp(k, _neutralNode->right->data.first))
					return (begin());
				MapNode* node = _root;
				while (node)
				{
					if (_comp(node->data.first, k))
					{
						if (node->right)
							node = node->right;
						else
							return (++(iterator(node)));
					}
					else if (_comp(k, node->data.first))
					{
						if (node->left)
							node = node->left;
						else
							return (iterator(node));
					}
					else // nodekey = key
						return (iterator(node));
				}
				return (iterator(node));
			}

			const_iterator lower_bound (const key_type& k) const
			{
				if (!_root || _comp(_neutralNode->left->data.first, k))
					return (end());
				if (_comp(k, _neutralNode->right->data.first))
					return (begin());
				MapNode* node = _root;
				while (node)
				{
					if (_comp(node->data.first, k))
					{
						if (node->right)
							node = node->right;
						else
							return (++(const_iterator(node)));
					}
					else if (_comp(k, node->data.first))
					{
						if (node->left)
							node = node->left;
						else
							return (const_iterator(node));
					}
					else // nodekey = key
						return (const_iterator(node));
				}
				return (const_iterator(node));
			}

			/*--------------------------- upper_bound() --------------------------------*/
			iterator upper_bound (const key_type& k)
			{
				if (!_root || _comp(_neutralNode->left->data.first, k))
					return (end());
				if (_comp(k, _neutralNode->right->data.first))
					return (begin());
				MapNode* node = _root;
				while (node)
				{
					if (_comp(node->data.first, k))
					{
						if (node->right)
							node = node->right;
						else
							return (++(iterator(node)));
					}
					else if (_comp(k, node->data.first))
					{
						if (node->left)
							node = node->left;
						else
							return (iterator(node));
					}
					else // nodekey = key
						return (++(iterator(node)));
				}
				return (iterator(node)); 
			}

			const_iterator upper_bound (const key_type& k) const
			{
				if (!_root || _comp(_neutralNode->left->data.first, k))
					return (end());
				if (_comp(k, _neutralNode->right->data.first))
					return (begin());
				MapNode* node = _root;
				while (node)
				{
					if (_comp(node->data.first, k))
					{
						if (node->right)
							node = node->right;
						else
							return (++(const_iterator(node)));
					}
					else if (_comp(k, node->data.first))
					{
						if (node->left)
							node = node->left;
						else
							return (const_iterator(node));
					}
					else // nodekey = key
						return (++(const_iterator(node)));
				}
				return (const_iterator(node));
			}

			/*--------------------------- equal_range() --------------------------------*/
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return (make_pair(lower_bound(k), upper_bound(k)));
			}


			/*------------------------------------------------------------------------------*/
			/*------------------ PRIVATE MEMBER FUNCTION -----------------------------------*/
			/*------------------------------------------------------------------------------*/
		private:
			/* ----------------createNeutralNode() ----------------------------------------**
			** cree et renvoie le noeud neutre de l'arbre
			** pas de parent, node left = upper node, node right = lower node
			** data non construite car nulle
			*/
			MapNode* createNeutralNode(void)
			{
				MapNode* neutralNode = _mapNodeAlloc.allocate(1);
				neutralNode->right = neutralNode;
				neutralNode->left = neutralNode;
				neutralNode->parent = NULL;
				return (neutralNode);
			}

			/* ---------------- createNode(value) ----------------------------------------**
			** cree et renvoie un noeud de l'arbre circulaire ,
			** data remplie avec value
			*/
			MapNode* createNode(const value_type & pair)
			{
				MapNode* newNode = _mapNodeAlloc.allocate(1);
				_alloc.construct(&newNode->data, pair);
				newNode->right = NULL;
				newNode->left = NULL;
				newNode->parent = NULL;
				return (newNode);
			}

			// Create the first node of the tree.
			MapNode* createRoot(value_type pair)
			{
				MapNode* newnode = createNode(pair);
				newnode->right = _neutralNode;
				newnode->left = _neutralNode;
				_neutralNode->right = newnode;
				_neutralNode->left = newnode;
				_root = newnode;
				return (newnode);
			}

			/* ---------------- destroyNode(node*) ----------------------------------------**
			** detruit la data  et desalloue le noeud pointe
			*/
			void destroyNode(MapNode* node)
			{
				_alloc.destroy(&node->data);
				_mapNodeAlloc.deallocate(node, 1);
			}

			/* ---------------- ftMax(int, int) ----------------------------------------**
			** retourne le maximum de 2 int
			*/
			int	ftMax(int a, int b)
			{
				if (a > b)
					return (a);
				return (b);
			}

			/* ---------------- countTreeLevel(mapnode*) ----------------------------------------**
			** retourne la hauteur de l'arbre
			*/
			int	countTreeLevel(MapNode *root) const
			{
				int	a;
				int	b;

				if (!root || root == _neutralNode)
					return (0);
				a = countTreeLevel(root->left);
				b = countTreeLevel(root->right);
				return (ftMax(a, b) + 1);
			}


			// A utility function to right
			// rotate subtree rooted with y
			// See the diagram given below.
			//				y					x
			//			  /   \				  /   \
			//			x		N3  <==>	N1     y
			//		  /  \						  /  \
			//		N1    N2					N2   N3

			MapNode *rightRotate(MapNode *y)
			{
				MapNode *x = y->left;
				MapNode *N2 = x->right;

				// Perform rotation
				x->right = y;
				x->parent = y->parent;
				y->parent = x;
				y->left = N2;
				if (N2)
					N2->parent = y;
				// Return new root
				return x;
			}

			// A utility function to left
			// rotate subtree rooted with x
			// See the diagram given above.
			//				y					x
			//			  /   \				  /   \
			//			x		N3  <==>	N1     y
			//		  /  \						  /  \
			//		N1    N2					N2   N3
			MapNode *leftRotate(MapNode *x)
			{
				MapNode *y = x->right;
				MapNode *N2 = y->left;

				// Perform rotation
				y->left = x;
				y->parent = x->parent;
				x->parent = y;
				x->right = N2;
				if (N2)
					N2->parent = x;
				// Return new root
				return y;
			}

			MapNode *balanceLeft(MapNode *node, key_type key)
			{
				//Left Left case
				if ((_comp(key, node->left->data.first) && (node->left->left && node->left->left != _neutralNode)) || (node->left->right == NULL))
					return rightRotate(node);
				// Left Right Case
				else
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
			}

			MapNode *balanceRight(MapNode *node, key_type key)
			{
				// Right Right Case
				if ((_comp(node->right->data.first, key) && (node->right->right && node->right->right != _neutralNode)) || (node->right->left == NULL))
					return leftRotate(node);
				// Right Left Case
				else
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
			}

			int checkAndBalance(MapNode **root, key_type key)
			{
				int a;
				int b;
				if (!(*root) || *root == _neutralNode)
					return (0);
				a = checkAndBalance(&((*root)->left), key);
				b = checkAndBalance(&((*root)->right), key);

				if ((a - b) > 1)
				{
					*root = balanceLeft(*root, key);
					return (a);
				}
				if ((b - a) > 1)
				{
					*root = balanceRight(*root, key);
					return (b);
				}
				return (ftMax(a, b) + 1);
			}

			/* Given a non-empty binary search tree, return the node
			with minimum key value found in that tree.
			*/
			MapNode* minValueNode(MapNode* node) const
			{
				MapNode* current = node;
				while (current && (current->left != NULL && current->left != _neutralNode))
					current = current->left;
				return current;
			}

			/* Given a non-empty binary search tree, return the node
			with maximum key value found in that tree.
			*/
			MapNode* maxValueNode(MapNode* node) const
			{
				MapNode* current = node;
				while (current && (current->right != NULL && current->right != _neutralNode))
					current = current->right;
				return current;
			}

			MapNode* insertNode(MapNode* parent, MapNode* node, value_type pair)
			{
				if (node == NULL || node == _neutralNode)
				{
					MapNode* newNode = createNode(pair);
					newNode->parent = parent;
					_size++;
					if ((parent->right == _neutralNode) && (_comp(parent->data.first, pair.first)))
					{
						newNode->right = _neutralNode;
						_neutralNode->left = newNode;
					}
					else if ((parent->left == _neutralNode) && (_comp(pair.first, parent->data.first)))
					{
						newNode->left = _neutralNode;
						_neutralNode->right = newNode;
					}
					return (newNode);
				}
				if (_comp(pair.first, node->data.first))
				{
					node->left = insertNode(node, node->left, pair);
				}

				else if (_comp(node->data.first, pair.first))
				{
					node->right = insertNode(node, node->right, pair);
				}

				else
					return node;
				/* return the (unchanged) node pointer */
				return node;
			}

			MapNode* insertion(MapNode* node, value_type pair)
			{
				if (!_root)
				{
					_size++;
					return (createRoot(pair));
				}
				else if (_comp(node->data.first, pair.first))
				{
					node->right = (insertNode(node, node->right, pair));
					checkAndBalance(&node, pair.first);
					return (node);
				}
				else if (_comp(pair.first, node->data.first))
				{
					node->left = (insertNode(node, node->left, pair));
					checkAndBalance(&node, pair.first);
					return (node);
				}
				else
					return (node); //si key = _root key
			}

			MapNode* deleteNode(MapNode* root)
			{
				//noeud sans enfants
				if ((!(root->left ) || (root->left == _neutralNode)) &&
					(!(root->right) || (root->right == _neutralNode)))
				{
					if (root->left && root->parent)
						_neutralNode->right = root->parent;

					if (root->right && root->parent)
						_neutralNode->left = root->parent;
					if (!(root->parent))
					{
						_neutralNode->left = _neutralNode;
						_neutralNode->right = _neutralNode;
					}
					destroyNode(root);
					return (NULL);
				}
				//noeud avec un seul enfant a droite
				else if (!(root->left) || (root->left == _neutralNode))
				{
					MapNode* tmp = root->right;
					tmp->parent = root->parent;
					if (root->left)
					{
						_neutralNode->right = minValueNode(root->right);
						_neutralNode->right->left = _neutralNode;
					}
					destroyNode(root);
					return (tmp);
				}
				//noeud avec un seul enfant a gauche
				else if (!(root->right) || (root->right == _neutralNode))
				{
					MapNode* tmp = root->left;
					tmp->parent = root->parent;
					if (root->right)
					{
						_neutralNode->left = maxValueNode(root->left);
						_neutralNode->left->right = _neutralNode;
					}
					destroyNode(root);
					return (tmp);
				}
				//noeud avec 2 enfants
				else
				{
					MapNode* tmp = minValueNode(root->right);
					_alloc.destroy(&root->data);
					_alloc.construct(&root->data, tmp->data);
					root->data = tmp->data;
					root->right = destruction(root->right, tmp->data.first);
					return (root);
				}
				return (root);
			}

			MapNode* destruction(MapNode* root, key_type key)
			{
				if (!root || root == _neutralNode)
					return (NULL);
				if (_comp(key, root->data.first))
					root->left = destruction(root->left, key);
				else if (_comp(root->data.first, key))
					root->right = destruction(root->right, key);
				else
					root = deleteNode(root);
				if (root == NULL)
					return (root);
				checkAndBalance(&root, key);
				_neutralNode->right->left = _neutralNode;
				_neutralNode->left->right = _neutralNode;
				return (root);
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

	}; //class map

}//namespace ft

