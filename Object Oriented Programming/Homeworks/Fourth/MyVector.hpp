#pragma once
template <typename T>
class MyVector
{
	T* data;
	int capacity;
	int index;

	void resize();

public:
	MyVector(int size = 4);

	void copyFrom(const MyVector<T>& other);
	void free();

	MyVector(const MyVector<T>& other);
	MyVector<T>& operator=(const MyVector<T>& other);
	~MyVector();

	int size() const;
	void remove(int index);
	void push_back(const T& element);
	T& operator[](size_t index); // for changing
	const T operator[](size_t index) const; // for reading
};

template <typename T>
MyVector<T>::MyVector(int size)
{
	this->capacity = size;
	index = 0;
	data = new T[size];
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template <typename T>
MyVector<T>::~MyVector()
{
	free();
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	index = other.index;
	capacity = other.capacity;
	data = new T[capacity];

	for (size_t i = 0; i < index; i++)
	{
		data[i] = other[i];
	}
}

template <typename T>
void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
}

template <typename T>
int MyVector<T>::size() const
{
	return index;
}

template <typename T>
void MyVector<T>::push_back(const T& element)
{
	if (index + 1 == capacity)
	{
		resize();
	}

	data[index++] = element;
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
	T* newData = new T[capacity * 2];

	for (size_t i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	capacity *= 2;
}