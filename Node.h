#pragma once

template <typename T>

class Node
{
public:
	T* Data;
	Node* nextNode;
	Node* prevNode;

public:
	Node(T* aData) : Data(aData)
	{
		nextNode = nullptr;
		prevNode = nullptr;
	}

	Node()
	{
		nextNode = nullptr;
		prevNode = nullptr;
	}

	~Node()
	{
	}

	T getData()
	{
		return Data;
	}
};