/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:24:33 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 18:59:24 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTTEST_HPP
# define LISTTEST_HPP

#include <list>
#include "../list.hpp"
#include <vector>
#include "../vector.hpp"
#include <iostream>
#include <string>
// #include <thread>         // std::this_thread::sleep_for
// #include <chrono>         // std::chrono::seconds
#include <unistd.h>


class ListTest
{
public:
	ListTest();
	~ListTest();

	void listConstructor();
	void listAssignation();
	void listBeginEnd();
	void listRbeginRend();
	void listEmpty();
	void listSize();
	void listMaximumSize();
	void listFront();
	void listBack();
	void listAssign();
	void listPushFront();
	void listPopFront();
	void listPushBack();
	void listPopBack();
	void listInsert();
	void listErase();
	void listSwap();
	void listResize();
	void listClear();
	void listSplice();
	void listRemove();
	void listRemoveIf();
	void listUnique();
	void listMerge();
	void listSort();
	void listReverse();
	void listRelationalOperators();
	void listSwapOverload();
};

#endif