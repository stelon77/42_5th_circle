/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:25:34 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/05/23 17:59:36 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MapTest.hpp"


bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

MapTest::MapTest(){}

MapTest::~MapTest(){}

void MapTest::mapConstructor()
{
	std::cout << "\n\n-----------------------------------------\n------------- TESTS SUR MAP -------------\n-----------------------------------------\n\n";
	std::cout << "------------CONSTRUCTORS-----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	std::map<char,int> second (first.begin(),first.end());
	std::map<char,int> third (second);
	std::map<char,int,classcomp> fourth;                 // class as Compare
	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	std::cout << "The contents of first are: ";
	for (std::map<char, int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';
	std::cout << "The contents of second are: ";
	for (std::map<char, int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';
	std::cout << "The contents of third are: ";
	for (std::map<char, int>::iterator it = third.begin(); it != third.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';
	std::cout << "The contents of fourth are: ";
	for (std::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';
	std::cout << "The contents of fifth are: ";
	for (std::map<char, int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> first1;

	first1['a']=10;
	first1['b']=30;
	first1['c']=50;
	first1['d']=70;

	ft::map<char,int> second1 (first1.begin(),first1.end());
	ft::map<char,int> third1 (second1);
	ft::map<char,int,classcomp> fourth1;                 // class as Compare
	ft::map<char,int,bool(*)(char,char)> fifth1 (fn_pt); // function pointer as Compare

	std::cout << "The contents of first are: ";
	for (ft::map<char, int>::iterator it = first1.begin(); it != first1.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';
	std::cout << "The contents of second are: ";
	for (ft::map<char, int>::iterator it = second1.begin(); it != second1.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';
	std::cout << "The contents of third are: ";
	for (ft::map<char, int>::iterator it = third1.begin(); it != third1.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';
	std::cout << "The contents of fourth are: ";
	for (ft::map<char, int>::iterator it = fourth1.begin(); it != fourth1.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';
	std::cout << "The contents of fifth are: ";
	for (ft::map<char, int>::iterator it = fifth1.begin(); it != fifth1.end(); it++)
		std::cout << it->second << ' ';
	std::cout << '\n';

	sleep(1);
}

void MapTest::mapAssignation()
{
	std::cout << "\n\n------ construction by assignation() ----\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> first;
	std::map<char,int> second;
	first['x']=8;
	first['y']=16;
	first['z']=32;
	second=first;                // second now contains 3 ints
	first=std::map<char,int>();  // and first is now empty
	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> first1;
	ft::map<char,int> second1;
	first1['x']=8;
	first1['y']=16;
	first1['z']=32;
	second1=first1;                // second now contains 3 ints
	first1=ft::map<char,int>();  // and first is now empty
	std::cout << "Size of first: " << first1.size() << '\n';
	std::cout << "Size of second: " << second1.size() << '\n';

  	sleep(1);
  }

void MapTest::mapBeginEnd()
{
	std::cout << "\n\n---------- begin() et end() -------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	// show content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	mymap1['b'] = 100;
	mymap1['a'] = 200;
	mymap1['c'] = 300;
	// show content:
	for (ft::map<char,int>::iterator it=mymap1.begin(); it!=mymap1.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

  	sleep(1);
}

void MapTest::mapRbeginRend()
{
	std::cout << "\n\n----------- rbegin() and rend() ---------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;
	// show content:
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	mymap1['x'] = 100;
	mymap1['y'] = 200;
	mymap1['z'] = 300;
	// show content:
	ft::map<char,int>::reverse_iterator rit1;
	for (rit1=mymap1.rbegin(); rit1!=mymap1.rend(); ++rit1)
		std::cout << rit1->first << " => " << rit1->second << '\n';

	sleep(1);
}

void MapTest::mapEmpty()
{
	std::cout << "\n\n--------------- empty() -----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	mymap1['a']=10;
	mymap1['b']=20;
	mymap1['c']=30;
	while (!mymap1.empty())
	{
		std::cout << mymap1.begin()->first << " => " << mymap1.begin()->second << '\n';
		mymap1.erase(mymap1.begin());
	}

  	sleep(1);
}

void MapTest::mapSize()
{
	std::cout << "\n\n---------------- size() -----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";
	std::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;
	std::cout << "mymap.size() is " << mymap.size() << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	mymap1['a']=101;
	mymap1['b']=202;
	mymap1['c']=302;
	std::cout << "mymap.size() is " << mymap1.size() << '\n';

	sleep(1);
}

void MapTest::mapMaximumSize()
{
	std::cout << "\n\n------------- max_size() ----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	int i;
	std::map<int,int> mymap;
	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";

	std::map<char, char> charmap;
	std::map<int, int> intmap;
	std::map<long, long> longmap;
	std::map<std::string, std::string> stringmap;
	std::cout << "Maximum size of list of char : " << charmap.max_size() << "\n";
	std::cout << "Maximum size of list of int : " << intmap.max_size() << "\n";
	std::cout << "Maximum size of list of long : " << longmap.max_size() << "\n";
	std::cout << "Maximum size of list of string : " << stringmap.max_size() << "\n";


  	std::cout << "\n\nmy map class\n\n";

	i = 0;
	ft::map<int,int> mymap1;
	if (mymap1.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap1[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";

	ft::map<char, char> charmap1;
	ft::map<int, int> intmap1;
	ft::map<long, long> longmap1;
	ft::map<std::string, std::string> stringmap1;
	std::cout << "Maximum size of list of char : " << charmap1.max_size() << "\n";
	std::cout << "Maximum size of list of int : " << intmap1.max_size() << "\n";
	std::cout << "Maximum size of list of long : " << longmap1.max_size() << "\n";
	std::cout << "Maximum size of list of string : " << stringmap1.max_size() << "\n";

	sleep(1);
}

void MapTest::mapBracket()
{
	std::cout << "\n\n--------------- Operator[] --------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,std::string> mymap;
	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];
	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';
	std::cout << "mymap now contains " << mymap.size() << " elements.\n";

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,std::string> mymap1;
	mymap1['a']="an element";
	mymap1['b']="another element";
	mymap1['c']=mymap1['b'];
	std::cout << "mymap['a'] is " << mymap1['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap1['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap1['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap1['d'] << '\n';
	std::cout << "mymap now contains " << mymap1.size() << " elements.\n";

  	sleep(1);
}

void MapTest::mapInsert()
{
	std::cout << "\n\n-------------- insert() -----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );
	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}
	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));
	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	// first insert function version (single parameter):
	mymap1.insert ( ft::pair<char,int>('a',100) );
	mymap1.insert ( ft::pair<char,int>('z',200) );
	ft::pair<ft::map<char,int>::iterator,bool> ret1;
	ret1 = mymap1.insert ( ft::pair<char,int>('z',500) );
	if (ret1.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret1.first->second << '\n';
	}
	// second insert function version (with hint position):
	ft::map<char,int>::iterator it1 = mymap1.begin();
	mymap1.insert (it1, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap1.insert (it1, ft::pair<char,int>('c',400));  // no max efficiency inserting
	// third insert function version (range insertion):
	ft::map<char,int> anothermap1;
	anothermap1.insert(mymap1.begin(),mymap1.find('c'));
	// showing contents:
	std::cout << "mymap contains:\n";
	for (it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';
	std::cout << "anothermap contains:\n";
	for (it1=anothermap1.begin(); it1!=anothermap1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';

  	sleep(1);
}

void MapTest::mapErase()
{
	std::cout << "\n\n-------------- erase() ------------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	std::map<char,int>::iterator it;
	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;
	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	mymap.erase ('c');                  // erasing by key
	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range
	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	ft::map<char,int>::iterator it1;
	// insert some values:
	mymap1['a']=10;
	mymap1['b']=20;
	mymap1['c']=30;
	mymap1['d']=40;
	mymap1['e']=50;
	mymap1['f']=60;
	it1=mymap1.find('b');
	mymap1.erase (it1);                   // erasing by iterator
	mymap1.erase ('c');                  // erasing by key
	it1=mymap1.find ('e');
	mymap1.erase ( it1, mymap1.end() );    // erasing by range
	// show content:
	for (it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';

  	sleep(1);
}

void MapTest::mapSwap()
{
	std::cout << "\n\n---------------- swap() -----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> foo,bar;
	foo['x']=100;
	foo['y']=200;
	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	foo.swap(bar);
	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> foo1,bar1;
	foo1['x']=100;
	foo1['y']=200;
	bar1['a']=11;
	bar1['b']=22;
	bar1['c']=33;
	foo1.swap(bar1);
	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it1=foo1.begin(); it1!=foo1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';
	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it1=bar1.begin(); it1!=bar1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';

	sleep(1);
}

void MapTest::mapClear()
{
	std::cout << "\n\n--------------- clear() -----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;
	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;
	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	mymap1['x']=100;
	mymap1['y']=200;
	mymap1['z']=300;
	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';
	mymap1.clear();
	mymap1['a']=1101;
	mymap1['b']=2202;
	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';

  	sleep(1);
}

void MapTest::mapKeyComp()
{
	std::cout << "\n\n---------------- key_comp() -------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	std::map<char,int>::key_compare mycomp = mymap.key_comp();
	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	std::cout << "mymap contains:\n";
	char highest = mymap.rbegin()->first;     // key value of last element
	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	ft::map<char,int>::key_compare mycomp1 = mymap1.key_comp();
	mymap1['a']=100;
	mymap1['b']=200;
	mymap1['c']=300;
	std::cout << "mymap contains:\n";
	char highest1 = mymap1.rbegin()->first;     // key value of last element
	ft::map<char,int>::iterator it1 = mymap1.begin();
	do {
		std::cout << it1->first << " => " << it1->second << '\n';
	} while ( mycomp1((*it1++).first, highest1) );
	std::cout << '\n';

  	sleep(1);
}

void MapTest::mapValueComp()
{
	std::cout << "\n\n------------ value_comp() ---------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;
	std::cout << "mymap contains:\n";
	std::pair<char,int> highest = *mymap.rbegin();          // last element
	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	mymap1['x']=1001;
	mymap1['y']=2002;
	mymap1['z']=3003;
	std::cout << "mymap contains:\n";
	ft::pair<char,int> highest1 = *mymap1.rbegin();          // last element
	ft::map<char,int>::iterator it1 = mymap1.begin();
	do {
		std::cout << it1->first << " => " << it1->second << '\n';
	} while ( mymap1.value_comp()(*it1++, highest1) );

  	sleep(1);
}

void MapTest::mapFind()
{
	std::cout << "\n\n---------------- find() -----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	std::map<char,int>::iterator it;
	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;
	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);
	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	ft::map<char,int>::iterator it1;
	mymap1['a']=50;
	mymap1['b']=100;
	mymap1['c']=150;
	mymap1['d']=200;
	it1 = mymap1.find('b');
	if (it1 != mymap1.end())
		mymap1.erase (it1);
	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap1.find('a')->second << '\n';
	std::cout << "c => " << mymap1.find('c')->second << '\n';
	std::cout << "d => " << mymap1.find('d')->second << '\n';

  	sleep(1);
}

void MapTest::mapCount()
{
	std::cout << "\n\n--------------- count() -----------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	char c;
	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;
	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else
		std::cout << " is not an element of mymap.\n";
	}

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	mymap1 ['a']=101;
	mymap1 ['c']=202;
	mymap1 ['f']=303;
	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap1.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else
		std::cout << " is not an element of mymap.\n";
	}

  	sleep(1);
}

void MapTest::mapLowerBoundUpperBound()
{
	std::cout << "\n\n------- lower and upper bound() ---------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;
	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;
	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)
	mymap.erase(itlow,itup);        // erases [itlow,itup)
	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	ft::map<char,int>::iterator itlow1,itup1;
	mymap1['a']=20;
	mymap1['b']=40;
	mymap1['c']=60;
	mymap1['d']=80;
	mymap1['e']=100;
	itlow1=mymap1.lower_bound ('b');  // itlow points to b
	itup1=mymap1.upper_bound ('d');   // itup points to e (not d!)
	mymap1.erase(itlow1,itup1);        // erases [itlow,itup)
	// print content:
	for (ft::map<char,int>::iterator it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
		std::cout << it1->first << " => " << it1->second << '\n';

  	sleep(1);
}

void MapTest::mapEqualRange()
{
	std::cout << "\n\n------------ equal range() --------------\n-----------------------------------------\n\n";
	std::cout << "map class std\n\n";

	std::map<char,int> mymap;
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

  	std::cout << "\n\nmy map class\n\n";

	ft::map<char,int> mymap1;
	mymap1['a']=10;
	mymap1['b']=20;
	mymap1['c']=30;
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret1;
	ret1 = mymap1.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret1.first->first << " => " << ret1.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret1.second->first << " => " << ret1.second->second << '\n';

  	sleep(1);
}
