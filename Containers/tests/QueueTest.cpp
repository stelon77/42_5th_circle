/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueueTest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:52:06 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 18:46:41 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "QueueTest.hpp"

QueueTest::QueueTest(){}

QueueTest::~QueueTest(){}

void QueueTest::queueConstructor()
{
	std::cout << "\n\n-----------------------------------------\n------------ TESTS SUR QUEUE ------------\n-----------------------------------------\n\n";
	std::cout << "------------CONSTRUCTORS-----------------\n-----------------------------------------\n\n";
	std::cout << "queue class std\n\n";

	std::deque<int> mydeck (3,100);        // deque with 3 elements
	std::vector<int> myvector (2,200);         // list with 2 elements

	std::queue<int> first;                 // empty queue
	std::queue<int> second (mydeck);       // queue initialized to copy of deque

	std::queue<int,std::vector<int> > third; // empty queue using vector
	std::queue<int,std::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

  	std::cout << "\n\nmy queue class\n\n";

	ft::list<int> mylist1(3,100);         // list with 2 elements
	ft::vector<int> myvect1 (2,200);

	ft::queue<int> first1;                 // empty queue
	ft::queue<int> second1 (mylist1);       // queue initialized to copy of list (deque non implemente)

	std::queue<int,ft::vector<int> > third1; // empty queue using vector
	std::queue<int,ft::vector<int> > fourth1 (myvect1); //queue copie of vector

	std::cout << "size of first: " << first1.size() << '\n';
	std::cout << "size of second: " << second1.size() << '\n';
	std::cout << "size of third: " << third1.size() << '\n';
	std::cout << "size of fourth: " << fourth1.size() << '\n';

  	sleep(1);
}

void QueueTest::queueEmpty()
{
	std::cout << "\n\n--------------- empty() -----------------\n-----------------------------------------\n\n";
	std::cout << "queue class std\n\n";

	std::queue<int> myqueue;
	int sum (0);
	for (int i=1;i<=10;i++) myqueue.push(i);
	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}
	std::cout << "total: " << sum << '\n';

  	std::cout << "\n\nmy queue class\n\n";

	ft::queue<int> myqueue1;
	sum = 0;
	for (int i=1;i<=10;i++) myqueue1.push(i);
	while (!myqueue1.empty())
	{
		sum += myqueue1.front();
		myqueue1.pop();
	}
	std::cout << "total: " << sum << '\n';

  	sleep(1);
}

void QueueTest::queueSize()
{
	std::cout << "\n\n-------------- size() -------------------\n-----------------------------------------\n\n";
	std::cout << "queue class std\n\n";

	std::queue<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';
	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

  	std::cout << "\n\nmy queue class\n\n";

	ft::queue<int> myints1;
	std::cout << "0. size: " << myints1.size() << '\n';
	for (int i=0; i<5; i++) myints1.push(i);
	std::cout << "1. size: " << myints1.size() << '\n';
	myints1.pop();
	std::cout << "2. size: " << myints1.size() << '\n';

  	sleep(1);
}

void QueueTest::queueFront()
{
	std::cout << "\n\n------------- front() -------------------\n-----------------------------------------\n\n";
	std::cout << "queue class std\n\n";

	std::queue<int> myqueue;
	myqueue.push(77);
	myqueue.push(16);
	myqueue.front() -= myqueue.back();    // 77-16=61
	std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

  	std::cout << "\n\nmy queue class\n\n";

	ft::queue<int> myqueue1;
	myqueue1.push(77);
	myqueue1.push(16);
	myqueue1.front() -= myqueue1.back();    // 77-16=61
	std::cout << "myqueue.front() is now " << myqueue1.front() << '\n';

  	sleep(1);
}

void QueueTest::queueBack()
{
	std::cout << "\n\n-------------- back() -------------------\n-----------------------------------------\n\n";
	std::cout << "queue class std\n\n";

	std::queue<int> myqueue;
	myqueue.push(12);
	myqueue.push(75);   // this is now the back
	myqueue.back() -= myqueue.front();
	std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

  	std::cout << "\n\nmy queue class\n\n";

	ft::queue<int> myqueue1;
	myqueue1.push(12);
	myqueue1.push(75);   // this is now the back
	myqueue1.back() -= myqueue1.front();
	std::cout << "myqueue.back() is now " << myqueue1.back() << '\n';

	sleep(1);
}

void QueueTest::queuePushAndPop()
{
	std::cout << "\n\n---------- push() and pop() -------------\n-----------------------------------------\n\n";
	std::cout << "queue class std\n\n";

	std::queue<int> myqueue;
	int myint;
	std::cout << "Please enter some integers (enter 0 to end):\n";
	do {
		std::cin >> myint;
		myqueue.push (myint);
		std::cin.ignore();
	} while (myint);
	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
	std::cout << '\n';

  	std::cout << "\n\nmy queue class\n\n";

	ft::queue<int> myqueue1;
	int myint1;
	std::cout << "Please enter some integers (enter 0 to end):\n";
	do {
		std::cin >> myint1;
		myqueue1.push (myint1);
		std::cin.ignore();
	} while (myint1);
	std::cout << "myqueue contains: ";
	while (!myqueue1.empty())
	{
		std::cout << ' ' << myqueue1.front();
		myqueue1.pop();
	}
	std::cout << '\n';

  	sleep(1);
}


void QueueTest::queueRelationalOperators()
{
	std::cout << "\n\n-------- relational operators() ---------\n-----------------------------------------\n\n";
	std::cout << "queue class std\n\n";

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
	std::queue<int, std::list<int> > aa (a);
	std::queue<int, std::list<int> > bb (b);
	std::queue<int, std::list<int> > cc (c);

	if (aa==bb) std::cout << "a and b are equal\n";
	if (bb!=cc) std::cout << "b and c are not equal\n";
	if (bb<cc) std::cout << "b is less than c\n";
	if (cc>bb) std::cout << "c is greater than b\n";
	if (aa<=bb) std::cout << "a is less than or equal to b\n";
	if (aa>=bb) std::cout << "a is greater than or equal to b\n";

	std::cout << "\n\nmy queue class\n\n";

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

	ft::queue<int> aa1 (a1);
	ft::queue<int> bb1 (b1);
	ft::queue<int> cc1 (c1);


	if (aa1==bb1) std::cout << "a and b are equal\n";
	if (bb1!=cc1) std::cout << "b and c are not equal\n";
	if (bb1<cc1) std::cout << "b is less than c\n";
	if (cc1>bb1) std::cout << "c is greater than b\n";
	if (aa1<=bb1) std::cout << "a is less than or equal to b\n";
	if (aa1>=bb1) std::cout << "a is greater than or equal to b\n";

	sleep(1);
}