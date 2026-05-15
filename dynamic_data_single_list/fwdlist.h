#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data{ data }, next{ next }
	{

	}
};


template<typename T>
class fwdlist
{
public:
	fwdlist() = default;
	~fwdlist();
	fwdlist(const fwdlist<T>& other);
	fwdlist<T>& operator=(const fwdlist<T>& other);
	void addHead(const T& data);
	void addTail(const T& data);
	void print() const;
	void removeHead();
	void removeAt(const T& data);
	void clear();
	bool isEmpty() const;

private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
};

template<typename T>
fwdlist<T>::~fwdlist()
{
	while (!isEmpty())
		removeHead();
}

template<typename T>
fwdlist<T>::fwdlist(const fwdlist<T>& other)
{
	auto tmp = other.head;
	while (tmp != nullptr)
	{
		addTail(tmp->data);
		tmp = tmp->next;
	}
}

template<typename T>
fwdlist<T>& fwdlist<T>::operator=(const fwdlist<T>& other)
{
	if (this == &other)
		return *this;
	clear();
	auto tmp = other.head;
	while (tmp != nullptr)
	{
		addTail(tmp->data);
		tmp = tmp->next;
	}
	return *this;
}

template<typename T>
inline void fwdlist<T>::addHead(const T& data)
{
	auto tmp = new Node<T>(data, head);
	head = tmp;
	if (isEmpty())
		tail = tmp;
	++size;
}

template<typename T>
inline void fwdlist<T>::addTail(const T& data)
{
	auto tmp = new Node<T>(data, nullptr);
	if (isEmpty())
	{
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tmp;
	}
	++size;
}

template<typename T>
inline void fwdlist<T>::print() const
{
	if (isEmpty()) {
		cout << "List is empty!" << endl;
		return;
	}
	auto tmp = head;
	cout << "List ::            ";
	while (tmp != nullptr)
	{
		cout << tmp->data << "        ";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void fwdlist<T>::removeHead()
{
	if (isEmpty())
		return;
	auto tmp = head;
	head = tmp->next;
	--size;
	delete tmp;
	if (isEmpty())
		tail = nullptr;
}

template<typename T>
inline void fwdlist<T>::removeAt(const T& data)
{
	if (isEmpty())
		return;
	auto tmp = head;
	while (tmp != nullptr && tmp->data != data)
		tmp = tmp->next;
	if (tmp == nullptr || tmp->next == nullptr)
		return;
	auto toDelete = tmp->next;
	tmp->next = toDelete->next;
	if (toDelete == tail)
		tail = tmp;
	delete toDelete;
	--size;
}

template<typename T>
inline void fwdlist<T>::clear()
{
	if (isEmpty())
	{
		cout << "The list is already empty";
		return;
	}
	while (!isEmpty())
	{
		removeHead();
	}
}

template<typename T>
inline bool fwdlist<T>::isEmpty() const
{
	return head == nullptr;
}