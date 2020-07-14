#pragma once
#include "Firm.h"
class List
{
private:

	struct Node
	{
		Firm firm;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;

	int size;

public:
	List() : head(nullptr), tail(nullptr), size(0) { }
	List(string name) : head(nullptr), tail(nullptr), size(0) { }

	List(const List& other)
	{
		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->firm);
			current = current->next;
		}
	}

	List(List&& other)
	{
		this->head = other.head;
		this->size = other.size;
		other.head = nullptr;
		other.size = 0;
	}

	List& operator=(const List& other)
	{
		if (this == &other)
			return *this;

		if (this != nullptr)
		{
			while (!IsEmpty())
			{
				DeleteHead();
			}
		}
		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->firm);
			current = current->next;
		}
		return *this;
	}

	List& operator=(List&& other)
	{
		if (this == &other)
			return *this;

		if (this != nullptr)
		{
			while (!IsEmpty())
			{
				DeleteHead();
			}
		}
		this->head = other.head;
		this->size = other.size;
		other.head = nullptr;
		other.size = 0;
		return *this;
	}

	~List()
	{
		DeleteAll();
	}

	bool IsEmpty() const
	{
		return size == 0;
	}
	int GetCount() const
	{
		return size;
	}

	void AddToHead(Firm dir)
	{
		Node* newElem = new Node;
		newElem->firm = dir;
		newElem->next = head;
		newElem->prev = nullptr;

		if (IsEmpty())
		{
			head = tail = newElem;
		}
		else
		{
			head->prev = newElem;
			head = newElem;
		}
		++size;
	}

	void AddToTail(Firm dir)
	{
		Node* newElem = new Node;
		newElem->firm = dir;
		newElem->next = nullptr;
		newElem->prev = tail;

		if (IsEmpty())
		{
			head = tail = newElem;
		}
		else
		{
			tail->next = newElem;
			tail = newElem;
		}
		++size;
	}

	void DeleteHead()
	{
		if (IsEmpty()) return;

		Node* temp = head->next;
		delete head;

		if (temp == nullptr)
		{
			head = tail = nullptr;
		}
		else
		{
			temp->prev = nullptr;
			head = temp;
		}
		--size;
	}

	void DeleteTail()
	{
		if (IsEmpty()) return;

		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node* temp = tail->prev;

			delete temp->next;
			temp->next = nullptr;
			tail = temp;
		}
		--size;
	}

	Firm Find_by_Name(string name)
	{
		Node* current = head;

		for (int i = 0; i < size; i++)
		{
			if (current->firm.Get_name() == name)
			{
				return current->firm;
			}
			current = current->next;
		}
	}

	Firm Find_by_Owner(string owner)
	{
		Node* current = head;

		for (int i = 0; i < size; i++)
		{
			if (current->firm.Get_owner() == owner)
			{
				return current->firm;
			}
			current = current->next;
		}
	}

	Firm Find_by_Telephone(string telephone)
	{
		Node* current = head;

		for (int i = 0; i < size; i++)
		{
			if (current->firm.Get_telephone() == telephone)
			{
				return current->firm;
			}
			current = current->next;
		}
	}

	Firm Find_by_kind_of_activity(string kind_of_activity)
	{
		Node* current = head;

		for (int i = 0; i < size; i++)
		{
			if (current->firm.Get_kind_of_activity() == kind_of_activity)
			{
				return current->firm;
			}
			current = current->next;
		}
	}

	void Print() const
	{
		for (Node* current = head; current != nullptr; current = current->next)
		{
			current->firm.ShowInfo();
			cout << endl;
		}
	}

	void DeleteAll()
	{
		while (!IsEmpty())
		{
			DeleteHead();
		}
	}

	int Get_size()
	{
		return size;
	}


	friend ofstream& operator<<(ofstream& fout, const List& ls);
	friend ifstream& operator>>(ifstream& fin, List& ls);
};

ofstream& operator<<(ofstream& fout, const List& ls)
{
	fout << ls.size << endl;
	List::Node* current = ls.head;

	for (int i = 0; i < ls.size; i++)
	{
		fout << current->firm;
		current = current->next;
	}

	return fout;
}

ifstream& operator>>(ifstream& fin, List& ls)
{
	int size;
	fin >> size;
	for (int i = 0; i < size; i++)
	{
		Firm buff;
		fin >> buff;
		ls.AddToTail(buff);
	}

	return fin;

}