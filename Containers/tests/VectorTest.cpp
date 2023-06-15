/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:32:56 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 18:35:18 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorTest.hpp"


VectorTest::VectorTest(){}

VectorTest::~VectorTest(){}

void VectorTest::vectorConstructor()
{
	std::cout << "\n\n-----------------------------------------\n------------ TESTS SUR VECTOR -----------\n-----------------------------------------\n\n";
	std::cout << "------------CONSTRUCTORS----------------\n----------------------------------------\n\n";
	std::cout << "vector class std\n\n";
	// constructors used in the same order as described above:
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of first are:";
	for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of second are:";
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of third are:";
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of fourth are:";
	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n\n";

	std::cout << "my vector class\n\n";
	ft::vector<int> myfirst;                                // empty vector of ints
	ft::vector<int> mysecond (4,100);                       // four ints with value 100
	ft::vector<int> mythird (mysecond.begin(),mysecond.end());  // iterating through second
	ft::vector<int> myfourth (mythird);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	ft::vector<int> myfifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of myfirst are:";
	for (ft::vector<int>::iterator it = myfirst.begin(); it != myfirst.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of mysecond are:";
	for (ft::vector<int>::iterator it = mysecond.begin(); it != mysecond.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of mythird are:";
	for (ft::vector<int>::iterator it = mythird.begin(); it != mythird.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of myfourth are:";
	for (ft::vector<int>::iterator it = myfourth.begin(); it != myfourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of myfifth are:";
	for (ft::vector<int>::iterator it = myfifth.begin(); it != myfifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n\n";
	sleep(1);
}

void VectorTest::vectorAssignation()
{
	std::cout << "--------------ASSIGNATION -----------------\n-------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> foo (3,50);
	std::vector<int> bar (5,20);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';

	std::cout << "\n\nmy vector class\n\n";

	ft::vector<int> myfoo (3,50);
	ft::vector<int> mybar (5,20);

	mybar = myfoo;
	myfoo = ft::vector<int>();

	std::cout << "Size of myfoo: " << int(myfoo.size()) << '\n';
	std::cout << "Size of mybar: " << int(mybar.size()) << '\n';
	sleep(1);
}

void VectorTest::vectorBeginEnd()
{
	std::cout << "\n\n--------- ITERATORS : begin(), end() ----------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy vector class \n\n";

	ft::vector<int> mymyvector;
	for (int i=1; i<=5; i++) mymyvector.push_back(i);

	std::cout << "mymyvector contains:";
	for (ft::vector<int>::iterator it = mymyvector.begin() ; it != mymyvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorRbeginRend()
{
		std::cout << "\n\n-------- ITERATORS : rbegin(), rend() ---------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector(5);  // 5 default-constructed ints

	int i=0;

	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myrevvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\nmy vector class\n\n";

	ft::vector<int> mymyvector (5);  // 5 default-constructed ints

	int j=0;
	ft::vector<int>::reverse_iterator myrit = mymyvector.rbegin();
	for (; myrit!= mymyvector.rend(); ++myrit)
		*myrit = ++j;
	std::cout << "mymyrevvector contains:";
	for (ft::vector<int>::iterator myit = mymyvector.begin(); myit != mymyvector.end(); ++myit)
		std::cout << ' ' << *myit;
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorSize()
{
	std::cout << "\n\n------------------ size() ---------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyints;
	std::cout << "0. size: " << mymyints.size() << '\n';

	for (int i=0; i<10; i++) mymyints.push_back(i);
	std::cout << "1. size: " << mymyints.size() << '\n';

	mymyints.insert (mymyints.end(),10,100);
	std::cout << "2. size: " << mymyints.size() << '\n';

	mymyints.pop_back();
	std::cout << "3. size: " << mymyints.size() << '\n';
	sleep(1);
}

void VectorTest::vectorCapacityMaxSize()
{
	std::cout << "\n\n---- comparing size, capacity and max_size ----\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);
	std::cout << "for int vector \n";
	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";

	std::vector<std::string> myvector2(50, "cool");
	std::cout << "\nfor string vector \n";
	std::cout << "size: " << myvector2.size() << "\n";
	std::cout << "capacity: " << myvector2.capacity() << "\n";
	std::cout << "max_size: " << myvector2.max_size() << "\n";


	std::cout << "\n\n my vector class\n\n";
	ft::vector<int> mymyvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) mymyvector.push_back(i);
	std::cout << "for int vector \n";
	std::cout << "size: " << mymyvector.size() << "\n";
	std::cout << "capacity: " << mymyvector.capacity() << "\n";
	std::cout << "max_size: " << mymyvector.max_size() << "\n";

	ft::vector<std::string> mymyvector2(50, "cool");
	std::cout << "\nfor string vector \n";
	std::cout << "size: " << mymyvector2.size() << "\n";
	std::cout << "capacity: " << mymyvector2.capacity() << "\n";
	std::cout << "max_size: " << mymyvector2.max_size() << "\n";
	sleep(1);
}

void VectorTest::vectorResize()
{
	std::cout << "\n\n------------------ resize ---------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector3;

	// set some initial content:
	for (int i=1;i<10;i++) myvector3.push_back(i);

	myvector3.resize(5);
	myvector3.resize(8,100);
	myvector3.resize(12);

	std::cout << "myvector contains:";
	for (unsigned long i=0;i<myvector3.size();i++)
		std::cout << ' ' << myvector3[i];
	std::cout << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector3;

	// set some initial content:
	for (int i=1;i<10;i++) mymyvector3.push_back(i);

	mymyvector3.resize(5);
	mymyvector3.resize(8,100);
	mymyvector3.resize(12);

	std::cout << "myvector contains:";
	for (unsigned long i=0;i<mymyvector3.size();i++)
		std::cout << ' ' << mymyvector3[i];
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorEmpty()
{
	std::cout << "\n\n-------------------- empty --------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector4;
	int sum (0);

	for (int i=1;i<=10;i++) myvector4.push_back(i);

	while (!myvector4.empty())
	{
		sum += myvector4.back();
		myvector4.pop_back();
	}

	std::cout << "total: " << sum << '\n';

	std::cout << "\n\n my vector class\n\n";


	ft::vector<int> mymyvector4;
	int mysum (0);

	for (int i=1;i<=10;i++) mymyvector4.push_back(i);

	while (!mymyvector4.empty())
	{
		mysum += mymyvector4.back();
		mymyvector4.pop_back();
	}

	std::cout << "total: " << mysum << '\n';
	sleep(1);
}

void VectorTest::vectorReserve()
{
		std::cout << "\n\n------------------ reserve --------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int>::size_type sz;

	std::vector<int> foo2;
	sz = foo2.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo2.push_back(i);
		if (sz!=foo2.capacity()) {
		sz = foo2.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar2;
	sz = bar2.capacity();
	bar2.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar2.push_back(i);
		if (sz!=bar2.capacity()) {
		sz = bar2.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int>::size_type mysz;

	ft::vector<int> myfoo2;
	mysz = myfoo2.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		myfoo2.push_back(i);
		if (mysz!=myfoo2.capacity()) {
		mysz = myfoo2.capacity();
		std::cout << "capacity changed: " << mysz << '\n';
		}
	}

	ft::vector<int> mybar2;
	mysz = mybar2.capacity();
	mybar2.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		mybar2.push_back(i);
		if (mysz!=mybar2.capacity()) {
		mysz = mybar2.capacity();
		std::cout << "capacity changed: " << mysz << '\n';
		}
	}
	sleep(1);
}

void VectorTest::vectorBrackets()
{
	std::cout << "\n\n------------------ operator[] -----------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector5 (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz2 = myvector5.size();

	// assign some values:
	for (unsigned i=0; i<sz2; i++) myvector5[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz2/2; i++)
	{
		int temp;
		temp = myvector5[sz2-1-i];
		myvector5[sz2-1-i]=myvector5[i];
		myvector5[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz2; i++)
		std::cout << ' ' << myvector5[i];
	std::cout << '\n';


	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector5 (10);   // 10 zero-initialized elements

	ft::vector<int>::size_type mysz2 = mymyvector5.size();

	// assign some values:
	for (unsigned i=0; i<mysz2; i++) mymyvector5[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<mysz2/2; i++)
	{
		int temp;
		temp = mymyvector5[mysz2-1-i];
		mymyvector5[mysz2-1-i]=mymyvector5[i];
		mymyvector5[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<mysz2; i++)
		std::cout << ' ' << mymyvector5[i];
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorAt()
{
	std::cout << "\n\n--------------------- at ----------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector6 (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector6.size(); i++)
	// for (unsigned i=0; i<=myvector6.size(); i++) //lance l'exception
		myvector6.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector6.size(); i++)
		std::cout << ' ' << myvector6.at(i);
	std::cout << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector6 (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<mymyvector6.size(); i++)
	// for (unsigned i=0; i<=mymyvector6.size(); i++) //lance l'exception
		mymyvector6.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<mymyvector6.size(); i++)
		std::cout << ' ' << mymyvector6.at(i);
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorFront()
{
	std::cout << "\n\n--------------------- front -------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector7;

	myvector7.push_back(78);
	myvector7.push_back(16);

	// now front equals 78, and back 16

	myvector7.front() -= myvector7.back();

	std::cout << "myvector.front() is now " << myvector7.front() << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector7;

	mymyvector7.push_back(78);
	mymyvector7.push_back(16);

	// now front equals 78, and back 16

	mymyvector7.front() -= mymyvector7.back();

	std::cout << "myvector.front() is now " << mymyvector7.front() << '\n';
	sleep(1);
}

void VectorTest::vectorBack()
{
std::cout << "\n\n--------------------- back --------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector8;

	myvector8.push_back(10);

	while (myvector8.back() != 0)
	{
		myvector8.push_back ( myvector8.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector8.size() ; i++)
		std::cout << ' ' << myvector8[i];
	std::cout << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector8;

	mymyvector8.push_back(10);

	while (mymyvector8.back() != 0)
	{
		mymyvector8.push_back ( mymyvector8.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<mymyvector8.size() ; i++)
		std::cout << ' ' << mymyvector8[i];
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorAssign()
{
	std::cout << "\n\n------------------- assign --------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";


	std::vector<int> first1;
	std::vector<int> second1;
	std::vector<int> third1;

	first1.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it1;
	it1=first1.begin()+1;

	second1.assign (it1,first1.end()-1); // the 5 central values of first

	int myints3[] = {1776,7,4};
	third1.assign (myints3,myints3+3);   // assigning from array.

	std::cout << "Size of first: " << int (first1.size()) << '\n';
	std::cout << "first contains:";
	for (unsigned i=0; i<first1.size() ; i++)
		std::cout << ' ' << first1[i];
	std::cout << "\nSize of second: " << int (second1.size()) << '\n';
	std::cout << "second contains:";
	for (unsigned i=0; i<second1.size() ; i++)
		std::cout << ' ' << second1[i];
	std::cout << "\nSize of third: " << int (third1.size()) << '\n';
	std::cout << "third contains:";
	for (unsigned i=0; i<third1.size() ; i++)
		std::cout << ' ' << third1[i];

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> myfirst1;
	ft::vector<int> mysecond1;
	ft::vector<int> mythird1;

	myfirst1.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator myit1;
	myit1=myfirst1.begin()+1;

	mysecond1.assign (myit1,myfirst1.end()-1); // the 5 central values of first

	int mymyints3[] = {1776,7,4};
	mythird1.assign (mymyints3,mymyints3+3);   // assigning from array.

	std::cout << "Size of first: " << int (myfirst1.size()) << '\n';
	std::cout << "first contains:";
	for (unsigned i=0; i<myfirst1.size() ; i++)
		std::cout << ' ' << myfirst1[i];

	std::cout << "\nSize of second: " << int (mysecond1.size()) << '\n';
	std::cout << "second contains:";
	for (unsigned i=0; i<mysecond1.size() ; i++)
		std::cout << ' ' << mysecond1[i];

	std::cout << "\nSize of third: " << int (mythird1.size()) << '\n';
	std::cout << "third contains:";
	for (unsigned i=0; i<mythird1.size() ; i++)
		std::cout << ' ' << mythird1[i];
	std::cout <<std::endl;
	sleep(1);
}

void VectorTest::vectorPushBack()
{
		std::cout << "\n\n------------------ push_back ------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector9;
	int myint1;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint1;
		std::cin.ignore();
		myvector9.push_back (myint1);
	} while (myint1);

	std::cout << "myvector stores " << int(myvector9.size()) << " numbers.\n";

	std::cout << "\n\n my vector class\n\n";


	ft::vector<int> mymyvector9;
	int mymyint1;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> mymyint1;
		std::cin.ignore();
		mymyvector9.push_back (mymyint1);
	} while (mymyint1);

	std::cout << "myvector stores " << int(mymyvector9.size()) << " numbers.\n";
	sleep(1);
}

void VectorTest::vectorPopBack()
{
	std::cout << "\n\n-------------------- pop_back -----------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector10;
	int sum2 (0);
	myvector10.push_back (100);
	myvector10.push_back (200);
	myvector10.push_back (300);
	while (!myvector10.empty())
	{
		sum2+=myvector10.back();
		myvector10.pop_back();
	}
	std::cout << "The elements of myvector add up to " << sum2 << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector10;
	int mysum2 (0);
	mymyvector10.push_back (100);
	mymyvector10.push_back (200);
	mymyvector10.push_back (300);

	while (!mymyvector10.empty())
	{
		mysum2+=mymyvector10.back();
		mymyvector10.pop_back();
	}
	std::cout << "The elements of myvector add up to " << mysum2 << '\n';
	sleep(1);
}

void VectorTest::vectorInsert()
{
	std::cout << "\n\n----------------- insert ----------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector11 (3,100);
	std::vector<int>::iterator it11;

	it11 = myvector11.begin();
	it11 = myvector11.insert ( it11 , 200 );

	myvector11.insert (it11,2,300);
	// "it" no longer valid, get a new one:
	it11 = myvector11.begin();

	std::vector<int> anothervector11 (2,400);

	myvector11.insert (it11+2,anothervector11.begin(),anothervector11.end());

	int myarray11 [] = { 501,502,503 };
	myvector11.insert (myvector11.begin(), myarray11, myarray11+3);

	std::cout << "myvector contains:";
	for (it11=myvector11.begin(); it11<myvector11.end(); it11++)
		std::cout << ' ' << *it11;
	std::cout << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector11 (3,100);
	ft::vector<int>::iterator myit11;
	myit11 = mymyvector11.begin();
	myit11 = mymyvector11.insert ( myit11 , 200 );
	mymyvector11.insert (myit11,2,300);
	// "it" no longer valid, get a new one:
	myit11 = mymyvector11.begin();
	ft::vector<int> myanothervector11 (2,400);
	mymyvector11.insert (myit11+2,myanothervector11.begin(),myanothervector11.end());
	int mymyarray11 [] = { 501,502,503 };
	mymyvector11.insert (mymyvector11.begin(), mymyarray11, mymyarray11+3);
	std::cout << "myvector contains:";
	for (myit11=mymyvector11.begin(); myit11<mymyvector11.end(); myit11++)
		std::cout << ' ' << *myit11;
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorErase()
{
	std::cout << "\n\n----------------- erase -----------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector12;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector12.push_back(i);

	// erase the 6th element
	myvector12.erase (myvector12.begin()+5);

	// erase the first 3 elements:
	myvector12.erase (myvector12.begin(),myvector12.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector12.size(); ++i)
		std::cout << ' ' << myvector12[i];
	std::cout << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector12;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) mymyvector12.push_back(i);

	// erase the 6th element
	mymyvector12.erase (mymyvector12.begin()+5);

	// erase the first 3 elements:
	mymyvector12.erase (mymyvector12.begin(),mymyvector12.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<mymyvector12.size(); ++i)
		std::cout << ' ' << mymyvector12[i];
	std::cout << '\n';
	sleep(1);
}


void VectorTest::vectorSwap()
{
	std::cout << "\n\n------------------- swap ----------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> foo3 (3,100);   // three ints with a value of 100
	std::vector<int> bar3 (5,200);   // five ints with a value of 200

	foo3.swap(bar3);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo3.size(); i++)
		std::cout << ' ' << foo3[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar3.size(); i++)
		std::cout << ' ' << bar3[i];
	std::cout << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> myfoo3 (3,100);   // three ints with a value of 100
	ft::vector<int> mybar3 (5,200);   // five ints with a value of 200

	myfoo3.swap(mybar3);

	std::cout << "foo contains:";
	for (unsigned i=0; i<myfoo3.size(); i++)
		std::cout << ' ' << myfoo3[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<mybar3.size(); i++)
		std::cout << ' ' << mybar3[i];
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorClear()
{
	std::cout << "\n\n--------------------- clear -------------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> myvector13;
	myvector13.push_back (100);
	myvector13.push_back (200);
	myvector13.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector13.size(); i++)
		std::cout << ' ' << myvector13[i];
	std::cout << '\n';

	myvector13.clear();
	myvector13.push_back (1101);
	myvector13.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector13.size(); i++)
		std::cout << ' ' << myvector13[i];
	std::cout << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> mymyvector13;
	mymyvector13.push_back (100);
	mymyvector13.push_back (200);
	mymyvector13.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<mymyvector13.size(); i++)
		std::cout << ' ' << mymyvector13[i];
	std::cout << '\n';

	mymyvector13.clear();
	mymyvector13.push_back (1101);
	mymyvector13.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<mymyvector13.size(); i++)
		std::cout << ' ' << mymyvector13[i];
	std::cout << '\n';
	sleep(1);
}

void VectorTest::vectorComparaisonOperators()
{
	std::cout << "\n\n---------- comparaison operators --------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> foo4 (3,100);   // three ints with a value of 100
	std::vector<int> bar4 (2,200);   // two ints with a value of 200

	if (foo4==bar4) std::cout << "foo and bar are equal\n";
	if (foo4!=bar4) std::cout << "foo and bar are not equal\n";
	if (foo4< bar4) std::cout << "foo is less than bar\n";
	if (foo4> bar4) std::cout << "foo is greater than bar\n";
	if (foo4<=bar4) std::cout << "foo is less than or equal to bar\n";
	if (foo4>=bar4) std::cout << "foo is greater than or equal to bar\n";


	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> myfoo4 (3,100);   // three ints with a value of 100
	ft::vector<int> mybar4 (2,200);   // two ints with a value of 200
	if (myfoo4==mybar4) std::cout << "foo and bar are equal\n";
	if (myfoo4!=mybar4) std::cout << "foo and bar are not equal\n";
	if (myfoo4< mybar4) std::cout << "foo is less than bar\n";
	if (myfoo4> mybar4) std::cout << "foo is greater than bar\n";
	if (myfoo4<=mybar4) std::cout << "foo is less than or equal to bar\n";
	if (myfoo4>=mybar4) std::cout << "foo is greater than or equal to bar\n";

	sleep(1);
}

void VectorTest::vectorSwapOverload()
{
	std::cout << "\n\n------------- swap overloaded -----------------\n-----------------------------------------------\n\n";
	std::cout << "vector class std\n\n";

	std::vector<int> foo5 (3,100);   // three ints with a value of 100
	std::vector<int> bar5 (5,200);   // five ints with a value of 200

	foo5.swap(bar5);

	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo5.begin(); it!=foo5.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (std::vector<int>::iterator it = bar5.begin(); it!=bar5.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "\n\n my vector class\n\n";

	ft::vector<int> myfoo5 (3,100);   // three ints with a value of 100
	ft::vector<int> mybar5 (5,200);   // five ints with a value of 200

	myfoo5.swap(mybar5);

	std::cout << "foo contains:";
	for (ft::vector<int>::iterator it = myfoo5.begin(); it!=myfoo5.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (ft::vector<int>::iterator it = mybar5.begin(); it!=mybar5.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	sleep(1);
}
