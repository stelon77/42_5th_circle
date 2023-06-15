/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTest.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:15:38 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 19:07:20 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORTEST_HPP
# define VECTORTEST_HPP

#include <vector>
#include "../vector.hpp"
#include <iostream>
#include <string>
// #include <thread>         // std::this_thread::sleep_for
// #include <chrono>         // std::chrono::seconds
#include <unistd.h>

class VectorTest
{
public:
	VectorTest();
	~VectorTest();

	void vectorConstructor();
	void vectorAssignation();
	void vectorBeginEnd();
	void vectorRbeginRend();
	void vectorSize();
	void vectorCapacityMaxSize();
	void vectorResize();
	void vectorEmpty();
	void vectorReserve();
	void vectorBrackets();
	void vectorAt();
	void vectorFront();
	void vectorBack();
	void vectorAssign();
	void vectorPushBack();
	void vectorPopBack();
	void vectorInsert();
	void vectorErase();
	void vectorSwap();
	void vectorClear();
	void vectorComparaisonOperators();
	void vectorSwapOverload();
};

#endif