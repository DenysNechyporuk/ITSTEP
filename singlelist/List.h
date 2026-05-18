#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class List
{
    Node<T>* head;
public:
    List();
    List(const List<T>& other);
    ~List();
    List<T>& operator=(const List<T>& other);

    void pushBack(const T& value);
    void pushFront(const T& value);
    void popBack();
    void popFront();
    bool isEmpty() const;
    void clear();
    void print() const;

    Node<T>* clone() const;
    Node<T>* operator+(const List<T>& other) const;
    Node<T>* operator*(const List<T>& other) const;
};

template <typename T>
List<T>::List()
{
    head = nullptr;
}

template <typename T>
List<T>::List(const List<T>& other)
{
    head = nullptr;
    Node<T>* curr = other.head;
    while (curr != nullptr)
    {
        pushBack(curr->data);
        curr = curr->next;
    }
}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
    if (this == &other) return *this;
    clear();
    Node<T>* curr = other.head;
    while (curr != nullptr)
    {
        pushBack(curr->data);
        curr = curr->next;
    }
    return *this;
}

template <typename T>
void List<T>::pushBack(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node<T>* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = newNode;
}

template <typename T>
void List<T>::pushFront(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void List<T>::popBack()
{
    if (head == nullptr) return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node<T>* curr = head;
    while (curr->next->next != nullptr)
        curr = curr->next;
    delete curr->next;
    curr->next = nullptr;
}

template <typename T>
void List<T>::popFront()
{
    if (head == nullptr) return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
bool List<T>::isEmpty() const
{
    return head == nullptr;
}

template <typename T>
void List<T>::clear()
{
    while (head != nullptr)
        popFront();
}

template <typename T>
void List<T>::print() const
{
    Node<T>* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

template <typename T>
Node<T>* List<T>::clone() const
{
    if (head == nullptr) return nullptr;
    Node<T>* newHead = nullptr;
    Node<T>* newTail = nullptr;
    Node<T>* curr = head;
    while (curr != nullptr)
    {
        Node<T>* newNode = new Node<T>(curr->data);
        if (newHead == nullptr)
        {
            newHead = newNode;
            newTail = newNode;
        }
        else
        {
            newTail->next = newNode;
            newTail = newNode;
        }
        curr = curr->next;
    }
    return newHead;
}

template <typename T>
Node<T>* List<T>::operator+(const List<T>& other) const
{
    List<T> temp(*this);
    Node<T>* curr = other.head;
    while (curr != nullptr)
    {
        temp.pushBack(curr->data);
        curr = curr->next;
    }
    return temp.clone();
}

template <typename T>
Node<T>* List<T>::operator*(const List<T>& other) const
{
    List<T> temp;
    Node<T>* curr = head;
    while (curr != nullptr)
    {
        Node<T>* curr2 = other.head;
        while (curr2 != nullptr)
        {
            if (curr->data == curr2->data)
            {
                temp.pushBack(curr->data);
                break;
            }
            curr2 = curr2->next;
        }
        curr = curr->next;
    }
    return temp.clone();
}