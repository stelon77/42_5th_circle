/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:25:00 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 18:43:45 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ListTest.hpp"

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

ListTest::ListTest(){}

ListTest::~ListTest(){}

void ListTest::listConstructor()
{
	std::cout << "\n\n-----------------------------------------\n------------ TESTS SUR LIST -------------\n-----------------------------------------\n\n";
	std::cout << "------------CONSTRUCTORS-----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

		// constructors used in the same order as described above:
	std::list<int> first;                                // empty list of ints
	std::list<int> second (4,100);                       // four ints with value 100
	std::list<int> third (second.begin(),second.end());  // iterating through second
	std::list<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "The contents of first are: ";
	for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of second are: ";
	for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of third are: ";
	for (std::list<int>::iterator it = third.begin(); it != third.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of fourth are: ";
	for (std::list<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of fifth are: ";
	for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';

  std::cout << "\n\nmy list class\n\n";

		// constructors used in the same order as described above:
	ft::list<int> myfirst;                                // empty list of ints
	ft::list<int> mysecond (4,100);                       // four ints with value 100
	ft::list<int> mythird (mysecond.begin(),mysecond.end());  // iterating through second
	ft::list<int> myfourth (mythird);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints2[] = {16,2,77,29};
	ft::list<int> myfifth (myints2, myints2 + sizeof(myints2) / sizeof(int) );
	std::cout << "The contents of first are: ";
	for (ft::list<int>::iterator it = myfirst.begin(); it != myfirst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of second are: ";
	for (ft::list<int>::iterator it = mysecond.begin(); it != mysecond.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of third are: ";
	for (ft::list<int>::iterator it = mythird.begin(); it != mythird.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of fourth are: ";
	for (ft::list<int>::iterator it = myfourth.begin(); it != myfourth.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of fifth are: ";
	for (ft::list<int>::iterator it = myfifth.begin(); it != myfifth.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	sleep(1);
}

void ListTest::listAssignation()
{
	std::cout << "\n\n------------ ASSIGNATION ----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> first (3);      // list of 3 zero-initialized ints
	std::list<int> second (5);     // list of 5 zero-initialized ints
	second = first;
	first = std::list<int>();
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> myfirst (3);      // list of 3 zero-initialized ints
	ft::list<int> mysecond (5);     // list of 5 zero-initialized ints
	mysecond = myfirst;
	myfirst = ft::list<int>();
	std::cout << "Size of first: " << int (myfirst.size()) << '\n';
	std::cout << "Size of second: " << int (mysecond.size()) << '\n';

	sleep(1);
}

void ListTest::listBeginEnd()

{
	std::cout << "\n\n----- ITERATORS : begin(), end() --------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	int myints[] = {75,23,65,42,13};
	std::list<int> mylist (myints,myints+5);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

		int myints2[] = {75,23,65,42,13};
	ft::list<int> mylist2 (myints2,myints2 +5);

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist2.begin(); it != mylist2.end(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';

	sleep(1);
}

void ListTest::listRbeginRend()
{
	std::cout << "\n\n---- ITERATORS : rbegin(), rend() -------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	for (int i=1; i<=5; ++i) mylist.push_back(i);

	std::cout << "mylist backwards:";
	for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist2;
	for (int i=1; i<=5; ++i) mylist2.push_back(i);

	std::cout << "mylist backwards:";
	for (ft::list<int>::reverse_iterator rit=mylist2.rbegin(); rit!=mylist2.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listEmpty()
{
	std::cout << "\n\n--------------- empty() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	int sum (0);
	for (int i=1;i<=10;++i) mylist.push_back(i);
	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}
	std::cout << "total: " << sum << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist2;
	int sum2(0);
	for (int i=1;i<=10;++i) mylist2.push_back(i);
	while (!mylist2.empty())
	{
		sum2 += mylist2.front();
		mylist2.pop_front();
	}
	std::cout << "total: " << sum2 << '\n';

	sleep(1);
}

void ListTest::listSize()
{
	std::cout << "\n\n--------------- size() ------------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';
	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';
	myints.insert (myints.begin(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';
	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> myints2;
	std::cout << "0. size: " << myints2.size() << '\n';
	for (int i=0; i<10; i++) myints2.push_back(i);
	std::cout << "1. size: " << myints2.size() << '\n';
	myints2.insert (myints2.begin(),10,100);
	std::cout << "2. size: " << myints2.size() << '\n';
	myints2.pop_back();
	std::cout << "3. size: " << myints2.size() << '\n';

	sleep(1);
}

void ListTest::listMaximumSize()
{
	std::cout << "\n\n------------ MaximumSize() --------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<char> charlist;
	std::list<int> intlist;
	std::list<long> longlist;
	std::list<std::string> stringlist;
	std::cout << "Maximum size of list of char : " << charlist.max_size() << "\n";
	std::cout << "Maximum size of list of int : " << intlist.max_size() << "\n";
	std::cout << "Maximum size of list of long : " << longlist.max_size() << "\n";
	std::cout << "Maximum size of list of string : " << stringlist.max_size() << "\n";

	std::cout << "\n\nmy list class\n\n";

	ft::list<char> charlist2;
	ft::list<int> intlist2;
	ft::list<long> longlist2;
	ft::list<std::string> stringlist2;
	std::cout << "Maximum size of list of char : " << charlist2.max_size() << "\n";
	std::cout << "Maximum size of list of int : " << intlist2.max_size() << "\n";
	std::cout << "Maximum size of list of long : " << longlist2.max_size() << "\n";
	std::cout << "Maximum size of list of string : " << stringlist2.max_size() << "\n";

	sleep(1);
}

void ListTest::listFront()
{
	std::cout << "\n\n--------------- Front() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	mylist.push_back(77);
	mylist.push_back(22);
	// now front equals 77, and back 22
	mylist.front() -= mylist.back();
	std::cout << "mylist.front() is now " << mylist.front() << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	mylist1.push_back(77);
	mylist1.push_back(22);
	// now front equals 77, and back 22
	mylist1.front() -= mylist1.back();
	std::cout << "mylist.front() is now " << mylist1.front() << '\n';

	sleep(1);
}

void ListTest::listBack()
{
	std::cout << "\n\n--------------- Back() ------------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;

	mylist.push_back(10);
	while (mylist.back() != 0)
	{
		mylist.push_back ( mylist.back() -1 );
	}
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;

	mylist1.push_back(10);
	while (mylist1.back() != 0)
	{
		mylist1.push_back ( mylist1.back() -1 );
	}
	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist1.begin(); it!=mylist1.end() ; ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listAssign()
{
	std::cout << "\n\n-------------- Assign() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> first;
	std::list<int> second;
	first.assign (7,100);                      // 7 ints with value 100
	second.assign (first.begin(),first.end()); // a copy of first
	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "The contents of first are: ";
	for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "The contents of second are: ";
	for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> first1;
	ft::list<int> second1;
	first1.assign (7,100);                      // 7 ints with value 100
	second1.assign (first1.begin(),first1.end()); // a copy of first
	int myints1[]={1776,7,4};
	first1.assign (myints1,myints1+3);            // assigning from array

	std::cout << "Size of first: " << int (first1.size()) << '\n';
	std::cout << "The contents of first are: ";
	for (ft::list<int>::iterator it = first1.begin(); it != first1.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "Size of second: " << int (second1.size()) << '\n';
	std::cout << "The contents of second are: ";
	for (ft::list<int>::iterator it = second1.begin(); it != second1.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';

	sleep(1);
}

void ListTest::listPushFront()
{
	std::cout << "\n\n----------- Push_front() ----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist (2,100);         // two ints with a value of 100
	mylist.push_front (200);
	mylist.push_front (300);
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1 (2,100);         // two ints with a value of 100
	mylist1.push_front (200);
	mylist1.push_front (300);
	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listPopFront()
{
	std::cout << "\n\n------------ pop_front() ----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	std::cout << "Popping out the elements in mylist:";
	while (!mylist.empty())
	{
		std::cout << ' ' << mylist.front();
		mylist.pop_front();
	}
	std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	mylist1.push_back (100);
	mylist1.push_back (200);
	mylist1.push_back (300);
	std::cout << "Popping out the elements in mylist:";
	while (!mylist1.empty())
	{
		std::cout << ' ' << mylist1.front();
		mylist1.pop_front();
	}
	std::cout << "\nFinal size of mylist is " << mylist1.size() << '\n';

	sleep(1);
}

void ListTest::listPushBack()
{
	std::cout << "\n\n------------ Push_back() ----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	int myint;
	std::cout << "Please enter some integers (enter 0 to end):\n";
	do {
		std::cin >> myint;
		mylist.push_back (myint);
		std::cin.ignore();
	} while (myint);
	std::cout << "mylist stores " << mylist.size() << " numbers.\n";
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	int myint1;
	std::cout << "Please enter some integers (enter 0 to end):\n";
	do {
		std::cin >> myint1;
		mylist1.push_back (myint1);
		std::cin.ignore();
	} while (myint1);
	std::cout << "mylist stores " << mylist1.size() << " numbers.\n";
	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listPopBack()
{
	std::cout << "\n\n------------- pop_back()-----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	int sum (0);
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	while (!mylist.empty())
	{
		sum+=mylist.back();
		mylist.pop_back();
	}
	std::cout << "The elements of mylist summed " << sum << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	int sum1 (0);
	mylist1.push_back (100);
	mylist1.push_back (200);
	mylist1.push_back (300);

	while (!mylist1.empty())
	{
		sum1+=mylist1.back();
		mylist1.pop_back();
	}
	std::cout << "The elements of mylist summed " << sum1 << '\n';

	sleep(1);
}

void ListTest::listInsert()
{
	std::cout << "\n\n-------------- insert() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	std::list<int>::iterator it;
	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5
	it = mylist.begin();
	++it;       // it points now to number 2           ^
	mylist.insert (it,10);                        // 1 10 2 3 4 5
	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
	--it;       // it points now to the second 20            ^
	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
													// 1 10 20 30 30 20 2 3 4 5
													//               ^
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	ft::list<int>::iterator it1;
	// set some initial values:
	for (int i=1; i<=5; ++i) mylist1.push_back(i); // 1 2 3 4 5
	it1 = mylist1.begin();
	++it1;       // it points now to number 2           ^
	mylist1.insert (it1,10);                        // 1 10 2 3 4 5
	// "it" still points to number 2                      ^
	mylist1.insert (it1,2,20);                      // 1 10 20 20 2 3 4 5
	--it1;       // it points now to the second 20            ^
	ft::vector<int> myvector1 (2,30);
	mylist1.insert (it1,myvector1.begin(),myvector1.end());
													// 1 10 20 30 30 20 2 3 4 5
													//               ^
	std::cout << "mylist contains:";
	for (it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listErase()
{
	std::cout << "\n\n--------------- Erase() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	std::list<int>::iterator it1,it2;
	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);
								// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); // ^^
	advance (it2,6);            // ^                 ^
	++it1;
		                        //    ^              ^
	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
								//    ^           ^
	it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
								//    ^           ^
	++it1;                      //       ^        ^
	--it2;                      //       ^     ^
	mylist.erase (it1,it2);     // 10 30 60 80 90
								//        ^
	std::cout << "mylist contains:";
	for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	ft::list<int>::iterator myit1,myit2;
	// set some values:
	for (int i=1; i<10; ++i) mylist1.push_back(i*10);
									 // 10 20 30 40 50 60 70 80 90
	myit1 = myit2 = mylist1.begin(); // ^^
	for (int i = 0; i < 6; i++)
		++myit2;            		 // ^                 ^
	++myit1;                      	 //    ^              ^
	myit1 = mylist1.erase (myit1);   // 10 30 40 50 60 70 80 90
									 //    ^           ^
	myit2 = mylist1.erase (myit2);   // 10 30 40 50 60 80 90
									 //    ^           ^
	++myit1;                    	 //       ^        ^
	--myit2;                     	 //       ^     ^
	mylist1.erase (myit1,myit2);     // 10 30 60 80 90
									 //        ^
	std::cout << "mylist contains:";
	for (myit1=mylist1.begin(); myit1!=mylist1.end(); ++myit1)
		std::cout << ' ' << *myit1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listSwap()
{
	std::cout << "\n\n---------------- Swap() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> first (3,100);   // three ints with a value of 100
	std::list<int> second (5,200);  // five ints with a value of 200
	first.swap(second);
	std::cout << "first contains:";
	for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "second contains:";
	for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> first1 (3,100);   // three ints with a value of 100
	ft::list<int> second1 (5,200);  // five ints with a value of 200
	first1.swap(second1);
	std::cout << "first contains:";
	for (ft::list<int>::iterator it1=first1.begin(); it1!=first1.end(); it1++)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	std::cout << "second contains:";
	for (ft::list<int>::iterator it1=second1.begin(); it1!=second1.end(); it1++)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listResize()
{
	std::cout << "\n\n-------------- Resize() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	// set some initial content:
	for (int i=1; i<10; ++i) mylist.push_back(i);
	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	// set some initial content:
	for (int i=1; i<10; ++i) mylist1.push_back(i);
	mylist1.resize(5);
	mylist1.resize(8,100);
	mylist1.resize(12);
	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listClear()
{
	std::cout << "\n\n--------------- Clear() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	std::list<int>::iterator it;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.clear();
	mylist.push_back (1101);
	mylist.push_back (2202);
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	ft::list<int>::iterator it1;
	mylist1.push_back (100);
	mylist1.push_back (200);
	mylist1.push_back (300);
	std::cout << "mylist contains:";
	for (it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	mylist1.clear();
	mylist1.push_back (1101);
	mylist1.push_back (2202);
	std::cout << "mylist contains:";
	for (it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listSplice()
{
	std::cout << "\n\n-------------- splice() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;
	// set some initial values:
	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);   // mylist2: 10 20 30
	it = mylist1.begin();
	++it;                         // points to 2
	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
									// mylist2 (empty)
									// "it" still points to 2 (the 5th element)

	mylist2.splice (mylist2.begin(),mylist1, it);
									// mylist1: 1 10 20 30 3 4
									// mylist2: 2
									// "it" is now invalid.
	it = mylist1.begin();
	std::advance(it,3);           // "it" points now to 30
	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
									// mylist1: 30 3 4 1 10 20
	std::cout << "mylist1 contains:";
	for (it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "mylist2 contains:";
	for (it=mylist2.begin(); it!=mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mymylist1, mymylist2;
	ft::list<int>::iterator myit;
	// set some initial values:
	for (int i=1; i<=4; ++i)
		mymylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i=1; i<=3; ++i)
		mymylist2.push_back(i*10);   // mylist2: 10 20 30
	myit = mymylist1.begin();
	++myit;                         // points to 2
	mymylist1.splice (myit, mymylist2); // mylist1: 1 10 20 30 2 3 4
									// mylist2 (empty)
									// "it" still points to 2 (the 5th element)

	mymylist2.splice (mymylist2.begin(),mymylist1, myit);
									// mylist1: 1 10 20 30 3 4
									// mylist2: 2
									// "it" is now invalid.
	myit = mymylist1.begin();
	for (int i = 0; i < 3; ++i)
		myit++;			            // "it" points now to 30
	mymylist1.splice ( mymylist1.begin(), mymylist1, myit, mymylist1.end());
									// mylist1: 30 3 4 1 10 20
	std::cout << "mylist1 contains:";
	for (myit=mymylist1.begin(); myit!=mymylist1.end(); ++myit)
		std::cout << ' ' << *myit;
	std::cout << '\n';
	std::cout << "mylist2 contains:";
	for (myit=mymylist2.begin(); myit!=mymylist2.end(); ++myit)
		std::cout << ' ' << *myit;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listRemove()
{
	std::cout << "\n\n-------------- remove() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	int myints[]= {17,89,7,14};
	std::list<int> mylist (myints,myints+4);
	mylist.remove(89);
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1 (myints,myints+4);
	mylist1.remove(89);
	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listRemoveIf()
{
	std::cout << "\n\n------------ remove_if() ----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	int myints[]= {15,36,7,17,20,39,4,1};
	std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
	mylist.remove_if (single_digit);           // 15 36 17 20 39
	mylist.remove_if (is_odd());               // 36 20
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1 (myints,myints+8);   // 15 36 7 17 20 39 4 1
	mylist1.remove_if (single_digit);           // 15 36 17 20 39
	mylist1.remove_if (is_odd());               // 36 20
	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listUnique()
{
	std::cout << "\n\n------------- unique() ------------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
						12.77, 73.35, 72.25, 15.3,  72.25 };
	std::list<double> mylist (mydoubles,mydoubles+10);
	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
								// 15.3,  72.25, 72.25, 73.0,  73.35
	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
								// 15.3,  72.25, 73.0,  73.35
	mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
										// 15.3,  72.25, 73.0
	mylist.unique (is_near());           //  2.72, 12.15, 72.25
	std::cout << "mylist contains:";
	for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<double> mylist1 (mydoubles,mydoubles+10);
	mylist1.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
								// 15.3,  72.25, 72.25, 73.0,  73.35
	mylist1.unique();           //  2.72,  3.14, 12.15, 12.77
								// 15.3,  72.25, 73.0,  73.35
	mylist1.unique (same_integral_part);  //  2.72,  3.14, 12.15
										// 15.3,  72.25, 73.0
	mylist1.unique (is_near());           //  2.72, 12.15, 72.25
	std::cout << "mylist contains:";
	for (ft::list<double>::iterator it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listMerge()
{
	std::cout << "\n\n--------------- merge() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);
	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);
	first.sort();
	second.sort();
	first.merge(second);
	// (second is now empty)
	second.push_back (2.1);
	first.merge(second,mycomparison);
	std::cout << "first contains:";
	for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<double> first1, second1;

	first1.push_back (3.1);
	first1.push_back (2.2);
	first1.push_back (2.9);
	second1.push_back (3.7);
	second1.push_back (7.1);
	second1.push_back (1.4);
	first1.sort();
	second1.sort();
	first1.merge(second1);
	// (second is now empty)
	second1.push_back (2.1);
	first1.merge(second1,mycomparison);
	std::cout << "first contains:";
	for (ft::list<double>::iterator it1=first1.begin(); it1!=first1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listSort()
{
	std::cout << "\n\n---------------- sort() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");
	mylist.sort();
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	mylist.sort(compare_nocase);
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<std::string> mylist1;
	ft::list<std::string>::iterator it1;
	mylist1.push_back ("one");
	mylist1.push_back ("two");
	mylist1.push_back ("Three");
	mylist1.sort();
	std::cout << "mylist contains:";
	for (it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	mylist1.sort(compare_nocase);
	std::cout << "mylist contains:";
	for (it1=mylist1.begin(); it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listReverse()
{
	std::cout << "\n\n------------- reverse() -----------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> mylist;
	for (int i=1; i<10; ++i) mylist.push_back(i);
	mylist.reverse();
	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> mylist1;
	for (int i=1; i<10; ++i) mylist1.push_back(i);
	mylist1.reverse();
	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	sleep(1);
}

void ListTest::listRelationalOperators()
{
	std::cout << "\n\n-------- relational operators() ---------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

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

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

	std::cout << "\n\nmy list class\n\n";

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

	if (a1==b1) std::cout << "a and b are equal\n";
	if (b1!=c1) std::cout << "b and c are not equal\n";
	if (b1<c1) std::cout << "b is less than c\n";
	if (c1>b1) std::cout << "c is greater than b\n";
	if (a1<=b1) std::cout << "a is less than or equal to b\n";
	if (a1>=b1) std::cout << "a is greater than or equal to b\n";

	sleep(1);
}

void ListTest::listSwapOverload()
{
	std::cout << "\n\n------------ swap overload() ------------\n-----------------------------------------\n\n";
	std::cout << "list class std\n\n";

	std::list<int> foo (3,100);   // three ints with a value of 100
	std::list<int> bar (5,200);   // five ints with a value of 200
	std::swap(foo,bar);
	std::cout << "foo contains:";
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains:";
	for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy list class\n\n";

	ft::list<int> foo1 (3,100);   // three ints with a value of 100
	ft::list<int> bar1 (5,200);   // five ints with a value of 200
	ft::swap(foo1,bar1);
	std::cout << "foo contains:";
	for (ft::list<int>::iterator it = foo1.begin(); it!=foo1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "bar contains:";
	for (ft::list<int>::iterator it = bar1.begin(); it!=bar1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}