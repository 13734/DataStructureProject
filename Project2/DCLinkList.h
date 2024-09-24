#pragma once

#include"Status.h"
#include<iostream>


template <typename T>
class DLNode
{
public:
	DLNode<T>* prior;
	DLNode<T>* next;
	T idata;
	DLNode() { prior = next = nullptr; }
	DLNode(T data, DLNode<T>* pprior = nullptr, DLNode<T>* pnext = nullptr)
	{
		idata = data;
		prior = pprior;
		next = pnext;
	}



};

 
template<typename T>
class DCLinkList
{
protected:
	DLNode<T>* head;
	int length;
public:
	Status pushFront(const T& data);
	Status pushBack(const T& data);
	Status popFront( T& data);
	Status popBack( T& data);
	Status getFront( T& data) const;
	Status getBack( T& data) const;

	DCLinkList();
	virtual ~DCLinkList();
	void clear();
	int getLength() const;
	bool isEmpty() const;
	int index(const T& data) const;
	Status getItem(int index,T& data) const;
	Status setItem(int index, const T& data);
	Status insert(int index, const T& data);
	Status del(int index, T& data);
	Status del(int index);
	void show() const;

};

template<typename T>
DCLinkList<T>::DCLinkList()
{
	head = new DLNode<T>;
	head->next = head->prior = head;
}

template<typename T>
Status DCLinkList<T>::pushFront(const T&data)
{
	DLNode<T> * ptemp = new DLNode<T>(data, head, head->next);
	if (!ptemp) return ALLOCATE_ERROR;
	head->next->prior = ptemp;
	head->next = ptemp;
	length++;
	return PROCESS_SUCCESS;

}

template<typename T>
Status DCLinkList<T>::pushBack(const T& data)
{
	DLNode<T> *ptemp = new DLNode<T>(data, head->prior, head);
	if (!ptemp)  return ALLOCATE_ERROR;
	head->prior->next = ptemp;
	head->prior = ptemp;
	length++;
	return PROCESS_SUCCESS;
}

template<typename T>
Status DCLinkList<T>::popFront(T& data)
{
	if (length == 0) return EMPTY_LIST;
	DLNode<T>* ptemp = head->next;
	ptemp->next->prior = head;
	head->next = ptemp->next;
	data = ptemp->idata;
	delete ptemp;
	length--;
	return PROCESS_SUCCESS;

}

template<typename T>
Status DCLinkList<T>::popBack(T& data)
{
	if (length == 0) return EMPTY_LIST;
	DLNode<T>* ptemp = head->prior;
	ptemp->prior->next = head;
	head->prior = ptemp->prior;
	data = ptemp->idata;
	delete ptemp;
	length--;
	return PROCESS_SUCCESS;
}

template<typename T>
Status DCLinkList<T>::getFront(T& data) const
{
	if (length == 0) return EMPTY_LIST;
	data = head->next->idata;
	return PROCESS_SUCCESS;
}

template<typename T>
Status DCLinkList<T>::getBack(T& data) const
{
	if (length == 0) return EMPTY_LIST;
	data = head->next->idata;
	return PROCESS_SUCCESS;
}

template<typename T>
void DCLinkList<T>::clear()
{
	DLNode<T>* ptemp = head->next;
	while (ptemp != head)
	{
		head->next = ptemp->next;
		delete ptemp;
		ptemp = head->next;
	}
	head->next = head->prior = head;
	length = 0;
}

template<typename T>
DCLinkList<T>::~DCLinkList()
{
	clear();
	delete head;
}

template<typename T>
int DCLinkList<T>::getLength() const
{
	return length;
}


template<typename T>
int DCLinkList<T>::index(const T& data) const
{
	int index = -1;
	int i = 0;
	DLNode<T> *ptemp = head->next;
	while (ptemp != head)
	{
		if (ptemp->idata == data)
		{
			index = i;
			break;
		}
		ptemp = ptemp->next;
		i++;
	}
	return index;
	
}

template<typename T>
Status DCLinkList<T>::del(int index, T& data)
{
	//if (index < -length || index >= length) return INDEX_ERROR;
	if (index < 0 || index >= length) return INDEX_ERROR;
	DLNode<T>* ptemp = head; //待删的上一个 与LinkList 同理
	for (int i = 0; i < index; i++)
	{
		ptemp = ptemp->next;
	}
	DLNode<T>* ptemp2 = ptemp->next;
	ptemp2->next->prior = ptemp;
	ptemp->next = ptemp2 -> next;
	delete ptemp2;
	length--;
	return PROCESS_SUCCESS;

}

template<typename T>
Status DCLinkList<T>::del(int index)
{
	T data;
	return del(index, data);
}

template<typename T>
bool DCLinkList<T>::isEmpty() const
{
	return !length;
}

template<typename T>
Status DCLinkList<T>::getItem(int index, T& data) const 
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	DLNode<T>* ptemp = head->next;
	for (int i = 0; i < index; i++)
	{
		ptemp = ptemp->next;
	}
	data = ptemp->idata;
	return PROCESS_SUCCESS;
}

template<typename T>
Status DCLinkList<T>::setItem(int index, const T& data) 
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	DLNode<T>* ptemp = head->next;
	for (int i = 0; i < index; i++)
	{
		ptemp = ptemp->next;
	}
	ptemp->idata = data;
	return PROCESS_SUCCESS;
}

template<typename T>
Status DCLinkList<T>::insert(int index, const T& data)
{
	//if (index < -length || index >= length) return INDEX_ERROR;
	if (index < 0 || index > length) return INDEX_ERROR;
	DLNode<T>* ptemp = head; //待删的上一个 与LinkList 同理
	for (int i = 0; i < index; i++)
	{
		ptemp = ptemp->next;
	}
	DLNode<T>* ptemp2 = new DLNode<T>(data, ptemp, ptemp->next);
	ptemp->next->prior = ptemp2;
	ptemp->next = ptemp2;
	length++;
	return PROCESS_SUCCESS;
}

template<typename T>
void DCLinkList<T>::show() const
{
	DLNode<T>* ptemp = head->next;
	for (int i = 0; i < length; i++)
	{
		std::cout << ptemp->idata << ",";
		ptemp = ptemp->next;
	}
	std::cout << std::endl;
	
}