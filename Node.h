#pragma once

template<class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T&, Node* = nullptr);
};

template<class T>
Node<T>::Node(const T& _data, Node* _next = nullptr)
	: data(_data), next(_next)
{
}