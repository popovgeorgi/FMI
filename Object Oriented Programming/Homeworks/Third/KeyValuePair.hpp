#pragma once
template <typename TKey, typename TValue>
struct KeyValuePair
{
	TKey key;
	TValue value;

public:
	KeyValuePair();
	KeyValuePair(TKey key, TValue value);
};

template <typename TKey, typename TValue>
KeyValuePair<TKey, TValue>::KeyValuePair()
{

}

template <typename TKey, typename TValue>
KeyValuePair<TKey, TValue>::KeyValuePair(TKey key, TValue value)
{
	this->key = key;
	this->value = value;
}

