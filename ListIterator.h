#pragma once
#include <assert.h>
#include "Node.h"

template<class T>
class ListIterator
{
private:
	const Node<T>* begin;
	Node<T>* current;

public:
	ListIterator(Node<T>* start);

public:
	T& operator*();

	ListIterator& operator++();
	ListIterator operator++(int);
	
	void goToStart();
	bool isAtEnd() const;
};

template<class T>
ListIterator<T>::ListIterator(Node<T>* start):
	begin(start), current(start)
{
}

template<class T>
T& ListIterator<T>::operator*()
{
	return current->data;
}

template<class T>
ListIterator<T>& ListIterator<T>::operator++()
{
	if (current)
	{
		current = current->next;
		return *this;
	}
	throw std::out_of_range("Cannot continue outside of the list's nodes!");
}

template<class T>
ListIterator<T> ListIterator<T>::operator++(int)
{
	if (current)
	{
		ListIterator old(*this);
		operator++();
		return old;
	}
	throw std::out_of_range("Cannot continue outside of the list's nodes!");
}

template<class T>
void ListIterator<T>::goToStart()
{
	current = begin;
}

template<class T>
bool ListIterator<T>::isAtEnd() const
{
	return current == nullptr;
}