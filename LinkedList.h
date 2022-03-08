#pragma once
#include "Node.h"

template <typename T>

class LinkedList
{
private:
	Node<T>* firstNode;
	Node<T>* lastNode;
	int len;

public:

	LinkedList()
	{
		firstNode = nullptr;
		lastNode = nullptr;
		len = 0;
	}

	~LinkedList()
	{
		Node<T>* crt;
		while (firstNode != nullptr)
		{
			crt = firstNode;
			firstNode = firstNode->nextNode;
			delete crt;
		}
	}

	void PushBack(T* Data)
	{
		Node<T>* node = new Node<T>(Data);

		len++;

		if (firstNode == nullptr && lastNode == nullptr)
		{
			firstNode = node;
			lastNode = node;
			return;
		}

		lastNode->nextNode = node;
		node->prevNode = lastNode;
		node->nextNode = nullptr;
		lastNode = node;
	}

	void PopBack()
	{
		len--;
		Node<T> crt = lastNode;

		lastNode = lastNode->prevNode;
		lastNode->nextNode = nullptr;
		
		delete crt;
	}

	void MoveNode(int pos1, int pos2)
	{
		Node<T> N1, N2;
		T swp;
		N1 = N2 = firstNode;

		for (int i = 1; i < pos1; i++)
		{
			N1 = N1->nextNode;
		}
		for (int i = 1; i < pos1; i++)
		{
			N2 = N2->nextNode;
		}

		swp = N1->Data;
		N1->Data = N2->Data;
		N2->Data = swp;
	}

	void DeleteNode(Node<T>* crt)
	{
		len--;

		if (firstNode == lastNode)
		{
			firstNode = lastNode = nullptr;

			delete crt;

			return;
		}

		if (crt == firstNode)
		{
			crt->nextNode->prevNode = nullptr;

			firstNode = crt->nextNode;

			delete crt;

			return;
		}

		if (crt == lastNode)
		{
			crt->prevNode->nextNode = nullptr;

			lastNode = crt->prevNode;

			delete crt;

			return;
		}

		crt->prevNode->nextNode = crt->nextNode;
		crt->nextNode->prevNode = crt->prevNode;

		delete crt;
	}

	Node<T>* GetNode(int k)
	{
		Node<T>* crt = firstNode;

		for (int i = 1; i < k; i++)
		{
			crt = crt->nextNode;
		}

		return crt;
	}

	Node<T>* Begin()
	{
		return firstNode;
	}

	int GetLen()
	{
		return len;
	}

	bool Contains(T* Data)
	{
		Node<T>* crt = firstNode;

		while (crt)
		{
			if (crt->Data == Data)
			{
				return true;
			}

			crt = crt->nextNode;
		}

		return false;
	}
};

