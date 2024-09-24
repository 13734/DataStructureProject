#pragma once
#include"Status.h"
#include<iostream>

template<class DataType>
class Node
{
public:
	Node() { next = nullptr; }
	Node(const DataType& idata, Node<DataType>* pnxt = nullptr) { data = idata, next = pnxt; }
	//Node(DataType idata, Node<DataType>* pnxt = nullptr) { data = idata, next = pnxt; }
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkList
{
protected:
	Node<DataType>* head;
	Node<DataType>* end;
	int length;
	void toBack();
	void refreshEnd();
public:
	LinkList();
	LinkList(const LinkList& list2);
	virtual ~LinkList();
	int getLength() const{ return length; }
	Status pushForward(const DataType& data);
	Status pushBack(const DataType& data);
	Status insert(int index, const DataType& data);
	//Status setItem(int index, const DataType& data);
	void clear();
	bool isEmpty() const;
	int index(const DataType& data) const;
	void show() const;
	Status popFront(DataType &data);
	Status getFront(DataType &data) const;
	Status getItem(int index, DataType& data) const;
	/*
	DataType popBack();
	DataType getBack();
	*/
	Status del(int index);
	Status del(int index, DataType& data);



};


template<class DataType>
void LinkList<DataType>::toBack()
{
	while (end->next != nullptr)
	{
		end = end->next;
	}
}


template<class DataType>
void LinkList<DataType>::refreshEnd()
{
	end = head;
	this->toBack();
}

template<class DataType>
LinkList<DataType>::LinkList()
{
	head = new Node<DataType>;
	end = head;
	length = 0;

}



template<class DataType>
LinkList<DataType>::LinkList(const LinkList& list2)
{
	head = new Node<DataType>;
	end = head;
	length = 0;
	
}

template<class DataType>
Status LinkList<DataType>::pushForward(const DataType & data)
{
	Node<DataType>* ptemp = new Node<DataType>(data, head->next);
	if (!ptemp) return ALLOCATE_ERROR;
	head->next = ptemp;
	if (!length) end = ptemp;
	length++;
	return PROCESS_SUCCESS;
}

template<class DataType>
Status LinkList<DataType>::pushBack(const DataType& data)
{
	toBack();
	Node<DataType>* ptemp = new Node<DataType>(data, nullptr);
	if (!ptemp) return ALLOCATE_ERROR;
	end->next = ptemp;
	end = ptemp;
	length++;
	return PROCESS_SUCCESS;
}

template<class DataType>
Status LinkList<DataType>::insert(int index, const DataType& data)
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	Node<DataType>* ptemp = head;
	for (int i = 0; i < index; i++)
	{
		ptemp = ptemp->next;
	}
	Node<DataType>* ptemp2 = new Node<DataType>(data, ptemp->next);
	if (!ptemp2) return ALLOCATE_ERROR;

	ptemp->next = ptemp2;
	length++;
	return PROCESS_SUCCESS;

}

template<class DataType>
Status LinkList<DataType>::del(int index, DataType& data)
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	Node<DataType>* ptemp = head;
	for (int i = 0; i < index; i++)
	{
		ptemp = ptemp->next;
	}

	data = ptemp->next->data;
	Node<DataType>* ptemp2 = ptemp->next;
	ptemp->next = ptemp2->next;
	if (ptemp2 == end) end = ptemp;
	delete ptemp2;
	length--;
	return PROCESS_SUCCESS;
}

template<class DataType>
Status LinkList<DataType>::del(int index)
{
	DataType data_tmp;
	return del(index, data_tmp);
}

template<class DataType>
bool LinkList<DataType>::isEmpty() const
{
	return !length;
}

template<class DataType>
int LinkList<DataType>::index(const DataType& data) const
{
	int index = -1;
	Node<DataType>* ptemp = head->next;
	int i = 0;
	while (ptemp != nullptr)
	{
		if (ptemp->data == data)
		{
			index = i;
			break;
		}
		ptemp = ptemp->next;
		i++;
	}
	return index;
}

template<class DataType>
void LinkList<DataType>::clear()
{
	Node<DataType>* ptemp1 = head->next;
	while (!ptemp1)
	{
		head->next = ptemp1->next;
		delete ptemp1;
		ptemp1 = head->next;
	}
	end = head;
	length = 0;
	/*
	Node<DataType>* ptemp1= head->next, *ptemp2;
	while (ptemp1->next != nullptr)
	{
		ptemp2 = ptemp1->next;
		delete ptemp1;
		ptemp1 = ptemp2;
	}

	delete ptemp1;

	length = 0;
	end = head;
	*/
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
	clear();
	delete head;
}

template<class DataType>
void LinkList<DataType>::show() const
{
	Node<DataType>* ptemp = head->next;
	while (ptemp != nullptr)
	{
		std::cout << ptemp->data << "\t";
		ptemp = ptemp->next;
	}
	std::cout << std::endl;
}

template<class DataType>
Status LinkList<DataType>::popFront(DataType &data)
{
	if (length == 0) throw"EMPTY LINKLIST";


	data = head->next->data;
	Node<DataType>* ptemp = head->next;
	head->next = ptemp->next;
	delete ptemp;
	if (length == 1) end = head;
	length--;

	return PROCESS_SUCCESS;
}

template<class DataType>
Status LinkList<DataType>::getFront(DataType& data) const
{
	if (length == 0) throw"EMPTY LINKLIST";
	data =  head->next->data;
	return PROCESS_SUCCESS;
}

template<class DataType>
Status LinkList<DataType>::getItem(int index, DataType& data) const
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	Node<DataType>* ptemp = head->next;
	for (int i = 0; i < index; i++)
	{
		ptemp = ptemp->next;
	}
	data = ptemp->data;
}
