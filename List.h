#pragma once
#include <iostream>
#include "ListIterator.h"

template<class T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	List();
	~List();
	List(const List&);
	const List& operator= (const List&);

private:
	void copy(const List&);
	void clear();

public:
	bool isEmpty() const;
	int getSize() const;
	T& front();
	T& back();

public:
	void pushBack(const T&);
	void pushFront(const T&);

	void popFront();
	void popBack();

public:
	ListIterator<T>& getIterator() const;

public:
	void print() const;
};


///
/// Big 4:
///
template<class T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
List<T>::List(const List& l)
{
	copy(l);
}

template<class T>
const List<T>& List<T>::operator=(const List& l)
{
	if (this != &l)
	{
		clear();
		copy(l);
	}
	return *this;
}

///
/// Help Functions:
///
template<class T>
void List<T>::copy(const List<T>& l)
{
	size = 0;
	if (l.head)
	{
		for (ListIterator<T> it(l.head); !it.isAtEnd(); ++it)
			this->pushBack(*it);
	}
	else
	{
		head = tail = nullptr;
	}
}

template<class T>
void List<T>::clear()
{
	while (size != 0)
		popBack();
}

///
/// Modifiers:
///
template<class T>
void List<T>::pushBack(const T& el)
{
	if (!isEmpty())
	{
		tail->next = new Node<T>(el);
		tail = tail->next;
	}
	else
	{
		head = tail = new Node<T>(el);
	}
	++size;
}

template<class T>
void List<T>::pushFront(const T& el)
{
	if (!isEmpty())
	{
		head = new Node<T>(el, head);
	}
	else
	{
		head = tail = new Node<T>(el);
	}
	++size;
}

template<class T>
void List<T>::popFront()
{
	if (!isEmpty())
	{
		if (head != tail)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			delete head;
			head = tail = nullptr;
		}
		--size;
	}
	else
		throw std::exception("Cannot pop from empty list!");
}

template<class T>
void List<T>::popBack()
{
	if (!isEmpty())
	{
		if (head != tail)
		{
			Node<T>* temp = head;
			while (temp->next != tail)
				temp = temp->next;
			delete tail;
			tail = temp;
		}
		else
		{
			delete head;
			head = tail = nullptr;
		}
		--size;
	}
	else
		throw std::exception("Cannot pop from empty list!");;
}

///
/// Access:
///
template<class T>
inline bool List<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
inline int List<T>::getSize() const
{
	return size;
}

template<class T>
inline T& List<T>::front()
{
	return head->data;
}

template<class T>
inline T& List<T>::back()
{
	return tail->data;
}

template<class T>
inline ListIterator<T>& List<T>::getIterator() const
{
	return ListIterator<T>(head);
}

template<class T>
inline void List<T>::print() const
{
	for (ListIterator<T> it(head); !it.isAtEnd(); ++it)
	{
		(*it).print();
		std::cout << " ";
	}
	std::cout << std::endl;
}
