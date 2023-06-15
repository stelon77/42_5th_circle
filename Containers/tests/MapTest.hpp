/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:25:47 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 18:57:12 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAPTEST_HPP
# define MAPTEST_HPP

#include <map>
#include "../map.hpp"
#include <vector>
#include "../vector.hpp"
#include <iostream>
#include <string>
// #include <thread>         // std::this_thread::sleep_for
// #include <chrono>         // std::chrono::seconds
#include <unistd.h>


class MapTest
{
	public:
		MapTest();
		~MapTest();

		void mapConstructor();
		void mapAssignation();
		void mapBeginEnd();
		void mapRbeginRend();
		void mapEmpty();
		void mapSize();
		void mapMaximumSize();
		void mapBracket();
		void mapInsert();
		void mapErase();
		void mapSwap();
		void mapClear();
		void mapKeyComp();
		void mapValueComp();
		void mapFind();
		void mapCount();
		void mapLowerBoundUpperBound();
		void mapEqualRange();
};

#endif