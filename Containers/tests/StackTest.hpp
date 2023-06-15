/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:00:14 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 19:04:13 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACKTEST_HPP
# define STACKTEST_HPP

#include <stack>
#include "../stack.hpp"
#include <deque>
#include <vector>
#include "../vector.hpp"
#include <list>
#include "../list.hpp"
#include <iostream>
#include <string>
// #include <thread>         // std::this_thread::sleep_for
// #include <chrono>         // std::chrono::seconds
#include <unistd.h>


class StackTest
{
public:
	StackTest();
	~StackTest();

	void stackConstructor();
	void stackEmpty();
	void stackSize();
	void stackTop();
	void stackPushAndPop();
	void stackRelationalOperators();
};

#endif