#pragma once
template <typename T>
class myVector
{
	T* data;
	int size;
	int index;

	void resize();

public:
	myVector();

	void insert(T element);
	T operator[](size_t index);
};

template <typename T>
myVector<T>::myVector()
{
	size = 4;
	index = 0;
	data = new T[size];
}

template <typename T>
void myVector<T>::insert(T element)
{
	if (index + 1 == size)
	{
		resize();
	}

	data[index] = element;
}

template <typename T>
T myVector<T>::operator[](size_t index)
{
	return data[index];
}

template <typename T>
void myVector<T>::resize()
{
	T* newData = new T[size * 2];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	size *= 2;
}