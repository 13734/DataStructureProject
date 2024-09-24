#pragma once
#include"Status.h"
#include<iostream>
template<typename T>
class SNode
{
public:
	T idata;
	int next;
};

template<typename T>
class SLinkList
{
	int avail;
	int length;
	int maxLength;// unnecessary
	SNode<T>* elems;
public:
	SLinkList(int size = 1e4);
	~SLinkList();
	void Clear();
	bool isEmpty() const;
	int getLength() const;

	int locate(const T& data) const;
	Status getElem(int index, T& data) const;
	Status setElem(int index, const T& data);
	Status insertElem(int index, const T& data);
	Status delElem(int index, T& data);
	void show();

};

template<typename T>
SLinkList<T>::SLinkList(int size) {
	elems = new SNode<T>[size];
	maxLength = size;
	elems[0].next = -1;
	avail = 1;
	for (int i = 1; i < maxLength; i++)
	{
		elems[i].next = i + 1;
	}
	elems[size - 1].next = -1;
	length = 0;
	

}

template<typename T>
Status SLinkList<T>::insertElem(int index,const T& data)
{
	if (index<0 || index> length) return INDEX_ERROR;
	if (avail == -1) return LIST_OVERFLOW;
	int p = 0, q = avail;
	for (int count = 0; count < index; count++)
	{
		p = elems[p].next;
	}
	avail = elems[avail].next;
	elems[q].idata = data;
	elems[q].next = elems[p].next;
	elems[p].next = q;

	length++;
	return PROCESS_SUCCESS;
}

template<typename T>
int SLinkList<T>::locate(const T& data) const {

	int p = elems[0].next;
	while (p == -1 || elems[p].idata == data)
	{
		p = elems[p].next;
	}

	return p;
}

template<typename T>
Status SLinkList<T>::getElem(int index, T& data) const
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	int p = elems[0].next;
	for (int i = 0; i < index; i++)
	{
		p = elems[p].next;
	}
	data = elems[p].idata;
	return PROCESS_SUCCESS;
}


template<typename T>
Status SLinkList<T>::setElem(int index,const T& data) 
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	int p = elems[0].next;
	for (int i = 0; i < index; i++)
	{
		p = elems[p].next;
	}
	 elems[p].idata = data;
	return PROCESS_SUCCESS;
}

template<typename T>
Status SLinkList<T>::delElem(int index, T& data)
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	int p = 0,q;
	for (int i = 0; i < index; i++)
	{
		p = elems[p].next;
	}
	q = elems[p].next;
	data = elems[q].idata;
	elems[p].next = elems[q].next;
	elems[q].next = avail;
	avail = p;
	length--;
	return PROCESS_SUCCESS;
}

template<typename T>
SLinkList<T>::~SLinkList()
{
	delete elems;
}
template<typename T>
void SLinkList<T>::Clear()
{
	elems[0].next = 0;
	avail = 1;
	for (int i = 1; i < maxLength; i++)
	{
		elems[i].next = i + 1;
	}
	elems[maxLength - 1].next = -1;
	length = 0;
}
template<typename T>
bool SLinkList<T>::isEmpty() const
{
	return !length;
}

template<typename T>
void SLinkList<T>::show()
{
	int p = elems[0].next;
	while (p != -1)
	{
		std::cout << elems[p].idata << " ";
		p = elems[p].next;
	}
	std::cout << std::endl;
}
template<typename T>
int SLinkList<T>::getLength() const
{
	return length;
}