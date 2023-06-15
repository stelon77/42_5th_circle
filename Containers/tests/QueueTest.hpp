/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueueTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:51:49 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 17:26:48 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUETEST_HPP
# define QUEUETEST_HPP

#include <queue>
#include "../queue.hpp"
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


class QueueTest
{
public:
	QueueTest();
	~QueueTest();

	void queueConstructor();
	void queueEmpty();
	void queueSize();
	void queueFront();
	void queueBack();
	void queuePushAndPop();
	void queueRelationalOperators();
};

#endif