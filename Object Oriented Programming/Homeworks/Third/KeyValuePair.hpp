#pragma once
#pragma warning(disable : 4996)

template <typename TValue>
struct KeyValuePair
{
	char* key;
	TValue value;

public:
	KeyValuePair();
	KeyValuePair(const char* key, TValue value);
};

template <typename TValue>
KeyValuePair<TValue>::KeyValuePair()
{

}

template <typename TValue>
KeyValuePair<TValue>::KeyValuePair(const char* key, TValue value)
{
	this->key = new char[50];
	strcpy(this->key, key);
	this->value = value;
}

