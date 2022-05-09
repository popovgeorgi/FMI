#pragma once
#include <iostream>

template <typename T>
class MyVector
{
	T* data;
	int size;
	int index;

	void resize();

public:
	MyVector();

	void insert(T element);
	int getSize() const;
	T& operator[](size_t index) const;
};

template <typename T>
MyVector<T>::MyVector()
{
	size = 4;
	index = 0;
	data = new T[size];
}

template <typename T>
int MyVector<T>::getSize() const
{
	return index;
}

template <typename T>
void MyVector<T>::insert(T element)
{
	if (index + 1 == size)
	{
		resize();
	}

	data[index] = element;
	index++;
}

template <typename T>
T& MyVector<T>::operator[](size_t index) const
{
	return data[index];
}

template <typename T>
void MyVector<T>::resize()
{
	T* newData = new T[size * 2];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	size *= 2;
}