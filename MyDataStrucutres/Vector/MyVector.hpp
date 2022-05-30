#pragma once
template <typename T>
class MyVector
{
	T* data;
	int size;
	int index;

	void resize();

public:
	MyVector(int size = 0);
	~MyVector();

	void insert(T element);
	T& operator[](size_t index); // for changing
	const T operator[](size_t index) const; // for reading
};

template <typename T>
MyVector<T>::MyVector(int size)
{
	this->size = size;
	index = 0;
	data = new T[size];
}

template <typename T>
void MyVector<T>::insert(T element)
{
	if (index + 1 == size)
	{
		resize();
	}

	data[index] = element;
}

template <typename T>
T& MyVector<T>::operator[](size_t index)
{
	return data[index];
}

template <typename T>
const T MyVector<T>::operator[](size_t index) const
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

template <typename T>
MyVector<T>::~MyVector()
{
	delete[] data;
}