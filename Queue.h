#pragma once
#include "List.h"

template<class T>
class Queue
{
private:
	List<T> qList;

public:
	Queue();
	Queue(const Queue&);
	~Queue();
	const Queue& operator= (const Queue&);

public:
	bool isEmpty() const;
	void push(T&);
	void pop();
	T& front();
};

///
/// Big 4:
///
template<class T>
inline Queue<T>::Queue()
{
}

template<class T>
inline Queue<T>::Queue(const Queue& other): List<T>(other)
{
}

template<class T>
inline Queue<T>::~Queue()
{
}

template<class T>
inline const Queue<T>& Queue<T>::operator=(const Queue& other)
{
	List<T>::operator=(other);
}

///
/// Modify and Access:
///
template<class T>
inline bool Queue<T>::isEmpty() const
{
	return qList.isEmpty();
}

template<class T>
inline void Queue<T>::push(T& el)
{
	qList.pushBack(el);
}

template<class T>
inline void Queue<T>::pop()
{
	qList.popFront();
}

template<class T>
inline T & Queue<T>::front()
{
	return qList.front();
}
