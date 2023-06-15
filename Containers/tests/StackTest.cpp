/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:00:00 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 18:48:18 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "StackTest.hpp"

StackTest::StackTest(){}

StackTest::~StackTest(){}

void StackTest::stackConstructor()
{
	std::cout << "\n\n-----------------------------------------\n--------- TESTS SUR STACK ---------------\n-----------------------------------------\n\n";
	std::cout << "------------CONSTRUCTORS-----------------\n-----------------------------------------\n\n";
	std::cout << "stack class std\n\n";

	std::deque<int> mydeck (3,100);        // deque with 3 elements
	std::list<int> mylist (2,200);         // list with 2 elements

	std::stack<int> first;                 // empty stack
	std::stack<int> second (mydeck);       // stack initialized to copy of deque

	std::stack<int,std::list<int> > third; // empty stack with list as underlying container
	std::stack<int,std::list<int> > fourth (mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

  	std::cout << "\n\nmy stack class\n\n";

	ft::list<int> mylist1(3,100);         // list with 2 elements
	ft::vector<int> myvect1 (2,200);

	ft::stack<int> first1;                 // empty stack
	ft::stack<int> second1 ( mylist1);       // stack initialized to copy of list

	std::stack<int,ft::vector<int> > third1; // empty stack with vector as underlying container
	std::stack<int,ft::vector<int> > fourth1 (myvect1); //stack copie of vector

	std::cout << "size of first: " << first1.size() << '\n';
	std::cout << "size of second: " << second1.size() << '\n';
	std::cout << "size of third: " << third1.size() << '\n';
	std::cout << "size of fourth: " << fourth1.size() << '\n';

  	sleep(1);
}

void StackTest::stackEmpty()
{
	std::cout << "\n\n--------------- empty() -----------------\n-----------------------------------------\n\n";
	std::cout << "stack class std\n\n";

	std::stack<int> mystack;
	int sum (0);
	for (int i=1;i<=10;i++) mystack.push(i);
	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
  	std::cout << "total: " << sum << '\n';

  	std::cout << "\n\nmy stack class\n\n";

	ft::stack<int> mystack1;
	sum = 0;;
	for (int i=1;i<=10;i++) mystack1.push(i);
	while (!mystack1.empty())
	{
		sum += mystack1.top();
		mystack1.pop();
	}
  	std::cout << "total: " << sum << '\n';

  	sleep(1);
}

void StackTest::stackSize()
{
	std::cout << "\n\n--------------- size() ------------------\n-----------------------------------------\n\n";
	std::cout << "stack class std\n\n";

	std::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';
	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

  	std::cout << "\n\nmy stack class\n\n";

	ft::stack<int> myints1;
	std::cout << "0. size: " << myints1.size() << '\n';
	for (int i=0; i<5; i++) myints1.push(i);
	std::cout << "1. size: " << myints1.size() << '\n';
	myints1.pop();
	std::cout << "2. size: " << myints1.size() << '\n';

  	sleep(1);
}

void StackTest::stackTop()
{
	std::cout << "\n\n---------------- top() ------------------\n-----------------------------------------\n\n";
	std::cout << "stack class std\n\n";

	std::stack<int> mystack;
	mystack.push(10);
	mystack.push(20);
	mystack.top() -= 5;
	std::cout << "mystack.top() is now " << mystack.top() << '\n';

  	std::cout << "\n\nmy stack class\n\n";

	ft::stack<int> mystack1;
	mystack1.push(10);
	mystack1.push(20);
	mystack1.top() -= 5;
	std::cout << "mystack.top() is now " << mystack1.top() << '\n';

	sleep(1);
}

void StackTest::stackPushAndPop()
{
	std::cout << "\n\n-------------- Push and pop() -----------\n-----------------------------------------\n\n";
	std::cout << "stack class std\n\n";

	std::stack<int> mystack;
	for (int i=0; i<5; ++i) mystack.push(i);
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

  	std::cout << "\n\nmy stack class\n\n";

	ft::stack<int> mystack1;
	for (int i=0; i<5; ++i) mystack1.push(i);
	std::cout << "Popping out elements...";
	while (!mystack1.empty())
	{
		std::cout << ' ' << mystack1.top();
		mystack1.pop();
	}
	std::cout << '\n';

	sleep(1);
}

void StackTest::stackRelationalOperators()
{
	std::cout << "\n\n-------- relational operators() ---------\n-----------------------------------------\n\n";
	std::cout << "stack class std\n\n";

	std::list<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	std::list<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	std::list<int> c;
	c.push_back(30);
	c.push_back(20);
	c.push_back(10);
	std::stack<int, std::list<int> > aa (a);
	std::stack<int, std::list<int> > bb (b);
	std::stack<int, std::list<int> > cc (c);

	if (aa==bb) std::cout << "a and b are equal\n";
	if (bb!=cc) std::cout << "b and c are not equal\n";
	if (bb<cc) std::cout << "b is less than c\n";
	if (cc>bb) std::cout << "c is greater than b\n";
	if (aa<=bb) std::cout << "a is less than or equal to b\n";
	if (aa>=bb) std::cout << "a is greater than or equal to b\n";

	std::cout << "\n\nmy stack class\n\n";

	ft::list<int> a1;
	a1.push_back(10);
	a1.push_back(20);
	a1.push_back(30);
	ft::list<int> b1;
	b1.push_back(10);
	b1.push_back(20);
	b1.push_back(30);
	ft::list<int> c1;
	c1.push_back(30);
	c1.push_back(20);
	c1.push_back(10);

	ft::stack<int> aa1 (a1);
	ft::stack<int> bb1 (b1);
	ft::stack<int> cc1 (c1);


	if (aa1==bb1) std::cout << "a and b are equal\n";
	if (bb1!=cc1) std::cout << "b and c are not equal\n";
	if (bb1<cc1) std::cout << "b is less than c\n";
	if (cc1>bb1) std::cout << "c is greater than b\n";
	if (aa1<=bb1) std::cout << "a is less than or equal to b\n";
	if (aa1>=bb1) std::cout << "a is greater than or equal to b\n";

	sleep(1);
}
