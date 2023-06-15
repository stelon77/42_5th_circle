/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:28:43 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 19:00:59 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorTest.hpp"
#include "ListTest.hpp"
#include "QueueTest.hpp"
#include "StackTest.hpp"
#include "MapTest.hpp"


int main()
{
	/* ********************************************************************** */
	/*                                                                        */
	/*                               VECTOR                                   */
	/*                                                                        */
	/* ********************************************************************** */

	VectorTest v;

	v.vectorConstructor();
	v.vectorAssignation();
	v.vectorBeginEnd();
	v.vectorRbeginRend();
	v.vectorSize();
	v.vectorCapacityMaxSize();
	v.vectorResize();
	v.vectorEmpty();
	v.vectorReserve();
	v.vectorBrackets();
	v.vectorAt();
	v.vectorFront();
	v.vectorBack();
	v.vectorAssign();
	v.vectorPushBack();
	v.vectorPopBack();
	v.vectorInsert();
	v.vectorErase();
	v.vectorSwap();
	v.vectorClear();
	v.vectorComparaisonOperators();
	v.vectorSwapOverload();

	/* ********************************************************************** */
	/*                                                                        */
	/*                                LIST                                    */
	/*                                                                        */
	/* ********************************************************************** */

	ListTest l;

	l.listConstructor();
	l.listAssignation();
	l.listBeginEnd();
	l.listRbeginRend();
	l.listEmpty();
	l.listSize();
	l.listMaximumSize();
	l.listFront();
	l.listBack();
	l.listAssign();
	l.listPushFront();
	l.listPopFront();
	l.listPushBack();
	l.listPopBack();
	l.listInsert();
	l.listErase();
	l.listSwap();
	l.listResize();
	l.listClear();
	l.listSplice();
	l.listRemove();
	l.listRemoveIf();
	l.listUnique();
	l.listMerge();
	l.listSort();
	l.listReverse();
	l.listRelationalOperators();
	l.listSwapOverload();

	/* ********************************************************************** */
	/*                                                                        */
	/*                               QUEUE                                    */
	/*                                                                        */
	/* ********************************************************************** */

	QueueTest q;

	q.queueConstructor();
	q.queueEmpty();
	q.queueSize();
	q.queueFront();
	q.queueBack();
	q.queuePushAndPop();
	q.queueRelationalOperators();


	/* ********************************************************************** */
	/*                                                                        */
	/*                               STACK                                    */
	/*                                                                        */
	/* ********************************************************************** */

	StackTest s;

	s.stackConstructor();
	s.stackEmpty();
	s.stackSize();
	s.stackTop();
	s.stackPushAndPop();
	s.stackRelationalOperators();


	/* ********************************************************************** */
	/*                                                                        */
	/*                                MAP                                     */
	/*                                                                        */
	/* ********************************************************************** */

	MapTest m;

	m.mapConstructor();
	m.mapAssignation();
	m.mapBeginEnd();
	m.mapRbeginRend();
	m.mapEmpty();
	m.mapSize();
	m.mapMaximumSize();
	m.mapBracket();
	m.mapInsert();
	m.mapErase();
	m.mapSwap();
	m.mapClear();
	m.mapKeyComp();
	m.mapValueComp();
	m.mapFind();
	m.mapCount();
	m.mapLowerBoundUpperBound();
	m.mapEqualRange();
	return (0);
}