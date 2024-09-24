#include<iostream>
#include"Status.h"
#include"SqList.h"
#include"LinkList.h"
#include"SLinkList.h"
using namespace std;
#include"DCLinkList.h"
int main1()
{
	std::cout << "Hello World" << std::endl;

	SqList<int> list1;
	for (int i = 0; i < 10; i++)
	{
		list1.pushBack(i);
	}
	std::cout << list1.getLength() << std::endl;
	list1.show_all();
	int c = 15;
	list1.insert(1, c);
	list1.del(2);
	list1.show_all();
	SqList<int> list2;
	list2.addList(list1, 5);
	list2.show_all();
	std::cout << list1.index(0) << std::endl;
	list1.del(list1.index(0));
	list1.show_all();
	list1.clear();
	std::cout << list1.isEmpty() << std::endl;
	return 0;
	
}
/*
int main()
{
	LinkList<int> llist1;
	for (int i = 0; i < 5; i++)
	{
		llist1.pushForward(i);
		llist1.pushBack(i);

	}
	llist1.show();
	llist1.del(4);
	std::cout << llist1.index(3) << std::endl;
	llist1.insert(4, 10);
	llist1.show();
	std::cout << llist1.getLength() << std::endl;
	int a;
	llist1.popFront(a);
	llist1.show();
	llist1.clear();
	std::cout << llist1.isEmpty() << std::endl;
	return 0;
}*/
/*
int main()
{
	DCLinkList<int> list3;
	for(int i = 0 ; i < 10 ;i++)
	{ 
		list3.pushBack(i);
		list3.pushFront(i);
	}
	cout << list3.getLength()<<endl;
	list3.show();
	int i;
	list3.popBack(i);
	cout<< "BACK " << i << endl;
	list3.popFront(i);
	list3.insert(18, 18);
	list3.insert(18, 111);
	list3.show();
	list3.del(list3.index(5));
	list3.del(list3.getLength()-1);
	list3.setItem(0, 0);
	list3.getItem(1, i);
	cout << "pos:" << i << endl;
	list3.show();
	list3.clear();
	cout << list3.isEmpty() << endl;
	list3.insert(0, 1);
	list3.show();
}
*/

int main()
{
	SLinkList<int> slist;
	for (int i = 0; i < 10; i++)
	{
		slist.insertElem(0, i);
	}
	cout << slist.getLength() << endl;
	slist.show();
	slist.insertElem(10, 111);
	slist.setElem(2, 33);
	int i;
	slist.delElem(3,i);
	slist.show();
}