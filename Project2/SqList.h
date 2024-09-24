#pragma once
#include"Status.h"
#include<iostream>
#define MAX_LIST_LENGTH  1000



template<typename DataType>
class SqList
{
public:
	SqList(int list_length = MAX_LIST_LENGTH);
	SqList(const SqList& list2);
	virtual ~SqList();
	DataType& operator[](int index)
	{
		if (index < 0 || index >= length) throw "index error";
		return datas[index];
	}
	int getLength() const { return length; }
	Status insert(int index, const DataType& data);
	Status pushBack(const DataType& data);
	Status addList(DataType* dataArray, int length);
	Status addList(const SqList<DataType> & sqlist2, int length);
	Status setItem(int index, const DataType& data);
	Status del(int index, DataType& data);
	Status del(int index);
	void clear() { length = 0; }
	bool isEmpty() { return !length; }
	
	int index(const DataType& data) const;
	DataType readData(int index) const
	{
		if (index >= length) throw"index error";
		return datas[index]; 
	}

	void show_all();

private:
	int length;
	int maxLength;
	DataType* datas;


};


template<typename DataType>
SqList<DataType>::SqList(const SqList& list2)
{
	length = list2.length;
	maxLength = list2.maxLength;
	datas = new DataType[maxLength];
	std::cout << datas << std::endl;
	for (int i = 0; i < length; i++)
	{
		datas[i] = list2.datas[i];
	}
}

template<typename DataType>
SqList<DataType>::SqList(int list_length)
{
	maxLength = list_length;
	length = 0;
	datas = new DataType[maxLength];
	//std::cout << datas << std::endl;
}

template<typename DataType>
SqList<DataType>::~SqList()
{
	//std::cout << datas << std::endl;
	delete [] datas;
}

template<typename DataType>
Status SqList<DataType>::pushBack(const DataType& data)
{
	if (length >= maxLength) return LIST_OVERFLOW;
	datas[length] = data;
	length++;
	return PROCESS_SUCCESS;
}

template<typename DataType>
Status SqList<DataType>::insert(int index, const DataType& data)
{
	if (length >= maxLength) return LIST_OVERFLOW;
	if (index >= length) return INDEX_ERROR;
	for (int i = length - 1; i >= index; i--)
	{
		datas[i + 1] = datas[i];
	}
	datas[index] = data;
	length++;
	return PROCESS_SUCCESS;

}

template<typename DataType>
Status SqList<DataType>::del(int index, DataType& data)
{
	if (index >= length || index < 0) return INDEX_ERROR;
	data = datas[index];
	for (int i = index; i < length - 1; i++)
	{
		datas[i] = datas[i + 1];
	}
	length--;
	return PROCESS_SUCCESS;
}

template<typename DataType>
Status SqList<DataType>::del(int index)
{
	DataType tmp;
	return this->del(index, tmp);
}

template<typename DataType>
int SqList<DataType>::index(const DataType& data) const
{
	int result = -1;
	for (int i = 0; i < length; i++)
	{
		if (datas[i] == data)
		{
			result = i;
			break;
		}

	}
	return result;

}

template<typename DataType>
Status SqList<DataType>::addList(DataType* dataArray, int mlength)
{
	if (length + mlength > maxLength) return LIST_OVERFLOW;
	for (int i = 0; i < mlength; i++)
	{
		this->pushBack(dataArray[i]);
	}
	return PROCESS_SUCCESS;
}

template<typename DataType>
Status SqList<DataType>::setItem(int index, const DataType& data)
{
	if (index < 0 || index >= length) return INDEX_ERROR;
	datas[index] = data;
	return PROCESS_SUCCESS;
}

template<typename DataType>
Status SqList<DataType>::addList(const SqList& sqData, int mlength)
{
	if (mlength == -1) mlength = sqData.getLength();
	if (sqData.getLength() < mlength) return PROCESS_FAILD;
	if (length + mlength > maxLength) return LIST_OVERFLOW;
	for (int i = 0; i < mlength; i++)
	{
		this->pushBack(sqData.readData(i));
	}
	return PROCESS_SUCCESS;
}

template<typename DataType>
void SqList<DataType>::show_all()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << datas[i] << "\t";
	}
	std::cout << std::endl;
}
